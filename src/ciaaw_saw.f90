module ciaaw__saw
    use iso_fortran_env
    implicit none
    
    type :: ciaaw_saw_elmt_t
    integer(int32) :: z
    real(real64) :: saw
    real(real64) :: saw_u
    real(real64) :: asaw
    real(real64) :: asaw_u
    end type

type(ciaaw_saw_elmt_t), parameter :: ciaaw_saw_H = &
ciaaw_saw_elmt_t(1, 12.0d0, 0.0001d0, 12.0d0, 0.0001d0)


end module