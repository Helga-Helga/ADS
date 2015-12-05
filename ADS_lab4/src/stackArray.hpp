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
	StackArray<T> *mainStack;
public:
	StackArray(StackArray<T> *mainStack = NULL) {
		if (!mainStack) {
			this->array = new T[80];
			this->top = 0;
			this->size = 80;
			this->mainStack = NULL;
		}
		else {
			this->mainStack = mainStack;
			this->array = this->mainStack->array;
			this->size = this->mainStack->size;
			this->top = this->size - 1;
		}
	}
	virtual ~StackArray() {
		if (!this->mainStack) {
			delete[] this->array;
		}
		else {
			this->mainStack->size = this->size;
		}
	}
	void push(T elem) {
		if (!this->mainStack && this->top < this->size - 1) {
			this->array[this->top++] = elem;
		}
		else if (this->mainStack && this->top > this->mainStack->top + 1) {
			this->mainStack->size--;
			this->array[this->top--] = elem;
		}
		else {
			throw runtime_error("Stack overflow");
		}
	}
	T pop() {
		if (!this->mainStack && this->top-- > 0) {
			return this->array[this->top];
		}
		else if (this->mainStack && this->top++ < this->size - 1) {
			this->mainStack->size++;
			return this->array[this->top];
		}
		else {
			throw runtime_error("Stack is empty");
		}
	}
	void print() {
		if (!mainStack) {
			for (size_t i = 0; i < this->top; i++) {
				cout<<array[i]<<" ";
			}
		}
		else {
			for (size_t i = this->size - 1; i > this->top; i--) {
				cout<<array[i]<<" ";
			}
		}
		cout<<endl;
	}
};
