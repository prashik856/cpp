/*
Problem Description
 
 

Given an integer array A with distinct elements, which represents the preorder traversal of a binary search tree,
 
construct the tree and return its root.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.



**Problem Constraints**
1 <= |A| <= 105
1 <= A.val <= 109
The given array is a valid preorder traversal of a BST.


**Input Format**
The first argument is an integer array denoting the preorder traversal.


**Output Format**
Return the root of the Binary Search Tree.


**Example Input**
Input 1:
A = [2, 1, 4, 3, 5]
Input 2:

A = [1, 2, 3]


**Example Output**
Output 1:
    2
   / \
  1   4
     / \
    3   5
Output 2:

      1
     /
    2
   /
  3


**Example Explanation**
Explanation 1:
We can see that is the tree created by the given pre order traversal.
Explanation 2:

We can see that is the tree created by the given pre order traversal.
*/
/*
The first element will be root.
Then we need to find the first element smaller than current element, and 1st element larget than first element.
Those will the left subtree root and right subtree root.
Repeat recursively.

Getting TLE.
Will work on it later.
Need to find next greater.
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

TreeNode *buildTreeMate(vector<int> &a, int low, int high){
    if(low > high){
        return 0;
    }

    int rootValue = a[low];
    TreeNode *node = new TreeNode(rootValue);
    
    int newLow = -1;
    int newMid = -1;

    for(int i=low+1; i<=high; i++){
        if(a[i] <= rootValue){
            newLow = i;
            break;
        } else if(a[i] > rootValue){
            break;
        }
    }

    for(int i=low + 1; i<=high; i++){
        if(a[i] > rootValue){
            newMid = i;
            break;
        }
    }

    if(newLow != -1 && newMid != -1){
        node -> left = buildTreeMate(a, newLow, newMid - 1);
        node -> right = buildTreeMate(a, newMid, high);
    } else if(newLow == -1 && newMid != -1){
        // left subtree is empty
        node -> right = buildTreeMate(a, newMid, high);
    } else if(newLow != -1 && newMid == -1){
        // right subtree is empty
        node -> left = buildTreeMate(a, newLow, high);
    }

    return node;
}

TreeNode *solve(vector<int> a){
    TreeNode *result = 0;

    int n = a.size();
    int low = 0;
    int high = n - 1;
    result = buildTreeMate(a, low, high);

    return result;
}

int main(){
    vector<int> a = {2, 1, 4, 3, 5};
    cout << "Given preorder traversal is: " << endl;
    printVector(a);

    TreeNode *result = solve(a);
    cout << "Result: " << endl;
    cout << "Inorder" << endl; inOrder(result); cout << endl;
    cout << "Preorder" << endl; preOrder(result); cout << endl;
    cout << "Postorder" << endl; postOrder(result); cout << endl;
    return 0;
}

// g++ -std=c++11