/*
 * Queue.cpp
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

#ifndef QUEUE_H_

#include "Queue.h"			//Header
#include <stdlib.h>			//Library for NULL values
#include "MyError.h"		//Library for error handling

using namespace std;

template <typename ElemType>
struct queueT {
	ElemType value;
	queueT *next;
};

template <typename ElemType>
Queue<ElemType>::Queue() {
	//data = new (queue<ElemType>);
	data = NULL;
	tail = NULL;
	this->dim = 0;
}

template <typename ElemType>
int Queue<ElemType>::size() {
	return (this->dim);
}

template <typename ElemType>
bool Queue<ElemType>::isEmpty(){
	return (dim == 0 ? true : false);
}

template <typename ElemType>
void Queue<ElemType>::enqueue(ElemType value){
	//push an element to the queue
	queueT *n;
	n = new queueT;
	n->value = value;
	n->next = NULL;
	if (data == NULL) {
		data = tail = n;
	} else {				//Tail pointer allows to add a new value
		tail->next = n;		//without searching the whole list for the
		tail = n;			//pointer to NULL.
	}
	this->dim += 1;
}

template <typename ElemType>
ElemType Queue<ElemType>::dequeue(){
	//Gets an element from the queue
	if (data == NULL)
		MyError::error("Error - The memory hasn't been allocated, the queue is empty.");
	queueT *old;
	old = data;
	ElemType value = data->value;
	data = data->next;
	if (data == NULL) tail == NULL;
	delete (old);
	this->dim -=1;
	return (value);
}

template <typename ElemType>
ElemType Queue<ElemType>::peek(){
	//Gets the top most element from the queue without erasing it
	if (data == NULL)
		MyError::error("Error - The memory hasn't been allocated, the queue is empty.");
	return (data->value);
}

template <typename ElemType>
std::string Queue<ElemType>::toString() {
	queueT *curr = data;
	std::string str;
	for (curr = data; curr!=NULL; curr=curr->next)
		str += curr->value.toString() + " ";
	return (str);
}

template <typename ElemType>
void erase(queueT<ElemType> *curr) {
	if (curr == NULL)
		return;
	erase(curr->next);
	delete(curr);
	curr=NULL;
}

template <typename ElemType>
Queue<ElemType>::~Queue() {
	erase(data);
	data=NULL;
}

#endif
