#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../element.h"
#include "tests.h"

void testDeleteFromNegativePosition () {
	struct Element *a = createElement('a');
    CU_ASSERT_PTR_NULL(deleteElement(a, -1));
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
}

void testDeleteFromMiddlePosition() {
	struct Element *a = createElement('a');
	struct Element *b = createElement('b');
	b = insertElement(a, b, 0);
	CU_ASSERT_EQUAL(deleteElement(b, 1), b);
	CU_ASSERT_PTR_NULL(b->next);
	CU_ASSERT_PTR_NULL(b->prev);
}

void testDeleteSingleElement() {
	struct Element *a = createElement('a');
	CU_ASSERT_PTR_NULL(deleteElement(a, 0));
}
