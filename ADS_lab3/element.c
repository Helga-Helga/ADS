#include "element.h"

struct Element* createElement(char value) {
    struct Element *elem = (struct Element*)malloc(sizeof(struct Element));
    elem->data = value;
    elem->next = NULL;
    elem->prev = NULL;
}

struct Element* insert(struct Element *elem, struct Element *newElem, int position) {
    int i;
    struct Element *tmp;
    if (position < 0) {
        return NULL;
    }
    else if (elem == NULL) {
        return NULL;
    }
    while (++i < position) {
        elem = elem->next;
        if (!elem) {
            return NULL;
        }
    }
    elem->next = (struct Element*)malloc(sizeof(struct Element));
    elem->next->prev = elem;
    tmp = elem;
    elem = elem->next;
    elem->data = newElem->data;
    elem->next = tmp->next;        
}
