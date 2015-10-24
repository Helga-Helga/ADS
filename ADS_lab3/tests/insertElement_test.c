#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../element.h"
#include "tests.h"

void testInsertAtNegativePosition() {
    struct Element *a = createElement('a');
    struct Element *b = createElement('b');
    CU_ASSERT_PTR_NULL(insertElement(a, b, -1));
    deleteList(a);
    deleteList(b);
}

void testInsertAtNULL() {
    struct Element *b = createElement('b');
    CU_ASSERT_PTR_NULL(insertElement(NULL, b, 0)); 
    deleteList(b);   
}

void testInsertAtFirstPosition() {
    struct Element *a = createElement('a');
    struct Element *b = createElement('b');
    struct Element *c = createElement('c');
    b = insertElement(a, b, 0);
    CU_ASSERT_PTR_NULL(b->prev);
    CU_ASSERT_EQUAL(insertElement(b, c, 2), b);
    CU_ASSERT_EQUAL(a->next, c);
    CU_ASSERT_EQUAL(c->prev, a);
    CU_ASSERT_EQUAL(b->next, a);
    CU_ASSERT_EQUAL(a->prev, b);
    deleteList(b);
}

void testInsertAtMiddlePosition() {
    struct Element *a = createElement('a');
    struct Element *b = createElement('b');
    struct Element *c = createElement('c');
    struct Element *d = createElement('d');
    b = insertElement(a, b, 0);
    b = insertElement(b, c, 2);
    CU_ASSERT_EQUAL(insertElement(b, d, 2), b);
    CU_ASSERT_EQUAL(a->next, d);
    CU_ASSERT_EQUAL(d->prev, a);
    CU_ASSERT_EQUAL(b->next, a);
    CU_ASSERT_EQUAL(a->prev, b);
    CU_ASSERT_EQUAL(d->next, c);
    CU_ASSERT_EQUAL(c->prev, d);
    CU_ASSERT_PTR_NULL(c->next);
    deleteList(b);
}
