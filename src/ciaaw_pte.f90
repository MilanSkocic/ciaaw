module ciaaw__pte
    !! Ciaaw pte - Autogenerated
    !! See [specs](../page/specs/ciaaw_pte.html)
    use ciaaw__common
    use ciaaw__types
    use ciaaw__saw
    use ciaaw__ice
    use ciaaw__ice
    private

type(element_type), parameter, public :: pt(5) = [&
 element_type("hydrogen",          "H",       1,         H_saw,     H_ice     ),&
 element_type("helium",            "He",      2,         He_saw,    He_ice    ),&
 element_type("lithium",           "Li",      3,         Li_saw,    Li_ice    ),&
 element_type("beryllium",         "B",       4,         Be_saw,    Be_ice    ),&
 element_type("boron",             "B",       5,         B_saw,    B_ice    )&
]
end module ciaaw__pte
