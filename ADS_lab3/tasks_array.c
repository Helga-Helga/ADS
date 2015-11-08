#include <string.h>
#include "tasks_array.h"
#include "utils.h"

size_t countWordsArray(T* array) {
	size_t size = 0;
	size_t i = 0;
	if (!array) {
		return size;
	}
	while (i++ < strlen(array)) {
		if (isWordEnd(array[i]) && !isWordEnd(array[i-1])) {
			size++;
		}
	}
	return size;
}

size_t wordlen(T* word) {
	if (!word) {
		return 0;
	}
	size_t i = 0;
	while (!isWordEnd(word[i++]));
	return i-1;
}

int cmpWithFirstWord(T* firstWord, T* word) {
	size_t i = 0, j = 0;
	if (!word) {
		return 0;
	}
	if (wordlen(firstWord) != wordlen(word)) {
		return 0;
	}
	if (word[i] != firstWord[j]) {
		return 0;
	}
	while (!isWordEnd(word[++i]) && !isWordEnd(firstWord[++j])) {
		if (word[i] != firstWord[j]) {
			return 0;
		}
	}
	return 1;
}

T* findNextWord(T* text) {
	if (!text || !*text) {
		return NULL;
	}
	while(!isWordEnd(*(text++)));
	if (!*(text-1)) {
		return NULL;
	}
	while(isWordEnd(*(text))) {
		if (!*text) {
			return NULL;
		}
		text++;
	}
	return text;
}

T* findFirstWord(T* text) {
	if (!text || !*text) {
		return NULL;
	}
	if (!isWordEnd(*text)) {
		return text;
	}
	else {
		return findNextWord(text);
	}
}

T* wordProcessingArray(T* source, T* destination, size_t len) {
	if (!source || !*source || len < 2) {
		return destination;
	}
	if (len&1) {
		while(!isWordEnd(source[1])) {
			*(destination++) = *(source++);
		}
	}
	else{
		*(destination++) = *(source);
		while(!isWordEnd(*source)) {
			*(destination++) = *(source++);
		}
	}
	return destination;
}

size_t dstlen(size_t srclen) {
	return (srclen*4)/3 + 1;
}

T* arrayProcessing(T* array) {
	if (!array || !*array || countWordsArray(array) < 2) {
		return NULL;
	}
	T* dst = (T*)malloc(dstlen(strlen(array)+1)*sizeof(T));
	T* dstEnd = dst;
	*dstEnd = 0;
	T* firstWord = findFirstWord(array);
	T* curr = findNextWord(firstWord);
	while(curr) {
		if (cmpWithFirstWord(firstWord, curr)) {
			curr = findNextWord(curr);
			continue;
		}
		else {
			if (dstEnd != dst && *dstEnd != ' ') {
				*(dstEnd++) = ' ';
			}
			dstEnd = wordProcessingArray(curr, dstEnd, wordlen(curr));
			if (dstEnd != dst && *(dstEnd-1) == ' ') {
				dstEnd--;
			}
			*dstEnd = 0;
		}
		curr = findNextWord(curr);
	}
	dstEnd--;
	if (*dstEnd == ' ') {
		*dstEnd = 0;
	}
	return (T*)realloc(dst, (strlen(dst)+1)*sizeof(T));
}
