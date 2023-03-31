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
double convertSmallBaseToBaseTen(char *input, int base){
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
    //printf("Value: (%.2f)10\n", convertedValue);
    return convertedValue;
}

/* For input base > 9 
 * input must have no base inside number space seperated 
 * with a space at the end
 */
double convertBigBaseToBaseTen(char *input, int base){
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
    
    //printf("Value: (%.2f)10\n", convertedValue);
    return convertedValue;
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

char *convertDecimalToAnyBase(double decimal, int base){
    int *convertedNumberReversed = malloc(sizeof(int));
    int convertedNumberLength = 0;

    // convert the int part to bin
    int dividend = (int)decimal;
    while (dividend > 0){
        int reminder = dividend%base;
        int quotient = (dividend-reminder)/base;
        //printf("%d/%d=%d*%d+%d\n", dividend, base, base, quotient, reminder);
        dividend = quotient;
        //printf("Chiffre a noter (reste): %d (et le truc a re-diviser %d)\n", reminder, quotient);

        // add the current value to the stack
        convertedNumberReversed = realloc(convertedNumberReversed, (convertedNumberLength+1)*sizeof(int));
        *(convertedNumberReversed+convertedNumberLength) = reminder;
        convertedNumberLength++;
    }

    //for(int i=0; i<convertedNumberLength; i++) printf("%d ", convertedNumberReversed[i]);
    //printf("\n");

    //now reverse the array from msb to lsb in a string
    char *convertedValue = malloc(sizeof(char));
    int convertedSize = 1;
    *(convertedValue) = '\0';
    for(int i=convertedNumberLength-1; i>=0; i--){
        int num = convertedNumberReversed[i];
        int numSize = 1;
        while (num/(int)power(10, numSize) > 0) numSize++;
        char strReminder[numSize+1];
        sprintf(strReminder, "%d", num);

        // concat the current num with the reminder
        convertedSize = convertedSize+numSize+1;
        convertedValue = realloc(convertedValue, (convertedSize)*sizeof(char));
        sprintf(convertedValue+indexOf(convertedValue, '\0'), " %s", strReminder);
    }
    free(convertedNumberReversed);

    //printf("Final value [%s]\n", convertedValue);

    //free(convertedValue);
    return convertedValue;
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

    if(argc < 2){
        fprintf(stderr, "\033[0;101m[ ! ]%s\tError: missing arg\n", COLOR_RST);
        fprintf(stdout, "\033[0;103m[ - ]%s\tUsage:  %s --from-decimal-to-any\n", COLOR_RST, *argv);
        fprintf(stdout, "\033[0;103m[ - ]%s\t\t%s --from-any-to-decimal\n", COLOR_RST, *argv);
        return(EXIT_FAILURE);
    }

    //for (int i = 0; i < 9; i++)printf("\033[0;10%dm[ + ]\t%sColor test\n", i, COLOR_RST);
    
    
    char *in;
    getPipeInput(&in);

    // parse input
    int base = getInputedBase(in);
    char *inputNumber = substring(in, 0, lastIndexOf(in, ' ')+1);

    free(in);
    in = NULL;


    // Compute conversion from anybase to decimal
    double decimalValue = 0;
    if(base < 9){
        //extract small base
        decimalValue = convertSmallBaseToBaseTen(inputNumber, base);
    }else if(base == 16){
        // extract from base 16
    }else{
        //extract from big base
        decimalValue = convertBigBaseToBaseTen(inputNumber, base);
    }
    free(inputNumber);
    inputNumber = NULL;

    printf("\033[0;105m[ = ]%s\t", COLOR_RST);
    printf("%.2f(10)\n", decimalValue);


    /*
    char *outputValue;
    free(outputValue);
    outputValue = NULL;
    */

    

    /*
    convertDecimalToAnyBase(5.998, 2);
    printf("\n");
    convertDecimalToAnyBase(4, 2);
    printf("\n");
    convertDecimalToAnyBase(87987988, 209);
    printf("\n");
    convertDecimalToAnyBase(173, 16);
    printf("\n");
    convertBigBaseToBaseTen("10 13 ", 16);
    printf("\n");
    */

    // Exit success
    return (EXIT_SUCCESS);
}