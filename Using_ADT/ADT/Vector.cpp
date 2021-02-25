/*
 * Vector.cpp
 *
 *  Created on: Jun 27, 2014
 *      Author: ucastro
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

#ifndef VECTOR_H_

#include "Vector.h"			//Header
#include "MyError.h"		//Library for error handling

using namespace std;

const int DEF_ALLOC = 10; //Default allocation size;

template <typename ElemType>
Vector<ElemType>::Vector() {
	this->data = new ElemType[DEF_ALLOC];
	this->numAlloc = DEF_ALLOC;
	this->dim = 0;
}

template <typename ElemType>
int Vector<ElemType>::size() {
	return (this->dim);
}

template <typename ElemType>
bool Vector<ElemType>::isEmpty() {
	return (this->dim == 0 ? true : false);
}

template <typename ElemType>
ElemType Vector<ElemType>::getAt(int index) {
	if (index >= this->dim)
		MyError::error("Wrong index assignment, value hasn't been initialized");
	return (data[index]);
}

template <typename ElemType>
void Vector<ElemType>::setAt(int index, ElemType value) {
	if (index >= this->dim)
		MyError::error("Wrong index assignment, value hasn't been initialized");
	data[index] = value;
}

/* Private Method, has to be declared in the private section
 * in order to use the keyword this and access the instance
 * variables numAlloc & dim. *
 */
template <typename ElemType>
void Vector<ElemType>::addSpace() {
	this->numAlloc += DEF_ALLOC;
	ElemType *temp = new ElemType[this->numAlloc];
	for (int i=0; i<this->dim; i++)
		temp[i] = data [i];
	delete[] data;
	data = temp;
}

template <typename ElemType>
void Vector<ElemType>::add(ElemType value) {
	if (this->dim == this->numAlloc)
		addSpace();
	data[this->dim] = value;
	this->dim += 1;
}

template <typename ElemType>
void Vector<ElemType>::insertAt(int pos, ElemType value) {
	if (pos >= this->dim)
		MyError::error("Wrong index assignment, memory hasn't been allocated");
	if (this->dim == this->numAlloc)
		addSpace();
	for (int i=this->dim; i<=pos; i--)
		data[i+1] = data[i];
	data[pos]=value;
	this->dim += 1;
}

template <typename ElemType>
void Vector<ElemType>::removeAt(int pos) {
	if (pos >= this->dim)
		MyError::error("Wrong index assignment, memory hasn't been allocated");
	this->dim -= 1;
	for (int i=pos; i<this->dim; i++)
		data[i] = data[i+1];
}

template <typename ElemType>
ElemType Vector<ElemType>::operator[](int n) {
	return (this->getAt(n));
}

template <typename ElemType>
Vector<ElemType> Vector<ElemType>::operator=(Vector<ElemType> otherVector) {
	while (this->dim != 0) {
		this->removeAt(0);
	}
	for (int i=0; i<otherVector.size(); i++)
		this->add(otherVector[i]);
}

template <typename ElemType>
string Vector<ElemType>::toString() {
	string str = "[ ";
	for (int i=0; i<this->dim; i++)
		str+= data[i].toString() + " ";
	str += "]";
	return (str);
}

template <typename ElemType>
Vector<ElemType>::~Vector() {
	delete[] this->data;
	this->dim = 0;			// <-- Not necessary, deallocated when Vector is out-of-scope.
}

#endif
