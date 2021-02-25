/*
 * Vector_Use.cpp
 *
 *  Created on: Jun 27, 2014
 *      Author: ucastro
 */

#include "Vector_Use.h"
#include <vector>
#include <iostream>
#include "stdio.h"		//Library for printf("format",ivar)
#include "stdlib.h"		//Library for the rand() function
using namespace std;

vector<int> generateRandomVector(int size);
void printVector(vector<int> &vector);

vector_use::vector_use() {
	vector<int> nums = generateRandomVector(10);
	printVector(nums);
}

vector<int> generateRandomVector(int size){
	vector<int> vector;
	for (int i=0; i<size; i++)
		vector.push_back((int(rand() % 100)));
	return (vector);
}

/* Allows the presentation of a vector in the
 * console.
 *
 * The Vector is passed as reference to avoid
 * copying the whole vector and optimize the
 * program.
 *
 */
void printVector(vector<int> &vector) {
	for (unsigned i=0; i<vector.size(); i++)
		printf("%4d",vector[i]);
}
