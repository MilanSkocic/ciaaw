module testsuite_naw
    !! Test naw
    use testdrive, only : new_unittest, unittest_type, error_type, check
    use ciaaw__common, only: dp, int32
    use ciaaw, only: nnaw, naw
    implicit none(type,external)
    private

    public :: collect_suite_naw

contains

subroutine collect_suite_naw(testsuite)
  type(unittest_type), allocatable, intent(out) :: testsuite(:)
  testsuite = [new_unittest("NAW", test_naw), &
               new_unittest("N NAW", test_naw)]
end subroutine collect_suite_naw


subroutine test_naw(error)
    integer(int32), parameter :: N = 3
    type(error_type), allocatable, intent(out) :: error 
    character(len=2) :: elmt(N)
    integer(int32) :: A(N)
    real(dp) :: expected_comp(N)
    integer(int32) :: i
    real(dp) :: value, expected

    elmt = [character(len=2) :: "H", "C", "Ne"]
    A = [2, 14, 20]
    expected_comp = [2.014101777844_dp, 14.00324198862_dp, 19.99244017525_dp]

    do i=1, N
        value = naw(elmt(i), A(i))
        expected = expected_comp(i)
        call check(error, value, expected)
        if (allocated(error)) return
    end do
end subroutine test_naw

subroutine test_nnaw(error)
    type(error_type), allocatable, intent(out) :: error 

    integer(int32), parameter :: N = 3
    integer(int32) :: i, value, expected
    character(len=2) :: elmt(N)
    integer(int32) :: expected_n(N)

    elmt = [character(len=2) :: "H", "C", "Ne"]
    expected_n = [7, 16, 20]

    do i=1, N
        value = nnaw(elmt(i))
        expected = expected_n(i)
        call check(error, value, expected)
        if (allocated(error)) return
    end do
end subroutine test_nnaw

end module testsuite_naw
