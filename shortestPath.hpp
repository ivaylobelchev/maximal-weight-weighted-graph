#pragma once
#include "graph.hpp"
#include "edge.hpp"

std::pair<long double, std::vector<Edge>> shortestPath(const Graph& graph, size_t start, size_t end, std::vector<size_t> topSort);