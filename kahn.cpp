#include "kahn.hpp"
#include <queue>

// first - topological order
// second - whether there's a cycle
std::pair<std::vector<size_t>, bool> kahn(const Graph& graph)
{
	// Calculate how many edges go to each of the nodes
	std::vector<int> incomingDegree(graph.nodes.size(), 0);
	for (auto& startNode : graph.nodes) {
		for (auto& endNode : startNode) {
			++(incomingDegree[endNode.first]);
		}
	}

	// Add the nodes with no incoming edges to the queue
	std::queue<size_t> q;
	for (size_t i = 0; i < graph.nodes.size(); ++i) {
		if (incomingDegree[i] == 0) q.push(i);
	}

	// Loop around the queue until there are no more elements left
	size_t index = 0;
	std::vector<size_t> order(graph.nodes.size(), 0);
	while (!q.empty()) {
		size_t current = q.front();
		q.pop();
		order[index++] = current;
		// Reduce the incomingDegree of each node, which had incoming edges from nodes, that have been removed from the queue
		for (auto& endNode : graph.nodes.at(current)) {
			--(incomingDegree[endNode.first]);
			// If any new node has no incoming edges, add them to the queue
			if (incomingDegree[endNode.first] == 0) q.push(endNode.first);
		}
	}

	// If the number of iterations doesn't match the number of nodes, we have a cycle
	if (index != graph.nodes.size()) {
		return { order, true };
	}

	return { order, false };
}