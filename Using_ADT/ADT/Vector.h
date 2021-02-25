/*
 * Vector.h
 *
 *  Created on: Jun 27, 2014
 *      Author: ucastro
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include <string>

template <typename ElemType>
class Vector {
public:
	Vector();
	virtual ~Vector();

	int size();
	bool isEmpty();

	ElemType getAt(int index);
	void setAt(int index, ElemType value);

	void add(ElemType value);
	void insertAt(int pos, ElemType value);
	void removeAt(int pos);

	ElemType operator[](int n);
	Vector<ElemType> operator=(Vector<ElemType> otherVector);	//overrides equals operator =

	std::string toString();

private:

	ElemType *data;
	int dim, numAlloc;

	void addSpace();

};

#include "Vector.cpp"	//Only for templated classes

#endif /* VECTOR_H_ */
