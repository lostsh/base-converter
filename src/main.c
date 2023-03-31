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
#include "str.h"

#define COLOR_RED "\033[0;91m"
#define COLOR_BLU "\033[0;94m"
#define COLOR_BRED "\033[1;91m"
#define COLOR_BBLU "\033[1;94m"
#define COLOR_RST "\033[0m"


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

    /* Actual operation mode input
     * get the operation mode from
     * command line arguments
    */

    if(argc < 2){
        fprintf(stderr, "\033[0;101m[ ! ]%s\tError: missing arg\n", COLOR_RST);
        fprintf(stdout, "\033[0;103m[ - ]%s\tUsage:  %s --from-decimal-to-any | -d\n", COLOR_RST, *argv);
        fprintf(stdout, "\033[0;103m[ - ]%s\t\t%s --from-any-to-decimal | -a\n", COLOR_RST, *argv);
        return(EXIT_FAILURE);
    }

    int operatingMode = -1;
    //check for short input
    if(len(argv[1]) == 2 && *(*(argv+1)) == '-' ){
        if( *(*(argv+1)+1) == 'd' ){
            operatingMode = 0;
        }else if( *(*(argv+1)+1) == 'a' ){
            operatingMode = 1;
        }else{
            fprintf(stderr, "\033[0;101m[ ! ]%s\tError: arg format exception\n", COLOR_RST);
            printf("\033[0;103m[ - ]%s\tUsage:  %s --from-decimal-to-any | -d\n", COLOR_RST, *argv);
            printf("\033[0;103m[ - ]%s\t\t%s --from-any-to-decimal | -a\n", COLOR_RST, *argv);
            return (EXIT_FAILURE);
        }
    }else{
        // full in put mode
        char *firstOption = "--from-decimal-to-any";
        char *secondOption = "--from-any-to-decimal";
        int isValid = 1;
        char *c = argv[1];
        do
        {
            isValid = (*c == *firstOption || *c == *secondOption);
            if(*c == *firstOption)firstOption++;
            if(*c == *secondOption)secondOption++;
            c++;
        } while (*c != '\0' && *firstOption != '\0' && *secondOption != '\0' && isValid);

        // check the input validity
        isValid = (*firstOption == '\0' || *secondOption == '\0') && *c == '\0';

        // swtich operating mode depending on the input
        if(isValid){
            if(*firstOption == '\0') operatingMode = 0;
            else operatingMode = 1;
        }else{
            fprintf(stderr, "\033[0;101m[ ! ]%s\tError: arg format exception\n", COLOR_RST);
            printf("\033[0;103m[ - ]%s\tUsage:  %s --from-decimal-to-any | -d\n", COLOR_RST, *argv);
            printf("\033[0;103m[ - ]%s\t\t%s --from-any-to-decimal | -a\n", COLOR_RST, *argv);
            return (EXIT_FAILURE);
        }
    }

    printf("\033[0;105m[ = ]%s\t", COLOR_RST);
    printf("Actually convert from %s.\n", (!operatingMode)?"decimal to any":"any to decimal");
    
    // enable below line only if remove pipe input support
    //printf("\033[0;107m[ > ]%s\t", COLOR_RST);

    /* Actual converting system
     * operatingMode 0 : convert from decimal to any base
     * operatingMode 1 : convert from any base to decimal
    */
    
    char *in;
    getPipeInput(&in);

    // parse input
    int base = getInputedBase(in);
    char *inputNumber = substring(in, 0, lastIndexOf(in, ' ')+1);

    free(in);
    in = NULL;
    
    // Compute conversion from anybase to decimal
    if(operatingMode){
        double decimalValue = 0;
        if(base < 9){
            //extract small base
            decimalValue = convertSmallBaseToBaseTen(inputNumber, base);
        }else if(base == 16){
            // extract from base 16
            decimalValue = hexToBaseTen(inputNumber);
        }else{
            //extract from big base
            decimalValue = convertBigBaseToBaseTen(inputNumber, base);
        }

        printf("\033[0;105m[ = ]%s\t", COLOR_RST);
        printf("%.2f(10)\n", decimalValue);
    }else{
        //compute convertion from decimal to any base
        char *value;
        if(base == 16){
            value = convertDecimalToHex(atof(inputNumber));
        }else{
            value = convertDecimalToAnyBase(atof(inputNumber), base);
        }

        printf("\033[0;105m[ = ]%s\t", COLOR_RST);
        printf("%s(%d)\n", value, base);
        free(value);
    }

    free(inputNumber);
    inputNumber = NULL;

    return (EXIT_SUCCESS);
}