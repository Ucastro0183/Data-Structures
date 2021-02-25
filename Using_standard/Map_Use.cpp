/*
 * Map_Use.cpp
 *
 *  Created on: Jun 30, 2014
 *      Author: ucastro
 */

#include "Map_Use.h"
#include "map"
#include <fstream>
#include <iostream>
using namespace std;

void readFile(ifstream &in, map<string,int> &m);
void mostRepeated(map<string,int> &m);

map_use::map_use() {
	map<string, int> count;
	ifstream in("note.txt");
	readFile(in, count);
	cout << "Number of unique words: " << count.size();
	mostRepeated(count);
}

void readFile(ifstream &in, map<string,int> &m) {
	while (true) {
		string word;
		in >> word;
		if (in.fail()) break;
		if (m.count(word)>0) {
			m[word] += 1;		//Access through brackets: m.insert(std::pair<string,int>(word, m.at(word)) );
		} else {
			m[word] =1;			//Access through brackets: m.insert(std::pair<string,int>(word, 1));
		}
	}
}

void mostRepeated(map<string,int> &max) {
	string word, maxWord;
	int maxCount = 0;

	map<string,int>::iterator itr = max.begin();	//map.begin() allocates the iterator of the map
	while (itr != max.end()) {						//map end correspond to the last item of the map
		word = itr->first;				//the field first in a iterator of map correspond to the key of that item
		if (itr->second > maxCount) {
			maxWord = word;
			maxCount = itr->second;		//the field second in a iterator of map correspond to the value of the mapped item
		}
	}

	cout << "the word most repeated is: " << maxWord << ", with " << maxCount << "repetitions";
}

