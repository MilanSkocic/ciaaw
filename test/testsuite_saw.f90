module testsuite_saw
    !! Test saw
    use testdrive, only : new_unittest, unittest_type, error_type, check
    use ciaaw__common, only: int32, dp
    use ciaaw, only: saw
    implicit none(type,external)
    private

    public :: collect_suite_saw

contains

subroutine collect_suite_saw(testsuite)
  type(unittest_type), allocatable, intent(out) :: testsuite(:)
  testsuite = [new_unittest("ASAW", test_asaw)]
end subroutine collect_suite_saw


subroutine test_asaw(error)
    integer(int32), parameter :: N = 3
    type(error_type), allocatable, intent(out) :: error
    character(len=2) :: elmt(3)
    real(dp) :: expected_asaw(N)
    integer(int32) :: i
    real(dp) :: value, expected

    elmt = [character(len=2) :: "H", "C", "Ne"]
    expected_asaw = [1.0080d0, 12.011d0, 20.180d0]

    do i=1, N
        value = saw(elmt(i))
        expected = expected_asaw(i)
        call check(error, value, expected)
        if (allocated(error)) return
    end do
end subroutine test_asaw

end module testsuite_saw
