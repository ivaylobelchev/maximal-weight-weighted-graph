#include "graph.hpp"
#include <unordered_set>

Graph::Graph(std::vector<Edge>& edges)
{
	std::unordered_set<std::string> names;
	for (auto& edge : edges) {
		names.insert(edge.start);
		names.insert(edge.end);
	}

	size_t i = 0;
	for (const auto& name : names) {
		//std::cout << name << std::endl;
		nameToNumber.insert({ name, i });
		numberToName.insert({ i, name });
		++i;
	}

	nodes.resize(names.size());
	for (auto& edge : edges) {
		nodes[nameToNumber.at(edge.start)].push_back({ nameToNumber.at(edge.end), -edge.weight });
	}
}