/**
 * \file convert.c
 * \version 1.0 First
 * \author Vernhes Yohann <yohann.vernhes@gmail.com>
 * \date 31 March 2023 
 * \brief Base converter.
 * Convert module.
 */

#include <stdio.h>  // printf getchar
#include <stdlib.h> //alloc
#include "convert.h"

double power(int number, int exponent){
    double result = 1;

    // get the positive part of the exponent
    int postitiveExpo = (exponent<0)?exponent*(-1):exponent;
    
    for(int i=0; i<postitiveExpo; i++)
        result*=number;
    
    // if exp neg then compute neg pow
    if(exponent<0) result = 1/result;
    return result;
}
