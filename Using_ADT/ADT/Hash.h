/*
 * Hash.h
 *
 * Hash data structure considers putting each element in a predefined bucket
 * so each time is required to access an object the hash function will compute
 * the exact place where this object shall be found.
 *
 * By this searches will be the most efficient as each element will have only
 * one possible place to be found.
 *
 *  Created on: Aug 29, 2014
 *      Author: ucastro
 */

#ifndef HASHMAP_H_
#define HASHMAP_H_

#include <string>

template <typename ElemType>
class HashMap {
public:
	HashMap();
	virtual ~HashMap();

	int size();
	bool isEmpty();

	void addValue(std::string key, ElemType value);
	ElemType getValue(std::string key);

private:
	struct cellT{
		std::string key;
		ElemType value;
		cellT *next;
	};

	cellT* data[];
	int dim;

	int fnHash(std::string key);
	void resizeMap();
};

#include "Hash.cpp"

#endif /* HASH_H_ */
