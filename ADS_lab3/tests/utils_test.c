#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../element.h"
#include "../utils.h"
#include "tests.h"

void testArrayToList() {
	size_t i = 0;
	T array[] = "bebe";
	size_t size = strlen(array)+1;
	struct Element* elem = arrayToList(array, size);
	struct Element* curr = elem;
	do {
		CU_ASSERT_EQUAL(curr->data, array[i]);
		curr = curr->next;
	} while (++i < size);
	deleteList(elem);
}

void testNULLToList() {
	CU_ASSERT_EQUAL(arrayToList(NULL, 0), NULL);
}

void testListToArray() {
	struct Element* elem = arrayToList("bebe", 5);
	T* array = listToArray(elem);
	CU_ASSERT_STRING_EQUAL(array, "bebe");
	deleteList(elem);
	free(array);
}
