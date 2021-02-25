/*
 * Set_Use.cpp
 *
 *  Created on: Jun 30, 2014
 *      Author: ucastro
 */

#include "Set.h"
#include <iostream>
#include "stdlib.h"		//Library for rand()
using namespace std;

void testRandom();

set_use::set_use() {
	testRandom();
}

void testRandom() {
	Set<int> numbs;
	while (true) {
		int num = rand() % 100 +1; // random number between 1 & 100.
		if (numbs.contains(num)) break;
		numbs.add(num);
	}
	cout << numbs.size() << " numbers where created before a repetition was found" << endl << endl;

	cout << "The set contains: " << endl;

	Set<int>::Iterator itr = numbs.iterator();
	while (itr.hasNext()) {
		cout << itr.next();
		if (itr.hasNext()) cout <<", ";
		else cout <<".";
	}
}



