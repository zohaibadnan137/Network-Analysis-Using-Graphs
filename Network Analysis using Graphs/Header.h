// Abdullah Bilal 19i-0616
// Zohaib Adnan 19i-0741
// Data Structures 
// Project 

#pragma once

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//**************** Structure and Class Prototypes ****************//

struct QNode;
struct Queue;
struct visitedListNode;
class visitedList;
struct adjacencyListNode;
struct listNode;
class vertex;
class graph;

//**************** Structure and Class Definitions ****************//

struct Queue {
	struct QNode {
		bool visited;
		vertex* address;
		QNode* next;

		QNode(vertex* A = 0) {
			visited = false;
			address = A;
			next = 0;
		}
		void markVisited() {
			visited = true;
		}
	};

	QNode* front;
	QNode* rear;
	int size;

	Queue() { 
		front = 0;
		rear = 0;
		size = 0;
	}
	void enqueue(vertex* A) {
		if (front == 0) {  // if empty
			front = rear = new QNode; // create new
			front->address = A;  // front->address is vertex's address.
		}
		else {
			QNode* temp = new QNode;
			temp->address = A;
			rear->next = temp;
			rear = rear->next; 
		}
		size++;
		return;
	}
	vertex* dequeue() {
		vertex* ret = 0;
		if (front == 0)
			return 0;
		if (front->next == 0) {
			ret = front->address;
			delete front;
			front = rear = 0;
		}
		else {
			QNode* temp = front;
			ret = temp->address;
			front = front->next;
			delete temp;
		}
			size--;
		return ret;
	}
	bool isEmpty() {
		if (!size) {
			return true;
		}
		return false;
	}
	int getSize()
	{
		return size;
	}
};

class visitedList {
	struct visitedListNode {
		vertex* address;
		visitedListNode* next;

		visitedListNode(vertex* A = 0) {
			address = A;
			next = 0;
		}
	};

	visitedListNode* head;
	int size;

public:
	visitedList() {
		head = 0;
		size = 0;
	}
	void add(vertex* A) {
		if (head == 0) {
			head = new visitedListNode;
			head->address = A;
			size++;
		}
		else {
			visitedListNode* temp = new visitedListNode;
			temp->address = A;
			size++;
			temp->next = head;
			head = temp;
		}
	}
	int getSize() {
		return size;
	}
	bool checkIfVisited(vertex* v) {
		visitedListNode* itt = head;
		while (itt != 0) {
			if (itt->address == v) {
				return true;
			}
			itt = itt->next;
		}
		return false;
	}
	~visitedList() // Destructor
	{
		if (head != 0) // Do nothing if the list is already empty
		{
			visitedListNode* itt; // Delete the list starting from the head 
			while (head != 0)
			{
				itt = head; // Store the current node
				head = head->next; // Move the head to next node
				delete itt; // Delete the current node
			}
			return;
		}
	}
};

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

struct componentListNode
{
	// Data members 
	vertex* ver; // Points to the current vertex
	listNode* bi; // Stores nodes that have a bidirectional edge with the current node
	int size; // Stores number of bidirectional edges that the current node has

	componentListNode* next;

	componentListNode()
	{
		ver = 0;
		bi = 0;
		size = 0;
		next = 0;
	}

	void addBi(vertex* add)
	{
		listNode* temp = new listNode;
		temp->address = add;
		if (bi == 0)
			bi = temp;
		else
		{
			temp->next = bi;
			bi = temp;
		}
		size++;
	}
};

class vertex {

