/**
 * \file main.c
 * \version 1.0 First
 * \author Vernhes Yohann <yohann.vernhes@gmail.com>
 * \date 31 Mar 2023
 * \brief EXO1 : Base Converter.
 * Main file.
 */

/* Include standard lib */
#include <stdio.h>  // printf fprintf stderr (stdout)
#include <stdlib.h> // exit EXIT_CODE

#include "input.h"
#include "convert.h"

#define COLOR_RED "\033[0;91m"
#define COLOR_BLU "\033[0;94m"
#define COLOR_BRED "\033[1;91m"
#define COLOR_BBLU "\033[1;94m"
#define COLOR_RST "\033[0m"

void convert(char *input){
    /* input form (numbers)base*/
    int number;
    int base;
    sscanf(input, "(%d)%d", &number, &base);
    printf("\t[%s]:%d %d\n", input, number, base);

    //convert the inputed number to decimal base
    double convertedValue = 0;
    int currentExponent = 0;
    while(number > 0){
        printf("Current number %d, current exponent %d, current converted value %.2f", number, currentExponent, convertedValue);
        int currentUnitToConvert = number%10;
        printf(" current unit to convert: %d\n", currentUnitToConvert);

        //add the value to accu: value is u*base^weight
        convertedValue += currentUnitToConvert*power(base, currentExponent);
        // remaning number
        number = number/10;
        currentExponent++;
    }
    printf("Value: %.2f\n", convertedValue);
}

/**
 * \fn int main(int argc, char** argv)
 * \author Vernhes Yohann <yohann.vernhes@gmail.com>
 * \version 1.0 First
 * \date 31 Mar 2023
 * \brief .
 * \param argc : arguments count.
 * \param argv : arguments values.
 * \return Success 0 else error code.
 */
int main(int argc, char **argv){
    printf("\033[0;104m[ + ]\t%sWELLCOME TO THE %sBase %sCONVERTER%s\n", COLOR_RED, COLOR_BBLU, COLOR_RED, COLOR_RST);

    char *in;
    int size = getPipeInput(&in);
    printf("[%s] => %d\n", in, size);

    convert(in);
    //for(int i=0; i<12; i++) printf("\t%d^%d=%.2f\n", 2, i, power(2, i));

    free(in);
    in = NULL;

    //printf("\t%d^%d=%.2f\n", 2, 2, power(2, 2));
    //printf("\t%d^%d=%.2f\n", 2, -1, power(2, -1));

    // Exit success
    return (EXIT_SUCCESS);
}