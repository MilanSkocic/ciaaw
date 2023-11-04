#include <stdlib.h>
#include <stdio.h>
#include "ciaaw.h"


int main(){

    printf("%d\n", ciaaw_saw_capi_H.z);
    printf("%f %f\n", ciaaw_saw_capi_H.saw, ciaaw_saw_capi_H.saw_u);
    printf("%f %f\n", ciaaw_saw_capi_H.asaw, ciaaw_saw_capi_H.asaw_u);
    return EXIT_SUCCESS;
}
