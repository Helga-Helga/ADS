#include "tests.h"

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

int main() {
    CU_pSuite insertElementSuite = NULL, createElementSuite = NULL, deleteElementSuite = NULL, 
              listSizeSuite = NULL, utilsSuite = NULL, tasksSuite = NULL, tasks_arraySuite;

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

    deleteElementSuite = CU_add_suite("Delete element", init_suite, clean_suite);
    if (NULL == deleteElementSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    listSizeSuite = CU_add_suite("List size", init_suite, clean_suite);
    if (NULL == listSizeSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    utilsSuite = CU_add_suite("Utils", init_suite, clean_suite);
    if (NULL == utilsSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    tasksSuite = CU_add_suite("Tasks", init_suite, clean_suite);
    if (NULL == tasksSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    tasks_arraySuite = CU_add_suite("Tasks array", init_suite, clean_suite);
    if (NULL == tasksSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if (
    	(NULL == CU_add_test(createElementSuite, "Create element", testCreateElement)) ||
    	(NULL == CU_add_test(insertElementSuite, "Insert at negative position", testInsertAtNegativePosition)) ||
        (NULL == CU_add_test(insertElementSuite, "Insert at NULL", testInsertAtNULL)) ||
        (NULL == CU_add_test(insertElementSuite, "Insert at first posiition", testInsertAtFirstPosition)) ||
        (NULL == CU_add_test(insertElementSuite, "Insert at middle position", testInsertAtMiddlePosition)) ||
        (NULL == CU_add_test(deleteElementSuite, "Delete from negative position", testDeleteFromNegativePosition)) ||
        (NULL == CU_add_test(deleteElementSuite, "Delete from NULL", testDeleteFromNULL)) ||
        (NULL == CU_add_test(deleteElementSuite, "Delete from first position", testDeleteFromFirstPosition)) ||
        (NULL == CU_add_test(deleteElementSuite, "Delete from middle position", testDeleteFromMiddlePosition)) ||
        (NULL == CU_add_test(deleteElementSuite, "Delete from end position", testDeleteFromEndPosition)) ||
        (NULL == CU_add_test(deleteElementSuite, "Delete single element", testDeleteSingleElement)) ||
        (NULL == CU_add_test(listSizeSuite, "List size", testListSize)) ||
        (NULL == CU_add_test(listSizeSuite, "Single element size", testSingleElementSize)) ||
        (NULL == CU_add_test(listSizeSuite, "NULL size", testNULLSize)) ||
        (NULL == CU_add_test(utilsSuite, "Array to list", testArrayToList)) ||
        (NULL == CU_add_test(utilsSuite, "NULL to list", testNULLToList)) ||
        (NULL == CU_add_test(utilsSuite, "List to array", testListToArray)) ||
        (NULL == CU_add_test(utilsSuite, "Comparison", testComparison)) ||
        (NULL == CU_add_test(utilsSuite, "Is word end", testIsWordEnd)) ||
        (NULL == CU_add_test(utilsSuite, "Count words", testCountWords)) ||
        (NULL == CU_add_test(utilsSuite, "Count letters", testCountLetters)) ||
        (NULL == CU_add_test(utilsSuite, "Cut first word", testCutFirstWord)) ||
        (NULL == CU_add_test(utilsSuite, "Left trim", testLtrim)) ||
        (NULL == CU_add_test(tasksSuite, "Word processing", testWordProcessing)) ||
        (NULL == CU_add_test(tasksSuite, "Text processing", testTextProcessing)) ||
        (NULL == CU_add_test(tasksSuite, "Advanced text processing", testAdvancedTextProcessing)) ||
        (NULL == CU_add_test(tasksSuite, "Lorem Ipsum  processing", testLoremIpsumProcessing)) ||
        (NULL == CU_add_test(tasks_arraySuite, "Count words array", testCountWordsArray)) ||
        (NULL == CU_add_test(tasks_arraySuite, "Word length", testWordlen)) ||
        (NULL == CU_add_test(tasks_arraySuite, "Comparison with first word", testCmpWithFirstWord)) ||
        (NULL == CU_add_test(tasks_arraySuite, "Find next word", testFindNextWord)) ||
        0) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}