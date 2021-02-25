/*
 * TreeMap.h
 *
 *  Created on: Aug 12, 2014
 *      Author: ucastro
 */

#ifndef TREEMAP_H_
#define TREEMAP_H_

#include <string>

template <typename ElemType>
class TreeMap {
public:
	TreeMap();
	virtual ~TreeMap();

	int size();
	bool isEmpty();

	void add(std::string key, ElemType value);
	ElemType getValue(std::string key);
	bool containsKey(std::string key);
	void remove(std::string key);

	struct Iterator {
		bool hasNext();
		ElemType next();
	};

	Iterator iterator();

	std::string toString();

private:
	struct treeT {
		std::string key;
		ElemType value;
		treeT *left, *right;
	};

	treeT *data;
	int dim;

	treeT *searchNode(treeT *&root, std::string key);

};

#endif /* TREEMAP_H_ */
