#pragma once
#include "stack.hpp"
#include "list.hpp"

template <class T> class StackList : public Stack<T> {
private:
	List<T> *list;
public:
	StackList() {
		this->list = new List<T>();
	}
	~StackList() {
		delete this->list;
	}
	void push(T value) {
		this->list->insert(value, false);
	}
	T pop() {
		return this->list->remove();
	}
};
