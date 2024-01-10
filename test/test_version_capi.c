#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ciaaw.h"
#include "common.h"

void test_version_number(void){


    char expected[6] = "0.1.0";
    char* value = ciaaw_get_version();

    printf("    %s", "VERSION...");
    
    if(strcmp(value, expected)!=0){
        printf("%s\n", "Failed");
        printf("    %s/%s\n", value, expected);
        exit(1);
    }
    printf("%s\n", "OK");

}

int main(){

    printf("%s\n", "***** TESTING C API CODE FOR VERSION *****");

    test_version_number();
    EXIT_SUCCESS;
}
