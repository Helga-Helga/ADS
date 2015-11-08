#include <string.h>
#include "tasks_array.h"
#include "utils.h"

size_t countWordsArray(T* array) {
	size_t size = 0;
	size_t i = 0;
	if (!array) {
		return size;
	}
	while (i++ < strlen(array)) {
		if (isWordEnd(array[i]) && !isWordEnd(array[i-1])) {
			size++;
		}
	}
	return size;
}
