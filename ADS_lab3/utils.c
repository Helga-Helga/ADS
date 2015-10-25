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
