/*
Problem Description

There are A people numbered 1 to A in a football academy.

The coach of the academy wants to make two teams (not necessary of equal size) but unfortunately, not all people get along, and several refuse to be put on the same team as that of their enemies.

Given a 2-D array B of size M x 2 denoting the enemies i.e B[i][0] and B[i][1] both are enemies of each other.

Return 1 if it possible to make exactly two teams else return 0.



Problem Constraints
2 <= A <= 105

1 <= M <= 105

1 <= B[i][0], B[i][1] <= A

B[i][0] != B[i][1]



Input Format
First argument is an integer A denoting number of peoples.

Second argument is a 2-D array B of size M x 2 denoting enemies.



Output Format
Return 1 if it possible to make exactly two teams else return 0.



Example Input
Input 1:

 A = 5
 B = [ [1, 2],
       [2, 3],
       [1, 5],
       [2, 4] ] 
Input 2:

 A = 4
 B = [ [1, 4],
       [3, 1],
       [4, 3],
       [2, 1] ]


Example Output
Output 1:

 1 
Output 2:

 0 


Example Explanation
Explanation 1:

 We can make two teams [1, 3, 4] and [2, 5].
Explanation 2:

 No possible way to create two teams. So, we need to return 0.
*/
/*
Solution Approach:
We need to check if the given question is birartite or not.
That means that if we color one node to red, all it's neighbours should be blue.
That is what we are doing here. And this is supposed to be a BFS question not a DFS one.
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

int solve(int a, vector< vector<int> > &b){
    int result = 1;

    vector<int> color(a, 0);
    vector<bool> visited(a, false);
    vector< vector<int> > adj(a, vector<int>());
    for(int i=0; i<b.size(); i++){
        int to = b[i][0] - 1;
        int from = b[i][1] - 1;
        adj[to].push_back(from);
        adj[from].push_back(to);
    }

    // We have created graph
    queue<int> q;
    for(int i=0; i<a; i++){
        if(!visited[i]){
            q.push(i);
            visited[i] = true;
            color[i] = 1;
            while(!q.empty()){
                int top = q.front();
                q.pop();
                for(int i=0; i<adj[top].size(); i++){
                    int neighbour = adj[top][i];
                    int childColor = color[top] == 1 ? 2 : 1;
                    if(!visited[neighbour]){
                        q.push(neighbour);
                        color[neighbour] = childColor;
                        visited[neighbour] = true;
                    }
                }
            }
        }
    }

    // check all colors
    // cout << "Colors:" << endl;
    // for(int i=0; i<a; i++){
    //     cout << color[i] << " ";
    // }
    // cout << endl;

    // cout << "Visited: " << endl;
    // for(int i=0; i<a;i++){
    //     cout << visited[i] << " ";
    // }
    // cout << endl;

    // Now colors are assigned
    // check colors now
    visited.clear();
    for(int i=0; i<a; i++){
        visited.push_back(i);
    }

    // go through every guy again
    for(int i=0; i<a; i++){
        int rootColor = color[i];
        // if 1 then 2, else 1
        int expectedColor = color[i] == 1 ? 2 : 1;
        for(int j=0; j<adj[i].size(); j++){
            int neighbour = adj[i][j];
            int neighbourColor = color[neighbour];
            if(expectedColor != neighbourColor){
                result = 0;
                return result;
            }
        }
    }

    return result;
}

int main(){
    int a = 5;
    vector< vector<int> > b = {
        {1, 2},
        {2, 3},
        {1, 5},
        {2, 4}
    };
    cout << "Given number of nodes is: " << a << endl;
    cout << "Given enemies is: " << endl;
    print2DVector(b);

    int result = solve(a, b);
    cout << result << endl;
    return 0;
}

// g++ -std=c++11