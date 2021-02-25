/*
 * grid.h
 *
 *  Created on: Jul 4, 2014
 *      Author: ucastro
 */

#ifndef GRID_H_
#define GRID_H_

#include <string>

template <typename ElemType>
class Grid {
public:
	Grid();
	Grid(int row, int col);			//Overloaded constructor
	virtual ~Grid();

	int numRows();
	int numCols();

	ElemType getAt(int row, int col);
	void setAt(int row, int col, ElemType value);

	void resize(int numRows, int numCols);

	std::string toString();

private:
	int rows;
	int cols;
	ElemType *data;
};

#include "Grid.cpp"		//Only for template classes

#endif /* GRID_H_ */
