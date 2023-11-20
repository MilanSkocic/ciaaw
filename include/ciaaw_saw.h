#ifndef CIAAW_SAW_H
#define CIAAW_SAW_H
struct ciaaw_saw_capi_elmt_t{
    char element[33];
    char symbol[3];
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

#endif

