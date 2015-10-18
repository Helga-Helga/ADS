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
#include "tests.h"

/*
 * CUnit Test Suite
 */

void testInsertAtNegativePosition() {
    struct Element *a = createElement('a');
    struct Element *b = createElement('b');
    CU_ASSERT_PTR_NULL(insert(a, b, -1));
}

void testInsertAtNULL() {
    struct Element *a = createElement('a');
    struct Element *b = createElement('b');
    CU_ASSERT_PTR_NULL(insert(NULL, b, 0));
    CU_ASSERT_EQUAL(insert(a, b, 0), b);
    CU_ASSERT_EQUAL(b->next, a);
    CU_ASSERT_EQUAL(a->prev, b);
    
}

void testInsertAtFirstPosition() {
    struct Element *a = createElement('a');
    struct Element *b = createElement('b');
    struct Element *c = createElement('c');
    b = insert(a, b, 0);
    CU_ASSERT_EQUAL(insert(b, c, 2), b);
    CU_ASSERT_EQUAL(a->next, c);
    CU_ASSERT_EQUAL(c->prev, a);
    CU_ASSERT_EQUAL(b->next, a);
    CU_ASSERT_EQUAL(a->prev, b);
}

void testInsertAtMiddlePosition() {
    struct Element *a = createElement('a');
    struct Element *b = createElement('b');
    struct Element *c = createElement('c');
    struct Element *d = createElement('d');
    b = insert(a, b, 0);
    b = insert(b, c, 2);
    CU_ASSERT_EQUAL(insert(b, d, 2), b);
    CU_ASSERT_EQUAL(a->next, d);
    CU_ASSERT_EQUAL(d->prev, a);
    CU_ASSERT_EQUAL(b->next, a);
    CU_ASSERT_EQUAL(a->prev, b);
    CU_ASSERT_EQUAL(d->next, c);
    CU_ASSERT_EQUAL(c->prev, d);
    CU_ASSERT_PTR_NULL(c->next);
}
