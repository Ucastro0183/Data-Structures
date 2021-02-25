/*
 * Stack.cpp
 *
 *  Created on: 29/06/2014
 *      Author: Ulises
 */

/* IMPORTANT NOTE:
 *
 * As this code has to be added to the header (as in any other template class),
 * it is required to exclude this file from the project build.
 *
 * (Right click) > Resource Configurations > Exclude from Build...
 *
 * Or add the #ifndef and #endif flags to the cpp
 *
 */

#ifndef STACK_H_

#include "Stack.h"			//Header
#include <stdlib.h>			//Library for NULL values
#include "MyError.h"		//Library for error handling

using namespace std;

template <typename ElemType>
struct stack {
	ElemType value;
	stack *next;
};

template <typename ElemType>
Stack<ElemType>::Stack() {
	this->dim = 0;
	data = NULL;
}

template <typename ElemType>
int Stack<ElemType>::size(){
	return (this->dim);
}

template <typename ElemType>
bool Stack<ElemType>::isEmpty(){
	return ( dim==0 ? true : false);
}

template <typename ElemType>
void Stack<ElemType>::push(ElemType value){
	//Push an element into the stack
	stack *n = new stack;
	n->value = value;
	n->next = data;
	data = n;
	this->dim += 1;
}

template <typename ElemType>
ElemType Stack<ElemType>::pop(){
	//Gets the last element
	if (this->dim == 0)
		MyError::error("There are no items stored in the stack");
	stack *curr = data;
	data = curr->next;
	ElemType value = curr->value;
	delete (curr);
	this->dim -= 1;
	return(value);
}

template <typename ElemType>
ElemType Stack<ElemType>::peek(){
	//Cheeks the last element without removing it
	if (data == NULL)
		MyError::error("There are no items stored in the stack");
	return(data->value);
}

template <typename ElemType>
std::string Stack<ElemType>::toString() {
	std::string str = "";
	for (stack *curr = data; curr != NULL; curr = curr->next)
		str += curr->value.toString() + " ";
	return (str);
}

template <typename ElemType>
void erase(stack<ElemType> *curr) {
	if (curr == NULL)
		return;
	erase(curr->next);
	delete curr;
	curr = NULL;
}

template <typename ElemType>
Stack<ElemType>::~Stack() {
	erase(data);
	this->dim = 0;
}

#endif
