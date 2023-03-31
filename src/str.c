/**
 * \file str.c
 * \version 1.0 First
 * \author Vernhes Yohann <yohann.vernhes@gmail.com>
 * \date 31 March 2023 
 * \brief Base converter.
 * String module.
 * First version is scrappy.
 */

#include <stdlib.h>
#include "str.h"

/* Get the size of the input. 
 * do not count the last \0 char
 */
unsigned int len(const char *word){
    unsigned int size = 0;
    while('\0' != *(word+size)) size++;
    return size;
}

/* Extract a substring
 * From startIndex (included)
 * to endIndex (excluded)
 * allocate char array of size+1 with \0 at the end
 */
char *substring(char *string, int startIndex, int endIndex){
  int size = endIndex-startIndex;
  char *substr = malloc((size+1)*sizeof(char));
  for(int i=startIndex; i<endIndex; i++){
    *(substr+(i-startIndex)) = *(string+i);
  }
  *(substr+size) = '\0';
  return substr;
}

/* Get the first occurence of search in string
 * start searching from startIndex to the end
 */
int indexOfFromIndex(const char *string, int startIndex, const char search){
  int index = startIndex;
  while (*(string+index) != '\0' && *(string+index) != search) index++;
  return (*(string+index)==search)?index:-1;
}

/* Get the last occurence of search in string
 * search backward from the end to the beginning
 */
int lastIndexOf(const char *string, const char search){
  int index = len(string);
  while(index >= 0 && *(string+index) != search) index--;
  return (*(string+index) == search)?index:-1;
}

/* Get the first occurence of search in string
 * start searching from 0 index
 */
int indexOf(const char *string, const char search){
 return indexOfFromIndex(string, 0, search);
}