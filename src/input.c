/**
 * \file input.c
 * \version 1.0 First
 * \author Vernhes Yohann <yohann.vernhes@gmail.com>
 * \date 31 March 2023 
 * \brief TP9 : Minesweeper.
 * Input module.
 */
#include <stdio.h>  // printf getchar
#include <stdlib.h> //alloc
#include "input.h"

/* Read input from stdin return the input size
 * allocate the input string buffer. */
int getPipeInput(char **input){
    *input = malloc(sizeof(char));
    (*input)[0] = '\0';
    short unsigned int input_size = 1;
    
    char c;
    do{
        c = getchar();

        *input = realloc((*input), (input_size+1)*sizeof(char));
        (*input)[input_size-1] = c;
        (*input)[input_size] = '\0';
        input_size++;
        
    }while(c != '\0' && c != '\n');
    input_size-=2;
    *input = realloc(*input, (input_size+1)*sizeof(char));
    (*input)[input_size] = '\0';

    return input_size;
}

/* Clear input buffer */
void clrInputBuffer(void){
    while (getchar() != '\n');
}

/* Get integer value in range minValue maxValue from the user */
void scanUserInteger(int* input, char isMin, int minValue, char isMax, int maxValue, const char* tryAgainMsg){
  int int_scRes;

  do{
    printf("%s", tryAgainMsg);
    int_scRes = scanf("%d", input);
    clrInputBuffer();
  }while (int_scRes != 1 || ((isMin && *input < minValue) || ( isMax && *input > maxValue)));
}

void scanIntegerInRange(int* input, int minValue, int maxValue, const char* tryAgainMsg){
    scanUserInteger(input, 1, minValue, 1, maxValue, tryAgainMsg);
}
void scanIntegerGreatherThan(int* input, int minValue, const char* tryAgainMsg){
    scanUserInteger(input, 1, minValue, 0, 0, tryAgainMsg);
}
void scanIntegerLowerThan(int* input, int maxValue, const char* tryAgainMsg){
    scanUserInteger(input, 0, 0, 1, maxValue, tryAgainMsg);
}
void scanInteger(int* input, const char* tryAgainMsg){
    scanUserInteger(input, 0, 0, 0, 0, tryAgainMsg);
}

/* Get char value from user value D or F */
void scanUserAction(char* action, const char* tryAgainMsg){
  int int_scRes;

  do{
    printf("%s", tryAgainMsg);
    int_scRes = scanf("%c", action);
    clrInputBuffer();
  }while (int_scRes != 1 || (*action != 'D' && *action != 'F'));
}