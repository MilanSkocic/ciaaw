module ciaaw__common
!! Common parameters
use, intrinsic :: ieee_arithmetic, only: ieee_value, ieee_quiet_nan, ieee_is_nan
use, intrinsic::  iso_c_binding, only: c_ptr, c_null_char, c_loc, &
                                       c_double, c_int, c_bool, &
                                       c_f_pointer
use stdlib_kinds, only: int64, dp, int32, sp
use stdlib_optval, only: optval
implicit none(type,external)
public
end module ciaaw__common
