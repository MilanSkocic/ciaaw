module ciaaw__types
!! Derived types for Standard Atomic Weights.
use ciaaw__common, only: int32, dp
implicit none(type,external)
private

integer(int32), parameter :: NROWS_ICE = 10
integer(int32), parameter :: NROWS_NAW = 50


!=======================================================================
! SAW_TYPE
!=======================================================================
type, public :: saw_type
!! Derived type representing the standard atomic weight of an element.
real(dp) :: saw_min !! Min standard atomic weight.
real(dp) :: saw_max !! Max standard atomic weight.
real(dp) :: saw !! Value standard atomic weight.
real(dp) :: saw_u !! Uncertainty standard atomic weight.
real(dp) :: asaw !! Abridged value standard atomic weight.
real(dp) :: asaw_u !! Abridged uncertainty standard atomic weight.
end type saw_type
!=======================================================================


!=======================================================================
! ICE_TYPE
!=======================================================================
type, public :: ice_type
!! Derived type reprensenting the isotopic abundance.
integer(int32) :: n               !! Number of isotopic compositions
real(dp) :: values(NROWS_ICE, 3)  !! Mass numbers, Abundance, Uncertainty
end type ice_type
!=======================================================================


!=======================================================================
! NAW_TYPE
!=======================================================================
type, public :: naw_type
!! Derived type reprensenting the nuclide's atomic weights.
integer(int32) :: n               !! Number of atomic weights
real(dp) :: values(NROWS_NAW, 3)  !! Mass numbers, Atomic weight, Uncertainty
end type naw_type
!=======================================================================


!=======================================================================
! ELEMENT_TYPE
!=======================================================================
type, public :: element_type
!! Derived type representing an element.
character(len=24) :: element  !! Element name.
character(len=8) :: symbol    !! Element symbol.
integer(int32) :: z           !! Element atomic number.
type(saw_type) :: saw         !! Standard atomic weights   
type(ice_type) :: ice         !! Isotopic composition of the element
type(naw_type) :: naw         !! Atomic weight of the nuclide
end type element_type
!=======================================================================


!=======================================================================
! NAN VALUE FOR ICE EMPTY ENTRY
!=======================================================================
type(ice_type), parameter, public :: ice_nan = &
ice_type(0,transpose(reshape([&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp &
], shape=[3, 10])))
!=======================================================================
end module ciaaw__types
