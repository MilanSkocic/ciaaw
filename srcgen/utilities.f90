module utils
    !! Functions for parsing and manipulating ciaaw_saw.
    use iso_fortran_env
    implicit none

    !! Properties of the file for the codata raw data.
    type :: ciaaw_saw_file_props
        integer(int32) :: n !! Number of lines.
        integer(int32) :: index_header_end !! Number of lines for the header.
        character(len=18) :: fpath !! Filepath to the raw codata constants.
        character(len=4) :: year !! Year of release of the codata constants.
    end type
    
    integer(int32), parameter :: LINE_LENGTH = 256 !! Length of line.
    integer(int32), parameter :: cix_element(2) = [1, 20]
    integer(int32), parameter :: cix_symbol(2) = [21, 27]
    integer(int32), parameter :: cix_z(2) = [28, 32]
    integer(int32), parameter :: cix_saw_min(2) = [33, 52]
    integer(int32), parameter :: cix_saw_max(2) = [53, 72]
    integer(int32), parameter :: cix_saw(2) = [73, 92]
    integer(int32), parameter :: cix_saw_u(2) = [93, 112]
    integer(int32), parameter :: cix_footnote(2) = [113, 122]
    integer(int32), parameter :: cix_asaw(2) = [123, 132]
    integer(int32), parameter :: cix_asaw_u(2) = [133, 142]
    integer(int32), parameter :: cix_compute(2) = [143, 152]

contains

subroutine convert_value_to_fortran(value)
    !! Convert power symbol d to e for C code
    ! Arguments
    character(len=*), intent(inout) :: value
        ! Value to be converted.
    
    ! Local vars
    integer(int32) :: i

    do i=1, len(value), 1
        if(value(i:i) == 'e' .or. value(i:i) == 'E')then
            value(i:i) = achar(iachar("d"))
        end if
    end do
end subroutine

subroutine clean_line(line)
    !! Fill the buffer with white space.
    implicit none
    ! Arguments
    character(len=*), intent(inout) :: line
        !! Line to be cleaned
    ! Local variables
    integer(int32) :: i
    do i=1, len(line)
        line(i:i) = " "
    end do
end subroutine

subroutine get_props(properties)
    !! Get the properties of the ciaaw file.
    implicit none

    ! Arguments
    type(ciaaw_saw_file_props), intent(inout) :: properties
        !! Properties of the ciaaw file.
    
    ! Local variables
    integer(int32) :: unit, iostat, iostat_read
    character(len=512) :: msg
    character(len=LINE_LENGTH) :: line

    iostat = 0 
    iostat_read = 0
    properties%index_header_end = 0
    open(file=properties%fpath, newunit=unit, iostat=iostat, iomsg=msg, action="read", status="old")

    if(iostat == 0)then
    loop: do 
            read(unit, "(A)", iostat=iostat_read) line
            if(iostat_read == 0)then
                if(line(1:1) == "-")then
                    properties%index_header_end = properties%index_header_end + 1
                    exit loop
                else
                    properties%index_header_end = properties%index_header_end + 1
                endif
            else 
                exit loop
            endif
        end do loop
    endif

    do while(iostat_read == 0)
        read(unit, "(A)", iostat=iostat_read) line
        if((iostat_read == 0) .and. (len(line)>0))then
            properties%n = properties%n+1
        else 
            exit
        endif
    end do

    close(unit)

end subroutine

