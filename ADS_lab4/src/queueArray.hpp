#pragma once
#include <stdexcept>
#include <iostream>
#include "queue.hpp"
using namespace std;

template <class T> class QueueArray : public Queue<T> {
private:
	T *array;
	size_t first;
	size_t last;
	size_t size;
	size_t elementsCount;
public:
	QueueArray() {
		this->array = new T[80];
		this->first = 0;
		this->last = 0;
		this->size = 80;
		this->elementsCount = 0;
	}
	virtual ~QueueArray() {
		delete[] this->array;
	}
	void push(T elem) {
		if (this->elementsCount >= this->size) {
			throw runtime_error("Queue overflow");
		}
		if (this->last == this->size) {
			this->last = 0;
		}
		this->array[this->last++] = elem;
		this->elementsCount++;
	}
	T pop() {
		if (this->elementsCount == 0) {
			throw runtime_error("Queue is empty");
		}
		if (this->first == this->size) {
			this->first = 0;
		}
		return this->array[this->first++];
	}
	void print() {
		if (this->last > this->first) {
			for (size_t i = this->first; i < this->last; i++) {
				cout<<array[i]<<" ";
			}	
		}
		else if (this->last < this->first) {
				for (size_t i = this->first; i < this->size; i++) {
					cout<<array[i]<<" ";
				}
				for (size_t i = 0; i < this->last; i++) {
					cout<<array[i]<<" ";
				}
		}
		cout<<endl;
	}
};
