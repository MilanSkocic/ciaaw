module testsuite_naw
    !! Test naw
    use iso_fortran_env
    use testdrive, only : new_unittest, unittest_type, error_type, check
    use stdlib_kinds, only: dp, int32
    use ciaaw
    implicit none
    private
    
    public :: collect_suite_naw

contains
    
subroutine collect_suite_naw(testsuite)
  type(unittest_type), allocatable, intent(out) :: testsuite(:)
  testsuite = [new_unittest("NAW", test_naw), &
               new_unittest("N NAW", test_naw)]
end subroutine


subroutine test_naw(error)
    integer(int32), parameter :: N = 3
    type(error_type), allocatable, intent(out) :: error 
    character(len=2) :: elmt(3) = [character(len=2) :: "H", "C", "Ne"]
    integer(int32) :: A(3) = [2, 14, 20]
    real(real64) :: expected_comp(N) = [2.014101777844_dp, 14.00324198862_dp, 19.99244017525_dp]

    integer(int32) :: i
    real(real64) :: value, expected

    do i=1, N
        value = get_naw(elmt(i), A(i))
        expected = expected_comp(i)
        call check(error, value, expected)
        if (allocated(error)) return
    end do
end subroutine

subroutine test_nnaw(error)
    type(error_type), allocatable, intent(out) :: error 

    integer(int32), parameter :: N = 3
    integer(int32) :: i, value, expected
    
    character(len=2) :: elmt(3) = [character(len=2) :: "H", "C", "Ne"]
    integer(int32) :: expected_n(N) = [7, 16, 20]

    do i=1, N
        value = get_nnaw(elmt(i))
        expected = expected_n(i)
        call check(error, value, expected)
        if (allocated(error)) return
    end do
end subroutine

end module
