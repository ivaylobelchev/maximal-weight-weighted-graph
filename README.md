# Maximal weight of a weighted graph.

## Important notes

This program is unfinished and does not compile.
I've attempted to write a solution to find the longest path in a **directed acyclic graph**. If the graph isn't acyclic, then the solution is NP-Hard.
As you can probably see, my attempt to write this solution wasn't very successful, since the code doesn't compile and is not complete.
I've attemped to implement a topological sort algorithm and then use its sorting to find the shortest path in a graph, identical to the one in the file, but with the opposite number for weight (same number but multiplied by -1).
Using Dijkstra's algorithm is not possible, since it doesn't work correctly with negative numbers.

## Overview

This program reads a weighted, directed graph from a text file and computes the path with the maximum total edge weight between two specified nodes, provided as command-line arguments. It outputs the sequence of nodes and corresponding edge weights that make up the maximal-weight path.

## Requirements

- **C++14 or later**.
- A compiler that supports C++14 (e.g., **GCC 5.4+, Clang 3.3+, MSVC 2015+**)

### Files

Ensure the following files are in the same directory:

- `main.cpp`
- `readFromFile.hpp`
- `readFromFile.cpp`
- `edge.hpp`
- `node.hpp`
- `topsort.hpp`
- `topsort.cpp`
- `shortestPath.hpp`
- `shortestPath.cpp`

## Usage

1. **Compile the program**:
   ```sh
   g++ -std=c++14 main.cpp readFromFile.cpp topsort.cpp shortestPath.cpp -o maximal-weight-graph
   ```
2. **Run the program**:
   ```sh
   ./maximal-weight-graph <start_node_tag> <end_node_tag>
   ```
   or
   ```sh
   ./maximal-weight-graph <start_node_tag> <end_node_tag> <text_file>
   ```
3. **Enter the filename** containing the matrix if using the first format without the text file as a command-line argument.

Example file data:

```
apple 0.7 pear
apple 0.2 pumpkin
pumpkin 0.3 orange
pear 0.1 orange
```

Each line in the input file represents a directed edge in the graph and contains three elements:

```<start_node_tag> <edge_weight> <end_node_tag>```
