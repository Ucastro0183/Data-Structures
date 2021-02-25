/*
 * grid.cpp
 *
 *  Created on: Jul 4, 2014
 *      Author: ucastro
 */

/* IMPORTANT NOTE:
 *
 * As this code has to be added to the header (as in any other template class),
 * it is required to exclude this file from the project build.
 *
 * (Right click) > Resource Configurations > Exclude from Build...
 *
 * Or add the #ifndef and #endif flags to the cpp
 *
 */

#ifndef GRID_H_

#include "Grid.h"			//Header
#include <stdlib.h>			//Library for NULL values
#include "MyError.h"		//Library for error handling
#include <iostream>
using namespace std;

template <typename ElemType>
Grid<ElemType>::Grid() {
	this->rows = 0;
	this->cols = 0;
	data = NULL;
}

template <typename ElemType>
Grid<ElemType>::Grid(int row, int col) {
	this->rows = row;
	this->cols = col;
	data = new ElemType[row][col];
}

template <typename ElemType>
int Grid<ElemType>::numRows() {
	return (this->rows);
}

template <typename ElemType>
int Grid<ElemType>::numCols() {
	return (this->cols);
}

template <typename ElemType>
ElemType Grid<ElemType>::getAt(int row, int col) {
	if (row>=this->rows || col>=this->rows)
		MyError::error("Bad argument, index out of boundary.");
	ElemType elem;
	elem = data[row][col]; //The brackets dereference the pointers
	return (elem);
}

template <typename ElemType>
void Grid<ElemType>::setAt(int row, int col, ElemType value) {
	if (row>=this->rows || col>=this->rows)
		MyError::error("Bad argument, index out of boundary.");
	data[row][col] = value;		//The brackets dereference the pointers
}

template <typename ElemType>
void Grid<ElemType>::resize(int numRows,int numCols) {
	ElemType *n = new ElemType[numRows][numCols];
	for (int i=0; i<rows && i<numRows; i++)
		for (int j=0; j<cols && j<numCols; j++)
			n[i][j] = data[i][j];		//The brackets dereference the pointers
	delete[] data;
	rows = numRows;
	cols = numCols;
	data = n;
}

template <typename ElemType>
std::string toStr(ElemType* data, int rows, int cols) {
	std::string str = "";
	for (int i=0; i<rows; i++) {
		for (int j=0; j<cols; j++)
			str += data[i][j] + " ";
		str += "/n";
	}
	return (str);
}

template <typename ElemType>
std::string Grid<ElemType>::toString() {
	std::string str = toStr(data, numCols(), numRows());
	return (str);
}

template <typename ElemType>
Grid<ElemType>::~Grid() {
	this->rows = 0;
	this->cols = 0;
	delete[] data;		//Deallocate the whole array
}

#endif
