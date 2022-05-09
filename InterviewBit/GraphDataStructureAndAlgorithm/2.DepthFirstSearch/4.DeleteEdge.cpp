/*
Problem Description

Given a undirected tree with N nodes labeled  from 1 to N.

Each node has a certain weight assigned to it given by an integer array A of size N.

You need to delete an edge in such a way that Product between sum of weight of nodes in one subtree with sum of weight of nodes in other subtree is maximized.

Return this maximum possible product modulo 109 + 7.

NOTE:

The tree is rooted at node labeled with 1.


Problem Constraints
2 <= N <= 105

1 <= A[i] <= 103



Input Format
First argument is an integer array A of size N denoting the weight of each node.

Second argument is a 2-D array B of size (N-1) x 2 denoting the edge of the tree.



Output Format
Return a single integer denoting the maximum product prossible of sum of weights of nodes in the two subtrees formed by deleting an edge with modulo 109 + 7.



Example Input
Input 1:

 A = [10, 5, 12, 6]
 B = [

        [1, 2]
        [1, 4]
        [4, 3]
     ]
Input 2:

 A = [11, 12]
 B = [

        [1, 2]
     ]


Example Output
Output 1:

 270
Output 2:

 132


Example Explanation
Explanation 1:

 Removing edge (1, 4) created two subtrees.
 Subtree-1 contains nodes (1, 2) and Subtree-2 contains nodes (3, 4)
 So product will be = (A[1] + A[2]) * (A[3] + A[4]) = 15 * 18 = 270
Explanation 2:

 Removing edge (1, 2) created two subtrees.
 Subtree-1 contains node (1) and Subtree-2 contains node (3)
 So product will be = (A[1]) * (A[2]) = 11 * 12 = 132
*/
/*
Solution Approach:
https://www.geeksforgeeks.org/delete-edge-minimize-subtree-sum-difference/
We can solve this problem using DFS. 
One simple solution is to delete each edge one by one and check subtree sum difference. Finally choose the minimum of them. 
This approach takes quadratic amount of time. 
An efficient method can solve this problem in linear time by calculating the sum of both subtrees using total sum of the tree. 
We can get the sum of other tree by subtracting sum of one subtree from the total sum of tree, in this way subtree sum 
difference can be calculated at each node in O(1) time. 
First we calculate the weight of complete tree and then while doing the DFS at each node, we calculate its subtree sum, 
by using these two values we can calculate subtree sum difference. 
In below code, another array subtree is used to store sum of subtree rooted at node i in subtree[i]. 
DFS is called with current node index and parent index each time to loop over children only at each node.

Interview bit hint:
If you know the subtree sum at a node then you can get the sum of other tree by subtracting sum of one 
subtree from the total sum of tree, in this way subtree sum product can be calculated at each node in O(1) time.
use this fact to find a solution to the problem.


Approach:
We can solve this problem using DFS.
One simple solution is to delete each edge one by one and check subtree sum product.
Finally choose the minimum of them. This approach takes quadratic amount of time.

An efficient method can solve this problem in linear time by calculating the sum of both subtrees using total sum of the tree. 
We can get the sum of other tree by subtracting sum of one subtree from the total sum of tree, in this way subtree sum product 
can be calculated at each node in O(1) time.
First we calculate the weight of complete tree and then while doing the DFS at each node, 
we calculate its subtree sum, by using these two values we can calculate subtree sum product and maintain the maximum among all.

const int maxn = 100009;
vector < int > adj[maxn];
long long s;
long long maxe;
const int mod = 1e9 + 7;

int dfs(int u, int p, vector < int > & A) {
  long long sum = A[u - 1];
  for (int v: adj[u]) {
    if (v == p) continue;
    sum += dfs(v, u, A);
  }
  long long res = ((sum % mod) * ((s - sum) % mod)) % mod;
  maxe = max(maxe, res);
  return sum;
}

int Solution::deleteEdge(vector < int > & A, vector < vector < int > > & B) {

  s = 0; //total sum of tree
  maxe = 0; //maximum product

  //clearing the adjacency list
  for (int i = 0; i <= A.size(); i++)
    adj[i].clear();

  //Calculating sum of weights of all nodes
  for (int a: A)
    s += a;

  //Creating tree 
  for (auto & it: B) {
    adj[it[0]].push_back(it[1]);
    adj[it[1]].push_back(it[0]);
  }

  dfs(1, 0, A);

  return maxe;
}

Okay, so we just use normal dfs. And this dfs should return the sum. This just means that any dfs should return 
the whole sum of this current subtree!
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

long long customDFS(int root, 
    int parent, 
    long long totalSum, 
    vector< vector<int> > &adj, 
    long long *tempResult,
    vector<int> &a){
        // Calculate current subtree sum
        long long sum = a[root];
        for(int i=0; i<adj[root].size(); i++){
            int neighbour = adj[root][i];
            if(neighbour == parent){
                continue;
            }
            sum += customDFS(neighbour, root, totalSum, adj, tempResult, a);
        }
        long long remainder = totalSum - sum;
        // Actual comparison should look like this!
        // long long mult = sum * remainder;
        // *tempResult = max(*tempResult, mult);

        // Stupid interview bit wants this! This is plain wrong.
        long long mult = sum * remainder;
        mult = mult % 1000000007;
        *tempResult = max(*tempResult, mult);
        return sum;
}

int solve(vector<int> &a, vector< vector<int> > &b){
    int result = 0;
    long long tempResult = 0;
    int n = a.size();

    long long totalSum = 0;
    vector< vector<int> > adj(n, vector<int>());
    vector<long long> subSum(n);
    for(int i=0; i<a.size(); i++){
        totalSum += a[i];
        subSum[i] = a[i];
    }

    // adj matrix
    for(int i=0; i<b.size(); i++){
        int to = b[i][0] - 1;
        int from = b[i][1] - 1;
        adj[to].push_back(from);
        adj[from].push_back(to);
    }

    customDFS(0, -1, totalSum, adj, &tempResult, a);

    result = tempResult % 1000000007;
    return result;
}

int main(){
    vector<int> a = {10, 5, 12, 6};
    vector< vector<int> > b = {
        {1, 2},
        {1, 4},
        {4, 3}
    };
    cout << "Given weight is: " << endl;
    printVector(a);

    cout << "Given edge matrix is: " << endl;
    print2DVector(b);

    int result = solve(a, b);
    cout << result << endl;

    return 0;
}

// g++ -std=c++11