#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../tasks_array.h"
#include "tests.h"

void testCountWordsArray() {
	T* array = "bebe";
	CU_ASSERT_EQUAL(countWordsArray(array), 1);
	array = " ";
	CU_ASSERT_EQUAL(countWordsArray(array), 0);
	array = "bebe  bebe";
	CU_ASSERT_EQUAL(countWordsArray(array), 2);
	array = "bebe, arar... murr	murr;";
	CU_ASSERT_EQUAL(countWordsArray(array), 4);
	array = "";
	CU_ASSERT_EQUAL(countWordsArray(array), 0);
	array = NULL;
	CU_ASSERT_EQUAL(countWordsArray(array), 0);
}
