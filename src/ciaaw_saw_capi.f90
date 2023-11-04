module ciaaw__saw_capi
    use iso_c_binding
    use ciaaw__saw
    implicit none

    type, bind(C) :: ciaaw_saw_capi_elmt_t
    integer(c_int) :: z
    real(c_double) :: saw
    real(c_double) :: saw_u
    real(c_double) :: asaw
    real(c_double) :: asaw_u
    end type

type(ciaaw_saw_capi_elmt_t), protected, bind(C,name="ciaaw_saw_capi_H") :: &
ciaaw_saw_capi_H = ciaaw_saw_capi_elmt_t(ciaaw_saw_H%z, &
                                         ciaaw_saw_H%saw, ciaaw_saw_H%saw_u, &
                                         ciaaw_saw_H%asaw, ciaaw_saw_H%asaw_u)

end module