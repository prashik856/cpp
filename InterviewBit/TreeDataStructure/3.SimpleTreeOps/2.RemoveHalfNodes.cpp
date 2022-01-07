/*
Problem Description

Given a binary tree A with N nodes.

You have to remove all the half nodes and return the final binary tree.

NOTE:

Half nodes are nodes which have only one child.
Leaves should not be touched as they have both children as NULL.


Problem Constraints
 1 <= N <= 105



Input Format
First and only argument is an pointer to the root of binary tree A.



Output Format
Return a pointer to the root of the new binary tree.



Example Input
Input 1:

           1
         /   \
        2     3
       / 
      4

Input 2:

            1
          /   \
         2     3
        / \     \
       4   5     6


Example Output
Output 1:

           1
         /   \
        4     3
Output 2:

            1
          /   \
         2     6
        / \

       4   5



Example Explanation
Explanation 1:

 The only half node present in the tree is 2 so we will remove this node.
Explanation 2:

 The only half node present in the tree is 3 so we will remove this node.
*/
/*
Let's see how this will go.
Just fyi, we need a parent value here.
Okay. My logic worked. Just remove any half nodes, and remember to return the new root.
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

void printStrings(vector<string> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << endl;
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

TreeNode *customPreOrder(TreeNode *root, TreeNode *parent){
    if(root == 0){
        // cout << "Root is empty" << endl;
        return root;
    }

    // leaf
    if(root -> left == 0 && root -> right == 0){
        // cout << "Encountered a leaf node" << endl;
        return root;
    }

    // half node
    while(!(root -> left == 0 && root -> right == 0) && 
            (root -> left == 0 || root -> right == 0)){
        // cout << "Encountered a half node " << root -> val << endl;
        
        TreeNode *node;
        if(root -> left != 0){
            // cout << root -> left -> val << " is non-empty" << endl;
            node = root -> left;
        } else {
            // cout << root -> right -> val << " is non-empty" << endl;
            node = root -> right;
        }

        if(parent != 0){
            // cout << "Parent is non zero " << parent -> val << endl;
            if(parent -> left == root){
                parent -> left = node;
                root = node;
            } else {
                parent -> right = node;
                root = node;
            }
        } else {
            // root
            // cout << "Parent is null" << endl;
            root = node;
        }
    }

    customPreOrder(root -> left, root);
    customPreOrder(root -> right, root);

    return root;
}

TreeNode *solve(TreeNode *root){
    TreeNode *parent = 0;
    root = customPreOrder(root, parent);
    return root;
}

int main(){
    int rootNode = 3;
    vector<int> a = {1, 2, 4, 5};
    TreeNode *root = createTree(rootNode, a);
    cout << "Given tree is: " << endl;
    inOrder(root);
    cout << endl;

    TreeNode *result = solve(root);
    cout << "Resulting tree is: " << endl;
    inOrder(result);
    cout << endl;
    return 0;
}

// g++ -std=c++11
