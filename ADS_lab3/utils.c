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
	if (!elem) {
		return 0;
	}
	while (elem && !isWordEnd(elem->data)) {
		counter++;
		elem = elem->next;
	}
	return counter;
}

struct Element* cutFirstWord(struct Element** elem) {
	struct Element* word = NULL;
	struct Element* curr = *elem;
	while (curr && isWordEnd(curr->data)) {
		curr = curr->next;
	}
	if (!curr) {
		return NULL;
	}
	word = curr;
	while (curr->next && !isWordEnd(curr->next->data)) {
		curr = curr->next;
	}
	if (curr->next) {
		curr->next->prev = word->prev;
	}
	if (word == *elem) {
		*elem = curr->next;
	}
	else {
		word->prev->next = curr->next;
	}
	word->prev = NULL;
	curr->next = NULL;
	return word;
}

struct Element* ltrim(struct Element* elem) {
	struct Element* curr = elem;
	while (curr && isWordEnd(curr->data)) {
		curr = curr->next;
	}
	if (!curr) {
		deleteList(elem);
		return NULL;
	}
	if (elem == curr) {
		return elem;
	}
	if (curr) {
		curr->prev->next = NULL;
		curr->prev = NULL;
	}
	deleteList(elem);
	return curr;
}

struct Element* rtrim(struct Element* elem) {
	struct Element* curr = elem;
	if (!curr) {
		return NULL;
	}
	while (curr->next) {
		curr = curr->next;
	}
	while (curr->prev && isWordEnd(curr->data)) {
		curr = curr->prev;
	}
	if (!isWordEnd(curr->data)) {
		deleteList(curr->next);
		return elem;
	}
	deleteList(curr);
	return NULL;
}
