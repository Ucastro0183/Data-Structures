/*
 * Queue_Use.cpp
 *
 *  Created on: 29/06/2014
 *      Author: Ulises
 */

#include "Queue_Use.h"
#include "Queue.h"
#include <iostream>
using namespace std;

void intro();

queue_use::queue_use() {
	intro();

	Queue<string> q;
	string response;
	while (true) {
		cout << "? " ;
		getline(cin,response);
		if (response == "next") {
			if (!q.isEmpty()) {
				cout <<	q.dequeue() << endl;
			} else {
				cout << " -- line is empty -- " << endl;
			}
		} else if (response == "end") {
			break;
		} else {
			q.enqueue(response);
		}
	}
}

void intro() {
	cout << "This program takes any number of lines and retrieves them "<< endl;
	cout << "one by one whens the keyword \"next\" is entered." << endl;
	cout << "Enter \"end\" to finish the program." << endl << endl;
}
