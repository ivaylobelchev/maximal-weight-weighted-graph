#pragma once
#include <string>

struct Edge
{
	std::string start;
	std::string end;
	double weight;
	//bool traversed = false;
	Edge(const std::string& start, const double& weight, const std::string& end)
		: start(start), end(end), weight(weight)
	{};
};