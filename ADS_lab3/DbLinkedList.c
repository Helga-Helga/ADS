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
 
void deleteList(DbLinkedList **list) {
    Node *tmp = (*list)->head;
    Node *next = NULL;
    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(*list);
    (*list) = NULL;
}

void pushFront(DbLinkedList *list, void *data) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) {
        exit(1);
    }
    tmp->value = data;
    tmp->next = list->head;
    tmp->prev = NULL;
    if (list->head) {
        list->head->prev = tmp;
    }
    list->head = tmp;
    
    if (list->tail == NULL) {
        list->tail = tmp;
    }
    list->size++;
}