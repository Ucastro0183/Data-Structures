/*
 * Map.cpp
 *
 *  Created on: Jun 30, 2014
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
#include "Map.h"			//Header

#ifndef MAP_H_

#include <stdlib.h>			//Library for NULL values
#include "MyError.h"		//Library for error handling

using namespace std;

template <typename ElemType>
struct mapT{
	string key;
	ElemType value;
	mapT *next;
};

template <typename ElemType>
Map<ElemType>::Map() {
	//data = new  map<ElemType>;
	data = NULL;
	this->dim = 0;
}

template <typename ElemType>
int Map<ElemType>::size() {
	return (this->dim);
}

template <typename ElemType>
bool Map<ElemType>::isEmpty() {
	return (this->dim == 0);
}

template <typename ElemType>
void Map<ElemType>::add(string key, ElemType value) {
	mapT *curr;
	curr = data;
	mapT *n;
	n = new mapT;
	n->key = key;
	n->value = value;
	n->next = NULL;
	if (curr == NULL) {
		data = n;
	} else if (curr->key > key) {
		n->next = curr;
		data = n;
	} else {
		mapT *prev;
		prev = curr;
		for (curr = curr->next; curr!=NULL; curr=curr->next ) {
			if (curr->key == key) {
				curr->value = value;
				this->dim -= 1;
				break;
			} else if (curr->key > key) {
				n->next = curr;
				prev->next = n;
				break;
			}
			prev = curr;
		}
		if (curr == NULL) {
			prev->next = n;
		}
	}
	this->dim += 1;
}

template <typename ElemType>
void Map<ElemType>::remove(string key) {
	mapT *curr;
	curr = data;
	if (this->containsKey(key) == false)
		MyError::error("Bad Argument - the item doesn't exist");
	if (curr->key == key) {
		data = curr->next;
		this->dim -= 1 ;
		delete (curr);
		return;
	}
	mapT *prev;
	prev = curr;
	for (curr=curr->next ; curr!=NULL && curr->key<=key; curr=curr->next) {
		if (curr->key == key) {
			prev->next = curr->next;
			delete (curr);
			curr = prev->next;
			this->dim -= 1;
		}
		prev = curr;
	}

}

template <typename ElemType>
bool Map<ElemType>::containsKey(string key) {
	mapT *curr;
	curr = data;
	if (curr == NULL) return(false);
	if (curr->key == key) return (true);
	for (curr=data ; curr!=NULL && curr->key<=key; curr=curr->next)
		if (curr->key == key) return (true);
	return (false);
}

template <typename ElemType>
ElemType Map<ElemType>::getValue(string key) {
	mapT *curr;
	curr = data;
	if (this->containsKey(key) == false)
		MyError::error("Bad Argument - the item doesn't exist");
	if (curr->key == key) return (curr->value);
	for (curr=data ; curr!=NULL && curr->key<=key; curr=curr->next)
		if (curr->key == key)
			return (curr->value);
	return (NULL);
}

/*
 * Iterator operations
 */
template <typename ElemType>
struct Map<ElemType>::Iterator {
	mapT *curr;

	Iterator(data) {
		curr = data;
	}

	bool hasNext() {
		return (curr == NULL ? false : true);
	}

	ElemType next() {
		ElemType val = curr->value;
		curr = curr->next;
		return (val);
	}

};

template <typename ElemType>
typename Map<ElemType>::Iterator Map<ElemType>::iterator() {
	Iterator *it = new (Iterator);
	return (*it);
}

template <typename ElemType>
void erase(mapT<ElemType> *curr) {
	if (curr == NULL)
		return;
	erase(curr->next);
	delete(curr);
	curr = NULL;
}

template <typename ElemType>
string Map<ElemType>::toString() {
	string str = "";
	mapT *curr = data;
	for(curr = data; curr!=NULL; curr=curr->next) {
		str += curr->key;
		str += ": " ;
		str += curr->value.toString() + '/n';
	}
	return (str);
}

template <typename ElemType>
Map<ElemType>::~Map() {
	erase(data);
	data = NULL;
}

#endif
