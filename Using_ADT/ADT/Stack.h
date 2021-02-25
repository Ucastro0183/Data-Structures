/*
 * Stack.h
 *
 *  Created on: 29/06/2014
 *      Author: Ulises
 */

#ifndef STACK_H_
#define STACK_H_

#include <string>

template <typename ElemType>
class Stack {
public:
	Stack();
	virtual ~Stack();

	int size();
	bool isEmpty();

	void push(ElemType value);	//Push an element into the stack
	ElemType pop();				//Gets the last element
	ElemType peek();			//Cheeks the last element without removing it

	std::string toString();

private:
	int dim;

	struct stack {
		ElemType value;
		stack *next;
	};

	stack *data;

};

#include "Stack.cpp"	//Only for template classes

#endif /* STACK_H_ */
