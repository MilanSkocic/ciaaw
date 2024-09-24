module testsuite_saw
    !! Test saw
    use iso_fortran_env
    use testdrive, only : new_unittest, unittest_type, error_type, check
    use ciaaw
    implicit none
    private
    
    public :: collect_suite_saw

contains

subroutine collect_suite_saw(testsuite)
  type(unittest_type), allocatable, intent(out) :: testsuite(:)
  testsuite = [new_unittest("ASAW", test_asaw)]
end subroutine


subroutine test_asaw(error)
    implicit none
    integer(int32), parameter :: N = 3
    type(error_type), allocatable, intent(out) :: error 
    integer(int32) :: z(3) = [1, 6,  10]
    real(real64) :: expected_asaw(N) = [1.0080d0, 12.011d0, 20.180d0]

    integer(int32) :: i
    real(real64) :: value, expected

    do i=1, N
        value = get_asaw(z(i))
        expected = expected_asaw(i)
        call check(error, value, expected)
        if (allocated(error)) return
    end do
end subroutine

end module
