/*
Problem Description

Given a binary matrix A of size N x M.

 Cells which contain 1 are called filled cell and cell that contain 0 are called empty cell.

Two cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally.

If one or more filled cells are also connected, they form a region. Find the length of the largest region.



Problem Constraints
 1 <= N, M <= 102

 A[i][j]=0 or A[i][j]=1



Input Format
First argument is a 2D binary matrix Aof size  N x M.



Output Format
Return a single interger denoting the length of largest region.



Example Input
Input 1:

 A = [  [0, 0, 1, 1, 0]
        [1, 0, 1, 1, 0]
        [0, 1, 0, 0, 0]
        [0, 0, 0, 0, 1]
    ]
Input 2:

 A = [  [1, 1, 1]
        [0, 0, 1]
    ]


Example Output
Output 1:

 6
Output 2:

 4


Example Explanation
Explanation 1:

 The largest region is denoted by red color in the matrix:
    00110
    10110
    01000
    00001
Explanation 2:

 The largest region is:
    111
    001
*/

/*
Solution approach:

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
    int m = a[0].size();
    vector< set<int> > adj(n*m, set<int>());

    for(int i=0; i<a.size(); i++){
        for(int j=0; j<a[i].size(); j++){
            if(a[i][j] == 0){
                continue;
            }

            int to = j + i * m;
            int row, col, from;
            // up
            row = i-1;
            col = j;
            from = col + row * m;
            if(row >= 0 && row < n && col >=0 && col < m && a[row][col] == 1){
                adj[to].insert(from);
                adj[from].insert(to);
            }
            // down
            row = i+1;
            col = j;
            from = col + row * m;
            if(row >= 0 && row < n && col >=0 && col < m && a[row][col] == 1){
                adj[to].insert(from);
                adj[from].insert(to);
            }
            // left
            row = i;
            col = j-1;
            from = col + row * m;
            if(row >= 0 && row < n && col >=0 && col < m && a[row][col] == 1){
                adj[to].insert(from);
                adj[from].insert(to);
            }
            // right
            row = i;
            col = j+1;
            from = col + row * m;
            if(row >= 0 && row < n && col >=0 && col < m && a[row][col] == 1){
                adj[to].insert(from);
                adj[from].insert(to);
            }
            // up left
            row = i-1;
            col = j-1;
            from = col + row * m;
            if(row >= 0 && row < n && col >=0 && col < m && a[row][col] == 1){
                adj[to].insert(from);
                adj[from].insert(to);
            }
            // up right
            row = i-1;
            col = j+1;
            from = col + row * m;
            if(row >= 0 && row < n && col >=0 && col < m && a[row][col] == 1){
                adj[to].insert(from);
                adj[from].insert(to);
            }
            // down left
            row = i+1;
            col = j-1;
            from = col + row * m;
            if(row >= 0 && row < n && col >=0 && col < m && a[row][col] == 1){
                adj[to].insert(from);
                adj[from].insert(to);
            }
            // down right
            row = i+1;
            col = j+1;
            from = col + row * m;
            if(row >= 0 && row < n && col >=0 && col < m && a[row][col] == 1){
                adj[to].insert(from);
                adj[from].insert(to);
            }
        }
    }

    // cout << "Given graph is: " << endl;
    // for(int i=0; i<adj.size(); i++){
    //     if(adj[i].size() > 0){
    //         cout << i << " -> ";
    //         set<int>::iterator itr;
    //         for(itr = adj[i].begin(); itr != adj[i].end(); itr++){
    //             cout << *itr << " ";
    //         }
    //         cout << endl;
    //     }
    // }

    // travel the graph now
    vector<bool> visited(n*m, false);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == 0){
                continue;
            } else {
                int node = j + i * m;
                // if node is not visited
                if(!visited[node]){
                    // cout << "node : " << node << endl;
                    // cout << "i, j -> " << i << " " << j << endl;
                    queue<int> q;
                    q.push(node);
                    int count = 1;
                    visited[node] = true;
                    while(!q.empty()){
                        int front = q.front();
                        q.pop();
                        set<int>::iterator itr;
                        for(itr = adj[front].begin(); itr != adj[front].end(); itr++){
                            int currentNeighbour = *itr;
                            if(!visited[currentNeighbour]){
                                // cout << "Visiting neighbour: " << currentNeighbour << endl;
                                q.push(currentNeighbour);
                                visited[currentNeighbour] = true;
                                count++;
                            }
                        }
                    }
                    // cout << "Count: " << count << endl;
                    result = max(result, count);
                    // cout << "Result: " << result << endl << endl;
                }
            }
        }
    }

    return result;
}

int main(){
    vector< vector<int> > a = {
        {0, 0, 1, 1, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1}};
    cout << "Given graph is: " << endl;
    print2DVector(a);

    int result = solve(a);
    cout << "Result: " << result << endl;
    return 0;
}

// g++ -std=c++11