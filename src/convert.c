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
#include "str.h"

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

/* For base between 0 and 9 :
 * Input form : (01011)2
 * For base bigger than 9 :
 * Input form : (23 2F D4)16
*/
double convertSmallBaseToBaseTen(char *input, int base){
    /* input form (numbers)base*/
    int number;
    sscanf(input, "%d", &number);

    //convert the inputed number to decimal base
    double convertedValue = 0;
    int currentExponent = 0;
    while(number > 0){
        int currentUnitToConvert = number%10;

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
    
    return convertedValue;
}

double hexToBaseTen(char *input){
    double convertedValue = 0;
    int currentExponent = 0;

    char *in = input+len(input)-2;
    char *chartoint = "0123456789ABCDEF";
    while (in != input-1){
        int val = indexOf(chartoint, *in);
        convertedValue+=val*power(16, currentExponent);
        currentExponent++;
        in--;
    }
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
        dividend = quotient;

        // add the current value to the stack
        convertedNumberReversed = realloc(convertedNumberReversed, (convertedNumberLength+1)*sizeof(int));
        *(convertedNumberReversed+convertedNumberLength) = reminder;
        convertedNumberLength++;
    }

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

    return convertedValue;
}

char *convertDecimalToHex(double decimal){
    char *hexValue = malloc(sizeof(char));
    *hexValue = '\0';
    int hexValueSize = 0;

    char *decitochar = "0123456789ABCDEF";
    int dividend = (int)decimal;
    while (dividend > 0){
        int reminder = dividend%16;
        int quotient = (dividend-reminder)/16;
        dividend = quotient;

        // add the current value to the char array
        hexValueSize++;
        hexValue = realloc(hexValue, (hexValueSize+1)*sizeof(char));
        *(hexValue+hexValueSize-1) = *(decitochar+reminder);
        *(hexValue+hexValueSize) = '\0';
    }

    // revert the order to have little Endian
    int size = len(hexValue)-1;
    for(int i=0; i<=size/2; i++){
        char temp = *(hexValue+i);
        *(hexValue+i) = *(hexValue+size-i);
        *(hexValue+size-i) = temp;
    }

    return hexValue;
}