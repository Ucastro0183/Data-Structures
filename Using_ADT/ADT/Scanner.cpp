/*
 * Scanner.cpp
 *
 *  Created on: Jun 27, 2014
 *      Author: ucastro
 */

#include "Scanner.h"		//Header
#include <stdlib.h>			//Library for NULL values
#include <stdexcept>		//Library for exceptions
#include <iostream>			//Library for console error printing

using namespace std;

struct words{
	string word;
	words *next;
};

words *data;

void error(string prompt){
	try {
		throw out_of_range(prompt);
	} catch (exception &e) {
		cerr << e.what() << endl;	//Console printing of the error
		throw;						//Commonly named re-throw
	}
}

Scanner::Scanner() {
	data = NULL;
	this->spaceOp = PreserveSpaces;
}

void Scanner::setInput(string str){
	words * curr;
	curr = new words;
	data = curr;
	curr->next = NULL;
	curr->word = "";
	for (unsigned int i=0; i<str.length(); i++) {
		if (!isspace(str[i])) {
			curr->word += str[i];
		} else if (curr->word != "") {
			if (spaceOp == PreserveSpaces)
				curr->word += str[i];
			curr = curr->next;
			curr->next = NULL;
			curr->word = "";
		}
	}
}

string Scanner::nextToken(){
	if (data == NULL)
		error("The scanner is empty, no memory allocated");
	string word = data->word;
	data = data->next;
	return (word);
}

bool Scanner::hasMoreTokens(){
	return (data == NULL ? false : true);
}

void Scanner::setSpaceOption(Scanner::spaceOptionT option){
	this->spaceOp = option;
}

typename Scanner::spaceOptionT Scanner::getSpaceOption(){
	return (this->spaceOp);
}

string Scanner::toString() {
	string str = "";
	for (words* curr = data; curr!=NULL; curr=curr->next)
		str += curr->word + " ";
	return (str);
}

void erase(words *list) {
	if (list == NULL)
		return;
	erase (list->next);
	delete (list);
	list = NULL;
}

Scanner::~Scanner() {
	erase(data);
}
