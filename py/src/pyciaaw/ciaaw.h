#ifndef CIAAW_H
#define CIAAW_H
#if _MSC_VER
#define ADD_IMPORT __declspec(dllimport)
#else
#define ADD_IMPORT
#endif

extern char* ciaaw_get_version(void);

struct ciaaw_saw_type{
    char element[25]; 
    char symbol[9]; 
    int z; 
    double saw_min; 
    double saw_max; 
    double saw; 
    double saw_u;
    double asaw; 
    double asaw_u; 
    char footnotes[9];
};

ADD_IMPORT extern const int ciaaw_saw_YEAR;

ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_H;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_He;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Li;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Be;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_B;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_C;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_N;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_O;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_F;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Ne;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Na;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Mg;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Al;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Si;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_P;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_S;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Cl;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Ar;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_K;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Ca;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Sc;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Ti;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_V;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Cr;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Mn;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Fe;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Co;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Ni;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Cu;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Zn;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Ga;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Ge;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_As;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Se;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Br;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Kr;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Rb;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Sr;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Y;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Zr;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Nb;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Mo;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Tc;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Ru;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Rh;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Pd;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Ag;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Cd;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_In;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Sn;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Sb;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Te;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_I;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Xe;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Cs;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Ba;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_La;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Ce;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Pr;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Nd;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Pm;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Sm;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Eu;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Gd;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Tb;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Dy;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Ho;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Er;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Tm;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Yb;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Lu;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Hf;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Ta;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_W;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Re;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Os;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Ir;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Pt;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Au;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Hg;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Tl;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Pb;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Bi;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Po;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_At;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Rn;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Fr;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Ra;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Ac;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Th;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Pa;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_U;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Np;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Pu;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Am;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Cm;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Bk;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Cf;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Es;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Fm;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Md;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_No;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Lr;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Rf;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Db;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Sg;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Bh;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Hs;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Mt;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Ds;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Rg;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Cn;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Nh;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Fl;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Mc;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Lv;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Ts;
ADD_IMPORT extern const struct ciaaw_saw_type ciaaw_saw_Og;

#endif
