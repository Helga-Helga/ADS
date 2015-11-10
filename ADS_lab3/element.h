/* 
 * File:   element.h
 * Author: olya
 *
 * Created on October 8, 2015, 3:23 PM
 */

#ifndef ELEMENT_H
#define	ELEMENT_H
 
#include <stdlib.h>
#include <stdio.h>

typedef char T;

struct Element{
    T data;
    struct Element *next;
    struct Element *prev;
};

struct Element* createElement(T);
int destructElement(struct Element *);
struct Element* insertElement(struct Element *, struct Element *, size_t);
int deleteList(struct Element *);
size_t listSize(struct Element *);

#endif	/* ELEMENT_H */
