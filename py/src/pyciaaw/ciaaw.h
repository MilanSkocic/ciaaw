#ifndef CIAAW_H
#define CIAAW_H
#if _MSC_VER
#define ADD_IMPORT __declspec(dllimport)
#else
#define ADD_IMPORT
#endif
#include <stdbool.h>

extern char* ciaaw_get_version(void);
extern double ciaaw_get_saw(char *s, int n, bool abridged, bool uncertainty);
extern double ciaaw_get_ice(char *s, int n, int A, bool uncertainty);
extern int ciaaw_get_nice(char *s, int n);
extern double ciaaw_get_naw(char *s, int n, int A, bool uncertaintuy);
extern int ciaaw_get_nnaw(char *s, int n);

#endif
