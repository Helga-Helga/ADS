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
