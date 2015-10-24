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
