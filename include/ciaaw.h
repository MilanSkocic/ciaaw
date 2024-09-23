#ifndef CIAAW_H
#define CIAAW_H
#if _MSC_VER
#define ADD_IMPORT __declspec(dllimport)
#else
#define ADD_IMPORT
#endif

extern char* ciaaw_get_version(void);

extern double ciaaw_get_asaw(int z);

#endif
