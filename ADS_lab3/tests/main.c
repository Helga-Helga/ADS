#include "tests.h"

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

int main() {
    CU_pSuite insertElementSuite = NULL, createElementSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    insertElementSuite = CU_add_suite("Insert element", init_suite, clean_suite);
    if (NULL == insertElementSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    createElementSuite = CU_add_suite("Create element", init_suite, clean_suite);
    if (NULL == createElementSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if (
    	(NULL == CU_add_test(createElementSuite, "Create element", testCreateElement)) ||
    	(NULL == CU_add_test(insertElementSuite, "Insert at negative position", testInsertAtNegativePosition)) ||
        (NULL == CU_add_test(insertElementSuite, "Insert at NULL", testInsertAtNULL)) ||
        (NULL == CU_add_test(insertElementSuite, "Insert at first posiition", testInsertAtFirstPosition)) ||
        (NULL == CU_add_test(insertElementSuite, "Insert at middle position", testInsertAtMiddlePosition))
        ) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}