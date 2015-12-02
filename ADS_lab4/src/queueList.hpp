#pragma once
#include "queue.hpp"

template <class T> class QueueList : public Queue<T> {
private:
	List<T> *list;
public:
	QueueList() {
		this->list = new List<T>();
	}
	~QueueList() {
		delete this->list;
	}
	void push(T value) {
		this->list->insert(value, true);
	}
	T pop() {
		return this->list->remove();
	}
	void print() {
		this->list->printList();
	}
};
