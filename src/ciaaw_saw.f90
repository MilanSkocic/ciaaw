module ciaaw__saw
!! Standard Atomic Weights - autogenerated.
use iso_fortran_env
use ieee_arithmetic
implicit none
private

integer(int64), parameter :: x = 1
real(real64), parameter :: nan = transfer(huge(x), 1.0d0)

type, public :: ciaaw_saw_element_t
!! Object representing an element.
character(len=24) :: element !! Element name
character(len=8) :: symbol !! Element symbol
integer(int32) :: z !! Element atomic number
real(real64) :: saw_min !! Min standard atomic weight
real(real64) :: saw_max !! Max standard atomic weight
real(real64) :: saw !! Value standard atomic weight
real(real64) :: saw_u !! Uncertainty standard atomic weight
real(real64) :: asaw !! Abridged value standard atomic weight
real(real64) :: asaw_u !! Abridged uncertainty standard atomic weight
end type

integer(int32), parameter, public :: ciaaw_saw_YEAR = 2021

type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_H =&
ciaaw_saw_element_t("hydrogen", "H", 1, &
1.00784d0, 1.00811d0, &
1.00798d0, 0.00008d0, &
1.0080d0, 0.0002d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_He =&
ciaaw_saw_element_t("helium", "He", 2, &
nan, nan, &
4.002602d0, 0.000002d0, &
4.0026d0, 0.0001d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_Li =&
ciaaw_saw_element_t("lithium", "Li", 3, &
6.938d0, 6.997d0, &
6.97d0, 0.02d0, &
6.94d0, 0.06d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_Be =&
ciaaw_saw_element_t("beryllium", "Be", 4, &
nan, nan, &
9.0121831d0, 0.0000005d0, &
9.0122d0, 0.00001d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_B =&
ciaaw_saw_element_t("boron", "B", 5, &
10.806d0, 10.821d0, &
10.813d0, 0.005d0, &
10.81d0, 0.02d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_C =&
ciaaw_saw_element_t("carbon", "C", 6, &
12.0096d0, 12.0116d0, &
12.0106d0, 0.0006d0, &
12.011d0, 0.002d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_N =&
ciaaw_saw_element_t("nitrogen", "N", 7, &
14.00643d0, 14.00728d0, &
14.0069d0, 0.0003d0, &
14.007d0, 0.001d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_O =&
ciaaw_saw_element_t("oxygen", "O", 8, &
15.99903d0, 15.99977d0, &
15.9994d0, 0.0003d0, &
15.999d0, 0.001d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_F =&
ciaaw_saw_element_t("fluorine", "F", 9, &
nan, nan, &
18.998403162d0, 0.000000005d0, &
18.998d0, 0.001d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_Ne =&
ciaaw_saw_element_t("neon", "Ne", 10, &
nan, nan, &
20.1797d0, 0.0006d0, &
20.180d0, 0.001d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_Na =&
ciaaw_saw_element_t("sodium", "Na", 11, &
nan, nan, &
22.98976928d0, 0.00000002d0, &
22.990d0, 0.001d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_Mg =&
ciaaw_saw_element_t("magnesium", "Mg", 12, &
24.304d0, 24.307d0, &
24.3055d0, 0.0009d0, &
24.305d0, 0.002d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_Al =&
ciaaw_saw_element_t("aluminium", "Al", 13, &
nan, nan, &
26.9815384d0, 0.0000003d0, &
26.982d0, 0.001d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_Si =&
ciaaw_saw_element_t("silicon", "Si", 14, &
28.084d0, 28.086d0, &
28.0850d0, 0.0006d0, &
28.085d0, 0.001d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_P =&
ciaaw_saw_element_t("phosphorous", "P", 15, &
nan, nan, &
30.973761998d0, 0.000000005d0, &
30.974d0, 0.001d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_S =&
ciaaw_saw_element_t("sulfur", "S", 16, &
32.059d0, 32.076d0, &
32.067d0, 0.005d0, &
32.06d0, 0.02d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_Cl =&
ciaaw_saw_element_t("chlorine", "Cl", 17, &
35.446d0, 35.457d0, &
35.451d0, 0.004d0, &
35.45d0, 0.01d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_Ar =&
ciaaw_saw_element_t("argon", "Ar", 18, &
39.792d0, 39.963d0, &
39.88d0, 0.05d0, &
39.95d0, 0.16d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_K =&
ciaaw_saw_element_t("potassium", "K", 19, &
nan, nan, &
39.0983d0, 0.0001d0, &
39.098d0, 0.001d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_Ca =&
ciaaw_saw_element_t("calcium", "Ca", 20, &
nan, nan, &
40.078d0, 0.004d0, &
40.078d0, 0.004d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_Sc =&
ciaaw_saw_element_t("scandium", "Sc", 21, &
nan, nan, &
44.955907d0, 0.000004d0, &
44.956d0, 0.001d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_Ti =&
ciaaw_saw_element_t("titanium", "Ti", 22, &
nan, nan, &
47.867d0, 0.001d0, &
47.867d0, 0.001d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_V =&
ciaaw_saw_element_t("vanadium", "V", 23, &
nan, nan, &
50.9415d0, 0.0001d0, &
50.942d0, 0.001d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_Cr =&
ciaaw_saw_element_t("chromium", "Cr", 24, &
nan, nan, &
51.9961d0, 0.0006d0, &
51.996d0, 0.001d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_Mn =&
ciaaw_saw_element_t("manganese", "Mn", 25, &
nan, nan, &
54.938043d0, 0.000002d0, &
54.938d0, 0.001d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_Fe =&
ciaaw_saw_element_t("iron", "Fe", 26, &
nan, nan, &
55.845d0, 0.002d0, &
55.845d0, 0.002d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_Co =&
ciaaw_saw_element_t("cobalt", "Co", 27, &
nan, nan, &
58.933194d0, 0.000003d0, &
58.933d0, 0.001d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_Ni =&
ciaaw_saw_element_t("nickel", "Ni", 28, &
nan, nan, &
58.6934d0, 0.0004d0, &
58.693d0, 0.001d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_Cu =&
ciaaw_saw_element_t("copper", "Cu", 29, &
nan, nan, &
63.546d0, 0.003d0, &
63.546d0, 0.003d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_Zn =&
ciaaw_saw_element_t("zinc", "Zn", 30, &
nan, nan, &
65.38d0, 0.02d0, &
65.38d0, 0.02d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_Ga =&
ciaaw_saw_element_t("gallium", "Ga", 31, &
nan, nan, &
69.723d0, 0.001d0, &
69.723d0, 0.001d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_Ge =&
ciaaw_saw_element_t("germanium", "Ge", 32, &
nan, nan, &
72.630d0, 0.008d0, &
72.630d0, 0.008d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_As =&
ciaaw_saw_element_t("arsenic", "As", 33, &
nan, nan, &
74.921595d0, 0.000006d0, &
74.922d0, 0.001d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_Se =&
ciaaw_saw_element_t("selenium", "Se", 34, &
nan, nan, &
78.971d0, 0.008d0, &
78.971d0, 0.008d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_Br =&
ciaaw_saw_element_t("bromine", "Br", 35, &
79.901d0, 79.907d0, &
79.904d0, 0.002d0, &
79.904d0, 0.003d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_Kr =&
ciaaw_saw_element_t("krypton", "Kr", 36, &
nan, nan, &
83.798d0, 0.002d0, &
83.798d0, 0.002d0)
type(ciaaw_saw_element_t), parameter, public :: ciaaw_saw_Tc =&
ciaaw_saw_element_t("technetium", "Tc", 43, &
nan, nan, &
nan, nan, &
nan, nan)

end module ciaaw__saw
