#ifndef CIAAW_SAW_H
#define CIAAW_SAW_H
struct ciaaw_saw_capi_elmt_t{
    char element[25];
    char symbol[9];
    int z;
    double saw_min;
    double saw_max;
    double saw;
    double saw_u;
    double asaw;
    double asaw_u;
};
extern const int ciaaw_saw_capi_YEAR;

extern const struct ciaaw_saw_capi_elmt_t ciaaw_saw_capi_H;
extern const struct ciaaw_saw_capi_elmt_t ciaaw_saw_capi_He;
extern const struct ciaaw_saw_capi_elmt_t ciaaw_saw_capi_Li;
extern const struct ciaaw_saw_capi_elmt_t ciaaw_saw_capi_Be;
extern const struct ciaaw_saw_capi_elmt_t ciaaw_saw_capi_B;
extern const struct ciaaw_saw_capi_elmt_t ciaaw_saw_capi_C;
extern const struct ciaaw_saw_capi_elmt_t ciaaw_saw_capi_N;
extern const struct ciaaw_saw_capi_elmt_t ciaaw_saw_capi_O;
extern const struct ciaaw_saw_capi_elmt_t ciaaw_saw_capi_F;
extern const struct ciaaw_saw_capi_elmt_t ciaaw_saw_capi_Ne;
extern const struct ciaaw_saw_capi_elmt_t ciaaw_saw_capi_Na;
extern const struct ciaaw_saw_capi_elmt_t ciaaw_saw_capi_Mg;
extern const struct ciaaw_saw_capi_elmt_t ciaaw_saw_capi_Al;
extern const struct ciaaw_saw_capi_elmt_t ciaaw_saw_capi_Si;
extern const struct ciaaw_saw_capi_elmt_t ciaaw_saw_capi_P;
extern const struct ciaaw_saw_capi_elmt_t ciaaw_saw_capi_S;
extern const struct ciaaw_saw_capi_elmt_t ciaaw_saw_capi_Cl;
extern const struct ciaaw_saw_capi_elmt_t ciaaw_saw_capi_Ar;

#endif

