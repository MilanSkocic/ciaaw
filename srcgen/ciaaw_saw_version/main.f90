program generator
    use iso_fortran_env
    use core
    use ciaaw_version_f90
    use ciaaw_version_h
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
    
    ! C API
    fpath = root // "/src/ciaaw_version_capi.f90"
    inquire(file=fpath, exist=exist)
    if(exist)then
        open(file=fpath, newunit=unit, status="old")
        close(unit=unit, status="delete")
    endif
    open(file=fpath, newunit=ffortran_capi, status="new", action="write")

    ! C HEADER
    fpath = root//"/include/ciaaw_version.h"
    inquire(file=fpath, exist=exist)
    if(exist)then
        open(file=fpath, newunit=unit, status="old")
        close(unit=unit, status="delete")
    endif
    open(file=fpath, newunit=fcheader, status="new", action="write")
    
    write(output_unit, "(A)", advance="YES") "OK"

    
    write(output_unit, "(A)", advance="NO") "Generating code..."
    call write_fortran_module_declaration(ffortran, version)
    call write_fortran_capi_module_declaration(ffortran_capi, version)
    call write_C_header_declaration(fcheader, version)
    call write_fortran_module_end(ffortran)
    call write_fortran_capi_module_end(ffortran_capi)
    call write_C_header_end(fcheader)
    write(output_unit, "(A)", advance="YES") "OK"
    
    close(ffortran)
    close(ffortran_capi)
    close(fcheader)


end program