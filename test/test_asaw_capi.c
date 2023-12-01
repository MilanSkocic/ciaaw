#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ciaaw.h"
#include "common.h"

void test_asaw(void){

    const int N = 2;
    int i;
    double value;
    double expected[N];
    double diff;

    struct ciaaw_saw_capi_element_t elements[N];
    
    printf("    %s", "ASAW...");
    
    expected[0] = 1.0080;
    expected[1] = 12.011;

    elements[0] = ciaaw_saw_capi_H;
    elements[1] = ciaaw_saw_capi_C;
    

    for(i=0; i<N; i++){
        value = elements[i].asaw;
        diff = value -expected[i];
        diff = roundn(diff, 16);
        if(!assertEqual(diff, 0.0, 16)){
            printf("%s\n", "Failed");
            printf("    %s    %+23.16f/%+23.16f/%+23.16f\n", elements[i].symbol, value, expected[i], diff);
            exit(1);
        }
    }
    printf("%s\n", "OK");

}

int main(){

    printf("%s\n", "***** TESTING C API CODE FOR ASAW *****");

    test_asaw();
    EXIT_SUCCESS;
}
