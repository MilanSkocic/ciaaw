module ciaaw__capi
    !! C API.
    use iso_c_binding, only: c_ptr, c_null_char, c_loc, c_double, c_int, c_bool, c_f_pointer
    use ciaaw__api
    use ciaaw__version, only: get_version
    implicit none
    private

    character(len=:), allocatable, target :: version_c

    public :: capi_get_version, capi_get_saw

contains


! VERSION
function capi_get_version()bind(c, name='ciaaw_get_version')result(cptr)
    !! Get the version
    implicit none
    type(c_ptr) :: cptr
        !! C pointer to a string indicating the version.

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

end module ciaaw__capi
