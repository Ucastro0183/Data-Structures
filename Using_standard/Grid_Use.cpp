/*
 * Grid_Use.cpp
 *
 *  Created on: 28/06/2014
 *      Author: Ulises
 */

#include "Grid_Use.h"

#include "vector"
#include "stdlib.h"
#include "stdio.h"
#include <iostream>
using namespace std;

void generateMatrix(vector<vector<int> > &g, int rows, int cols);
void printMatrix(vector<vector<int> > &grid);

grid_use::grid_use() {
	vector<vector<int> > matrix;
	generateMatrix(matrix,6,6);
	printMatrix(matrix);
}

void generateMatrix(vector<vector<int> > &g, int rows, int cols) {
	for (int row=0; row<rows; row++) {
		vector<int> *v = new vector<int>;
		for (int col=0; col<cols; col++)
			v->push_back((rand() %100 + 1));	//generates numbers between 1 & 100
		g.push_back(*v);
	}
}

void printMatrix(vector<vector<int> > &grid) {
	cout << "Matrix:" << endl;
	for (unsigned row=0; row<grid.size(); row++) {
		for (unsigned col=0; col<grid[0].size(); col++)
			printf("%4d",grid[row][col]);
		cout << endl;
	}
}
