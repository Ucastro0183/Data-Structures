/*
 * Set.cpp
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

#ifndef SET_H_

#include "Set.h"			//Header
#include <stdlib.h>			//Library for NULL values
#include "MyError.h"		//Library for error handling

using namespace std;

template <typename ElemType>
struct list {
	ElemType value;
	list *next;
};

template <typename ElemType>
int *Set<ElemType>::operatorCmp(ElemType one, ElemType two) {
		if (one == two) return (0);
		else if (one < two) return (-1);
		else return (1);
	};

template <typename ElemType>
Set<ElemType>::Set(int (*cmpFn)(ElemType, ElemType)) {
	// pass function to instance variable
	this->cmp = cmpFn;
	data = NULL;
	this->dim = 0;
}


template <typename ElemType>
int Set<ElemType>::size(){
	return (this->dim);
}

template <typename ElemType>
int Set<ElemType>::isEmpty(){
	return (this->dim == 0);
}

template <typename ElemType>
void Set<ElemType>::add(ElemType value){
	// add avoid duplications, if the element exist it won't duplicate it
	if (this->contains(value)) return;
	list *n;
	n = new list;
	n->value = value;
	n->next = NULL;
	list *prev, *curr;
	curr = data;
	if (curr == NULL) {
		data = n;
		this->dim += 1;
		return;
	}
	prev = NULL;
	while (cmp(curr->value,value)<1) {
		prev = curr;
		curr = curr->next;
		if (curr == NULL) break;
	}
	if (prev != NULL) {
		prev->next = n;
		n->next = curr;
	} else {
		n->next = data;
		data = n;
	}
	this->dim += 1;
}

template <typename ElemType>
void Set<ElemType>::remove(ElemType value){
	// removes an element if exist in the list
	if (this->contains(value) == false)
		MyError::error("Bad argument - The value hasn't been allocated.");
	list *curr;
	curr = data;
	if (cmp(curr->value, value) == 0) {
		data = curr->next;
		delete (curr);
		this->dim -= 1;
		return;
	}
	list *elim;
	elim = NULL;
	for (curr = data; curr!=NULL && cmp(curr->value,value)<=0; curr = curr->next)
		if (cmp((curr->next)->value, value) == 0) {
			elim = (curr->next);
			curr->next = elim->next;
			delete (elim);
		}
	this->dim -= 1;
}

template <typename ElemType>
bool Set<ElemType>::contains(ElemType value){
	// checks if some given element exist in the list
	list *curr;
	curr = data;
	for (curr = data; curr!=NULL && cmp(curr->value,value)<=0; curr=curr->next) {
		if (cmp(curr->value, value) == 0) return (true);
	}
	return (false);
}

template <typename ElemType>
bool Set<ElemType>::equals(Set &otherSet){
	if (otherSet.dim != this->dim) return (false);
	list *curr;
	curr = data;
	Set<ElemType>::Iterator it = otherSet.iterator();
	while (it.hasNext()) {
		if (this->contains(it.next()) == false)
			return (false);
	}
	return (true);
}

template <typename ElemType>
bool Set<ElemType>::isSubsetOf(Set &otherSet){
	list *curr;
	curr = data;
	for (curr = this; curr != NULL; curr=curr->next)
		if (otherSet.contains(curr->value) == false)
			return (false);
	return (true);
}

template <typename ElemType>
void Set<ElemType>::unionWith(Set &otherSet){
	Set<ElemType>::Iterator it = otherSet.iterator();
	while (it.hasNext()) {
		this->add(it.next());
	}
}

template <typename ElemType>
void Set<ElemType>::intersect(Set &otherSet){
	list *curr;
	for (curr = data; curr != NULL; curr)
		if (otherSet.contains(curr->value) == false) {
			ElemType value = curr->value;
			curr=curr->next;
			this->remove(value);
		} else curr=curr->next;
}

template <typename ElemType>
void Set<ElemType>::substract(Set<ElemType> &otherSet){
	Set<ElemType>::Iterator it = otherSet.iterator();
	while(it.hasNext()) {
		this->remove(it.next());
	}
}

template <typename ElemType>
typename Set<ElemType>::Iterator Set<ElemType>::iterator() {
	Set<ElemType>::Iterator *it = new (Set<ElemType>::Iterator);

	list *curr;
	curr = data;

	it->hasNext() = (curr); {
		return (curr == NULL);
	};

	it->next() = (curr); {
			ElemType value = curr->value;
			curr = curr->next;
			return (value);
	};

	return (*it);
}

template <typename ElemType>
string Set<ElemType>::toString() {
	string str = "";
	for(list *curr = data; curr != NULL; curr = curr->next)
		str += curr->value.toString() + "/n";
	return (str);
}

template <typename ElemType>
void erase(list<ElemType> *curr) {
	if (curr == NULL) return;
	erase(curr->next);
	delete(curr);
	curr = NULL;
}

template <typename ElemType>
Set<ElemType>::~Set() {
	erase(data);
}

#endif
