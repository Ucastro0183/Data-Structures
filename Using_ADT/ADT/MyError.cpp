/*
 * MyError.cpp
 *
 *  Created on: Jul 18, 2014
 *      Author: ucastro
 */

#include "MyError.h"		//Header
#include <stdexcept>		//Library for exceptions
#include <iostream>			//Library for console error printing

void MyError::error(string prompt) {
	try {
		throw out_of_range(prompt);
	} catch (exception &e) {
		cerr << e.what() << endl;	//Console printing of the error
		throw;						//Commonly named re-throw
	}
}
