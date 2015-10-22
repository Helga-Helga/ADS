#include "element.h"

struct Element* createElement(char value) {
    struct Element *elem = (struct Element*)malloc(sizeof(struct Element));
    elem->data = value;
    elem->next = NULL;
    elem->prev = NULL;
    return elem;
}

void destructElement(struct Element *elem) {
    free (elem);
    if (elem->prev->next) {
        elem->prev->next = NULL;
    }
    if (elem->next->prev) {
        elem->next->prev = NULL;
    }
}

struct Element* insertElement(struct Element *elem, struct Element *newElem, int position) {
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

struct Element* deleteElement(struct Element *elem, int position) {
    struct Element *head;
    struct Element *curr;
    int i = 0;
    head = elem;
    if (position < 0) {
        return NULL;
    }
    else if (elem == NULL) {
        return NULL;
    }
    else if (!elem->next && position == 0){
        return NULL;
    }
    else if (position == 0) {
        head = elem->next;
        destructElement(elem);
        head->prev = NULL;
        return head;
    }
    curr = elem;
    while (i++ < position) {
        curr = curr->next;
        if (!curr) {
            return NULL;
        }
    }
    if (curr->next) {
        curr->next->prev = curr->prev;
    }  
    curr->prev->next = curr->next;
    destructElement(curr);
    return head;
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
