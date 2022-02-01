/*
Problem Description
 
 

You are given the root of a binary tree A, you need to return the absolute difference between sum of all covered elements and the sum of all uncovered elements.

In a binary tree, a node is called Uncovered if it appears either on left boundary or right boundary. Rest of the nodes are called covered.



Problem Constraints
1 <= Number of nodes in the binary tree <= 105


Input Format
The first argument is the root of the binary tree A.


Output Format
Return a single integer denoting the absolute difference of the sum of covered and uncovered nodes.


Example Input
Input 1:
    2
   / \
  1   4
 /   / \
6  10   5
Input 2:

      1
     /
    2
   /
  3


Example Output
Output 1:
8
Output 2:

6


Example Explanation
Explanation 1:
The node with value 10 is the only covered node. All other nodes are uncovered.
Therefore, the absolute difference is |(10) - (2 + 1 + 4 + 6 + 5)| = 8
Explanation 2:

All the given nodes are uncovered. Hence, the answer is sum of given nodes - 6.
*/
/*
Solution Approach:
Only doubt I have is what are covered and uncovered nodes. 
Other than that, this problem is easy.
This is working.
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

long solve(TreeNode *A){
  long result = 0;
  long totalSum = 0;
  long borderSum = 0;
  queue<TreeNode *> parent;
  queue<TreeNode *> child;
  parent.push(A);

  while(!parent.empty()){
    // Add to borderSum 
    if(parent.size() == 1){
      borderSum += (parent.front() -> val);
    } else {
      borderSum += (parent.front() -> val);
      borderSum += (parent.back() -> val);
    }

    // total sum
    while(!parent.empty()){
      TreeNode *node = parent.front();
      parent.pop();
      totalSum += (node -> val);
      if(node -> left != 0){
        child.push(node -> left);
      }
      if(node -> right != 0){
        child.push(node -> right);
      }
    }

    while(!child.empty()){
      TreeNode *node = child.front();
      child.pop();
      parent.push(node);
    }
  }
  long coveredNodesSum = totalSum - borderSum;
  result = abs(coveredNodesSum - borderSum);
  return result;
}

int main(){
    vector<int> a = {1,2,3,4,5};
    return 0;
}

// g++ -std=c++11