#pragma once

template <class T> class Container {
public:
	virtual void push(T) = 0;
	virtual T pop() = 0;
	virtual ~Container() {};
};
