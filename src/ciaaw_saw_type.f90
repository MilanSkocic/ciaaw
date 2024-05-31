module ciaaw__saw_type
    !! Derived types for Standard Atomic Weights. 
    use iso_fortran_env
    use iso_c_binding
    implicit none
    private

    type, public :: saw_element_type
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
        character(len=8) :: footnote !! Footnotes
    end type

end module ciaaw__saw_type
