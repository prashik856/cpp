/*
Given a string s, partition s such that every string of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",

Return

  [
    ["a","a","b"]
    ["aa","b"],
  ]
Ordering the results in the answer :

Entry i will come before Entry j if :

len(Entryi[0]) < len(Entryj[0]) OR
(len(Entryi[0]) == len(Entryj[0]) AND len(Entryi[1]) < len(Entryj[1])) OR
*
*
*
(len(Entryi[0]) == len(Entryj[0]) AND … len(Entryi[k] < len(Entryj[k]))
In the given example,

   ["a", "a", "b"] comes before ["aa", "b"] because len("a") < len("aa")
*/
/*
Solution Approach:
Generate all Palindrome Partitioning:
https://www.geeksforgeeks.org/given-a-string-print-all-possible-palindromic-partition/?ref=lbp
Given a string, find all possible palindromic partitions of given string.
Let's write a code first to generate all partitions.
If we remove the if(isPalindrome) conditions, we can get the all combinations of substrings of the string.
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

void print2DStrings(vector< vector<string> > arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
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

bool isPalindrome(string a, int start, int end){
    while(start < end){
        if(a[start] != a[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void getResult(string &a, vector<string> &temp, int start, int end, vector< vector<string> > &result){
    if(start > end){
        // cout << "Got result" << endl;
        vector<string> tempResult = temp;
        // printStrings(tempResult);
        result.push_back(tempResult);
        return;
    }

    // cout << "Given start: " << start << endl;
    // cout << "Given end: " << end << endl;
    // cout << "Given temp: " << endl;
    // printStrings(temp); 

    for(int i=start; i<=end; i++){
        // we only move ahead if start to i substring is palindrome
        if(isPalindrome(a, start, i)){
            // Create substring
            string subString = "";
            for(int j=start; j<=i; j++){
                subString.push_back(a[j]);
            }
            // cout << "Substring is: " << subString << endl;

            // insert into solution
            // cout << "Inserting" << endl;
            temp.push_back(subString);

            // call recursion
            // cout << "Calling recursion" << endl;
            getResult(a, temp, i+1, end, result);

            // backtrack
            // cout << "Backtrack" << endl;
            // cout << "Temp size: " << temp.size() << endl;
            // cout << "Start: " << start << endl;
            // cout << "End: " << end << endl;
            // cout << "i: " << i << endl;
            temp.pop_back();
        }
    }

    return;
}

vector< vector<string> > solve(string a){
    vector< vector<string> > result;

    // temporary array to store results
    vector<string> temp;
    int start = 0;
    int end = a.size() - 1;
    getResult(a, temp,start,end,result);
    // cout << "Here" << endl;
    return result;
}

int main(){
    string a = "abba";
    cout << "Given string is: " << a << endl;

    vector< vector<string> > result = solve(a);
    cout << "Result: " << endl;
    print2DStrings(result);
    return 0;
}

// g++ -std=c++11