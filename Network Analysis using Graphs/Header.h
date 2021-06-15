#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;



class vertex;

struct adjacencyListNode {
	int from;
	int to;

	adjacencyListNode* next;

	adjacencyListNode() {
		from = 0;
		to = 0;
		next = 0;
	}
};

struct listNode {
	vertex* address;
	listNode* next;

	listNode() {
		address = 0;
		next = 0;
	}
};

class vertex {

	int ID;
	listNode* inNodes;
	listNode* outNodes;

public:
	bool isSourceNode() {
		if (inNodes == NULL) {
			return true;
		}
		return false;
	}
	bool isSinkNode() {
		if (outNodes == NULL) {
			return true;
		}
		return false;
	}
	void addInNodes(vertex* toBeAdded) {
		if (inNodes == NULL) {
			inNodes = new listNode;
			inNodes->address = toBeAdded;
		}
		else {
			listNode* temp = new listNode;
			temp->address = toBeAdded;
			temp->next = inNodes;
			inNodes = temp;
		}
	}
	void addOutNodes(vertex* toBeAdded) {
		if (outNodes == NULL) {
			outNodes = new listNode;
			outNodes->address = toBeAdded;
		}
		else {
			listNode* temp = new listNode;
			temp->address = toBeAdded;
			temp->next = outNodes;
			outNodes = temp;
		}
	}
	vertex(int id):ID(id) {
		inNodes = 0;
		outNodes = 0;
	}
	int getID() {
		return ID;
	}
	void printIn() {
		int n = 0;
		listNode* itt = inNodes;
		cout << ID << "  In Nodes: ";
		while (itt != 0) {
			cout << itt->address->getID() << ", ";
			n++;
			itt = itt->next;
		}
		cout << endl << "In degree: " << n << endl;
	}
	void printOut() {
		int n = 0;
		listNode* itt = outNodes;
		cout << ID << "  Out Nodes: ";
		while (itt != 0) {
			cout << itt->address->getID() << "  ";
			n++;
			itt = itt->next;
		}
		cout << endl << "Out degree: " << n << endl;
	}
};

class graph {
	listNode* list;
	adjacencyListNode* adjacencyListHead; // undirected

	bool EdgeIsPresent(int fromId, int toId) {
		adjacencyListNode* itt = adjacencyListHead;
		while (itt != 0) {  // iterating through adjacency list and checking if edge exists(undirected).
			if (fromId == itt->from && toId == itt->to) {
				return true;
			}
			itt = itt->next;
		}
		while (itt != 0) {  // iterating through adjacency list and checking if edge exists.
			if (toId == itt->from && fromId == itt->to) {
				return true;
			}
			itt = itt->next;
		}
		return false;
	}
	void addUndirectedList(listNode* fromVertex, listNode* toVertex) {
		// this function would only run in constructor if undirected edge is not present.
		if (adjacencyListHead == 0) {  // creating first node.
			adjacencyListHead = new adjacencyListNode;
			adjacencyListHead->from = fromVertex->address->getID();  // assigning ID
			adjacencyListHead->to = toVertex->address->getID();   // assigning ID
		}
		else {
			adjacencyListNode* temp = new adjacencyListNode;
			temp->from = fromVertex->address->getID();  // assigning ID
			temp->to = toVertex->address->getID();   // assigning ID
			temp->next = adjacencyListHead; // setting temp as head node.
			adjacencyListHead = temp;
		}
	}
	void addEdge(listNode* fromVertex, listNode* toVertex) {
		toVertex->address->addInNodes(fromVertex->address);
		fromVertex->address->addOutNodes(toVertex->address);
	}
	listNode* IDIsPresent(int id) {
		listNode* itt = list;
		while (itt != 0) {
			if (itt->address->getID() == id) {
				return itt;
			}
			itt = itt->next;
		}
		return 0;
	}
	listNode* addNode(int id) {
		if (list == 0) {
			list = new listNode;
			list->address = new vertex(id);
			return list;
		}
		else if (IDIsPresent(id) != 0) {
			return IDIsPresent(id);
		}
		else {
			listNode* temp = new listNode;
			temp->address = new vertex(id);
			temp->next = list;
			list = temp;
			return temp;
		}
	}
	bool isolatedNodeCheck(listNode* check) {

	}
public:
	// prerequisites
	graph() {
		list = 0;
		adjacencyListHead = 0;
	}
	void createTree(string filePath) {
		listNode* fromNode, *toNode;
		string buffer, subBuffer;
		int fromID, toID;
		int counter = 0, i = 0;
		ifstream file;
		file.open(filePath, ios::in);
		if (!file.is_open()) {
			cout << "Failure in opening File." << endl;
			exit(0);
		}
		// discarding first four lines.
		getline(file, buffer);
		getline(file, buffer);
		getline(file, buffer);
		getline(file, buffer);
		while (counter < 100) {  // initially 10 to test on small dataset.
			getline(file, buffer);  // reading line.
			subBuffer = "";  // resetting everything.
			i = 0;
			while (buffer[i] != 9) {  // reading till tab(ascii = 9).
				subBuffer += buffer[i];
				i++;
			}
			fromID = stoi(subBuffer);  // storing fromId as int.
			fromNode = IDIsPresent(fromID);
			if (!fromNode) {  // if vertex not already present, create new and add in graph vertex list.
				fromNode = addNode(fromID);
				//cout << fromNode->address->getID() << "  ";
			}
			// resetting again.
			i++;
			subBuffer = "";
			subBuffer = buffer.substr(i);
			toID = stoi(subBuffer);
			toNode = IDIsPresent(toID);
			if (!toNode) {  // if not present, create vertex
				toNode = addNode(toID);
			}
			//cout << toNode->address->getID() << endl;
			if (!this->EdgeIsPresent(fromID, toID)) {
				addUndirectedList(fromNode, toNode);
			}
			addEdge(fromNode, toNode);
			counter++;
		}
		file.close();
	}
	
