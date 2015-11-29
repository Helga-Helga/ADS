#pragma once
#include "queue.hpp"

template <class T> class QueueArray : public Queue<T> {
private:
	T *array;
	size_t first;
	size_t last;
	size_t size;
public:
	QueueArray() {
		this->array = new T[80];
		this->first = 0;
		this->last = 0;
		this->size = 80;
	}
	virtual ~QueueArray() {
		delete[] this->array;
	}
	void push(T elem) {
		this->array[this->last++] = elem;
	}
	T pop() {
		return this->array[this->first++];
	}
};
