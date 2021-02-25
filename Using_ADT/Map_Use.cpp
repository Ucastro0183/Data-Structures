/*
 * Map_Use.cpp
 *
 *  Created on: Jun 30, 2014
 *      Author: ucastro
 */

#include "Map_Use.h"
#include "Map.h"
#include <fstream>
#include <iostream>
using namespace std;

void readFile(ifstream &in, Map<int> &m);
void mostRepeated(Map<int> &m);

map_use::map_use() {
	Map<int> count;
	ifstream in("note.txt");
	readFile(in, count);
	cout << "Number of unique words: " << count.size();
	mostRepeated(count);
}

void readFile(ifstream &in, Map<int> &m) {
	while (true) {
		string word;
		in >> word;
		if (in.fail()) break;
		if (m.containsKey(word)) {
			m[word] += 1;		//Access through brackets: m.add(word, (m.getValue(word)+1) );
		} else {
			m[word] =1;			//Access through brackets: m.add(word, 1);
		}
	}
}

void mostRepeated(Map<int> &max) {
	string word, maxWord;
	int maxCount = 0;

	Map<int>::Iterator itr = max.interator();
	while (itr.hasNext()) {
		word = itr.next();
		if (max[word] > maxCount) {
			maxWord = word;
			maxCount = max[word];
		}
	}

	cout << "the word most repeated is: " << maxWord << ", with " << maxCount << "repetitions";
}

