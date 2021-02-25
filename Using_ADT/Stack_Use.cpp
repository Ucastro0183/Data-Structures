/*
 * Stack1_Use.cpp
 *
 *  Created on: 29/06/2014
 *      Author: Ulises
 */

#include "Stack.h"
#include <iostream>
#include "stdio.h"
using namespace std;

void reverseString(string line);

stack_use::stack_use() {
	cout << "Please enter a line: " << endl;
	string line;
	getline(cin, line);
	reverseString(line);
}

void reverseString(string line) {
	cout << "The reverse line is: " << endl;
	Stack<char> stack;
	for (int i=0; i<line.length(); i++)
		stack.push(line[i]);
	while (!stack.isEmpty()) {
		cout << stack.pop();
	}
}
