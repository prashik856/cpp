// Problem: https://www.hackerrank.com/challenges/ctci-is-binary-search-tree/problem
// Intuition: Inorder search in BST should give us a sorted array
// Take care that every element should be distinct
/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
    struct Node {
        int data;
        Node* left;
        Node* right;
    }
*/
    void solve(Node *root, vector<Node*> &path){   
        // current root is empty
        if(root == 0){
            return;
        }
        
        solve(root -> left, path);
        path.push_back(root);
        // cout << "Current Array is: " << endl;
        // for(int i=0; i<path.size(); i++){
        //     cout << path[i] -> data << " ";
        // }
        // cout << endl;
        solve(root -> right, path);
        
    }    

    bool checkBST(Node* root) {
        bool result = true;
        vector<Node*> path;
        solve(root, path);
        // Check if path is sorted
        for(int i=1; i<path.size(); i++){
            if(path[i-1]->data >= path[i]->data){
                result = false;
                break;
            }
        }
        return result;
    }