#include "topsort.hpp"

void dfs(size_t i, std::vector<bool>& visited, std::vector<size_t>& visitedNodes, const std::vector<Node>& nodes)
{
	visited[i] = true;

	for (int j = 0; j < nodes[j].edges.size(); ++j) {
		if (visited[nodes[i].edges[j].first] == false) {
			dfs(nodes[i].edges[j].first, visited, visitedNodes, nodes);
		}
	}

	visitedNodes.push_back(i);
}

std::vector<size_t> topSort(const std::vector<Node>& nodes)
{
	const size_t numberOfNodes = nodes.size();

	std::vector<bool> visited;
	for (auto i = nodes.size(); i > 0; --i) {
		visited.push_back(false);
	}

	std::vector<size_t> ordering;
	for (auto i = nodes.size(); i > 0; --i) {
		visited.push_back(0);
	}

	size_t index = numberOfNodes - 1;

	for (size_t i = 0; i < numberOfNodes; ++i) {
		if (visited[i] == false) {
			std::vector<size_t> visitedNodes;
			dfs(i, visited, visitedNodes, nodes);
			// Add the result of visitedNodes to ordering
			for (auto& visitedNode : visitedNodes) {
				ordering[i] = visitedNode;
				--i;
			}
		}
	}

	return ordering;
}