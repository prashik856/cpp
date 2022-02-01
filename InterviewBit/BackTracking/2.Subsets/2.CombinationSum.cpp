/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:

All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The combinations themselves must be sorted in ascending order.
CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR … (a1 = b1 AND a2 = b2 AND … ai = bi AND ai+1 > bi+1)
The solution set must not contain duplicate combinations.
Example, 

Given candidate set 2,3,6,7 and target 7,

A solution set is:

[2, 2, 3]
[7]
Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.

Example : itertools.combinations in python.

If you do, we will disqualify your submission retroactively and give you penalty points.
*/
/*
Solution Approach:
This is just 0/1 unlimited knapsack.
No need for dp here.
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


unordered_map<string, int> mapping;
void getSolution(vector<int> &a, 
    int b, 
    int index, 
    vector<int> &temp, 
    int currentSum, 
    vector< vector<int> > &result){
    if(currentSum == b){
        // cout << "Equal" << endl;
        vector<int> tempResult = temp;
        sort(tempResult.begin(), tempResult.end());
        
        // Create key
        string key = "";
        for(int i=0; i<tempResult.size(); i++){
            string val = to_string(tempResult[i]);
            key = key + val;
            key.push_back('-');
        }

        if(mapping.find(key) == mapping.end()){
            result.push_back(tempResult);
            mapping[key] = 1;
        }
        return;
    }

    if(currentSum > b){
        return;
    }

    if(index < 0){
        return;
    }

    // cannot include
    if(a[index] > b){
        getSolution(a, b, index - 1, temp, currentSum, result);
    }
    // choice
    else {
        // don't include
        getSolution(a, b, index - 1, temp, currentSum, result);
        // include
        currentSum += a[index];
        temp.push_back(a[index]);
        getSolution(a, b, index, temp, currentSum, result);
        
        // back track
        currentSum -= a[index];
        temp.pop_back();
    }
}

vector< vector<int> > solve(vector<int> a, int b){
    vector< vector<int> > result;

    mapping.clear();
    int index = a.size() - 1;
    vector<int> temp;
    int currentSum = 0;
    getSolution(a, b, index, temp, currentSum, result);
    sort(result.begin(), result.end());
    return result;
}

int main(){
    vector<int> a = {8, 10, 6, 11, 1, 16, 8};
    int b = 28;
    cout << "Given array is: " << endl;
    printVector(a);
    cout << "Given target is: " << b << endl;

    vector< vector<int> > result = solve(a, b);
    print2DVector(result);
    return 0;
}

// g++ -std=c++11