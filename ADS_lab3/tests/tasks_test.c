#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../element.h"
#include "../utils.h"
#include "tests.h"
#include "../tasks.h"

void testWordProcessing() {
	struct Element* word = arrayToList("bebe", sizeof("bebe"));
	T* array = listToArray(wordProcessing(word));
	CU_ASSERT_STRING_EQUAL(array, "bbebe");
	deleteList(word);
	free(array);
	word = arrayToList("muu", sizeof("muu"));
	array = listToArray(wordProcessing(word));
	CU_ASSERT_STRING_EQUAL(array, "mu");
	deleteList(word);
	free(array);
}

void testTextProcessing() {
	struct Element* text = arrayToList("bebe bebebe", sizeof("bebe bebebe"));
	struct Element* result = textProcessing(text);
	T* array = listToArray(result);
	CU_ASSERT_STRING_EQUAL(array, "bbebebe");
	deleteList(result);
	free(array);
}
