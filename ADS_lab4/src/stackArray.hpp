#pragma once
#include <stdexcept>
#include <iostream>
#include "stack.hpp"
using namespace std;

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
		if (this->top++ != this->size) {
			this->array[this->top] = elem;
		}
		else {
			throw runtime_error("Stack overflow");
		}
	}
	T pop() {
		if (this->top != 0) {
			return this->array[this->top];
		}
		else {
			throw runtime_error("Stack is empty");
		}
	}
};
