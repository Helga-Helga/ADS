#include "element.h"

struct Element* createList(char value) {
    struct Element *elem = (struct Element*)malloc(sizeof(struct Element));
    elem->data = value;
    elem->next = NULL;
    elem->prev = NULL;
}