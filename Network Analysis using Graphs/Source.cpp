#include"Header.h"

int main() {
	string dataPath = "C:\\Users\\abdul\\source\\repos\\Network Analysis using Graphs\\Network Analysis using Graphs\\Text.txt";
	graph G1;
	G1.createTree(dataPath);

	// Part 1
	G1.numberOfNodes();
	G1.numberOfEdges();
	G1.numberOfSourceNodes();
	G1.numberOfSinkNodes();
	G1.numberOfIsolatedNodes();

	// Part 2
	G1.displayInDegree();
	G1.displayOutDegree();
}