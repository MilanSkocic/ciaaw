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
    
    int i, iopt;
    bool fsaw, fice, fnaw;
    double x, dx, cmu;

    fsaw = false;
    fice = false;
    fnaw = false;
    cmu = 1.0;

    char *elements[SAW_NARGS];
    for (i=0;i<SAW_NARGS;i++){
        elements[i] = (char *)malloc(sizeof(char)*4);
        elements[i] = "\0";
    }

    char *s=NULL;
    
    static struct option_t loptions[]={
    {"-s", "--saw",     NULL,        "Get the standard atomic weight."},
    {"-i", "--ice",     NULL,        "Get the isotopic composition."},
    {"-n", "--naw",     NULL,        "Get the nuclide atomic weight."},
    {"-m", "--mu",      NULL,        "Get the molar mass in g/mol."},
    {"-u", "--usage",   NULL,        "Show usage text and exit."},
    {"-v", "--version", NULL,        "Show version information and exit."},
    {"-h", "--help ",   NULL,        "Show help text and exit."},
    {NULL, NULL,        NULL,        NULL} };

    for(i=1;i<argc;i++){
        s = long2short(argv[i], loptions);
        if(s!=NULL){argv[i]=s;}
    }
    
    while ((iopt = getopt(argc, argv, "+:smuvh")) != -1) {
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
        for(i=optind;i<argc;i++){
            x = ciaaw_saw(argv[i], strlen(argv[i]), true, false)*cmu; 
            dx = ciaaw_saw(argv[i], strlen(argv[i]), true, true)*cmu; 
            printf("%-5s%-16.6f%-16.6f\n", argv[i], x, dx);
        }
        return EXIT_SUCCESS;
    }

    return EXIT_SUCCESS;
}
