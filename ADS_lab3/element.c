#include "element.h"

struct Element* createElement(char value) {
    struct Element *elem = (struct Element*)malloc(sizeof(struct Element));
    elem->data = value;
    elem->next = NULL;
    elem->prev = NULL;
}

struct Element* insert(struct Element *elem, struct Element *newElem, int position) {
    int i;
    if (position < 0) {
        return NULL;
    }
    else if (elem == NULL) {
        return NULL;
    }
    for (i = 0; i <= position; i++) {
        elem = elem->next;
        if (!elem->next) {
            return NULL;
        }
    }
    elem->next = (struct Element*)malloc(sizeof(struct Element));
    elem->next->prev = elem;
    elem = elem->next;
    elem->data = newElem->data;
    elem->next = NULL;
        
}