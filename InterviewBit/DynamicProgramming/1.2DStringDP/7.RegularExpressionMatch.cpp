/*
mplement wildcard pattern matching with support for ‘?’ and ‘*’ for strings A and B.

’?’ : Matches any single character.
‘*’ : Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Input Format:

The first argument of input contains a string A.
The second argument of input contains a string B.
Output Format:

Return 0 or 1:
    => 0 : If the patterns do not match.
    => 1 : If the patterns match.
Constraints:

1 <= length(A), length(B) <= 9e4
Examples :

Input 1:
    A = "aa"
    B = "a"

Output 1:
    0

Input 2:
    A = "aa"
    B = "aa"

Output 2:
    1

Input 3:
    A = "aaa"
    B = "aa"

Output 3:
    0
    
Input 4:
    A = "aa"
    B = "*"

Output 4:
    1

Input 5:
    A = "aa"
    B = "a*"

Output 5:
    1

Input 6:
    A = "ab"
    B = "?*"

Output 6:
    1

Input 7:
    A = "aab"
    B = "c*a*b"

Output 7:
    0
*/
/*
What a headache!
1. Think of base conditions
    -> if both b and a are empty (pattern matches)
    -> if b is empty by a is not (pattern does not match)
    -> if a is empty but b is not (only matches if every character in b is *) else pattern does not match
2. Cases
    if b == ? -> reduce string and reduce pattern
    if b == *
        -> reduce string and reduce pattern OR
        -> reduce string and don't reduce pattern OR
        -> don't reduce string and reduce pattern (empty match)
    if b != ? && b != *
        -> if equal (reduce string and pattern)
        -> else doesn't match
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

void print2DVector(vector< vector<bool> > arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void print2DVector(vector< vector<char> > arr){
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
    if(root == 0){
        return;
    }
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

class DisjointSet {
    private:
        vector<int> parent;
        vector<int> rank;
        int n;
    public:
        DisjointSet(int N){
            parent.clear();
            rank.clear();
            n = N;
            // parent of i is i
            for(int i=0; i<n; i++){
                parent.push_back(i);
            }
            // rank is 0?
            for(int i=0; i<n; i++){
                rank.push_back(0);
            }
        }

        int find(int i){
            if(parent[i] == i){
                return i;
            }

            else {
                // since parent[i] != i, we find representative of parent[i]
                int result = find(parent[i]);
                
                // Cache value
                parent[i] = result;
                
                return result;
            }
        }

        void getUnion(int i, int j) {
            /*
            1. If the rank of left is less than the rank of right, then it’s best to move left under right, 
            because that won’t change the rank of right (while moving right under left would increase the height). 
            2. In the same way, if the rank of right is less than the rank of left, then we should move right under left.
            3. If the ranks are equal, it doesn’t matter which tree goes under the other, but the rank of the result will 
            always be one greater than the rank of the trees.
            */
            // get root of i
            int irep = find(i);

            // get root of j
            int jrep = find(j);

            // if irep == jrep, we have same root
            if(irep == jrep){
                return;
            }

            // Else, let's get their ranks
            int rankirep = rank[irep];
            int rankjrep = rank[jrep];

            if(rankirep == rankjrep){
                // set anything
                parent[irep] = jrep;
                // put i under j
                // increase rank of j
                rank[jrep]++;
            } else if(rankirep > rankjrep) {
                // we move j under i, and we don't have to increase the rank of i
                parent[jrep] = irep;
            } else {
                // rankjrep > rankirep
                // we move i under j, and we don't have to increase the rank of j
                parent[irep] = jrep;
            }
        }
};

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

bool match(string &a, string &b, int indexA, int indexB, unordered_map<int, int> &table) {
    // if pattern is empty, 
    // empty pattern always matches
    if(indexB < 0 && indexA < 0) {
        return true;
    }

    if(indexB < 0) {
        return false;
    }

    // pattern is non empty, but given string is empty. 
    // this won't match
    // But this will match if b[indexB] == *
    if(indexA < 0) {
        // we have empty string but we are mathcing it with *
        if(b[indexB] == '*'){
            return match(a, b, indexA, indexB - 1, table);
        } else {
            return false;
        }
    }

    int key = indexB + indexA * b.size();
    if(table[key] != 0){
        // cout << "Cache hit" << endl;
        if(table[key] == 1){
            return false;
        }
        if(table[key] == 2){
            return true;
        }
    }

    if(b[indexB] == '?') {
        bool tempResult = match(a, b, indexA - 1, indexB - 1, table);
        if(tempResult){
            table[key] = 2;
        } else {
            table[key] = 1;
        }
        return tempResult;
    }

    if(b[indexB] == '*') {
        // case 1 -> we match any character, and reduce our string
        // case 2 -> we matchh any character, and reduce our string and pattern
        // case 3 -> we match empty character with *, and reduce our pattern
        bool tempResult = match(a, b, indexA-1, indexB, table) || 
                            match(a, b, indexA - 1, indexB - 1, table) ||
                            match(a, b, indexA, indexB - 1, table);
        if(tempResult){
            table[key] = 2;
        } else {
            table[key] = 1;
        }
        return tempResult;
    }

    // b is a character now, and it should match
    if(b[indexB] != '*' && b[indexB] != '?') {
        if(b[indexB] != a[indexA]) {
            return false;
        } else {
            bool tempResult = match(a, b, indexA - 1, indexB - 1, table);
            if(tempResult){
                table[key] = 2;
            } else {
                table[key] = 1;
            }
            return tempResult;
        }
    }

    // nothing matched
    table[key] = 1;
    return false;
}

int solve(string A, string B) {
    int result = 0;
    // let A = row, B = col
    // maxA = A.size()
    // maxB = B.size()
    // index = col + row * maxCol
    // index = indexB + indexA * maxB
    unordered_map<int, int> table;
    string copyA = A;
    string copyB = B;
    bool m = match(copyA, copyB, copyA.size() - 1, copyB.size() - 1, table);

    if(m){
        result = 1;
    } 

    return result;
}

int main(){
    vector<string> a = {
        "aa", "aa", "aaa", "aa", "aa", "ab", "aab", "abbc", "abbcc", "abbbbcccddde", "cc", "acba", "aaaaaaaaaaaaaaaaaaaa",
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "bacb", "cc"
    };
    vector<string> b = {
        "a", "aa", "aa", "*", "a*", "?*", "c*a*b", "a*", "a*c", "a*c*e", "?", "?b*a*ba", "*",
        "a**************************************************************************************", "b**c*?*", "***??"
    };
    vector<string> c = {  "0", "1", "0", "1", "1", "1", "0", "1", "1", "1", "0", "0", "1", "1", "1", "1"};
    cout << "Given input1 strings: " << endl;
    printStrings(a); cout << endl;
    cout << "Given input2 strings: " << endl;
    printStrings(b); cout << endl;
    cout << "Expected output : " << endl;
    for(int i=0; i<c.size(); i++) {
        cout << c[i] << " ";
    }
    cout << endl;

    cout << "Result: " << endl;
    for(int i=0; i<a.size(); i++){
        int result = 0;
        result = solve(a[i], b[i]);
        cout << result << " ";
    }
    cout << endl;
    return 0;
}

// g++ -std=c++11