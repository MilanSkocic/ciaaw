!> @file
!! @brief Version module

!> @brief Version module.
module ciaaw__version
!! Version
use iso_fortran_env
use iso_c_binding
implicit none
private

character(len=*), parameter :: version = "0.1.0"
character(len=:), allocatable, target :: version_f
character(len=:), allocatable, target :: version_c

public :: get_version

contains

!> @brief Get the version
!! @return fptr Pointer to the version string.
function get_version()result(fptr)
    !! Get the version. 
    implicit none

    !! Returns
    character(len=:), pointer :: fptr
        !! Pointer to the version string.

    if(allocated(version_f))then
        deallocate(version_f)
    endif
    allocate(character(len=len(version)) :: version_f)
    version_f = version
    fptr => version_f    
end function

!> @brief Get the version
!! @return cptr Pointer to the version string.
function capi_get_version()bind(c,name="ciaaw_get_version")result(cptr)
    implicit none
    type(c_ptr) :: cptr

    character(len=:), pointer :: fptr
    fptr => get_version() 

    if(allocated(version_c))then
        deallocate(version_c)
    endif
    allocate(character(len=len(fptr)+1) :: version_c)

    version_c = fptr // c_null_char
    cptr = c_loc(version_c)
end function

end module ciaaw__version
