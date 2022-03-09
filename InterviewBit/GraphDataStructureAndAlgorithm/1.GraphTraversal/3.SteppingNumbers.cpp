/*
Problem Description

Given A and B you have to find all stepping numbers in range A to B.

The stepping number:

A number is called as a stepping number if the adjacent digits have a difference of 1.

e.g. 123 is stepping number, but 358 is not a stepping number



Input Format
First argument is an integer A.

Second argument is an integer B.



Output Format
Return a integer array sorted in ascending order denoting the stepping numbers between A and B.



Example Input
Input 1:

 A = 10
 B = 20


Example Output
Output 1:

 [10, 12]


Example Explanation
Explanation 1:

 All stepping numbers are 10 , 12 
*/
/*
Solution Approach:
https://www.geeksforgeeks.org/stepping-numbers/
Method 2: Using BFS/DFS
The idea is to use a Breadth First Search/Depth First Search traversal.
How to build the graph? 
Every node in the graph represents a stepping number; 
there will be a directed edge from a node U to V if V can be transformed from U. 
(U and V are Stepping Numbers) A Stepping Number V can be transformed from U in following manner.
lastDigit refers to the last digit of U (i.e. U % 10) 
An adjacent number V can be:  
U*10 + lastDigit + 1 (Neighbor A)
U*10 + lastDigit – 1 (Neighbor B)
By applying above operations a new digit is appended to U, it is either lastDigit-1 or lastDigit+1, 
so that the new number V formed from U is also a Stepping Number. 
Therefore, every Node will have at most 2 neighboring Nodes.

Edge Cases: When the last digit of U is 0 or 9
Case 1: lastDigit is 0 : In this case only digit ‘1’ can be appended.
Case 2: lastDigit is 9 : In this case only digit ‘8’ can be appended.

What will be the source/starting Node?  
Every single digit number is considered as a stepping Number, 
so bfs traversal for every digit will give all the stepping numbers starting from that digit.
Do a bfs/dfs traversal for all the numbers from [0,9].
Note: For node 0, no need to explore neighbors during BFS traversal since it will lead to 01, 012, 010 and 
these will be covered by the BFS traversal starting from node 1. 

Example to find all the stepping numbers from 0 to 21
-> 0 is a stepping Number and it is in the range
   so display it.
-> 1 is a Stepping Number, find neighbors of 1 i.e.,
   10 and 12 and push them into the queue

How to get 10 and 12?
Here U is 1 and last Digit is also 1 
V = 10 + 0 = 10 ( Adding lastDigit - 1 )
V = 10 + 2 = 12 ( Adding lastDigit + 1 )

Then do the same for 10 and 12 this will result into
101, 123, 121 but these Numbers are out of range. 
Now any number transformed from 10 and 12 will result
into a number greater than 21 so no need to explore 
their neighbors.

-> 2 is a Stepping Number, find neighbors of 2 i.e. 
   21, 23.
-> 23 is out of range so it is not considered as a 
   Stepping Number (Or a neighbor of 2)

The other stepping numbers will be 3, 4, 5, 6, 7, 8, 9.
Coooooool
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

vector<int> solve(int a, int b){
    vector<int> result;

    queue<int> q;
    unordered_map<int, int> mapping;
    for(int i=0; i<=9; i++){
        q.push(i);
        mapping[i] = 1;
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(node >= a && node <=b){
            result.push_back(node);
        }

        int lastDigit = node % 10;
        if(lastDigit == 0){
            // only append
            int v1 = node * 10 + lastDigit + 1;
            if(v1 <=b && mapping.find(v1) == mapping.end()){
                q.push(v1);
                mapping[v1] = 1;
            }
        } else if(lastDigit == 9){
            // -1
            int v1 = node * 10 + lastDigit - 1;
            if(v1 <= b && mapping.find(v1) == mapping.end()){
                q.push(v1);
                mapping[v1] = 1;
            }
        } else {
            // +1 and -1
            int v1 = node * 10 + lastDigit + 1;
            if(v1 <= b && mapping.find(v1) == mapping.end()){
                q.push(v1);
                mapping[v1] = 1;
            }

            int v2 = node * 10 + lastDigit - 1;
            if(v2 <= b && mapping.find(v2) == mapping.end()){
                q.push(v2);
                mapping[v2] = 1;
            }
        }
    }
    sort(result.begin(), result.end());
    return result;
}

int main(){
    int a = 213;
    int b = 231141;
    cout << "Given inputs are: " << a << " " << b << endl;

    vector<int> result = solve(a, b);
    cout << "Result: " << endl;
    printVector(result);
    return 0;
}

// g++ -std=c++11