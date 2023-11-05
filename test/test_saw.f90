program test_g704
    use iso_fortran_env
    use ciaaw__saw
    implicit none

    print "(A)", "***** TESTING FORTRAN CODE FOR SAW *****"

    call test_saw()

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

subroutine test_saw()
    implicit none

    character(len=2) :: element = "H"
    real(real64) :: value
    real(real64) :: expected
    real(real64) :: diff
    write(*, "(4X, A)", advance="no") "saw..."
    value  = ciaaw_saw_H%saw
    expected = 12.011d0
    diff = value - expected
    diff = roundn(diff, 4)
    if(.not. assertEqual(diff, 0.0d0, 4))then
        write(*, "(A)", advance="yes") "Failed"
        write(*, "(4X, A, 4X, SP, F23.16, A1, F23.16, A1, F23.16)", advance="yes") &
        element, value, "/", expected, "/", diff
        stop 1
    endif
    write(*, "(A)", advance="yes") "OK"
    
end subroutine

end program