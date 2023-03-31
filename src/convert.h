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

double power(int number, int exponent);

double convertSmallBaseToBaseTen(char *input, int base);

double convertBigBaseToBaseTen(char *input, int base);

double hexToBaseTen(char *input);

int getInputedBase(char *input);

char *convertDecimalToAnyBase(double decimal, int base);

char *convertDecimalToHex(double decimal);

#endif /* CONVERT_H */
