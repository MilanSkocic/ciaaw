module ciaaw__common
    !! Common parameters
    use stdlib_kinds, only: int64, dp, int32, sp
    private

    integer(int64), parameter :: x = 1
    real(dp), parameter :: nan_dp = transfer(huge(x), 1.0_dp)
    real(sp), parameter :: nan_sp = transfer(huge(x), 1.0_sp)


    public :: sp, dp, int32, int64
    public :: nan_sp, nan_dp

end module
