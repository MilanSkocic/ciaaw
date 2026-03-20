module testsuite_ice
    !! Test ice
    use testdrive, only : new_unittest, unittest_type, error_type, check
    use ciaaw__common, only: dp, int32
    use ciaaw, only: ice, get_nice
    use ciaaw__pte, only: pt
    implicit none(type,external)
    private

    public :: collect_suite_ice

contains

subroutine collect_suite_ice(testsuite)
  type(unittest_type), allocatable, intent(out) :: testsuite(:)
  testsuite = [new_unittest("ICE", test_ice),&
               new_unittest("N ICE", test_nice),&
               new_unittest("ICE SUM", test_ice_sum)]
end subroutine collect_suite_ice


subroutine test_ice(error)
    integer(int32), parameter :: N = 3
    type(error_type), allocatable, intent(out) :: error
    character(len=2) :: elmt(3)
    integer(int32) :: A(3)
    real(dp) :: expected_comp(N)
    integer(int32) :: i
    real(dp) :: value, expected

    elmt = [character(len=2) :: "H", "C", "Ne"]
    A = [1, 12, 20]
    expected_comp = [0.99984426_dp, 0.988922_dp, 0.904838_dp]

    do i=1, N
        value = ice(elmt(i), A(i))
        expected = expected_comp(i)
        call check(error, value, expected)
        if (allocated(error)) return
    end do
end subroutine test_ice


subroutine test_nice(error)
    type(error_type), allocatable, intent(out) :: error

    integer(int32), parameter :: N = 3
    integer(int32) :: i, value, expected

    character(len=2) :: elmt(N)
    integer(int32) :: expected_n(N)

    elmt = [character(len=2) :: "H", "C", "Ne"]
    expected_n = [2, 2, 3]

    do i=1, N
        value = get_nice(elmt(i))
        expected = expected_n(i)
        call check(error, value, expected)
        if (allocated(error)) return
    end do
end subroutine test_nice


subroutine test_ice_sum(error)
    type(error_type), allocatable, intent(out) :: error

    integer(int32), parameter :: N = 3
    integer(int32) :: i, j, nice
    real(dp) :: value, expected

    expected = 1.0_dp
    do i=1, 92
        nice = pt(i)%ice%n
        value = 0.0_dp
        select case (trim(pt(i)%symbol))
            case ("Tc")
                expected = 0.0_dp
            case ("Pm")
                expected = 0.0_dp
            case ("Po")
                expected = 0.0_dp
            case ("At")
                expected = 0.0_dp
            case ("Rn")
                expected = 0.0_dp
            case ("Fr")
                expected = 0.0_dp
            case ("Ra")
                expected = 0.0_dp
            case ("Ac")
                expected = 0.0_dp
            case default
                expected = 1.0_dp
        end select
        do j=1, nice
            value = value + pt(i)%ice%values(j,2)
        end do
        value = nint(value * 1d3) * 1d-3
        call check(error, value, expected)
        if (allocated(error)) return
    end do

end subroutine test_ice_sum

end module testsuite_ice
