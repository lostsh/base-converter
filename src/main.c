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
void convertToBaseTen(char *input){
    /* input form (numbers)base*/
    int number;
    int base;
    sscanf(input, "(%d)%d", &number, &base);
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
/* For input base > 9 */
void convertBigBaseToBaseTen(char *input){
    int base = 0;
    int number = 0;
    
    int cursor = len(input)-1;
    //int isReadingNumber = 0; //tell if you are reading the actual number of the base
    while (cursor >= 0){
        char c = *(input+cursor);
        printf("current char is: [%c]\n", c);

        // get the number base : 
        if((cursor-1 >= 0 && *(input+(cursor-1)) == ' ') || cursor==0 ){
            char *val;
            // first number on the right is the base
            if(indexOfFromIndex(input, cursor+1, ' ') == -1){
                val = substring(input, cursor, len(input));
                //printf("\t\t\t\t\t\t\t BASE IS : %s\n", val);
                sscanf(val, "%d", &base);
                //printf("Base : %d\n", base);
            }else{
                //get the numbers
                val = substring(input, cursor, indexOfFromIndex(input, cursor+1, ' '));
                int currentNumber = 0;
                //printf("\t\t\t\t\t\t\t VAL IS : %s\n", val);
                sscanf(val, "%d", &currentNumber);
                //printf("Current Number: %d\n", currentNumber);
            }
            free(val);
        }

        // get the numbers


        /*
        if( (c == '(' || c == ')')) isReadingNumber = !isReadingNumber;
        printf("Is actually reading the inside of the brackets: %s, (value: %d)\n", (isReadingNumber?"yes":"no"), isReadingNumber);


        if(isReadingNumber){
            printf("Read the content\n");
            // convert the number
            if(cursor-1 > 0 && (*(input+(cursor-1)) == ' ')){
                printf("Get a number value\n");
                char *val = substring(input, cursor, indexOfFromIndex(input, cursor+1, ' '));
                printf("\t\t\t\t\t\t\t VAL IS : %s\n", val);
                int number;
                sscanf(val, "%d", &number);
                printf("Valeur : %d\n", number);
                free(val);
            }
        }else if(cursor-1 > 0 && *(input+(cursor-1)) == ' '){
            // read the base of the number
            printf("reading the base is finished : cursor : %d max %d\n", cursor, len(input));
            char baseStr[4] = ""; //max base size : 999 (512)
            for(int i=cursor; i<len(input); i++){
                //printf("chiffre courant de la base: %c\n", *(input+i));
                baseStr[(i-cursor)] = *(input+i);
            }
            baseStr[3] = '\0';
            //printf("Base is: %s\n", baseStr);
            // convert base value to integer
            sscanf(baseStr, "%d", &base);
            printf("La base est donc : %d\n", base);
        }*/

        cursor--;
    }
    

    //convert the inputed number to decimal base
    /*
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
    printf("Value: (%.2f)10\n", convertedValue);*/
    printf("Valeur : %d\n", number);
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
    printf("\033[0;104m[ * ]\t%sInput form: ([valueToConvert])[base]\n\texample: (0101)2 => (5)10\n", COLOR_RST);

    char *in;
    //int size = getPipeInput(&in);
    //printf("[%s] => %d\n", in, size);
    getPipeInput(&in);

    /*
    char *sub;
    sub = substring(in, 1, 4);
    printf("substring : %s\n", sub);
    free(sub);
    sub = NULL;
    printf("First index of space in input is: %d\n", indexOf(in, ' '));*/

    //convertToBaseTen(in);
    convertBigBaseToBaseTen(in);
    //for(int i=0; i<12; i++) printf("\t%d^%d=%.2f\n", 2, i, power(2, i));

    free(in);
    in = NULL;

    //printf("\t%d^%d=%.2f\n", 2, 2, power(2, 2));
    //printf("\t%d^%d=%.2f\n", 2, -1, power(2, -1));

    // Exit success
    return (EXIT_SUCCESS);
}