module ciaaw__common
!! Common parameters
use stdlib_kinds, only: int64, dp, int32, sp
use stdlib_optval, only: optval
use ieee_arithmetic, only: ieee_quiet_nan, ieee_value
implicit none(type,external)
private
public :: optval
public :: sp, dp, int32, int64
end module ciaaw__common