	void displayNodes() {
		listNode* itt = list;
		while (itt != 0) {
			cout << itt->address->getID() << endl;
			itt = itt->next;
		}
	}
	void sourceNodesDetails() {
		listNode* itt = list;
		while (itt != 0) {
			if (itt->address->isSourceNode()) {
				itt->address->printIn();
				itt->address->printOut();
			}
			itt = itt->next;
		}
	}

	// Part 1
	void numberOfNodes() {
		int no = 0;
		listNode* itt = list;
		while (itt != 0) {
			no++;
			itt = itt->next;
		}
		cout << no << endl;
	}
	void numberOfEdges() {
		adjacencyListNode* itt = adjacencyListHead;
		int no = 0;
		while (itt != 0) {
			no++;
			itt = itt->next;
		}
		cout << "Number of Edges(Undirected): " << no << endl;
	}
	void numberOfSourceNodes() {
		int n = 0;
		listNode* itt = list;
		while (itt != 0) {
			if (itt->address->isSourceNode()) {
				n++;
			}
			itt = itt->next;
		}
		cout << "Number of Source Nodes: " << n << endl;
	}
	void numberOfSinkNodes() {
		int n = 0;
		listNode* itt = list;
		while (itt != 0) {
			if (itt->address->isSinkNode()) {
				n++;
			}
			itt = itt->next;
		}
		cout << "Number of Sink Nodes: " << n << endl;
	}
	void numberOfIsolatedNodes() {
		int n = 0;
		listNode* itt = list;
		while (itt != 0) {
			if (itt->address->isSinkNode() && itt->address->isSourceNode()) {
				n++;
			}
			itt = itt->next;
		}
		cout << "Number of Isolated Nodes: " << n << endl;
	}
	bool isIsolatedVertex() {
		listNode* itt = list;
		while (itt != 0) {

			itt = itt->next;
		}
	}

	// Part 2
	void displayInDegree(int n = -1) {
		if (n == -1) {
			listNode* itt = list;
			while (itt != 0) {
				itt->address->printIn();
				itt = itt->next;
			}
		}
		else {
			listNode* itt = list;
			while (itt != 0) {
				if (itt->address->getID() == n) {
					itt->address->printIn();
					return;
				}
				itt = itt->next;
			}
		}
	}
	void displayOutDegree(int n = -1) {
		if (n == -1) {
			listNode* itt = list;
			while (itt != 0) {
				itt->address->printOut();
				itt = itt->next;
			}
		}
		else {
			listNode* itt = list;
			while (itt != 0) {
				if (itt->address->getID() == n) {
					itt->address->printOut();
					return;
				}
				itt = itt->next;
			}
		}
		
	}

	// Part 3

};

