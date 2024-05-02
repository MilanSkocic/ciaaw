!> @file
!> @brief Derived types for Standard Atomic Weights. 

!> @brief Derived types for Standard Atomic Weights. 
module ciaaw__saw_type
use iso_fortran_env
use iso_c_binding
implicit none
private

!> @brief Derived type representing an element.
type, public :: element_t
character(len=24) :: element !< Element name.
character(len=8) :: symbol !< Element symbol.
integer(int32) :: z !< Element atomic number.
real(real64) :: saw_min !< Min standard atomic weight.
real(real64) :: saw_max !< Max standard atomic weight.
real(real64) :: saw !< Value standard atomic weight.
real(real64) :: saw_u !< Uncertainty standard atomic weight.
real(real64) :: asaw !< Abridged value standard atomic weight.
real(real64) :: asaw_u !< Abridged uncertainty standard atomic weight.
end type

!> @brief Derived type representing an element.
type, public, bind(C) :: capi_element_t
character(kind=c_char) :: element(25) !< Element name.
character(kind=c_char) :: symbol(9) !< Element symbol.
integer(c_int) :: z !< Element atomic number.
real(c_double) :: saw_min !< Min standard atomic weight.
real(c_double) :: saw_max !< Max standard atomic weight.
real(c_double) :: saw !< Value standard atomic weight.
real(c_double) :: saw_u !< Uncertainty standard atomic weight.
real(c_double) :: asaw !< Abridged value standard atomic weight.
real(c_double) :: asaw_u !< Abridged uncertainty standard atomic weight.
end type

end module ciaaw__saw_type
