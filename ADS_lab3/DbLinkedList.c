typedef struct _Node {
    void *value;
    struct _Node *next;
    struct _Node *prev;
} Node;