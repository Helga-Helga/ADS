#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../element.h"
#include "tests.h"

void testDeleteFromNegativePosition () {
	struct Element *a = createElement('a');
    CU_ASSERT_PTR_NULL(deleteElement(a, -1));
    deleteList(a);
}

void testDeleteFromNULL() {
    CU_ASSERT_PTR_NULL(deleteElement(NULL, 0));
}

void testDeleteFromFirstPosition() {
	struct Element *a = createElement('a');
	struct Element *b = createElement('b');
	b = insertElement(a, b, 0);
	CU_ASSERT_EQUAL(deleteElement(b, 0), a);
	CU_ASSERT_PTR_NULL(a->next);
	CU_ASSERT_PTR_NULL(a->prev);
	deleteList(a);
}

void testDeleteFromMiddlePosition() {
	struct Element *a = createElement('a');
	struct Element *b = createElement('b');
	struct Element *c = createElement('c');
	insertElement(a, b, 1);
	insertElement(a, c, 2);
	CU_ASSERT_EQUAL(deleteElement(a, 1), a);
	CU_ASSERT_EQUAL(a->next, c);
	CU_ASSERT_EQUAL(c->prev, a);
	deleteList(a);
}

void testDeleteFromEndPosition() {
	struct Element *a = createElement('a');
	struct Element *b = createElement('b');
	b = insertElement(a, b, 0);
	CU_ASSERT_EQUAL(deleteElement(b, 1), b);
	CU_ASSERT_PTR_NULL(b->next);
	CU_ASSERT_PTR_NULL(b->prev);
	deleteList(b);
}

void testDeleteSingleElement() {
	struct Element *a = createElement('a');
	CU_ASSERT_PTR_NULL(deleteElement(a, 0));
	deleteList(a);
}
