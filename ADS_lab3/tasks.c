#include "tasks.h"

struct Element* wordProcessing(struct Element* word) {
	size_t counter = countLetters(word);
	struct Element* curr = word;
	if (counter&1) {
		while (--counter) {
			curr = curr->next;
		}
		destructElement(curr);
		return word;
	}
	else {
		return insertElement(curr, createElement(curr->data), 1);
	}
}