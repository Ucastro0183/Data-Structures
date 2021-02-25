/*
 * Queue.h
 *
 *  Created on: 29/06/2014
 *      Author: Ulises
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <string>

template <typename ElemType>
class Queue {
public:
	Queue();
	virtual ~Queue();

	int size();
	bool isEmpty();

	void enqueue(ElemType value);	//push an element to the queue
	ElemType dequeue();				//Gets an element from the queue
	ElemType peek();				//Gets the top most element from the queue without erasing it

	std::string toString();

private:
	int dim;

	struct queueT {
		ElemType value;
		queueT *next;
	};

	queueT *tail;
	queueT *data;

};

#include "Queue.cpp"			//Only for template classes.

#endif /* QUEUE_H_ */
