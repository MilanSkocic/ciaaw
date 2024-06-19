module ciaaw__saw_type
    !! Derived types for Standard Atomic Weights. 
    use stdlib_kinds, only: dp, int32
    implicit none
    private

    type, public :: saw_type
        !! Derived type representing the saw of an element.
        character(len=24) :: element !! Element name.
        character(len=8) :: symbol !! Element symbol.
        integer(int32) :: z !! Element atomic number.
        real(dp) :: saw_min !! Min standard atomic weight.
        real(dp) :: saw_max !! Max standard atomic weight.
        real(dp) :: saw !! Value standard atomic weight.
        real(dp) :: saw_u !! Uncertainty standard atomic weight.
        real(dp) :: asaw !! Abridged value standard atomic weight.
        real(dp) :: asaw_u !! Abridged uncertainty standard atomic weight.
        character(len=8) :: footnotes !! Footnotes
    end type

end module ciaaw__saw_type
