#include "element.h"

struct Element* createList(char value) {
    struct Element *elem = (struct Element*)malloc(sizeof(struct Element));
    elem->data = value;
    elem->next = NULL;
    elem->prev = NULL;
}

void insertAtTail(struct Element *elem, char value) {
    while (elem->next != NULL) {
        elem = elem->next;
    }
    elem->next = (struct Element*)malloc(sizeof(struct Element));
    (elem->next)->prev = elem;
    elem = elem->next;
    elem->data = value;
    elem->next = NULL;
}