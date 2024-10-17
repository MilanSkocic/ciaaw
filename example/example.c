#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "ciaaw.h"


    // ASAW = Abridged Standard Atomic Weight
    // SAW  = Standard Atomic Weight
    // ICE  = Isotopic Composition of the Element
    // U    = Uncertainty

int main(void){


    printf("%s\n", "########## CIAAW VERSION ##########");
    printf("version %s\n", ciaaw_get_version());
    
    printf("%s\n", "########## CIAAW SAW ##########");
    printf("%s %10.5f\n", "ASAW    = ", ciaaw_get_saw("H", 1, true, false));
    printf("%s %10.5f\n", "U ASAW  = ", ciaaw_get_saw("H", 1, true, true));
    printf("%s %10.5f\n", "SAW     = ", ciaaw_get_saw("H", 1, false, false));
    printf("%s %10.5f\n", "U SAW   = ", ciaaw_get_saw("H", 1, false, true));

    printf("%s\n", "########## CIAAW ICE ##########");
    printf("%s %d\n",     "N ICE H      = ", ciaaw_get_nice("H", 1));
    printf("%s %12.6f\n", "ICE H 1      = ", ciaaw_get_ice("H", 1, 1, false)); 
    printf("%s %23.16e\n", "U ICE H 1   = ", ciaaw_get_ice("H", 1, 1, true)); 
    printf("%s %12.6f\n", "ICE H 2      = ", ciaaw_get_ice("H", 1, 2, false)); 
    printf("%s %23.16e\n", "U ICE H 2   = ", ciaaw_get_ice("H", 1, 2, true)); 

    return EXIT_SUCCESS;
    }
