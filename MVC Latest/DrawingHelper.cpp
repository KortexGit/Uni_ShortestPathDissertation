// DrawingHelper.cpp
#include "DrawingHelper.h"

void DrawingHelper::DrawNode(Graphics^ g, int x, int y, int nodeID) {
    g->FillEllipse(Brushes::LightBlue, x - radius, y - radius, 2 * radius, 2 * radius);
    PointF point = PointF(x, y);
    g->DrawString(nodeID.ToString(), gcnew Drawing::Font("Arial Bold", 11), Brushes::Black, point);
}

void DrawingHelper::DrawEdge(Graphics^ g, int x1, int y1, int x2, int y2, Color edgeColor, Color brushColor, double penWidth, int fontSize, int weight) {
    Pen^ pen = gcnew Pen(edgeColor);
    pen->Width = penWidth;
    g->DrawLine(pen, x1, y1, x2, y2);
    PointF point = PointF((x1 + x2) / 2, (y1 + y2) / 2);
    g->DrawString(weight.ToString(), gcnew Drawing::Font("Arial", fontSize), gcnew SolidBrush(brushColor), point);
}

void DrawingHelper::DrawGraph(Graphics^ g, const std::vector<std::vector<int>>& graph, List<Point>^ nodePositions, int radius) {
    for (int i = 0; i < Model::MAX_NODES; i++) {
        for (int j = 0; j < Model::MAX_NODES; j++) {
            if (graph[i][j] > 0) {
                DrawEdge(g, nodePositions[i].X, nodePositions[i].Y, nodePositions[j].X, nodePositions[j].Y, Color::Black, Color::Red, 1.5f, 10, graph[i][j]);
            }
        }
    }
    for (int i = 0; i < Model::MAX_NODES; i++) {
        DrawNode(g, nodePositions[i].X, nodePositions[i].Y, i);
    }
}

void DrawingHelper::ClearDisplay(Graphics^ g, Control^ control) {
    g->Clear(control->BackColor);
}