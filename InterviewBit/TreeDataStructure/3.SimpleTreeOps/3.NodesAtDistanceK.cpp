/*
Problem Description
 
 

Given the root of a binary tree A, the value of a target node B, and an integer C, return an array of the values of all nodes that have a distance C from the target node.

You can return the answer in any order.


Problem Constraints
1 ≤ N ≤ 105 (N is the number of nodes in the binary tree)
1 ≤ Ai ≤ N (Ai denotes the values of the nodes in the tree)
All the values in the nodes are unique.
1 ≤ C ≤ 104


Input Format
The first argument is the root node of the binary tree A.
The second argument is an integer B denoting the label of the target node.
The third argument is an integer C denoting the distance.


Output Format
Return an array of integers denoting the nodes which are at a distance C from the node B.


Example Input
Input 1:
A =     1
       / \
      2   3
     / \
    4   5


B = 2
C = 1

Input 2:

A =     1
       / \
      2   3
     / \
    4   5


B = 2
C = 2



Example Output
Output 1:
[1, 4, 5]
Output 2:

[3]


Example Explanation
Explanation 1: 

For the given tree, we have target node as 2.

All the nodes with are at distance 1, meaning the adjacent nodes are [1, 4, 5].

Explanation 2:

The given tree is same, and [3] is the only node with distance 2.
*/
/*
What we can do here is, create an acutal graph using adjacent nodes, and then using bfs to get all 
the nodes at a particular distance.
All the values are unique.

Yeah, this worked.
But takes a lot of time to code man.
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

void customPreOrder(TreeNode *root, vector< vector<int> > &adjacencyVector){
    if(root == 0){
        return;
    }
    int node = root -> val;
    if(root -> left != 0){
        int left = root -> left -> val;
        adjacencyVector[node].push_back(left);
        adjacencyVector[left].push_back(node);
        customPreOrder(root -> left, adjacencyVector);
    }
    if(root -> right != 0){
        int right = root -> right -> val;
        adjacencyVector[node].push_back(right);
        adjacencyVector[right].push_back(node);
        customPreOrder(root -> right, adjacencyVector);
    }
}

vector<int> solve(TreeNode *root, int b, int c){
    vector<int> result;
    
    int N = 100001;
    vector< vector<int> > adjacencyVector(N, vector<int>());
    customPreOrder(root, adjacencyVector);
    // cout << "Given Graph is: " << endl;
    // for(int i=0; i<N; i++){
    //     if(adjacencyVector[i].size() > 0){
    //         cout << i << " -> ";
    //         for(int j=0; j<adjacencyVector[i].size(); j++){
    //             cout << adjacencyVector[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    // }

    // Okay, now that we have created our graph, we need to use bfs
    queue<int> parents;
    queue<int> child;
    vector<bool> visited(N, false);
    int currentDistance = 0;
    parents.push(b);
    while(currentDistance <= c){
        while(!parents.empty()){
            int node = parents.front();
            parents.pop();
            visited[node] = true;
            // cout << "Vising node: " << node << endl;
            for(int i=0; i<adjacencyVector[node].size(); i++){
                int childNode = adjacencyVector[node][i];
                if(!visited[childNode]){
                    child.push(childNode);
                }
            }
        }
        currentDistance++;
        // cout << "Current Distance is: " << currentDistance << endl;
        // cout << "Number of nodes at this distance is: " << child.size() << endl;

        // Now at currentdistance, we have child.size() nodes
        if(currentDistance == c){
            // cout << "Nodes at distance c: " << child.size() << endl;
            while(!child.empty()){
                result.push_back(child.front());
                child.pop();
            }
            break;
        } else {
            while(!child.empty()){
                int top = child.front();
                parents.push(top);
                child.pop();
            }
        }
    }

    return result;
}

int main(){
    int rootNode = 4;
    vector<int> a = {3, 5,1,2,6,7};
    TreeNode *root = createTree(rootNode, a);
    cout << "Given tree is: " << endl;
    inOrder(root);
    cout << endl;
    int b = 2;
    cout << "Given node to start from : " << b << endl;
    int c = 6;
    cout << "Distance to look at: " << c << endl;

    vector<int> result = solve(root, b, c);
    cout << "Result: " << endl;
    printVector(result);
    return 0;
}

// g++ -std=c++11