subroutine write_saw_data(fciaaw, ffortran, ffortran_capi, props)
    !! Generate the fortran code for ciaaw__saw.
    implicit none
    ! Arguments
    integer(int32), intent(in) :: fciaaw
        !! File unit of the ciaaw data.
    integer(int32), intent(in) :: ffortran
        !! File unit of the Fortran module.
    integer(int32), intent(in) :: ffortran_capi
        !! File unit of the Fortran CAPI module.
    type(ciaaw_saw_file_props), intent(in) :: props
        !! props Properties of the codata file.

    character(len=32) :: out_format

    character(len=LINE_LENGTH) :: line
    
    character(len=64) :: name
    character(len=64) :: name_capi
    
    character(len=10) :: element
    character(len=2) :: symbol
    character(len=4) :: z
    character(len=64) :: saw_max
    character(len=64) :: saw_min
    character(len=64) :: saw
    character(len=64) :: saw_u
    character(len=64) :: asaw
    character(len=64) :: asaw_u
    logical :: compute
    real(real64) :: saw_min_db
    real(real64) :: saw_value_db
    real(real64) :: saw_max_db
    real(real64) :: saw_u_db
    
    integer(int32) :: i, n
    
    rewind(unit=fciaaw)
    do i=1, props%index_header_end
        read(fciaaw, "(A)") line
    end do

    ! fortran
    write(ffortran, "(A,/)") 'integer(int32), parameter :: ciaaw_saw_YEAR = ' // props%year
    ! fortran C API
    write(ffortran_capi, "(A,/)") &
    'integer(c_int), protected, bind(C, name="CIAAW_CAPI_YEAR") :: ciaaw_saw_capi_YEAR = ciaaw_saw_YEAR'
    

    do i=1, props%n
        call clean_line(line)
        read(fciaaw, "(A)") line
        if(len(trim(line))>0)then
            read(line(cix_compute(1): cix_compute(2)), "(L4)") compute
            read(line(cix_element(1): cix_element(2)), "(A)") element
            read(line(cix_symbol(1): cix_symbol(2)), "(A)") symbol
            read(line(cix_z(1): cix_z(2)), "(A)") z
            read(line(cix_saw_min(1): cix_saw_min(2)), "(A)") saw_min
            read(line(cix_saw_max(1): cix_saw_max(2)), "(A)") saw_max
            read(line(cix_saw(1): cix_saw(2)), "(A)") saw
            read(line(cix_saw_u(1): cix_saw_u(2)), "(A)") saw_u
            read(line(cix_asaw(1): cix_asaw(2)), "(A)") asaw
            read(line(cix_asaw_u(1): cix_asaw_u(2)), "(A)") asaw_u
            
            print *, compute

            if(compute)then
                read(saw_max, "(D20.10)") saw_max_db
                read(saw_min, "(D20.10)") saw_min_db
                
                saw_value_db = (saw_max_db + saw_min_db)/2.0d0
                saw_u_db = (saw_max_db - saw_min_db)/(2.0d0*sqrt(3.0d0))
                
                n = floor(log10(saw_u_db))
                saw_u_db = ceiling(saw_u_db * 10**(-n*1.0d0))*10**(n*1.0d0)
                
                write(out_format, "(A, I1, A)") "(F19.", -n, ", A)"
                write(saw, out_format) saw_value_db, "d0"
                
                write(out_format, "(A, I1, A)") "(F19.", -n, ", A)"
                write(saw_u, out_format) saw_u_db, "d0"
            else
                saw_max = "-1"
                saw_min = "-1"
            end if
            
            name = "ciaaw_saw_"//trim(symbol)
            write(ffortran, "(A)") "type(ciaaw_saw_elmt_t), parameter :: "//trim(name)//" =&"
            write(ffortran, "(A)") 'ciaaw_saw_elmt_t("'//trim(element)//'", '//'"'//trim(symbol)//'", '//trim(z)//", "//&
                                    trim(saw_min)// ", "//trim(saw_max)//", "//&
                                    trim(adjustl(saw))//", "//trim(adjustl(saw_u))//", "//&
                                    trim(asaw)//", "//trim(asaw_u)//')'
            write(ffortran, "(A)") ""
            name_capi = "ciaaw_saw_capi_"//trim(symbol)
write(ffortran_capi, "(A)", advance="NO") "type(ciaaw_saw_capi_elmt_t) :: "//trim(name_capi)//" =ciaaw_saw_capi_elmt_t("
            write(ffortran_capi, "(A)") trim(name)//"%z, &"
            write(ffortran_capi, "(A)", advance="NO") trim(name)//"%saw_max, "//trim(name)//"%saw_min, "
            write(ffortran_capi, "(A)", advance="NO") trim(name)//"%saw, "//trim(name)//"%saw_u, "
            write(ffortran_capi, "(A)") trim(name)//"%asaw, "//trim(name)//"%asaw_u)"
            write(ffortran_capi, "(A)") ""
        endif

    end do

end subroutine

end module