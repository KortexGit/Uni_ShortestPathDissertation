// GraphManager.h
#pragma once
#include <vector>
#include <fstream>
#include <msclr/marshal_cppstd.h>
#include "Model.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

public ref class GraphManager {
public:
    static void AddEdge(int u, int v);
    static void AddNode(int width, int height);
    static void RandomGenerator(int width, int height);
    static void SaveGraphToFile(String^ filePath, List<Point>^ nodePositions);
    static void LoadGraphFromFile(String^ filePath, List<Point>^ nodePositions, Graphics^ g, Control^ control, int radius);
    static void ClearGraph();
    static List<Point>^ GetNodePositions();
    static Point GetNodePositionIndex(int index);

private:
    static List<Point>^ GraphManager::nodePositions = nullptr; // TODO: Make this a vector of points?
};