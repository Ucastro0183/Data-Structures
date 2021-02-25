/*
 * ConnectionsGraph.cpp
 *
 *  Created on: Aug 19, 2014
 *      Author: ucastro
 */

#include "ConnectionsGraph.h"
#include <stdlib.h>
#include <stdarg.h>
#include <string>
#include <set>
#include <stdexcept>
#include <iostream>

#define err(prompt) try { \
				throw std::out_of_range(prompt); \
			} catch (std::exception &e) { \
				std::cerr << e.what() << std::endl; \
				throw;\
			}

ConnectionsGraph::ConnectionsGraph() {
	this->dim = 0;
}

int ConnectionsGraph::size() {
	return (this->dim);
}

bool ConnectionsGraph::isEmpty() {
	return (this->dim == 0);
}

/*void ConnectionsGraph::addNode(std::string name, ...) {
	nodeT *n = new nodeT;
	n->name = name;
	va_list v1;
	va_start(v1,name);
	std::string next = va_arg(v1, std::string);		//strings arguments can not pass by (...) list
	while (next != NULL) {
		nodeT* c = getNode(next);
		addConnection(n,c);
		next = va_arg(v1,std::string);
	}
	va_end(v1);
}*/

void ConnectionsGraph::addNode(std::string name) {
	if (getNode(name) != NULL)
		err("This node: " + name + " has already been defined in the map.");
	nodeT *n = new nodeT;
	n->name = name;
	data.insert(n);
	dim++;
}

void ConnectionsGraph::addConnection(std::string start, std::string end) {
	nodeT *a = getNode(start);
	nodeT *b = getNode(end);
	if ( a == NULL )
		err("Node:" + start + " has not been defined.");
	if( b == NULL)
		err("Node:" + end + " has not been defined.");
	addConnection(a, b);
}

typename ConnectionsGraph::nodeT *ConnectionsGraph::getNode(std::string name) {
	std::set< ConnectionsGraph::nodeT * >::iterator itr = data.begin();
	do {
		if ((*itr)->name == name)
			return (*itr);
		itr++;
	} while (itr != data.end());
	return (NULL);
}

void ConnectionsGraph::addConnection(typename ConnectionsGraph::nodeT *&start, typename ConnectionsGraph::nodeT *end) {
	connectionT* con = new connectionT;
	con->start = start;
	con->end = end;
	start->connetions.insert(con);
}

void ConnectionsGraph::deleteConnection(std::string start, std::string end) {
	nodeT *a = getNode(start);
	nodeT *b = getNode(end);
	if ( a == NULL )
		err("Node:" + start + " has not been defined.");
	if( b == NULL)
		err("Node:" + end + " has not been defined.");
	deleteConnection(a, b);
}

void ConnectionsGraph::deleteConnection(typename ConnectionsGraph::nodeT *&start, typename ConnectionsGraph::nodeT *&end) {
	std::set<ConnectionsGraph::nodeT *>::iterator itr ;
	for (itr = data.begin(); itr != data.end(); itr++) {
		std::set<ConnectionsGraph::connectionT *>::iterator it;
		for (it = (*itr)->connetions.begin(); it != (*itr)->connetions.end(); ){
			if ((*it)->start == start && (*it)->end == end)
				(*itr)->connetions.erase(it);
			it++;
		}
	}
}


ConnectionsGraph::~ConnectionsGraph() {
	for (std::set<nodeT *>::iterator itr = data.begin(); itr != data.end(); itr++) {
		delete *itr;
	}
}

