/**
 * Height of binary tree.
 * 
 Create a binary tree.
 Get height of the binary tree.

 Flow:
 1. Problem statement, Input, Output
 2. Design IBH
 3. Code.
 */
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int value;
        Node *left;
        Node *right;

        Node(int val) {
            value = val;
            left = 0;
            right = 0;
        }
};

class BinaryTree{
    public:
        Node *createBinaryTree(int inputValue) {
            Node *newNode = new Node(inputValue);
            return newNode;
        }

        void addNode(Node *node, int inputValue) {

            // cout << "Current Root value: " << node -> value << endl;
            // cout << "Input value: " << inputValue << endl;

            if(inputValue <= node->value && node->left == 0) {
                // cout << "Less than node and left node empty" << endl;
                Node *newNode = new Node(inputValue);
                node->left = newNode;
                return;
            }

            if(inputValue > node->value && node->right == 0) {
                // cout << "Greater than node and right node empty" << endl;
                Node *newNode = new Node(inputValue);
                node->right = newNode;
                return;
            }

            if(inputValue <= node->value && node->left != 0) {
                // cout << "Less than node and left node not empty" << endl;
                addNode(node->left, inputValue);
                return;
            }

            if(inputValue > node->value && node->right != 0) {
                // cout << "Greater than node and right node not empty" << endl;
                addNode(node->right, inputValue);
                return;
            }

            return;
        }

        void inOrder(Node *node) {
            if(node == 0) {
                return;
            }

            inOrder(node -> left);

            cout << node -> value << " ";

            inOrder(node -> right);
        }
};

int getBTHeight(Node *root) {
    if(root == 0) {
        return 0;
    }

    int leftHeight = getBTHeight(root -> left);
    int rightHeight = getBTHeight(root -> right);

    return 1 + max(leftHeight, rightHeight);
}

int main() {
    int val = 50;
    // cout << "Adding root as " << val << endl;
    BinaryTree binaryTree = BinaryTree();
    Node *root = binaryTree.createBinaryTree(val);
    cout << "Root of tree: " << root -> value << endl << endl;

    val = 20;
    // cout << "Adding item in BT " << val << endl;
    binaryTree.addNode(root, val);
    // cout << endl;

    val = 60;
    // cout << "Adding item in BT " << val << endl;
    binaryTree.addNode(root, val);
    // cout << endl;

    val = 30;
    // cout << "Adding item in BT " << val << endl;
    binaryTree.addNode(root, val);
    // cout << endl;

    val = 70;
    // cout << "Adding item in BT " << val << endl;
    binaryTree.addNode(root, val);
    // cout << endl;

    val = 55;
    // cout << "Adding item in BT " << val << endl;
    binaryTree.addNode(root, val);
    // cout << endl;

    val = 25;
    // cout << "Adding item in BT " << val << endl;
    binaryTree.addNode(root, val);
    // cout << endl;
    
    val=10;
    // cout << "Adding item in BT " << val << endl;
    binaryTree.addNode(root, val);
    // cout << endl;

    cout << "Printing the whole binary tree" << endl;
    binaryTree.inOrder(root);
    cout << endl;

    int heightOfBT = getBTHeight(root);

    cout << "Height Of Binary Tree: " << heightOfBT << endl;

    return 0;
}