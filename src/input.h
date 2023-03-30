/**
 * \file input.h
 * \version 1.0 First
 * \author Vernhes Yohann <yohann.vernhes@gmail.com>
 * \date 31 March 2023 
 * \brief TP9 : Minesweeper.
 * Input module header file.
 */
#ifndef INPUT_H
#define INPUT_H

/**
 * \fn int getPipeInput(char **)
 * \author Vernhes Yohann <yohann.vernhes@gmail.com>
 * \version 1.0 First
 * \date 31 March 2023 
 * \brief get string user input.
 * Read input from stdin return the input size
 * allocate the input string buffer.
 */
int getPipeInput(char **input);

unsigned int len(const char *word);

char *substring(char *string, int startIndex, int endIndex);

int indexOfFromIndex(const char *string, int startIndex, const char search);
int lastIndexOf(const char *string, const char search);
int indexOf(const char *string, const char search);

/**
 * \fn clrInputBuffer()
 * \author Vernhes Yohann <yohann.vernhes@gmail.com>
 * \version 1.0 First
 * \date 31 March 2023 
 * \brief Clear input buffer by reading it until the end.
 * we should use fseek, rewind or reopen stdin, but ...
 */
void clrInputBuffer(void);

/**
 * \fn scanUserInteger(int*, char, int, char, int, const char*)
 * \author Vernhes Yohann <yohann.vernhes@gmail.com>
 * \version 1.0 First
 * \date 31 March 2023 
 * \brief Get integer input from stdin.
 * \param *input : output integer taken from user.
 * \param isMin : 0 means ignore minValue, else use minValue.
 * \param minValue : minimum valide value.
 * \param isMax : 0 means ignore maxValue, else use maxValue.
 * \param maxValue : maximum valide value.
 * \param *tryAgainMsg : message shown in case of incorrect input.
 */
void scanUserInteger(int* input, char isMin, int minValue, char isMax, int maxValue, const char* tryAgainMsg);

/**
 * \fn scanIntegerInRange(int*, int, int, const char*)
 * \author Vernhes Yohann <yohann.vernhes@gmail.com>
 * \version 1.0 First
 * \date 31 March 2023 
 * \brief Get integer input from stdin.
 * Ouputed integer is between minValue and MaxValue.
 * Simplify the usage of scanUserInteger(int*, char, int, char, int, const char*).
 * \param *input : output integer taken from user.
 * \param minValue : minimum valide value.
 * \param maxValue : maximum valide value.
 * \param *tryAgainMsg : message shown in case of incorrect input.
 */
void scanIntegerInRange(int* input, int minValue, int maxValue, const char* tryAgainMsg);

/**
 * \fn scanIntegerGreatherThan(int*, int, const char*)
 * \author Vernhes Yohann <yohann.vernhes@gmail.com>
 * \version 1.0 First
 * \date 31 March 2023 
 * \brief Get integer input from stdin.
 * Ouputed integer greather than minValue.
 * Simplify the usage of scanUserInteger(int*, char, int, char, int, const char*).
 * \param *input : output integer taken from user.
 * \param minValue : minimum valide value.
 * \param *tryAgainMsg : message shown in case of incorrect input.
 */
void scanIntegerGreatherThan(int* input, int minValue, const char* tryAgainMsg);

/**
 * \fn scanIntegerLowerThan(int*, int, const char*)
 * \author Vernhes Yohann <yohann.vernhes@gmail.com>
 * \version 1.0 First
 * \date 31 March 2023 
 * \brief Get integer input from stdin.
 * Ouputed integer lower than maxValue.
 * Simplify the usage of scanUserInteger(int*, char, int, char, int, const char*).
 * \param *input : output integer taken from user.
 * \param maxValue : maximum valide value.
 * \param *tryAgainMsg : message shown in case of incorrect input.
 */
void scanIntegerLowerThan(int* input, int maxValue, const char* tryAgainMsg);

/**
 * \fn scanInteger(int*, const char*)
 * \author Vernhes Yohann <yohann.vernhes@gmail.com>
 * \version 1.0 First
 * \date 31 March 2023 
 * \brief Get integer input from stdin.
 * Simplify the usage of scanUserInteger(int*, char, int, char, int, const char*).
 * \param *input : output integer taken from user.
 * \param *tryAgainMsg : message shown in case of incorrect input.
 */
void scanInteger(int* input, const char* tryAgainMsg);

/**
 * \fn void scanUserAction(char* action, const char* tryAgainMsg)
 * \author Vernhes Yohann <yohann.vernhes@gmail.com>
 * \version 1.0 First
 * \date 31 March 2023 
 * \brief Get char value from user value D or F.
 * \param *action : output action taken from user.
 * \param *tryAgainMsg : message shown in case of incorrect input.
 */
void scanUserAction(char* action, const char* tryAgainMsg);


#endif /*INPUT_H*/