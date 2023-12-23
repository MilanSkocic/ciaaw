program test_g704
    use iso_fortran_env
    use ciaaw__saw
    use test__common
    implicit none

    print "(A)", "***** TESTING FORTRAN CODE FOR ASAW *****"

    call test_asaw()

contains

subroutine test_asaw()
    implicit none

    integer(int32), parameter :: N=2
    integer(int32) :: i
    type(ciaaw_saw_element_t) :: elements(N)
    real(real64) :: value
    real(real64) :: expected(N)
    real(real64) :: diff
    write(*, "(4X, A)", advance="no") "ASAW..."

    elements(1) = ciaaw_saw_H
    elements(2) = ciaaw_saw_C

    expected(1) = 1.008d0
    expected(2) = 12.011d0

    do i=1, size(elements)
        value  = elements(i)%asaw
        diff = value - expected(i)
        diff = roundn(diff, 16)
        if(.not. assertEqual(diff, 0.0d0, 16))then
            write(*, "(A)", advance="yes") "Failed"
            write(*, "(4X, A, 4X, SP, F23.16, A1, F23.16, A1, F23.16)", advance="yes") &
            elements(i)%symbol, value, "/", expected(i), "/", diff
            stop 1
    endif
    
    end do
    
    write(*, "(A)", advance="yes") "OK"
    
end subroutine

end program