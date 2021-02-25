/*
 * Grid_Use.cpp
 *
 *  Created on: 28/06/2014
 *      Author: Ulises
 */

#include "Grid_Use.h"

#include "Grid.h"
#include "stdlib.h"
#include "stdio.h"
#include <iostream>
using namespace std;

void generateMatrix(Grid<int> &g, int rows, int cols);
void printMatrix(Grid<int> &grid);

grid_use::grid_use() {
	Grid<int> matrix(6,6);
	generateMatrix(matrix,6,6);
	printMatrix(matrix);
}

void generateMatrix(Grid<int> &g, int rows, int cols) {
	Grid<int> grid(rows,cols);
	for (int row=0; row<rows; row++)
		for (int col=0; col<cols; col++)
			grid.setAt(row,col,(rand() %100 + 1));	//generates numbers between 1 & 100
}

void printMatrix(Grid<int> &grid) {
	cout << "Matrix:" << endl;
	for (int row=0; row<grid.numRows(); row++) {
		for (int col=0; col<grid.numCols(); col++)
			printf("%4d",grid.getAt(row,col));
		cout << endl;
	}
}
