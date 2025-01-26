/* EXAMPLE IN C */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "ciaaw.h"


    // ASAW = Abridged Standard Atomic Weight
    // SAW  = Standard Atomic Weight
    // ICE  = Isotopic Composition of the Element
    // NAW  = Nuclide Atomic Weight
    // U    = Uncertainty

int main(void){


    printf("%s\n", "########## CIAAW VERSION ##########");
    printf("version %s\n", ciaaw_get_version());
    
    printf("%s\n", "########## CIAAW SAW ##########");
    printf("%s %10.5f\n", "ASAW H   = ", ciaaw_get_saw("H", 1, true, false));
    printf("%s %10.5f\n", "U ASAW H = ", ciaaw_get_saw("H", 1, true, true));
    printf("%s %10.5f\n", "SAW H    = ", ciaaw_get_saw("H", 1, false, false));
    printf("%s %10.5f\n", "U SAW H  = ", ciaaw_get_saw("H", 1, false, true));
    printf("%s %10.5f\n", "ASAW Tc  = ", ciaaw_get_saw("Tc", 2, true, false));

    printf("%s\n", "########## CIAAW ICE ##########");
    printf("%s %d\n",     "N ICE H      = ", ciaaw_get_nice("H", 1));
    printf("%s %12.6f\n", "ICE H 1      = ", ciaaw_get_ice("H", 1, 1, false)); 
    printf("%s %23.16e\n","U ICE H 1    = ", ciaaw_get_ice("H", 1, 1, true)); 
    printf("%s %12.6f\n", "ICE H 2      = ", ciaaw_get_ice("H", 1, 2, false)); 
    printf("%s %23.16e\n","U ICE H 2    = ", ciaaw_get_ice("H", 1, 2, true)); 
    printf("%s %d\n",     "N ICE Tc     = ", ciaaw_get_nice("Tc", 2));
    printf("%s %d\n",     "N ICE C      = ", ciaaw_get_nice("C", 1));

    printf("%s\n", "########## CIAAW NAW ##########");
    printf("%s %23.16f\n", "NAW H 2      = ", ciaaw_get_naw("H", 1, 2, false)); 
    printf("%s %23.16e\n", "U NAW H 2    = ", ciaaw_get_naw("H", 1, 2, true)); 
    printf("%s %d\n",      "N NAW Tc     = ", ciaaw_get_nnaw("Tc", 2));

    return EXIT_SUCCESS;
    }
