#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../element.h"
#include "tests.h"

void testListSize() {
	CU_ASSERT_EQUAL(listSize(insertElement(createElement('a'), createElement('b'), 1)), 2);
}
