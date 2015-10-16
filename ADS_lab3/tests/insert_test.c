/*
 * File:   insert_test.c
 * Author: olya
 *
 * Created on Oct 16, 2015, 8:50:01 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../element.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testInsert() {
    struct Element *elem = createElement('a');
    struct Element *newElem = createElement('b');
    CU_ASSERT_PTR_NULL(insert(elem, newElem, -1));
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("insert_test", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testInsert", testInsert))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
