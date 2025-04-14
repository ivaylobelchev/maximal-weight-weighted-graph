#include "readFromFile.hpp"
#include "dfs.hpp"
#include "shortestPath.hpp"
#include "kahn.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	std::string start, end, fileName;
	if (argc == 3 || argc == 4) {
		start = argv[1];
		end = argv[2];
	}
	else {
		std::cerr << "Invalid number of arguments!";
		std::cerr << "Usage: ./maximal-weight-graph <start_node_tag> <end_node_tag>\n";
		std::cerr << "Usage: ./maximal-weight-graph <start_node_tag> <end_node_tag> <text_file>\n";
		return 1;
	}

	if (argc == 4) {
		fileName = argv[3];
	}
	else {
		// Prompt the user for the filename and read it.
		std::string fileName;
		std::cout << "Please enter the filename to open: ";
		// Allows for spaces in the filename
		if (!std::getline(std::cin, fileName)) {
			std::cerr << "Error reading the filename!\n";
			return 1;
		}
	}

	std::vector<Edge> edges;
	if (readFromFile(fileName, edges) == false) {
		return 2;
	}

	Graph graph(edges);

	// Check if start and end exist
	bool startEndMissing = false;
	if (graph.nameToNumber.find(start) == graph.nameToNumber.end()) {
		std::cerr << "\nThe start value \"" << start << "\" is missing!\n";
		startEndMissing = true;
	}
	if (graph.nameToNumber.find(end) == graph.nameToNumber.end()) {
		std::cerr << "\nThe end value \"" << end << "\" is missing!\n";
		startEndMissing = true;
	}
	if (startEndMissing) return 3;

	// DFS
	std::vector<size_t> dfs_result = DFS(graph, graph.nameToNumber.at(start), graph.nameToNumber.at(end));

	// Kahn's algorithm - topological sort
	std::pair<std::vector<size_t>, bool> sortKahn = kahn(graph);
	if (sortKahn.second) {
		std::cerr << "\nThis graph contains a cycle!\n";
		return 4;
	}

	// Remove all nodes unreachable from the start position by combining DFS and Kahn's algorithm
	std::vector<size_t> topSort = topologicalSort(dfs_result, sortKahn.first);
	
	// Find the shortest path for the same graph with inverted weights
	// which actually finds the longest path
	std::pair<long double, std::vector<Edge>> longestPath = shortestPath(graph, graph.nameToNumber.at(start), graph.nameToNumber.at(end), topSort);

	// Print the longest path
	std::cout << "\nLongest path:\n\n";
	for (Edge& edge : longestPath.second) {
		std::cout << '\t' << edge.start << ' ' << -edge.weight << ' ' << edge.end << '\n';
	}
	std::cout << "\nTotal weight: " << -longestPath.first << '\n';

	return 0;
}