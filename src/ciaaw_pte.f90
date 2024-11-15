module ciaaw__pte
    !! Ciaaw pte - Autogenerated
    !! See [specs](../page/specs/ciaaw_api.html)
    use ciaaw__common
    use ciaaw__types
    use ciaaw__saw
    use ciaaw__ice
    use ciaaw__naw
    private

type(element_type), parameter, public :: pt(118) = [&
 element_type("hydrogen",          "H",       1,         H_saw,     H_ice,     H_naw     ),&
 element_type("helium",            "He",      2,         He_saw,    He_ice,    He_naw    ),&
 element_type("lithium",           "Li",      3,         Li_saw,    Li_ice,    Li_naw    ),&
 element_type("beryllium",         "Be",      4,         Be_saw,    Be_ice,    Be_naw    ),&
 element_type("boron",             "B",       5,         B_saw,     B_ice,     B_naw     ),&
 element_type("carbon",            "C",       6,         C_saw,     C_ice,     C_naw     ),&
 element_type("nitrogen",          "N",       7,         N_saw,     N_ice,     N_naw     ),&
 element_type("oxygen",            "O",       8,         O_saw,     O_ice,     O_naw     ),&
 element_type("fluorine",          "F",       9,         F_saw,     F_ice,     F_naw     ),&
 element_type("neon",              "Ne",      10,        Ne_saw,    Ne_ice,    Ne_naw    ),&
 element_type("sodium",            "Na",      11,        Na_saw,    Na_ice,    Na_naw    ),&
 element_type("magnesium",         "Mg",      12,        Mg_saw,    Mg_ice,    Mg_naw    ),&
 element_type("aluminium",         "Al",      13,        Al_saw,    Al_ice,    Al_naw    ),&
 element_type("silicon",           "Si",      14,        Si_saw,    Si_ice,    Si_naw    ),&
 element_type("phosphorus",        "P",       15,        P_saw,     P_ice,     P_naw     ),&
 element_type("sulfur",            "S",       16,        S_saw,     S_ice,     S_naw     ),&
 element_type("chlorine",          "Cl",      17,        Cl_saw,    Cl_ice,    Cl_naw    ),&
 element_type("argon",             "Ar",      18,        Ar_saw,    Ar_ice,    Ar_naw    ),&
 element_type("potassium",         "K",       19,        K_saw,     K_ice,     K_naw     ),&
 element_type("calcium",           "Ca",      20,        Ca_saw,    Ca_ice,    Ca_naw    ),&
 element_type("scandium",          "Sc",      21,        Sc_saw,    Sc_ice,    Sc_naw    ),&
 element_type("titanium",          "Ti",      22,        Ti_saw,    Ti_ice,    Ti_naw    ),&
 element_type("vanadium",          "V",       23,        V_saw,     V_ice,     V_naw     ),&
 element_type("chromium",          "Cr",      24,        Cr_saw,    Cr_ice,    Cr_naw    ),&
 element_type("manganese",         "Mn",      25,        Mn_saw,    Mn_ice,    Mn_naw    ),&
 element_type("iron",              "Fe",      26,        Fe_saw,    Fe_ice,    Fe_naw    ),&
 element_type("cobalt",            "Co",      27,        Co_saw,    Co_ice,    Co_naw    ),&
 element_type("nickel",            "Ni",      28,        Ni_saw,    Ni_ice,    Ni_naw    ),&
 element_type("copper",            "Cu",      29,        Cu_saw,    Cu_ice,    Cu_naw    ),&
 element_type("zinc",              "Zn",      30,        Zn_saw,    Zn_ice,    Zn_naw    ),&
 element_type("gallium",           "Ga",      31,        Ga_saw,    Ga_ice,    Ga_naw    ),&
 element_type("germanium",         "Ge",      32,        Ge_saw,    Ge_ice,    Ge_naw    ),&
 element_type("arsenic",           "As",      33,        As_saw,    As_ice,    As_naw    ),&
 element_type("selenium",          "Se",      34,        Se_saw,    Se_ice,    Se_naw    ),&
 element_type("bromine",           "Br",      35,        Br_saw,    Br_ice,    Br_naw    ),&
 element_type("krypton",           "Kr",      36,        Kr_saw,    Kr_ice,    Kr_naw    ),&
 element_type("rubidium",          "Rb",      37,        Rb_saw,    Rb_ice,    Rb_naw    ),&
 element_type("strontium",         "Sr",      38,        Sr_saw,    Sr_ice,    Sr_naw    ),&
 element_type("yttrium",           "Y",       39,        Y_saw,     Y_ice,     Y_naw     ),&
 element_type("zirconium",         "Zr",      40,        Zr_saw,    Zr_ice,    Zr_naw    ),&
 element_type("nobium",            "Nb",      41,        Nb_saw,    Nb_ice,    Nb_naw    ),&
 element_type("molybdenum",        "Mo",      42,        Mo_saw,    Mo_ice,    Mo_naw    ),&
 element_type("technetium",        "Tc",      43,        Tc_saw,    Tc_ice,    Tc_naw    ),&
 element_type("ruthenium",         "Ru",      44,        Ru_saw,    Ru_ice,    Ru_naw    ),&
 element_type("rhodium",           "Rh",      45,        Rh_saw,    Rh_ice,    Rh_naw    ),&
 element_type("palladium",         "Pd",      46,        Pd_saw,    Pd_ice,    Pd_naw    ),&
 element_type("silver",            "Ag",      47,        Ag_saw,    Ag_ice,    Ag_naw    ),&
 element_type("cadmium",           "Cd",      48,        Cd_saw,    Cd_ice,    Cd_naw    ),&
 element_type("indium",            "In",      49,        In_saw,    In_ice,    In_naw    ),&
 element_type("tin",               "Sn",      50,        Sn_saw,    Sn_ice,    Sn_naw    ),&
 element_type("antimony",          "Sb",      51,        Sb_saw,    Sb_ice,    Sb_naw    ),&
 element_type("tellurium",         "Te",      52,        Te_saw,    Te_ice,    Te_naw    ),&
 element_type("iodine",            "I",       53,        I_saw,     I_ice,     I_naw     ),&
 element_type("xenon",             "Xe",      54,        Xe_saw,    Xe_ice,    Xe_naw    ),&
 element_type("caesium",           "Cs",      55,        Cs_saw,    Cs_ice,    Cs_naw    ),&
 element_type("barium",            "Ba",      56,        Ba_saw,    ice_nan,   Ba_naw    ),&
 element_type("lanthanum",         "La",      57,        La_saw,    ice_nan,   La_naw    ),&
 element_type("cerium",            "Ce",      58,        Ce_saw,    ice_nan,   Ce_naw    ),&
 element_type("praseodymium",      "Pr",      59,        Pr_saw,    ice_nan,   Pr_naw    ),&
 element_type("neodymium",         "Nd",      60,        Nd_saw,    ice_nan,   Nd_naw    ),&
 element_type("promethium",        "Pm",      61,        Pm_saw,    ice_nan,   Pm_naw    ),&
 element_type("samarium",          "Sm",      62,        Sm_saw,    ice_nan,   Sm_naw    ),&
 element_type("europium",          "Eu",      63,        Eu_saw,    ice_nan,   Eu_naw    ),&
 element_type("gadolinium",        "Gd",      64,        Gd_saw,    ice_nan,   Gd_naw    ),&
 element_type("terbium",           "Tb",      65,        Tb_saw,    ice_nan,   Tb_naw    ),&
 element_type("dysprosium",        "Dy",      66,        Dy_saw,    ice_nan,   Dy_naw    ),&
 element_type("holmium",           "Ho",      67,        Ho_saw,    ice_nan,   Ho_naw    ),&
 element_type("erbium",            "Er",      68,        Er_saw,    ice_nan,   Er_naw    ),&
 element_type("thulium",           "Tm",      69,        Tm_saw,    ice_nan,   Tm_naw    ),&
 element_type("ytterbium",         "Yb",      70,        Yb_saw,    ice_nan,   Yb_naw    ),&
 element_type("lutetium",          "Lu",      71,        Lu_saw,    ice_nan,   Lu_naw    ),&
 element_type("hafnium",           "Hf",      72,        Hf_saw,    ice_nan,   Hf_naw    ),&
 element_type("tantalum",          "Ta",      73,        Ta_saw,    ice_nan,   Ta_naw    ),&
 element_type("tungsten",          "W",       74,        W_saw,     ice_nan,   W_naw     ),&
 element_type("rhenium",           "Re",      75,        Re_saw,    ice_nan,   Re_naw    ),&
 element_type("osmium",            "Os",      76,        Os_saw,    ice_nan,   Os_naw    ),&
 element_type("iridium",           "Ir",      77,        Ir_saw,    ice_nan,   Ir_naw    ),&
 element_type("platinum",          "Pt",      78,        Pt_saw,    ice_nan,   Pt_naw    ),&
 element_type("gold",              "Au",      79,        Au_saw,    ice_nan,   Au_naw    ),&
 element_type("mercury",           "Hg",      80,        Hg_saw,    ice_nan,   Hg_naw    ),&
 element_type("thallium",          "Tl",      81,        Tl_saw,    ice_nan,   Tl_naw    ),&
 element_type("lead",              "Pb",      82,        Pb_saw,    ice_nan,   Pb_naw    ),&
 element_type("bismuth",           "Bi",      83,        Bi_saw,    ice_nan,   Bi_naw    ),&
 element_type("polonium",          "Po",      84,        Po_saw,    ice_nan,   Po_naw    ),&
 element_type("astatine",          "At",      85,        At_saw,    ice_nan,   At_naw    ),&
 element_type("radon",             "Rn",      86,        Rn_saw,    ice_nan,   Rn_naw    ),&
 element_type("francium",          "Fr",      87,        Fr_saw,    ice_nan,   Fr_naw    ),&
 element_type("radium",            "Ra",      88,        Ra_saw,    ice_nan,   Ra_naw    ),&
 element_type("actinium",          "Ac",      89,        Ac_saw,    ice_nan,   Ac_naw    ),&
 element_type("thorium",           "Th",      90,        Th_saw,    ice_nan,   Th_naw    ),&
 element_type("protactinium",      "Pa",      91,        Pa_saw,    ice_nan,   Pa_naw    ),&
 element_type("uranium",           "U",       92,        U_saw,     ice_nan,   U_naw     ),&
 element_type("neptunium",         "Np",      93,        Np_saw,    ice_nan,   Np_naw    ),&
 element_type("plutonium",         "Pu",      94,        Pu_saw,    ice_nan,   Pu_naw    ),&
 element_type("americium",         "Am",      95,        Am_saw,    ice_nan,   Am_naw    ),&
 element_type("curium",            "Cm",      96,        Cm_saw,    ice_nan,   Cm_naw    ),&
 element_type("berkelium",         "Bk",      97,        Bk_saw,    ice_nan,   Bk_naw    ),&
 element_type("californium",       "Cf",      98,        Cf_saw,    ice_nan,   Cf_naw    ),&
 element_type("einsteinium",       "Es",      99,        Es_saw,    ice_nan,   Es_naw    ),&
 element_type("fermium",           "Fm",      100,       Fm_saw,    ice_nan,   Fm_naw    ),&
 element_type("mendelevium",       "Md",      101,       Md_saw,    ice_nan,   Md_naw    ),&
 element_type("nobelium",          "No",      102,       No_saw,    ice_nan,   No_naw    ),&
 element_type("lawrencium",        "Lr",      103,       Lr_saw,    ice_nan,   Lr_naw    ),&
 element_type("rutherfordium",     "Rf",      104,       Rf_saw,    ice_nan,   Rf_naw    ),&
 element_type("dubnium",           "Db",      105,       Db_saw,    ice_nan,   Db_naw    ),&
 element_type("seaborgium",        "Sg",      106,       Sg_saw,    ice_nan,   Sg_naw    ),&
 element_type("bohrium",           "Bh",      107,       Bh_saw,    ice_nan,   Bh_naw    ),&
 element_type("hassium",           "Hs",      108,       Hs_saw,    ice_nan,   Hs_naw    ),&
 element_type("meitnerium",        "Mt",      109,       Mt_saw,    ice_nan,   Mt_naw    ),&
 element_type("darmstadtium",      "Ds",      110,       Ds_saw,    ice_nan,   Ds_naw    ),&
 element_type("roentgenium",       "Rg",      111,       Rg_saw,    ice_nan,   Rg_naw    ),&
 element_type("copernicium",       "Cn",      112,       Cn_saw,    ice_nan,   Cn_naw    ),&
 element_type("nihonium",          "Nh",      113,       Nh_saw,    ice_nan,   Nh_naw    ),&
 element_type("flerovium",         "Fl",      114,       Fl_saw,    ice_nan,   Fl_naw    ),&
 element_type("moscovium",         "Mc",      115,       Mc_saw,    ice_nan,   Mc_naw    ),&
 element_type("livermorium",       "Lv",      116,       Lv_saw,    ice_nan,   Lv_naw    ),&
 element_type("tennesine",         "Ts",      117,       Ts_saw,    ice_nan,   Ts_naw    ),&
 element_type("organesson",        "Og",      118,       Og_saw,    ice_nan,   Og_naw    )&
]
end module ciaaw__pte