/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.

'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:

int isMatch(const char *s, const char *p)
Some examples:

isMatch("aa","a") → 0
isMatch("aa","aa") → 1
isMatch("aaa","aa") → 0
isMatch("aa", "a*") → 1
isMatch("aa", ".*") → 1
isMatch("ab", ".*") → 1
isMatch("aab", "c*a*b") → 1
Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/
/*
Solution approach:
wtf is up with hard limit here!
b = 3262
a = 
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
            int tempResult = match(a, b, indexA, indexB - 1, table);
            return tempResult;
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

    if(b[indexB] == '.') {
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
    if(b[indexB] != '*' && b[indexB] != '.') {
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

bool solve2(string &A, string &B, int indexA, int indexB, unordered_map<int, int> &table) {
    // empty pattern matches empty pattern
    if(indexA >= A.size() && indexB >= B.size()) {
        return true;
    }

    // empty pattern
    if(indexB >= B.size()) {
        return false;
    }

    int key = indexB + indexA * B.size();
    if(table[key] != 0){
        // cout << "Cache hit" << endl;
        if(table[key] == 1){
            return true;
        } else {
            return false;
        }
    }

    // empty string and non empty pattern
    if(indexA >= A.size()) {
        bool tempResult = solve2(A, B, indexA, indexB + 2, table);
        if(tempResult){
            table[key] = 1;
        } else {
            table[key] = 2;
        }
        return tempResult;
        // if(B[indexB] != '.' && B[indexB] != '*') {

        //     // b is a character
        //     if(indexB + 1 < B.size()) {
        //         // matching null
        //         if(B[indexB + 1] == '*') {
        //             bool tempResult = solve2(A, B, indexA, indexB + 2, table);
        //             if(tempResult) {
        //                 table[key] = 1;
        //             } else {
        //                 table[key] = 2;
        //             }
        //             return tempResult;
        //         } else {
        //             // won't match null
        //             return false;
        //         }
        //     } else {
        //         // last character in B, and it is a character
        //         return false;
        //     }
        // }
        // if(B[indexB] == '.' && indexB + 1 == B.size()) {
        //     // b is . and it ends there
        //     return false;
        // }
        // if(B[indexB] == '.' && indexB + 1 < B.size()){
        //     // b and b + 1 is ".*" which mathces empty string
        //     if(B[indexB + 1] == '*') {
        //         // match forward
        //         bool tempResult = solve2(A, B, indexA, indexB + 2, table);
        //         if(tempResult) {
        //                 table[key] = 1;
        //             } else {
        //                 table[key] = 2;
        //             }
        //         return tempResult;
        //     } else {
        //         // Since a is empty, only .* is allowed
        //         // Everything else .a, or .. is not allowed
        //         return false;
        //     }
        // }
    }
    
    if(B[indexB] == '.') {
        // b is .c or .*
        if(indexB + 1 < B.size()) {
            if(B[indexB + 1] == '*') {
                bool tempResult = solve2(A, B, indexA + 1, indexB, table) || 
                        solve2(A, B, indexA + 1, indexB + 2, table) || 
                        solve2(A, B, indexA, indexB + 2, table);
                if(tempResult) {
                        table[key] = 1;
                    } else {
                        table[key] = 2;
                    }
                return tempResult;
            }
            if(B[indexB + 1] != '*') {
                // ignore current character
                bool tempResult = solve2(A, B, indexA + 1, indexB + 1, table);
                if(tempResult) {
                        table[key] = 1;
                    } else {
                        table[key] = 2;
                    }
                return tempResult;
            }
        } else {
            // this is last char in b
            bool tempResult = solve2(A, B, indexA + 1, indexB + 1, table);
            if(tempResult) {
                        table[key] = 1;
                    } else {
                        table[key] = 2;
                    }
            return tempResult;
        }
    }

    if(B[indexB] == '*') {
        // invalid
        return false;
    }

    if(B[indexB] != '.' && B[indexB] != '*') {
        // b is a. or a*
        if(indexB + 1 < B.size()) {
            if(B[indexB + 1] == '*') {
                // skip. match with null
                bool result1 = solve2(A, B, indexA, indexB + 2, table);
                bool result2 = false;
                // match with equal
                if(B[indexB] == A[indexA]) {
                    result2 = solve2(A, B, indexA + 1, indexB, table);
                }
                // return or
                bool tempResult = result1 || result2;
                if(tempResult) {
                        table[key] = 1;
                    } else {
                        table[key] = 2;
                    }
                return tempResult;
            } else {
                // should be equal
                if(B[indexB] == A[indexA]) {
                    bool tempResult = solve2(A, B, indexA + 1, indexB + 1, table);
                    if(tempResult) {
                        table[key] = 1;
                    } else {
                        table[key] = 2;
                    }
                    return tempResult;
                } else {
                    // not equal, return false
                    return false;
                }
            }
        } else {
            // this is last char in b
            if(B[indexB] != A[indexA]) {
                return false;
            } else {
                // character matches
                bool tempResult = solve2(A, B, indexA + 1, indexB + 1, table);
                if(tempResult) {
                        table[key] = 1;
                    } else {
                        table[key] = 2;
                    }
                return tempResult;
            }
        }
    }

    return false;
}

int solve(const string A, const string B) {
    string cA = A;
    string cB = B;
    int result = 0;
    unordered_map<int, int> table;
    bool m = solve2(cA, cB, 0, 0, table);
    if(m) {
        result = 1;
    }
    return result;
}

int main(){
    vector<string> a = {
        "aa", "aa", "aaa", "aa", "aa", "aa", "ab", "aab", "", "abbc",
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
    };
    vector<string> b = {
        "a", "aa", "aa", "*", "a*", ".*", ".*", "c*a*b", ".*", "ab*bbc", "a*aa....a*aa*a*.aaaa..aa*aa*a.a*.a.a*a*a.a*.a*.aa*.a.a..a.a*aaa*.aaa..a*a*.a..a*..aa*a*a*a*a.a*a*a..aaa.a*.a*a.a*.a*a*..aaa*.a*a*a.a*.aa*a*a*.a..a*a*a*.a*a*.aa*.a*a..aaa*a*a.aaaa..aa....a*a*.a*a..a*.a*a*aaa*a*.a*..a*aaa.aaaa*.a*a..a*aa.a*aa*a*a*...aa*a*a*.....a*.a.a*a...aa*.aa*a..a*aaaa*aa*.aa*a.a*a.a*aa.aa..aaa.a.aaa*aa*aa*a.a*a*aa*a*a*a..aaa*a*.a*.a*a*.aaa*...a.a*a.a*a*a*.a*a*aaa*a*a*a*a..a.a*a*a*a*.a*.aa*a.a*aa.aaa*a..a*aa*..a.aa.aaaa*a*aa*.aa.a*a*aa*a*a.a*a.a*aaaa*.a..aaaa.a*a.aa*a*a*a*aaa*a*aa*a.a*aa*..aaaa*a*aaa*..aa.a*a*.a.aa*aa.aa*aa*aaa*aa*a*..a.a*aa*a*aa*aa...a*a*.aaa*a.a.a*a*aa*aaaa*a*aaa*a*aa.aa*a*aaa*.a*a*.a*a*a*a*a.a*aaa*a.aa*a*.a*.aaa.a*a*aa*a*..a*aaa*...a*..a*a*a*a..aa*aaa*a*a*aaaaa.a*a*..aa.a*.a*aaa.aa.a*a*a*a*a*aa*a*a*a*a*a*a*a*aaa..aa.a*aa*.a*a*a*aa*a....aa.a*a*aaa..aa*..aa.a.aa*..a*..a*a*..a*.a.aa*.aa...aaa*a*a*.a*aaa*a..aa*..a*aaa.aa*aaaa*.a.a*a*a..a*aa*a*aa*.a..a*a.aa*.aaa*aaa*.....a*a*aaa...a*.aa*a*.aaaaa*..a*a.aa*a.a..aaaaa*a.a*a*a*..aa..aaa*a*aaaaaaa*aaaa*.a..a.a.a......aa*a*.a.a*.aaa*a*aa*.a..a*.aa...a*a*a*a*aaaa*a*aa*a*a*a*aaa*a*a*.a*...a*.aa*a*a*.a*a*.....a.a.a*.a*.a*..a*a*a*aaaa.aa.a*a*..a*.a*a.a*a*a*aaa*a..aaa*a..a*aa..a*a.aa*a*a*..a*..a*a*...a*.aa.aaaa*aa*a*a*.a*aa.a*aa*aa*aa*.a*.a.aaa*a*aaa*aa*.aaa*a*a.a*.a*aa*a*a*...a*..aa*a*aaa*a...aa.a.aa..aaa*.aa*.a.a*aa*.aa.a*a*a*aa*aa*a*a*a*a*a*..aa*.a*aa*aa*aa*a*.a....a*aa*a.a.a*aa*aaa..aa*aaa.a*a*aa*a*a*a*aaa.a*aa..a*.aaa*a*aa*.aaa.a*..a*a.a.a*a*aa*aaa*a*aa...a*..a*.aa*a*aa..aa.aaaa*aaaa*.a.a*aaa*.a*a*a*aa*a*aa.a*a*aaaa.aa*a.a*.aaa*a.aa*a.a*.aaaa*aa*a...a*a*a.aa*a*..a*.aa*.a*aa*..a*a*a*a.aa*...aaaaa*aaa*a*.aa*aa*.a.a*.aaa*a*a*.a*.aa.aaaa*aa*.aa*.aa*a*..a*aa*a*.aa*.aa.a.aa*.aaa*.a.a*a*.aaaa*a.a.a*a*..aa.a*a*aa*.a*aa..a*a*.aaaa*a..a*a*a*.a.a*a*a*.a*..a*.a*a*a*a*.a*.a...a*....a*a*a.a*aa.a*.a*.aa*aa*.aa*..aa*....aaa*a*a.aa*aa*.a*a*a*a*..a.a*a.a*.a*a.a...aa.a*...a.a*a*a.aa*....aa.a.aa*a*.aa.aaaaaaa...a..a*a*aa*aa*aa.a..a*..aa*a*a..a*aa.aaaa*a.a*.aa.a*.a*a..a*..a*a*.aa*a*aa.a*a.aaa*a*a*aa*aa.aaa.a*.aaa....a*a*a*....aa*a*a*a*aa*a...aaa*.aa*a*a*aaa*a.a..a.aaaa*aa*aa*a.aa*aa*a*a*a*a.aa*.a*aa...a*a*aa*..a*a*..a*a*.a.a*a*.aa*a*a*..a*..a*a*a*a*a*aa*aa.a*.a.aa*a*.a..aaaaa.a.a*a*.a*.aa..aaa.a*a*a*aaaa*a*a*..a*aa*a.aa*a*aaaaaa*a.a*.a.a*..a*.a*a*aa..a.a*aaa..a*a.aa.aa*a....a*aa..a*a..a.a*aa*...aa*.a*..a*a*aa*.aa*.a.a...a*.a*...a*.aaa.a*a*.a*a*aa*.aaaa.a*a*a*..a*a*.a.a*aa*a.a.a*a*a.aa*a.aa...a*a*aa.a*aa.a*a*aaa*.a..a*....aa*.a*a.a*.aa.a*a*a*aa..a*.a*.a*aaaa*a..a*a*a*a.a*.aaaaaa*.aa.a*aa.a*aa.a.aa*.a.a*.a*a*.aa*.a...a.aa..a*aaa*..a*a*a*a*.aa*.a*aaaa*a..a*a.aa*aaa*aaaa.a*.aa*aa.a*....a*..aa*.a.a*.a*..aa*a.a*a.a...a*...a*a*aa*a*a*a.a*.aa...a..a*a.a*a*a*a*a*.a*a.a.a.a*a*a*..a*.aa*...a*.a*a*a*aa*..a.a*.a*a.aaa*aaaa*a*.aa.a*..aa.a*aa*aa...a..a*.a*aaaa.a...a*..a*a*a*a.aa..aa*aa*a*a..a*.a..aaa*a.a*aa*aaa*..a*aaa..aa*.a*.aa*aa*a*a..a.aa*aa*a*.a*.a*aa*aa*.aa*..a*..a*a.aa.a*.a*..a*.a.a*a*aaa.aa*.a*a*a*aa*a*.a.a*aaaa*.a*....a*aa*..aa*..a*aaa*a*a.a*a.a*a*aa*..a*a*aa.a*a*a*aaa*aa*.a*...a*a.a*..aa*a.aa*a...a*a.aa.a.a*aa*.a*a*a*a*aaa*a*a*.aa*..a*.aa.a*.a*.a*.aa*aa*a*..a*aa.aa.aaa*aaa*aa*a...a*a*aaaaa*a.a*.aa*.a*.a*a*a*a..a.a...a*..a*a*.a*a*aa*aaa*.a*a*.a*a*...a*a*a*a*a..a*a*a.aa.aaa*...a*a.a..aaa*a*.a*a*.a*..a*aa.aa*a..a.a*a*........a.aaa*a*...a*aaa.a*a*aa*a*a*a*"
    };
    vector<string> c = {  "0", "1", "0", "0", "1", "1", "1", "1", "1", "1", "1"};
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
        if(result != stoi(c[i])){
            cout << endl << endl;
            cout << "A: " << a[i] << endl;
            cout << "B: " << b[i] << endl;
            cout << "Result: " << result << endl;
            cout << "Expected Result: " << stoi(c[i]) << endl;
            cout << endl;
        }
    }
    cout << endl;
    return 0;
}

// g++ -std=c++11