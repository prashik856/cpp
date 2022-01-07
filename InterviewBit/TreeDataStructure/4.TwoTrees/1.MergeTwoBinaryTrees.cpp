/*
Problem Description

Given two Binary Trees A and B, you need to merge them in a single binary tree.

The merge rule is that if two nodes overlap, then sum of node values is the new value of the merged node.

Otherwise, the non-null node will be used as the node of new tree.



Problem Constraints
1 <= Number of Nodes in A , B <= 105



Input Format
First argument is an pointer to the root of binary tree A.

Second argument is an pointer to the root of binary tree B.



Output Format
Return a pointer to the root of new binary tree.



Example Input
Input 1:

 A =   2

      / \

     1   4

    /

   5


B =   3
      / \
      6  1
      \   \
       2   7

Input 2:

 A =   12

      / \

     11  14            


B =   3
      / \
      6  1



Example Output
Output 1:

     5
    / \
   7   5
  / \   \ 
 5   2   7
Output 2:

   15
  / \
 17  15


Example Explanation
Explanation 1:

 After merging both the trees you get:
     5
    / \
   7   5
  / \   \ 
 5   2   7
Explanation 2:

 After merging both the trees we get:
   15
  / \
 17  15
*/
/*
Solution Approach:
Easy preorder traversal solution.
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

void customePreOrder(TreeNode *rootA, TreeNode *rootB, TreeNode *parent){
    // See left child
    // if a -> left is zero
    TreeNode *newNode;
    if(rootA -> left == 0 && rootB -> left != 0){
        newNode = rootB -> left;
        parent -> left = newNode;
        // that's it, no need to move ahead.
    } 
    // if b->left is zero
    else if(rootA -> left != 0 && rootB -> left == 0){
        newNode = rootA -> left;
        parent -> left = newNode;
    } 
    // both are not equal to zero
    else if(rootA -> left != 0 && rootB -> left != 0){
        int val = rootA -> left -> val + rootB -> left -> val;
        newNode = new TreeNode(val);
        parent -> left = newNode;
        customePreOrder(rootA -> left, rootB -> left, newNode);
    }

    // See Right child
    TreeNode *rightNode;
    if(rootA -> right == 0 && rootB -> right != 0){
        rightNode = rootB -> right;
        parent -> right = rightNode;
        // that's it, no need to move ahead.
    } 
    // if b->left is zero
    else if(rootA -> right != 0 && rootB -> right == 0){
        rightNode = rootA -> right;
        parent -> right = rightNode;
    } 
    // both are not equal to zero
    else if(rootA -> right != 0 && rootB -> right != 0){
        int val = rootA -> right -> val + rootB -> right -> val;
        rightNode = new TreeNode(val);
        parent -> right = rightNode;
        customePreOrder(rootA -> right, rootB -> right, rightNode);
    }
}

TreeNode *solve(TreeNode *rootA, TreeNode *rootB){
    TreeNode *result;
    if(rootA == 0){
        return rootB;
    }
    if(rootB == 0){
        return rootA;
    }
    int val = rootA -> val + rootB -> val;
    result = new TreeNode(val);
    customePreOrder(rootA, rootB, result);
    return result;
}

int main(){
    int rootNodeA = 15;
    vector<int> a = {1,22,13,44,59};
    int rootNodeB = 20;
    vector<int> b = {1,5,4,3,5,93,35,23,5,2,53};

    TreeNode *rootA = createTree(rootNodeA, a);
    TreeNode *rootB = createTree(rootNodeB, b);
    cout << "Given Trees are: " << endl;
    preOrder(rootA); cout << endl;
    preOrder(rootB); cout << endl;

    TreeNode *result = solve(rootA, rootB);
    cout << "Resulting Tree is: " << endl;
    preOrder(result); cout << endl;
    return 0;
}

// g++ -std=c++11