#ifndef CIAAW_SAW_H
#define CIAAW_SAW_H

struct ciaaw_saw_capi_elmt_t{
    int z; 
    double saw;
    double saw_u;
    double asaw;
    double asaw_u;
};

extern const struct ciaaw_saw_capi_elmt_t ciaaw_saw_capi_H;

#endif