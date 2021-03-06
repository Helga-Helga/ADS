#include "element.h"

struct Element* createElement(T value) {
    struct Element *elem = (struct Element*)malloc(sizeof(struct Element));
    elem->data = value;
    elem->next = NULL;
    elem->prev = NULL;
    return elem;
}

int destructElement(struct Element *elem) {
    if (!elem) {
        return 0;
    }
    if (elem->prev) {
        elem->prev->next = elem->next;
    }
    if (elem->next) {
        elem->next->prev = elem->prev;
    }
    free(elem);
    return 0;
}

struct Element* insertElement(struct Element *elem, struct Element *newElem, size_t position) {
    size_t i = 0;
    struct Element *curr;
    if (!newElem) {
        return elem;
    }
    else if (elem == NULL && position != 0) {
        return NULL;
    }
    else if (elem == NULL) {
        return newElem;
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

int deleteList(struct Element *elem) {
    struct Element *curr;
    if (!elem) {
        return 0;
    }
    curr = elem;
    while (curr->next) {
        curr = curr->next;
        destructElement(curr->prev);
    }
    destructElement(curr);
    return 1;
}

size_t listSize(struct Element* elem) {
    size_t size = 0;
    if (!elem) {
        return 0;
    }
    while (++size && (elem = elem->next)); 
    return size;
}
