/**
 * Breadth First Search
 * 
 */
#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<queue>
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

class ListGraph {
    public:
        unordered_map<int, vector<int>> adjacencencyList;
        // stores all nodes
        set<int> allNodes;
        ListGraph() {
            allNodes = set<int>();
            adjacencencyList = unordered_map<int, vector<int>>();
        }

        void addEdge(int from, int to) {
            // add both nodes to our set
            this->allNodes.insert(to);
            this->allNodes.insert(from);

            if(this->adjacencencyList.find(from) == this->adjacencencyList.end()) {
                vector<int> newList = vector<int>();
                newList.push_back(to);
                this->adjacencencyList[from] = newList;
            } else {
                this->adjacencencyList[from].push_back(to);
            }

            if(this->adjacencencyList.find(to) == this->adjacencencyList.end()) {
                vector<int> newList = vector<int>();
                newList.push_back(from);
                this->adjacencencyList[to] = newList;
            } else {
                this->adjacencencyList[to].push_back(from);
            }
        }

        void printGraph() {
            for(auto item: this->adjacencencyList) {
                cout << "Node " << item.first << " : ";
                printVector(this->adjacencencyList[item.first]);
            }
        }

        void bfs(int node) {
            queue<int> bfsQueue = queue<int>();
            bfsQueue.push(node);
            unordered_map<int, int> visited = unordered_map<int, int>();
            visited[node] = 1;
            cout << "Root Node: " << node << endl;

            while(!bfsQueue.empty()) {
                int currentNode = bfsQueue.front();
                bfsQueue.pop();
                cout << "Node -> " << currentNode << endl;
                
                vector<int> adjacentNodes = this->adjacencencyList[currentNode];

                for(int i=0; i<adjacentNodes.size(); i++) {
                    int neighbour = adjacentNodes[i];
                    if(visited.find(neighbour) == visited.end()) {
                        // not visited
                        bfsQueue.push(neighbour);
                        // mark visited
                        visited[neighbour] = 1;
                    }
                }
            }

            cout << "End" << endl;
        }
};

int main() {
    cout << endl << "Graph with Adjacency list: " << endl;
    ListGraph listGraph = ListGraph();

    listGraph.addEdge(0, 1);
    listGraph.addEdge(1, 2);
    listGraph.addEdge(0,2);
    listGraph.addEdge(2, 3);
    listGraph.addEdge(3, 4);
    listGraph.addEdge(0,4);
    listGraph.addEdge(1,4);
    listGraph.addEdge(0,5);
    listGraph.addEdge(4,5);

    listGraph.printGraph();

    listGraph.bfs(0);
    return 0;
}