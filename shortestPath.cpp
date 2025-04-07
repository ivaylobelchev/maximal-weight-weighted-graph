#include "shortestPath.hpp"
#include "node.hpp"
#include "topsort.hpp"

//std::vector<Node> reverseEdge(std::vector<Node>& nodes)
//{
//	std::vector <Node> reverse;
//	reverse.resize(nodes.size());
//	for (int i = 0; i < nodes.size(); ++i) {
//		reverse.push_back(nodes[i]);
//		for (int j = 0; j < reverse[i].edges.size(); ++j) {
//			reverse[i].edges[j].second = -reverse[i].edges[j].second;
//		}
//	}
//	return reverse;
//}

//std::vector<Edge> reverseEdge(std::vector<Edge>& edges)
//{
//	std::vector<Edge> reverse;
//	reverse.resize(edges.size());
//	for (int i = 0; i < edges.size(); ++i) {
//		reverse.push_back(edges[i]);
//		reverse[i].weight = -edges[i].weight;
//	}
//	return reverse;
//}

std::vector<Node> reverseEdge(std::vector<Node>& nodes)
{
	std::vector <Node> reverse;
	reverse.resize(nodes.size());
	for (int i = 0; i < nodes.size(); ++i) {
		reverse.push_back(nodes[i]);
		for (int j = 0; j < reverse[i].edges.size(); ++j) {
			reverse[i].edges[j].second = -reverse[i].edges[j].second;
		}
	}
	return reverse;
}

std::pair<int, std::vector<Edge>> shortestPath(std::vector<Edge>& edges)
{
	std::map<std::string, size_t> nodeNames;
	std::vector<Node> nodes = getNodes(edges, nodeNames);

	std::vector<size_t> ordering = topSort(nodes);

	std::vector<Node> nodesReversed = reverseEdge(nodes);
	std::vector<Node> nodesReversedOrdered;
	for (int i = 0; i < ordering.size(); ++i) {
		nodesReversedOrdered.push_back(nodesReversed[ordering[i]]);
	}

	std::vector<std::pair<int, std::vector<Edge>>> distance;
	distance.resize(nodesReversedOrdered.size());
	for (int i = 0; i < distance.size(); ++i) {
		distance[i].first = 0;
	}

	for (int i = 0; i < nodesReversedOrdered.size(); ++i) {
		if (distance[i].first != 0 && !nodesReversedOrdered[i].edges.empty()) {
			for (auto& edge : nodesReversedOrdered[i].edges) {
				int newDistance = distance[i].first + edge.second;
				if (distance[ordering[edge.first]].first == 0) {
					distance[ordering[edge.first]].first = newDistance;
				}
				else {
					distance[ordering[edge.first]].first = std::min(distance[ordering[edge.first]].first, newDistance);
				}
			}
		}
	}

	return
}