#ifndef UTILS_H
#define	UTILS_H

#include "element.h"

struct Element* arrayToList(T*, size_t);
T* listToArray(struct Element*);
struct Element** split(struct Element*, T);
int comparison(struct Element*, struct Element*);
int isWordEnd(T);
size_t countWords(struct Element*);
size_t countLetters(struct Element*);
struct Element* cutFirstWord(struct Element**);
struct Element* ltrim(struct Element*);
struct Element* rtrim(struct Element*);

#endif	/* UTILS_H */
