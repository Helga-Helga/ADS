#pragma once
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
			if (this->first == NULL && this->last == NULL) {
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
			T value = this->first->value;
			if (this->first->next == NULL) {
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
