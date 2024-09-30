module ciaaw__api
    !! Getters
    use ieee_arithmetic, only: ieee_value, ieee_quiet_nan, ieee_is_nan
    use ciaaw__common
    use ciaaw__types, only: element_type
    use ciaaw__pte, only: pt
    private

    public :: get_saw    
    public :: print_periodic_table

contains

! Base search functions
function is_in_pt(z)result(res)
    !! Check if the atomic number z is in the periodic table
    integer(int32), intent(in) :: z
    logical :: res
    
    if((z<1) .or. (z>size(pt))) then
        res = .false.
    else
        res = .true.
    end if
end function

function get_z_by_symbol(s)result(res)
    !! Get the atomic number z of the element defined by the symbol s.
    !! Returns -1 if the element is not found.
    character(len=*), intent(in) :: s
    integer(int32) :: res

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

    header = [character(len=20) :: "", "", ""]
    ice_headers = [character(len=15) :: "A", "C /%", "dC /%"]

    do i=1, size(pt)
        print "(A)", "======================================================================"
        header(1) = pt(i)%symbol
        header(2) = pt(i)%element
        write(v, "(I3)") pt(i)%z
        header(3) = "z=" // v
        print "(3A15)", header
        print "(A)", "======================================================================"
        
        print "(A)", "STANDARD ATOMIC WEIGHTS" 
        write(v, "(F10.5)") pt(i)%saw%asaw
        write(u, "(F10.5)") pt(i)%saw%asaw_u
        print "(A4, A10, A, A10)", "M = ", adjustl(v), "+/-", adjustl(u)
        
        print "(A)", "----------------------------------------------------------------------"
        
        print "(A)", "ISOTOPIC COMPOSITIONS" 
        print "(3A15)", ice_headers 
        do j=1, pt(i)%ice%n
            write(w, "(I3)") nint(pt(i)%ice%values(j,1))
            write(v, "(ES12.5)") pt(i)%ice%values(j,2)
            write(u, "(ES12.5)") pt(i)%ice%values(j,3)
            print "(3A15)", adjustl(w), adjustl(v), adjustl(u) 
        enddo
        print "(A)", "======================================================================"

        print *, ""
        print *, ""

    end do

end subroutine


function get_saw(s, abridged, uncertainty)result(res)
    !! Get the standard atomic weight. By default the abridged value is provided.
    !! If the non abridged value is desired, set abridged to false.
    !! The uncertainty instead of the value can be retrieved if the uncertainty is set to true.

    character(len=*), intent(in) :: s                 !! Element symbol.
    logical, intent(in), optional :: abridged         !! Flag for returning the abridged standard atomic weight. Default to TRUE.
    logical, intent(in), optional :: uncertainty      !! Flag for returning the uncertainty instead of the value. Default to FALSE.

    real(dp) :: res, saw_max, saw_min, saw, saw_u
    integer(int32) :: z, n
    
    logical :: v, u
    
    v = optval(abridged, .true.)
    u = optval(uncertainty, .false.)
        
    z = get_z_by_symbol(s)
    
    if(z>0)then
        if(v .eqv. .true.)then
            if(u .eqv. .true.)then
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
                
                if(u .eqv. .true.)then
                    res = saw_u
                else
                    res = saw
                end if
            else
                if(u .eqv. .true.)then
                    res = pt(z)%saw%saw_u
                else
                    res = pt(z)%saw%saw
                end if 
            end if 
        end if
    end if

    if(res < 0.0_dp)then
        res = ieee_value(1.0_dp, ieee_quiet_nan)
    endif

end function


end module
