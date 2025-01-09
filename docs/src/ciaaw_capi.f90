module ciaaw__capi
    !! C API.
    !! See [specs](../page/specs/capi.html)
    use iso_c_binding, only: c_ptr, c_null_char, c_loc, c_double, c_int, c_bool, c_f_pointer
    use ciaaw__common
    use ciaaw__api
    implicit none
    private

    character(len=:), allocatable, target :: version_c

    public :: capi_get_version
    public :: capi_get_saw
    public :: capi_get_ice, capi_get_nice
    public :: capi_get_naw, capi_get_nnaw
    ! public :: capi_get_ice_values

contains

! ------------------------------------------------------------------------------
! VERSION 
function capi_get_version()bind(c, name='ciaaw_get_version')result(cptr)
    !! C API for [[ciaaw__api(module):get_version(function)]].
    
    type(c_ptr) :: cptr                   !! C pointer to a string indicating the version.

    character(len=:), pointer :: fptr     

    fptr => get_version() 

    if(allocated(version_c))then
        deallocate(version_c)
    endif
    allocate(character(len=len(fptr)+1) :: version_c)

    version_c = fptr // c_null_char
    cptr = c_loc(version_c)
end function
! ------------------------------------------------------------------------------


! ------------------------------------------------------------------------------
! SAW
function capi_get_saw(s, n, abridged, uncertainty)bind(C, name="ciaaw_get_saw")result(res)
    !! C API for [[ciaaw__api(module):get_saw(function)]].

    ! Arguments
    type(c_ptr), intent(in), value :: s               !! Symbol.
    integer(c_int), intent(in), value :: n            !! Size of the symbol string.
    logical(c_bool), intent(in), value :: abridged    !! Flag for setting if abridged value is desired.
    logical(c_bool), intent(in), value :: uncertainty !! Flag for setting if the uncertainty is desired instead of the value.
    
    ! Returns
    real(c_double) :: res 
    
    ! Variables
    integer(c_int) :: i
    character, pointer, dimension(:) :: c2f_s
    character(len=n) :: fs
    logical :: f_abridged, f_uncertainty
    
    
    call c_f_pointer(s, c2f_s, shape=[n])
    
    do i=1, n
        fs(i:i) = c2f_s(i)
    enddo

    f_abridged = logical(abridged)
    f_uncertainty = logical(uncertainty)

    res = get_saw(fs, f_abridged, f_uncertainty)
end function
! ------------------------------------------------------------------------------


! ------------------------------------------------------------------------------
! ICE 
function capi_get_ice(s, n, A, uncertainty)bind(C, name="ciaaw_get_ice")result(res)
    !! C API for [[ciaaw__api(module):get_ice(function)]]
    
    ! Arguments
    type(c_ptr), intent(in), value :: s                    !! Element symbol.
    integer(c_int), intent(in), value :: n                 !! Size of the symbol string.
    integer(c_int), intent(in), value :: A                 !! Mass number.
    logical(c_bool), intent(in), value :: uncertainty      !! Flag for returning the uncertainty instead of the value. Default to FALSE.

    ! Returns
    real(c_double) :: res
    
    ! Variables
    integer(c_int) :: i
    character, pointer, dimension(:) :: c2f_s
    character(len=n) :: fs
    logical :: f_uncertainty

    
    call c_f_pointer(s, c2f_s, shape=[n])
    
    do i=1, n
        fs(i:i) = c2f_s(i)
    enddo

    f_uncertainty = logical(uncertainty)

    res = get_ice(fs, A, f_uncertainty)
end function

function capi_get_nice(s,n)bind(C, name="ciaaw_get_nice")result(res)
    !! C API for [[ciaaw__api(module):get_nice(function)]]

    ! Arguments
    type(c_ptr), intent(in), value :: s           !! Element symbol.
    integer(c_int), intent(in), value :: n        !! Size of the symbol string.

    ! Returns
    integer(c_int) :: res

    ! Variables
    integer(c_int) :: i
    character, pointer, dimension(:) :: c2f_s
    character(len=n) :: fs
    
    call c_f_pointer(s, c2f_s, shape=[n])

    do i=1, n
        fs(i:i) = c2f_s(i)
    enddo

    res = get_nice(fs)
end function

! function capi_get_ice_values(s, n)bind(C, name="ciaaw_get_ice_values")result(res)
!     !! C API for [[ciaaw__api(module):get_ice_values(function)]]
    
!     ! Arguments
!     type(c_ptr), intent(in), value :: s           !! Element symbol.
!     integer(c_int), intent(in), value :: n        !! Size of the symbol string.

!     ! Returns
!     type(c_ptr) :: res

!     ! Variables
!     integer(c_int) :: i
!     character, pointer, dimension(:) :: c2f_s
!     character(len=n) :: fs
!     real(dp), pointer, contiguous :: fptr(:,:)
    
!     call c_f_pointer(s, c2f_s, shape=[n])

!     do i=1, n
!         fs(i:i) = c2f_s(i)
!     enddo

!     fptr => get_ice_values(fs)

!     res = c_loc(fptr)

! end function
! ------------------------------------------------------------------------------


! ------------------------------------------------------------------------------
! NAW 
function capi_get_naw(s, n, A, uncertainty)bind(C, name="ciaaw_get_naw")result(res)
    !! C API for [[ciaaw__api(module):get_naw(function)]]
    
    ! Arguments
    type(c_ptr), intent(in), value :: s                    !! Element symbol.
    integer(c_int), intent(in), value :: n                 !! Size of the symbol string.
    integer(c_int), intent(in), value :: A                 !! Mass number.
    logical(c_bool), intent(in), value :: uncertainty      !! Flag for returning the uncertainty instead of the value. Default to FALSE.

    ! Returns
    real(c_double) :: res
    
    ! Variables
    integer(c_int) :: i
    character, pointer, dimension(:) :: c2f_s
    character(len=n) :: fs
    logical :: f_uncertainty

    
    call c_f_pointer(s, c2f_s, shape=[n])
    
    do i=1, n
        fs(i:i) = c2f_s(i)
    enddo

    f_uncertainty = logical(uncertainty)

    res = get_naw(fs, A, f_uncertainty)
end function

function capi_get_nnaw(s,n)bind(C, name="ciaaw_get_nnaw")result(res)
    !! C API for [[ciaaw__api(module):get_nnaw(function)]]

    ! Arguments
    type(c_ptr), intent(in), value :: s           !! Element symbol.
    integer(c_int), intent(in), value :: n        !! Size of the symbol string.

    ! Returns
    integer(c_int) :: res

    ! Variables
    integer(c_int) :: i
    character, pointer, dimension(:) :: c2f_s
    character(len=n) :: fs
    
    call c_f_pointer(s, c2f_s, shape=[n])

    do i=1, n
        fs(i:i) = c2f_s(i)
    enddo

    res = get_nnaw(fs)
end function
! ------------------------------------------------------------------------------

end module ciaaw__capi
