module testsuite_version
    !! Test ice
    use testdrive, only : new_unittest, unittest_type, error_type, check
    use ciaaw__common, only: dp, int32
    use ciaaw, only: version
    implicit none(type,external)
    private

    public :: collect_suite_version

contains

subroutine collect_suite_version(testsuite)
  type(unittest_type), allocatable, intent(out) :: testsuite(:)
  testsuite = [new_unittest("VERSION", test_version)]
end subroutine collect_suite_version


subroutine test_version(error)
    integer(int32), parameter :: N = 3
    type(error_type), allocatable, intent(out) :: error
    character(len=32) :: expected
    character(len=32) :: value
    integer(int32) :: funit

    open(newunit=funit, file='VERSION', status='old', action='read')
    read(funit, '(A)') expected
    close(funit)

    value = version()
    call check(error, value, expected)
    if (allocated(error)) return
end subroutine test_version
end module

