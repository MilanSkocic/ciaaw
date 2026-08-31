#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include "ciaaw.h"
#include "codata.h"

#define VERSION_SIZE 256
#define ARGS_SIZE 256
#define SAW_NARGS 5


struct option_t {char *s; char *l; char *arg; char *help;};

static void version_text(){
    char v[VERSION_SIZE];
    strcpy(v, "ciaaw ");
    strcat(v, ciaaw_version());
    strcat(v, "\n\n");
    strcat(v, "Copyright (c) 2022 Milan Skocic\n");
    strcat(v, "License MIT\n");
    strcat(v, "\n");
    strcat(v, "Wrtten by Milan Skocic\n");
    printf("%s", v);
}

//----------------------------------------------------------------------
// FUNCTION: USAGE_TEXT()
//----------------------------------------------------------------------
//{{{
static void usage_text(){
    printf("%s\n", "ciaaw [-s|--saw] [-i|--ice] [-n|--naw] [-m|-mu] [-c|colnames] [-u|--usage] [-v|--version] [-h|--help] ELEMENT...");
}
//}}}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
// FUNCTION: HELP_TEXT()
//----------------------------------------------------------------------
//{{{
static void help_text(struct option_t *options){
int i=0;
char buf[64];
printf("%s\n", "Usage: ciaaw [OPTION]... ELEMENT...");
printf("%s\n", "ciaaw - atomic weights, isotopic compositions and nuclide atomic weights.");
printf("%s\n", "");
while(options[i].s != NULL){
    buf[0] = '\0';
    strcat(buf, options[i].s);
    if(options[i].l != NULL){
        strcat(buf, ", ");
        strcat(buf, options[i].l);
    }
    if(options[i].arg != NULL){
        strcat(buf, " ");
        strcat(buf, options[i].arg);
    }
    printf("  %-24s", buf);
    printf("%-s\n", options[i].help);
    i++;
}
printf("%s\n", "");
}
//}}}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
// FUNCTION: LONG2SHORT()
//----------------------------------------------------------------------
//{{{
static char *long2short(char *option, struct option_t *options){
int i=0;
if(option==NULL){return NULL;}
if(strlen(option)<3){return option;}
if(!((option[0]=='-') && (option[1]=='-'))){return option;}

while(options[i].s!=NULL){
    if(strcmp(option, options[i].l)==0){return options[i].s;}
    else{i++;}
}
return option;
}
//}}}
//----------------------------------------------------------------------


int main(int argc, char **argv){
    
    int i,j,k, iopt;
    char *s;

    bool fsaw, fice, fnaw, fheader;
    double x, dx, cmu;
    
    int nice, nnaw;
    double *ice_values;
    double *naw_values;
    int z;

    fsaw = false;
    fice = false;
    fnaw = false;
    fheader = false;
    cmu = 1.0;
    nice = 0;
    nnaw = 0;
    z = 0;
    ice_values = NULL;
    naw_values = NULL;

    s = NULL;
    
    static struct option_t loptions[]={
    {"-s", "--saw",     NULL,        "Get the standard atomic weight."},
    {"-i", "--ice",     NULL,        "Get the isotopic composition."},
    {"-n", "--naw",     NULL,        "Get the nuclide atomic weight."},
    {"-m", "--mu",      NULL,        "Get the molar mass in g/mol."},
    {"-c", "--colnames",NULL,        "Show headers."},
    {"-u", "--usage",   NULL,        "Show usage text and exit."},
    {"-v", "--version", NULL,        "Show version information and exit."},
    {"-h", "--help ",   NULL,        "Show help text and exit."},
    {NULL, NULL,        NULL,        NULL} };

    for(i=1;i<argc;i++){
        s = long2short(argv[i], loptions);
        if(s!=NULL){argv[i]=s;}
    }
    
    while ((iopt = getopt(argc, argv, "+:sinmcuvh")) != -1) {
        switch (iopt) {
            case 's':
                fsaw = true;
                break;
            case 'i':
                fice = true;
                break;
            case 'n':
                fnaw = true;
                break;
            case 'm':
                cmu = MOLAR_MASS_CONSTANT.value*1000.0;
                break;
            case 'c':
                fheader = true;
                break;
            case 'v':
                version_text();
                return EXIT_SUCCESS;
            case 'u':
                usage_text();
                return EXIT_SUCCESS;
            case 'h':
                help_text(loptions);
                return EXIT_SUCCESS;
            case ':': 
                fprintf(stderr, "Option %c needs a value.\n", optopt); 
                return EXIT_SUCCESS;
            case '?': 
                fprintf(stderr, "Unknown option: %c\n", optopt);
                return EXIT_SUCCESS;
        }
    }

    if(optind == argc){
        print_periodic_table();
        return EXIT_SUCCESS;
    }

    if(fsaw == true){
        if(fheader==true){printf("%-5s%-5s%-5s%-16s%-16s\n", "S", "Z", "A", "M", "dM");}
        for(i=optind;i<argc;i++){
            x = ciaaw_saw(argv[i], strlen(argv[i]), true, false)*cmu; 
            dx = ciaaw_saw(argv[i], strlen(argv[i]), true, true)*cmu; 
            z = ciaaw_s2z(argv[i], strlen(argv[i]));
            printf("%-5s%-5d%-5s%-16.6f%-16.6f\n", argv[i], z, "", x, dx);
        }
    }
    if(fice == true){
        if(fheader==true){printf("%-5s%-5s%-5s%-16s%-16s\n", "S", "Z", "A", "C", "dC");}
        for(k=optind;k<argc;k++){
            nice = ciaaw_nice(argv[k], strlen(argv[k]));
            ice_values = ciaaw_ices(argv[k], strlen(argv[k]));
            if(nice==-1){
                printf("%s is not a valid element.\n", argv[k]);
                return EXIT_SUCCESS;
            }
            z = ciaaw_s2z(argv[k], strlen(argv[k]));
            for(i=0;i<nice;i++){
                printf("%-5s", argv[k]);
                printf("%-5d", z);
                for(j=0;j<3;j++){
                    x = *(ice_values+i+j*nice);
                    if(j==0){printf("%-5.0f", x);}
                    if(j==1){printf("%-16.8f", x);}
                    if(j==2){printf("%-16g", x);}
                }
                printf("\n");
            }
        }
    }
    if(fnaw == true){
        if(fheader==true){printf("%-5s%-5s%-5s%-16s%-16s\n", "S", "Z", "A", "M", "dM");}
        for(k=optind;k<argc;k++){
            nnaw = ciaaw_nnaw(argv[k], strlen(argv[k]));
            naw_values = ciaaw_naws(argv[k], strlen(argv[k]));
            if(nnaw==-1){
                printf("%s is not a valid element.\n", argv[k]);
                return EXIT_SUCCESS;
            }
            z = ciaaw_s2z(argv[k], strlen(argv[k]));
            for(i=0;i<nnaw;i++){
                printf("%-5s", argv[k]);
                printf("%-5d", z);
                for(j=0;j<3;j++){
                    x = *(naw_values+i+j*nnaw)*cmu;
                    if(j==0){printf("%-5.0f", x);}
                    if(j==1){printf("%-16.8f", x);}
                    if(j==2){printf("%-16g", x);}
                }
                printf("\n");
            }
        }
    }

    return EXIT_SUCCESS;
}
