module ciaaw__pte
    !! Ciaaw pte - Autogenerated
    !! See [specs](../page/specs/ciaaw_api.html)
    use ciaaw__common
    use ciaaw__types
    use ciaaw__saw
    use ciaaw__ice
    use ciaaw__ice
    private

type(element_type), parameter, public :: pt(118) = [&
 element_type("hydrogen",          "H",       1,         H_saw,     H_ice     ),&
 element_type("helium",            "He",      2,         He_saw,    He_ice    ),&
 element_type("lithium",           "Li",      3,         Li_saw,    Li_ice    ),&
 element_type("beryllium",         "Be",      4,         Be_saw,    Be_ice    ),&
 element_type("boron",             "B",       5,         B_saw,     B_ice     ),&
 element_type("carbon",            "C",       6,         C_saw,     C_ice     ),&
 element_type("nitrogen",          "N",       7,         N_saw,     N_ice     ),&
 element_type("oxygen",            "O",       8,         O_saw,     O_ice     ),&
 element_type("fluorine",          "F",       9,         F_saw,     F_ice     ),&
 element_type("neon",              "Ne",      10,        Ne_saw,    Ne_ice    ),&
 element_type("sodium",            "Na",      11,        Na_saw,    Na_ice    ),&
 element_type("magnesium",         "Mg",      12,        Mg_saw,    Mg_ice    ),&
 element_type("aluminium",         "Al",      13,        Al_saw,    Al_ice    ),&
 element_type("silicon",           "Si",      14,        Si_saw,    Si_ice    ),&
 element_type("phosphorus",        "P",       15,        P_saw,     P_ice     ),&
 element_type("sulfur",            "S",       16,        S_saw,     S_ice     ),&
 element_type("chlorine",          "Cl",      17,        Cl_saw,    Cl_ice    ),&
 element_type("argon",             "Ar",      18,        Ar_saw,    Ar_ice    ),&
 element_type("potassium",         "K",       19,        K_saw,     K_ice     ),&
 element_type("calcium",           "Ca",      20,        Ca_saw,    Ca_ice    ),&
 element_type("scandium",          "Sc",      21,        Sc_saw,    Sc_ice    ),&
 element_type("titanium",          "Ti",      22,        Ti_saw,    Ti_ice    ),&
 element_type("vanadium",          "V",       23,        V_saw,     V_ice     ),&
 element_type("chromium",          "Cr",      24,        Cr_saw,    ice_nan   ),&
 element_type("manganese",         "Mn",      25,        Mn_saw,    ice_nan   ),&
 element_type("iron",              "Fe",      26,        Fe_saw,    ice_nan   ),&
 element_type("cobalt",            "Co",      27,        Co_saw,    ice_nan   ),&
 element_type("nickel",            "Ni",      28,        Ni_saw,    ice_nan   ),&
 element_type("copper",            "Cu",      29,        Cu_saw,    ice_nan   ),&
 element_type("zinc",              "Zn",      30,        Zn_saw,    ice_nan   ),&
 element_type("gallium",           "Ga",      31,        Ga_saw,    ice_nan   ),&
 element_type("germanium",         "Ge",      32,        Ge_saw,    ice_nan   ),&
 element_type("arsenic",           "As",      33,        As_saw,    ice_nan   ),&
 element_type("selenium",          "Se",      34,        Se_saw,    ice_nan   ),&
 element_type("bromine",           "Br",      35,        Br_saw,    ice_nan   ),&
 element_type("krypton",           "Kr",      36,        Kr_saw,    ice_nan   ),&
 element_type("rubidium",          "Rb",      37,        Rb_saw,    ice_nan   ),&
 element_type("strontium",         "Sr",      38,        Sr_saw,    ice_nan   ),&
 element_type("yttrium",           "Y",       39,        Y_saw,     ice_nan   ),&
 element_type("zirconium",         "Zr",      40,        Zr_saw,    ice_nan   ),&
 element_type("nobium",            "Nb",      41,        Nb_saw,    ice_nan   ),&
 element_type("molybdenum",        "Mo",      42,        Mo_saw,    ice_nan   ),&
 element_type("technetium",        "Tc",      43,        Tc_saw,    ice_nan   ),&
 element_type("ruthenium",         "Ru",      44,        Ru_saw,    ice_nan   ),&
 element_type("rhodium",           "Rh",      45,        Rh_saw,    ice_nan   ),&
 element_type("palladium",         "Pd",      46,        Pd_saw,    ice_nan   ),&
 element_type("silver",            "Ag",      47,        Ag_saw,    ice_nan   ),&
 element_type("cadmium",           "Cd",      48,        Cd_saw,    ice_nan   ),&
 element_type("indium",            "In",      49,        In_saw,    ice_nan   ),&
 element_type("tin",               "Sn",      50,        Sn_saw,    ice_nan   ),&
 element_type("antimony",          "Sb",      51,        Sb_saw,    ice_nan   ),&
 element_type("tellurium",         "Te",      52,        Te_saw,    ice_nan   ),&
 element_type("iodine",            "I",       53,        I_saw,     ice_nan   ),&
 element_type("xenon",             "Xe",      54,        Xe_saw,    ice_nan   ),&
 element_type("caesium",           "Cs",      55,        Cs_saw,    ice_nan   ),&
 element_type("barium",            "Ba",      56,        Ba_saw,    ice_nan   ),&
 element_type("lanthanum",         "La",      57,        La_saw,    ice_nan   ),&
 element_type("cerium",            "Ce",      58,        Ce_saw,    ice_nan   ),&
 element_type("praseodymium",      "Pr",      59,        Pr_saw,    ice_nan   ),&
 element_type("neodymium",         "Nd",      60,        Nd_saw,    ice_nan   ),&
 element_type("promethium",        "Pm",      61,        Pm_saw,    ice_nan   ),&
 element_type("samarium",          "Sm",      62,        Sm_saw,    ice_nan   ),&
 element_type("europium",          "Eu",      63,        Eu_saw,    ice_nan   ),&
 element_type("gadolinium",        "Gd",      64,        Gd_saw,    ice_nan   ),&
 element_type("terbium",           "Tb",      65,        Tb_saw,    ice_nan   ),&
 element_type("dysprosium",        "Dy",      66,        Dy_saw,    ice_nan   ),&
 element_type("holmium",           "Ho",      67,        Ho_saw,    ice_nan   ),&
 element_type("erbium",            "Er",      68,        Er_saw,    ice_nan   ),&
 element_type("thulium",           "Tm",      69,        Tm_saw,    ice_nan   ),&
 element_type("ytterbium",         "Yb",      70,        Yb_saw,    ice_nan   ),&
 element_type("lutetium",          "Lu",      71,        Lu_saw,    ice_nan   ),&
 element_type("hafnium",           "Hf",      72,        Hf_saw,    ice_nan   ),&
 element_type("tantalum",          "Ta",      73,        Ta_saw,    ice_nan   ),&
 element_type("tungsten",          "W",       74,        W_saw,     ice_nan   ),&
 element_type("rhenium",           "Re",      75,        Re_saw,    ice_nan   ),&
 element_type("osmium",            "Os",      76,        Os_saw,    ice_nan   ),&
 element_type("iridium",           "Ir",      77,        Ir_saw,    ice_nan   ),&
 element_type("platinum",          "Pt",      78,        Pt_saw,    ice_nan   ),&
 element_type("gold",              "Au",      79,        Au_saw,    ice_nan   ),&
 element_type("mercury",           "Hg",      80,        Hg_saw,    ice_nan   ),&
 element_type("thallium",          "Tl",      81,        Tl_saw,    ice_nan   ),&
 element_type("lead",              "Pb",      82,        Pb_saw,    ice_nan   ),&
 element_type("bismuth",           "Bi",      83,        Bi_saw,    ice_nan   ),&
 element_type("polonium",          "Po",      84,        Po_saw,    ice_nan   ),&
 element_type("astatine",          "At",      85,        At_saw,    ice_nan   ),&
 element_type("radon",             "Rn",      86,        Rn_saw,    ice_nan   ),&
 element_type("francium",          "Fr",      87,        Fr_saw,    ice_nan   ),&
 element_type("radium",            "Ra",      88,        Ra_saw,    ice_nan   ),&
 element_type("actinium",          "Ac",      89,        Ac_saw,    ice_nan   ),&
 element_type("thorium",           "Th",      90,        Th_saw,    ice_nan   ),&
 element_type("protactinium",      "Pa",      91,        Pa_saw,    ice_nan   ),&
 element_type("uranium",           "U",       92,        U_saw,     ice_nan   ),&
 element_type("neptunium",         "Np",      93,        Np_saw,    ice_nan   ),&
 element_type("plutonium",         "Pu",      94,        Pu_saw,    ice_nan   ),&
 element_type("americium",         "Am",      95,        Am_saw,    ice_nan   ),&
 element_type("curium",            "Cm",      96,        Cm_saw,    ice_nan   ),&
 element_type("berkelium",         "Bk",      97,        Bk_saw,    ice_nan   ),&
 element_type("californium",       "Cf",      98,        Cf_saw,    ice_nan   ),&
 element_type("einsteinium",       "Es",      99,        Es_saw,    ice_nan   ),&
 element_type("fermium",           "Fm",      100,       Fm_saw,    ice_nan   ),&
 element_type("mendelevium",       "Md",      101,       Md_saw,    ice_nan   ),&
 element_type("nobelium",          "No",      102,       No_saw,    ice_nan   ),&
 element_type("lawrencium",        "Lr",      103,       Lr_saw,    ice_nan   ),&
 element_type("rutherfordium",     "Rf",      104,       Rf_saw,    ice_nan   ),&
 element_type("dubnium",           "Db",      105,       Db_saw,    ice_nan   ),&
 element_type("seaborgium",        "Sg",      106,       Sg_saw,    ice_nan   ),&
 element_type("bohrium",           "Bh",      107,       Bh_saw,    ice_nan   ),&
 element_type("hassium",           "Hs",      108,       Hs_saw,    ice_nan   ),&
 element_type("meitnerium",        "Mt",      109,       Mt_saw,    ice_nan   ),&
 element_type("darmstadtium",      "Ds",      110,       Ds_saw,    ice_nan   ),&
 element_type("roentgenium",       "Rg",      111,       Rg_saw,    ice_nan   ),&
 element_type("copernicium",       "Cn",      112,       Cn_saw,    ice_nan   ),&
 element_type("nihonium",          "Nh",      113,       Nh_saw,    ice_nan   ),&
 element_type("flerovium",         "Fl",      114,       Fl_saw,    ice_nan   ),&
 element_type("moscovium",         "Mc",      115,       Mc_saw,    ice_nan   ),&
 element_type("livermorium",       "Lv",      116,       Lv_saw,    ice_nan   ),&
 element_type("tennesine",         "Ts",      117,       Ts_saw,    ice_nan   ),&
 element_type("organesson",        "Og",      118,       Og_saw,    ice_nan   )&
]
end module ciaaw__pte