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
#include <fstream>
#include <utility>
#include <msclr/marshal_cppstd.h>

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
	private:
		System::Windows::Forms::Button^ btn_generateNodes;
		System::Windows::Forms::PictureBox^ pic_nodeVisuals;
		System::Windows::Forms::Button^ btn_selectSource;
		System::Windows::Forms::Button^ btn_selectDestination;
		System::Windows::Forms::Button^ btn_runAlgorithm;
		System::Windows::Forms::TextBox^ txt_messageOutput;
		System::Windows::Forms::Button^ btn_saveGraph;
		System::Windows::Forms::Button^ btn_loadGraph;

		System::ComponentModel::Container^ components;

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
			this->btn_runAlgorithm = (gcnew System::Windows::Forms::Button());
			this->txt_messageOutput = (gcnew System::Windows::Forms::TextBox());
			this->btn_saveGraph = (gcnew System::Windows::Forms::Button());
			this->btn_loadGraph = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_nodeVisuals))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_generateNodes
			// 
			this->btn_generateNodes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_generateNodes->Location = System::Drawing::Point(837, 541);
			this->btn_generateNodes->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->btn_generateNodes->MaximumSize = System::Drawing::Size(144, 26);
			this->btn_generateNodes->MinimumSize = System::Drawing::Size(144, 26);
			this->btn_generateNodes->Name = L"btn_generateNodes";
			this->btn_generateNodes->Size = System::Drawing::Size(144, 26);
			this->btn_generateNodes->TabIndex = 0;
			this->btn_generateNodes->Text = L"Generate Nodes";
			this->btn_generateNodes->UseVisualStyleBackColor = true;
			this->btn_generateNodes->Click += gcnew System::EventHandler(this, &View::btn_generateNodes_Click);
			// 
			// pic_nodeVisuals
			// 
			this->pic_nodeVisuals->BackColor = System::Drawing::SystemColors::ControlDark;
			this->pic_nodeVisuals->Location = System::Drawing::Point(13, 14);
			this->pic_nodeVisuals->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->pic_nodeVisuals->MinimumSize = System::Drawing::Size(796, 480);
			this->pic_nodeVisuals->Name = L"pic_nodeVisuals";
			this->pic_nodeVisuals->Size = System::Drawing::Size(818, 614);
			this->pic_nodeVisuals->TabIndex = 1;
			this->pic_nodeVisuals->TabStop = false;
			this->pic_nodeVisuals->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &View::pic_nodeVisuals_MouseClick);
			// 
			// btn_selectSource
			// 
			this->btn_selectSource->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_selectSource->Location = System::Drawing::Point(985, 541);
			this->btn_selectSource->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->btn_selectSource->MaximumSize = System::Drawing::Size(144, 26);
			this->btn_selectSource->MinimumSize = System::Drawing::Size(144, 26);
			this->btn_selectSource->Name = L"btn_selectSource";
			this->btn_selectSource->Size = System::Drawing::Size(144, 26);
			this->btn_selectSource->TabIndex = 2;
			this->btn_selectSource->Text = L"Select Source";
			this->btn_selectSource->UseVisualStyleBackColor = true;
			this->btn_selectSource->Click += gcnew System::EventHandler(this, &View::btn_selectSource_Click);
			// 
			// btn_selectDestination
			// 
			this->btn_selectDestination->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btn_selectDestination->Location = System::Drawing::Point(837, 573);
			this->btn_selectDestination->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->btn_selectDestination->MaximumSize = System::Drawing::Size(144, 26);
			this->btn_selectDestination->MinimumSize = System::Drawing::Size(144, 26);
			this->btn_selectDestination->Name = L"btn_selectDestination";
			this->btn_selectDestination->Size = System::Drawing::Size(144, 26);
			this->btn_selectDestination->TabIndex = 3;
			this->btn_selectDestination->Text = L"Select Destination";
			this->btn_selectDestination->UseVisualStyleBackColor = true;
			this->btn_selectDestination->Click += gcnew System::EventHandler(this, &View::btn_selectDestination_Click);
			// 
			// btn_runAlgorithm
			// 
			this->btn_runAlgorithm->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_runAlgorithm->Location = System::Drawing::Point(985, 573);
			this->btn_runAlgorithm->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->btn_runAlgorithm->MaximumSize = System::Drawing::Size(144, 26);
			this->btn_runAlgorithm->MinimumSize = System::Drawing::Size(144, 26);
			this->btn_runAlgorithm->Name = L"btn_runAlgorithm";
			this->btn_runAlgorithm->Size = System::Drawing::Size(144, 26);
			this->btn_runAlgorithm->TabIndex = 7;
			this->btn_runAlgorithm->Text = L"Run Algorithm";
			this->btn_runAlgorithm->UseVisualStyleBackColor = true;
			this->btn_runAlgorithm->Click += gcnew System::EventHandler(this, &View::btn_runAlgorithm_Click);
			// 
			// txt_messageOutput
			// 
			this->txt_messageOutput->Location = System::Drawing::Point(837, 14);
			this->txt_messageOutput->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->txt_messageOutput->MaximumSize = System::Drawing::Size(292, 521);
			this->txt_messageOutput->MinimumSize = System::Drawing::Size(292, 521);
			this->txt_messageOutput->Multiline = true;
			this->txt_messageOutput->Name = L"txt_messageOutput";
			this->txt_messageOutput->ReadOnly = true;
			this->txt_messageOutput->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txt_messageOutput->Size = System::Drawing::Size(292, 521);
			this->txt_messageOutput->TabIndex = 8;
			// 
			// btn_saveGraph
			// 
			this->btn_saveGraph->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_saveGraph->Location = System::Drawing::Point(837, 602);
			this->btn_saveGraph->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->btn_saveGraph->MaximumSize = System::Drawing::Size(144, 26);
			this->btn_saveGraph->MinimumSize = System::Drawing::Size(144, 26);
			this->btn_saveGraph->Name = L"btn_saveGraph";
			this->btn_saveGraph->Size = System::Drawing::Size(144, 26);
			this->btn_saveGraph->TabIndex = 9;
			this->btn_saveGraph->Text = L"Save Graph";
			this->btn_saveGraph->UseVisualStyleBackColor = true;
			this->btn_saveGraph->Click += gcnew System::EventHandler(this, &View::btn_saveGraph_Click);
			// 
			// btn_loadGraph
			// 
			this->btn_loadGraph->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_loadGraph->Location = System::Drawing::Point(985, 602);
			this->btn_loadGraph->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->btn_loadGraph->MaximumSize = System::Drawing::Size(144, 26);
			this->btn_loadGraph->MinimumSize = System::Drawing::Size(144, 26);
			this->btn_loadGraph->Name = L"btn_loadGraph";
			this->btn_loadGraph->Size = System::Drawing::Size(144, 26);
			this->btn_loadGraph->TabIndex = 10;
			this->btn_loadGraph->Text = L"Load Graph";
			this->btn_loadGraph->UseVisualStyleBackColor = true;
			this->btn_loadGraph->Click += gcnew System::EventHandler(this, &View::btn_loadGraph_Click);
			// 
			// View
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1142, 640);
			this->Controls->Add(this->btn_loadGraph);
			this->Controls->Add(this->btn_saveGraph);
			this->Controls->Add(this->txt_messageOutput);
			this->Controls->Add(this->btn_runAlgorithm);
			this->Controls->Add(this->btn_selectDestination);
			this->Controls->Add(this->btn_selectSource);
			this->Controls->Add(this->btn_generateNodes);
			this->Controls->Add(this->pic_nodeVisuals);
			this->Location = System::Drawing::Point(102, 13);
			this->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1158, 679);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(1158, 679);
			this->Name = L"View";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Computing the Shortest Path between Nodes";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_nodeVisuals))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		static const int radius = 20;
		SelectionMode currentMode = SelectionMode::None;
		static List<Point>^ nodePositions = gcnew List<Point>(/*model::MAX_NODES*/); // TODO: Move to model?
		static List<Tuple<int, int>^>^ shortestPathEdges = gcnew List<Tuple<int, int>^>(/*model::MAX_NODES*/); // TODO: Move to model?
		static List<int>^ parent = gcnew List<int>(/*model::MAX_NODES*/); // TODO: Move to model?

		static int srcNode = -1;
		static int destNode = -1;

		Void btn_generateNodes_Click(Object^ sender, EventArgs^ e) {
			// Check if first time running or variables reset to run again
			if (srcNode != -1 && destNode != -1) {
				resetVariables();
			}
			else {
				randomGenerator();

				// Clear previous drawing
				clearDisplay();

				// Draw the graph
				drawGraph(model::graph);

				// Enable selectSource button for next step
				btn_selectSource->Enabled = true;
			}
		}

		Void pic_nodeVisuals_MouseClick(Object^ sender, Windows::Forms::MouseEventArgs^ e) { // TODO: Update this to offer left click right click selecting of nodes
			switch (currentMode) {
			case SelectSource:
				selectSource(e->Location);
				break;
			case SelectDestination:
				selectDestination(e->Location);
				break;
			case None:
				txt_messageOutput->AppendText("Error: Please select source node to begin" + "\r\n");
			}
		}

		Void btn_selectSource_Click(Object^ sender, EventArgs^ e) {
			currentMode = SelectSource;
			btn_selectSource->Enabled = false;
			btn_selectDestination->Enabled = true;
		}

		Void btn_selectDestination_Click(Object^ sender, EventArgs^ e) {
			currentMode = SelectDestination;
			btn_selectDestination->Enabled = false;
			btn_runAlgorithm->Enabled = true;
		}

		Void btn_runAlgorithm_Click(Object^ sender, EventArgs^ e) {
			// Check srcNode and destNode not equal to -1 (uninitialised) and then run algorithm
			if (srcNode != -1 && destNode != -1) {
				dijkstra(model::graph, srcNode, destNode);
				txt_messageOutput->AppendText("Successfully ran dijkstra's" + "\r\n");
				updateVisualisation();
				//clearVariables();
			}
			else {
				txt_messageOutput->AppendText("Error: Failed to run dijkstra's. Please select source node or destination node first" + "\r\n");
				txt_messageOutput->AppendText("Selected Source Node: " + srcNode + "\r\n");
				txt_messageOutput->AppendText("Selected Destination Node: " + destNode + "\r\n");
			}
		}

		Void btn_saveGraph_Click(System::Object^ sender, System::EventArgs^ e) {
			SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
			saveFileDialog->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
			saveFileDialog->FilterIndex = 1;
			saveFileDialog->RestoreDirectory = true;

			if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				saveGraphToFile(saveFileDialog->FileName);
			}
		}

		Void btn_loadGraph_Click(System::Object^ sender, System::EventArgs^ e) {
			OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
			openFileDialog->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
			openFileDialog->FilterIndex = 1;
			openFileDialog->RestoreDirectory = true;

			if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				loadGraphFromFile(openFileDialog->FileName);
			}
		}

		void addEdge(int u, int v) {
			model::graph[u][v] = rand() % 100 + 1; // Add a random weight to the edge within the graph
			model::graph[v][u] = model::graph[u][v];
		}

		void randomGenerator() {
			// Clear the previous graph
			clearGraph();

			// Initialise rand value to current system time
			srand(time(nullptr));

			// Add random edges to the graph
			for (int i = 0; i < model::MAX_NODES; i++) {
				for (int j = 0; j < model::MAX_NODES; j++) {
					if (i != j && rand() % 25 == 0) {
						addEdge(i, j);
					}
				}
			}
		}

		   // Dijkstra's algorithm
		   void dijkstra(const std::vector<std::vector<int>>& graph, int srcNode, int destNode) {
			   std::vector<int> dist(model::MAX_NODES, INT_MAX);  // The output array. dist[i] will hold the shortest distance from src to i
			   std::vector<bool> visited(model::MAX_NODES, false); // Visited[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is finalised.
			   std::vector<int> parent(model::MAX_NODES, -1); // Parent array to store shortest path tree

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

		   // Helper Function for Dijkstras to find the vertex with the minimum distance value
		   int minimumDistance(const std::vector<int>& dist, const std::vector<bool>& visited) {
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
			   PointF point = PointF((x1 + x2) / 2, (y1 + y2) / 2); // Calculates the halfway point between the nodes to write the weight for the edge
			   g->DrawString(weight.ToString(), gcnew Drawing::Font("Arial", fontSize), brush, point); // Writes the weight of the edge at this point
		   }

		   // Function to draw the graph
		   void drawGraph(const std::vector<std::vector<int>>& graph) {
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

		   void selectSource(Point& clickLocation) {
			   // Selects Source Node
			   srcNode = searchNodePositionsForClickLocation(clickLocation);
			   txt_messageOutput->AppendText("Source Node Selected: " + srcNode + "\r\n");
		   }

		   void selectDestination(Point& clickLocation) {
			   // Selects Destination Node
			   destNode = searchNodePositionsForClickLocation(clickLocation);
			   txt_messageOutput->AppendText("Destination Node Selected: " + destNode + "\r\n");
		   }

		   int searchNodePositionsForClickLocation(Point% clickLocation) {
			   for (int i = 0; i < model::MAX_NODES; i++) {
				   Point node(nodePositions[i].X, nodePositions[i].Y);

				   // Assuming a circular node with a radius of 20 pixels
				   if (clickLocation.X >= node.X - radius && clickLocation.X <= node.X + radius &&
					   clickLocation.Y >= node.Y - radius && clickLocation.Y <= node.Y + radius) {
					   // Click location is within the radius of the node, return the index
					   // txt_messageOutput->AppendText("Selected Node: " + i + "\r\n"); // Debugging message
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
			   txt_messageOutput->AppendText("Shortest path calculated." + "\r\n");
			   txt_messageOutput->AppendText("Shortest path is:" + "\r\n");
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
								   fontSize = 11;
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

		   void clearGraph() {
			   // Clear the existing graph
			   for (int i = 0; i < model::MAX_NODES; i++) {
				   for (int j = 0; j < model::MAX_NODES; j++) {
					   model::graph[i][j] = 0;
					   model::graph[j][i] = model::graph[i][j]; // TODO: Check if this is required
				   }
			   }
		   }

		   void clearDisplay() {
			   Graphics^ g = pic_nodeVisuals->CreateGraphics();
			   g->Clear(pic_nodeVisuals->BackColor);
		   }

		   void resetVariables() {
			   // Clear the graph for next running
			   clearGraph();

			   // Reset variables
			   srcNode = -1;
			   destNode = -1;

			   //model::graph.clear(); // Clear outer vector
			   //model::graph.shrink_to_fit(); // Release memory held

			   //if (nodePositions != nullptr) delete nodePositions;
			   shortestPathEdges->Clear();
			   parent->Clear();

			   currentMode = SelectionMode::None;
		   }

		   void saveGraphToFile(String^ filePath) {
			   std::ofstream outFile(msclr::interop::marshal_as<std::string>(filePath));
			   if (!outFile.is_open()) {
				   txt_messageOutput->AppendText("Error: Unable to open file for writing.\r\n");
				   return;
			   }

			   // Save number of nodes
			   outFile << model::MAX_NODES << "\n";

			   // Save node positions with their indices
			   for (int i = 0; i < nodePositions->Count; i++) {
				   Point node = nodePositions[i];
				   outFile << i << " " << node.X << " " << node.Y << "\n";
			   }

			   // Save graph edges and weights
			   for (int i = 0; i < model::MAX_NODES; ++i) {
				   for (int j = i + 1; j < model::MAX_NODES; ++j) {
					   if (model::graph[i][j] > 0) {
						   outFile << i << " " << j << " " << model::graph[i][j] << "\n";
					   }
				   }
			   }

			   outFile.close();
			   txt_messageOutput->AppendText("Graph saved successfully.\r\n");
		   }

		   void loadGraphFromFile(String^ filePath) {
			   std::ifstream inFile(msclr::interop::marshal_as<std::string>(filePath));
			   if (!inFile.is_open()) {
				   txt_messageOutput->AppendText("Error: Unable to open file for reading.\r\n");
				   return;
			   }

			   // Clear existing graph and node positions
			   clearGraph();
			   nodePositions->Clear();

			   // Clear the screen
			   clearDisplay();

			   // Read number of nodes
			   int numNodes;
			   inFile >> numNodes;
			   if (numNodes != model::MAX_NODES) {
				   txt_messageOutput->AppendText("Error: Number of nodes in file does not match MAX_NODES.\r\n");
				   return;
			   }

			   // Load node positions
			   for (int i = 0; i < numNodes; i++) {
				   int index, x, y;
				   if (!(inFile >> index >> x >> y) || index != i) {
					   txt_messageOutput->AppendText("Error: Invalid node data in file.\r\n");
					   return;
				   }
				   nodePositions->Add(Point(x, y));
				   drawNode(x, y, i);
			   }

			   // Load graph edges and weights
			   int u, v, weight;
			   while (inFile >> u >> v >> weight) {
				   if (u < 0 || u >= numNodes || v < 0 || v >= numNodes) {
					   txt_messageOutput->AppendText("Error: Invalid node index in file.\r\n");
					   continue;
				   }
				   model::graph[u][v] = weight;
				   model::graph[v][u] = weight; // For undirected graph

				   // Draw the edge
				   drawEdge(nodePositions[u].X, nodePositions[u].Y,
					   nodePositions[v].X, nodePositions[v].Y,
					   Color::Black, Color::Red, 1.5f, 10, weight);
			   }

			   inFile.close();

			   // Reset selection variables
			   srcNode = -1;
			   destNode = -1;
			   currentMode = SelectionMode::None;
			   shortestPathEdges->Clear();

			   txt_messageOutput->AppendText("Graph loaded successfully.\r\n");
		   }
};
}
