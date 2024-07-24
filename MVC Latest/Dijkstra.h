#pragma once
#include <vector>
#include <climits>
#include <algorithm>
#include "Model.h"

using namespace System::Collections::Generic;

class Dijkstra {
public:
    static void dijkstra(const std::vector<std::vector<int>>& graph, int srcNode, int destNode, std::vector<std::pair<int, int>>& shortestPathEdges);
    static int minimumDistance(const std::vector<int>& distanceFromSrcToIndex, const std::vector<bool>& visited);
};
