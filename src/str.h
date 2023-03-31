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

/**
 * \fn unsigned int len(const char*)
 * \author Vernhes Yohann <yohann.vernhes@gmail.com>
 * \version 1.0 First
 * \date 31 March 2023 
 * \brief Get word length.
 * Return the length of the word
 * the terminated char does not count.
 * (Exclude \0 char)
 */
unsigned int len(const char *word);

/**
 * \fn char *substring(char*, int, int)
 * \author Vernhes Yohann <yohann.vernhes@gmail.com>
 * \version 1.0 First
 * \date 31 March 2023 
 * \brief Return substring.
 * Return substring from start (included)
 * to end (excluded).
 */
char *substring(char *string, int startIndex, int endIndex);

/**
 * \fn int indexOfFromIndex(const char*, int, const char)
 * \author Vernhes Yohann <yohann.vernhes@gmail.com>
 * \version 1.0 First
 * \date 31 March 2023 
 * \brief Get index of search from start.
 * Return first position of search char
 * start searching from the start index.
 */
int indexOfFromIndex(const char *string, int startIndex, const char search);

/**
 * \fn int indexOf(const char*, const char)
 * \author Vernhes Yohann <yohann.vernhes@gmail.com>
 * \version 1.0 First
 * \date 31 March 2023 
 * \brief Get first index of searched char.
 * Return first position of search char.
 */
int indexOf(const char *string, const char search);

/**
 * \fn int lastIndexOf(const char*, const char)
 * \author Vernhes Yohann <yohann.vernhes@gmail.com>
 * \version 1.0 First
 * \date 31 March 2023 
 * \brief Get last index of searched char.
 * Return last index of searched char
 * iterate over the string in reverse order
 * from the end to the start.
 */
int lastIndexOf(const char *string, const char search);

#endif /* STR_H */
