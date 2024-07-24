// GraphManager.cpp
#include "GraphManager.h"
#include "DrawingHelper.h"

void GraphManager::RandomGenerator(int width, int height) {
    ClearGraph();
    AddNode(width, height);

    srand(time(nullptr));
    for (int i = 0; i < Model::MAX_NODES; i++) {
        for (int j = 0; j < Model::MAX_NODES; j++) {
            if (i != j && rand() % 25 == 0) {
                AddEdge(i, j);
            }
        }
    }
}

void GraphManager::AddEdge(int u, int v) {
    Model::graph[u][v] = rand() % 100 + 1;
    Model::graph[v][u] = Model::graph[u][v];
}

void GraphManager::AddNode(int width, int height) {
    if (nodePositions == nullptr) {
        nodePositions = gcnew List<Point>();
    }

    nodePositions->Clear();

    for (int i = 0; i < Model::MAX_NODES; i++) {
        int x = rand() % (width - 2 * DrawingHelper::radius) + DrawingHelper::radius;
        int y = rand() % (height - 2 * DrawingHelper::radius) + DrawingHelper::radius;
        nodePositions->Add(Point(x, y));
    }
}

void GraphManager::SaveGraphToFile(String^ filePath, List<Point>^ nodePositions) {
    std::ofstream outFile(msclr::interop::marshal_as<std::string>(filePath));
    if (!outFile.is_open()) {
        return;
    }
    outFile << Model::MAX_NODES << "\n";
    for (int i = 0; i < nodePositions->Count; i++) {
        Point node = nodePositions[i];
        outFile << i << " " << node.X << " " << node.Y << "\n";
    }
    for (int i = 0; i < Model::MAX_NODES; ++i) {
        for (int j = i + 1; j < Model::MAX_NODES; ++j) {
            if (Model::graph[i][j] > 0) {
                outFile << i << " " << j << " " << Model::graph[i][j] << "\n";
            }
        }
    }
    outFile.close();
}

void GraphManager::LoadGraphFromFile(String^ filePath, List<Point>^ nodePositions, Graphics^ g, Control^ control, int radius) {
    std::ifstream inFile(msclr::interop::marshal_as<std::string>(filePath));
    if (!inFile.is_open()) {
        return;
    }
    ClearGraph();
    nodePositions->Clear();
    DrawingHelper::ClearDisplay(g, control);
    int numNodes;
    inFile >> numNodes;

    if (numNodes != Model::MAX_NODES) {
        return;
    }

    for (int i = 0; i < numNodes; i++) {
        int index, x, y;
        if (!(inFile >> index >> x >> y) || index != i) {
            return;
        }
        nodePositions->Add(Point(x, y));
        DrawingHelper::DrawNode(g, x, y, i);
    }

    int u, v, weight;
    while (inFile >> u >> v >> weight) {
        if (u < 0 || u >= numNodes || v < 0 || v >= numNodes) {
            continue;
        }
        Model::graph[u][v] = weight;
        Model::graph[v][u] = weight;
        DrawingHelper::DrawEdge(g, nodePositions[u].X, nodePositions[u].Y, nodePositions[v].X, nodePositions[v].Y, Color::Black, Color::Red, 1.5f, 10, weight);
    }
    inFile.close();
}

List<Point>^ GraphManager::GetNodePositions() {
    return nodePositions;
}

Point GraphManager::GetNodePositionIndex(int index) {
    return nodePositions[index];
}

void GraphManager::ClearGraph() {
    for (int i = 0; i < Model::MAX_NODES; i++) {
        for (int j = 0; j < Model::MAX_NODES; j++) {
            Model::graph[i][j] = 0;
        }
    }
}