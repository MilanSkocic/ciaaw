module ciaaw__api
    !! API
    use ieee_arithmetic, only: ieee_value, ieee_quiet_nan, ieee_is_nan
    use ciaaw__version
    use ciaaw__common
    use ciaaw__types
    use ciaaw__pte
    private

    character(len=:), allocatable, target :: version_f

    real(dp), allocatable, target :: n_ice_out(:,:)

    public :: get_z_by_symbol
    public :: get_version
    public :: get_saw
    public :: get_ice, get_nice
    public :: get_naw, get_nnaw
    public :: print_periodic_table
    ! public :: get_ice_values

contains

! ------------------------------ -----------------------------------------------
! VERSION
function get_version()result(fptr)
    !! Get the version
    implicit none
    character(len=:), pointer :: fptr    !! Fortran pointer to a string indicating the version..

    if(allocated(version_f))then
        deallocate(version_f)
    endif
    allocate(character(len=len(version)) :: version_f)
    version_f = version
    fptr => version_f
end function
! ------------------------------------------------------------------------------

! ------------------------------------------------------------------------------
! Base search functions
function is_in_pt(z)result(res)
    !! Check if the atomic number z is in the periodic table
    integer(int32), intent(in) :: z  !! Atomic number
    logical :: res                   !! True or False

    if((z<1) .or. (z>size(pt))) then
        res = .false.
    else
        res = .true.
    end if
end function

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
end function


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
end subroutine
!-------------------------------------------------------------------------------




! ------------------------------------------------------------------------------
! SAW
function get_saw(s, abridged, uncertainty)result(res)
    !! Get the standard atomic weight for the element s.
    character(len=*), intent(in) :: s              !! Element symbol.
    logical, intent(in), optional :: abridged      !! Set to False if the abridged value is not desired. Default to TRUE.
    logical, intent(in), optional :: uncertainty   !! Set to True if the uncertainty is desired. Default to FALSE.
    real(dp) :: res                                !! NaN if the provided element is incorrect or -1 if the element does not have a SAW.

    real(dp) :: saw_max, saw_min, saw, saw_u
    integer(int32) :: z, n
    logical :: a2, u2


    a2 = optval(abridged, .true.)
    u2 = optval(uncertainty, .false.)

    z = get_z_by_symbol(s)

    res = ieee_value(1.0_dp, ieee_quiet_nan)

    if(z>0)then
        if(a2 .eqv. .true.)then
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
end function
! ------------------------------------------------------------------------------


! ------------------------------------------------------------------------------
! ICE
function get_ice(s, A, uncertainty)result(res)
    !! Get the isotopic composition of the element s for the mass number A.
    character(len=*), intent(in) :: s              !! Element symbol.
    integer(int32), intent(in) :: A                !! Mass number.
    logical, intent(in), optional :: uncertainty   !! Set to True if the uncertainty is desired. Default to FALSE.
    real(dp) :: res                                !! NaN if the provided element or the mass number A are incorrect or -1 if the element does not have an ICE.

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
end function

function get_nice(s)result(res)
    !! Get the number of isotopes in ICE of the element s.
    character(len=*), intent(in) :: s             !! Element symbol.
    integer(int32) :: res                         !! >0 if found or -1 if not found.

    integer(int32) :: z

    z = get_z_by_symbol(s)

    if(z>0)then
        res = pt(z)%ice%n
    else
        res = -1
    endif
end function

! function get_ice_values(s)result(res)
!     !! Get the (n, 3) values array. See [[ciaaw__types(module):ice_type(type)]].
!     !! Returns a null pointer if the provided symbol is incorrect.

!     ! Arguments
!     character(len=*), intent(in) :: s             !! Element symbol.

!     ! Returns
!     real(dp), pointer :: res(:,:)

!     ! Variables
!     integer(int32) :: z

!     z = get_z_by_symbol(s)
!     res => null()

!     if(allocated(n_ice_out))then
!         deallocate(n_ice_out)
!     end if

!     if(z>0)then
!         allocate(n_ice_out(pt(z)%ice%n, 3))
!         n_ice_out(:,:) = pt(z)%ice%values(1:pt(z)%ice%n,:)
!         res => n_ice_out
!     else
!         allocate(n_ice_out(1,3))
!         n_ice_out(1,:) = ice_nan%values(1,:)
!         res => null()
!     endif

! end function
! ------------------------------------------------------------------------------



! ------------------------------------------------------------------------------
! NAW
function get_naw(s, A, uncertainty)result(res)
    !! Get the atomic weight of the nuclide s for the mass number A.
    character(len=*), intent(in) :: s              !! Element symbol.
    integer(int32), intent(in) :: A                !! Mass number.
    logical, intent(in), optional :: uncertainty   !! Flag for returning the uncertainty instead of the value. Default to FALSE.
    real(dp) :: res                                !! NaN if the provided element or A are incorrect or -1 if the element does not have an NAW.

    ! Variables
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
end function

function get_nnaw(s)result(res)
    !! Get the number of nuclides in NAW of the element s.
    character(len=*), intent(in) :: s             !! Element symbol.
    integer(int32) :: res                         !! >O if found or -1 if not found.

    integer(int32) :: z

    z = get_z_by_symbol(s)

    if(z>0)then
        res = pt(z)%naw%n
    else
        res = -1
    endif
end function
!-------------------------------------------------------------------------------

end module
