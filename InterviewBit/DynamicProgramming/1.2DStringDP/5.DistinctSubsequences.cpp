/*
Given two sequences A, B, count number of unique ways in sequence A, to form a subsequence that is identical to the sequence B.

Subsequence : A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, “ACE” is a subsequence of “ABCDE” while “AEC” is not).

Input Format:

The first argument of input contains a string, A.
The second argument of input contains a string, B.
Output Format:

Return an integer representing the answer as described in the problem statement.
Constraints:

1 <= length(A), length(B) <= 700
Example :

Input 1:
    A = "abc"
    B = "abc"
    
Output 1:
    1

Explanation 1:
    Both the strings are equal.

Input 2:
    A = "rabbbit" 
    B = "rabbit"

Output 2:
    3

Explanation 2:
    These are the possible removals of characters:
        => A = "ra_bbit" 
        => A = "rab_bit" 
        => A = "rabb_it"
        
    Note: "_" marks the removed character.
*/
/*
Solution Approach:
https://www.geeksforgeeks.org/count-distinct-occurrences-as-a-subsequence/
Input: S = banana, T = ban
Output: 3
Explanation: T appears in S as below three subsequences.
[ban], [ba  n], [b   an]

Input: S = geeksforgeeks, T = ge
Output: 6
Explanation: T appears in S as below three subsequences.
[ge], [     ge], [g e], [g    e] [g     e]
and [     g e]   

Approach: Create a recursive function such that it returns count of subsequences of S that match T. 
Here m is the length of T and n is length of S. This problem can be recursively defined as below.  

1. Given the string T is an empty string, returning 1 as an empty string can be the subsequence of all.
2. Given the string S is an empty string, returning 0 as no string can be the subsequence of an empty string.
3. If the last character of S and T do not match, then remove the last character of S and 
call the recursive function again. Because the last character of S cannot be a part of the subsequence or 
remove it and check for other characters.
4. If the last character of S match then there can be two possibilities, 
first there can be a subsequence where the last character of S is a part of it and second where it is not a 
part of the subsequence. So the required value will be the sum of both. 
Call the recursive function once with last character of both the strings removed and again with only last character of 
S removed.
Implementation working as below.
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

int customStringCompare(string &A, string &B, int indexA, int indexB) {
    int result = 0;

    if(A.size() > B.size()) {
        for(int i=0; i<B.size(); i++) {
            if(A[i] != B[i]){
                return 1;
            }
        }
    } else {
        for(int i=0; i<A.size(); i++){
            if(A[i] != B[i]){
                return 1;
            }
        }
    }

    return result;
}

int distSub(string &A, string &B, int indexA, int indexB, int* result) {
    // bad values
    if(indexA < 0 || indexB < 0) {
        return 0;
    }

    // size of B > size of A
    if(indexB > indexA) {
        return 0;
    }

    // indexes are equal, both strings must be equal
    if(indexA == indexB) {
        if(customStringCompare(A,B,indexA,indexB) == 0){
            return indexA + 1;
        }
    }

    int result1 = 0;
    int result2 = 0;
    int result3 = 0;
    // here, indexA > indexB
    if(indexA > indexB) {
        if(A[indexA] == B[indexB]) {
            result1 = 1 + distSub(A, B, indexA - 1, indexB - 1, result);
        }
        result2 = distSub(A, B, indexA - 1, indexB, result);
        // what if not equal, -> we go to result 2
    }
    if(result1 == B.size()) {
        (*result) += 1;
    }
    if(result2 == B.size()) {
        (*result) += 1;
    }
    int tempResult = max(result1, result2);
    return tempResult;
}

int solve2(string &A, string &B, int indexA, int indexB, vector< vector<int> > &table) {
    // What if B is empty
    if(indexB < 0) {
        // empty string
        // always a substring
        return 1;
    }

    // what if A is empty
    if(indexA < 0) {
        return 0;
    }

    if(table[indexA][indexB] != -1){
        return table[indexA][indexB];
    }
    
    // Check if values are equal
    int result1 = 0;
    int result2 = 0;
    if(A[indexA] == B[indexB]){
        // one is to include 
        // other is to not include
        result1 = solve2(A, B, indexA - 1, indexB - 1, table) + solve2(A, B, indexA - 1, indexB, table);
        // cout << "Result1: " << result1 << endl;
        table[indexA][indexB] = result1;
        return result1;
    }
    result2 = solve2(A, B, indexA - 1, indexB, table);
    // cout << "Result2: " << result2 << endl;
    table[indexA][indexB] = result2;
    return result2;
}

int solve(string &A, string &B) {
    int result = 0;

    int n = 700;
    vector< vector<int> > table(n, vector<int>(n, -1));
    result = solve2(A, B, A.size() - 1, B.size() - 1, table);

    return result;
}

int main(){
    string A = "abcd";
    string B = "abed";
    cout << "Given input 1: " << A << endl;
    cout << "Given input 2: " << B << endl;

    int result = solve(A, B);
    cout << "Result: " << result << endl;
    return 0;
}

// g++ -std=c++11