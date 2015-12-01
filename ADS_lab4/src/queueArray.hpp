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
		if (++this->last == this->size) {
			this->last = 0;
		}
		this->array[this->last] = elem;
	}
	T pop() {
		if (++this->first == this->size) {
			this->first = 0;
		}
		return this->array[this->first];
	}
};
