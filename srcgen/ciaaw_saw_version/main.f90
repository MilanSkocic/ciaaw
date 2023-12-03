program generator
    use iso_fortran_env
    use core
    use ciaaw_version_f90
    implicit none
    
    character(len=*), parameter :: root = "../../"
    character(len=:), allocatable :: version
    integer(int32) :: ffortran, ffortran_capi, fcheader, fcpython, unit
    logical :: exist
    character(len=64) :: fpath

    version = get_version()
    write(output_unit, "(A)") "version = "//version

    write(output_unit, "(A)", advance="NO") "Opening files..."
    
    ! FORTRAN
    fpath = root//"/src/ciaaw_version.f90"
    inquire(file=fpath, exist=exist)
    if(exist)then
        open(file=fpath, newunit=unit, status="old")
        close(unit=unit, status="delete")
    endif
    open(file=fpath, newunit=ffortran, status="new", action="write")
    
    write(output_unit, "(A)", advance="YES") "OK"

    
    write(output_unit, "(A)", advance="NO") "Generating code..."
    call write_fortran_module_declaration(ffortran, version)
    call write_fortran_module_end(ffortran)
    write(output_unit, "(A)", advance="YES") "OK"
    
    close(ffortran)


end program