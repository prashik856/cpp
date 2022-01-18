/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note: You may assume that duplicates do not exist in the tree.

Example :

Input :
        Preorder : [1, 2, 3]
        Inorder  : [2, 1, 3]

Return :
            1
           / \
          2   3
*/
/*
Solution Approach:
Same goes for this dickhead, with pointers it got accepted. 
But without pointers, it got rejected.

fuck IB!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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
TreeNode* solve2(vector<int> a, vector<int> b, int ilow, int ihigh){
    static int pindex = 0;
    if(ilow < 0){
        // cout << "Low is less than 0" << endl;
        return 0;
    }

    if(ihigh >= a.size()){
        // cout << "high is greater than N" << endl;
        return 0;
    }

    if(ilow > ihigh){
        // cout << "ilow is greater than ihigh" << endl;
        return 0;
    }

    // cout << "Given ilow is: " << ilow << endl;
    // cout << "Given ihigh is: " << ihigh << endl;
    // cout << "Given pindex is: " << *pindex << endl;
    // cout << "Pre order value is: " << a[*pindex] << endl;
    int rootValue = a[pindex];
    pindex = pindex + 1;
    TreeNode* node = new TreeNode(rootValue);
    if(ilow == ihigh){
        return node;
    }
    // for left and right
    int index = mapping[rootValue] - 1;
    int leftSubTree = index - ilow;
    int rightSubTree = ihigh - index;
    // cout << "Left subtree length: " << leftSubTree << endl;
    // cout << "Right subtree length: " << rightSubTree << endl;
    // cout << endl;
    // calculate left and right

    // cout << "Going to different subtrees: " << endl;
    node -> left = solve2(a, b, ilow, index - 1);
    node -> right = solve2(a, b, index + 1, ihigh);

    return node;
}

TreeNode *solve(vector<int> a, vector<int> b){
    TreeNode *root = 0;
    mapping.clear();
    // pindex = 0;
    for(int i=0; i<b.size(); i++){
        mapping[b[i]] = i+1;
    }
    int ilow = 0;
    int ihigh = a.size() - 1;
    root = solve2(a, b, ilow, ihigh);

    return root;
}

int main(){
    // int rootNode = 10;
    // vector<int> a = {5, 15, 4, 6, 14, 16};
    // TreeNode *root = createTree(rootNode, a);
    // cout << "Given Tree is:" << endl;
    // inOrder(root); cout << endl;
    // preOrder(root); cout << endl;

    TreeNode* result = solve({1, 2, 3, 4, 5}, {3, 2, 4, 1, 5});
    cout << "Result:" << endl;
    cout << "Inorder" << endl; inOrder(result); cout << endl;
    cout << "Preorder" << endl; preOrder(result); cout << endl;
    cout << "Postorder" << endl; postOrder(result); cout << endl;
    return 0;
}

// g++ -std=c++11