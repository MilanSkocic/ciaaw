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
    integer(int32), parameter :: cix_element(2) = [1, 10]
    integer(int32), parameter :: cix_compute(2) = [124, 133]

contains

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

subroutine write_saw_data(fciaaw, ffortran, props)
    !! Generate the fortran code for ciaaw__saw.
    implicit none
    ! Arguments
    integer(int32), intent(in) :: fciaaw
        !! File unit of the ciaaw data.
    integer(int32), intent(in) :: ffortran
        !! File unit of the Fortran module.
    type(ciaaw_saw_file_props), intent(in) :: props
        !! props Properties of the codata file.


    character(len=LINE_LENGTH) :: line
    character(len=10) :: element
    logical :: compute
    integer(int32) :: i
    
    rewind(unit=fciaaw)
    do i=1, props%index_header_end
        read(fciaaw, "(A)") line
    end do

    ! fortran
    write(ffortran, "(A,/)") 'integer(int32), parameter :: YEAR = ' // props%year

    do i=1, props%n
        call clean_line(line)
        read(fciaaw, "(A)") line
        if(len(trim(line))>0)then
            read(line(cix_compute(1): cix_compute(2)), "(L4)") compute
            print *, compute
        endif

    end do

end subroutine

end module