	int ID;
	// Singly linked lists for directionality
	listNode* inNodes; // These nodes point towards the current node
	listNode* outNodes; // The current node points towards these nodes

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
	vertex(int id):ID(id) { // Constructor 
		inNodes = 0;
		outNodes = 0;
	}
	int getID() {
		return ID;
	}
	void printIn() { // Prints all nodes pointing towards the current node
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
	void printOut() { // Prints all nodes the current node is pointing towards
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
	listNode* getInNode() {
		return inNodes;
	}
	listNode* getOutNode() {
		return outNodes;
	}
};

class graph {
	listNode* list; // Main linked list which keeps track of all exisiting vertices 
	adjacencyListNode* adjacencyListHead; // undirected

	bool EdgeIsPresent(int fromId, int toId) { 
		adjacencyListNode* itt = adjacencyListHead;
		while (itt != 0) {  // iterating through adjacency list and checking if an undirected edge exists
			if (fromId == itt->from && toId == itt->to) {
				return true;
			}
			itt = itt->next;
		}
		itt = adjacencyListHead;
		while (itt != 0) {  // iterating through adjacency list and checking if edge exists (reversing from and to)
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
	int countArticulation() {
		listNode* itt = list;
		int n = 0;
		while (itt->next != 0) {
			if (articulationNodeCheck(itt, itt)) {
				n++;
			}
			itt = itt->next;
		}
		itt = itt->next;
		if (articulationNodeCheck(itt, list)) {
			n++;
		}
		return n;
	}
	int countNodes() {
		int no = 0;
		listNode* itt = list;
		while (itt != 0) {
			no++;
			itt = itt->next;
		}
		return no;
	}
 	bool articulationNodeCheck(listNode* starting, listNode* check) {
		if (check == 0 || starting == 0) {
			return false;
		}
		Queue q;
		int n = 0;
		visitedList v;
		vertex* vtx;
		v.add(check->address);
		if (check == starting) {
			vtx = starting->next->address;
			q.enqueue(vtx);
			v.add(vtx);
		}
		else {
			vtx = starting->address;
			q.enqueue(vtx);
			v.add(vtx);
		}
		listNode* itt = vtx->getOutNode();  // initialising iterator to iterate all.
		if (itt == 0) {
			return false;
		}
		while (!q.isEmpty()) {
			vtx = q.dequeue();
			itt = vtx->getOutNode();
			while (itt != 0) {
				if (itt == check) {
					continue;
				}
				else if (!v.checkIfVisited(itt->address)){
					v.add(itt->address);
				}
				itt = itt->next;
			}
		}
		if (n != (countNodes() - 1)) {
			return true;
		}
		return false;
	}
	componentListNode* findBi(vertex* v)
	{
		componentListNode* currVer = new componentListNode;
		currVer->ver = v;

		// Open the out and in linked lists for the current vertex
		listNode* out = v->getOutNode();
		listNode* in;

		while (out != 0)
		{
			// For each vertex in the out list, check whether it exists in the in list
			in = v->getInNode();
			while (in != 0)
			{
				if (out->address->getID() == in->address->getID())
					currVer->addBi(out->address); // Add the current out vertex because it has a bidirectional relationship with the current vertex
				in = in->next;
			}
			out = out->next;
		}
		return currVer;
	}

public:
	// prerequisites
	graph() {
		list = 0;
		adjacencyListHead = 0;
	}
	void createGraph(string filePath) {
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
		while (true) {  // initially 10 to test on small dataset.
			getline(file, buffer);  // reading line.
			if (buffer == "") {
				break;
			}
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

	// Parts 1, 2, 3, 4, 5, 6
	void numberOfNodes() {
		int no = 0;
		listNode* itt = list;
		while (itt != 0) {
			no++;
			itt = itt->next;
		}
		cout << "Number of nodes: " << no << endl;
	}
	void numberOfEdges() {
		adjacencyListNode* itt = adjacencyListHead;
		int no = 0;
		while (itt != 0) {
			no++;
			itt = itt->next;
		}
		cout << "Number of undirected edges: " << no << endl;
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
		cout << "Number of source nodes: " << n << endl;
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
		cout << "Number of sink nodes: " << n << endl;
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
		cout << "Number of isolated nodes: " << n << endl;
	}
	void noOfArticulationNodes() {
		cout << "Number of articulation nodes: " << countArticulation() << endl;
	}

	// Parts 8 and 9
	void findShortestPath(int srcID, int destID)
	{
		listNode* src = IDIsPresent(srcID);
		listNode* dest = IDIsPresent(destID);
		if (src == 0)
		{
			cout << "Error! The source vertex does not exist." << endl;
			return;
		}
		else if (dest == 0)
		{
			cout << "Error! The destination vertex does not exist." << endl;
			return;
		}
		Queue q;
		visitedList visited;
		int length = 1;
		q.enqueue(src->address);
		visited.add(src->address);
		while (!q.isEmpty())
		{
			int inQueue = q.getSize();
			while (inQueue > 0)
			{
				vertex* temp1 = q.dequeue();
				listNode* temp2 = temp1->getOutNode();
				while (temp2 != 0)
				{
					if (temp2->address->getID() == destID)
						goto next;
					if (!visited.checkIfVisited(temp2->address))
					{
						visited.add(temp2->address);
						q.enqueue(temp2->address);
					}
					temp2 = temp2->next;
				}
				inQueue--;
			}
			length++;
		}
		cout << "No path exists between " << srcID << " and " << destID << "." << endl;
		return;
	next:
		cout << "The shortest path between " << srcID << " and " << destID << " is " << length << "." << endl;
		return;
	}
	void findAllShortestPaths()
	{
		listNode* itt1 = list;
		while (itt1 != 0)
		{
			listNode* itt2 = list;
			while (itt2 != 0)
			{
				if (itt1 != itt2)
					findShortestPath(itt1->address->getID(), itt2->address->getID());
				itt2 = itt2->next;
			}
			itt1 = itt1->next;
		}
		return;
	}

	// Parts 10 and 11
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

	// Parts 12 and 13
	void findLargestSCC()
	{
		listNode* curr = list;
		componentListNode* compHead = 0;
		while (curr != 0)
		{
			componentListNode* temp = findBi(curr->address);
			if (compHead == 0)
				compHead = temp;
			else
			{
				temp->next = compHead;
				compHead = temp;
			}
			curr = curr->next;
		}

		int max = 0;
		componentListNode* maxComp = 0;

		componentListNode* currComp = compHead;
		while (currComp != 0)
		{
			if (currComp->size >= max)
			{
				max = currComp->size;
				maxComp = currComp;
			}
			currComp = currComp->next;
		}

		cout << "The size of the largest strongly connected component is " << max << "." << endl;
		cout << maxComp->ver->getID();

		listNode* temp = maxComp->bi;
		while (temp != 0)
		{
			cout << " - " << temp->address->getID();
			temp = temp->next;
		}

		return;
	}
	void displaySCC()
	{
		listNode* curr = list;
		componentListNode* compHead = 0;
		while (curr != 0)
		{
			componentListNode* temp = findBi(curr->address);
			if (compHead == 0)
				compHead = temp;
			else
			{
				temp->next = compHead;
				compHead = temp;
			}
			curr = curr->next;
		}

		visitedList v1;

		componentListNode* itt = compHead;

		int s = 0;
		while (itt != 0)
		{
			if (!v1.checkIfVisited(itt->ver))
			{
				v1.add(itt->ver);
				s += itt->size;
				cout << itt->ver->getID();
				listNode* itt2 = itt->bi;
				while (itt2 != 0)
				{
					v1.add(itt2->address);
					cout << " - " << itt2->address->getID();
					itt2 = itt2->next;
				}
				cout << endl;
				cout << endl;
			}
			itt = itt->next;
		}

		cout << "size: " << s << endl;
	}
	// Parts 13 and 14
};

