#ifndef STR_H
#define STR_H

unsigned int len(const char *word);

char *substring(char *string, int startIndex, int endIndex);

int indexOfFromIndex(const char *string, int startIndex, const char search);

int lastIndexOf(const char *string, const char search);

int indexOf(const char *string, const char search);

#endif /* STR_H */
