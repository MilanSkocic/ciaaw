#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include "ciaaw.h"
#include "codata.h"

#define VERSION_SIZE 256

#define ERR_MSG_SIZE          256
#define ERR_INCORRECT_ELEMENT -1
#define ERR_NO_SAW            -2
#define ERR_BRACKETS_MISMATCH -3
#define ERR_NOT_ALPHANUM      -4

struct option_t {char *s; char *l; char *arg; char *help;};

//----------------------------------------------------------------------
// FUNCTION: VERSION_TEXT()
//----------------------------------------------------------------------
//{{{
static void version_text(){
    char v[VERSION_SIZE];
    strcpy(v, "ciaaw ");
    strcat(v, ciaaw_version());
    strcat(v, "\n\n");
    strcat(v, "Copyright (c) 2022 Milan Skocic\n");
    strcat(v, "License MIT\n");
    strcat(v, "\n");
    strcat(v, "Written by Milan Skocic\n");
    printf("%s", v);
}
//}}}

//----------------------------------------------------------------------
// FUNCTION: USAGE_TEXT()
//----------------------------------------------------------------------
//{{{
static void usage_text(){
    printf("%s\n", "ciaaw [-s|--saw] [-i|--ice] [-n|--naw] [-m|--mu] [-c|--colnames] [-M|--molarmass SPECIES]");
    printf("%s\n", "      [-u|--usage] [-v|--version] [-h|--help] ELEMENT...");
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
printf("%s\n", "ciaaw - atomic weights, isotopic compositions and nuclides' atomic weights.");
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

//----------------------------------------------------------------------
// FUNCTION: _MM()
//----------------------------------------------------------------------
//{{{
double _mm(char **s, char *end, int *ierr, char *errmsg){
    
    char terminator;
    int n, i;
    double m, m2, C, M;
    char *eptr;
    char *cptr;
    char *etok;
    char *ctok;
    bool felmt, fcoef;
    
    char *buf = (char *)malloc(256);
    char *e = (char *)malloc(sizeof(char)*strlen(*s)*3);
    char *c = (char *)malloc(sizeof(char)*strlen(*s)*3);
    if (e == NULL || c == NULL || buf == NULL) {
        free(e); free(c); free(buf);
        return -1.0;
    }
    buf[0] = '\0';
    e[0] = '\0';
    c[0] = '\0';

    m = 0.0;
    felmt = false;
    fcoef = false;
    
    terminator = '\0';
    if(end != NULL){ terminator = *end;}
    
    while((**s) != terminator && (**s)!='\0'){
        felmt = false;
        fcoef = false;
        if(**s==' '){(*s)++;continue;}
        if(isupper(**s)){
            felmt = true;
            n = strlen(e);
            e[n] = **s;
            e[n+1] = '\0';
            (*s)++;
            while(islower(**s)){
                n = strlen(e);
                e[n] = **s;
                e[n+1] = '\0';
                (*s)++;
            }
            n = strlen(e);
            e[n] = ' ';
            e[n+1] = '\0';
        }

        if(isdigit(**s)){
            fcoef = true;
            n = strlen(c);
            c[n] = **s;
            c[n+1] = '\0';
            (*s)++;
            while(isdigit(**s)){
                n = strlen(c);
                c[n] = **s;
                c[n+1] = '\0';
                (*s)++;
            }
            n = strlen(c);
            c[n] = ' ';
            c[n+1] = '\0';
        }
        // check for implicit coefficients e.g. KCl, H2O
        if((felmt==true) && (fcoef==false)){
            n = strlen(c);
            c[n] = '1';
            c[n+1] = ' ';
            c[n+2] = '\0';
        }
        if(**s=='('){
            (*s)++;
            m2=_mm(s,")", ierr, errmsg);
            i = 0;
            while(isdigit(**s) && i<255){
                buf[i] = **s;
                i++;
                (*s)++;
            }
            buf[i]='\0';
            if(strlen(buf)>0){
                m2*=atof(buf);
            }
            m += m2;
            continue;
        }
        if(felmt==false && fcoef==false){ (*s)++; }
    }
    if (**s == terminator && terminator != '\0') {
        (*s)++;
    }
    etok = strtok_r(e, " ", &eptr);
    ctok = strtok_r(c, " ", &cptr);
    while((etok!=NULL) && (ctok!=NULL)){
        M = ciaaw_saw(etok, strlen(etok), false, false);
        if(M==-1.0){
            *ierr = -2;
            snprintf(errmsg, ERR_MSG_SIZE, "%s does not have a SAW.", etok);
        }
        if(isnan(M)){
            *ierr = -1;
            snprintf(errmsg, ERR_MSG_SIZE, "%s is not a valid element.", etok);
        }
        C = atof(ctok);
        m += C*M;
        etok = strtok_r(NULL, " ", &eptr);
        ctok = strtok_r(NULL, " ", &cptr);
    }

    free(e);
    free(c);
    free(buf);

    return m;
}
//}}}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
// FUNCTION: MM()
//----------------------------------------------------------------------
//{{{
double mm(char *s, int *ierr, char *errmsg){
    
    int lb, rb;
    double m;
    char *s2,*_s2;

    *ierr = 0;
    lb = rb = 0;
    m = NAN;
    s2 = (char *)malloc(sizeof(char)*strlen(s)+1);
    strcpy(s2,s);

    while(*s!='\0'){
        if(*s=='('){lb++;s++;continue;}
        if(*s==')'){rb++;s++;continue;}
        if(!isalnum(*s)){
            *ierr = ERR_NOT_ALPHANUM;
            snprintf(errmsg, ERR_MSG_SIZE, "%c is not alphanumeric character.", *s);
            free(s2);
            return m;
        }
        s++;
    }

    if(lb!=rb){
        *ierr = ERR_BRACKETS_MISMATCH;
        snprintf(errmsg, ERR_MSG_SIZE, "Incorrect number of brackets: %d/%d", lb, rb);
        free(s2);
        return m;
    }

    _s2 = s2;
    m = _mm(&s2, NULL, ierr, errmsg);
    
    free(_s2);

    return m;
}
//}}}
//----------------------------------------------------------------------


int main(int argc, char **argv){
    
    int i,j,k, iopt;
    char *s;

    bool fsaw, fice, fnaw, fheader, fspecies;
    double x, dx, cmu;
    
    int nice, nnaw;
    double *ice_values;
    double *naw_values;
    double mm_value;
    int z;

    int ierr;
    char errmsg[ERR_MSG_SIZE];
    
    ierr = 0;
    fsaw = false;
    fice = false;
    fnaw = false;
    fheader = false;
    fspecies = false;
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
    {"-M", "--molarmass", NULL,       "Compute the molar mass."},
    {"-u", "--usage",   NULL,        "Show usage text and exit."},
    {"-v", "--version", NULL,        "Show version information and exit."},
    {"-h", "--help",   NULL,        "Show help text and exit."},
    {NULL, NULL,        NULL,        NULL} };

    for(i=1;i<argc;i++){
        if (strcmp(argv[i], "--") == 0) {break;} // Stop translating options after the POSIX delimiter
        s = long2short(argv[i], loptions);
        if(s!=NULL){argv[i]=s;}
    }
    
    while ((iopt = getopt(argc, argv, "+:sinmcMuvh")) != -1) {
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
            case 'M':
                fspecies = true;
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

    
    if(!fsaw && !fice && !fnaw && !fspecies){
        print_periodic_table();
        return EXIT_SUCCESS;
    }
    
    if(fspecies){
        if(fheader){printf("%-16s%-16s\n", "Species", "M-g.mol-1");}
        for(k=optind;k<argc;k++){
            mm_value = mm(argv[k], &ierr, errmsg)*MOLAR_MASS_CONSTANT.value*1000;
            if(ierr<0){
                printf("[Error %d] - %s\n", ierr, errmsg);
            }else{
                printf("%-16s%-+16.6f\n", argv[k],mm_value);
            }
        }
        return EXIT_SUCCESS;
    }

    if(fsaw){
        if(fheader){printf("%-5s%-5s%-5s%-16s%-16s\n", "S", "Z", "A", "M", "dM");}
        for(k=optind;k<argc;k++){
            x = ciaaw_saw(argv[k], strlen(argv[k]), true, false); 
            dx = ciaaw_saw(argv[k], strlen(argv[k]), true, true); 
            z = ciaaw_s2z(argv[k], strlen(argv[k]));
            if(isnan(x)){
                printf("[Error %d] - %s is not a valid element.\n", ERR_INCORRECT_ELEMENT, argv[k]);
                return EXIT_SUCCESS;
            }
            if(x<0.0){
                printf("[Error %d] - %s does not have a SAW.\n", ERR_INCORRECT_ELEMENT, argv[k]);
                return EXIT_SUCCESS;
            }
            printf("%-5s%-5d%-5s%-16.6f%-16.6f\n", argv[k], z, "", x*cmu, dx*cmu);
        }
    }
    if(fice){
        if(fheader){printf("%-5s%-5s%-5s%-16s%-16s\n", "S", "Z", "A", "C", "dC");}
        for(k=optind;k<argc;k++){
            nice = ciaaw_nice(argv[k], strlen(argv[k]));
            ice_values = ciaaw_ices(argv[k], strlen(argv[k]));
            if(nice==-1){
                printf("%s is not a valid element.\n", argv[k]);
                return EXIT_SUCCESS;
            }
            if(nice==0){
                printf("%s does not have ICEs.\n", argv[k]);
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
    if(fnaw){
        if(fheader){printf("%-5s%-5s%-5s%-16s%-16s\n", "S", "Z", "A", "M", "dM");}
        for(k=optind;k<argc;k++){
            nnaw = ciaaw_nnaw(argv[k], strlen(argv[k]));
            naw_values = ciaaw_naws(argv[k], strlen(argv[k]));
            if(nnaw==-1){
                printf("%s is not a valid element.\n", argv[k]);
                return EXIT_SUCCESS;
            }
            if(nnaw==0){
                printf("%s does not have NAWs.\n", argv[k]);
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
