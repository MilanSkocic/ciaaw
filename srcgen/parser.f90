module utils
    !! Functions for parsing and manipulating ciaaw_saw.
    use iso_fortran_env
    use core
    use fortran_code
    use c_code
    implicit none

    
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

subroutine write_saw_data(fciaaw, ffortran, ffortran_capi, fcheader, fcpython, props)
    !! Generate the fortran code for ciaaw__saw.
    implicit none
    ! Arguments
    integer(int32), intent(in) :: fciaaw
        !! File unit of the ciaaw data.
    integer(int32), intent(in) :: ffortran
        !! File unit of the Fortran module.
    integer(int32), intent(in) :: ffortran_capi
        !! File unit of the Fortran CAPI module.
    integer(int32), intent(in) :: fcheader
        !! File unit of the C header.
    integer(int32), intent(in) :: fcpython
        !! File unit for CPython. 
    type(ciaaw_saw_file_props), intent(in) :: props
        !! props Properties of the codata file.

    character(len=32) :: out_format

    character(len=LINE_LENGTH) :: line
    
    character(len=64) :: name
    character(len=64) :: name_capi
    
    character(len=LENGTH_ELEMENT+1) :: element
    character(len=LENGTH_SYMBOL+1) :: symbol
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
    
    integer(int32) :: i, n, j, ix_trim
    
    rewind(unit=fciaaw)
    do i=1, props%index_header_end
        read(fciaaw, "(A)") line
    end do

    ! fortran
    write(ffortran, "(A,/)") 'integer(int32), parameter :: ciaaw_saw_YEAR = ' // props%year
    ! fortran C API
    write(ffortran_capi, "(A,/)") &
    'integer(c_int), protected, bind(C, name="ciaaw_saw_capi_YEAR") :: ciaaw_saw_capi_YEAR = ciaaw_saw_YEAR'
    ! C HEADER
    write(fcheader, "(A,/)") &
    'extern const int ciaaw_saw_capi_YEAR;'
    ! cpython
    write(fcpython, "(4X, A)") "v = PyLong_FromLong(ciaaw_saw_capi_YEAR);"
    write(fcpython, "(4X, A)") 'PyDict_SetItemString(d, "YEAR", v);'
    write(fcpython, "(4X, A)") "Py_INCREF(v);"
    write(fcpython, "(A)") ""
    

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
                saw_max = "-1.0d0"
                saw_min = "-1.0d0"
            end if
            
            ! Fortran
            name = "ciaaw_saw_"//trim(symbol)
            write(ffortran, "(A)") "type(ciaaw_saw_elmt_t), parameter :: "//trim(name)//" =&"
            write(ffortran, "(A)") 'ciaaw_saw_elmt_t("'//trim(element)//'", '//'"'//trim(symbol)//'", '//trim(z)//", "//&
                                    trim(saw_min)// ", "//trim(saw_max)//", "//&
                                    trim(adjustl(saw))//", "//trim(adjustl(saw_u))//", "//&
                                    trim(asaw)//", "//trim(asaw_u)//')'

            ! Fortran C API
            name_capi = "ciaaw_saw_capi_"//trim(symbol)
            write(ffortran_capi, "(A)", advance="NO") 'type(ciaaw_saw_capi_elmt_t), protected, '
            write(ffortran_capi, "(A)", advance="YES") 'bind(C, name="'//trim(name_capi)//'") :: '//&
                                                       trim(name_capi)//" = ciaaw_saw_capi_elmt_t(&"
            ix_trim = len(trim(element))
            write(ffortran_capi, "(A)", advance="NO") '['
            do j=1, ix_trim
                 write(ffortran_capi, "(A)", advance="NO") '"'//element(j:j)//'",'
            end do
            write(ffortran_capi, "(A)", advance='NO') 'c_null_char, '
            do j=(ix_trim+2), len(element)-1
                 write(ffortran_capi, "(A)", advance="NO") '"'//element(j:j)//'",'
            end do
            write(ffortran_capi, "(A)", advance="YES") '" "], &'
            
            ix_trim = len(trim(symbol))
            write(ffortran_capi, "(A)", advance="NO") '['
            do j=1, ix_trim
                write(ffortran_capi, "(A)", advance="NO") '"'//symbol(j:j)//'",'
            end do
            write(ffortran_capi, "(A)", advance='NO') 'c_null_char, '
            do j=(ix_trim+2), len(symbol)-1
                 write(ffortran_capi, "(A)", advance="NO") '"'//symbol(j:j)//'",'
            end do
            write(ffortran_capi, "(A)", advance="YES") '" "], &'

            write(ffortran_capi, "(A)", advance="YES") trim(name)//"%z, &"
            write(ffortran_capi, "(A)", advance="NO") trim(name)//"%saw_max, "//trim(name)//"%saw_min, "
            write(ffortran_capi, "(A)", advance="NO") trim(name)//"%saw, "//trim(name)//"%saw_u, "
            write(ffortran_capi, "(A)") trim(name)//"%asaw, "//trim(name)//"%asaw_u)"

            ! C Header
            name = "ciaaw_saw_capi_"//trim(symbol)
            write(fcheader, "(A)") 'extern const struct ciaaw_saw_capi_elmt_t '//trim(name)//';'

            ! Cpython
            name_capi = "ciaaw_saw_capi_"//trim(symbol)
            write(fcpython, "(4X, A)", advance="NO") 'element = Py_BuildValue("{'
            write(fcpython, "(A)", advance='NO') 's:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d'
            write(fcpython, "(A)", advance="YES") '}",'
            write(fcpython, "(8X, A)", advance="YES") '"element",'//trim(name_capi)//'.element,'
            write(fcpython, "(8X, A)", advance="YES") '"symbol",'//trim(name_capi)//'.symbol,'
            write(fcpython, "(8X, A)", advance="YES") '"z",'//trim(name_capi)//'.z,'
            write(fcpython, "(8X, A)", advance="YES") '"saw_max",'//trim(name_capi)//'.saw_max,'
            write(fcpython, "(8X, A)", advance="YES") '"saw_min",'//trim(name_capi)//'.saw_min,'
            write(fcpython, "(8X, A)", advance="YES") '"saw",'//trim(name_capi)//'.saw,'
            write(fcpython, "(8X, A)", advance="YES") '"saw_u",'//trim(name_capi)//'.saw_u,'
            write(fcpython, "(8X, A)", advance="YES") '"asaw",'//trim(name_capi)//'.asaw,'
            write(fcpython, "(8X, A)", advance="YES") '"asaw_u",'//trim(name_capi)//'.asaw_u'
            write(fcpython, "(4X, A)", advance="YES") ');'
            write(fcpython, "(4X, A)") 'PyDict_SetItemString(d, "'//trim(symbol)//'", element);'
            write(fcpython, "(4X, A)") "Py_INCREF(element);"
            write(fcpython, "(A)") ""

        endif

    end do
    write(ffortran, '(A)') ''
    write(ffortran_capi, '(A)') ''
    write(fcheader, '(A)') ''

end subroutine

end module