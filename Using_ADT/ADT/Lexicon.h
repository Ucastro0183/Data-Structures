/*
 * Lexicon.h
 *
 *  Created on: Sep 3, 2014
 *      Author: ucastro
 */

#ifndef LEXICON_H_
#define LEXICON_H_

#include <string>

class Lexicon {
public:
	Lexicon();
	virtual ~Lexicon();

	void addWord(std::string word);
	bool containsWord(std::string word);
	bool conainsPrefix(std::string word);

private:
	struct digit {
		char ch;
		digit* next[27];
	};

	static const int DIM_ARR = 27; // 26 digits plus \n for marking final words
	digit* root;

	void addWord(std::string word, digit* &root);
	bool containsWord(std::string word, digit* &root);
	bool conainsPrefix(std::string word, digit* &root);
	void erase(digit* &root);
};

#endif /* LEXICON_H_ */
