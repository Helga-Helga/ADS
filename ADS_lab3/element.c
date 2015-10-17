#include "element.h"

struct Element* createElement(char value) {
    struct Element *elem = (struct Element*)malloc(sizeof(struct Element));
    elem->data = value;
    elem->next = NULL;
    elem->prev = NULL;
}

struct Element* insert(struct Element *elem, struct Element *newElem, int position) {
    int i = 0;
    struct Element *curr;
    if (position < 0) {
        return NULL;
    }
    else if (elem == NULL) {
        return NULL;
    }
    else if (position == 0) {
        newElem->next = elem;
        elem->prev = newElem;
        return newElem;
    }
    curr = elem;
    while (++i < position) {
        curr = curr->next;
        if (!curr) {
            return NULL;
        }
    }
    if (curr->next) {
        newElem->next = curr->next;
        newElem->next->prev = newElem;
    } 
    curr->next = newElem;
    newElem->prev = curr;
    return elem;
}
