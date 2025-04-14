# Maximal weight of a weighted graph.

## Overview

This program reads a weighted directed graph from a text file and computes the path with the maximum total edge weight between two specified nodes, provided as command-line arguments. It can detect whether the graph contains cycles, and if it doesn't, it outputs the sequence of nodes, the corresponding edge weights that make up the maximum-weight path, and the total weight of that path.

The program implements an algorithm that finds the minimum-weight path in a directed acyclic graph (DAG). All the edge weights passed to the minimum-weight algorithm have been negated so that the algorithm finds the longest path instead of the shortest. The algorithm requires a topological sort, which is performed using Kahn's algorithm — a method that also detects the presence of cycles. After the sort, depth-first search (DFS) is used to prune nodes that are unreachable from the starting node.

## Requirements

- **C++14 or later**.
- A compiler that supports C++14 (e.g., **GCC 5.4+, Clang 3.3+, MSVC 2015+**)

### Files

Ensure the following files are in the same directory:

- `main.cpp`
- `readFromFile.hpp`
- `readFromFile.cpp`
- `edge.hpp`
- `dfs.hpp`
- `dfs.cpp`
- `shortestPath.hpp`
- `shortestPath.cpp`
- `graph.hpp`
- `graph.cpp`
- `kahn.hpp`
- `kahn.cpp`

## Usage

1. **Compile the program**:
   ```sh
   g++ -std=c++14 main.cpp readFromFile.cpp graph.cpp kahn.cpp dfs.cpp shortestPath.cpp -o maximal-weight-graph
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

### Test data

The test data should begin with the number of edges expected in the file. Each subsequent line represents a directed edge in the graph and contains three elements:

`<start_node_tag> <edge_weight> <end_node_tag>`

Example file data:

```
4
apple 0.7 pear
apple 0.2 pumpkin
pumpkin 0.3 orange
pear 0.1 orange
```

Other test graphs are available in the "test_files" directory. For example:

```
test_files/test4.txt
```
