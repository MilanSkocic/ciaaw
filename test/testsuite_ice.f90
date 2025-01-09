module testsuite_ice
    !! Test ice
    use iso_fortran_env
    use testdrive, only : new_unittest, unittest_type, error_type, check
    use stdlib_kinds, only: dp, int32
    use ciaaw
    use ciaaw__pte
    implicit none
    private
    
    public :: collect_suite_ice

contains

subroutine collect_suite_ice(testsuite)
  type(unittest_type), allocatable, intent(out) :: testsuite(:)
  testsuite = [new_unittest("ICE", test_ice),&
               new_unittest("N ICE", test_nice),&
               new_unittest("ICE SUM", test_ice_sum)]
end subroutine


subroutine test_ice(error)
    integer(int32), parameter :: N = 3
    type(error_type), allocatable, intent(out) :: error 
    character(len=2) :: elmt(3) = [character(len=2) :: "H", "C", "Ne"]
    integer(int32) :: A(3) = [1, 12, 20]
    real(real64) :: expected_comp(N) = [0.99984426_dp, 0.988922_dp, 0.904838_dp]

    integer(int32) :: i
    real(real64) :: value, expected

    do i=1, N
        value = get_ice(elmt(i), A(i))
        expected = expected_comp(i)
        call check(error, value, expected)
        if (allocated(error)) return
    end do
end subroutine


subroutine test_nice(error)
    type(error_type), allocatable, intent(out) :: error 

    integer(int32), parameter :: N = 3
    integer(int32) :: i, value, expected
    
    character(len=2) :: elmt(3) = [character(len=2) :: "H", "C", "Ne"]
    integer(int32) :: expected_n(N) = [2, 2, 3]

    do i=1, N
        value = get_nice(elmt(i))
        expected = expected_n(i)
        call check(error, value, expected)
        if (allocated(error)) return
    end do
end subroutine


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

end subroutine

end module
