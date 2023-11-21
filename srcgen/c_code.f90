module c_code
    ! Module for generating C header
    use fortran_code

contains

subroutine write_C_header_declaration(fcode)
    !! Generate the C header declaration
    implicit none
    ! Arguments
    integer(int32), intent(in) :: fcode
        !! File unit of the C header.
    character(len=32) :: S_LENGTH_ELEMENT
    character(len=32) :: S_LENGTH_SYMBOL
    
    write(S_LENGTH_ELEMENT, "(I2)") LENGTH_ELEMENT+1
    write(S_LENGTH_SYMBOL, "(I1)") LENGTH_SYMBOL+1
    
    write(fcode, "(A)") '#ifndef CIAAW_SAW_H'
    write(fcode, "(A)") '#define CIAAW_SAW_H'

    write(fcode, "(A)") 'struct ciaaw_saw_capi_elmt_t{'
    write(fcode, "(4X, A)") 'char element['//trim(S_LENGTH_ELEMENT)//'];'
    write(fcode, "(4X, A)") 'char symbol['//trim(S_LENGTH_SYMBOL)//'];'
    write(fcode, "(4X, A)") 'int z;'
    write(fcode, "(4X, A)") 'double saw_min;'
    write(fcode, "(4X, A)") 'double saw_max;'
    write(fcode, "(4X, A)") 'double saw;'
    write(fcode, "(4X, A)") 'double saw_u;'
    write(fcode, "(4X, A)") 'double asaw;'
    write(fcode, "(4X, A)") 'double asaw_u;'
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


end module