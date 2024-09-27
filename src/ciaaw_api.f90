module ciaaw__api
    !! Getters
    use ciaaw__common
    use ciaaw__types, only: element_type
    use ciaaw__pte, only: pt
    private

    public :: get_asaw, get_asaw_u    
    public :: get_asaw_by_symbol
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

function get_saw(z, s, name)result(res)
    !! 

    integer(int32), intent(in), optional :: z
    character(len=*), intent(in), optional :: s
    character(len=*), intent(in), optional :: name

    real(dp) :: res
    integer(int32) :: z2
    
    if(present(s))then
         z2 = get_z_by_symbol(s)
    else if(present(z))then
         z2 = z
    endif

    res = pt(z2)%saw%saw 

end function

! BY INDEX
function get_asaw(z)result(res)
    !! Get abridged standard atomic value by atomic number z.
    !! Returns -1 if the element is not found.
    integer(int32), intent(in) :: z

    real(dp) :: res 

    if(is_in_pt(z)) then
        res = pt(z)%saw%asaw
    else
        res = -1.0_dp
    end if
end function

function get_asaw_u(z)result(res)
    !! Get the uncertainty for the abridged standard atomic value by atomic number z.
    !! Returns -1 if the element is not found.
    integer(int32), intent(in) :: z

    real(dp) :: res 

    if(is_in_pt(z)) then
        res = pt(z)%saw%asaw_u
    else
        res = -1.0_dp
    end if
end function


! BY SYMBOL
function get_asaw_by_symbol(s)result(res)
    !! Get abridged standard atomic value by the symbol.
    !! Returns -1 if the element is not found.
    character(len=*), intent(in) :: s

    real(dp) :: res

    integer(int32) :: z

    z = get_z_by_symbol(s)

    if(z > 0) then
        res = get_asaw(z)
    end if

end function


end module
