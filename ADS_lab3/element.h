/* 
 * File:   element.h
 * Author: olya
 *
 * Created on October 8, 2015, 3:23 PM
 */

#ifndef ELEMENT_H
#define	ELEMENT_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* ELEMENT_H */

#include <stdlib.h>
#include <stdio.h>

struct Element{
    char data;
    struct Element *next;
    struct Element *prev;
};

struct Element* createElement(char);
struct Element* insert(struct Element *, struct Element *, int);