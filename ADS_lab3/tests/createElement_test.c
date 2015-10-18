/*
 * File:   createList_test.c
 * Author: olya
 *
 * Created on Oct 8, 2015, 4:44:02 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../element.h"
#include "tests.h"

/*
 * CUnit Test Suite
 */

void testCreateElement() {
    struct Element *elem = createElement('a');
    CU_ASSERT_PTR_NOT_NULL(elem);
    CU_ASSERT_EQUAL(elem->data, 'a');
    CU_ASSERT_PTR_NULL(elem->next);
    CU_ASSERT_PTR_NULL(elem->prev);
}
