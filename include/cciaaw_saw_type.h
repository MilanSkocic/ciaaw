#ifndef CCIAAW_SAW_TYPE_H
#define CCIAAW_SAW_TYPE_H

struct cciaaw_saw_type{
    char element[25]; 
    char symbol[9]; 
    int z; 
    double saw_min; 
    double saw_max; 
    double saw; 
    double saw_u;
    double asaw; 
    double asaw_u; 
    char footnotes[9];
};

#endif
