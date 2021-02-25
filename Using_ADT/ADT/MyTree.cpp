/*
 * Tree.cpp
 *
 * This data management structure store the data in a tree like
 * list where searching for a value is made by binary search, this is
 * why it's called binary tree. Each value is located ordered at the
 * left or right pointer of the previous value.
 *
 * It isn't very helpful when the data is entered already ordered.
 *
 *  Created on: Jul 28, 2014
 *      Author: ucastro
 */

#include "MyTree.h"
#include "MyError.h"
#include <stdlib.h>

#ifndef TREE_H_

/* This is the constructor of the class
 *
 */
template <typename ElemType>
int MyTree<ElemType>::operatorCmp(ElemType one, ElemType two) {
	if (one == two) return (0);
		else if (one < two) return (-1);
			else return (1);
}

template <typename ElemType>
MyTree<ElemType>::MyTree(int (*cmpFn)(ElemType , ElemType )) {
	// Pass cmpFn to instance
	cmp = cmpFn;
	data = NULL;
	numCells = 0;
	return (this);
}

template <typename ElemType>
int MyTree<ElemType>::size() {
	return (numCells);
}

template <typename ElemType>
bool MyTree<ElemType>::isEmpty() {
	return (numCells == 0);
}

template <typename ElemType>
void MyTree<ElemType>::add(ElemType value) {
	if (this->contains(value))
		return;
	cell *n = getPtr(data,value);
	// n will always be a NULL pointer, else contains(value) would be true
	n->value = value;
	n->left = n->right = NULL;
	numCells++;
}

// TODO check out this method!!!
template <typename ElemType>
void removeCell(typename MyTree<ElemType>::cell *&root, ElemType value) {
	if (cmp(root->value,value)==0) {
		typename MyTree<ElemType>::cell *old = root;
		root = NULL;
		//addTree(old->left);
		//addTree(old->right);
	}
	if (cmp(root->value,value) > 0) {
		removeCell(root->right,value);
	} else {
		removeCell(root->left,value);
	}
}

template <typename ElemType>
void MyTree<ElemType>::remove(ElemType value) {
	if (!contains(value))
		error("Value entered is not located in the tree: "+this);
	removeCell(data, value);
	numCells--;
}

template <typename ElemType>
typename MyTree<ElemType>::cell *getPtr(typename MyTree<ElemType>::cell *&node, ElemType &value) {
	if (node == NULL)
		return (node);
	if (cmp(node->value,value)==0)
		return (node);
	if (cmp(node->value,value)<0)
		return (getPtr(node->left, value));
	else
		return(getPtr(node->right, value));
}

template <typename ElemType>
bool MyTree<ElemType>::contains(ElemType value) {
	if (getPtr(data,value)==NULL)
		return (false);
	else
		return(true);
}

// TODO Fix the implementation of the Iterator
template <typename ElemType>
struct MyTree<ElemType>::Iterator {
	cell *curr, *itData;
	int (*cmp)(ElemType, ElemType);

	void Iterator(MyTree<ElemType>::cell *data, int (*fnCmp)(ElemType, ElemType)) {
		//XXX It is required to copy the data into itData ?
		itData = data;
		for (curr = itData; curr->left != NULL; )
			curr = curr->left;
	}

	bool hasNext() {
		return (curr == NULL);
	}

	cell *getNext(cell *list) {
		cell *old = NULL;
		if (list->left == curr) {
			old = list;
			list = list->right;
		} else {
			return (getNext(list->left));
		}
		return (old);
	}

	ElemType next() {
		return(getNext(curr)->value);
	}
};

template <typename ElemType>
MyTree<ElemType>::Iterator MyTree<ElemType>::iterator() {
	MyTree<ElemType>::Iterator *it = new Iterator(data);
	return (*it);
}

template <typename ElemType>
std::string toStr(typename MyTree<ElemType>::cell *&root) {
	std::string str = toStr(root->left);
	str += root->value.toString() + " ";
	str += toStr(root->right);
	return (str);
}

template <typename ElemType>
std::string MyTree<ElemType>::toString() {
	std::string str = "[ " + toStr(data) + "]";
	return (str);
}

template <typename ElemType>
void eraseCell(typename MyTree<ElemType>::cell* list) {
	if (list == NULL)
		return;
	eraseCell(list->left);
	eraseCell(list->right);
	delete list;
	list = NULL;
}

template <typename ElemType>
MyTree<ElemType>::~MyTree() {
	eraseCell(data);
}

#endif /* TREE_H_ */
