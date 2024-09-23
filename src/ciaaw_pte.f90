module ciaaw__pte
    !! Periodic table of the element.
    !! See [specs](../page/specs/ciaaw_pte.html).
    use ciaaw__common
    use ciaaw__types
    use ciaaw__saw
    use ciaaw__ice
    implicit none
    private
    
    type(element_type), parameter :: pt(10) = [&
    element_type("hydrogen",    "H",      1,    H_saw,     H_ice),&
    element_type("helium",      "He",     2,    He_saw,    He_ice),&
    element_type("lithium",     "Li",     3,    Li_saw,    Li_ice),&
    element_type("beryllium",   "Be",     4,    Be_saw,    He_ice),&
    element_type("boron",       "B",      5,    B_saw,     He_ice),&
    element_type("carbon",      "C",      6,    C_saw,     He_ice),&
    element_type("nitrogen",    "N",      7,    N_saw,     He_ice),&
    element_type("oxygen",      "O",      8,    O_saw,     He_ice),&
    element_type("fluorine",    "F",      9,    F_saw,     He_ice),&
    element_type("Neon",        "Ne",    10,    F_saw,     He_ice)&
    ]

    public :: get_asaw, get_asaw_u    
    public :: get_asaw_by_symbol

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
