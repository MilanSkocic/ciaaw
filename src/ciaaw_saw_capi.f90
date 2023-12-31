module ciaaw__saw_capi
!! Standard Atomic Weights C API - autogenerated.
use iso_c_binding
use ciaaw__saw
implicit none
private

type, public, bind(C) :: ciaaw_saw_capi_element_t
!! Object representing an element.
character(kind=c_char) :: element(25) !! Element name
character(kind=c_char) :: symbol(9) !! Element symbol
integer(c_int) :: z !! Element atomic number
real(c_double) :: saw_min !! Min standard atomic weight
real(c_double) :: saw_max !! Max standard atomic weight
real(c_double) :: saw !! Value standard atomic weight
real(c_double) :: saw_u !! Uncertainty standard atomic weight
real(c_double) :: asaw !! Abridged value standard atomic weight
real(c_double) :: asaw_u !! Abridged uncertainty standard atomic weight
end type

integer(c_int), protected, public, bind(C, name="ciaaw_saw_capi_YEAR") :: ciaaw_saw_capi_YEAR = ciaaw_saw_YEAR

type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_H") :: ciaaw_saw_capi_H =&
ciaaw_saw_capi_element_t(&
["h","y","d","r","o","g","e","n",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["H",c_null_char, " "," "," "," "," "," "," "], &
ciaaw_saw_H%z, &
ciaaw_saw_H%saw_max, ciaaw_saw_H%saw_min, ciaaw_saw_H%saw, ciaaw_saw_H%saw_u, ciaaw_saw_H%asaw, ciaaw_saw_H%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_He") :: ciaaw_saw_capi_He =&
ciaaw_saw_capi_element_t(&
["h","e","l","i","u","m",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["H","e",c_null_char, " "," "," "," "," "," "], &
ciaaw_saw_He%z, &
ciaaw_saw_He%saw_max, ciaaw_saw_He%saw_min, ciaaw_saw_He%saw, ciaaw_saw_He%saw_u, ciaaw_saw_He%asaw, ciaaw_saw_He%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_Li") :: ciaaw_saw_capi_Li =&
ciaaw_saw_capi_element_t(&
["l","i","t","h","i","u","m",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["L","i",c_null_char, " "," "," "," "," "," "], &
ciaaw_saw_Li%z, &
ciaaw_saw_Li%saw_max, ciaaw_saw_Li%saw_min, ciaaw_saw_Li%saw, ciaaw_saw_Li%saw_u, ciaaw_saw_Li%asaw, ciaaw_saw_Li%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_Be") :: ciaaw_saw_capi_Be =&
ciaaw_saw_capi_element_t(&
["b","e","r","y","l","l","i","u","m",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["B","e",c_null_char, " "," "," "," "," "," "], &
ciaaw_saw_Be%z, &
ciaaw_saw_Be%saw_max, ciaaw_saw_Be%saw_min, ciaaw_saw_Be%saw, ciaaw_saw_Be%saw_u, ciaaw_saw_Be%asaw, ciaaw_saw_Be%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_B") :: ciaaw_saw_capi_B =&
ciaaw_saw_capi_element_t(&
["b","o","r","o","n",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["B",c_null_char, " "," "," "," "," "," "," "], &
ciaaw_saw_B%z, &
ciaaw_saw_B%saw_max, ciaaw_saw_B%saw_min, ciaaw_saw_B%saw, ciaaw_saw_B%saw_u, ciaaw_saw_B%asaw, ciaaw_saw_B%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_C") :: ciaaw_saw_capi_C =&
ciaaw_saw_capi_element_t(&
["c","a","r","b","o","n",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["C",c_null_char, " "," "," "," "," "," "," "], &
ciaaw_saw_C%z, &
ciaaw_saw_C%saw_max, ciaaw_saw_C%saw_min, ciaaw_saw_C%saw, ciaaw_saw_C%saw_u, ciaaw_saw_C%asaw, ciaaw_saw_C%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_N") :: ciaaw_saw_capi_N =&
ciaaw_saw_capi_element_t(&
["n","i","t","r","o","g","e","n",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["N",c_null_char, " "," "," "," "," "," "," "], &
ciaaw_saw_N%z, &
ciaaw_saw_N%saw_max, ciaaw_saw_N%saw_min, ciaaw_saw_N%saw, ciaaw_saw_N%saw_u, ciaaw_saw_N%asaw, ciaaw_saw_N%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_O") :: ciaaw_saw_capi_O =&
ciaaw_saw_capi_element_t(&
["o","x","y","g","e","n",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["O",c_null_char, " "," "," "," "," "," "," "], &
ciaaw_saw_O%z, &
ciaaw_saw_O%saw_max, ciaaw_saw_O%saw_min, ciaaw_saw_O%saw, ciaaw_saw_O%saw_u, ciaaw_saw_O%asaw, ciaaw_saw_O%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_F") :: ciaaw_saw_capi_F =&
ciaaw_saw_capi_element_t(&
["f","l","u","o","r","i","n","e",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["F",c_null_char, " "," "," "," "," "," "," "], &
ciaaw_saw_F%z, &
ciaaw_saw_F%saw_max, ciaaw_saw_F%saw_min, ciaaw_saw_F%saw, ciaaw_saw_F%saw_u, ciaaw_saw_F%asaw, ciaaw_saw_F%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_Ne") :: ciaaw_saw_capi_Ne =&
ciaaw_saw_capi_element_t(&
["n","e","o","n",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["N","e",c_null_char, " "," "," "," "," "," "], &
ciaaw_saw_Ne%z, &
ciaaw_saw_Ne%saw_max, ciaaw_saw_Ne%saw_min, ciaaw_saw_Ne%saw, ciaaw_saw_Ne%saw_u, ciaaw_saw_Ne%asaw, ciaaw_saw_Ne%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_Na") :: ciaaw_saw_capi_Na =&
ciaaw_saw_capi_element_t(&
["s","o","d","i","u","m",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["N","a",c_null_char, " "," "," "," "," "," "], &
ciaaw_saw_Na%z, &
ciaaw_saw_Na%saw_max, ciaaw_saw_Na%saw_min, ciaaw_saw_Na%saw, ciaaw_saw_Na%saw_u, ciaaw_saw_Na%asaw, ciaaw_saw_Na%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_Mg") :: ciaaw_saw_capi_Mg =&
ciaaw_saw_capi_element_t(&
["m","a","g","n","e","s","i","u","m",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["M","g",c_null_char, " "," "," "," "," "," "], &
ciaaw_saw_Mg%z, &
ciaaw_saw_Mg%saw_max, ciaaw_saw_Mg%saw_min, ciaaw_saw_Mg%saw, ciaaw_saw_Mg%saw_u, ciaaw_saw_Mg%asaw, ciaaw_saw_Mg%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_Al") :: ciaaw_saw_capi_Al =&
ciaaw_saw_capi_element_t(&
["a","l","u","m","i","n","i","u","m",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["A","l",c_null_char, " "," "," "," "," "," "], &
ciaaw_saw_Al%z, &
ciaaw_saw_Al%saw_max, ciaaw_saw_Al%saw_min, ciaaw_saw_Al%saw, ciaaw_saw_Al%saw_u, ciaaw_saw_Al%asaw, ciaaw_saw_Al%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_Si") :: ciaaw_saw_capi_Si =&
ciaaw_saw_capi_element_t(&
["s","i","l","i","c","o","n",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["S","i",c_null_char, " "," "," "," "," "," "], &
ciaaw_saw_Si%z, &
ciaaw_saw_Si%saw_max, ciaaw_saw_Si%saw_min, ciaaw_saw_Si%saw, ciaaw_saw_Si%saw_u, ciaaw_saw_Si%asaw, ciaaw_saw_Si%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_P") :: ciaaw_saw_capi_P =&
ciaaw_saw_capi_element_t(&
["p","h","o","s","p","h","o","r","o","u","s",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "], &
["P",c_null_char, " "," "," "," "," "," "," "], &
ciaaw_saw_P%z, &
ciaaw_saw_P%saw_max, ciaaw_saw_P%saw_min, ciaaw_saw_P%saw, ciaaw_saw_P%saw_u, ciaaw_saw_P%asaw, ciaaw_saw_P%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_S") :: ciaaw_saw_capi_S =&
ciaaw_saw_capi_element_t(&
["s","u","l","f","u","r",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["S",c_null_char, " "," "," "," "," "," "," "], &
ciaaw_saw_S%z, &
ciaaw_saw_S%saw_max, ciaaw_saw_S%saw_min, ciaaw_saw_S%saw, ciaaw_saw_S%saw_u, ciaaw_saw_S%asaw, ciaaw_saw_S%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_Cl") :: ciaaw_saw_capi_Cl =&
ciaaw_saw_capi_element_t(&
["c","h","l","o","r","i","n","e",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["C","l",c_null_char, " "," "," "," "," "," "], &
ciaaw_saw_Cl%z, &
ciaaw_saw_Cl%saw_max, ciaaw_saw_Cl%saw_min, ciaaw_saw_Cl%saw, ciaaw_saw_Cl%saw_u, ciaaw_saw_Cl%asaw, ciaaw_saw_Cl%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_Ar") :: ciaaw_saw_capi_Ar =&
ciaaw_saw_capi_element_t(&
["a","r","g","o","n",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["A","r",c_null_char, " "," "," "," "," "," "], &
ciaaw_saw_Ar%z, &
ciaaw_saw_Ar%saw_max, ciaaw_saw_Ar%saw_min, ciaaw_saw_Ar%saw, ciaaw_saw_Ar%saw_u, ciaaw_saw_Ar%asaw, ciaaw_saw_Ar%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_K") :: ciaaw_saw_capi_K =&
ciaaw_saw_capi_element_t(&
["p","o","t","a","s","s","i","u","m",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["K",c_null_char, " "," "," "," "," "," "," "], &
ciaaw_saw_K%z, &
ciaaw_saw_K%saw_max, ciaaw_saw_K%saw_min, ciaaw_saw_K%saw, ciaaw_saw_K%saw_u, ciaaw_saw_K%asaw, ciaaw_saw_K%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_Ca") :: ciaaw_saw_capi_Ca =&
ciaaw_saw_capi_element_t(&
["c","a","l","c","i","u","m",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["C","a",c_null_char, " "," "," "," "," "," "], &
ciaaw_saw_Ca%z, &
ciaaw_saw_Ca%saw_max, ciaaw_saw_Ca%saw_min, ciaaw_saw_Ca%saw, ciaaw_saw_Ca%saw_u, ciaaw_saw_Ca%asaw, ciaaw_saw_Ca%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_Sc") :: ciaaw_saw_capi_Sc =&
ciaaw_saw_capi_element_t(&
["s","c","a","n","d","i","u","m",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["S","c",c_null_char, " "," "," "," "," "," "], &
ciaaw_saw_Sc%z, &
ciaaw_saw_Sc%saw_max, ciaaw_saw_Sc%saw_min, ciaaw_saw_Sc%saw, ciaaw_saw_Sc%saw_u, ciaaw_saw_Sc%asaw, ciaaw_saw_Sc%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_Ti") :: ciaaw_saw_capi_Ti =&
ciaaw_saw_capi_element_t(&
["t","i","t","a","n","i","u","m",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["T","i",c_null_char, " "," "," "," "," "," "], &
ciaaw_saw_Ti%z, &
ciaaw_saw_Ti%saw_max, ciaaw_saw_Ti%saw_min, ciaaw_saw_Ti%saw, ciaaw_saw_Ti%saw_u, ciaaw_saw_Ti%asaw, ciaaw_saw_Ti%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_V") :: ciaaw_saw_capi_V =&
ciaaw_saw_capi_element_t(&
["v","a","n","a","d","i","u","m",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["V",c_null_char, " "," "," "," "," "," "," "], &
ciaaw_saw_V%z, &
ciaaw_saw_V%saw_max, ciaaw_saw_V%saw_min, ciaaw_saw_V%saw, ciaaw_saw_V%saw_u, ciaaw_saw_V%asaw, ciaaw_saw_V%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_Cr") :: ciaaw_saw_capi_Cr =&
ciaaw_saw_capi_element_t(&
["c","h","r","o","m","i","u","m",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["C","r",c_null_char, " "," "," "," "," "," "], &
ciaaw_saw_Cr%z, &
ciaaw_saw_Cr%saw_max, ciaaw_saw_Cr%saw_min, ciaaw_saw_Cr%saw, ciaaw_saw_Cr%saw_u, ciaaw_saw_Cr%asaw, ciaaw_saw_Cr%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_Mn") :: ciaaw_saw_capi_Mn =&
ciaaw_saw_capi_element_t(&
["m","a","n","g","a","n","e","s","e",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["M","n",c_null_char, " "," "," "," "," "," "], &
ciaaw_saw_Mn%z, &
ciaaw_saw_Mn%saw_max, ciaaw_saw_Mn%saw_min, ciaaw_saw_Mn%saw, ciaaw_saw_Mn%saw_u, ciaaw_saw_Mn%asaw, ciaaw_saw_Mn%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_Fe") :: ciaaw_saw_capi_Fe =&
ciaaw_saw_capi_element_t(&
["i","r","o","n",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["F","e",c_null_char, " "," "," "," "," "," "], &
ciaaw_saw_Fe%z, &
ciaaw_saw_Fe%saw_max, ciaaw_saw_Fe%saw_min, ciaaw_saw_Fe%saw, ciaaw_saw_Fe%saw_u, ciaaw_saw_Fe%asaw, ciaaw_saw_Fe%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_Co") :: ciaaw_saw_capi_Co =&
ciaaw_saw_capi_element_t(&
["c","o","b","a","l","t",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["C","o",c_null_char, " "," "," "," "," "," "], &
ciaaw_saw_Co%z, &
ciaaw_saw_Co%saw_max, ciaaw_saw_Co%saw_min, ciaaw_saw_Co%saw, ciaaw_saw_Co%saw_u, ciaaw_saw_Co%asaw, ciaaw_saw_Co%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_Ni") :: ciaaw_saw_capi_Ni =&
ciaaw_saw_capi_element_t(&
["n","i","c","k","e","l",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["N","i",c_null_char, " "," "," "," "," "," "], &
ciaaw_saw_Ni%z, &
ciaaw_saw_Ni%saw_max, ciaaw_saw_Ni%saw_min, ciaaw_saw_Ni%saw, ciaaw_saw_Ni%saw_u, ciaaw_saw_Ni%asaw, ciaaw_saw_Ni%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_Cu") :: ciaaw_saw_capi_Cu =&
ciaaw_saw_capi_element_t(&
["c","o","p","p","e","r",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["C","u",c_null_char, " "," "," "," "," "," "], &
ciaaw_saw_Cu%z, &
ciaaw_saw_Cu%saw_max, ciaaw_saw_Cu%saw_min, ciaaw_saw_Cu%saw, ciaaw_saw_Cu%saw_u, ciaaw_saw_Cu%asaw, ciaaw_saw_Cu%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_Zn") :: ciaaw_saw_capi_Zn =&
ciaaw_saw_capi_element_t(&
["z","i","n","c",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["Z","n",c_null_char, " "," "," "," "," "," "], &
ciaaw_saw_Zn%z, &
ciaaw_saw_Zn%saw_max, ciaaw_saw_Zn%saw_min, ciaaw_saw_Zn%saw, ciaaw_saw_Zn%saw_u, ciaaw_saw_Zn%asaw, ciaaw_saw_Zn%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_Ga") :: ciaaw_saw_capi_Ga =&
ciaaw_saw_capi_element_t(&
["g","a","l","l","i","u","m",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["G","a",c_null_char, " "," "," "," "," "," "], &
ciaaw_saw_Ga%z, &
ciaaw_saw_Ga%saw_max, ciaaw_saw_Ga%saw_min, ciaaw_saw_Ga%saw, ciaaw_saw_Ga%saw_u, ciaaw_saw_Ga%asaw, ciaaw_saw_Ga%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_Ge") :: ciaaw_saw_capi_Ge =&
ciaaw_saw_capi_element_t(&
["g","e","r","m","a","n","i","u","m",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["G","e",c_null_char, " "," "," "," "," "," "], &
ciaaw_saw_Ge%z, &
ciaaw_saw_Ge%saw_max, ciaaw_saw_Ge%saw_min, ciaaw_saw_Ge%saw, ciaaw_saw_Ge%saw_u, ciaaw_saw_Ge%asaw, ciaaw_saw_Ge%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_As") :: ciaaw_saw_capi_As =&
ciaaw_saw_capi_element_t(&
["a","r","s","e","n","i","c",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["A","s",c_null_char, " "," "," "," "," "," "], &
ciaaw_saw_As%z, &
ciaaw_saw_As%saw_max, ciaaw_saw_As%saw_min, ciaaw_saw_As%saw, ciaaw_saw_As%saw_u, ciaaw_saw_As%asaw, ciaaw_saw_As%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_Se") :: ciaaw_saw_capi_Se =&
ciaaw_saw_capi_element_t(&
["s","e","l","e","n","i","u","m",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["S","e",c_null_char, " "," "," "," "," "," "], &
ciaaw_saw_Se%z, &
ciaaw_saw_Se%saw_max, ciaaw_saw_Se%saw_min, ciaaw_saw_Se%saw, ciaaw_saw_Se%saw_u, ciaaw_saw_Se%asaw, ciaaw_saw_Se%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_Br") :: ciaaw_saw_capi_Br =&
ciaaw_saw_capi_element_t(&
["b","r","o","m","i","n","e",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["B","r",c_null_char, " "," "," "," "," "," "], &
ciaaw_saw_Br%z, &
ciaaw_saw_Br%saw_max, ciaaw_saw_Br%saw_min, ciaaw_saw_Br%saw, ciaaw_saw_Br%saw_u, ciaaw_saw_Br%asaw, ciaaw_saw_Br%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_Kr") :: ciaaw_saw_capi_Kr =&
ciaaw_saw_capi_element_t(&
["k","r","y","p","t","o","n",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["K","r",c_null_char, " "," "," "," "," "," "], &
ciaaw_saw_Kr%z, &
ciaaw_saw_Kr%saw_max, ciaaw_saw_Kr%saw_min, ciaaw_saw_Kr%saw, ciaaw_saw_Kr%saw_u, ciaaw_saw_Kr%asaw, ciaaw_saw_Kr%asaw_u)
type(ciaaw_saw_capi_element_t), protected, public, bind(C, name="ciaaw_saw_capi_Tc") :: ciaaw_saw_capi_Tc =&
ciaaw_saw_capi_element_t(&
["t","e","c","h","n","e","t","i","u","m",c_null_char, " "," "," "," "," "," "," "," "," "," "," "," "," "," "], &
["T","c",c_null_char, " "," "," "," "," "," "], &
ciaaw_saw_Tc%z, &
ciaaw_saw_Tc%saw_max, ciaaw_saw_Tc%saw_min, ciaaw_saw_Tc%saw, ciaaw_saw_Tc%saw_u, ciaaw_saw_Tc%asaw, ciaaw_saw_Tc%asaw_u)

end module ciaaw__saw_capi
