/**
* @file
* @brief C API - Derived type for Standard Atomic Weights
*/

#ifndef CIAAW_SAW_TYPE_H
#define CIAAW_SAW_TYPE_H

/** @brief C API - Structure representing an element.*/
struct ciaaw_saw_element_t{
    char element[25]; /**< Element name. */
    char symbol[9]; /**< Element symbol. */
    int z; /**< Element atomic number. */
    double saw_min; /**< Min standard atomic weight. */
    double saw_max; /**< Max standard atomic weight. */
    double saw; /**< Value standard atomic weight. */
    double saw_u; /**< Uncertainty standard atomic weight. */
    double asaw; /**< Abridged value standard atomic weight. */
    double asaw_u; /**< Abridged uncertainty standard atomic weight. */
};

#endif
