program test_g704
    use iso_fortran_env
    use ciaaw__saw
    implicit none

    print "(A)", "***** TESTING FORTRAN CODE FOR ASAW *****"

    call test_asaw()

contains

pure elemental function roundn(x, n)result(r)
    implicit none
    real(real64), intent(in) :: x
    integer(int32), intent(in) :: n
    real(real64) :: r
    real(real64) :: fac

    fac = 10**n
    r = nint(x*fac, kind=kind(x)) / fac
end function

 function assertEqual(x1, x2, n)result(r)
    implicit none
    real(real64), intent(in) :: x1
    real(real64), intent(in) :: x2
    integer(int32), intent(in) :: n
    logical :: r

    real(real64) :: fac
    real(real64) :: ix1
    real(real64) :: ix2
    
    fac = 10**n
    ix1 = nint(x1 * fac, kind=kind(n))
    ix2 = nint(x2 * fac, kind=kind(n))
    r = ix1 == ix2


end function

subroutine test_asaw()
    implicit none

    integer(int32), parameter :: N=2
    integer(int32) :: i
    type(ciaaw_saw_elmt_t) :: elements(N)
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