#pragma once
#include "edge.hpp"
#include <map>
#include <vector>
#include <utility>

struct Node
{
	std::string name;
	std::vector<std::pair<size_t, double>> edges;

	Node(const std::string& name)
		: name(name)
	{}
};

std::vector<Node> getNodes(const std::vector<Edge>& edges, std::map<std::string, size_t>& nodeNames)
{
	std::unordered_set<std::string> nodesSet;
	for (auto& edge : edges) {
		nodesSet.insert(edge.start);
		nodesSet.insert(edge.end);
	}

	std::vector<Node> nodesVector;
	for (auto& node : nodesSet) {
		nodesVector.push_back(Node(node));
	}

	for (size_t i = 0; i < nodesVector.size(); ++i) {
		nodeNames.insert({ nodesVector[i].name, i });
	}

	for (auto& edge : edges) {
		auto iterStart = nodeNames.find(edge.start);
		auto iterEnd = nodeNames.find(edge.end);
		nodesVector[iterStart->second].edges.push_back({ iterEnd->second, edge.weight });
	}

	return nodesVector;
}