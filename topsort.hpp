#pragma once
#include "node.hpp"
#include <unordered_set>
#include <vector>

std::vector<Node> getNodes(const std::vector<Edge>& edges, std::map<std::string, size_t>& nodeNames, const std::vector<Node>& nodes);

std::vector<size_t> topSort(const std::vector<Node>& nodes);