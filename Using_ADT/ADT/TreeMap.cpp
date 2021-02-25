/*
 * TreeMap.cpp
 *
 *  Created on: Aug 12, 2014
 *      Author: ucastro
 */

#include "TreeMap.h"
#include "MyError.h"
#include <stdlib.h>

#ifndef TREEMAP_H_

template <typename ElemType>
TreeMap<ElemType>::TreeMap() {
	data = NULL;
	dim = 0;
}

template <typename ElemType>
int TreeMap<ElemType>::size() {
	return (dim);
}

template <typename ElemType>
bool TreeMap<ElemType>::isEmpty() {
	return (dim == 0);
}

template <typename ElemType>
void TreeMap<ElemType>::add(std::string key, ElemType value) {
	treeT *node = searchNode (data, key);
	if (node == NULL) {
		treeT *n = new treeT;
		n->key = key;
		n->value = value;
		n->left = n->right = NULL;
		node = n;
		dim++;
	} else {
		node->value = value;
	}
}

template <typename ElemType>
typename TreeMap<ElemType>::treeT *TreeMap<ElemType>::searchNode(treeT *&root, std::string key) {
	if (root == NULL)
		return (root);
	if (root->key == key)
		return (root);
	if (root->key > key)
		return (searchNode(root->left,key));
	else
		return (searchNode(root->right,key));
}

template <typename ElemType>
ElemType TreeMap<ElemType>::getValue(std::string key) {
	treeT *node = searchNode(data, key);
	if (node == NULL)
		error("The key: \"" + key + "\", is not defined in the map");
	else
		return (node->value);
}

template <typename ElemType>
bool TreeMap<ElemType>::containsKey(std::string key) {
	return (searchNode(data, key) != NULL);
}

template <typename ElemType>
void TreeMap<ElemType>::remove(std::string key) {
	//TODO remove node
}

template <typename ElemType>
struct TreeMap<ElemType>::Iterator {
	treeT *curr;

	Iterator(treeT *data) {
		// TODO It is required to copy the data into curr, otherwise will modify the
		//      real data of MyTree when popping out with next.
		curr = data;
	}

	bool hasNext() {
		return (curr == NULL ? false : true);
	}

	treeT *searchNext(treeT *&node) {
		if (node->left == NULL)
			return (node);
		else
			return (searchNext(node->left));
	}

	ElemType next() {
		treeT *old = searchNext(curr);
		ElemType value = old->value;
		old = old->right;
		return (value);
	}

};

template <typename ElemType>
typename TreeMap<ElemType>::Iterator TreeMap<ElemType>::iterator() {
	TreeMap<ElemType>::Iterator *it = new Iterator(data);
	return (*it);
}

template <typename ElemType>
std::string toStr(typename TreeMap<ElemType>::treeT *list) {
	if (list == NULL)
		return ("");
	std::string str = toStr(list->left);
	str += list->key + ": " + list->value.toString() + '/n';
	str += toStr(list->right);
	return (str);
}

template <typename ElemType>
std::string TreeMap<ElemType>::toString() {
	std::string str = toStr(data);
	return (str);
}

template <typename ElemType>
void erase(typename TreeMap<ElemType>::treeT *list) {
	if (list == NULL)
		return;
	erase(list->left);
	erase(list->right);
	delete list;
	list = NULL;
}

template <typename ElemType>
TreeMap<ElemType>::~TreeMap() {
	erase(data);
}

#endif /* TREEMAP_H_ */
