#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "ciaaw.h"



int main(void){

    char s[9] = "";

    printf("%s\n", "########## CIAAW VERSION ##########");
    printf("version %s\n", ciaaw_get_version());
    
    printf("%s\n", "########## CIAAW SAW ##########");
    printf("%s %10.5f\n", "Abridged Standard Atomic Weight: ", ciaaw_get_saw("H", 1, true, false));
    printf("%s %10.5f\n", "Uncertainty for Abridged Standard Atomic Weight: ", ciaaw_get_saw("H", 1, true, true));
    printf("%s %10.5f\n", "Standard Atomic Weight: ", ciaaw_get_saw("H", 1, false, false));
    printf("%s %10.5f\n", "Uncertainty for Standard Atomic Weight: ", ciaaw_get_saw("H", 1, false, true));

    printf("%s\n", "");


    return EXIT_SUCCESS;
}
