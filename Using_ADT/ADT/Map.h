/*
 * Map.h
 *
 *  Created on: Jun 30, 2014
 *      Author: ucastro
 */

#ifndef MAP_H_
#define MAP_H_

#include <string>
using namespace std;

template <typename ElemType>
class Map {
public:
	Map();
	virtual ~Map();

	int size();
	bool isEmpty();

	//The key of the Map should be a string
	//Allows the use of brackets to retrieve a value
	void add(string key, ElemType value);
	void remove(string key);

	bool containsKey(string key);
	ElemType getValue(string key); //Throws an error if the key doesn't exist.

	struct Iterator {

		bool hasNext();
		string next();

	}; /* Class Iterator */

	Iterator iterator();

	ElemType operator[](string n) {
			return (this->getValue(n));
		}

	string toString();

private:
	int dim;

	struct mapT{
		string key;
		ElemType value;
		mapT *next;
	};

	mapT *data;

}; /* Class Map */

#include "Map.cpp"		//Only for template classes

#endif /* MAP_H_ */
