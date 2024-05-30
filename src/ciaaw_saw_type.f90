module ciaaw__saw_type
    !! Derived types for Standard Atomic Weights. 
    use iso_fortran_env
    use iso_c_binding
    implicit none
    private

    type, public :: element_t
        !! Derived type representing an element.
        character(len=24) :: element !! Element name.
        character(len=8) :: symbol !! Element symbol.
        integer(int32) :: z !! Element atomic number.
        real(real64) :: saw_min !! Min standard atomic weight.
        real(real64) :: saw_max !! Max standard atomic weight.
        real(real64) :: saw !! Value standard atomic weight.
        real(real64) :: saw_u !! Uncertainty standard atomic weight.
        real(real64) :: asaw !! Abridged value standard atomic weight.
        real(real64) :: asaw_u !! Abridged uncertainty standard atomic weight.
    end type

    type, public, bind(C) :: capi_element_t
        !! Derived type representing an element in C API.
        character(kind=c_char) :: element(25) !! Element name.
        character(kind=c_char) :: symbol(9) !! Element symbol.
        integer(c_int) :: z !! Element atomic number.
        real(c_double) :: saw_min !! Min standard atomic weight.
        real(c_double) :: saw_max !! Max standard atomic weight.
        real(c_double) :: saw !! Value standard atomic weight.
        real(c_double) :: saw_u !! Uncertainty standard atomic weight.
        real(c_double) :: asaw !! Abridged value standard atomic weight.
        real(c_double) :: asaw_u !! Abridged uncertainty standard atomic weight.
    end type

end module ciaaw__saw_type
