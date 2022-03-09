/*
Problem Description

Given a 2D character matrix A of size N x M, containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.



Problem Constraints
1 <= N, M <= 103



Input Format
First and only argument 2D character matrix A of size N X M.



Output Format
Make changes to the the input only as matrix is passed by reference.



Example Input
Input 1:

 A = [  [X, X, X, X],
        [X, O, O, X],
        [X, X, O, X],
        [X, O, X, X]
     ]


Example Output
Output 1:

 A = [  [X, X, X, X],
        [X, X, X, X],
        [X, X, X, X],
        [X, O, X, X]
     ]


Example Explanation
Explanation 1:

 'O' in (4,2) is not surrounded by X from below.
*/
/*
Solution Approach:
https://www.geeksforgeeks.org/given-matrix-o-x-replace-o-x-surrounded-x/

Here, we will first replace all the values of 0 with -.
Now, we find all the values - which are present on the boundary of this matrix whose value is -, and 
we run bfs on all of these coordinates. While running bfs, we replace the value of - with 0.
Once this is done, we will replace all values of - with X. 
Done.
Cooooooool.
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

vector< vector<char> > solve(vector< vector<char> > &a){
    // replace 0 with -
    int n = a.size();
    int m = a[0].size();
    queue< vector<int> > q;
    vector< vector<bool> > visited(n, vector<bool> (m, false));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == 'O'){
                // Save boundary coordinate
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    // Save coordinate
                    vector<int> temp = {i,j};
                    // Visited that node
                    visited[i][j] = true;
                    // Push into queue
                    q.push(temp);
                }
                // Replace with -
                a[i][j] = '-';
            }
        }
    }
    // cout << "Matrix after updated: " << endl;
    // print2DVector(a);
    // cout << "Number of elements in the queue: " << endl;
    // cout << q.size() << endl;

    while(!q.empty()){
        vector<int> front = q.front();
        q.pop();
        int row = front[0];
        int col = front[1];
        a[row][col] = 'O';

        // up
        if(row - 1 >= 0 && a[row - 1][col] == '-' && !visited[row-1][col]){
            vector<int> temp = {row - 1, col};
            visited[row-1][col] = true;
            q.push(temp);
        }

        // down
        if(row + 1 < n && a[row+1][col] == '-' && !visited[row+1][col]){
            vector<int> temp = {row + 1, col};
            visited[row+1][col] = true;
            q.push(temp);
        }

        // left
        if(col - 1 >= 0 && a[row][col - 1] == '-' && !visited[row][col - 1]){
            vector<int> temp = {row, col - 1};
            visited[row][col - 1] = true;
            q.push(temp);
        }

        // right
        if(col + 1 < m && a[row][col + 1] == '-' && !visited[row][col + 1]){
            vector<int> temp = {row, col + 1};
            visited[row][col + 1] = true;
            q.push(temp);
        }
    }
    // cout << "Matrix after 0 updated: " << endl;
    // print2DVector(a);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == '-'){
                a[i][j] = 'X';
            }
        }
    }

    return a;
}

int main(){
    vector< vector<char> > a = {{'X', 'O', 'X', 'X', 'X', 'X'},
                                {'X', 'O', 'X', 'X', 'O', 'X'},
                                {'X', 'X', 'X', 'O', 'O', 'X'},
                                {'O', 'X', 'X', 'X', 'X', 'X'},
                                {'X', 'X', 'X', 'O', 'X', 'O'},
                                {'O', 'O', 'X', 'O', 'O', 'O'},
                                };
    cout << "Given input matrix is: " << endl;
    print2DVector(a);

    vector< vector<char> > result = solve(a);
    cout << "Result: " << endl;
    print2DVector(result);
    return 0;
}

// g++ -std=c++11