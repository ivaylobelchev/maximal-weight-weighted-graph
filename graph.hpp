#pragma once
#include "edge.hpp"
#include <vector>
#include <map>

class Graph 
{
public:
	std::vector<std::vector<std::pair<size_t, long double>>> nodes;
	// the weight is saved as the negative value of itself!
	//		Level 1 - all nodes, ordered by their number
	//		Level 2 - the edges of the nodes
	//		Level 3 - the end of the edges, the weight of the edges

	std::map<std::string, size_t> nameToNumber;
	// nameToNumber.at("start") to access the number

	std::map<size_t, std::string> numberToName;
	// numberToName.at(45) to access the name

	Graph(std::vector<Edge>& edges);
};