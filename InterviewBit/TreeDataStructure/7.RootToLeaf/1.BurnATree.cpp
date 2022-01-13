/*
Problem Description

Given a binary tree denoted by root node A and a leaf node B from this tree.

 It is known that all nodes connected to a given node (left child, right child and parent) get burned in 1 second. Then all the nodes which are connected through one intermediate get burned in 2 seconds, and so on.

You need to find the minimum time required to burn the complete binary tree.



Problem Constraints
2 <= number of nodes <= 105

1 <= node value, B <= 105

node value will be distinct



Input Format
First argument is a root node of the binary tree, A.

Second argument is an integer B denoting the node value of leaf node.



Output Format
Return an integer denoting the minimum time required to burn the complete binary tree.



Example Input
Input 1:

 Tree :      1 
            / \ 
           2   3 
          /   / \
         4   5   6
 B = 4
Input 2:

 Tree :      1
            / \
           2   3
          /     \
         4       5 
 B = 5 


Example Output
Output 1:

 4
Output 2:

 4


Example Explanation
Explanation 1:

 After 1 sec: Node 4 and 2 will be burnt. 
 After 2 sec: Node 4, 2, 1 will be burnt.
 After 3 sec: Node 4, 2, 1, 3 will be burnt.
 After 4 sec: Node 4, 2, 1, 3, 5, 6(whole tree) will be burnt.
 
Explanation 2:

 After 1 sec: Node 5 and 3 will be burnt. 
 After 2 sec: Node 5, 3, 1 will be burnt.
 After 3 sec: Node 5, 3, 1, 2 will be burnt.
 After 4 sec: Node 5, 3, 1, 2, 4(whole tree) will be burnt.
*/
/*
Solution Approach:
The minimum time required will be equal to height of the tree observed from the given node.

This should have worked, but it is not working. 
Fuck IB.
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

void customPreOrder(TreeNode *root, vector< vector<int> > &adj){
    if(root == 0){
        return;
    }

    int currentValue = root -> val;
    if( root -> left != 0){
        adj[currentValue].push_back(root -> left -> val);
        adj[root -> left -> val].push_back(currentValue);
        customPreOrder(root -> left, adj);
    }
    if( root -> right != 0){
        adj[currentValue].push_back(root -> right -> val);
        adj[root -> right -> val].push_back(currentValue);
        customPreOrder(root -> right, adj);
    }
}

int solve(TreeNode *root, int b){
    int result = 0;
    int N = 10001;
    vector<bool> visited(N, false);
    vector< vector<int> > adj(N, vector<int> ());
    customPreOrder(root, adj);
    queue<int> parent;
    queue<int> child;
    parent.push(b);
    while(!parent.empty()){

        while(!parent.empty()){
            int node = parent.front();
            parent.pop();
            visited[node] = true;
            vector<int> neighbours = adj[node];
            for(int i=0; i<neighbours.size(); i++){
                int currentNeighbour = neighbours[i];
                if(!visited[currentNeighbour]){
                    child.push(currentNeighbour);
                }
            }
        }

        while(!child.empty()){
            int front = child.front();
            child.pop();
            parent.push(front);
        }
        result++;
    }

    return result - 1;
}

int main(){
    int rootNode = 3;
    vector<int> a = {1,2,4,5};
    TreeNode *root = createTree(rootNode, a);
    cout << "Given Tree is:" << endl;
    inOrder(root); cout << endl;
    int b = 1;
    cout << "Node to start from is: " << b << endl;
    
    int result = solve(root, b);
    cout << "Result: " << result << endl;
    return 0;
}

// g++ -std=c++11