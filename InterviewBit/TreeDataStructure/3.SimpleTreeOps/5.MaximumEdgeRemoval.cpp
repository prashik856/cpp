/*
Problem Description

Given an undirected tree with an even number of nodes. Consider each connection between a parent and child node to be an edge.

You need to remove maximum number of these edges, such that the disconnected subtrees that remain each have an even number of nodes.

Return the maximum number of edges you can remove.



Problem Constraints
2 <= A <= 105

1 <= B[i][0], B[i][1] <= A

Integer A will be even.



Input Format
First argument is an integer A denoting the number of nodes in the tree.

Second argument is a 2D array B of size (A-1) * 2, denoting the edge between nodes B[i][0] and B[i][1].



Output Format
Return an integer, denoting the maximum number of edges you can remove.



Example Input
Input 1:

 A = 6
 B = [
       [1, 2]
       [1, 3]
       [1, 4]
       [3, 5]
       [4, 6]
     ]
Input 2:

 A = 2
 B = [
       [1, 2]
     ]


Example Output
Output 1:

 2
Output 2:

 0


Example Explanation
Explanation 1:

      1
    / | \
   2  3  4
      |   \
      5    6
 Maximum number of edges we can remove is 2, i.e (1, 3) and (1, 4)
Explanation 2:

 We can't remove any edges.
*/
/*
Solution Approach:
After reading the method:
1. We use dfs to find the number of nodes in the subtree.
2. If the number of nodes are even, we delete that edge.
    > Else, we include that edge.
3. Now, we run dfs recursively. 
    i.e. For every node visited, we visited it's child itself, and return the number of nodes it has.

int Solution::solve(int V, vector<vector<int> > &edges) {
	// create an adjacency list and insert all the edges
	vector<int> *adjList = new vector<int>[V+1];
	for(vector<int> edge: edges) {
		int u = edge[0], v = edge[1];
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	
	// Algorithm: 
	// do dfs and keep track of nodes in subtree (countSubtreeNodes)
	// if countSubtreeNodes is even then we can detach that subtree
	// else we keep that in tree and add the value nodes in subtree to the total nodes
	vector<bool> ok(V+1, false);
	int total = 0; // keep track of total edges removed, passed as a reference
	
	// function declaration 
	void dfs(vector<int>*&, vector<bool>&, int, int&);
	// function call
	dfs(adjList, ok, 1, total);
	
	// return max total edges removed
	return total;
}

int dfs(vector<int> *&adjList, vector<bool> &ok, int u, int &total) {
	// mark the node as visited
	ok[u] = true;
	
	// total nodes in current tree considering u as a root
	int nodesInTree = 1; // 1, considering the node itself
	
	// iterate over all the neighbors of (u)
	for(int v: adjList[u]) {
		// if neighbour(v) is not visited
		if(!ok[v]) {
			// find nodes in that subtree (tree starting from v)
			int nodesInSubtree = dfs(adjList, ok, v, total);
			
			// if even then we can detach that subtree, means we can remove the edge
			if(nodesInSubtree%2 == 0) ++total;
			// else that nodes of subtree should remain in current tree where root is u
			else nodesInTree += nodesInSubtree;
		}	
	}
	return nodesInTree;
}

// This is a good solution, but don't know why this is timing out.
// this is good O(n) solution man!
*/
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print2DVector(vector< vector<int> > arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printStrings(vector<string> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << endl;
    }
    cout << endl;
}

