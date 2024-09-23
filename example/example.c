#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ciaaw.h"



int main(void){

    char s[9] = "";

    printf("%s\n", "########## CIAAW VERSION ##########");
    printf("version %s\n", ciaaw_get_version());
    
    printf("%s\n", "########## CIAAW SAW - get by atomic number z ##########");
    printf("%s %10.5f", "Abridged Standard Atomic Weight: ", ciaaw_get_asaw(1));
    //printf("%s %10.5f", "Uncertainty for Abridged Standard Atomic Weight: ", get_asaw_u(1));

    printf("%s\n", "");


    return EXIT_SUCCESS;
}
