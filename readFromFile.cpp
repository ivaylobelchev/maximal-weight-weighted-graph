#include "readFromFile.hpp"
#include <fstream>

bool readFromFile(const std::string& fileName, std::vector<Edge>& edges)
{
	// Open the file.
	std::ifstream textFile{ fileName };
	if (!textFile.is_open()) {
		std::cerr << "Error opening text file: " << fileName << '\n';
		return false;
	}

	std::string line;
	int lines = 0;
	while (!textFile.eof()) {
		std::getline(textFile, line);
		++lines;
	}

	// Go back to the beginning of the file.
	textFile.clear();
	textFile.seekg(0);

	for (int i = 0; i < lines; ++i) {
		std::string first, second;
		double weight = 0;
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