/*
Problem Description

Given two integer array A and B, you have to pick one element from each array such that their xor is maximum.

Return this maximum xor value.



Problem Constraints
1 <= |A|, |B| <= 105

1 <= A[i], B[i] <= 109



Input Format
First argument is an integer array A.

Second argument is an integer array B.



Output Format
Return an integer denoting the maximum xor value as described in the question.



Example Input
Input 1:

 A = [1, 2, 3]
 B = [4, 1, 2]


Example Output
Output 1:

 7


Example Explanation
Explanation 1:

 Pick A[2] and B[0] because their xor value is maximum. 3 ^ 4 = 7
*/
/*
We first need to represent every number by it's binary representation.
Let's start with this first.
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
}

void printStrings(vector<string> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << endl;
    }
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

vector<int> getBinaryForm(int a){
    vector<int> binary(32, 0);
    int index = 31;
    while(a > 0){
        if(a & 1){
            //last bit set
            binary[index] = 1;
        }
        index--;
        a = a / 2;
    }
    return binary;
}

int solve(vector<int> a, vector<int> b){
    int result = 0;

    int n = a.size();
    int m = b.size();
    vector< vector<int> > binaryA(n, vector<int>(32, 0));
    vector< vector<int> > binaryB(m, vector<int>(32, 0));

    // cout << "For A" << endl;
    for(int i=0; i<a.size(); i++){
        int val = a[i];
        vector<int> temp = getBinaryForm(val);
        binaryA[i] = temp;
        // printVector(temp);
    }

    // cout << "For B" << endl;
    // Reversing all bits
    for(int i=0; i<b.size(); i++){
        int val = b[i];
        val = val ^ INT_MAX;
        vector<int> temp = getBinaryForm(val);
        binaryB[i] = temp;
        // printVector(temp);
    }

    int rootValue = 0;
    TreeNode *rootA = new TreeNode(0);

    // Creation of Trie
    for(int i=0; i<n; i++){
        TreeNode *currentNode = rootA;
        for(int j=31; j>=0; j--){
            int val = binaryA[i][j];
            TreeNode *node = new TreeNode(val);
            // if value is 0
            if(val == 0){
                if(currentNode -> left == 0){
                    // insert
                    currentNode -> left = node;
                    currentNode = node;
                } else {
                    // already present
                    currentNode = node;
                }
            } 
            // if value is 1
            else {
                if(currentNode -> right == 0){
                    // insert
                    currentNode -> right = node;
                    currentNode = node;
                } else {
                    // already present
                    currentNode = node;
                }
            }
        }
    }
    // cout << "Trie created is: " << endl;
    // inOrder(rootA);
    // cout << endl;
    long tempResult = 0;
    for(int i=0; i<m; i++){
        TreeNode *currentNode = rootA;
        int powerValue = 0;
        for(int j=31; j>=0; j--){
            int val = binaryB[i][j];

            if(val == 0){
                // 0
            } else {
                // 1
            }
            powerValue++;
        }
    }

    return result;
}

int main(){
    vector<int> a = {1, 2, 3};
    vector<int> b = {4, 1, 2};
    cout << "Given arrays are: " << endl;
    printVector(a);
    printVector(b);

    int result = solve(a, b);
    cout << "Result: " << result << endl;
    return 0;
}

// g++ -std=c++11