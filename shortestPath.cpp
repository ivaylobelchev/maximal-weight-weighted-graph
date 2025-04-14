#include "shortestPath.hpp"

std::pair<long double, std::vector<Edge>> shortestPath(const Graph& graph, size_t start, size_t end, std::vector<size_t> topSort)
{
	std::vector<std::pair<long double, std::vector<Edge>>> nodesBestPath;
	//		Level 1 - all nodes, ordered by their number
	//		Level 2 - best path weight to that node, best route to that node
	nodesBestPath.resize(graph.nodes.size());

	// start has to be first in the topological sort, which is ensured by DFS
	nodesBestPath[start].first = 0;

	for (size_t currentNode : topSort) {
		long double bestPathToCurrentNode = nodesBestPath[currentNode].first;
		for (auto& edge : graph.nodes[currentNode]) {
			// Check if this node even has a best path value before checking if it's smaller
			if ((nodesBestPath[edge.first].second.empty() && currentNode != start)
				|| bestPathToCurrentNode + edge.second < nodesBestPath[edge.first].first)
			{
				// Save new best path value
				nodesBestPath[edge.first].first = bestPathToCurrentNode + edge.second;
				// Copy the best path from currentNode
				nodesBestPath[edge.first].second = nodesBestPath[currentNode].second;
				// Add the current node to the path
				nodesBestPath[edge.first].second.push_back(Edge(graph.numberToName.at(currentNode), edge.second, graph.numberToName.at(edge.first)));
			}
		}
	}

	return nodesBestPath[end];
}