/**
 * Graph Implementation
 * 
 * there is no sql library available readily which implements a graph for us.
 * We need to implement it on our own.
 * 
 * We can implement graph using 2 ways:
 * 1. Using Adjacency Matrix
 * 2. Using Adjacency List
 * 
 * We will use undirected and unweighted graph for now.
 * We actually only want information about connections.
 * 
 * Using Adjacency matrix, 
 * we will have a NxN matrix (N is the number of nodes in our graph.)
 * When a node 1 is connected to node 2,
 * we set 2 values inside matrix to 1.
 * Basically (1, 2) = 1 and (2, 1) = 1.
 * This goes true for any value (x,y) which are connected together with an edge.
 * 
 * For directed graph, we will only have one way connection.
 * There are limitations with Adjacency matrix implementation.
 * Currently, the nodes values were pretty straight forward.
 * If our Node name is string/character, we might not be able to 
 * use adjacency matrix to implement Graph.
 * 
 * Using adjacency list, we can have anything.
 * To implement adjacency, we can use unordered map.
 * And here, key can be anything.
 */
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print2DVector(vector< vector<int>> arr) {
    for(int i=0; i<arr.size(); i++) {
        printVector(arr[i]);
    }
    cout << endl;
}

// this node value can be a int, string, anything that we want.
class Node {
    public:
        int value;
        Node(int val) {
            this->value = val;
        }
};

void printVector(vector<Node> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i].value << " ";
    }
    cout << endl;
}

class UndirectedUnweightedGraph {
    public:
        unordered_map<int, vector<Node>> adjacencyList;
        UndirectedUnweightedGraph() {

        }

        void addEdge(Node from, Node to) {
            if(this->adjacencyList.find(from.value) == this->adjacencyList.end()) {
                vector<Node> fromNeighbours = vector<Node>();
                fromNeighbours.push_back(to);
                this->adjacencyList[from.value] = fromNeighbours;

                vector<Node> toNeighbours = vector<Node>();
                toNeighbours.push_back(from);
                this->adjacencyList[to.value] = toNeighbours;
            } else {
                this->adjacencyList[from.value].push_back(to);
                this->adjacencyList[to.value].push_back(from);
            }
        }

        void printAdjacencyList() {
            for(auto item: this->adjacencyList) {
                cout << "Node: " << item.first << " : ";
                printVector(item.second);
            }
        }
};

class GraphWithMatrix {
    public:
        int numberOfNodes;
        vector<vector<int>> adjacencyMatrix;
        GraphWithMatrix(int maxNodes) {
            this->numberOfNodes = maxNodes;
            adjacencyMatrix = vector< vector<int>>(this->numberOfNodes, 
                vector<int>(this->numberOfNodes, 0));
        }

        // for undirected graph.
        void addEdge(int from, int to) {
            // Assuming from and to are < number of Nodes
            adjacencyMatrix[from][to] = 1;
            adjacencyMatrix[to][from] = 1;
        }

        void printAdjacencyMatrix() {
            print2DVector(this->adjacencyMatrix);
        }
};

int main() {
    cout << "Graph with Adjacency Matrix" << endl;
    GraphWithMatrix matrixGraph = GraphWithMatrix(4);
    matrixGraph.addEdge(0, 1);
    matrixGraph.addEdge(1, 2);
    matrixGraph.addEdge(2, 3);
    matrixGraph.addEdge(3, 0);
    cout << "Printing Adjacency Matrix: " << endl;
    matrixGraph.printAdjacencyMatrix();


    cout << endl << "Graph with Adjacency list: " << endl;
    UndirectedUnweightedGraph graph = UndirectedUnweightedGraph();
    graph.addEdge(Node(0), Node(1));
    graph.addEdge(Node(1), Node(2));
    graph.addEdge(Node(2), Node(3));
    graph.addEdge(Node(3), Node(0));

    cout << "Printing Adjacency List: " << endl;
    graph.printAdjacencyList();

    return 0;
}