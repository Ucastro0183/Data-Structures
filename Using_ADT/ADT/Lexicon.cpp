/*
 * Lexicon.cpp
 *
 *  Created on: Sep 3, 2014
 *      Author: ucastro
 */

#include "Lexicon.h"
#include <stdio.h>

Lexicon::Lexicon() {
	root = new digit;
	root->ch = ' ';
	for (int i=0; i<DIM_ARR; i++)
		root->next[i] = NULL;
}

void Lexicon::addWord(std::string word) {
	addWord(word,root->next[word[0]-'A']);
}

void Lexicon::addWord(std::string word, digit* &root) {
	if (root == NULL) {
		root = new digit;
		root->ch = ' ';
		for (int i=0; i<DIM_ARR; i++)
			root->next[i] = NULL;
	}
	if (word.length() == 0) {
		root->ch='\n';
		return;
	}
	if (root->ch==' ')
		root->ch = word[0];
	word = word.length()>1 ? word.substr(1) : "";
	addWord(word, (word=="" ? root->next[26] : root->next[word[0]-'A']) );
}

bool Lexicon::containsWord(std::string word) {
	return (containsWord(word,root->next[word[0]-'A']));
}

bool Lexicon::containsWord(std::string word, digit* &root) {
	if (word=="" && root!=NULL)
		return (true);
	if (root==NULL)
		return (false);
	word = word.length()>1 ? word.substr(1) : "";
	return (containsWord(word, (word=="" ? root->next[26] : root->next[word[0]-'A'])));
}

bool Lexicon::conainsPrefix(std::string word) {
	return (conainsPrefix(word,root->next[word[0]-'A']));
}

bool Lexicon::conainsPrefix(std::string word, digit* &root) {
	if (word=="")
		return (true);
	if (root==NULL)
		return (false);
	word = word.length()>1 ? word.substr(1) : "";
	return (conainsPrefix(word, (word=="" ? root->next[26] : root->next[word[0]-'A'])));
}

void Lexicon::erase(digit* &root) {
	if (root == NULL) return;
	for (int i=0; i<DIM_ARR; i++)
		erase(root->next[i]);
	delete root;
}

Lexicon::~Lexicon() {
	erase(root);// TODO Auto-generated destructor stub
}

