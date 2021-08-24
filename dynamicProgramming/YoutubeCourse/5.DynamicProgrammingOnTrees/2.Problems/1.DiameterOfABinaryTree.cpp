/*
Diameter of Tree (Here, Binary Tree)
Number of nodes along the longest path between two leaf

Flow:
Problem Statement
Syntax Discussion
Code Variation

We need to get diameter of binary tree
We need 2 leaf Nodes
# of nodes(between and including)

How is it dp on tree?
-> We need to find the height of both left and right child
for every single node
-> Using this, we will find the diameter of the particular node
-> Now, using diameters of every tree, we can find the
diameter of the whole BT.

Now, what will be BC?
the same!

Now, what will be the Hypothesis?
That will be calculations done in left 
and right subtree
left = solve(r->left, r)
right = solve(r->right, r)

What will be induction?
temp = max(left, right)

*/

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int value){
            data = value;
            left = 0;
            right = 0;
        }
};

class BinaryTree{
    public:
        Node *root;
        BinaryTree() {
            root = 0;
        }

        void insert(int value){
            Node *node = new Node(value);
            if(root == 0){
                root = node;
            }

            else{
                bool flag = true;
                Node *temp = root;
                while(flag) {
                    if(value > temp -> data) {
                        // check if empty
                        if(temp -> right == 0) {
                            temp -> right = node;
                            flag = false;
                        } else {
                            temp = temp -> right;
                        }
                    } else {
                        // check if left empty
                        if(temp -> left == 0) {
                            temp -> left = node;
                            flag = false;
                        } else {
                            temp = temp -> left;
                        }
                    }
                }
            }

        }

        void pre(Node *node) {
            if(node == 0){
                return;
            }

            pre(node -> left);
            cout << node -> data << " ";
            pre(node -> right);
        }
};

int solve(Node *root, int* result){
    // Let's start with base condition
    if(root == 0){
        return 0;
    }

    // Hypothesis
    int left = solve(root -> left, result);
    int right = solve(root -> right, result);

    // Induction
    // the current height of the tree that we will be 
    // returning
    int temp = max(left, right) + 1;

    // Calculate the current answer
    int ans = 1 + left + right;

    // Calculate if this answer is the actual answer
    *result = max(ans, *result);

    // Return the current height
    return temp;
}

int main(){
    // Create binary tree first
    int maxSize = 100000;
    BinaryTree *binaryTree = new BinaryTree();
    for(int i=0; i<maxSize; i++){
        int value = rand();
        //cout << value << " ";
        binaryTree -> insert(value);
    }

    // binaryTree -> pre(binaryTree-> root);
    // cout << endl;

    int result = numeric_limits<int>::min();
    solve(binaryTree -> root, &result);

    cout << "The Diameter of the binary tree is: " << result << endl;
    return 0;
}