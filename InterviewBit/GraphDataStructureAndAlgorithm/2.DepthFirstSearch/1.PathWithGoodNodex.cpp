/*

Problem Description

Given a tree with N nodes labelled from 1 to N.

Each node is either good or bad denoted by binary array A of size N where if A[i] is 1 then ithnode is good else if A[i] is 
0 then ith node is bad.

Also the given tree is rooted at node 1 and you need to tell the number of root to leaf paths in the tree that contain not more than C good nodes.

NOTE:

Each edge in the tree is bi-directional.


Problem Constraints
2 <= N <= 105

A[i] = 0 or A[i] = 1

0 <= C <= N



Input Format
First argument is an binary integer array A of size N.

Second argument is a 2-D array B of size (N-1) x 2 denoting the edge of the tree.

Third argument is an integer C.



Output Format
Return an integer denoting the number of root to leaf paths in the tree that contain not more than C good nodes.



Example Input
Input 1:

 A = [0, 1, 0, 1, 1, 1]
 B = [  [1, 2]
        [1, 5]
        [1, 6]
        [2, 3]
        [2, 4]
     ]
 C = 1


Example Output
Output 1:

 3


Example Explanation
Explanation 1:

 Path (1 - 2 - 3) and (1 - 5) and (1 - 6) are the paths which contain atmost C nodes.
 */
/*
Solution Approach:
The graph given is bi-directional.
We use of adj matrix to check if the current node is a leaf.
A leaf will be the one whose adj[] value will be 1, and that 1 node will be it's parent.
Now, while traveling, we keep track of current number of good nodes. When we encounter a leaf, 
we check our current count and increment the result if current count is less than c.
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

void print2DVector(vector< vector<bool> > arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void print2DVector(vector< vector<char> > arr){
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

void print2DStrings(vector< vector<string> > arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
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

void customDFS(int root, 
            vector<int> &a, 
            int c, 
            int* result, 
            vector<bool> &visited, 
            vector< vector<int> > &adj,
            int current_goods,
            int parent){
    // cout << "Current Node: " << root << endl;
    // cout << "Current Goods: " << current_goods << endl;
    visited[root] = true;
    if(a[root] == 1){
        current_goods++;
    }

    // see if this is leaf
    if(adj[root].size() == 1 && adj[root][0] == parent){
        // leaf
        if(current_goods <= c){
            (*result) = (*result) + 1;
        }
        return;
    } else {
        // not a leaf
        for(int i=0; i<adj[root].size(); i++){
            int neighbour = adj[root][i];
            if(!visited[neighbour]){
                customDFS(neighbour, a, c, result, visited, adj, current_goods, root);
            }
        }
    }
    return;
}

int solve(vector<int> &a, vector< vector<int> > &b, int c){
    int result = 0;

    // Create adj list
    vector< vector<int> > adj(a.size(), vector<int>());
    for(int i=0; i<b.size(); i++){
        int to = b[i][0] - 1;
        int from = b[i][1] - 1;
        adj[to].push_back(from);
        adj[from].push_back(to);
    }

    // Now, all the nodes with adj list of value 1 will be a leaf
    vector<bool> visited(a.size(), false);
    int parent = -1;
    customDFS(0, a, c, &result, visited, adj, 0, parent);

    return result;
}

int main(){
    vector<int> a = {0, 1, 0, 1, 1, 1};
    vector< vector<int> > b = {{1, 2}, {1, 5}, {1, 6}, {2, 3}, {2, 4}};
    int c = 1;
    cout << "Given good bad vector is: " << endl;
    printVector(a);
    cout << "Given edge vector is: " << endl;
    print2DVector(b);
    cout << "Given limit is: " << c << endl;

    int result = solve(a, b, c);
    cout << "Result: " << result << endl;    
    return 0;
}

// g++ -std=c++11