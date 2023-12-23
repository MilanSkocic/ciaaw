#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ciaaw.h"
#include "common.h"

void test_version_number(void){


    char expected[6] = "0.1.0";
    char value[6] = "12345";
    int i;
    for(i=0; i<strlen(value); i++){
        value[i] = ciaaw_version_capi_version[i];
    }

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
