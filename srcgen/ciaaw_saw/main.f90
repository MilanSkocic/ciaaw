program generator
    use iso_fortran_env
    use core
    use ciaaw_saw_f90
    use ciaaw_saw_h
    use ciaaw_saw_cpy
    use ciaaw_saw_writer
    implicit none

    character(len=*), parameter :: root = "../../"
    integer(int32) :: fciaaw, ffortran, ffortran_capi, fcheader, fcpython
    integer(int32) :: unit
    logical :: exist
    character(len=64) :: fpath
    type(ciaaw_saw_file_props) :: props

    props = ciaaw_saw_file_props(0, 0, "./ciaaw_2021.txt", "2021")

    print *, "Reading ciaaw file properties..."
    call get_props(props)
    print "(4X, A, I3)", "Number of constants: ", props%n
    print "(4X, A, I2)", "Header Offset: ", props%index_header_end
    print "(4X, A, A)", "fpath: ", props%fpath
    print "(4X, A, A)", "Year: ", props%year

    write(output_unit, "(A)", advance="NO") "Opening files..."
    ! CIAAW SAW SOURCE
    open(file=props%fpath, newunit=fciaaw, status="old", action="read")
    
    ! FORTRAN
    fpath = root//"/src/ciaaw_saw.f90"
    inquire(file=fpath, exist=exist)
    if(exist)then
        open(file=fpath, newunit=unit, status="old")
        close(unit=unit, status="delete")
    endif
    open(file=fpath, newunit=ffortran, status="new", action="write")
    
    ! C API
    fpath = root // "/src/ciaaw_saw_capi.f90"
    inquire(file=fpath, exist=exist)
    if(exist)then
        open(file=fpath, newunit=unit, status="old")
        close(unit=unit, status="delete")
    endif
    open(file=fpath, newunit=ffortran_capi, status="new", action="write")

    ! C Header
    fpath = root//"/include/ciaaw_saw.h"
    inquire(file=fpath, exist=exist)
    if(exist)then
        open(file=fpath, newunit=unit, status="old")
        close(unit=unit, status="delete")
    endif
    open(file=fpath, newunit=fcheader, status="new", action="write")
    
    ! CPython
    fpath = root//"pywrapper/pyciaaw/ciaaw_saw.c"
    inquire(file=fpath, exist=exist)
    if(exist)then
        open(file=fpath, newunit=unit, status="old")
        close(unit=unit, status="delete")
    endif
    open(file=fpath, newunit=fcpython, status="new", action="write")
    write(output_unit, "(A)", advance="YES") "OK"

    write(output_unit, "(A)", advance="NO") "Generating code..."
    call write_fortran_module_declaration(ffortran)
    call write_fortran_capi_module_declaration(ffortran_capi)
    call write_C_header_declaration(fcheader)
    call write_cpython_extension_declaration(fcpython)
    call write_saw_data(fciaaw, ffortran, ffortran_capi, fcheader, fcpython, props)
    call write_fortran_module_end(ffortran)
    call write_fortran_capi_module_end(ffortran_capi)
    call write_C_header_end(fcheader)
    call write_cpython_extension_end(fcpython)
    write(output_unit, "(A)", advance="YES") "OK"

    close(fciaaw)
    close(ffortran)
    close(ffortran_capi)
    close(fcheader)

end program