program test_version
    use ciaaw__version
    implicit none

    print "(A)", "***** TESTING FORTRAN CODE FOR VERSION *****"
    call test_version_number()

contains

subroutine test_version_number()
    implicit none

    character(len=len(ciaaw_version_version)) :: value = ciaaw_version_version
    character(len=len(ciaaw_version_version)) :: reference

    reference = "0.1.0"
    
    write(*, "(4X, A)", advance="no") "VERSION..."

    if(value /= reference)then
        write(*, "(A)", advance="yes") "Failed"
        write(*, "(4X, A, A)", advance="yes") value, reference
        stop 1
    endif
    write(*, "(A)", advance="yes") "OK"

end subroutine

end program