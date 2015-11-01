#include "tasks.h"

struct Element* wordProcessing(struct Element* word) {
	if (!word) {
		return NULL;
	}
	size_t counter = countLetters(word);
	struct Element* curr = word;
	if (counter == 1) {
		deleteList(word);
		return NULL;
	}
	else if (counter&1) {
		while (--counter) {
			curr = curr->next;
		}
		destructElement(curr);
		return word;
	}
	else {
		return insertElement(curr, createElement(curr->data), 0);
	}
}

struct Element* textProcessing(struct Element* text) {
	if (countWords(text) < 2) {
		deleteList(text);
		return NULL;
	}
	struct Element* first = cutFirstWord(&text);
	struct Element* curr = cutFirstWord(&text);
	struct Element* end = NULL;
	while (curr) {
		text = ltrim(text);
		if (!comparison(first, curr)) {
			end = insertElement(end, createElement(' '), listSize(end));
			curr = wordProcessing(curr);
			end = insertElement(end, curr, listSize(end));
		}
		else {
			deleteList(curr);
		}
		curr = cutFirstWord(&text);
	}
	deleteList(first);
	deleteList(text);
	end = rtrim(ltrim(end));
	end = insertElement(end, createElement('\0'), listSize(end));
	return end;
}

int printList(struct Element* text) {
	struct Element* curr = text;
	while (curr && curr->data != 0) {
		printf("%s\n", curr->data);
		curr = curr->next;
	}
	return 0;
}
