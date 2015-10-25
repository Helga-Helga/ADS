#include "tasks.h"

struct Element* wordProcessing(struct Element* word) {
	if (!word) {
		return NULL;
	}
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

struct Element* textProcessing(struct Element* text) {
	if (countWords(text) < 2) {
		deleteList(text);
		return NULL;
	}
	text = ltrim(text);
	struct Element* curr = NULL;
	struct Element* first = cutFirstWord(&text);
	struct Element* end = NULL;
	while (text) {
		text = ltrim(text);
		curr = cutFirstWord(&text);
		if (!comparison(first, curr)) {
			end = insertElement(end, createElement(' '), listSize(end));
			insertElement(end, wordProcessing(curr), listSize(end));
		}
		else {
			deleteList(curr);
		}
	}
	deleteList(first);
	end = rtrim(ltrim(end));
	end = insertElement(end, createElement('\0'), listSize(end));
	return end;
}
