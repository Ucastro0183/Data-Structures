/*
 * Hash.cpp
 *
 *  Created on: Aug 29, 2014
 *      Author: ucastro
 */

#include "Hash.h"
#include "MyError.h"
#include <stdlib.h>

#ifndef HASHMAP_H_

const int BASE_DIM = 10;
int NO_CELLS;

template <typename ElemType>
HashMap<ElemType>::HashMap() {
	NO_CELLS = BASE_DIM;
	cellT* new_data[NO_CELLS];
	for (int i = 0; i<NO_CELLS; i++) {
		new_data[i]=NULL;
	}
	data=new_data;		//TODO Checkout this assignment
	dim=0;
}

template <typename ElemType>
int HashMap<ElemType>::size() {
	return (dim);
}

template <typename ElemType>
bool HashMap<ElemType>::isEmpty() {
	return (dim==0);
}

template <typename ElemType>
void HashMap<ElemType>::resizeMap() {
	int old_size = NO_CELLS;
	NO_CELLS += BASE_DIM;
	cellT* new_data[] = new cellT[NO_CELLS];
	for (int i=0; i<old_size; i++)
		for (cellT *cell=data[i]; cell !=NULL; cell = cell->next) {
			new_data[fnHash(cell->key)] = cell;
		}
	data = new_data;  //TODO Check this assignment
}

template <typename ElemType>
void HashMap<ElemType>::addValue(std::string key, ElemType value) {
	cellT* n = new cellT;
	n->key = key;
	n->value = value;
	n->value = data[fnHash(key)];
	data[fnHash(key)] = n;
	dim++;
	if (dim == NO_CELLS) resizeMap();
}

const int MULTIP_HASH = -1664117991L;

template <typename ElemType>
int HashMap<ElemType>::fnHash(std::string key) {
	unsigned long code = 0;
	for (int i=0; i<key.length(); i++) {
		code = code * MULTIP_HASH + key[i];
	}
	return (code % NO_CELLS);
}

template <typename ElemType>
ElemType HashMap<ElemType>::getValue(std::string key) {
	int index = fnHash(key);
	ElemType value = NULL;
	for (cellT *cell = data[index]; cell != NULL; cell = cell->next) {
		if (cell->key == key) {
			return (cell->value);
		}
	}
	error("The key: \""+key+"\", has not been defined in the HashMap.");
	return (value);
}

template <typename ElemType>
void eraseCell(typename HashMap<ElemType>::cellT *cell) {
	if (cell == NULL) return;
	eraseCell(cell->next);
	delete cell;
	cell = NULL;
}

template <typename ElemType>
HashMap<ElemType>::~HashMap() {
	for (int i=0; i<NO_CELLS; i++) {
		eraseCell(data[i]);
	}
	delete [] data;
}

#endif /* HASHMAP_H_ */
