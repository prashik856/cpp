/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



The digit 0 maps to 0 itself.

The digit 1 maps to 1 itself.

Input: Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Make sure the returned strings are lexicographically sorted.
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

unordered_map<string, char> mapping;
void getResult(string a, vector<int> indices, vector<string> &result){
    printVector(indices);
    string temp = "";
    for(int i=0; i<a.size(); i++){
        string key = "";
        key.push_back(a[i]);
        key.push_back('-');
        string indexString = to_string(indices[i]);
        key = key + indexString;
        // cout << "Key: " << key << endl;
        if(mapping.find(key) == mapping.end()){
            return;
        } else {
            temp.push_back(mapping[key]);
        }
    }
    // put it in the result
    result.push_back(temp);

    // all combinations
    int count = 0;
    while(count < 4){
        for(int i=0; i<indices.size(); i++){
            indices[i]++;
            getResult(a, indices, result);
        }
        count++;
    }
    
}

vector<string> solve(string a){
    vector<string> result;
    int n = a.size();
    
    // initialize
    vector<int> indices(n, 0);
    mapping.clear();

    // initialize mapping
    mapping["1-0"] = '1';
    mapping["0-0"] = '0';
    mapping["2-0"] = 'a';
    mapping["2-1"] = 'b';
    mapping["2-2"] = 'c';
    mapping["3-0"] = 'd';
    mapping["3-1"] = 'e';
    mapping["3-2"] = 'f';
    mapping["4-0"] = 'g';
    mapping["4-1"] = 'h';
    mapping["4-2"] = 'i';
    mapping["5-0"] = 'j';
    mapping["5-1"] = 'k';
    mapping["5-2"] = 'l';
    mapping["6-0"] = 'm';
    mapping["6-1"] = 'n';
    mapping["6-2"] = 'o';
    mapping["7-0"] = 'p';
    mapping["7-1"] = 'q';
    mapping["7-2"] = 'r';
    mapping["7-3"] = 's';
    mapping["8-0"] = 't';
    mapping["8-1"] = 'u';
    mapping["8-2"] = 'v';
    mapping["9-0"] = 'w';
    mapping["9-1"] = 'x';
    mapping["9-2"] = 'y';
    mapping["9-3"] = 'z';

    string temp = "";
    getResult(a, indices, result);
    return result;
}

int main(){
    string a = "12340";
    cout << "Given input array is: " << a << endl;

    vector<string> result = solve(a);
    cout << "Result: " << endl;
    printStrings(result);
}

// g++ -std=c++11