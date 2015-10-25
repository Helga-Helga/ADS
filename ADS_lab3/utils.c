#include "utils.h"

struct Element* arrayToList(T* source, size_t size) {
	struct Element* elem = NULL;
	if (!source || !size) {
		return NULL;
	}
	while (size--) {
		elem = insertElement(elem, createElement(source[size]), 0);
	}
	return elem;
}

T* listToArray(struct Element* elem) {
	if (!elem) {
		return NULL;
	}
	T* array = (T*)malloc(sizeof(T)*listSize(elem));
	struct Element* curr = elem;
	size_t i = 0;
	while (curr) {
		array[i] = curr->data;
		curr = curr->next;
		i++;
	}
	return array;
}

int comparison(struct Element* elem1, struct Element* elem2) {
	do {
		if (!elem1 || !elem2) {
			return 0;
		}
		if (elem1->data != elem2->data) {
			return 0;
		}
		elem1 = elem1->next;
		elem2 = elem2->next;
	} while (elem1 || elem2);
	return 1;
}

int isWordEnd(T symbol) {
	T stopSymbols[] = " .,;\n\t";
	size_t i = 0;
	do {
		if (stopSymbols[i] == symbol) {
			return 1;
		}
	} while (++i < sizeof(stopSymbols));
	return 0;
}

size_t countWords(struct Element* elem) {
	size_t size = 0;
	while (elem) {
		if (isWordEnd(elem->data) && elem->prev && !isWordEnd(elem->prev->data)) {
			size++;
		}
		elem = elem->next;
	}
	return size;
}

size_t countLetters(struct Element* elem) {
	size_t counter = 0;
	while (!isWordEnd(elem->data)) {
		counter++;
		elem = elem->next;
	}
	return counter;
}

struct Element* cutFirstWord(struct Element** elem) {
	struct Element* word = NULL;
	struct Element* curr = *elem;
	while (isWordEnd(curr->data)) {
		curr = curr->next;
	}
	word = curr;
	while (!isWordEnd(curr->data)) {
		curr = curr->next;
	}
	if (word != *elem) {
		word->prev->next = curr;
		curr->prev = word->prev;
	}
	else {
		*elem = curr;
	}
	return word;
}
