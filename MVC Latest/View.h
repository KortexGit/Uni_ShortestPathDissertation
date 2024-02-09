#pragma once
#include <cstdlib>
#include <list>
#include <ctime>
#include <vector>
#include <climits>
#include <Windows.h>
#include <cmath>
#include "model.h"
#include <iostream>

namespace MVCLatest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text;

	enum SelectionMode {
		None,
		SelectSource,
		SelectDestination
	};

	/// <summary>
	/// Summary for View
	/// </summary>
	public ref class View : public Form
	{
	public:
		View(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~View()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ btn_generateNodes;
	private: System::Windows::Forms::PictureBox^ pic_nodeVisuals;
	private: System::Windows::Forms::Button^ btn_selectSource;
	private: System::Windows::Forms::Button^ btn_selectDestination;
	private: System::Windows::Forms::CheckBox^ chk_demoMode;
	private: System::Windows::Forms::Button^ btn_demoNext;
	private: System::Windows::Forms::Button^ btn_demoPrev;
	private: System::Windows::Forms::Button^ btn_runAlgorithm;
	private: System::Windows::Forms::TextBox^ txt_errorOutput;
	//private: System::Windows::Forms::TextBox^ txt_errorOutput;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btn_generateNodes = (gcnew System::Windows::Forms::Button());
			this->pic_nodeVisuals = (gcnew System::Windows::Forms::PictureBox());
			this->btn_selectSource = (gcnew System::Windows::Forms::Button());
			this->btn_selectDestination = (gcnew System::Windows::Forms::Button());
			this->chk_demoMode = (gcnew System::Windows::Forms::CheckBox());
			this->btn_demoNext = (gcnew System::Windows::Forms::Button());
			this->btn_demoPrev = (gcnew System::Windows::Forms::Button());
			this->btn_runAlgorithm = (gcnew System::Windows::Forms::Button());
			this->txt_errorOutput = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_nodeVisuals))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_generateNodes
			// 
			this->btn_generateNodes->Location = System::Drawing::Point(6, 441);
			this->btn_generateNodes->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn_generateNodes->Name = L"btn_generateNodes";
			this->btn_generateNodes->Size = System::Drawing::Size(99, 28);
			this->btn_generateNodes->TabIndex = 0;
			this->btn_generateNodes->Text = L"Generate Nodes";
			this->btn_generateNodes->UseVisualStyleBackColor = true;
			this->btn_generateNodes->Click += gcnew System::EventHandler(this, &View::btn_generateNodes_Click);
			// 
			// pic_nodeVisuals
			// 
			this->pic_nodeVisuals->Location = System::Drawing::Point(6, 7);
			this->pic_nodeVisuals->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->pic_nodeVisuals->Name = L"pic_nodeVisuals";
			this->pic_nodeVisuals->Size = System::Drawing::Size(934, 431);
			this->pic_nodeVisuals->TabIndex = 1;
			this->pic_nodeVisuals->TabStop = false;
			this->pic_nodeVisuals->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &View::pic_nodeVisuals_MouseClick);
			// 
			// btn_selectSource
			// 
			this->btn_selectSource->Enabled = false;
			this->btn_selectSource->Location = System::Drawing::Point(110, 441);
			this->btn_selectSource->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn_selectSource->Name = L"btn_selectSource";
			this->btn_selectSource->Size = System::Drawing::Size(90, 28);
			this->btn_selectSource->TabIndex = 2;
			this->btn_selectSource->Text = L"Select Source";
			this->btn_selectSource->UseVisualStyleBackColor = true;
			this->btn_selectSource->Click += gcnew System::EventHandler(this, &View::btn_selectSource_Click);
			// 
			// btn_selectDestination
			// 
			this->btn_selectDestination->Enabled = false;
			this->btn_selectDestination->Location = System::Drawing::Point(204, 441);
			this->btn_selectDestination->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn_selectDestination->Name = L"btn_selectDestination";
			this->btn_selectDestination->Size = System::Drawing::Size(106, 28);
			this->btn_selectDestination->TabIndex = 3;
			this->btn_selectDestination->Text = L"Select Destination";
			this->btn_selectDestination->UseVisualStyleBackColor = true;
			this->btn_selectDestination->Click += gcnew System::EventHandler(this, &View::btn_selectDestination_Click);
			// 
			// chk_demoMode
			// 
			this->chk_demoMode->AutoSize = true;
			this->chk_demoMode->Enabled = false;
			this->chk_demoMode->Location = System::Drawing::Point(408, 448);
			this->chk_demoMode->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->chk_demoMode->Name = L"chk_demoMode";
			this->chk_demoMode->Size = System::Drawing::Size(84, 17);
			this->chk_demoMode->TabIndex = 4;
			this->chk_demoMode->Text = L"Demo Mode";
			this->chk_demoMode->UseVisualStyleBackColor = true;
			this->chk_demoMode->CheckedChanged += gcnew System::EventHandler(this, &View::chk_demoMode_CheckedChanged);
			// 
			// btn_demoNext
			// 
			this->btn_demoNext->Enabled = false;
			this->btn_demoNext->Location = System::Drawing::Point(496, 441);
			this->btn_demoNext->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn_demoNext->Name = L"btn_demoNext";
			this->btn_demoNext->Size = System::Drawing::Size(76, 28);
			this->btn_demoNext->TabIndex = 5;
			this->btn_demoNext->Text = L"Next Node";
			this->btn_demoNext->UseVisualStyleBackColor = true;
			this->btn_demoNext->Click += gcnew System::EventHandler(this, &View::btn_demoNext_Click);
			// 
			// btn_demoPrev
			// 
			this->btn_demoPrev->Enabled = false;
			this->btn_demoPrev->Location = System::Drawing::Point(576, 441);
			this->btn_demoPrev->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn_demoPrev->Name = L"btn_demoPrev";
			this->btn_demoPrev->Size = System::Drawing::Size(70, 28);
			this->btn_demoPrev->TabIndex = 6;
			this->btn_demoPrev->Text = L"Prev Node";
			this->btn_demoPrev->UseVisualStyleBackColor = true;
			this->btn_demoPrev->Click += gcnew System::EventHandler(this, &View::btn_demoPrev_Click);
			// 
			// btn_runAlgorithm
			// 
			this->btn_runAlgorithm->Enabled = false;
			this->btn_runAlgorithm->Location = System::Drawing::Point(314, 441);
			this->btn_runAlgorithm->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn_runAlgorithm->Name = L"btn_runAlgorithm";
			this->btn_runAlgorithm->Size = System::Drawing::Size(90, 28);
			this->btn_runAlgorithm->TabIndex = 7;
			this->btn_runAlgorithm->Text = L"Run Algorithm";
			this->btn_runAlgorithm->UseVisualStyleBackColor = true;
			this->btn_runAlgorithm->Click += gcnew System::EventHandler(this, &View::btn_runAlgorithm_Click);
			// 
			// txt_errorOutput
			// 
			this->txt_errorOutput->Location = System::Drawing::Point(6, 474);
			this->txt_errorOutput->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txt_errorOutput->Multiline = true;
			this->txt_errorOutput->Name = L"txt_errorOutput";
			this->txt_errorOutput->ReadOnly = true;
			this->txt_errorOutput->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txt_errorOutput->Size = System::Drawing::Size(936, 46);
			this->txt_errorOutput->TabIndex = 8;
			// 
			// View
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(947, 525);
			this->Controls->Add(this->txt_errorOutput);
			this->Controls->Add(this->btn_runAlgorithm);
			this->Controls->Add(this->btn_demoPrev);
			this->Controls->Add(this->btn_demoNext);
			this->Controls->Add(this->chk_demoMode);
			this->Controls->Add(this->btn_selectDestination);
			this->Controls->Add(this->btn_selectSource);
			this->Controls->Add(this->pic_nodeVisuals);
			this->Controls->Add(this->btn_generateNodes);
			this->Location = System::Drawing::Point(102, 13);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MaximumSize = System::Drawing::Size(968, 580);
			this->MinimumSize = System::Drawing::Size(670, 440);
			this->Name = L"View";
			this->Text = L"View";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_nodeVisuals))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: static const int radius = 20;
	private: SelectionMode currentMode = SelectionMode::None;
	private: static List<Point>^ nodePositions = gcnew List<Point>(/*model::MAX_NODES*/);
	private: static List<Tuple<int, int>^>^ shortestPathEdges = gcnew List<Tuple<int, int>^>(/*model::MAX_NODES*/);
	private: static List<int>^ parent = gcnew List<int>(/*model::MAX_NODES*/);

	private: static int srcNode = -1;
	private: static int destNode = -1;

	private: static bool demoMode = false;
	private: static int currentStep = 0;

	private: Void btn_generateNodes_Click(Object^ sender, EventArgs^ e) {
		// Check if first time running or variables reset to run again
		if (srcNode != -1 && destNode != -1) {
			clearVariables();
		}
		else {
			randomGenerator();

			// Clear previous drawing
			pic_nodeVisuals->CreateGraphics()->Clear(SystemColors::Control);

			// Draw the graph
			drawGraph(model::graph);

			// Enable selectSource button for next step
			btn_selectSource->Enabled = true;
		}
	}

	private: Void pic_nodeVisuals_MouseClick(Object^ sender, Windows::Forms::MouseEventArgs^ e) {
		switch (currentMode) {
		case SelectSource:
			selectSource(e->Location);
			break;
		case SelectDestination:
			selectDestination(e->Location);
			break;
		case None:
			txt_errorOutput->Text += "Error: Please select source node to begin";
		}
	}

	private: Void btn_selectSource_Click(Object^ sender, EventArgs^ e) {
		currentMode = SelectSource;
		btn_selectSource->Enabled = false;
		btn_selectDestination->Enabled = true;
	}

	private: Void btn_selectDestination_Click(Object^ sender, EventArgs^ e) {
		currentMode = SelectDestination;
		btn_selectDestination->Enabled = false;
		btn_runAlgorithm->Enabled = true;
	}

	private: Void btn_runAlgorithm_Click(Object^ sender, EventArgs^ e) {
		// Check srcNode and destNode not equal to -1 (uninitialised) and then run algorithm
		if (srcNode != -1 && destNode != -1) {
			dijkstra(model::graph, srcNode, destNode);
			txt_errorOutput->Text += "\t Successfully ran dijkstra's";
			updateVisualisation();
			//clearVariables();
			std::cout << "Test output";
		}
		else {
			txt_errorOutput->Text += "\t Couldn't run dijkstra's, src node or dest node not selected";
			txt_errorOutput->Text += "\t SrcNode: " + srcNode + "\t DestNode: " + destNode;
		}
	}

	private: Void chk_demoMode_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (!chk_demoMode->Checked) {
			demoMode = false;
			btn_demoNext->Enabled = false;
			btn_demoPrev->Enabled = false;
		}
		else {
			demoMode = true;
			btn_demoNext->Enabled = true;
			btn_demoPrev->Enabled = true;
		}
	}

	private: Void btn_demoNext_Click(System::Object^ sender, System::EventArgs^ e) {
		if (currentStep < model::MAX_NODES) {
			currentStep++;
			//dijkstra(model::graph, srcNode, destNode);
			updateVisualisation();
		}
		else {
			txt_errorOutput->Text += "\t Error: Can't exceed max number of nodes";
		}
	}

	private: Void btn_demoPrev_Click(System::Object^ sender, System::EventArgs^ e) {
		if (currentStep > 0) {
			currentStep--;
			//dijkstra(model::graph, srcNode, destNode);
			updateVisualisation();
		}
		else {
			txt_errorOutput->Text += "\t Error: Can't go to previous nodes as current node is source node. Please press next and try again.";
		}
	}

	void addEdge(int u, int v) {
		// TODO: After running code will fail at this line, I'm guessing model::graph is uninitialised due to us clearing it previously (quick-fix implemented stop clearing model::graph after execution)
		model::graph[u][v] = rand() % 100 + 1;
		model::graph[v][u] = model::graph[u][v];
	}

	void randomGenerator() {
		// Initialise rand value to current system time
		srand(time(nullptr));

		// Add random edges to the graph
		for (int i = 0; i < model::MAX_NODES; i++) {
			for (int j = 0; j < model::MAX_NODES; j++) {
				if (i != j && rand() % 4 == 0) {
					addEdge(i, j);
				}
			}
		}
	}

	// Dijkstra's algorithm
	void dijkstra(const std::vector<std::vector<int>> &graph, int srcNode, int destNode) {
		std::vector<int> dist(model::MAX_NODES, INT_MAX);  // The output array. dist[i] will hold the shortest distance from src to i
		std::vector<bool> visited(model::MAX_NODES, false); // visited[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is finalized.
		std::vector<int> parent(model::MAX_NODES, -1); // parent array to store shortest path tree

		dist[srcNode] = 0;

		for (int loop = 0; loop < model::MAX_NODES; loop++) {
			int minDist = minimumDistance(dist, visited);
			visited[minDist] = true;
			for (int index = 0; index < model::MAX_NODES; index++) {
				if (!visited[index] && model::graph[minDist][index] && dist[minDist] != INT_MAX && dist[minDist] + model::graph[minDist][index] < dist[index]) {
					parent[index] = minDist;
					dist[index] = dist[minDist] + model::graph[minDist][index];
				}
			}
		}

		// After the algorithm runs, store the edges of the shortest path
		if (srcNode != destNode) {
			int current = destNode;
			while (current != srcNode) {
				int prev = parent[current];
				shortestPathEdges->Add(Tuple::Create(prev, current));

				current = prev;
			}
			shortestPathEdges->Reverse();
		}
	}

	// Function to find the vertex with the minimum distance value
	int minimumDistance(const std::vector<int> &dist, const std::vector<bool> &visited) {
		int min = INT_MAX, index = -1;

		for (int i = 0; i < model::MAX_NODES; i++) {
			if (!visited[i] && dist[i] <= min) {
				min = dist[i];
				index = i;
			}
		}
		return index;
	}

	// Function to draw nodes
	void drawNode(int x, int y, int nodeID) {
		Graphics^ g = pic_nodeVisuals->CreateGraphics();
		g->FillEllipse(Brushes::LightBlue, x - radius, y - radius, 2 * radius, 2 * radius);

		// Draw nodeID within the node
		PointF point = PointF(x, y);
		g->DrawString(nodeID.ToString(), gcnew Drawing::Font("Arial Bold", 11), Brushes::Black, point);
	}

	// Function to draw edges
	void drawEdge(int x1, int y1, int x2, int y2, Color edgeColor, Color brushColor, float penWidth, int fontSize, int weight) {
		Pen^ pen = gcnew Pen(edgeColor);
		SolidBrush^ brush = gcnew SolidBrush(brushColor);
		pen->Width = penWidth;
		Graphics^ g = pic_nodeVisuals->CreateGraphics();
		g->DrawLine(pen, x1, y1, x2, y2);

		// Draw weight of edge
		PointF point = PointF((x1 + x2) / 2, (y1 + y2) / 2);
		g->DrawString(weight.ToString(), gcnew Drawing::Font("Arial", fontSize), brush, point);
	}

	// Function to draw the graph
	void drawGraph(const std::vector<std::vector<int>> &graph) {
		nodePositions = gcnew List<Point>(model::MAX_NODES);
		for (int i = 0; i < model::MAX_NODES; i++) {
			int x = rand() % (pic_nodeVisuals->Width - 2 * radius) + radius;
			int y = rand() % (pic_nodeVisuals->Height - 2 * radius) + radius;
			nodePositions->Add(Point(x, y));
			drawNode(x, y, i);
		}
		for (int i = 0; i < model::MAX_NODES; i++) {
			for (int j = 0; j < model::MAX_NODES; j++) {
				if (graph[i][j] > 0) {
					Color lineColor = Color::Black; // Default color is black
					Color textColor = Color::Red;
					float penWidth = 1.5;
					int fontSize = 10;
					drawEdge(nodePositions[i].X, nodePositions[i].Y, nodePositions[j].X, nodePositions[j].Y, lineColor, textColor, penWidth, fontSize, model::graph[i][j]);
				}
			}
		}
	}

	void selectSource(Point &clickLocation) {
		// Selects Source Node
		srcNode = searchNodePositionsForClickLocation(clickLocation);
		txt_errorOutput->Text += "\t Source Node: " + srcNode;
	}

	void selectDestination(Point &clickLocation) {
		// Selects Destination Node
		destNode = searchNodePositionsForClickLocation(clickLocation);
		txt_errorOutput->Text += "\t Dest Node: " + destNode;
	}

	int searchNodePositionsForClickLocation(Point %clickLocation) {
		for (int i = 0; i < model::MAX_NODES; i++) {
			Point node(nodePositions[i].X, nodePositions[i].Y);

			// Assuming a circular node with a radius of 20 pixels
			if (clickLocation.X >= node.X - radius && clickLocation.X <= node.X + radius &&
				clickLocation.Y >= node.Y - radius && clickLocation.Y <= node.Y + radius) {
				// Click location is within the radius of the node, return the index
				txt_errorOutput->Text += "\t Click location within node range. Index: " + i;
				return i;
			}
		}

		// Click location not found within any node
		// TODO: Error message if node not found within click radius
		return -1;
	}

	void updateVisualisation() {
		// TODO: Update visualisation after dijkstra's algorithm runs
		drawGraphWithShortestPath(model::graph, shortestPathEdges);
		txt_errorOutput->Text += "\t Should have updated";
	}

	void drawGraphWithShortestPath(const std::vector<std::vector<int>>& graph, List<Tuple<int, int>^>^ shortestPathEdges) {
		Graphics^ g = pic_nodeVisuals->CreateGraphics();

		// Draw Edges
		for (int i = 0; i < model::MAX_NODES; i++) {
			for (int j = i + 1; j < model::MAX_NODES; j++) {  // Draw only one side of the symmetric graph
				if (graph[i][j]) {
					// Determine the color based on whether the edge belongs to the shortest path
					Color lineColor = Color::Black; // Default color is black
					Color textColor = Color::Red;
					float penWidth = 1.3;
					int fontSize = 10;
					String^ weightText = System::Convert::ToString(graph[i][j]);

					// Check if the current edge is in the shortest path
					for each (Tuple<int, int> ^ edge in shortestPathEdges) {
						if ((edge->Item1 == i && edge->Item2 == j) || (edge->Item1 == j && edge->Item2 == i)) {
							lineColor = Color::Green; // Change color to green if it's in the shortest path
							textColor = Color::Green;
							penWidth = 2.5;
							fontSize = 12;
							break; // No need to continue checking once found
						}
					}
					// TODO: Clear the page before reprinting because there are currently duplicate numbers in different colors
					// Draw edge with correct color and weight
					drawEdge(nodePositions[i].X, nodePositions[i].Y, nodePositions[j].X, nodePositions[j].Y, lineColor, textColor, penWidth, fontSize, graph[i][j]);
				}
			}
		}
	}


	void clearVariables() {
		// Clear vectors and release memory
		//for (auto& innerVec : model::graph) {
		//	// Check if innerVec is empty before clearing
		//	if (!innerVec.empty()) {
		//		innerVec.clear(); // Clear all values
		//		//innerVec.shrink_to_fit(); // Release memory held by vector
		//	}
		//}

		// Reset variables
		srcNode = -1;
		destNode = -1;

		//model::graph.clear(); // Clear outer vector
		//model::graph.shrink_to_fit(); // Release memory held

		//if (nodePositions != nullptr) delete nodePositions;
		shortestPathEdges->Clear();
		parent->Clear();

		chk_demoMode->Checked = false;
		std::cout << demoMode;

		currentMode = SelectionMode::None;
	}
};
}
