#include "Graph.h"
#include "MainForm.h"
#include "GlobalVariable.h"

using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace OfflineProgram;

// -- Global Variable --
// ====================================
int graph_color_red = 0xff0000;
int graph_color_green = 0x1dbd02;
int graph_color_blue = 0x052ea8;
double samplingTime = 50;
double logTime;
const int sampleSize = 100;
bool pause = false;

// Plot data variable
double timeData[sampleSize];
double sampleData[6][sampleSize];
double lineGraph[6];
string label[3];
void update_data();

// -- On Timer --
void Graph::on_timer() {
	update_data();
	show_chart();
	update_force_ui();
}

// -- Show graph --
void Graph::show_chart() {
	//int width = Graph::Size.Width - 150;
	//int height = Graph::Size.Height - 150;
	int width = 580;
	int height = 400;
	c = gcnew XYChart(width, height, 0xf4f4f4, 0x000000, 1);
	c->setPlotArea(50, 10, width - 80, height - 40, 0xffffff, -1, -1, 0xcccccc, 0xcccccc);
	c->setClipping();

	LegendBox ^ b = c->addLegend(50, 3);
	b->setBackground(Chart::Transparent, Chart::Transparent);
	b->setWidth(520);

	c->getLegend()->setFontSize(8);
	c->yAxis()->setTitle("Force (N)", "Arial Bold", 10);
	c->xAxis()->setWidth(2);
	c->yAxis()->setWidth(2);
	c->xAxis()->setDateScale3();
	
	//Convert the data format
	array<double> ^ xData = gcnew array<double>(sampleSize);
	array<double> ^ yData = gcnew array<double>(sampleSize);
	array<double> ^ yData1 = gcnew array<double>(sampleSize);
	array<double> ^ yData2 = gcnew array<double>(sampleSize);
	array<double> ^ yData3 = gcnew array<double>(sampleSize);
	array<double> ^ yData4 = gcnew array<double>(sampleSize);

	for (int i = 0; i < sampleSize; i++) {
		xData[i] = timeData[i];
		yData1[i] = sampleData[0][i];
		yData2[i] = sampleData[1][i];
		yData3[i] = sampleData[2][i];
		yData4[i] = sampleData[3][i];
	}

	String ^ _legend1 = gcnew String(label[0].c_str());
	String ^ _legend2 = gcnew String(label[1].c_str());
	String ^ _legend3 = gcnew String(label[2].c_str());

	// Add line layer
	LineLayer ^ layer = c->addLineLayer2();
	layer->setLineWidth(2);
	layer->setXData(xData);
	layer->addDataSet(yData1, graph_color_red, _legend1);
	layer->addDataSet(yData2, graph_color_green, _legend2);
	layer->addDataSet(yData3, graph_color_blue, _legend3);
	winChartViewer1->Chart = c;
}

void set_graph_data(double line1, double line2, double line3, string str1, string str2, string str3) {
	lineGraph[0] = line1;
	lineGraph[1] = line2;
	lineGraph[2] = line3;
	label[0] = str1;
	label[1] = str2;
	label[2] = str3;
}

void update_data() {
	int numOflineToPlot = 4;
	double Ts = samplingTime / 1000;
	logTime += Ts;
	for (int i = 1; i < sampleSize; i++)timeData[i - 1] = timeData[i];
	timeData[sampleSize - 1] = logTime;
	for (int j = 0; j < numOflineToPlot; j++) {
		for (int i = 1; i < sampleSize; i++) sampleData[j][i - 1] = sampleData[j][i];
		sampleData[j][sampleSize - 1] = lineGraph[j];
	}
}


void Graph::update_force_ui() {
	Vector3d force, trackBarVal, progressBarVal;
	force << lineGraph[0], lineGraph[1], lineGraph[2];

	tbFx->Text = force[0].ToString("N3");
	tbFy->Text = force[1].ToString("N3");
	tbFz->Text = force[2].ToString("N3");

	trackBarVal(0) = 50 - (force(0) * 15);
	trackBarVal(1) = 50 + (force(1) * 15);
	trackBarVal(2) = 50 + (force(2) * 15);

	for (int i = 0; i < 3; i++) { 
		if (trackBarVal(i) > 100) trackBarVal(i) = 100; 
		if (trackBarVal(i) < 0) trackBarVal(i) = 0;
	}

	trackBarX->Value = trackBarVal(0);
	trackBarY->Value = trackBarVal(1);
	trackBarZ->Value = trackBarVal(2);

	progressBarVal(0) = (abs(force(0)) / 5) * 100;
	progressBarVal(1) = (abs(force(1)) / 5) * 100;
	progressBarVal(2) = (abs(force(2)) / 5) * 100;
	for (int i = 0; i < 3; i++) if (progressBarVal(i) > 100) progressBarVal(i) = 100;

	progressBarX->Value = progressBarVal(0);
	progressBarY->Value = progressBarVal(1);
	progressBarZ->Value = progressBarVal(2);
}