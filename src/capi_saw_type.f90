module capi__saw_type
    !! Ciaaw saw type: C API.
    use iso_c_binding, only: c_char, c_double, c_int
    implicit none
    private

    type, public, bind(C) :: capi_saw_type
        !! Derived type representing an element in C.
        character(kind=c_char) :: element(25) !! Element name.
        character(kind=c_char) :: symbol(9) !! Element symbol.
        integer(c_int) :: z !! Element atomic number.
        real(c_double) :: saw_min !! Min standard atomic weight.
        real(c_double) :: saw_max !! Max standard atomic weight.
        real(c_double) :: saw !! Value standard atomic weight.
        real(c_double) :: saw_u !! Uncertainty standard atomic weight.
        real(c_double) :: asaw !! Abridged value standard atomic weight.
        real(c_double) :: asaw_u !! Abridged uncertainty standard atomic weight.
        character(kind=c_char) :: footnotes(9) !! Footnotes
    end type

end module capi__saw_type
