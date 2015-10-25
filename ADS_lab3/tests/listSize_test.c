#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../element.h"
#include "tests.h"

void testListSize() {
	struct Element* list = insertElement(createElement('a'), createElement('b'), 1);
	CU_ASSERT_EQUAL(listSize(list), 2);
}

void testSingleElementSize() {
	struct Element* elem = createElement('a');
	CU_ASSERT_EQUAL(listSize(elem), 1);
}
