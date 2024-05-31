#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ciaaw.h"


int main(void){

    struct ciaaw_saw_element_t elmt;

    printf("%s\n", "########## CIAAW VERSION ##########");
    printf("version %s\n", ciaaw_get_version());
    
    printf("%s\n", "########## CIAAW SAW ##########");
    elmt = ciaaw_saw_H;
    printf("%s %s\n", "Element: ", elmt.element);
    printf("%s %s\n", "Symbol: ", elmt.symbol);
    printf("%s %d\n", "Z: ", elmt.z);
    printf("%s %23.16f\n", "standard atomic weight max: ", elmt.saw_max);
    printf("%s %23.16f\n", "standard atomic weight min: ", elmt.saw_min);
    printf("%s %23.16f\n", "standard atomic weight: ", elmt.saw);
    printf("%s %23.16f\n", "standard atomic weight uncertainty: ", elmt.saw_u);
    printf("%s %23.16f\n", "abredged standard atomic weight: ", elmt.asaw);
    printf("%s %23.16f\n", "abredged standard atomic weight uncertainty: ", elmt.asaw_u);
    printf("%s\n", "");

    elmt = ciaaw_saw_F;
    printf("%s %s\n", "Element: ", elmt.element);
    printf("%s %s\n", "Symbol: ", elmt.symbol);
    printf("%s %d", "Z: ", elmt.z);
    printf("%s %23.16f\n", "standard atomic weight max: ", elmt.saw_max);
    printf("%s %23.16f\n", "standard atomic weight min: ", elmt.saw_min);
    printf("%s %23.16f\n", "standard atomic weight: ", elmt.saw);
    printf("%s %23.16f\n", "standard atomic weight uncertainty: ", elmt.saw_u);
    printf("%s %23.16f\n", "abredged standard atomic weight: ", elmt.asaw);
    printf("%s %23.16f\n", "abredged standard atomic weight uncertainty: ", elmt.asaw_u);

    return EXIT_SUCCESS;
}
