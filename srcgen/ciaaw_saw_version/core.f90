module core
    use iso_fortran_env
    implicit none



contains

function get_version()result(version)
    implicit none
    character(len=64) :: version

    integer(int32) :: iostat_open, iostat_read, unit
    character(len=128) :: line
    
    line = ""
    version = ""
    open(file="../../fpm.toml", newunit=unit, iostat=iostat_open, status='old', action='read')
    if(iostat_open == 0)then
        loop:do 
            read(unit, "(A)", iostat=iostat_read) line
            if(iostat_read == 0)then
                if(line(1:10) == 'version = ')then
                    version = trim(line(11:))
                    exit loop
                else
                    version = "Error reading version line in fpm."
                endif
            else
                version = "Error reading line in fpm."
                exit loop
            endif
        end do loop
    else
        version = "Error opening fpm"
    end if

    close(unit)

end function

end module