// problem: https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=trees
// Intuition: Just DFS
#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    void DFS(Node *root, int currentHeight, int *result){
        // if current node is null
        if(root == 0){
            return;
        }
        *result = max(*result, currentHeight);
        DFS(root -> left, currentHeight + 1, result);
        DFS(root -> right, currentHeight + 1, result);
    }
    
    int height(Node* root) {
        // Write your code here.
        int result = 0;
        int currentHeight = 0;
        DFS(root, currentHeight, &result);
        return result;
    }

}; //End of Solution