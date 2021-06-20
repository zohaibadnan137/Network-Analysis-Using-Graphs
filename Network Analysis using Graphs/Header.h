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
		bool visited;

		visitedListNode(vertex* A = 0) {
			address = A;
			visited = false;
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
	/*void loadDFSList(listNode* list) {
		listNode* itt = list;
		visitedListNode* visitedItt;
		while (itt) {
			if (!head) {
				head = new visitedListNode;
				visitedItt = head;
			}
			else {
				visitedItt->next = new visitedListNode;
				visitedItt = visitedItt->next;
			}
			visitedItt->address = itt->address;
			itt = itt->next;
		}

	}*/
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
	vertex* fromN;
	int to;
	vertex* toN;

	adjacencyListNode* next;

	adjacencyListNode() {
		from = 0;
		fromN = 0;
		to = 0;
		toN = 0;
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
	listNode* comp; 
	int size; 

	componentListNode* next;

	componentListNode()
	{
		ver = 0;
		comp = 0;
		size = 1;
		next = 0;
	}

	void add(vertex* add)
	{
		listNode* temp = new listNode;
		temp->address = add;
		if (comp == 0)
			comp = temp;
		else
		{
			temp->next = comp;
			comp = temp;
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
	int noOfOutNodes() {
		listNode* itt = inNodes;
		int n = 0;
		while (itt) {
			n++;
			itt = itt->next;
		}
		return n;
	}
};

// Helper functions
int findIndex(vertex* find, vertex** Arr, int size) {
	for (int i = 0; i < size; i++) {
		if (Arr[i] == find) {
			return i;
		}
	}
	return -1;
}
int findI(int f, int* arr, int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == f) {
			return i;
		}
	}
	return -1;
}
int min(int n1, int n2) {
	if (n1 < n2) {
		return n1;
	}
	else {
		return n2;
	}
}

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
			adjacencyListHead->fromN = fromVertex->address;
			adjacencyListHead->to = toVertex->address->getID();   // assigning ID
			adjacencyListHead->toN = toVertex->address;

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
	int ArticulationPrerequisites(bool forVertices) {
		const int noOfVertices = countNodes();
		int* allVertices = new int[noOfVertices];
		listNode* itt = list;
		int i = 0;
		while (itt) {
			allVertices[i] = itt->address->getID();
			i++;
			itt = itt->next;
		}
		bool* visited = new bool[noOfVertices] {false};
		int* discoveryTime = new int[noOfVertices] {-1};
		int* lowestTime = new int[noOfVertices] {-1};
		int* parent = new int[noOfVertices] {-1};
		bool* ArticulationPoints = new bool[noOfVertices]{ false };
		int* time = new int{ 0 };


		if (forVertices == false) {
			int* result = new int{ 0 };
			for (i = 0; i < noOfVertices; i++) {
				if (!visited[i]) {
					findBridge(i, noOfVertices, visited, discoveryTime, lowestTime, allVertices, parent, time, result);
				}
			}
			return *result;
		}


		else {
			for (int i = 0; i < noOfVertices; i++) {
				if (!visited[i]) {
					findAP(i, noOfVertices, visited, discoveryTime, lowestTime, allVertices, parent, ArticulationPoints, time);
				}
			}
			int n = 0;
			for (int i = 0; i < noOfVertices; i++) {
				if (ArticulationPoints[i] == true) {
					n++;
				}
			}
			return n;
		}
	}
	void findAP(int init, int noOfVertices, bool* visited, int* discoveryTime, int* lowestTime, int* allVertices, int* parent, bool* ArticulationPoints, int*& time) {
		// doing DFS
		int childeren = 0;
		int u = init, v;
		visited[u] = true;  // mark as true so that not visited again.
		discoveryTime[u] = lowestTime[u] = ++*time;  // initially both times are same.
		adjacencyListNode* itt = adjacencyListHead, *temp;
		while (itt) {  // iterating through adjacency list
			temp = itt;
			itt = itt->next;
			if (allVertices[u] == temp->from) {  // selecting only ones with particular vertex present.
				v = findI(temp->to, allVertices, noOfVertices);
				if (!visited[v]) {
					childeren++;
					parent[v] = u;
					findAP(v, noOfVertices, visited, discoveryTime, lowestTime, allVertices, parent, ArticulationPoints, time);
					lowestTime[u] = min(lowestTime[u], lowestTime[v]);
					if (parent[u] == -1 && childeren > 1) {  // if it is starting point and connects 2 or more parts of graph.
						ArticulationPoints[u] = true;
					}
					if (parent[u] != -1 && lowestTime[v] > discoveryTime[u]) {  // vertex is not starting point and there is another way to connect graph as well.
						ArticulationPoints[u] = true;
					}
				}
				else if (v != parent[u]) {
					lowestTime[u] = min(lowestTime[u], discoveryTime[v]);  
				}
			}
			if (allVertices[u] == temp->to) {  // for to value as we are assuming graph as undirected.
				v = findI(temp->from, allVertices, noOfVertices);
				if (!visited[v]) {
					childeren++;
					parent[v] = u;
					findAP(v, noOfVertices, visited, discoveryTime, lowestTime, allVertices, parent, ArticulationPoints, time);
					lowestTime[u] = min(lowestTime[u], lowestTime[v]);
					if (parent[u] == -1 && childeren > 1) {  // if it is starting point and connects 2 or more parts of graph.
						ArticulationPoints[u] = true;
					}
					if (parent[u] != -1 && lowestTime[v] > discoveryTime[u]) {  // vertex is not starting point and there is another way to connect graph as well.
						ArticulationPoints[u] = true;
					}
				}
				else if (v != parent[u]) {
					lowestTime[u] = min(lowestTime[u], discoveryTime[v]);
				}
			}
		}
	}
	void findBridge(int init, int noOfVertices, bool* visited, int* discoveryTime, int* lowestTime, int* allVertices, int* parent, int*& time, int*& result) {
		int u = init, v;
		visited[u] = true;
		discoveryTime[u] = lowestTime[u] = ++*time;
		adjacencyListNode* itt = adjacencyListHead, *temp;
		while (itt) {
			temp = itt;
			itt = itt->next;
			if (allVertices[u] == temp->from) {  // selecting only ones with particular vertex present.
				v = findI(temp->to, allVertices, noOfVertices);
				if (!visited[v]) {
					parent[v] = u;
					findBridge(v, noOfVertices, visited, discoveryTime, lowestTime, allVertices, parent, time, result);

					lowestTime[v] = min(lowestTime[v], lowestTime[u]);

					if (lowestTime[v] > discoveryTime[u]) {
						result++;
					}
				}
				else if (v != parent[u]) {
					lowestTime[u] = min(lowestTime[u], discoveryTime[v]);
				}
			}
		}

	}
	int BridgeDFS(int vertNo, vertex** vertices, int noOfVertices, bool* visited, int* lowestTime, int* discoveryTime, int parentVertex = -1) {
		int noOfBridges = 0;  
		vertex* vert = vertices[vertNo];
		vertex* vertexOutNodes;
		int n = vert->noOfOutNodes();
		int to = 0;
		listNode* itt = 0;
		itt = vert->getInNode();
		int i = 0;
		while(itt){
			vertexOutNodes = itt->address;
			to = findIndex(itt->address, vertices, noOfVertices);  // finding index corresponding to the to node of outNode.
			
		if (to != parentVertex) {
				if (visited[to]) {
					lowestTime[to] = min(lowestTime[vertNo], discoveryTime[to]);
				}
				else {
					noOfBridges += BridgeDFS(to, vertices, noOfVertices, visited, lowestTime, discoveryTime, vertNo);
					lowestTime[vertNo] = min(lowestTime[vertNo], lowestTime[to]);
					if (lowestTime[to] > discoveryTime[vertNo]) {
						noOfBridges++;
					}
				}
			}
			itt = itt->next;
			i++;
		}
		return noOfBridges;
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
					currVer->add(out->address); // Add the current out vertex because it has a bidirectional relationship with the current vertex
				in = in->next;
			}
			out = out->next;
		}
		return currVer;
	}
	componentListNode* findUnion(vertex* v)
	{
		componentListNode* curr = new componentListNode;
		curr->ver = v;

		listNode* out = v->getOutNode();

		while (out != 0)
		{
			curr->add(out->address);
			out = out->next;
		}

		listNode* in = v->getInNode();
		while (in != 0)
		{
			listNode* temp = curr->comp;
			bool flag = false;
			while (temp != 0)
			{
				if (temp->address->getID() == in->address->getID())
				{
					flag = true;
					break;
				}
				temp = temp->next;
			}
			if (!flag)
				curr->add(in->address);
			in = in->next;
		}
		return curr;
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
	int countNodes() {
		int no = 0;
		listNode* itt = list;
		while (itt != 0) {
			no++;
			itt = itt->next;
		}
		return no;
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
		cout << "Number of Articulation Nodes: " << ArticulationPrerequisites(true) << endl;
	}
	void noOfBridgeEdges() {
		cout << "Number of Bridge Edges: " << ArticulationPrerequisites(false) << endl;
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
		componentListNode* maxComponent = NULL;

		componentListNode* currComp = compHead;
		while (currComp != 0)
		{
			if (currComp->size > max)
			{
				max = currComp->size;
				maxComponent = currComp;
			}
			currComp = currComp->next;
		}

		cout << "The size of the largest strongly connected component is " << max << "." << endl;
		cout << maxComponent->ver->getID();

		listNode* temp = maxComponent->comp;
		while (temp != 0)
		{
			cout << " - " << temp->address->getID();
			temp = temp->next;
		}
		cout << endl;
		return;
	}
	void displaySCC()
	{
		// Populate component list
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

		componentListNode* currComp = compHead;

		while (currComp != 0)
		{
			cout << "Size: " << currComp->size << endl;
			cout << currComp->ver->getID();
			listNode * temp = currComp->comp;
			while (temp != 0)
			{
				cout << " - " << temp->address->getID();
				temp = temp->next;
			}
			cout << endl;
			currComp = currComp->next;
		}
		return;
	}

	// Parts 13 and 14
	void findLargestWCC()
	{
		listNode* curr = list;
		componentListNode* componentListHead = 0;
		while (curr != 0)
		{
			componentListNode* temp = findUnion(curr->address);
			if (componentListHead == 0)
				componentListHead = temp;
			else
			{
				temp->next = componentListHead;
				componentListHead = temp;
			}
			curr = curr->next;
		}

		int max = 0;
		componentListNode* maxComponent = 0;

		componentListNode* currComponent = componentListHead;
		while (currComponent != 0)
		{
			if (currComponent->size > max)
			{
				max = currComponent->size;
				maxComponent = currComponent;
			}
			currComponent = currComponent->next;
		}

		cout << "The size of the largest weakly connected component is " << max << "." << endl;
		cout << maxComponent->ver->getID();

		listNode* temp = maxComponent->comp;
		while (temp != 0)
		{
			cout << " - " << temp->address->getID();
			temp = temp->next;
		}
		cout << endl;
		return;
	}
	void displayWCC()
	{
		listNode* curr = list;
		componentListNode* componentListHead = 0;
		while (curr != 0)
		{
			componentListNode* temp = findUnion(curr->address);
			if (componentListHead == 0)
				componentListHead = temp;
			else
			{
				temp->next = componentListHead;
				componentListHead = temp;
			}
			curr = curr->next;
		}

		componentListNode* currComponent = componentListHead;
		while (currComponent != 0)
		{
			cout << "Size: " << currComponent->size << endl;
			cout << currComponent->ver->getID();
			listNode* temp = currComponent->comp;
			while (temp != 0)
			{
				cout << " - " << temp->address->getID();
				temp = temp->next;
			}
			cout << endl;
			currComponent = currComponent->next;
		}
		return;
	}
};
