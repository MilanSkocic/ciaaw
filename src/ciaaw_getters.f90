module ciaaw__getters
    !! Getters
    use ciaaw__common
    use ciaaw__types, only: element_type
    use ciaaw__pte, only: pt

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
    integer(int32) :: i

    do i=1, size(pt)
        print "(A25, A3)", pt(i)%element, pt(i)%symbol
        print "(2F10.5)", pt(i)%saw%asaw, pt(i)%saw%asaw_u
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
