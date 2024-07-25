#pragma once
#include <cstdlib>
#include <list>
#include <ctime>
#include <vector>
#include <climits>
#include <Windows.h>
#include <cmath>
#include <iostream>
#include <fstream>
#include <utility>

#include "Model.h"
#include "DrawingHelper.h"
#include "GraphManager.h"
#include "Dijkstra.h"

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

	public ref class View : public Form
	{
	public:
		View(void)
		{
			InitializeComponent();
		}

	protected:
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
			this->btn_generateNodes->Location = System::Drawing::Point(1674, 1040);
			this->btn_generateNodes->Margin = System::Windows::Forms::Padding(4, 6, 4, 6);
			this->btn_generateNodes->MaximumSize = System::Drawing::Size(288, 50);
			this->btn_generateNodes->MinimumSize = System::Drawing::Size(288, 50);
			this->btn_generateNodes->Name = L"btn_generateNodes";
			this->btn_generateNodes->Size = System::Drawing::Size(288, 50);
			this->btn_generateNodes->TabIndex = 0;
			this->btn_generateNodes->Text = L"Generate Nodes";
			this->btn_generateNodes->UseVisualStyleBackColor = true;
			this->btn_generateNodes->Click += gcnew System::EventHandler(this, &View::btn_generateNodes_Click);
			// 
			// pic_nodeVisuals
			// 
			this->pic_nodeVisuals->BackColor = System::Drawing::SystemColors::ControlLight;
			this->pic_nodeVisuals->Location = System::Drawing::Point(26, 27);
			this->pic_nodeVisuals->Margin = System::Windows::Forms::Padding(4, 6, 4, 6);
			this->pic_nodeVisuals->MinimumSize = System::Drawing::Size(1592, 923);
			this->pic_nodeVisuals->Name = L"pic_nodeVisuals";
			this->pic_nodeVisuals->Size = System::Drawing::Size(1636, 1181);
			this->pic_nodeVisuals->TabIndex = 1;
			this->pic_nodeVisuals->TabStop = false;
			this->pic_nodeVisuals->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &View::pic_nodeVisuals_MouseClick);
			// 
			// btn_runAlgorithm
			// 
			this->btn_runAlgorithm->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_runAlgorithm->Location = System::Drawing::Point(1966, 1040);
			this->btn_runAlgorithm->Margin = System::Windows::Forms::Padding(4, 6, 4, 6);
			this->btn_runAlgorithm->MaximumSize = System::Drawing::Size(288, 50);
			this->btn_runAlgorithm->MinimumSize = System::Drawing::Size(288, 50);
			this->btn_runAlgorithm->Name = L"btn_runAlgorithm";
			this->btn_runAlgorithm->Size = System::Drawing::Size(288, 50);
			this->btn_runAlgorithm->TabIndex = 7;
			this->btn_runAlgorithm->Text = L"Run Algorithm";
			this->btn_runAlgorithm->UseVisualStyleBackColor = true;
			this->btn_runAlgorithm->Click += gcnew System::EventHandler(this, &View::btn_runAlgorithm_Click);
			// 
			// txt_messageOutput
			// 
			this->txt_messageOutput->Location = System::Drawing::Point(1674, 27);
			this->txt_messageOutput->Margin = System::Windows::Forms::Padding(4, 6, 4, 6);
			this->txt_messageOutput->MaximumSize = System::Drawing::Size(580, 998);
			this->txt_messageOutput->MinimumSize = System::Drawing::Size(580, 998);
			this->txt_messageOutput->Multiline = true;
			this->txt_messageOutput->Name = L"txt_messageOutput";
			this->txt_messageOutput->ReadOnly = true;
			this->txt_messageOutput->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txt_messageOutput->Size = System::Drawing::Size(580, 998);
			this->txt_messageOutput->TabIndex = 8;
			// 
			// btn_saveGraph
			// 
			this->btn_saveGraph->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_saveGraph->Location = System::Drawing::Point(1674, 1102);
			this->btn_saveGraph->Margin = System::Windows::Forms::Padding(4, 6, 4, 6);
			this->btn_saveGraph->MaximumSize = System::Drawing::Size(288, 50);
			this->btn_saveGraph->MinimumSize = System::Drawing::Size(288, 50);
			this->btn_saveGraph->Name = L"btn_saveGraph";
			this->btn_saveGraph->Size = System::Drawing::Size(288, 50);
			this->btn_saveGraph->TabIndex = 9;
			this->btn_saveGraph->Text = L"Save Graph";
			this->btn_saveGraph->UseVisualStyleBackColor = true;
			this->btn_saveGraph->Click += gcnew System::EventHandler(this, &View::btn_saveGraph_Click);
			// 
			// btn_loadGraph
			// 
			this->btn_loadGraph->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_loadGraph->Location = System::Drawing::Point(1966, 1102);
			this->btn_loadGraph->Margin = System::Windows::Forms::Padding(4, 6, 4, 6);
			this->btn_loadGraph->MaximumSize = System::Drawing::Size(288, 50);
			this->btn_loadGraph->MinimumSize = System::Drawing::Size(288, 50);
			this->btn_loadGraph->Name = L"btn_loadGraph";
			this->btn_loadGraph->Size = System::Drawing::Size(288, 50);
			this->btn_loadGraph->TabIndex = 10;
			this->btn_loadGraph->Text = L"Load Graph";
			this->btn_loadGraph->UseVisualStyleBackColor = true;
			this->btn_loadGraph->Click += gcnew System::EventHandler(this, &View::btn_loadGraph_Click);
			// 
			// View
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(2264, 1169);
			this->Controls->Add(this->btn_loadGraph);
			this->Controls->Add(this->btn_saveGraph);
			this->Controls->Add(this->txt_messageOutput);
			this->Controls->Add(this->btn_runAlgorithm);
			this->Controls->Add(this->btn_generateNodes);
			this->Controls->Add(this->pic_nodeVisuals);
			this->Location = System::Drawing::Point(102, 13);
			this->Margin = System::Windows::Forms::Padding(4, 6, 4, 6);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(2290, 1240);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(2290, 1240);
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
		SelectionMode currentMode = SelectionMode::None;
		static int srcNode = -1;
		static int destNode = -1;

		Void btn_generateNodes_Click(System::Object^ sender, System::EventArgs^ e) {
			if (srcNode != -1 && destNode != -1) {
				resetVariables();
			}
			else {
				resetVariables();
				GraphManager::RandomGenerator(pic_nodeVisuals->Width, pic_nodeVisuals->Height);
				DrawingHelper::ClearDisplay(pic_nodeVisuals->CreateGraphics(), pic_nodeVisuals);
				DrawingHelper::DrawGraph(pic_nodeVisuals->CreateGraphics(), Model::graph, GraphManager::GetNodePositions(), DrawingHelper::radius);
			}
		}

		Void pic_nodeVisuals_MouseClick(Object^ sender, Windows::Forms::MouseEventArgs^ e) { // TODO: Update this to offer left click / right click selecting of nodes
			if (e->Button == System::Windows::Forms::MouseButtons::Left) {
				selectSource(e->Location);
			}
			else if (e->Button == System::Windows::Forms::MouseButtons::Right) {
				selectDestination(e->Location);
			}
		}

		Void btn_runAlgorithm_Click(Object^ sender, EventArgs^ e) {
			// Check srcNode and destNode not equal to -1 (uninitialised) and then run algorithm
			if (srcNode != -1 && destNode != -1) {
				Dijkstra::dijkstra(Model::graph, srcNode, destNode, Model::shortestPathEdges);
				txt_messageOutput->AppendText("Algorithm finished" + "\r\n");
				updateVisualisation();
			}
			else {
				txt_messageOutput->AppendText("Error: Failed to run dijkstra's. Please select a valid source node and destination nodes." + "\r\n");
			}
		}

		Void btn_saveGraph_Click(System::Object^ sender, System::EventArgs^ e) { // TODO: Add null graph checks before saving
			SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
			saveFileDialog->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
			saveFileDialog->FilterIndex = 1;
			saveFileDialog->RestoreDirectory = true;
			if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				GraphManager::SaveGraphToFile(saveFileDialog->FileName, GraphManager::GetNodePositions());
				txt_messageOutput->AppendText("Graph saved successfully.\r\n");
			}
		}

		Void btn_loadGraph_Click(System::Object^ sender, System::EventArgs^ e) { // TODO: Add null file checks before loading into the graph
			OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
			openFileDialog->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
			openFileDialog->FilterIndex = 1;
			openFileDialog->RestoreDirectory = true;
			resetVariables();
			if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				GraphManager::LoadGraphFromFile(openFileDialog->FileName, GraphManager::GetNodePositions(), pic_nodeVisuals->CreateGraphics(), pic_nodeVisuals, DrawingHelper::radius);
				txt_messageOutput->AppendText("Graph loaded successfully.\r\n");
			}
		}

		void selectSource(Point& clickLocation) {
			// Selects Source Node
			srcNode = searchNodePositionsForClickLocation(clickLocation);
			if (srcNode != -1) {
				txt_messageOutput->AppendText("Source Node Selected: " + srcNode + "\r\n");
			}
			else {
				return;
			}
		}

		void selectDestination(Point& clickLocation) {
			// Selects Destination Node
			destNode = searchNodePositionsForClickLocation(clickLocation);
			if (destNode != -1) {
				txt_messageOutput->AppendText("Destination Node Selected: " + destNode + "\r\n");
			}
			else {
				return;
			}
		}

		int searchNodePositionsForClickLocation(Point% clickLocation) {
			for (int i = 0; i < Model::MAX_NODES; i++) {
				Point node(GraphManager::GetNodePositionIndex(i).X, GraphManager::GetNodePositionIndex(i).Y);

				// Assuming a circular node with a radius of 20 pixels
				if (clickLocation.X >= node.X - DrawingHelper::radius && clickLocation.X <= node.X + DrawingHelper::radius &&
					clickLocation.Y >= node.Y - DrawingHelper::radius && clickLocation.Y <= node.Y + DrawingHelper::radius) {
					// Click location is within the radius of the node, return the index
					return i;
				}
			}

			// No valid node is found, display the error message
			txt_messageOutput->AppendText("Error: Please click on a node to select it." + "\r\n");
			return -1;
		}

		void updateVisualisation() {
			// Create a bitmap for double buffering
			Bitmap^ buffer = gcnew Bitmap(pic_nodeVisuals->Width, pic_nodeVisuals->Height);
			Graphics^ g = Graphics::FromImage(buffer);

			// Clear the graphics
			g->Clear(pic_nodeVisuals->BackColor);

			// Draw the graph with the shortest path
			drawGraphWithShortestPath(Model::graph, g);

			// Draw the bitmap on the picture box
			pic_nodeVisuals->Image = buffer;

			resetVariables();

			txt_messageOutput->AppendText("Shortest path calculated." + "\r\n");
			//txt_messageOutput->AppendText("Shortest path is:" + "\r\n");
		}

		void drawGraphWithShortestPath(const std::vector<std::vector<int>>& graph, Graphics^ g) {
			// Draw Edges
			for (int i = 0; i < Model::MAX_NODES; i++) {
				for (int j = i + 1; j < Model::MAX_NODES; j++) {  // Draw only one side of the symmetric graph
					if (graph[i][j]) {
						// Determine the color based on whether the edge belongs to the shortest path
						Color lineColor = Color::Black; // Default color is black
						Color textColor = Color::Red;
						double penWidth = 1.3;
						int fontSize = 10;
						String^ weightText = System::Convert::ToString(graph[i][j]);

						// Check if the current edge is in the shortest path
						for (const auto& edge : Model::shortestPathEdges) {
							if ((edge.first == i && edge.second == j) || (edge.first == j && edge.second == i)) {
								lineColor = Color::Green; // Change color to green if it's in the shortest path
								textColor = Color::Green;
								penWidth = 2.5;
								fontSize = 12;
								break; // No need to continue checking once found
							}
						}

						// Draw Nodes
						if (GraphManager::GetNodePositions() != nullptr) {
							for (int i = 0; i < Model::MAX_NODES; i++) {
								DrawingHelper::DrawNode(g, GraphManager::GetNodePositionIndex(i).X, GraphManager::GetNodePositionIndex(i).Y, i);
							}
						}

						// Draw edge with correct color and weight
						DrawingHelper::DrawEdge(g, GraphManager::GetNodePositionIndex(i).X, GraphManager::GetNodePositionIndex(i).Y, GraphManager::GetNodePositionIndex(j).X, GraphManager::GetNodePositionIndex(j).Y, lineColor, textColor, penWidth, fontSize, graph[i][j]);
					}
				}
			}
		}

		void resetVariables() {
			// Clear the graph for next running
			//GraphManager::ClearGraph();

			Model::shortestPathEdges.clear();

			// Reset variables
			srcNode = -1;
			destNode = -1;

			currentMode = SelectionMode::None;
		}
};
}
