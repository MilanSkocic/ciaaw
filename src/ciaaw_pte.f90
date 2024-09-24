module ciaaw__pte
    !! Periodic table of the element.
    !! See [specs](../page/specs/ciaaw_pte.html).
    use ciaaw__common
    use ciaaw__types
    use ciaaw__saw
    use ciaaw__ice
    implicit none
    private
    
    type(element_type), parameter :: pt(36) = [&
    element_type("hydrogen",    "H",      1,    H_saw,     H_ice),&
    element_type("helium",      "He",     2,    He_saw,    He_ice),&

    element_type("lithium",     "Li",     3,    Li_saw,    Li_ice),&
    element_type("beryllium",   "Be",     4,    Be_saw,    He_ice),&
    element_type("boron",       "B",      5,    B_saw,     He_ice),&
    element_type("carbon",      "C",      6,    C_saw,     He_ice),&
    element_type("nitrogen",    "N",      7,    N_saw,     He_ice),&
    element_type("oxygen",      "O",      8,    O_saw,     He_ice),&
    element_type("fluorine",    "F",      9,    F_saw,     He_ice),&
    element_type("neon",        "Ne",    10,    Ne_saw,    He_ice),&

    element_type("sodium",      "Na",    11,    Na_saw,    He_ice),&
    element_type("magnesium",   "Mg",    12,    Mg_saw,    He_ice),&
    element_type("aluminium",   "Al",    13,    Al_saw,    He_ice),&
    element_type("silicon",     "Si",    14,    Si_saw,    He_ice),&
    element_type("phosphorus",  "P",     15,    P_saw,     He_ice),&
    element_type("sulfur",      "S",     16,    S_saw,     He_ice),&
    element_type("chlorine",    "Cl",    17,    Cl_saw,    He_ice),&
    element_type("argon",       "Ar",    18,    Ar_saw,    He_ice),&
    
    element_type("potassium",   "K",     19,    K_saw,     He_ice),&
    element_type("calcium",     "Ca",    20,    Ca_saw,    He_ice),&
    element_type("scandium",    "Sc",    21,    Sc_saw,    He_ice),&
    element_type("titanium",    "Ti",    22,    Ti_saw,    He_ice),&
    element_type("vanadium",    "V",     23,    V_saw,     He_ice),&
    element_type("chromium",    "Cr",    24,    Cr_saw,    He_ice),&
    element_type("manganese",   "Mn",    25,    Mn_saw,    He_ice),&
    element_type("iron",        "Fe",    26,    Fe_saw,    He_ice),&
    element_type("cobalt",      "Co",    27,    Co_saw,    He_ice),&
    element_type("nickel",      "Ni",    28,    Ni_saw,    He_ice),&
    element_type("copper",      "Cu",    29,    Cu_saw,    He_ice),&
    element_type("zinc",        "Zn",    30,    Zn_saw,    He_ice),&
    element_type("gallium",     "Ga",    31,    Ga_saw,    He_ice),&
    element_type("germanium",   "Ge",    32,    Ge_saw,    He_ice),&
    element_type("arsenic",     "As",    33,    As_saw,    He_ice),&
    element_type("selenium",    "Se",    34,    Se_saw,    He_ice),&
    element_type("bromine",     "Br",    35,    Br_saw,    He_ice),&
    element_type("krypton",     "Kr",    36,    Kr_saw,    He_ice)&
    ]
    
    public :: element_type
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
