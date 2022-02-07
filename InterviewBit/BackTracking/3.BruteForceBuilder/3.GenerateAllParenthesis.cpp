/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
Make sure the returned list of strings are sorted.
*/
/*
Solution Approach:
To get all permutations of a string:
https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

To get balanced parentheses:
https://www.geeksforgeeks.org/print-all-combinations-of-balanced-parentheses/

Approach: 
To form all the sequences of balanced bracket subsequences with n pairs. 
So there are n opening brackets and n closing brackets. 
So the subsequence will be of length 2*n. 
There is a simple idea, the i’th character can be ‘{‘ if and only if the count of ‘{‘ till i’th is less than n 
and i’th character can be ‘}’ if and only if the count of ‘{‘ is greater than the count of ‘}’ till index i. 
If these two cases are followed then the resulting subsequence will always be balanced. 
So form the recursive function using the above two cases.

Algorithm:  
-> Create a recursive function that accepts a string (s), count of opening brackets (o) and count of closing brackets (c) 
and the value of n.
-> if the value of opening bracket and closing bracket is equal to n then print the string and return.
-> If the count of opening bracket is greater than count of closing bracket then call the function recursively with 
the following parameters String s + “}”, count of opening bracket o, count of closing bracket c + 1, and n.
-> If the count of opening bracket is less than n then call the function recursively with the following parameters 
String s + “{“, count of opening bracket o + 1, count of closing bracket c, and n.

Cooooool
Need to call in two recursion functions.
1. if countOpen < n -> put (, and call the recusive function
2. if countOpen < countClose -> put ), and call the recursive function.
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

void getResult(string s, vector<string> &result, int countOpen, int countClose, int n){
    // cout << "Given string is: " << s << endl;
    // cout << "Count Open: " << countOpen << endl;
    // cout << "Count Close: " << countClose << endl;

    if(countOpen == countClose && countOpen == n && countClose == n){
        // cout << s << endl;
        result.push_back(s);
        return;
    }

    if(countOpen < n){
        s.push_back('(');
        getResult(s, result, countOpen + 1, countClose, n);
        s.pop_back();
    }

    if(countOpen > countClose){
        s.push_back(')');
        getResult(s, result, countOpen, countClose + 1, n);
        s.pop_back();
    }
}

vector<string> solve(int a){
    vector<string> result;

    string temp = "";
    int countOpen = 0;
    int countClose = 0;
    getResult(temp, result, countOpen, countClose, a);
    sort(result.begin(), result.end());
    return result;
}

int main(){
    int n = 1;
    cout << "Given input n : " << n << endl;

    vector<string> result = solve(n);
    cout << "Result: " << endl;
    printStrings(result);
    return 0;
}

// g++ -std=c++11