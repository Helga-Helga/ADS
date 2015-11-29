#pragma once
#include "stack.hpp"

template <class T> class StackArray : public Stack<T> {
private:
	T *array;
	size_t top;
	size_t size;
public:
	StackArray() {
		this->array = new T[80];
		this->top = 0;
		this->size = 80;
	}
	virtual ~StackArray() {
		delete[] this->array;
	}
	void push(T elem) {
		this->array[this->top++] = elem;
	}
	T pop() {
		return this->array[--this->top];
	}
};
