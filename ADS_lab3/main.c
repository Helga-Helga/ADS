/* 
 * File:   main.c
 * Author: olya
 *
 * Created on October 8, 2015, 3:18 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "element.h"
#include "tasks.h"
#include "utils.h"
#include "tasks_array.h"

/*
 * 
 */
int main(int argc, char** argv) {
	if (argc != 3) {
		printf("Usage: %s (list|array) \"Your text\"\n", argv[0]);
		return (EXIT_FAILURE);
	}
	else if (strcmp(argv[1], "list") == 0) {
		struct Element* text = arrayToList(argv[2], strlen(argv[2]));
		if (!text) {
			perror("The string mush contain at least two words\n");
		}
		text = textProcessing(text);
		printf("Text processed:\n");
		printList(text);
		deleteList(text);
		return (EXIT_SUCCESS);
	}
	else if (strcmp(argv[1], "array") == 0) {
		T* text = arrayProcessing(argv[2]);
		if (!text) {
			perror("The string mush contain at least two words\n");
		}
		printf("Text processed:\n%s\n", text);
		free(text);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