class ListNode{
    public: 
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createLinkedList(vector<int> arr){
    ListNode *head = 0;
    int n = arr.size();
    for(int i=0; i<n; i++){
        int value = arr[i];
        ListNode *newNode = new ListNode(value);

        if(head == 0){
            head = newNode;
        } else {
            ListNode *temp = head;
            while(temp->next != 0){
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
    }
    return head;
}

void printLinkedList(ListNode *head){
    ListNode *temp = head;
    while(temp != 0){
        cout << temp->val << " ";
        temp = temp -> next;
    }
    cout << endl;
}


int getLinkedListLength(ListNode *head){
    ListNode *temp = head;
    int count = 0;
    while(temp !=0){
        temp = temp -> next;
        count++;
    }
    return count;
}

class TreeNode{
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x): val(x), left(0), right(0){}
};

TreeNode *createTree(int rootValue, vector<int> a){
    TreeNode *root = new TreeNode(rootValue);

    // Create Tree
    for(int i=0; i<a.size(); i++){
        int val = a[i];
        TreeNode *node = new TreeNode(val);
        // We need to find the location for this val
        TreeNode *temp = root;
        while(true){
            // if value is less than current root
            if(val <= temp -> val){
                if(temp -> left == 0){
                    // found it
                    temp -> left = node;
                    break;
                } else {
                    temp = temp -> left;
                    continue;
                }
            } 
            // if value is greater than current root
            else {
                if(temp -> right == 0){
                    // found it
                    temp -> right = node;
                    break;
                } else {
                    temp = temp -> right;
                    continue;
                }
            }
        }
    }
    return root;
}

// Depth first search
void preOrder(TreeNode *root){
    if(root == 0){
        return;
    }
    cout << root -> val << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

// Sorted order
void inOrder(TreeNode *root){
    if(root == 0){
        return;
    }
    inOrder(root -> left);
    cout << root -> val << " ";
    inOrder(root -> right);
}

// Visited all children first
void postOrder(TreeNode *root){
    if(root == 0){
        return;
    }
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> val << " ";
}

// Breadth first search
void bfs(TreeNode *root){
    queue<TreeNode *> q;
    q.push(root);

    while(!q.empty()){
        TreeNode *node = q.front();
        q.pop();
        cout << node->val << " ";
        if(node -> left != 0){
            q.push(node -> left);
        }
        if(node -> right != 0){
            q.push(node -> right);
        }
    }
}

// Depth first search using Stack
void dfs(TreeNode *root){
    stack<TreeNode *> s;
    s.push(root);
    while(!s.empty()){
        TreeNode *node = s.top();
        s.pop();
        cout << node -> val << " ";
        if(node -> left != 0){
            s.push(node -> left);
        }
        if(node -> right != 0){
            s.push(node -> right);
        }
    }
}

int customDfs(int currentNode, vector< vector<int> > adjacencyList, int *result, vector<bool> &visited){
    // visited the current Node
    cout << "Visiting node: " << currentNode << endl;
    visited[currentNode] = true;
    // keep count of current tree, starting with 1
    int nodesInTree = 1;
    for(int i=0; i<adjacencyList[currentNode].size(); i++){
        int neighbour = adjacencyList[currentNode][i];
        // if neighbour not visited
        if(!visited[neighbour]){
            // get count of current neighbour subtree
            int nodesInSubTree = customDfs(neighbour, adjacencyList, result, visited);
            // cout << "Neighbour: " << neighbour << endl;
            // cout << "Number of nodes in this neighbour: " << nodesInSubTree << endl;

            // if current neighbour subtree count is even, we remove edge
            if(nodesInSubTree % 2 == 0) {
                *result = *result + 1;
            } else {
                // Else we add these number of subtrees in our current nodes in tree count
                nodesInTree += nodesInSubTree;
            }
        }
    }
    // return nodes in current tree
    return nodesInTree;
}

int solve(int a, vector< vector<int> > b){
    int result = 0;

    vector<bool> visited(a+1, false);
    vector< vector<int> > adjacencyList(a+1, vector<int>());
    int root = -1;
    for(int i=0; i<b.size(); i++){
        int to = b[i][0];
        root = to;
        int from = b[i][1];
        adjacencyList[to].push_back(from);
        adjacencyList[from].push_back(to);
    }
    customDfs(1, adjacencyList, &result, visited);
    return result;
}

int main(){
    int a = 2;
    vector< vector<int> > b = {{1, 2}};
    cout << "Given number of edges are: " << a << endl;
    cout << "Given edges are: " << endl;
    print2DVector(b);

    int result = solve(a, b);
    cout << "Result: " << result << endl;
    return 0;
}

// g++ -std=c++11