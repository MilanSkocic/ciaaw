program generator
    use iso_fortran_env
    implicit none
    
    integer, parameter :: LENGTH_ELEMENT = 24
    integer, parameter :: LENGTH_SYMBOL = 8
    
    integer(int32), parameter :: LINE_LENGTH = 256 !! Length of line.

    ! Indexes for the table columns
    integer(int32), parameter :: cix_element(2) = [1, 20]
    integer(int32), parameter :: cix_symbol(2) = [21, 30]
    integer(int32), parameter :: cix_z(2) = [31, 40]
    integer(int32), parameter :: cix_saw(2) = [41, 70]
    integer(int32), parameter :: cix_saw_u(2) = [71, 90]
    integer(int32), parameter :: cix_footnote(2) = [91, 100]
    integer(int32), parameter :: cix_asaw(2) = [101, 110]
    integer(int32), parameter :: cix_asaw_u(2) = [111, 120]
    
    ! Properties of the file for the ciaaw saw data.
    type :: ciaaw_saw_file_props
        integer(int32) :: n !! Number of lines.
        integer(int32) :: index_header_end !! Number of lines for the header.
        character(len=18) :: fpath !! Filepath to the raw codata constants.
        character(len=6) :: year !! Year of release of the codata constants.
    end type

    type(ciaaw_saw_file_props) :: props
    character(len=*), parameter :: root = "../../"
    integer(int32) :: fciaaw, ffortran, fcheader, fcpython
    integer(int32) :: i
    integer(int32) :: unit
    logical :: exist
    character(len=64) :: fpath
    character(len=6), parameter :: years(2) = [character(len=6) :: "2021", "latest"]
    character(len=:), allocatable :: suffix

    do i=1, size(years)
        suffix = "_"//trim(years(i))

        print *, '########## SAW '//years(i)//' ##########' 
        props = ciaaw_saw_file_props(0, 0, './saw'//suffix//'.txt', years(i))

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
        fpath = root//'/src/ciaaw_saw'//suffix//'.f90'
        inquire(file=fpath, exist=exist)
        if(exist)then
            open(file=fpath, newunit=unit, status="old")
            close(unit=unit, status="delete")
        endif
        open(file=fpath, newunit=ffortran, status="new", action="write")
        
        ! C Header
        fpath = root//'/include/ciaaw_saw'//suffix//'.h'
        inquire(file=fpath, exist=exist)
        if(exist)then
            open(file=fpath, newunit=unit, status="old")
            close(unit=unit, status="delete")
        endif
        open(file=fpath, newunit=fcheader, status="new", action="write")
        
        ! CPython
        fpath = root//'pywrapper/src/pyciaaw/cpy_ciaaw_saw'//suffix//'.c'
        inquire(file=fpath, exist=exist)
        if(exist)then
            open(file=fpath, newunit=unit, status="old")
            close(unit=unit, status="delete")
        endif
        open(file=fpath, newunit=fcpython, status="new", action="write")
        write(output_unit, "(A)", advance="YES") "OK"

        write(output_unit, "(A)", advance="NO") "Generating code..."
        call write_fortran_module_declaration(ffortran, props%year)
        call write_C_header_declaration(fcheader, props%year)
        call write_cpython_extension_declaration(fcpython, props%year)
        call write_saw_data(fciaaw, ffortran, fcheader, fcpython, props)
        call write_fortran_module_end(ffortran, props%year)
        call write_C_header_end(fcheader)
        call write_cpython_extension_end(fcpython)
        write(output_unit, "(A)", advance="YES") "OK"

        close(fciaaw)
        close(ffortran)
        close(fcheader)
        print *, '########## SAW '//years(i)//' ##########'
    enddo

contains

subroutine write_fortran_module_declaration(fcode, year)
    !! Generate the Fortran module declaration.
    implicit none
    ! Arguments
    integer(int32), intent(in) :: fcode
        !! File unit of the Fortran module.
    character(len=*), intent(in) :: year
        !! Ciaaw year

    character(len=32) :: S_LENGTH_ELEMENT
    character(len=32) :: S_LENGTH_SYMBOL
    character(len=:), allocatable :: suffix
    
    write(S_LENGTH_ELEMENT, "(I2)") LENGTH_ELEMENT
    write(S_LENGTH_SYMBOL, "(I1)") LENGTH_SYMBOL
   
    suffix = trim("_"//year)
    write(fcode, "(A)") "!> @file"
    write(fcode, "(A)") '!> @brief CIAAW Standard Atomic Weights '//trim(year)//' -autogenerated'
    write(fcode, "(A)") ""
    write(fcode, "(A)") '!> @brief CIAAW Standard Atomic Weights '//trim(year)//' - autogenerated.'
    write(fcode, "(A)") "module ciaaw__saw"//suffix
    write(fcode, "(A)") "use iso_fortran_env"
    write(fcode, "(A)") "use iso_c_binding"
    write(fcode, "(A)") "use ieee_arithmetic"
    write(fcode, "(A)") "implicit none"
    write(fcode, "(A, /)") "private"
    write(fcode, "(A)") "integer(int64), parameter :: x = 1"
    write(fcode, "(A, /)") "real(real64), parameter :: nan = transfer(huge(x), 1.0d0)"

    if(year == "latest")then
        suffix = ''
    else
        suffix = trim('_'//props%year)
    endif
    write(fcode, "(A)") "!> @brief Object representing an element."
    write(fcode, "(A)") "type, public :: element_t"//suffix
    write(fcode, "(A)") 'character(len='//trim(S_LENGTH_ELEMENT)//') :: element !< Element name.'
    write(fcode, "(A)") 'character(len='//trim(S_LENGTH_SYMBOL)//') :: symbol !< Element symbol.'
    write(fcode, "(A)") 'integer(int32) :: z !< Element atomic number.'
    write(fcode, "(A)") 'real(real64) :: saw_min !< Min standard atomic weight.'
    write(fcode, "(A)") 'real(real64) :: saw_max !< Max standard atomic weight.'
    write(fcode, "(A)") 'real(real64) :: saw !< Value standard atomic weight.'
    write(fcode, "(A)") 'real(real64) :: saw_u !< Uncertainty standard atomic weight.'
    write(fcode, "(A)") 'real(real64) :: asaw !< Abridged value standard atomic weight.'
    write(fcode, "(A)") 'real(real64) :: asaw_u !< Abridged uncertainty standard atomic weight.'
    write(fcode, "(A)") "end type"
    write(fcode, "(A)") ""
    
    write(S_LENGTH_ELEMENT, "(I2)") LENGTH_ELEMENT+1
    write(S_LENGTH_SYMBOL, "(I1)") LENGTH_SYMBOL+1
    
    write(fcode, "(A)") "!> @brief Object representing an element."
    write(fcode, "(A)") "type, public, bind(C) :: capi_element_t"//suffix
    write(fcode, "(A)") 'character(kind=c_char) :: element('//trim(S_LENGTH_ELEMENT)//') !< Element name.'
    write(fcode, "(A)") 'character(kind=c_char) :: symbol('//trim(S_LENGTH_SYMBOL)//') !< Element symbol.'
    write(fcode, "(A)") 'integer(c_int) :: z !< Element atomic number.'
    write(fcode, "(A)") 'real(c_double) :: saw_min !< Min standard atomic weight.'
    write(fcode, "(A)") 'real(c_double) :: saw_max !< Max standard atomic weight.'
    write(fcode, "(A)") 'real(c_double) :: saw !< Value standard atomic weight.'
    write(fcode, "(A)") 'real(c_double) :: saw_u !< Uncertainty standard atomic weight.'
    write(fcode, "(A)") 'real(c_double) :: asaw !< Abridged value standard atomic weight.'
    write(fcode, "(A)") 'real(c_double) :: asaw_u !< Abridged uncertainty standard atomic weight.'
    write(fcode, "(A)") "end type"
    write(fcode, "(A)") ""
end subroutine

subroutine write_fortran_module_end(fcode, year)
    !! Generate the end of the Fortran module.
    implicit none
    ! Arguments
    integer(int32), intent(in) :: fcode
        !! File unit of the Fortran module.
    character(len=*), intent(in) :: year
        !! Codata year
    
    character(len=:), allocatable :: suffix
    
    suffix = trim("_"//year)
    write(fcode, "(A)") "end module ciaaw__saw"//suffix
end subroutine

subroutine write_C_header_declaration(fcode, year)
    !! Generate the C header declaration
    implicit none
    ! Arguments
    integer(int32), intent(in) :: fcode
        !! File unit of the C header.
    character(len=*), intent(in) :: year
        !! Codata year
    
    character(len=:), allocatable :: suffix
    
    character(len=32) :: S_LENGTH_ELEMENT
    character(len=32) :: S_LENGTH_SYMBOL
    
    write(S_LENGTH_ELEMENT, "(I2)") LENGTH_ELEMENT+1
    write(S_LENGTH_SYMBOL, "(I1)") LENGTH_SYMBOL+1

    suffix = trim("_"//year)
    write(fcode, "(A)") '/**'
    write(fcode, "(A)") '* @file'
    write(fcode, "(A) ") '* @brief C API Standard Atomic Weights '//trim(year)//' - autogenerated.'
    write(fcode, "(A)") "*/"
    write(fcode, "(A)") ""
    write(fcode, "(A)") '#ifndef CIAAW_SAW_H'//suffix
    write(fcode, "(A)") '#define CIAAW_SAW_H'//suffix
    write(fcode, "(A)") "#if _MSC_VER"
    write(fcode, "(A)") "#define ADD_IMPORT __declspec(dllimport)"
    write(fcode, "(A)") "#else"
    write(fcode, "(A)") "#define ADD_IMPORT"
    write(fcode, "(A)") "#endif"
    
    if(year == "latest")then
        suffix = ''
    else
        suffix = trim('_'//year)
    endif
    write(fcode, "(A)") "/** @brief C API Object representing an element.*/"
    write(fcode, "(A)") 'struct ciaaw_saw_element_t'//suffix//'{'
    write(fcode, "(4X, A)") 'char element['//trim(S_LENGTH_ELEMENT)//']; /**< Element name. */'
    write(fcode, "(4X, A)") 'char symbol['//trim(S_LENGTH_SYMBOL)//']; /**< Element symbol. */'
    write(fcode, "(4X, A)") 'int z; /**< Element atomic number. */'
    write(fcode, "(4X, A)") 'double saw_min; /**< Min standard atomic weight. */'
    write(fcode, "(4X, A)") 'double saw_max; /**< Max standard atomic weight. */'
    write(fcode, "(4X, A)") 'double saw; /**< Value standard atomic weight. */'
    write(fcode, "(4X, A)") 'double saw_u; /**< Uncertainty standard atomic weight. */'
    write(fcode, "(4X, A)") 'double asaw; /**< Abridged value standard atomic weight. */'
    write(fcode, "(4X, A)") 'double asaw_u; /**< Abridged uncertainty standard atomic weight. */'
     write(fcode, "(A)") '};'
    
end subroutine

subroutine write_C_header_end(fcode)
    !! Generate the C header declaration
    implicit none
    ! Arguments
    integer(int32), intent(in) :: fcode
        !! File unit of the C header.
    write(fcode, "(A)") '#endif'
    write(fcode, "(A)") ''
    
end subroutine

subroutine write_cpython_extension_declaration(fcode, year)
    !! Generate the cpython module declaration.
    implicit none
    integer(int32), intent(in) :: fcode
        !! File unit of the Python module.
    character(len=*), intent(in) :: year
        !! Codata year

    character(len=:), allocatable :: suffix

    suffix = trim("_"//year)
    write(fcode, "(A)") "#define PY_SSIZE_T_CLEAN"
    write(fcode, "(A)") "#include <Python.h>"
    write(fcode, "(A)") '#include "ciaaw_saw'//suffix//'.h"'
    write(fcode, "(A)") ""
    write(fcode, "(A)") 'PyDoc_STRVAR(module_docstring, "C extension for saw '//trim(year)//'.");'
    write(fcode, "(A)") ""
    write(fcode, "(A)") "static PyMethodDef myMethods[] = {{ NULL, NULL, 0, NULL }};"
    write(fcode, "(A)") ""
    write(fcode, "(A)", advance='NO') 'static struct PyModuleDef saw'//suffix//' = '
    write(fcode, "(A)") '{PyModuleDef_HEAD_INIT, "saw'//suffix//'", module_docstring, -1, myMethods};'
    write(fcode, "(A)") ""
    write(fcode, "(A)") 'PyMODINIT_FUNC PyInit_saw'//suffix//'(void){'
    write(fcode, "(4X, A)") "PyObject *m;"
    write(fcode, "(4X, A)") "PyObject *d;"
    write(fcode, "(4X, A)") "PyObject *v;"
    write(fcode, "(4X, A)") "PyObject *element;"
    write(fcode, "(4X, A)") 'm = PyModule_Create(&saw'//suffix//');'
    write(fcode, "(4X, A)") "d = PyModule_GetDict(m);"
    write(fcode, "(A)") ""
end subroutine

subroutine write_cpython_extension_end(fcode)
    !! Generate the cpython module end.
    implicit none
    integer(int32), intent(in) :: fcode
        !! File unit of the Python module.
    write(fcode, "(4X, A)") "return m;"
    write(fcode, "(A)") "}"
end subroutine

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

subroutine write_saw_data(fciaaw, ffortran, fcheader, fcpython, props)
    !! Generate the fortran code for ciaaw__saw.
    implicit none
    ! Arguments
    integer(int32), intent(in) :: fciaaw
        !! File unit of the ciaaw data.
    integer(int32), intent(in) :: ffortran
        !! File unit of the Fortran module.
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
    character(len=64) :: name_binding
    
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
    
    integer(int32) :: i, n, j, ix_trim, ix_comma, ix_rbracket
    
    character(len=:), allocatable :: suffix
    character(len=:), allocatable :: year_value

    if(props%year == "latest")then
        suffix = ''
        year_value = years(1)
    else
        suffix = trim('_'//props%year)
        year_value = trim(props%year)
    endif
    
    rewind(unit=fciaaw)
    do i=1, props%index_header_end
        read(fciaaw, "(A)") line
    end do

    ! fortran
    write(ffortran, "(A)") 'integer(int32), parameter, public :: YEAR'//suffix//' = '//year_value//' !< Year of saw'
    write(ffortran, "(A,A,/)") 'integer(c_int), protected, bind(C,name="YEAR'//suffix//'") ::',&
                              'capi_YEAR'//suffix//' = YEAR'//suffix//' !< C API Year of saw'
    ! C HEADER
    write(fcheader, "(A,/)") &
    'ADD_IMPORT extern const int YEAR'//suffix//'; /**< C API Publication year. */'
    ! cpython
    write(fcpython, "(4X, A)") 'v = PyLong_FromLong(YEAR'//suffix//');'
    write(fcpython, "(4X, A)") 'PyDict_SetItemString(d, "YEAR'//suffix//'", v);'
    write(fcpython, "(4X, A)") "Py_INCREF(v);"
    write(fcpython, "(A)") ""

    do i=1, props%n
        call clean_line(line)
        read(fciaaw, "(A)") line
        if(len(trim(line))>0)then
            read(line(cix_element(1): cix_element(2)), "(A)") element
            read(line(cix_symbol(1): cix_symbol(2)), "(A)") symbol
            read(line(cix_z(1): cix_z(2)), "(A)") z
            ! read(line(cix_saw_min(1): cix_saw_min(2)), "(A)") saw_min
            ! read(line(cix_saw_max(1): cix_saw_max(2)), "(A)") saw_max
            read(line(cix_saw(1): cix_saw(2)), "(A)") saw
            read(line(cix_saw_u(1): cix_saw_u(2)), "(A)") saw_u
            read(line(cix_asaw(1): cix_asaw(2)), "(A)") asaw
            read(line(cix_asaw_u(1): cix_asaw_u(2)), "(A)") asaw_u

            compute = .false.
            if(saw(1:1) == '[')then
                compute = .true.
                ix_comma = index(saw,',')
                ix_rbracket = index(saw, "]")
                saw_min = trim(saw(2:ix_comma-1))//'d0'
                saw_max = trim(saw(ix_comma+1:ix_rbracket-1))//'d0'
            endif
            
            if(compute)then
                read(saw_max, "(D20.10)") saw_max_db
                read(saw_min, "(D20.10)") saw_min_db
                
                saw_value_db = (saw_max_db + saw_min_db)/2.0d0
                saw_u_db = (saw_max_db - saw_min_db)/(2.0d0*sqrt(3.0d0))
                
                n = floor(log10(saw_u_db))
                saw_u_db = ceiling(saw_u_db * 10**(-n*1.0d0))*10**(n*1.0d0)
                
                write(out_format, "(A, I1, A)") "(F29.", -n, ", A)"
                write(saw, out_format) saw_value_db, "d0"
                write(saw_u, out_format) saw_u_db, "d0"
            else
                saw_max = "nan"
                saw_min = "nan"
                if(trim(saw) == "nan")then
                    saw = trim(saw)
                else
                    saw = trim(saw) //'d0'
                end if
                if(trim(saw_u) == "nan")then
                    saw_u = trim(saw_u)
                else
                    saw_u = trim(saw_u) //'d0'
                end if
            end if
            if(trim(asaw) == "nan")then
                asaw = trim(asaw)
            else
                asaw = trim(asaw)//'d0'
            end if
            if(trim(asaw_u) == "nan")then
                asaw_u = trim(asaw_u)
            else
                asaw_u = trim(asaw_u)//'d0'
            end if
            
            ! Fortran
            name = trim(symbol)//suffix
            write(ffortran, '(A)') '!> ' // trim(element) // "."
            write(ffortran, "(A)") 'type(element_t'//suffix//'), parameter, public :: '//trim(name)//' =&'
            write(ffortran, "(A)", advance='NO') 'element_t'//suffix//'("'//trim(element)//'",'
            write(ffortran, "(A)", advance='NO') '"'//trim(symbol)//'", '//trim(z)//", "
            write(ffortran, "(A)", advance='NO') trim(saw_min)// ", "//trim(saw_max)//", "
            write(ffortran, "(A)", advance='NO') trim(adjustl(saw))//", "//trim(adjustl(saw_u))//", "
            write(ffortran, "(A)", advance='YES') trim(asaw)//", "//trim(asaw_u)//')'

            ! Fortran C API
            name_capi = "capi_"//trim(symbol)//suffix
            name_binding = 'ciaaw_saw_'//trim(symbol)//suffix
            write(ffortran, '(A)') '!> C API ' // trim(element) // "."
            write(ffortran, "(A)", advance="NO") 'type(capi_element_t'//suffix//'), protected, '
            write(ffortran, "(A)", advance="YES") 'bind(C, name="'//trim(name_binding)//'") :: '//trim(name_capi)//' =&'
            write(ffortran, "(A)", advance="YES")  'capi_element_t'//suffix//'(&'
            ix_trim = len(trim(element))
            write(ffortran, "(A)", advance="NO") '['
            do j=1, ix_trim
                 write(ffortran, "(A)", advance="NO") '"'//element(j:j)//'",'
            end do
            write(ffortran, "(A)", advance='NO') 'c_null_char, '
            do j=(ix_trim+2), len(element)-1
                 write(ffortran, "(A)", advance="NO") '"'//element(j:j)//'",'
            end do
            write(ffortran, "(A)", advance="YES") '" "], &'
            
            ix_trim = len(trim(symbol))
            write(ffortran, "(A)", advance="NO") '['
            do j=1, ix_trim
                write(ffortran, "(A)", advance="NO") '"'//symbol(j:j)//'",'
            end do
            write(ffortran, "(A)", advance='NO') 'c_null_char, '
            do j=(ix_trim+2), len(symbol)-1
                 write(ffortran, "(A)", advance="NO") '"'//symbol(j:j)//'",'
            end do
            write(ffortran, "(A)", advance="YES") '" "], &'

            write(ffortran, "(A)", advance="YES") trim(name)//"%z, &"
            write(ffortran, "(A)", advance="NO") trim(name)//"%saw_max, "//trim(name)//"%saw_min, "
            write(ffortran, "(A)", advance="NO") trim(name)//"%saw, "//trim(name)//"%saw_u, "
            write(ffortran, "(A)") trim(name)//"%asaw, "//trim(name)//"%asaw_u)"
            write(ffortran, '(A)') ""

            ! C Header
            name = "ciaaw_saw_"//trim(symbol)//suffix
        write(fcheader, "(A)", advance='NO') 'ADD_IMPORT extern const struct ciaaw_saw_element_t'//suffix//' '//trim(name)//';'
            write(fcheader, '(A)') '/**< C API '//trim(symbol)//suffix//'.*/'

            ! Cpython
            name_capi = "ciaaw_saw_"//trim(symbol)//suffix
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
    write(fcheader, '(A)') ''

end subroutine

end program
