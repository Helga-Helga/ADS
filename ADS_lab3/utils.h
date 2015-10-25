#ifndef UTILS_H
#define	UTILS_H

#include "element.h"

struct Element* arrayToList(T*, size_t);
T* listToArray(struct Element*);
struct Element** split(struct Element*, T);
int comparison(struct Element*, struct Element*);

#endif	/* UTILS_H */
