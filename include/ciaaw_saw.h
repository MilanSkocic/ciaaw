/**
* @file
* @brief CIAAW_SAW module - autogenerated.
*/

#ifndef CIAAW_SAW_H
#define CIAAW_SAW_H
#if _MSC_VER
#define ADD_IMPORT __declspec(dllimport)
#else
#define ADD_IMPORT
#endif
struct ciaaw_saw_capi_element_t{
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
ADD_IMPORT extern const int ciaaw_saw_capi_YEAR;

ADD_IMPORT extern const struct ciaaw_saw_capi_element_t ciaaw_saw_capi_H;
ADD_IMPORT extern const struct ciaaw_saw_capi_element_t ciaaw_saw_capi_He;
ADD_IMPORT extern const struct ciaaw_saw_capi_element_t ciaaw_saw_capi_Li;
ADD_IMPORT extern const struct ciaaw_saw_capi_element_t ciaaw_saw_capi_Be;
ADD_IMPORT extern const struct ciaaw_saw_capi_element_t ciaaw_saw_capi_B;
ADD_IMPORT extern const struct ciaaw_saw_capi_element_t ciaaw_saw_capi_C;
ADD_IMPORT extern const struct ciaaw_saw_capi_element_t ciaaw_saw_capi_N;
ADD_IMPORT extern const struct ciaaw_saw_capi_element_t ciaaw_saw_capi_O;
ADD_IMPORT extern const struct ciaaw_saw_capi_element_t ciaaw_saw_capi_F;
ADD_IMPORT extern const struct ciaaw_saw_capi_element_t ciaaw_saw_capi_Ne;
ADD_IMPORT extern const struct ciaaw_saw_capi_element_t ciaaw_saw_capi_Na;
ADD_IMPORT extern const struct ciaaw_saw_capi_element_t ciaaw_saw_capi_Mg;
ADD_IMPORT extern const struct ciaaw_saw_capi_element_t ciaaw_saw_capi_Al;
ADD_IMPORT extern const struct ciaaw_saw_capi_element_t ciaaw_saw_capi_Si;
ADD_IMPORT extern const struct ciaaw_saw_capi_element_t ciaaw_saw_capi_P;
ADD_IMPORT extern const struct ciaaw_saw_capi_element_t ciaaw_saw_capi_S;
ADD_IMPORT extern const struct ciaaw_saw_capi_element_t ciaaw_saw_capi_Cl;
ADD_IMPORT extern const struct ciaaw_saw_capi_element_t ciaaw_saw_capi_Ar;

#endif

