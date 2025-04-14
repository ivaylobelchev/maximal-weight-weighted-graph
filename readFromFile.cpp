#include "readFromFile.hpp"
#include <iostream>
#include <fstream>

bool readFromFile(const std::string& fileName, std::vector<Edge>& edges)
{
	// Open the file.
	std::ifstream textFile{ fileName };
	if (!textFile.is_open()) {
		std::cerr << "Error opening text file: " << fileName << '\n';
		return false;
	}

	// Reading the number of lines
	int lines = 0;
	textFile >> lines;

	// Reading all the edges in the file
	for (int i = 0; i < lines; ++i) {
		std::string first, second;
		long double weight = 0;
		textFile >> first;
		textFile >> weight;
		textFile >> second;
		if (first == "" || second == "") {
			std::cerr << "Error reading line: " << first << ' ' << weight << ' ' << second << '\n';
			continue;
		}
		edges.push_back(Edge(first, weight, second));
	}

	textFile.close();
	return true;
}