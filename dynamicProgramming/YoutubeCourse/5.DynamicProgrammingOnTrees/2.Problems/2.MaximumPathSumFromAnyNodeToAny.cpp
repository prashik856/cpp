/*
Maximum Path Sum from Any Node to Any

Flow:
-> Problem Statement
-> Format Discussion
-> code variation

We need to find a path in the BT where the sum of that path is maximum.
We need to remember that the number can be negatives too.
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

long solve(Node *root, long *result) {
    // BC
    if(root == 0) {
        return 0;
    }
    

    // Hypothesis
    long left = solve(root -> left, result);
    long right = solve(root -> right, result);

    // cout << "For Node: " << root -> data << endl;
    // cout << "Left Value: " << left << endl;
    // cout << "Right Value: " << right << endl;

    // Induction
    // We need to return this tempAns
    // In temp, what if the return value is negative?
    // if max(left, right) is negative and root->data is positive, it does not make sense to add max(left,right) to root -> data
    long tempAns = max(
        root -> data + max(left, right),
        (long) root -> data
    );

    // Check if this is the max Value
    long ans = max(
        root -> data + left + right,
        tempAns
    );
    // cout << "Answer Value: " << ans << endl;

    *result = max(*result, ans);
    // cout << "Result Value: " << *result << endl;

    // Return maxSum Path
    // cout << "Return Value: " << tempAns << endl;
    // cout << endl;
    return tempAns;
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