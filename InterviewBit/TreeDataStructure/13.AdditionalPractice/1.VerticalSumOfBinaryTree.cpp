/*
Problem Description
 
 

You are given the root of a binary tree A.

You have to find the vertical sum of the tree.

A vertical sum denotes an array of sum of the different verticals of a binary tree,

where the leftmost vertical sum is the first element of the array and rightmost vertical is the last.



Problem Constraints
1 <= Number of nodes in the binary tree <= 105
1 <= Ai <= 103


Input Format
The first argument is the root of a binary tree A.


Output Format
Return an array denoting the vertical sum of the binary tree.


Example Input
Input 1:
A =     1
      /   \
     2     3
    / \   / \
   4   5 6   7
Input 2:

A =     1
       /
      2
     /
    3


Example Output
Output 1:
[4, 2, 12, 3, 7]
Output 2:

[3, 2, 1]


Example Explanation
Explanation 1:
The element 4 is present in the leftmost vertical. 
The middle vertical consists of 3 elements 1, 5, 6.
The resultant array is [4, 2, 12, 3, 7].
Explanation 2:

The leftmost vertical is the element 3. The next verticals are 2 and 1.
Hence, the resultant array is [3, 2, 1].
*/
/*
Solution Approach:
Create a map to store elements according to their levels from the left side.
Store the max and min value of the levels as well.
Start from min value to max value, return the sum level wise using the map.
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

void customPreOrder(TreeNode *root, 
                    int currentLevel, 
                    unordered_map<int, vector<int> > &mapping, 
                    int *maxLevel, 
                    int *minLevel){
    if(root == 0){
        return;
    }
    int currentValue = root -> val;
    // store in map
    mapping[currentLevel].push_back(currentValue);
    // calculate max and min
    *minLevel = min(*minLevel, currentLevel);
    *maxLevel = max(*maxLevel, currentLevel);
    customPreOrder(root -> left, currentLevel - 1, mapping, maxLevel, minLevel);
    customPreOrder(root -> right, currentLevel + 1, mapping, maxLevel, minLevel);
}

vector<int> solve(TreeNode *root){
    vector<int> result;

    int currentLevel = 0;
    int maxLevel = INT_MIN;
    int minLevel = INT_MAX;
    unordered_map<int, vector<int> > mapping;
    customPreOrder(root, currentLevel, mapping, &maxLevel, &minLevel);
    // cout << "Min Level is: " << minLevel << endl;
    // cout << "Max Level is: " << maxLevel << endl;
    for(int i=minLevel; i<=maxLevel; i++){
        vector<int> nodes = mapping[i];
        int sumValue = 0;
        if(nodes.size() == 0){
            continue;
        } else {
            for(int j=0; j<nodes.size(); j++){
                sumValue += nodes[j];
            }
            result.push_back(sumValue);
        }
    }

    return result;
}

int main(){
    int rootNode = 3;
    vector<int> a = {1,2,4,5};
    TreeNode *root = createTree(rootNode, a);
    cout << "Given tree is: " << endl;
    inOrder(root); cout << endl;

    vector<int> result = solve(root);
    cout << "Result: " << endl;
    printVector(result);
    return 0;
}

// g++ -std=c++11