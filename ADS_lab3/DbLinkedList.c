#include "Header.h"

typedef struct _Node {
    void *value;
    struct _Node *next;
    struct _Node *prev;
} Node;

typedef struct _DbLinkedList {
    size_t size;
    Node *head;
    Node *tail;
} DbLinkedList;

DbLinkedList* createList() {
    DbLinkedList *tmp = (DbLinkedList*) malloc(sizeof(DbLinkedList));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;
    
    return tmp;
}
 