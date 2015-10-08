#include "element.h"

struct Element {
    char data;
    Element *next;
    Element *prev;
};