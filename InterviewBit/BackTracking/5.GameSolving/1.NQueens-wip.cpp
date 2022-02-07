/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

N Queens: Example 1

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,

There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/
/*
Solution Approach:
https://www.geeksforgeeks.org/n-queen-problem-backtracking-3/
I remember this solving in hackerrank
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

unordered_map<string, int> mapping;
void setVisited(int row, int col, vector< vector<bool> > &visited, int n){
    // already visited
    visited[row][col] = true;
    // up 
    for(int i=row+1; i<n; i++){
        visited[i][col] = true;
    }

    // down
    for(int i=row-1; i>=0; i--){
        visited[i][col] = true;
    }

    // right
    for(int i=col+1; i<n; i++){
        visited[row][i] = true;
    }

    // left
    for(int i=col-1; i>=0; i--){
        visited[row][i] = true;
    }

    // up right
    for(int i=row+1, j=col+1; i<n && j<n; i++,j++){
        visited[i][j] = true;
    }

    // up left
    for(int i=row+1, j=col-1; i<n && j>=0; i++,j--){
        visited[i][j] = true;
    }

    // down left
    for(int i=row-1,j=col-1; i>=0 && j>=0; i--,j--){
        visited[i][j] = true;
    }

    // down right
    for(int i=row-1,j=col+1; i>=0 && j<n; i--,j++){
        visited[i][j] = true;
    }
}

void unsetVisited(int row, int col, vector< vector<bool> > &visited, int n){
    // already visited
    visited[row][col] = false;
        // up 
    for(int i=row+1; i<n; i++){
        visited[i][col] = false;
    }

    // down
    for(int i=row-1; i>=0; i--){
        visited[i][col] = false;
    }

    // right
    for(int i=col+1; i<n; i++){
        visited[row][i] = false;
    }

    // left
    for(int i=col-1; i>=0; i--){
        visited[row][i] = false;
    }

    // up right
    for(int i=row+1, j=col+1; i<n && j<n; i++,j++){
        visited[i][j] = false;
    }

    // up left
    for(int i=row+1, j=col-1; i<n && j>=0; i++,j--){
        visited[i][j] = false;
    }

    // down left
    for(int i=row-1,j=col-1; i>=0 && j>=0; i--,j--){
        visited[i][j] = false;
    }

    // down right
    for(int i=row-1,j=col+1; i>=0 && j<n; i--,j++){
        visited[i][j] = false;
    }
}

bool isPossible(int row, int col, vector<string> board, int n){
    // already visited
    if(board[row][col] == 'Q'){
        return false;
    }

    // up 
    for(int i=row+1; i<n; i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }

    // down
    for(int i=row-1; i>=0; i--){
        if(board[i][col] == 'Q'){
            return false;
        }
    }

    // right
    for(int i=col+1; i<n; i++){
        if(board[row][i] == 'Q'){
            return false;
        }
    }

    // left
    for(int i=col-1; i>=0; i--){
        if(board[row][i] == 'Q'){
            return false;
        }
    }

    // up right
    for(int i=row+1, j=col+1; i<n && j<n; i++,j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    // up left
    for(int i=row+1, j=col-1; i<n && j>=0; i++,j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    // down left
    for(int i=row-1,j=col-1; i>=0 && j>=0; i--,j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    // down right
    for(int i=row-1,j=col+1; i>=0 && j<n; i--,j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    return true;
}

void getResult(int n, 
    int currentQueens, 
    vector<string> &board, 
    vector< vector<bool> > &visited, 
    vector< vector<string> > &result,
    int startRow,
    int startCol) {
        // cout << "Currentqueens: " << currentQueens << endl;
        // cout << "N : " << n << endl;
        // cout << "Board: " << endl;
        // printStrings(board);
        if(currentQueens == n){
            // store the result
            vector<string> temp = board;
            result.push_back(temp);
            return;
        }

        for(int i=startRow; i<n; i++){
            for(int j=startCol; j<n; j++){
                if(!visited[i][j]){
                    // check isPossible only when we can keep the queen here.
                    bool possible = isPossible(i, j, board, n);
                    if(possible){
                        // cout << "Initial board: " << endl;
                        // printStrings(board);
                        // cout << "Initial Visited: " << endl;
                        // print2DVector(visited);
                        // cout << "Possible for: " << i << " " << j << endl;
                        // set to q
                        board[i][j] = 'Q';
                        // set visited
                        setVisited(i, j, visited, n);

                        // go call recursion with currentQueens + 1
                        getResult(n, currentQueens + 1, board, visited, result, startRow + 1, startCol);

                        // backtrack
                        // unset q
                        board[i][j] = '.';
                        // unset visited
                        unsetVisited(i, j, visited, n);
                    }
                }
            }
        }
}

vector< vector<string> > solve(int n){
    vector< vector<string> > result;

    int currentQueens = 0;
    vector< vector<bool> > visited;
    vector<string> board;
    for(int i=0; i<n; i++){
        string temp = "";
        vector<bool> visitedTemp;
        for(int j=0; j<n; j++){
            temp.push_back('.');
            visitedTemp.push_back(false);
        }
        board.push_back(temp);
        visited.push_back(visitedTemp);
    }
    int startRow = 0;
    int startCol = 0;
    getResult(n, currentQueens, board, visited, result, startRow, startCol);

    return result;
}

int main(){
    int n = 9;
    cout << "Given number of queens is: " << n << endl;

    vector< vector<string> > result = solve(n);
    cout << "Result: " << endl;
    print2DStrings(result);
    return 0;
}

// g++ -std=c++11