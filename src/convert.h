/**
 * \file convert.h
 * \version 1.0 First
 * \author Vernhes Yohann <yohann.vernhes@gmail.com>
 * \date 31 March 2023
 * \brief Base converter.
 * Convert module header file.
 */
#ifndef CONVERT_H
#define CONVERT_H

/**
 * \fn double power(int, int)
 * \author Vernhes Yohann <yohann.vernhes@gmail.com>
 * \version 1.0 First
 * \date 31 March 2023 
 * \brief Get number at the power of exponent.
 * Negative exponent supported.
 */
double power(int number, int exponent);

/**
 * \fn int getInputedBase(char*)
 * \author Vernhes Yohann <yohann.vernhes@gmail.com>
 * \version 1.0 First
 * \date 31 March 2023
 * \brief Get the numerical base.
 * Cxtracts the number that is furthest 
 * from the end of the string.
 */
int getInputedBase(char *input);

/**
 * \fn double convertSmallBaseToBaseTen(char*, int)
 * \author Vernhes Yohann <yohann.vernhes@gmail.com>
 * \version 1.0 First
 * \date 31 March 2023 
 * \brief Convert a number to decimal base.
 * Convert the str number given from the given base
 * to its equivalent in the decimal base.
 * Given number must be in a base < 9
 * (but not hex).
 */
double convertSmallBaseToBaseTen(char *input, int base);

/**
 * \fn double convertBigBaseToBaseTen(char*, int)
 * \author Vernhes Yohann <yohann.vernhes@gmail.com>
 * \version 1.0 First
 * \date 31 March 2023 
 * \brief Convert a number to decimal base.
 * Convert the str number given from the given base
 * to its equivalent in the decimal base.
 * Given number must be in a base > 9 
 * (but not hex).
 */
double convertBigBaseToBaseTen(char *input, int base);

/**
 * \fn char *convertDecimalToAnyBase(double, int)
 * \author Vernhes Yohann <yohann.vernhes@gmail.com>
 * \version 1.0 First
 * \date 31 March 2023
 * \brief Convert decimal value to any base.
 * Convert the decimal number given to 
 * a number in the numerical base given.
 * (but not hex).
 */
char *convertDecimalToAnyBase(double decimal, int base);

/**
 * \fn double hexToBaseTen(char*)
 * \author Vernhes Yohann <yohann.vernhes@gmail.com>
 * \version 1.0 First
 * \date 31 March 2023 
 * \brief Convert an hex to decimal base.
 * Convert the str hex given to a 
 * decimal number.
 */
double hexToBaseTen(char *input);

/**
 * \fn char *convertDecimalToHex(double)
 * \author Vernhes Yohann <yohann.vernhes@gmail.com>
 * \version 1.0 First
 * \date 31 March 2023
 * \brief Convert decimal value to hex.
 * Convert decimal value to hex.
 */
char *convertDecimalToHex(double decimal);

#endif /* CONVERT_H */
