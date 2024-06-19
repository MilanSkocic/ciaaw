module ciaaw__version
    !! Version
    implicit none
    private

    character(len=*), parameter :: version = "0.4.2"
    character(len=:), allocatable, target :: version_f
    character(len=:), allocatable, target :: version_c

    public :: get_version

contains

function get_version()result(fptr)
    !! Get the version
    implicit none
    character(len=:), pointer :: fptr
        !! Fortran pointer to a string indicating the version..

    if(allocated(version_f))then
        deallocate(version_f)
    endif
    allocate(character(len=len(version)) :: version_f)
    version_f = version
    fptr => version_f    
end function

end module ciaaw__version
