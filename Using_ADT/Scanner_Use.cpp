/*
 * Scanner_Use.cpp
 *
 *  Created on: Jun 27, 2014
 *      Author: ucastro
 */

#include "Scanner_Use.h"
#include "Scanner.h"
#include <string>
#include <iostream>
using namespace std;


scanner_use::scanner_use() {
	Scanner scanner;
	string line;
	cout << "please enter a sentence: " << endl;
	cin >> line;
	scanner.setInput(line);
	int count = 0;
	while (scanner.hasMoreTokens()) {
		scanner.nextToken();
		cout++;
	}
	cout << "You entered " << count << " tokens." << endl;
}


