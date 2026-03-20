!###############################################################################
$BLOCK comment --file ciaaw.3.prep
NAME
    ciaaw - library for isotopic abundances and standard atomic weights  

LIBRARY
    ciaaw (-libciaaw, -lciaaw)

SYNOPSIS
    use ciaaw
    include "ciaaw.h"
    import pyciaaw

DESCRIPTION
    ciaaw is a Fortran library providing the standard and abridged atomic
    weights, the isotopic abundance and the isotopes’ standard atomic weights:

        o SAW  Standard Atomic Weights.
        o ICE  Isotopic Composition of the Element
        o NAW  Nuclides Atomic Weight.

    The data are taken from http://ciaaw.org.
    C API allows usage from C, or can be used as a basis for other wrappers.
    Python wrapper allows easy usage from Python.

    The latest standard atomic weights were released in 2021 by the ciaaw 
    (https://www.ciaaw.org). 
    All the values for the atomic weights are provided as double precision reals.
    The standard atomic weights (or realtive atomic mass), A_r(E), are extracted
    from table 1 from Prohaska et al. (IUPAC Technical Report 94(5):573–600). 
    For the elements that feature an interval for the standard atomic weight, 
    the mean value and the uncertainty are computed using formulas defined in 
    IUPAC Technical Report 93(5):629–646.
    The standard atomic weights are a dimensionless quantity and thus they need 
    to be multiplied by the molar mass constant Mu in order to get the value in 
    g.mol-1. See codata for physical constants.

    The latest isotopic compositions were released in 2013 by the 
    ciaaw (https://www.ciaaw.org). 
    All the values for the compositions are provided as double precision reals.
    The isotopic compositions of the element, are extracted from table 1 
    from Meija et al. (IUPAC Technical Report. 88(3):293–306).

    The latest atomic weights for nuclides were released in 2020 by 
    ciaaw https://www.ciaaw.org from Huang et al. (AME 2020 45(3):030002). 
    All the values for the nuclide atomic weights are provided as double precision reals.

$INCLUDE ./fapi.txt

$INCLUDE ./capi.txt

$INCLUDE ./pyapi.txt

    References

        o W.J. Huang, Meng Wang, F.G. Kondev, G. Audi, and S. Naimi. The AME 2020 atomic mass
        evaluation (I). Evaluation of input data, and adjustment procedures*. 45(3):030002.

        o Juris Meija, Tyler B. Coplen, Michael Berglund, Willi A. Brand, Paul De Bièvre, Manfred
        Gröning, Norman E. Holden, Johanna Irrgeher, Robert D. Loss, Thomas Walczyk, and Thomas
        Prohaska. Isotopic compositions of the elements 2013 (IUPAC Technical Report). 88(3):293–306.

        o Thomas Prohaska, Johanna Irrgeher, Jacqueline Benefield, John K. Böhlke, Lesley A. Chesson,
        Tyler B. Coplen, Tiping Ding, Philip J. H. Dunn, Manfred Gröning, Norman E. Holden, Harro
        A. J. Meijer, Heiko Moossen, Antonio Possolo, Yoshio Takahashi, Jochen Vogl, Thomas Walczyk,
        Jun Wang, Michael E. Wieser, Shigekazu Yoneda, Xiang-Kun Zhu, and Juris Meija. Standard
        atomic weights of the elements 2021 (IUPAC Technical Report). 94(5):573–600.

        o M.H. van der Veen, J. Meia, and D. Brynn Hibbert. Interpretation and use of standard atomic
        weights (IUPAC Technical Report). 93(5):629–646.

NOTES
    To use ciaaw within your fpm project, add the following to your fpm.toml file:

        [dependencies]
        iapws = { git="https://github.com/MilanSkocic/ciaaw.git" }

    dp stands for double precision and it is an alias to real64
    from the iso_fortran_env module.

    The definitions of the acronyms:
        o ASAW   Abridged Standard Atomic Weight
        o SAW    Standard Atomic Weight
        o ICE    Isotopic Composition of the Element
        o NAW    Nuclide Atomic Weight

    The definitions of the abbreviations:
        o s    Element
        o Z    Atomic number
        o A    Mass number
        o u    Uncertainty
        o ab   Abridged
        o res  Result

EXAMPLES
$INCLUDE ./example.mantxt

SEE ALSO
    ciaaw(1), gsl(3), codata(3)
$ENDBLOCK
module ciaaw
!! Main module for the CIAAW library: API and C API.
use ciaaw__common, only: dp, int32, optval, &
                         ieee_is_nan, ieee_quiet_nan, ieee_value, &
                         c_ptr, c_int, c_bool, c_double, c_null_char, &
                         c_f_pointer, c_loc
use ciaaw__types, only: element_type
use ciaaw__pte, only: pt
implicit none(type,external)
private

$IFDEF FPM_VERSION
$IMPORT FPM_VERSION
character(len=*), parameter, private :: v = '${FPM_VERSION}'
$ENDIF
character(len=:), allocatable, target :: vf
character(len=:), allocatable, target :: vc

real(dp), allocatable, target :: n_ice_out(:,:)

!=======================================================================
! PUBLIC
!=======================================================================
public :: get_version, capi_get_version
public :: version, capi_version
public :: get_saw, capi_get_saw
public :: saw, capi_saw
public :: get_ice, capi_get_ice
public :: ice, capi_ice
public :: get_nice, capi_get_nice
public :: get_naw, capi_get_naw
public :: get_nnaw, capi_get_nnaw
public :: print_periodic_table
! public :: get_ice_values
!=======================================================================

contains
!=======================================================================
! GET_VERSION() - DEPRECATED
!=======================================================================
function get_version()result(fptr)
!! Get the version.
!! Deprecated. It will be removed in the next major release.
!! Use version() instead.
implicit none
character(len=:), pointer :: fptr  !! Fortran pointer to a string indicating the version..
if(allocated(vf))then
    deallocate(vf)
endif
allocate(character(len=len(v)) :: vf)
vf = v
fptr => vf
end function get_version
!-----------------------------------------------------------------------
function capi_get_version()bind(c, name='ciaaw_get_version')result(cptr)
!! C API.
type(c_ptr) :: cptr    !! C pointer to a string indicating the version.
character(len=:), pointer :: fptr
fptr => get_version()
if(allocated(vc))then
    deallocate(vc)
endif
allocate(character(len=len(fptr)+1) :: vc)
vc = fptr // c_null_char
cptr = c_loc(vc)
end function capi_get_version
!=======================================================================


!=======================================================================
! VERSION()
!=======================================================================
function version()result(fptr)
!! Get the version.
character(len=:), pointer :: fptr !! Pointer to a string (=>version).
if(allocated(vf))then
    deallocate(vf)
endif
allocate(character(len=len(v)) :: vf)
vf = v
fptr => vf
end function version
!-----------------------------------------------------------------------
function capi_version()bind(C,name="ciaaw_version")result(cptr)
!! C API - Get the version
type(c_ptr) :: cptr !! C pointer to a string indicating the version.
character(len=:), pointer :: fptr
fptr => version()
if(allocated(vc))then
    deallocate(vc)
endif
allocate(character(len=len(fptr)+1) :: vc)
vc = fptr // c_null_char
cptr = c_loc(vc)
end function capi_version
!=======================================================================


!=======================================================================
! PRINT_PERIODIC_TABLE
!=======================================================================
subroutine print_periodic_table()
!! Print periodic table.
integer(int32) :: i,j

character(len=20) :: v, u, w

character(len=15) :: header(3)
character(len=15) :: ice_headers(3)
character(len=15) :: naw_headers(3)

header = [character(len=20) :: "", "", ""]
ice_headers = [character(len=15) :: "A", "C /%", "dC /%"]
naw_headers = [character(len=15) :: "A", "M", "dM"]

do i=1, size(pt)
    print "(A)", "============================================="
    header(1) = pt(i)%symbol
    header(2) = pt(i)%element
    write(v, "(I3)") pt(i)%z
    header(3) = "z=" // v
    print "(3A15)", header
    print "(A)", "---------------------------------------------"

    print "(A)", "STANDARD ATOMIC WEIGHTS"
    write(v, "(F10.5)") pt(i)%saw%asaw
    write(u, "(F10.5)") pt(i)%saw%asaw_u
    print "(A4, A10, A, A10)", "M = ", adjustl(v), "+/-", adjustl(u)

    print "(A)", "---------------------------------------------"

    print "(A)", "ISOTOPIC COMPOSITIONS"
    print "(3A15)", ice_headers
    do j=1, pt(i)%ice%n
        write(w, "(I3)") nint(pt(i)%ice%values(j,1))
        write(v, "(ES12.5)") pt(i)%ice%values(j,2)
        write(u, "(ES12.5)") pt(i)%ice%values(j,3)
        print "(3A15)", adjustl(w), adjustl(v), adjustl(u)
    enddo
    print "(A)", "---------------------------------------------"

    print "(A)", "NUCLIDE ATOMIC WEIGHTS"
    print "(3A15)", naw_headers
    do j=1, pt(i)%naw%n
        write(w, "(I3)") nint(pt(i)%naw%values(j,1))
        write(v, "(ES12.5)") pt(i)%naw%values(j,2)
        write(u, "(ES12.5)") pt(i)%naw%values(j,3)
        print "(3A15)", adjustl(w), adjustl(v), adjustl(u)
    enddo
    print "(A)", "============================================="

    print *, ""
    print *, ""
end do
end subroutine print_periodic_table
!=======================================================================


!=======================================================================
! Base search functions
!=======================================================================
function is_in_pt(z)result(res)
!! Check if the atomic number z is in the periodic table
integer(int32), intent(in) :: z  !! Atomic number
logical :: res                   !! True or False

if((z<1) .or. (z>size(pt))) then
    res = .false.
else
    res = .true.
end if
end function is_in_pt
!-----------------------------------------------------------------------
function get_z_by_symbol(s)result(res)
!! Get the atomic number z of the element defined by the symbol s.
character(len=*), intent(in) :: s    !! Element symbol
integer(int32) :: res                !! >0 if found and -1 if not found.

integer(int32) :: i
type(element_type) :: elmt

res = -1

do i=1, size(pt)
    elmt = pt(i)
    if(s == elmt%symbol)then
        res = i
        exit
    endif
end do
end function get_z_by_symbol
!=======================================================================


!=======================================================================
! GET_SAW() - DEPRECATED
!=======================================================================
function get_saw(s, abridged, uncertainty)result(res)
!! Get the standard atomic weight for the element s.
!! Deprecated. It will be removed in the next major release.
!! Use saw() instead.
character(len=*), intent(in) :: s    !! Element symbol.
logical, intent(in), optional :: abridged  !! Set to False if the abridged value is not desired. Default to TRUE.
logical, intent(in), optional :: uncertainty   !! Set to True if the uncertainty is desired. Default to FALSE.
real(dp) :: res                      !! NaN if the provided element is incorrect or -1 if the element does not have a SAW.

real(dp) :: saw_max, saw_min, saw, saw_u
integer(int32) :: z, n
logical :: ab2, u2

ab2 = optval(abridged, .true.)
u2 = optval(uncertainty, .false.)

z = get_z_by_symbol(s)

res = ieee_value(1.0_dp, ieee_quiet_nan)

if(z>0)then
    if(ab2 .eqv. .true.)then
        if(u2 .eqv. .true.)then
            res = pt(z)%saw%asaw_u
        else
            res = pt(z)%saw%asaw
        end if
    else
        if((pt(z)%saw%saw == -1.0_dp) .and. (pt(z)%saw%saw_max > 0.0_dp) .and. (pt(z)%saw%saw_min > 0.0_dp))then

            saw_max = pt(z)%saw%saw_max
            saw_min = pt(z)%saw%saw_min

            saw = (saw_max + saw_min) / 2.0_dp
            saw_u = (saw_max - saw_min)/(2.0_dp*sqrt(3.0_dp))

            n = floor(log10(saw_u))

            saw_u = ceiling(saw_u * 10.0_dp**(-n))*10.0_dp**n
            saw = nint(saw * 10.0_dp**(-n)) * 10.0_dp**n

            if(u2 .eqv. .true.)then
                res = saw_u
            else
                res = saw
            end if
        else
            if(u2 .eqv. .true.)then
                res = pt(z)%saw%saw_u
            else
                res = pt(z)%saw%saw
            end if
        end if
    end if
end if
end function get_saw
!-----------------------------------------------------------------------
function capi_get_saw(s, n, abridged, uncertainty)bind(C, name="ciaaw_get_saw")result(res)
!! C API.
!! Deprecated. It will be removed in the next major release.
!! Use capi_saw() instead.
type(c_ptr), intent(in), value :: s       !! Symbol.
integer(c_int), intent(in), value :: n    !! Size of the symbol string.
logical(c_bool), intent(in), value :: abridged  !! Flag for setting if abridged value is desired.
logical(c_bool), intent(in), value :: uncertainty   !! Flag for setting if the uncertainty is desired instead of the value.
real(c_double) :: res                     !! NaN if the provided element is incorrect or -1 if the element does not have a SAW.

integer(c_int) :: i
character, pointer, dimension(:) :: c2f_s
character(len=n) :: fs
logical :: f_ab, f_u

call c_f_pointer(s, c2f_s, shape=[n])

do i=1, n
    fs(i:i) = c2f_s(i)
enddo

f_ab = logical(abridged)
f_u = logical(uncertainty)

res = get_saw(fs, f_ab, f_u)
end function capi_get_saw
!=======================================================================


!=======================================================================
! SAW()
!=======================================================================
function saw(s, ab, u)result(res)
!! Get the standard atomic weight for the element s.
character(len=*), intent(in) :: s    !! Element symbol.
logical, intent(in), optional :: ab  !! Set to False if the abridged value is not desired. Default to TRUE.
logical, intent(in), optional :: u   !! Set to True if the uncertainty is desired. Default to FALSE.
real(dp) :: res                      !! NaN if the provided element is incorrect or -1 if the element does not have a SAW.

real(dp) :: vmax, vmin, v, vu
integer(int32) :: z, n
logical :: ab2, u2

ab2 = optval(ab, .true.)
u2 = optval(u, .false.)

z = get_z_by_symbol(s)

res = ieee_value(1.0_dp, ieee_quiet_nan)

if(z>0)then
    if(ab2 .eqv. .true.)then
        if(u2 .eqv. .true.)then
            res = pt(z)%saw%asaw_u
        else
            res = pt(z)%saw%asaw
        end if
    else
        if((pt(z)%saw%saw == -1.0_dp) .and. (pt(z)%saw%saw_max > 0.0_dp) .and. (pt(z)%saw%saw_min > 0.0_dp))then

            vmax = pt(z)%saw%saw_max
            vmin = pt(z)%saw%saw_min

            v = (vmax + vmin) / 2.0_dp
            vu = (vmax - vmin)/(2.0_dp*sqrt(3.0_dp))

            n = floor(log10(vu))

            vu = ceiling(vu * 10.0_dp**(-n))*10.0_dp**n
            v = nint(v * 10.0_dp**(-n)) * 10.0_dp**n

            if(u2 .eqv. .true.)then
                res = vu
            else
                res = v
            end if
        else
            if(u2 .eqv. .true.)then
                res = pt(z)%saw%saw_u
            else
                res = pt(z)%saw%saw
            end if
        end if
    end if
end if
end function saw
!-----------------------------------------------------------------------
function capi_saw(s, n, ab, u)bind(C, name="ciaaw_saw")result(res)
!! C API.
type(c_ptr), intent(in), value :: s       !! Symbol.
integer(c_int), intent(in), value :: n    !! Size of the symbol string.
logical(c_bool), intent(in), value :: ab  !! Flag for setting if abridged value is desired.
logical(c_bool), intent(in), value :: u   !! Flag for setting if the uncertainty is desired instead of the value.
real(c_double) :: res                     !! NaN if the provided element is incorrect or -1 if the element does not have a SAW.

integer(c_int) :: i
character, pointer, dimension(:) :: c2f_s
character(len=n) :: fs
logical :: f_ab, f_u

call c_f_pointer(s, c2f_s, shape=[n])

do i=1, n
    fs(i:i) = c2f_s(i)
enddo

f_ab = logical(ab)
f_u = logical(u)

res = saw(fs, f_ab, f_u)
end function capi_saw
!=======================================================================


!=======================================================================
! GET_ICE() - DEPRECATED
!=======================================================================
function get_ice(s, A, uncertainty)result(res)
!! Get the isotopic composition of the element s for the mass number A.
!! Deprecated. It will be removed in the next major release.
!! Use ice() instead.
character(len=*), intent(in) :: s   !! Element symbol.
integer(int32), intent(in) :: A     !! Mass number.
logical, intent(in), optional :: uncertainty  !! Set to True if the uncertainty is desired. Default to FALSE.
real(dp) :: res                     !! NaN if the provided element or the mass number A are incorrect or -1 if the element does not have an ICE.

real(dp) :: A_double
integer(int32) :: i, z, col, row
logical :: u2

u2 = optval(uncertainty, .false.)
z = get_z_by_symbol(s)
A_double = real(A, dp)

res = ieee_value(1.0_dp, ieee_quiet_nan)

if(u2 .eqv. .true.)then
    col = 3
else
    col = 2
endif

row = 0
if((z>0) .and. (pt(z)%ice%n > 0))then
    do i=1, pt(z)%ice%n
        if(pt(z)%ice%values(i, 1) == A_double)then
            row = i
            exit
        endif
    end do
endif
if(row > 0)then
    res = pt(z)%ice%values(row, col)
endif
end function get_ice
!-----------------------------------------------------------------------
function capi_get_ice(s, n, A, uncertainty)bind(C, name="ciaaw_get_ice")result(res)
!! C API.
!! Deprecated. It will be removed in the next major release.
!! Use capi_ice() instead.
type(c_ptr), intent(in), value :: s      !! Element symbol.
integer(c_int), intent(in), value :: n   !! Size of the symbol string.
integer(c_int), intent(in), value :: A   !! Mass number.
logical(c_bool), intent(in), value :: uncertainty  !! Flag for returning the uncertainty instead of the value. Default to FALSE.
real(c_double) :: res                    !! NaN if the provided element or the mass number A are incorrect or -1 if the element does not have an ICE.

integer(c_int) :: i
character, pointer, dimension(:) :: c2f_s
character(len=n) :: fs
logical :: f_u

call c_f_pointer(s, c2f_s, shape=[n])

do i=1, n
    fs(i:i) = c2f_s(i)
enddo

f_u = logical(uncertainty)

res = get_ice(fs, A, f_u)
end function capi_get_ice
!=======================================================================


!=======================================================================
! ICE()
!=======================================================================
function ice(s, A, u)result(res)
!! Get the isotopic composition of the element s for the mass number A.
!! Deprecated. It will be removed in the next major release.
!! Use ice() instead.
character(len=*), intent(in) :: s   !! Element symbol.
integer(int32), intent(in) :: A     !! Mass number.
logical, intent(in), optional :: u  !! Set to True if the uncertainty is desired. Default to FALSE.
real(dp) :: res                     !! NaN if the provided element or the mass number A are incorrect or -1 if the element does not have an ICE.

real(dp) :: A_double
integer(int32) :: i, z, col, row
logical :: u2

u2 = optval(u, .false.)
z = get_z_by_symbol(s)
A_double = real(A, dp)

res = ieee_value(1.0_dp, ieee_quiet_nan)

if(u2 .eqv. .true.)then
    col = 3
else
    col = 2
endif

row = 0
if((z>0) .and. (pt(z)%ice%n > 0))then
    do i=1, pt(z)%ice%n
        if(pt(z)%ice%values(i, 1) == A_double)then
            row = i
            exit
        endif
    end do
endif
if(row > 0)then
    res = pt(z)%ice%values(row, col)
endif
end function ice
!-----------------------------------------------------------------------
function capi_ice(s, n, A, u)bind(C, name="ciaaw_ice")result(res)
!! C API.
type(c_ptr), intent(in), value :: s      !! Element symbol.
integer(c_int), intent(in), value :: n   !! Size of the symbol string.
integer(c_int), intent(in), value :: A   !! Mass number.
logical(c_bool), intent(in), value :: u  !! Flag for returning the uncertainty instead of the value. Default to FALSE.
real(c_double) :: res                    !! NaN if the provided element or the mass number A are incorrect or -1 if the element does not have an ICE.

integer(c_int) :: i
character, pointer, dimension(:) :: c2f_s
character(len=n) :: fs
logical :: f_u

call c_f_pointer(s, c2f_s, shape=[n])

do i=1, n
    fs(i:i) = c2f_s(i)
enddo

f_u = logical(u)

res = ice(fs, A, f_u)
end function capi_ice
!=======================================================================


!=======================================================================
! GET_NICE
!=======================================================================
function get_nice(s)result(res)
!! Get the number of isotopes in ICE of the element s.
character(len=*), intent(in) :: s     !! Element symbol.
integer(int32) :: res                 !! >0 if found or -1 if not found.

integer(int32) :: z

z = get_z_by_symbol(s)

if(z>0)then
    res = pt(z)%ice%n
else
    res = -1
endif
end function get_nice
!-----------------------------------------------------------------------
function capi_get_nice(s,n)bind(C, name="ciaaw_get_nice")result(res)
!! C API.
type(c_ptr), intent(in), value :: s        !! Element symbol.
integer(c_int), intent(in), value :: n     !! Size of the symbol string.
integer(c_int) :: res                      !! >0 if found or -1 if not found.

integer(c_int) :: i
character, pointer, dimension(:) :: c2f_s
character(len=n) :: fs

call c_f_pointer(s, c2f_s, shape=[n])

do i=1, n
    fs(i:i) = c2f_s(i)
enddo

res = get_nice(fs)
end function capi_get_nice
!=======================================================================


!=======================================================================
! GET_ICE_VALUES
!=======================================================================
! function get_ice_values(s)result(res)
! !! Get the (n, 3) values array. See [[ciaaw__types(module):ice_type(type)]].
! !! Returns a null pointer if the provided symbol is incorrect.
! 
! ! Arguments
! character(len=*), intent(in) :: s             !! Element symbol.
! 
! ! Returns
! real(dp), pointer :: res(:,:)
! 
! ! Variables
! integer(int32) :: z
! 
! z = get_z_by_symbol(s)
! res => null()
! 
! if(allocated(n_ice_out))then
!     deallocate(n_ice_out)
! end if
! 
! if(z>0)then
!     allocate(n_ice_out(pt(z)%ice%n, 3))
!     n_ice_out(:,:) = pt(z)%ice%values(1:pt(z)%ice%n,:)
!     res => n_ice_out
! else
!     allocate(n_ice_out(1,3))
!     n_ice_out(1,:) = ice_nan%values(1,:)
!     res => null()
! endif
! end function get_ice_values
!-----------------------------------------------------------------------
! function capi_get_ice_values(s, n)bind(C, name="ciaaw_get_ice_values")result(res)
!     !! C API for [[ciaaw__api(module):get_ice_values(function)]]
    
!     ! Arguments
!     type(c_ptr), intent(in), value :: s           !! Element symbol.
!     integer(c_int), intent(in), value :: n        !! Size of the symbol string.

!     ! Returns
!     type(c_ptr) :: res

!     ! Variables
!     integer(c_int) :: i
!     character, pointer, dimension(:) :: c2f_s
!     character(len=n) :: fs
!     real(dp), pointer, contiguous :: fptr(:,:)
    
!     call c_f_pointer(s, c2f_s, shape=[n])

!     do i=1, n
!         fs(i:i) = c2f_s(i)
!     enddo

!     fptr => get_ice_values(fs)

!     res = c_loc(fptr)

! end function
!=======================================================================



!=======================================================================
! GET_NAW
!=======================================================================
function get_naw(s, A, u)result(res)
!! Get the atomic weight of the nuclide s for the mass number A.
character(len=*), intent(in) :: s   !! Element symbol.
integer(int32), intent(in) :: A     !! Mass number.
logical, intent(in), optional :: u  !! Flag for returning the uncertainty instead of the value. Default to FALSE.
real(dp) :: res                     !! NaN if the provided element or A are incorrect or -1 if the element does not have an NAW.

real(dp) :: A_double
integer(int32) :: i, z, col, row
logical :: u2


u2 = optval(u, .false.)
z = get_z_by_symbol(s)
A_double = real(A, dp)

res = ieee_value(1.0_dp, ieee_quiet_nan)

if(u2 .eqv. .true.)then
    col = 3
else
    col = 2
endif

row = 0
if((z>0) .and. (pt(z)%naw%n > 0))then
    do i=1, pt(z)%naw%n
        if(pt(z)%naw%values(i, 1) == A_double)then
            row = i
            exit
        endif
    end do
endif
if(row > 0)then
    res = pt(z)%naw%values(row, col)
endif
end function get_naw
!-----------------------------------------------------------------------
function capi_get_naw(s, n, A, u)bind(C, name="ciaaw_get_naw")result(res)
!! C API.
type(c_ptr), intent(in), value :: s      !! Element symbol.
integer(c_int), intent(in), value :: n   !! Size of the symbol string.
integer(c_int), intent(in), value :: A   !! Mass number.
logical(c_bool), intent(in), value :: u  !! Flag for returning the uncertainty instead of the value. Default to FALSE.
real(c_double) :: res                    !! NaN if the provided element or A are incorrect or -1 if the element does not have an NAW.

integer(c_int) :: i
character, pointer, dimension(:) :: c2f_s
character(len=n) :: fs
logical :: f_u

call c_f_pointer(s, c2f_s, shape=[n])

do i=1, n
    fs(i:i) = c2f_s(i)
enddo

f_u = logical(u)

res = get_naw(fs, A, f_u)
end function capi_get_naw
!=======================================================================


!=======================================================================
! GET_NNAW
!=======================================================================
function get_nnaw(s)result(res)
!! Get the number of nuclides in NAW of the element s.
character(len=*), intent(in) :: s   !! Element symbol.
integer(int32) :: res               !! >0 if found or -1 if not found.

integer(int32) :: z

z = get_z_by_symbol(s)

if(z>0)then
    res = pt(z)%naw%n
else
    res = -1
endif
end function get_nnaw
!-----------------------------------------------------------------------
function capi_get_nnaw(s,n)bind(C, name="ciaaw_get_nnaw")result(res)
!! C API.
type(c_ptr), intent(in), value :: s       !! Element symbol.
integer(c_int), intent(in), value :: n    !! Size of the symbol string.
integer(c_int) :: res

integer(c_int) :: i
character, pointer, dimension(:) :: c2f_s
character(len=n) :: fs

call c_f_pointer(s, c2f_s, shape=[n])

do i=1, n
    fs(i:i) = c2f_s(i)
enddo

res = get_nnaw(fs)
end function capi_get_nnaw
!=======================================================================
end module ciaaw
