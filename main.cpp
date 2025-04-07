#include "readFromFile.hpp"
#include "shortestPath.hpp"
#include "node.hpp"
#include "topsort.hpp"
#include <map>

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
			return false;
		}
	}

	std::vector<Edge> edges;
	if (readFromFile(fileName, edges) == false) {
		return 2;
	}

	std::cout << "Printing edges:\n\n";
	for (auto& edge : edges) {
		std::cout << "Start: " << edge.start << '\n';
		std::cout << "Weight: " << edge.weight << '\n';
		std::cout << "End: " << edge.end << "\n\n";
	}
	

	//std::vector<Edge> result = shortestPath(start, end, edges);


	return 0;
}