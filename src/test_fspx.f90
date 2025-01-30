module test_fspx
    !! Module documentation
    use iso_fortran_env
    implicit none

    real(real64), parameter :: P1 = 1.0_real64 !! Parameter docstring


contains

pure function test_1(a)result(res)
    !! Function docstring.
    !!
    !! The specified result for the function appears as an argument.
    !! Multi-line docstring does not seem to be recognized.

    
    ! Arguments
    real(real64), intent(in) :: a !! Argument for the function

    ! Returns
    real(real64) :: res !! Returned value

    res = a + 1
end function


subroutine test_2(a, b)
    !! docstring

    ! Arguments
    real(real64), intent(in) :: a !! Argument a
    real(real64), intent(out) :: b !! Argument b

    ! local variables
    real(real64) :: local_i  !! Appears as argument even if it is a local variable
    character(len=25) :: s !! Appears as argument even if it is a local variable

end subroutine

real(real64) function test_3(a)result(res)
    !! Function docstring.
    !!
    !! The specified result for the function appears as an argument.
    !! Multi-line docstring does not seem to be recognized.

    
    ! Arguments
    real(real64), intent(in) :: a !! Argument for the function


    test_f3 = a + 1
end function

end module

