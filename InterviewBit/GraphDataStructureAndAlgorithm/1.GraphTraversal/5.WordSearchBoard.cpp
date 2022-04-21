/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The cell itself does not count as an adjacent cell. 

The same letter cell may be used more than once.

Example :

Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns 1,
word = "SEE", -> returns 1,
word = "ABCB", -> returns 1,
word = "ABFSAB" -> returns 1
word = "ABCD" -> returns 0
Note that 1 corresponds to true, and 0 corresponds to false.
*/
/*
Solution:
Find all the points where the first character of input string equals to board character.
From that character, run to all the 4 directions.
In the recursive function, take care of of input indices.
If next character is equal, we move on to next index, and then again in all four directions.
if found, return.
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

void doCustomDFS(int i, int j, vector<string> &a, int index, string &b, bool *found, int n, int m){
    // cout << "Inside custom DFS" << endl;
    // if found
    if(*found){
        return;
    }

    // if i is less than 0 or i is greater than equal to n
    if(i < 0 || i >=n){
        return;
    }

    // if j is less than 0 or j is greater than equal to m
    if(j < 0 || j >= m){
        return;
    }
    // cout << "Current word to search: " <<  b[index] << endl;
    // cout << "Current word: " << a[i][j] << endl;

    // if equal
    if(a[i][j] == b[index]){
        // cout << "Found: " << a[i][j] << " " << endl;
        // what is current index value?
        if(index + 1 >= b.size()){
            *found = true;
            return;
        }
        // our index value is yet to reach the end
        // move ahead to four sides
        doCustomDFS(i+1, j, a, index+1, b, found, n, m);
        doCustomDFS(i, j+1, a, index+1, b, found, n, m);
        doCustomDFS(i-1, j, a, index+1, b, found, n, m);
        doCustomDFS(i, j-1, a, index+1, b, found, n, m);
    }
    return;
}

int solve(vector<string> &a, string &b){
    int result = 0;

    int n = a.size();
    int m = a[0].size();

    // let's start
    int index = 0;
    bool found = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == b[index]){
                // search here
                // cout << "Found: "  << a[i][j] << endl;
                doCustomDFS(i+1,j,a,index+1,b,&found, n, m);
                doCustomDFS(i,j+1,a,index+1,b,&found, n, m);
                doCustomDFS(i-1,j,a,index+1,b,&found, n, m);
                doCustomDFS(i,j-1,a,index+1,b,&found, n, m);
            }
            if(found){
                result = 1;
                break;
            }
            // cout << endl;
        }
        if(found){
            result = 1;
            break;
        }
    }

    return result;
}

int main(){
    vector<string> a = { "ABCE",
                        "SFCS",
                        "ADEE"};
    string b = "ABCD";
    cout << "Given word board is: " << endl;
    printStrings(a);
    cout << "Given string to find is: " << endl;
    cout << b << endl;

    int result = solve(a, b);
    cout << "Result: " << result << endl;
    return 0;
}

// g++ -std=c++11