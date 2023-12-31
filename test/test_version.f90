program test_version
    use ciaaw__version
    implicit none

    print "(A)", "***** TESTING FORTRAN CODE FOR VERSION *****"
    call test_version_number()

contains

subroutine test_version_number()
    implicit none

    character(len=len(ciaaw_version_version)) :: value = ciaaw_version_version
    character(len=len(ciaaw_version_version)) :: expected

    expected = "0.1.0"
    
    write(*, "(4X, A)", advance="no") "VERSION..."

    if(value /= expected)then
        write(*, "(A)", advance="yes") "Failed"
        write(*, "(4X, A, A, A)", advance="yes") value, '/', expected
        stop 1
    endif
    write(*, "(A)", advance="yes") "OK"

end subroutine

end program