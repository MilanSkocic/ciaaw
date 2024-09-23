module ciaaw__capi
    !! C API.
    use iso_c_binding, only: c_ptr, c_null_char, c_loc, c_double, c_int
    use ciaaw__pte
    use ciaaw__version, only: get_version
    implicit none
    private

    character(len=:), allocatable, target :: version_c

    public :: capi_get_version

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
function capi_get_asaw(z)bind(c, name="ciaaw_get_asaw")result(res)
    !! Get abridged standard atomic value by atomic number z.
    !! Returns -1 if the element is not found.
    integer(c_int), intent(in), value :: z

    real(c_double) :: res 

    res = get_asaw(z)
    
end function

end module ciaaw__capi
