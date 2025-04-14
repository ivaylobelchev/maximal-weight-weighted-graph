#include "dfs.hpp"
#include <algorithm>

void dfsRec(const Graph& graph, size_t at, std::vector<bool>& visited, std::vector<size_t>& topSort)
{
	if (visited[at]) return;

	visited[at] = true;
	topSort.push_back(at);

	for (auto& edge : graph.nodes[at])
	{
		dfsRec(graph, edge.first, visited, topSort);
	}
}

std::vector<size_t> DFS(const Graph& graph, size_t start, size_t end)
{
	std::vector<bool> visited(graph.nodes.size(), false);
	std::vector<size_t> dfsResult;

	dfsRec(graph, start, visited, dfsResult);

	return dfsResult;
}

std::vector<size_t> topologicalSort(std::vector<size_t> dfs, std::vector<size_t> kahn)
{
	std::vector<size_t> topSort;

	for (size_t& kahnValue : kahn) {
		if (std::find(dfs.begin(), dfs.end(), kahnValue) != dfs.end()) {
			topSort.push_back(kahnValue);
		}
	}

	return topSort;
}