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

/* For base between 0 and 9 :
 * Input form : (01011)2
 * For base bigger than 9 :
 * Input form : (23 2F D4)16
*/
void convertSmallBaseToBaseTen(char *input, int base){
    /* input form (numbers)base*/
    int number;
    sscanf(input, "%d", &number);
    //printf("\t[%s]:%d %d\n", input, number, base);

    //convert the inputed number to decimal base
    double convertedValue = 0;
    int currentExponent = 0;
    while(number > 0){
        //printf("Current number %d, current exponent %d, current converted value %.2f", number, currentExponent, convertedValue);
        int currentUnitToConvert = number%10;
        //printf(" current unit to convert: %d\n", currentUnitToConvert);

        //add the value to accu: value is u*base^weight
        convertedValue += currentUnitToConvert*power(base, currentExponent);
        // remaning number
        number = number/10;
        currentExponent++;
    }
    printf("Value: (%.2f)10\n", convertedValue);
}
/* For input base > 9 
 * input must have no base inside number space seperated 
 * with a space at the end
 */
void convertBigBaseToBaseTen(char *input, int base){
    double convertedValue = 0;
    
    int cursor = len(input)-1;
    int currentExponent = 0;
    while (cursor >= 0){
        // get the number base : 
        if((cursor-1 >= 0 && *(input+(cursor-1)) == ' ') || cursor==0 ){
            /*
             * the char at the end of a number is an \0 if its the LSB otherwithe a space
            */
            //char stopChar = currentExponent==0?'\0':' ';
            //printf("Let's substring the current number : from %d to %d\n", cursor, indexOfFromIndex(input, cursor+1, stopChar));
            //char *val = substring(input, cursor, indexOfFromIndex(input, cursor+1, stopChar));
            char *val = substring(input, cursor, indexOfFromIndex(input, cursor+1, ' '));
            int currentNumber = 0;
            sscanf(val, "%d", &currentNumber);

            // add the current num : convert to decimal value
            convertedValue += currentNumber * power(base, currentExponent);
            currentExponent++;

            free(val);
        }

        cursor--;
    }
    
    printf("Value: (%.2f)10\n", convertedValue);
}

/* the base is the first number of the right */
int getInputedBase(char *input){
    int base = -1;
    int lastSpaceIndex = lastIndexOf(input, ' ');
    if(lastSpaceIndex != -1){
        //return in put base
        char *val = substring(input, lastSpaceIndex+1, len(input));
        sscanf(val, "%d", &base);
        free(val);
    }
    return base;
}

void convertDecimalToAnyBase(double decimal, int base){
    int dividend = (int)decimal;
    while (dividend > 0){
        int reminder = dividend%base;
        int quotient = (dividend-reminder)/base;
        printf("%d/%d=%d*%d+%d\n", dividend, base, base, quotient, reminder);
        dividend = quotient;
        printf("Chiffre a noter (reste): %d (et le truc a re-diviser %d)\n", reminder, quotient);
    }
    
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
    //printf("\033[0;104m[ * ]\t%sInput form: ([valueToConvert])[base]\n\texample: (0101)2 => (5)10\n", COLOR_RST);
    
    char *in;
    getPipeInput(&in);

    int base = getInputedBase(in);
    char *inputNumber = substring(in, 0, lastIndexOf(in, ' ')+1);
    if(base < 9){
        //extract small base
        convertSmallBaseToBaseTen(inputNumber, base);
    }else if(base == 16){
        // extract from base 16
    }else{
        //extract from big base
        convertBigBaseToBaseTen(inputNumber, base);
    }
    free(inputNumber);
    inputNumber = NULL;

    free(in);
    in = NULL;

    convertDecimalToAnyBase(5.998, 2);
    printf("\n");

    // Exit success
    return (EXIT_SUCCESS);
}