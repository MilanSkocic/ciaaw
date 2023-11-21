module ciaaw__saw_capi
!! Standard Atomic Weights - autogenerated.
use iso_c_binding
use ciaaw__saw
implicit none

type, bind(C) :: ciaaw_saw_capi_elmt_t
character(kind=c_char) :: element(25)
character(kind=c_char) :: symbol(9)
integer(c_int) :: z
real(c_double) :: saw_min
real(c_double) :: saw_max
real(c_double) :: saw
real(c_double) :: saw_u
real(c_double) :: asaw
real(c_double) :: asaw_u
end type

integer(c_int), protected, bind(C, name="ciaaw_saw_capi_YEAR") :: ciaaw_saw_capi_YEAR = ciaaw_saw_YEAR

type(ciaaw_saw_capi_elmt_t), protected, bind(C, name="ciaaw_saw_capi_H") :: ciaaw_saw_capi_H = ciaaw_saw_capi_elmt_t(&
["h","y","d","r","o","g","e","n",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["H",c_null_char, " "," "," "," "," "," "," "], &
ciaaw_saw_H%z, &
ciaaw_saw_H%saw_max, ciaaw_saw_H%saw_min, ciaaw_saw_H%saw, ciaaw_saw_H%saw_u, ciaaw_saw_H%asaw, ciaaw_saw_H%asaw_u)
type(ciaaw_saw_capi_elmt_t), protected, bind(C, name="ciaaw_saw_capi_He") :: ciaaw_saw_capi_He = ciaaw_saw_capi_elmt_t(&
["h","e","l","i","u","m",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["H","e",c_null_char, " "," "," "," "," "," "], &
ciaaw_saw_He%z, &
ciaaw_saw_He%saw_max, ciaaw_saw_He%saw_min, ciaaw_saw_He%saw, ciaaw_saw_He%saw_u, ciaaw_saw_He%asaw, ciaaw_saw_He%asaw_u)
type(ciaaw_saw_capi_elmt_t), protected, bind(C, name="ciaaw_saw_capi_Li") :: ciaaw_saw_capi_Li = ciaaw_saw_capi_elmt_t(&
["l","i","t","h","i","u","m",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["L","i",c_null_char, " "," "," "," "," "," "], &
ciaaw_saw_Li%z, &
ciaaw_saw_Li%saw_max, ciaaw_saw_Li%saw_min, ciaaw_saw_Li%saw, ciaaw_saw_Li%saw_u, ciaaw_saw_Li%asaw, ciaaw_saw_Li%asaw_u)
type(ciaaw_saw_capi_elmt_t), protected, bind(C, name="ciaaw_saw_capi_Be") :: ciaaw_saw_capi_Be = ciaaw_saw_capi_elmt_t(&
["b","e","r","y","l","l","i","u","m",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["B","e",c_null_char, " "," "," "," "," "," "], &
ciaaw_saw_Be%z, &
ciaaw_saw_Be%saw_max, ciaaw_saw_Be%saw_min, ciaaw_saw_Be%saw, ciaaw_saw_Be%saw_u, ciaaw_saw_Be%asaw, ciaaw_saw_Be%asaw_u)
type(ciaaw_saw_capi_elmt_t), protected, bind(C, name="ciaaw_saw_capi_B") :: ciaaw_saw_capi_B = ciaaw_saw_capi_elmt_t(&
["b","o","r","o","n",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["B",c_null_char, " "," "," "," "," "," "," "], &
ciaaw_saw_B%z, &
ciaaw_saw_B%saw_max, ciaaw_saw_B%saw_min, ciaaw_saw_B%saw, ciaaw_saw_B%saw_u, ciaaw_saw_B%asaw, ciaaw_saw_B%asaw_u)
type(ciaaw_saw_capi_elmt_t), protected, bind(C, name="ciaaw_saw_capi_C") :: ciaaw_saw_capi_C = ciaaw_saw_capi_elmt_t(&
["c","a","r","b","o","n",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["C",c_null_char, " "," "," "," "," "," "," "], &
ciaaw_saw_C%z, &
ciaaw_saw_C%saw_max, ciaaw_saw_C%saw_min, ciaaw_saw_C%saw, ciaaw_saw_C%saw_u, ciaaw_saw_C%asaw, ciaaw_saw_C%asaw_u)

end module ciaaw__saw_capi
