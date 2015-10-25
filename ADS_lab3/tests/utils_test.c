#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../element.h"
#include "../utils.h"
#include "tests.h"

void testArrayToList() {
	size_t i = 0;
	T array[] = "bebe";
	size_t size = strlen(array);
	struct Element* elem = arrayToList(array, size);
	struct Element* curr = elem;
	do {
		CU_ASSERT_EQUAL(curr->data, array[i]);
		curr = curr->next;
	} while (++i < size);
	deleteList(elem);
}

void testNULLToList() {
	T array[] = "";
	size_t size = strlen(array);
	CU_ASSERT_EQUAL(arrayToList(array, size), NULL);
}
