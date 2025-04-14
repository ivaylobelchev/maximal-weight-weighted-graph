#pragma once
#include "graph.hpp"

std::vector<size_t> DFS(const Graph& graph, size_t start, size_t end);

std::vector<size_t> topologicalSort(std::vector<size_t> dfs, std::vector<size_t> kahn);