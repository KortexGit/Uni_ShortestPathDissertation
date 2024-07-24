// DrawingHelper.h
#pragma once
#include <vector>
#include <list>
#include "Model.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

public ref class DrawingHelper {
public:
	static const int radius = 20;
	static void DrawNode(Graphics^ g, int x, int y, int nodeID);
	static void DrawEdge(Graphics^ g, int x1, int y1, int x2, int y2, Color edgeColor, Color brushColor, double penWidth, int fontSize, int weight);
	static void DrawGraph(Graphics^ g, const std::vector<std::vector<int>>& graph, List<Point>^ nodePositions, int radius);
	static void ClearDisplay(Graphics^ g, Control^ control);
};