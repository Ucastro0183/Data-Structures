/*
 * UsingADT.cpp
 *
 *  Created on: Jul 4, 2014
 *      Author: ucastro
 */

#include <iostream>
#include "stdio.h"
using namespace std;

#include "Grid_Use.h"
#include "Map_Use.h"
#include "Queue_Use.h"
#include "Scanner_Use.h"
#include "Set_Use.h"
#include "Stack_Use.h"
#include "Vector_Use.h"

int main() {
	cout << "Select an option:" << endl <<
			"0.- Exit" << endl <<
			"1.- Grid_Use.cpp" << endl <<
			"2.- Map_Use.cpp" << endl <<
			"3.- Queue_Use.cpp" << endl <<
			"4.- Scanner_Use.cpp" << endl <<
			"5.- Set_Use.cpp" << endl <<
			"6.- Stack_Use.cpp" << endl <<
			"7.- Vector_Use.cpp" << endl ;
	while (true) {
		cout << endl << "? ";
		int choice;
		scanf("%d", &choice);
		switch (choice) {
		case 0:
			break;
		case 1: grid_use();
			break;
		case 2: map_use();
			break;
		case 3: queue_use();
			break;
		case 4: scanner_use();
			break;
		case 5: set_use();
			break;
		case 6: stack_use();
			break;
		case 7: vector_use();
			break;
		default:
			cout << "Bad choice, please select again.";
		}
		if (choice == 0) break;
	}
	return (0);
}


