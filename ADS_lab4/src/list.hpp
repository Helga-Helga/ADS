#pragma once
#include <stdexcept>
#include <iostream>
using namespace std;
template <class T> class List {
	private:
		struct Element {
			T value;
			Element *next;
			Element(T value, Element *next = NULL) {
				this->value = value;
				this->next = next;
			}
			~Element() {
				this->next = NULL;
			}
		};
		Element *first;
		Element *last;
	public:
		List() {
			this->first = this->last = NULL;
		}
		~List() {
			while (this->first) {
				this->remove();
			}
		}
		void insert(T value, bool isLast) {
			if (!this->first && !this->last) {
				this->first = this->last = new Element(value);
			}
			else if (isLast) {
				this->last = this->last->next = new Element(value, this->last->next);
			}
			else {
				this->first = new Element(value, this->first);
			}
		}
		T remove() {
			if (!this->first) {
				throw runtime_error("List is empty");
			}
			T value = this->first->value;
			if (!this->first->next) {
				delete this->first;
				this->first = this->last = NULL;
			}
			else {
				Element *tmp = this->first->next;
				delete this->first;
				this->first = tmp;
			}
			return value;
		}
};
