/*
 * ConectionsGraph.h
 *
 *  Created on: Aug 19, 2014
 *      Author: ucastro
 */

#ifndef CONNECTIONSGRAPH_H_
#define CONNECTIONSGRAPH_H_

#include <set>
#include <string>

/**
 * This class represents a graph of interconnected items,
 * usually used to estimate shortest rout possible between
 * two items. By the way its implemented this data structure
 * represents directional connections, by meaning that each
 * connection is defined unidirectional.
 *
 * Typical examples of this type of structures might be a
 * map of flights between cities or bus lines routes.
 */
class ConnectionsGraph {
public:
	ConnectionsGraph();
	virtual ~ConnectionsGraph();
	int size();
	bool isEmpty();
	//void addNode(std::string name, ...);
	void addNode(std::string name);
	void addConnection(std::string start, std::string end);
	void deleteConnection(std::string start, std::string end);

private:
	struct nodeT;

	struct connectionT{
		//information of each link, such as time, cost, distance, etc...
		nodeT *start, *end;
	};

	struct nodeT {
		//information of the node, such as city name.
		std::string name;
		std::set<connectionT *> connetions;
	};

	std::set<nodeT *> data;
	int dim;

	nodeT *getNode(std::string name);
	void addConnection(nodeT *&start, nodeT *end);
	void deleteConnection(nodeT *&start, nodeT *&end);

	/*
	 * Another typical data representations of this type of
	 * data are adjacency matrixes, where rows and columns represent
	 * from and to directions and available connections are checked
	 * in the matrix.
	 */
};

#endif /* CONNECTIONSGRAPH_H_ */
