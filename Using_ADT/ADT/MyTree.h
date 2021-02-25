/*
 * Tree.h
 *
 *  Created on: Jul 28, 2014
 *      Author: ucastro
 */

#ifndef TREE_H_
#define TREE_H_

#include <string>

/**
 * This class store objects in a tree-like order
 * placing elements in the order they are added
 * in a unbalanced manner.
 *
 * The size of the tree might vary from O(nlog(n))
 * in a totally balanced tree, to a O(n2) in a
 * fully unbalanced tree.
 *
 * if the data in the tree is entered in a ordered
 * matter the result will be a fully unbalanced
 * tree.
 *
 * @author Ulises Castro
 *
 * @usage
 *     MyTree<ElemType> treeVar = new MyTree<ElemType>(fnCmp);
 */
template <typename ElemType>
class MyTree {
private:
	/**
	 * Basic comparison method, return -1 if
	 * the first element is bigger than the second
	 * else if the first element is smaller will return 1.
	 * When both elements are equals return 0.
	 */
	int operatorCmp(ElemType , ElemType );

public:

	/**
	 * Constructor of the class, this method need to be called
	 * when instantiating the class, it will allocate the memory
	 * required for the data structure.
	 *
	 * @usage
	 * 		MyTree<ElemType> treeVar = new MyTree<ElemType>(fnCmp);
	 *
	 * @param cmpFn Function to compare elements within the tree
	 * 				for primary types this parameter might be discard
	 * 				the class will use the basic comparison operands.
	 *
	 * If required, comparison function will have to be of the type:
	 *
	 * 		int (*cmpFn)(ElemType , ElemType )
	 *
	 * Which have to return -1 if first element is bigger than the second,
	 * 1 if the first element is smaller than the second, or 0 if they are
	 * equals.
	 */
	MyTree(int (*cmpFn)(ElemType , ElemType ) = operatorCmp);		//Overloaded constructor

	/**
	 * Destructor of the class, this method is automatically called
	 * when an instance of the class goes out-of-scope, it is in
	 * charge of deallocating the memory used to store the values
	 * in the tree.
	 */
	virtual ~MyTree();

	/**
	 * This method returns the size of the data structure as the
	 * number of elements stored within.
	 * @return Number of elements stored in the tree.
	 */
	int size();

	/**
	 *  This method indicates whether if an instance is empty or not.
	 *  @return true if the tree is empty.
	 */
	bool isEmpty();

	/**
	 * Adds a new element in the tree-like data structure. This method verify
	 * if the element already exist in the tree, if so, it won't duplicate it,
	 * it will just ignore the instruction.
	 *
	 * @param value New object or element to store in the data structure.
	 */
	void add(ElemType value);

	/**
	 *
	 */
	void remove(ElemType value);

	/**
	 * This method indicates is a given element is already present in the
	 * data structure.
	 *
	 * @return true if the element has already been stored in the tree.
	 *
	 * @param value Element to verify if exist in the structured data.
	 */
	bool contains(ElemType value);

	struct Iterator {
		bool hasNext();
		void next();
	};

	Iterator iterator();

	/**
	 * Returns a string representation of the data in a sorted manner.
	 * @return string of the data stored.
	 */
	std::string toString();

private:
	struct cell {
		ElemType value;
		cell *left;
		cell *right;
	};

	cell *data;
	int numCells;
	int (*cmp)(ElemType, ElemType);

	void addTree(cell *root);
};

#include "MyTree.cpp"

#endif /* TREE_H_ */
