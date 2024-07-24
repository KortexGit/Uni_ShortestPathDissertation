#include "Model.h"

std::vector<std::vector<int>> Model::graph(MAX_NODES, std::vector<int>(MAX_NODES)); // Stores the generated graph
std::vector<std::pair<int, int>> Model::shortestPathEdges;
//std::vector<int> Model::shortestPathTree(Model::MAX_NODES, -1); // Stores the current shortest path tree
//std::vector<int> Model::distanceFromSrcToIndex(Model::MAX_NODES, INT_MAX);  // The output array. Will hold the shortest distance from src to i