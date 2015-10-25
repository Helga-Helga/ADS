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

void testComparison() {
	struct Element* elem1 = arrayToList("bebe", 5);
	struct Element* elem2 = arrayToList("bebe", 5);
	struct Element* elem3 = arrayToList("mu", 3);
	CU_ASSERT_EQUAL(comparison(elem1, elem2), 1);
	CU_ASSERT_EQUAL(comparison(elem1, elem3), 0);
	CU_ASSERT_EQUAL(comparison(elem2, elem3), 0);
	deleteList(elem1);
	deleteList(elem2);
	deleteList(elem3);
}

void testIsWordEnd() {
	CU_ASSERT_EQUAL(isWordEnd(' '), 1);
	CU_ASSERT_EQUAL(isWordEnd(0), 1);
	CU_ASSERT_EQUAL(isWordEnd('a'), 0);
}

void testCountWords() {
	struct Element* list = arrayToList("bebe bebe", sizeof("bebe bebe"));
	CU_ASSERT_EQUAL(countWords(list), 2);
	deleteList(list);
	CU_ASSERT_EQUAL(countWords(NULL), 0);
	list = arrayToList("bebe   bebe", sizeof("bebe   bebe"));
	CU_ASSERT_EQUAL(countWords(list), 2);
	deleteList(list);
	list = arrayToList("bebe, arar... murr	murr;", sizeof("bebe, arar... murr	murr;"));
	CU_ASSERT_EQUAL(countWords(list), 4);
	deleteList(list);
}
