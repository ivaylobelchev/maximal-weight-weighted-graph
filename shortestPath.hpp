#pragma once
#include "edge.hpp"
#include <vector>

//std::vector<Edge> reverseEdge(std::vector<Edge>& edges);
//std::vector<Node> reverseEdge(std::vector<Node>& nodes);

std::pair<int, std::vector<Edge>> shortestPath(const std::string& start, const std::string& end, const std::vector<Edge>& edges);