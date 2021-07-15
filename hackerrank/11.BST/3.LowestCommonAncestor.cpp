// Problem: https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=trees
// Intuition: https://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/
// Find common path, and break where the path differs
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

    void findPath(Node *root, int node, vector<Node*> &path, bool *foundNode) {
        
        if(*foundNode){
            return;
        }
        
        if(root == 0){
            return;
        }
        
        path.push_back(root);
        if(node == root -> data){
            *foundNode = true;
            return;
        }
        
        // If node found on from this node
        // This node will be included in the path
        
        findPath(root -> left, node, path, foundNode);
        findPath(root -> right, node, path, foundNode);
        
        if(!*foundNode){
            path.pop_back();
        }
    }
  
    Node *lca(Node *root, int v1,int v2) {
		// Write your code here.
        Node *result;
        
        vector<Node*> path1;
        vector<Node*> path2;
        
        bool foundNode1 = false;
        findPath(root, v1, path1, &foundNode1);
        
        bool foundNode2 = false;
        findPath(root, v2, path2, &foundNode2);
        
        // cout << "Path to " << v1 << " :" << endl;
        // for(int i=0; i<path1.size(); i++){
        //     cout << path1[i] -> data << " ";
        // }
        // cout << endl;
        
        // cout << "Path to " << v2 << " :" << endl;
        // for(int i=0; i<path2.size(); i++){
        //     cout << path2[i] -> data << " ";
        // }
        // cout << endl;
        
        bool foundAnswer = false;
        int index = 0;
        while(!foundAnswer){
            if(path1[index] == path2[index]){
                index++;
                continue;
            }
            else {
                //found our node
                result = path1[index - 1];
                break;
            }
        }
        
        
        return result;
    }

}; //End of Solution