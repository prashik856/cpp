/*
Problem Description

Given an N x M matrix A of non-negative integers representing the height of each unit cell in a continent, the "Blue lake" touches the left and top edges of the matrix and the "Red lake" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the number of cells from where water can flow to both the Blue and Red lake.



Problem Constraints
1 <= M, N <= 1000

1 <= A[i][j] <= 109



Input Format
First and only argument is a 2D matrix A.



Output Format
Return an integer denoting the number of cells from where water can flow to both the Blue and Red lake.



Example Input
Input 1:

 A = [
       [1, 2, 2, 3, 5]
       [3, 2, 3, 4, 4]
       [2, 4, 5, 3, 1]
       [6, 7, 1, 4, 5]
       [5, 1, 1, 2, 4]
     ]
Input 2:

 A = [
       [2, 2]
       [2, 2]
     ]


Example Output
Output 1:

 7
Output 2:

 4


Example Explanation
Explanation 1:

 Blue Lake ~   ~   ~   ~   ~ 
        ~  1   2   2   3  (5) *
        ~  3   2   3  (4) (4) *
        ~  2   4  (5)  3   1  *
        ~ (6) (7)  1   4   5  *
        ~ (5)  1   1   2   4  *
           *   *   *   *   * Red Lake
 Water can flow to both lakes from the cells denoted in parentheses.

Explanation 2:

 Water can flow from all cells.
*/
/*
Solution Approach:
Run bfs twice, one from all the co-ordinates connected to red lake and other from blue lake.
Mark the visited cell and count the cell which are visited in both bfs.
Yup. This will work!
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

int solve(vector< vector<int> > a){
    int result = 0;
    // Create graph
    int rows = a.size();
    int cols = a[0].size();
    vector< vector<int> > visitedBlue(rows, vector<int>(cols, false));
    vector< vector<int> > visitedRed(rows, vector<int>(cols, false));
    // create queue
    queue< vector<int> > q;


    // blue lake
    // [0][i] and [i][0]
    // cols of blue lake
    for(int i=0; i<cols; i++){
        int row = 0;
        int col = i;
        visitedBlue[row][col] = true;
        vector<int> temp = {row, col};
        q.push(temp);
    }
    // rows of blue lake
    for(int i=0; i<rows; i++){
        int row = i;
        int col = 0;
        visitedBlue[row][col] = true;
        vector<int> temp = {row, col};
        q.push(temp);
    }
    cout << "all nodes from blue" << endl;
    // perform bfs
    while(!q.empty()){
        vector<int> node = q.front();
        q.pop();
        int row = node[0];
        int col = node[1];
        cout << "Node: " << a[row][col] << endl;
        // up 
        if(row - 1 >= 0 && a[row][col] >= a[row-1][col] && !visitedBlue[row - 1][col]){
            visitedBlue[row-1][col] = true;
            vector<int> neighbour = {row - 1, col};
            q.push(neighbour);
        }

        // down
        if(row + 1 < rows && a[row][col] >= a[row + 1][col] && !visitedBlue[row+1][col]){
            visitedBlue[row+1][col] = true;
            vector<int> neighbour = {row+1, col};
            q.push(neighbour);
        }

        // left
        if(col - 1 >= 0 && a[row][col] >= a[row][col - 1] && !visitedBlue[row][col - 1]){
            visitedBlue[row][col - 1] = true;
            vector<int> neighbour = {row, col - 1};
            q.push(neighbour);
        }

        // right
        if(col + 1 < cols && a[row][col] >= a[row][col + 1] && !visitedBlue[row][col + 1]){
            visitedBlue[row][col + 1] = true;
            vector<int> neighbour = {row, col + 1};
            q.push(neighbour);
        }
    }
    cout << "Visited Blue: " << endl;
    print2DVector(visitedBlue);
    cout << endl;

    // Red lake
    // [rows-1][i] and [i][cols-1]
    for(int i=0; i<cols; i++){
        int row = rows - 1;
        int col = i;
        visitedRed[row][col] = true;
        vector<int> temp = {row, col};
        q.push(temp);
    }

    for(int i=0; i<rows; i++){
        int row = i;
        int col = cols - 1;
        visitedRed[row][col] = true;
        vector<int> temp = {row, col};
        q.push(temp);
    }
    cout << "All nodes from red" << endl;
    // perform bfs
    while(!q.empty()){
        vector<int> node = q.front();
        q.pop();
        int row = node[0];
        int col = node[1];
        int val = a[row][col];
        cout << "Node: " << val << endl;
        // up 
        if(row - 1 >= 0 && a[row][col] >= a[row-1][col] && !visitedRed[row - 1][col]){
            visitedRed[row-1][col] = true;
            vector<int> neighbour = {row - 1, col};
            q.push(neighbour);
        }

        // down
        if(row + 1 < rows && a[row][col] >= a[row + 1][col] && !visitedRed[row+1][col]){
            visitedRed[row+1][col] = true;
            vector<int> neighbour = {row+1, col};
            q.push(neighbour);
        }

        // left
        if(col - 1 >= 0 && a[row][col] >= a[row][col - 1] && !visitedRed[row][col - 1]){
            visitedRed[row][col - 1] = true;
            vector<int> neighbour = {row, col - 1};
            q.push(neighbour);
        }

        // right
        if(col + 1 < cols && a[row][col] >= a[row][col + 1] && !visitedRed[row][col + 1]){
            visitedRed[row][col + 1] = true;
            vector<int> neighbour = {row, col + 1};
            q.push(neighbour);
        }
    }
    cout << "Visited Red: " << endl;
    print2DVector(visitedRed);
    cout << endl;

    return result;
}

int main(){
    vector< vector<int> > a = {
       {1, 2, 2, 3, 5},
       {3, 2, 3, 4, 4},
       {2, 4, 5, 3, 1},
       {6, 7, 1, 4, 5},
       {5, 1, 1, 2, 4}
       };
    cout << "Given cube is: " << endl;
    print2DVector(a);

    int result = solve(a);
    cout << "Result: " << result << endl;
    return 0;
}

// g++ -std=c++11