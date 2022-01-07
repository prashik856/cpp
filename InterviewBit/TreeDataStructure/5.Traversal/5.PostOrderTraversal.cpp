/*
Problem Description

Given a binary tree, return the Postorder traversal of its nodes values.

NOTE: Using recursion is not allowed.



Problem Constraints
 1 <= number of nodes <= 105



Input Format
First and only argument is root node of the binary tree, A.



Output Format
Return an integer array denoting the Postorder traversal of the given binary tree.



Example Input
Input 1:

   1
    \
     2
    /
   3
Input 2:

   1
  / \
 6   2
    /
   3


Example Output
Output 1:

 [3, 2, 1]
Output 2:

 [6, 3, 2, 1]


Example Explanation
Explanation 1:

 The Preoder Traversal of the given tree is [3, 2, 1].
Explanation 2:

 The Preoder Traversal of the given tree is [6, 3, 2, 1].
*/
/*
Solution using recursion:
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

void customPostOrder(TreeNode *a, vector<int> &result){
    if(a == 0){
        return;
    }

    customPostOrder(a -> left, result);
    customPostOrder(a -> right, result);
    result.push_back(a -> val);
}

void customPreOrder(TreeNode *a, vector<int> &result){
    if(a == 0){
        return;
    }

    result.push_back(a -> val);
    customPreOrder(a -> left, result);
    customPreOrder(a -> right, result);
}

void customInOrder(TreeNode *a, vector<int> &result){
    if(a == 0){
        return;
    }

    customInOrder(a -> left, result);
    result.push_back(a -> val);
    customInOrder(a -> right, result);
}

void inOrderStack(TreeNode *a, vector<int> &result){
    stack<TreeNode *> st;
    TreeNode *currentNode = a;
    st.push(currentNode);
    while(!st.empty()){
        currentNode = st.top() -> left;
        if(currentNode == 0){
            TreeNode *top = st.top();
            st.pop();
            if(top == 0 && st.empty()){
                break;
            }
            result.push_back(top -> val);
            currentNode = top -> right;
            st.push(currentNode);
        } else {
            st.push(currentNode);
        }
    }
}

vector<int> solve(TreeNode *a){
    vector<int> result;

    customPostOrder(a, result);

    return result;
}

int main(){
    int rootNode = 4;
    vector<int> a = {1,2,3,4,5};
    TreeNode *rootA = createTree(rootNode, a);
    cout << "Given Tree is: " << endl;
    inOrder(rootA); cout << endl;

    vector<int> result = solve(rootA);
    return 0;
}

// g++ -std=c++11