#pragma once
#include <string>

struct Edge
{
	std::string start;
	std::string end;
	long double weight;
	Edge(const std::string& start, const long double& weight, const std::string& end)
		: start(start), end(end), weight(weight)
	{};
};