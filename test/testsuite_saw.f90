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
  testsuite = [new_unittest("YEAR", test_YEAR), new_unittest("ASAW", test_asaw)]
end subroutine

subroutine test_YEAR(error)
    implicit none
    type(error_type), allocatable, intent(out) :: error 
    integer(int32) :: value, expected
    expected = 2021
    value = YEAR
    call check(error, value, expected)
    if (allocated(error)) return
end subroutine

subroutine test_asaw(error)
    implicit none
    integer(int32), parameter :: N = 2
    type(error_type), allocatable, intent(out) :: error 
    type(element_t) :: elements(N) = [H, C]
    real(real64) :: expected_asaw(N) = [1.0080d0, 12.011d0]

    integer(int32) :: i
    real(real64) :: value, expected

    do i=1, N
        value = elements(i)%asaw
        expected = expected_asaw(i)
        call check(error, value, expected)
        if (allocated(error)) return
    end do
end subroutine

end module
