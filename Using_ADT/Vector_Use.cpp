/*
 * Vector_Use.cpp
 *
 *  Created on: Jun 27, 2014
 *      Author: ucastro
 */

#include "Vector.h"
#include <iostream>
#include "stdio.h"		//Library for printf("format",ivar)
#include "stdlib.h"		//Library for the rand() function
using namespace std;

Vector<int> generateRandomVector(int size);
void printVector(Vector<int> &vector);

vector_use::vector_use() {
	Vector<int> nums = generateRandomVector(10);
	printVector(nums);
}

Vector<int> generateRandomVector(int size){
	Vector<int> vector;
	for (int i=0; i<size; i++)
		vector.add(int(rand() % 100));
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
void printVector(Vector<int> &vector) {
	for (int i=0; i<vector.size(); i++)
		printf("%4d",vector[i]);
}
