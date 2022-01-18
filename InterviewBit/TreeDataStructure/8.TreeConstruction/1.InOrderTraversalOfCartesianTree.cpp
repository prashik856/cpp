/*
Given an inorder traversal of a cartesian tree, construct the tree.

Cartesian tree :  is a heap ordered binary tree, where the root is greater than all the elements in the subtree.

Note: You may assume that duplicates do not exist in the tree.

Example :

Input : [1 2 3]

Return :   
          3
         /
        2
       /
      1
*/
/*
Solution Approach:
Since the question is quite vague, this might help.

Find the max value, make it as root.
root.left will be the max element in the remaining array left side of root’s index.
root.left will be the max element in the remaining array right side of root’s index.

Let's create a recursive function for this:
Done.
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

TreeNode* customCreateTree(vector<int> a, int low, int high){
    // base case, if low < high
    if(low > high){
        return 0;
    }

    // base case if high >= a.size()
    if(high >= a.size()){
        return 0;
    }

    // base case if low < 0
    if(low < 0){
        return 0;
    }

    // if low == high
    if(low == high){
        TreeNode *newNode = new TreeNode(a[low]);
        return newNode;
    }

    int maxValue = INT_MIN;
    int maxIndex = 0;
    for(int i=low; i<=high; i++){
        if(a[i] > maxValue){
            maxValue = a[i];
            maxIndex = i;
        }
    }

    TreeNode *newNode = new TreeNode(maxValue);
    cout << "Max value is: " << maxValue << endl;
    int mid = maxIndex;
    newNode -> left = customCreateTree(a, low, mid - 1);
    newNode -> right = customCreateTree(a, mid + 1, high);
    return newNode;
}

TreeNode *solve(vector<int> a){
    TreeNode *root;

    int low = 0;
    int high = a.size() - 1;
    root = customCreateTree(a, low, high);

    return root;
}

int main(){
    vector<int> a = {1,2,3};
    cout << "Given array is: " << endl;
    printVector(a);

    TreeNode *result = solve(a);
    cout << "Result: " << endl;
    inOrder(result); cout << endl;
    return 0;
}

// g++ -std=c++11