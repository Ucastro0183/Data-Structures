/*
 * Queue_Use.cpp
 *
 *  Created on: 29/06/2014
 *      Author: Ulises
 */

#include "Queue_Use.h"
#include "queue"
#include <iostream>
using namespace std;

void intro();

queue_use::queue_use() {
	intro();

	queue<string> q;
	string response;
	while (true) {
		cout << "? " ;
		getline(cin,response);
		if (response == "\r") {
			if (!q.empty()) {
				cout <<	q.front() << endl;
				q.pop();
			} else {
				cout << " -- line is empty -- " << endl;
			}
		} else if (response == ".") {
			break;
		} else {
			q.push(response);
		}
	}
}

void intro() {
	cout << "This program takes any number of lines and retrieves them "<< endl;
	cout << "one by one whens the keyword \"next\" is entered." << endl;
	cout << "Enter \"end\" to finish the program." << endl << endl;
}
