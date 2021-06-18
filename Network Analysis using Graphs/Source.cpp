#include"Header.h"

int main() {
	//string dataPath = "C:\\Users\\abdul\\source\\repos\\Network Analysis using Graphs\\Network Analysis using Graphs\\Text.txt";
	string dataPath = "C:\\Users\\zohai\\Desktop\\CA-GrQc.txt";
	graph G1;
	G1.createGraph(dataPath);

	// Part 1
	G1.numberOfNodes();
	G1.numberOfEdges();
	G1.numberOfSourceNodes();
	G1.numberOfSinkNodes();
	G1.numberOfIsolatedNodes();
	G1.noOfArticulationNodes();

	//G1.findShortestPath(3466, 10310);
	//G1.findShortestPath(3466, 1854);
	//G1.findShortestPath(3466, 495);
	//G1.findShortestPath(3466, 17968);
	//G1.findShortestPath(14845, 9450);
	//G1.findAllShortestPaths();
	G1.findShortestPath(25543, 26048);


	/*componentListNode* temp = G1.findBi(G1.IDIsPresent(3466)->address);
	cout << temp->ver->getID() << " " << temp->size << " ";
	listNode* temp2 = temp->bi;
	while (temp2 != 0)
	{
		cout << temp2->address->getID() << " ";
		temp2 = temp2->next;
	}
	cout << endl;*/

	// Part 2
	/*G1.displayInDegree();
	G1.displayOutDegree();*/

	// Part 3
	G1.findLargestSCC();
	cout << endl;
	cout << endl;
	G1.displaySCC();
}