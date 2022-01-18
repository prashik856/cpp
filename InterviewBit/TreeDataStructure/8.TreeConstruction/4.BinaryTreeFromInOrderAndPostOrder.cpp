/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note: You may assume that duplicates do not exist in the tree.

Example :

Input : 
        Inorder : [2, 1, 3]
        Postorder : [2, 3, 1]

Return : 
            1
           / \
          2   3

*/
/*
Solution Approach:
We start from back, and we find it's value in inorder array.
Now, left side of inorder array will be left subtree, right side will be right subtree.

Sending without pointers, it was getting TLE, while with pointers, it got accepted.
Sending it as reference passed? -> Weird!!!!!!!!!!!!!!!!!!!
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

unordered_map<int, int> mapping;
TreeNode *buildTreeMate(vector<int> &in, vector<int> &post, int ilow, int ihigh, int pindex){
    if(ilow > ihigh){
        return 0;
    }

    int rootValue = post[pindex];
    TreeNode *node = new TreeNode(rootValue);
    if(ilow == ihigh){
        return node;
    }
    // find this node in in order
    int index = mapping[rootValue] - 1;

    int leftSubtreeLength = index - ilow;
    int rightSubTreeLength = ihigh - index;
    // cout << "Root value: " << rootValue << endl; 
    // cout << "Index value: " << index << endl;
    // cout << "Length of left subtree: " << leftSubtreeLength << endl;
    // cout << "Length of right subtree: " << rightSubTreeLength << endl;
    // cout << endl;

    node -> left = buildTreeMate(in, post, ilow, index - 1, pindex - rightSubTreeLength - 1);
    node -> right = buildTreeMate(in, post, index + 1, ihigh, pindex - 1);
    return node;
}

TreeNode *solve(vector<int> in, vector<int> post){
    TreeNode *result = 0;

    int n = post.size();
    mapping.clear();
    // save indices
    for(int i=0; i<in.size(); i++){
        mapping[in[i]] = i + 1;
    }
    int ilow = 0;
    int ihigh = n-1;
    int pindex = n-1;
    result = buildTreeMate(in, post, ilow, ihigh, pindex);

    return result;
}

int main(){
    TreeNode* result = solve({1, 2, 3, 4, 5, 6, 7}, {1, 3, 2, 5, 7, 6, 4});
    cout << "Result: " << endl;
    cout << "Inorder" << endl;
    inOrder(result); cout << endl;
    cout << "Preorder: " << endl;
    preOrder(result); cout << endl;
    cout << "Post order: " << endl;
    postOrder(result); cout << endl;
    return 0;
}

// g++ -std=c++11