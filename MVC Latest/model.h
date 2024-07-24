#pragma once
// Model.h
#include <vector>

class Model {
public:
	static std::vector<std::vector<int>> graph;
	static std::vector<std::pair<int, int>> shortestPathEdges;
	//static std::vector<int> shortestPathTree; // Use this for printing the shortest path nodes
	//static std::vector<int> distanceFromSrcToIndex; // Use this for printing the total weight of path
	static const int MAX_NODES = 50;
};