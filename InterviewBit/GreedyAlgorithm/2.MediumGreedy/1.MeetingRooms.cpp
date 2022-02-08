/*
Problem Description

Given an 2D integer array A of size N x 2 denoting time intervals of different meetings.

Where:

A[i][0] = start time of the ith meeting.
A[i][1] = end time of the ith meeting.
Find the minimum number of conference rooms required so that all meetings can be done.



Problem Constraints
1 <= N <= 10

0 <= A[i][0] < A[i][1] <= 2 * 109



Input Format
The only argument given is the matrix A.



Output Format
Return the minimum number of conference rooms required so that all meetings can be done.



Example Input
Input 1:

 A = [      [0, 30]
            [5, 10]
            [15, 20]
     ]

Input 2:

 A =  [     [1, 18]
            [18, 23]
            [15, 29]
            [4, 15]
            [2, 11]
            [5, 13]
      ]


Example Output
Output 1:

 2
Output 2:

 4


Example Explanation
Explanation 1:

 Meeting one can be done in conference room 1 form 0 - 30.
 Meeting two can be done in conference room 2 form 5 - 10.
 Meeting one can be done in conference room 2 form 15 - 20 as it is free in this interval.
Explanation 2:

 Meeting one can be done in conference room 1 from 1 - 18.
 Meeting five can be done in conference room 2 from 2 - 11.
 Meeting four can be done in conference room 3 from 4 - 15.
 Meeting six can be done in conference room 4 from 5 - 13.
 Meeting three can be done in conference room 2 from 15 - 29 as it is free in this interval.
 Meeting two can be done in conference room 4 from 18 - 23 as it is free in this interval.
*/
/*
Solution Approach:
Yesss my technique worked.
For this quesiton, we make use of priority queue and greedy.
For greedy approach, we sort the meeting times.
Start the first meeting, keep track of maximum rooms required and current rooms required.
We need to look at when the meetings are going to end and next meeting is goint to start.
Empty the rooms before starting a new meeting. This is done by using priority queue and popping all
the elements when meeting start time > any other ongoing meeting time.
We then push the current meeting end time in our queue, and update the meeting time that meeting value which 
is going to end first. This is tracked by q.top() value.
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

int solve(vector< vector<int> > &a){
    int result = 0;

    int n = a.size();
    sort(a.begin(), a.end());
    // we need to keep track of lowest value
    // We will use priority queue for this
    priority_queue<int, vector<int>, greater<int> > q;
    result = 1;
    int currentRooms = 1;
    int r1 = a[0][1];
    q.push(r1);
    for(int i=1; i<n; i++){
        int l2 = a[i][0];
        int r2 = a[i][1];

        // free all rooms
        if(l2 >= r1){
            // we can free rooms here
            while(!q.empty() && l2 > q.top()){
                currentRooms--;
                q.pop();
            }

            // Put the current meeting in rooms
            currentRooms++;
            result = max(result, currentRooms);
            q.push(r2);
            r1 = q.top();
        } else {
            // We cannot free rooms here
            currentRooms++;
            result = max(result, currentRooms);
            q.push(r2);
            r1 = q.top();
        }
    }

    return result;
}

int main(){
    vector< vector<int> > a = {{0, 30}, {5, 10}, {15, 20}};
    cout << "Given meeting timings are: " << endl;
    print2DVector(a);

    int result = solve(a);
    cout << "Minimum number of rooms required are: " << result << endl;
    return 0;
}

// g++ -std=c++11