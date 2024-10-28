module ciaaw__capi
    !! C API.
    !! See [specs](../page/specs/capi.html)
    use iso_c_binding, only: c_ptr, c_null_char, c_loc, c_double, c_int, c_bool, c_f_pointer
    use ciaaw__api
    use ciaaw__version, only: get_version
    implicit none
    private

    character(len=:), allocatable, target :: version_c

    public :: capi_get_version, capi_get_saw, capi_get_nice

contains


! VERSION
function capi_get_version()bind(c, name='ciaaw_get_version')result(cptr)
    !! Get the version
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


! SAW
function capi_get_saw(s, n, abridged, uncertainty)bind(C, name="ciaaw_get_saw")result(res)
    !! C API.
    !! Get the standard atomic weight. By default the abridged value is provided.
    !! If the non abridged value is desired, set abridged to false.
    !! The uncertainty instead of the value can be retrieved if the uncertainty is set to true.
    !! Returns NaN if provided symbol is incorrect or -1 if the element does not have a standard atomic weight.

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


function capi_get_ice(s, n, A, uncertainty)bind(C, name="ciaaw_get_ice")result(res)
    !! C API.
    !! Get the isotopic composition of the element for the mass number A. 
    !! The uncertainty instead of the value can be retrieved if the uncertainty is set to true.
    !! Returns NaN if provided symbol or A are incorrect or -1 if the element does not have an ICE.
    
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
    !! C API.
    !! Get the number of isotopes in ICE.
    !! Returns -1 if the provided symbol is incorrect.

    ! Arguments
    type(c_ptr), intent(in), value :: s                    !! Element symbol.
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

end module ciaaw__capi
