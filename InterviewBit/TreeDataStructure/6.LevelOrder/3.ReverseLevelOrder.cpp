/*
Problem Description

Given a binary tree, return the reverse level order traversal of its nodes values. (i.e, from left to right and from last level to starting level).



Problem Constraints
1 <= number of nodes <= 5 * 105

1 <= node value <= 105



Input Format
First and only argument is a pointer to the root node of the Binary Tree, A.



Output Format
Return an integer array denoting the reverse level order traversal from left to right.



Example Input
Input 1:

    3
   / \
  9  20
    /  \
   15   7
Input 2:

   1
  / \
 6   2
    /
   3


Example Output
Output 1:

 [15, 7, 9, 20, 3] 
Output 2:

 [3, 6, 2, 1]


Example Explanation
Explanation 1:

 Nodes as level 3 : [15, 7]
 Nodes at level 2: [9, 20]
 Nodes at level 1: [3]
 Reverse level order traversal will be: [15, 7, 9, 20, 3]
Explanation 2:

 Nodes as level 3 : [3]
 Nodes at level 2: [6, 2]
 Nodes at level 1: [1]
 Reverse level order traversal will be: [3, 6, 2, 1]
*/
/*
Let's write bfs first
Save nodes of every level in a vector. Ease pease.
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

vector<int> solve(TreeNode *root){
    vector<int> result;
    vector< vector<int> > levelWiseNodes;

    queue<TreeNode *> parent;
    queue<TreeNode *> child;
    TreeNode *tempNode = root;
    parent.push(tempNode);
    while(!parent.empty()){
        vector<int> currentLevelNodes;
        while(!parent.empty()){
            TreeNode *currentNode = parent.front();
            parent.pop();
            currentLevelNodes.push_back(currentNode -> val);
            if(currentNode -> left != 0){
                child.push(currentNode -> left);
            }
            if(currentNode -> right != 0){
                child.push(currentNode -> right);
            }
        }

        while(!child.empty()){
            TreeNode *front = child.front();
            child.pop();
            parent.push(front);
        }

        // at the end
        levelWiseNodes.push_back(currentLevelNodes);
    }

    int n = levelWiseNodes.size();
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<levelWiseNodes[i].size(); j++){
            result.push_back(levelWiseNodes[i][j]);
        }
    }

    return result;
}

int main(){
    int rootNode = 19;
    vector<int> a = {1,2,3,4,5, 34, 23, 2, 34, 9, 39, 90, 63, 63, 24, 95, 221, 23};
    TreeNode *root = createTree(rootNode, a);
    cout << "Given Tree is: " << endl;
    inOrder(root); cout << endl;

    vector<int> result = solve(root);
    cout << "Result: " << endl;
    printVector(result);
    return 0;
}

// g++ -std=c++11