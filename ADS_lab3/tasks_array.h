#ifndef TASKS_ARRAY_H
#define TASKS_ARRAY_H

#include "element.h"

size_t countWordsArray(T*);
size_t wordlen(T*);
int cmpWithFirstWord(T*, T*);
T* findNextWord(T*);
T* findFirstWord(T*);
T* wordProcessingArray(T*, T*, size_t);
size_t dstlen(size_t);
T* arrayProcessing(T*);
T* deleteEverySecondWord(T*);

#endif
