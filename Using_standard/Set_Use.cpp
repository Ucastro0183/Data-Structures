/*
 * Set_Use.cpp
 *
 *  Created on: Jun 30, 2014
 *      Author: ucastro
 */

#include "Set_Use.h"
#include "set"
#include <iostream>
#include "stdlib.h"		//Library for rand()
using namespace std;

void testRandom();

set_use::set_use() {
	testRandom();
}

void testRandom() {
	set<int> numbs;
	while (true) {
		int num = rand() % 100 +1; // random number between 1 & 100.
		if (numbs.count(num)>0) break;
		numbs.insert(num);
	}
	cout << numbs.size() << " numbers where created before a repetition was found" << endl << endl;

	cout << "The set contains: " << endl;

	set<int>::iterator itr = numbs.begin();
	while (itr != numbs.end()) {
		cout << *itr;
		itr++;
		if (itr != numbs.end()) cout <<", ";
		else cout <<".";
	}
}



