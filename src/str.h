/**
 * \file str.h
 * \version 1.0 First
 * \author Vernhes Yohann <yohann.vernhes@gmail.com>
 * \date 31 March 2023
 * \brief Base converter.
 * String module header file.
 */
#ifndef STR_H
#define STR_H

unsigned int len(const char *word);

char *substring(char *string, int startIndex, int endIndex);

int indexOfFromIndex(const char *string, int startIndex, const char search);

int lastIndexOf(const char *string, const char search);

int indexOf(const char *string, const char search);

#endif /* STR_H */
