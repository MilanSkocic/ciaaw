module cciaaw__saw_type
    !! Ciaaw saw type

    type, public, bind(C) :: cciaaw_saw_element_type
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
    end type

end module cciaaw__saw_type
