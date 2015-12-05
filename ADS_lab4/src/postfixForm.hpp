#pragma once
#include <string>
#include "stackArray.hpp"
using namespace std;

double calc(double *numbers, string expression = "AB*C+D/FE/-") {
	StackArray<double> *stack;
	stack = new StackArray<double>();
	double left, right;
	for (char c: expression) {
		switch (c) {
			case '+':
			right = stack->pop();
			left = stack->pop();
			stack->push(left + right);
			break;
			case '-':
			right = stack->pop();
			left = stack->pop();
			stack->push(left - right);
			break;
			case '*':
			right = stack->pop();
			left = stack->pop();
			stack->push(left * right);
			break;
			case '/':
			right = stack->pop();
			left = stack->pop();
			stack->push(left / right);
			break;
			default:
			stack->push(numbers[c - 'A']);
			break;
		}
	}
	return stack->pop();
}
