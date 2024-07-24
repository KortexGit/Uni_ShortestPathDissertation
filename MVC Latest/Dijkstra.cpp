#include "Dijkstra.h"


void Dijkstra::dijkstra(const std::vector<std::vector<int>>& graph, int srcNode, int destNode, std::vector<std::pair<int, int>>& shortestPathEdges) {
	std::vector<int> distanceFromSrcToIndex(Model::MAX_NODES, INT_MAX);  // The output array. dist[i] will hold the shortest distance from src to i
	std::vector<bool> visited(Model::MAX_NODES, false); // Visited[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is finalised.
	std::vector<int> shortestPathTree(Model::MAX_NODES, -1); // Parent array to store shortest path tree

	distanceFromSrcToIndex[srcNode] = 0;

	for (int loop = 0; loop < Model::MAX_NODES; loop++) {
		int minDist = minimumDistance(distanceFromSrcToIndex, visited);
		visited[minDist] = true;
		for (int index = 0; index < Model::MAX_NODES; index++) {
			if (!visited[index] && Model::graph[minDist][index] && distanceFromSrcToIndex[minDist] != INT_MAX && distanceFromSrcToIndex[minDist] + Model::graph[minDist][index] < distanceFromSrcToIndex[index]) {
				shortestPathTree[index] = minDist;
				distanceFromSrcToIndex[index] = distanceFromSrcToIndex[minDist] + Model::graph[minDist][index];
			}
		}
	}

	// After the algorithm runs, store the edges of the shortest path
	if (srcNode != destNode) {
		int current = destNode;
		while (current != srcNode) {
			int prev = shortestPathTree[current];
			shortestPathEdges.push_back(std::make_pair(prev, current));

			current = prev;
		}
		std::reverse(shortestPathEdges.begin(), shortestPathEdges.end());
	}
}

int Dijkstra::minimumDistance(const std::vector<int>& distanceFromSrcToIndex, const std::vector<bool>& visited) {
	int minDistance = INT_MAX, index = -1;

	for (int i = 0; i < Model::MAX_NODES; i++) {
		if (!visited[i] && distanceFromSrcToIndex[i] <= minDistance) {
			minDistance = distanceFromSrcToIndex[i];
			index = i;
		}
	}
	return index;
}
