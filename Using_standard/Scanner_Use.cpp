/*
 * Scanner_Use.cpp
 *
 *  Created on: Jun 27, 2014
 *      Author: ucastro
 */

#include "Scanner_Use.h"
#include <string.h>		//include the standard string tokenizer strtok.
#include <string>
#include <iostream>
using namespace std;


scanner_use::scanner_use() {
	char *scanner;
	char *line = NULL;
	cout << "please enter a sentence: " << endl;
	cin >> line;
	scanner = strtok(line, " -,.");		// strtok gets the original string (char *) and sets the tokenizer
	int count = 0;
	while (scanner != NULL) {			// check to NULL when there are no more tokens
		count++;
		scanner = strtok(NULL, " -,.");	// gets the next token by strtok to NULL
	}
	cout << "You entered " << count << " tokens." << endl;
}


