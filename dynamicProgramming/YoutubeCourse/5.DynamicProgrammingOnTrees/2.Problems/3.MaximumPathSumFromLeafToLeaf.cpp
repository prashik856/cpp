/*
Maximum Path sum from leaf to leaf

flow: 
Problem statement
Break down 
code variation


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

class BinaryTree {
    public:
        Node *root;
        BinaryTree(){
            root = 0;
        }

        void insert(int value) {
            Node *node = new Node(value);
            if(root == 0){
                root = node;
            }

            else {
                Node *temp = root;
                bool flag = true;
                while(flag) {
                    if(value > temp -> data) {
                        if(temp -> right == 0) {
                            temp -> right = node;
                            flag = false;
                        } else {
                            temp = temp -> right;
                        }
                    } else {
                        if(temp -> left == 0){
                            temp -> left = node;
                            flag = false;
                        } else {
                            temp = temp -> left;
                        }
                    }
                }
            }
        }

        void preTraversal(Node *node) {
            if(node == 0){
                return;
            }

            preTraversal(node -> left);
            cout << node -> data << " ";
            preTraversal(node -> right);
        }
};

long solve(Node *root, long *result){
    if(root == 0) {
        return 0;
    }

    long left = solve(root -> left, result);
    long right = solve(root -> right, result);

    // Induction
    // Get max path from left or right
    long tempAnswer = root -> data + max(left, right);
    // check if we take this node as root, we get max sum
    long ans = max(tempAnswer, root -> data + left + right);

    // calculate result
    *result = max(*result, ans);

    return tempAnswer;
}


int main(){
        int maxSize = 10000;
    int maxValue = 1000000000;
    BinaryTree *bt = new BinaryTree();
    // cout << "Given Input is: " << endl;
    for(int i=0; i<maxSize; i++) {
        int value = rand() % maxValue;
        bool positive = true;
        if(value % 2 == 1) {
            positive = false;
        }

        if(!positive) {
            value = 0 - value;
        } 

        // cout << value << " ";
        bt -> insert(value);
    }
    // cout << endl;

    // cout << "Given input sorted is: " << endl;
    // bt -> preTraversal(bt -> root);
    // cout << endl;

    long result = -9999999999999;
    solve(bt -> root, &result);

    cout << "Maximum Sum Path is: " << endl;
    cout << result << endl;
    return 0;
}