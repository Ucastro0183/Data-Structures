/*
 * Set.h
 *
 *  Created on: Jun 30, 2014
 *      Author: ucastro
 */

#ifndef SET_H_
#define SET_H_

#include <string>

template <typename ElemType>

class Set {
private:
	int *operatorCmp(ElemType one, ElemType two);
public:
	Set(int (*cmpFn)(ElemType, ElemType) = operatorCmp);
	virtual ~Set();

	int size();
	int isEmpty();

	void add(ElemType value);		// add avoid duplications, if the element exist it won't duplicate it
	void remove(ElemType value);	// removes an element if exist in the set
	bool contains(ElemType value);	// checks if some given element exist in the set

	bool equals(Set &otherSet);
	bool isSubsetOf(Set &otherSet);

	void unionWith(Set &otherSet);
	void intersect(Set &otherSet);
	void substract(Set &otherSet);

	struct Iterator {

		bool hasNext();
		ElemType next();
	};

	Iterator iterator();

	std::string toString();

	/*
	 * NOTE:
	 *
	 * Sets tent to storage date in a sorted way in order
	 * to maximize efficiency.
	 *
	 */
private:
	int dim;

	struct list {
		ElemType value;
		list *next;
	};

	list *data;
	int (*cmp)(ElemType, ElemType);

};

#include "Set.cpp"		//Only for template classes

#endif /* SET_H_ */
