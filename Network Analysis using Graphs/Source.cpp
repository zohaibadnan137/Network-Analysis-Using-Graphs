#include"Header.h"

int main() {
	string dataPath = "C:\\Users\\abdul\\source\\repos\\Network Analysis using Graphs\\Network Analysis using Graphs\\Text.txt";
	string d2 = "";
	//string dataPath = "C:\\Users\\zohai\\Desktop\\CA-GrQc.txt";
	graph G1;
	G1.createGraph(dataPath);

	// Part 1
	G1.numberOfNodes();
	G1.numberOfEdges();
	//G1.numberOfSourceNodes();
	//G1.numberOfSinkNodes();
	//G1.numberOfIsolatedNodes();
	//G1.noOfArticulationNodes();
	//G1.noOfBridgeEdges();
	//G1.checkArticulationNodes(3466);
	//G1.findShortestPath(3466, 10310);
	//G1.findShortestPath(3466, 1854);
	//G1.findShortestPath(3466, 495);
	//G1.findShortestPath(3466, 17968);
	//G1.findShortestPath(14845, 9450);
	//G1.findAllShortestPaths();

	// Part 2
	/*G1.displayInDegree();
	G1.displayOutDegree();*/
}