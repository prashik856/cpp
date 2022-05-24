/*
Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character


Input Format:

The first argument of input contains a string, A.
The second argument of input contains a string, B.
Output Format:

Return an integer, representing the minimum number of steps required.
Constraints:

1 <= length(A), length(B) <= 450
Examples:

Input 1:
    A = "abad"
    B = "abac"

Output 1:
    1

Explanation 1:
    Operation 1: Replace d with c.

Input 2:
    A = "Anshuman"
    B = "Antihuman"

Output 2:
    2

Explanation 2:
    => Operation 1: Replace s with t.
    => Operation 2: Insert i.
*/

/*
Solution Approach:
Need to write recursive solution first.

To write recursive solution, think of the minimum input first and what will be the return value for that input.
This is very important. 
Once this is done, write the choices that we have:
1. if equal, return 0
2. if not equal -> 1 + (either insert, delete, or replace)

Once we have a working recursive solution, just tabulize it.
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

int lcm(string &A, int indexA, string &B, int indexB, vector< vector<int> > &table) {
    if(indexA < 0 || indexB < 0) {
        return 0;
    }

    if(table[indexA][indexB] != -1){
        return table[indexA][indexB];
    }

    int result1 = 0;
    int result2 = 0;
    int result3 = 0;

    // if equal
    if(A[indexA] == B[indexB]){
        result1 = 1 + lcm(A, indexA - 1, B, indexB - 1, table);
    } else {
        
        result2 = lcm(A, indexA, B, indexB - 1, table);
        // if we delete from A
        result3 = lcm(A, indexA - 1, B, indexB, table);
    }
    int tempResult = max(max(result1, result2), max(result2, result3));
    table[indexA][indexB] = tempResult;
    return tempResult;
}

long editDistance(string &A, string &B, int indexA, int indexB, vector< vector<long> > &table) {
    // both less than 0, return 0
    if(indexA < 0 && indexB < 0){
        return 0;
    }

    if(indexA < 0){
        return indexB + 1;
    }

    if(indexB < 0){
        return indexA + 1;
    }

    // return cache
    if(table[indexA][indexB] != -1){
        return table[indexA][indexB];
    }

    // if equal
    long result1 = INT_MAX;
    // delete
    long result2 = INT_MAX;
    // insert
    long result3 = INT_MAX;
    // replace
    long result4 = INT_MAX;
    // no operation
    if(A[indexA] == B[indexB]){
        result1 = editDistance(A, B, indexA - 1, indexB - 1, table);
    } else {
        // delete
        result2 = 1 + editDistance(A, B, indexA -1, indexB, table);   
        
        // insert
        result3 = 1 + editDistance(A, B, indexA, indexB - 1, table);
        
        
        // replace
        result4 = 1 + editDistance(A, B, indexA - 1, indexB - 1, table);
        
    }
    // cout << "IndexA: " << indexA << endl;
    // cout << "IndexB: " << indexB << endl;
    // cout << "ValA: " << A[indexA] << endl;
    // cout << "ValB: " << B[indexB] << endl;
    // cout << "Equal: " << result1 << endl;
    // cout << "Delete: " << result2 << endl;
    // cout << "Insert: " << result3 << endl;
    // cout << "Replace: " << result4 << endl;
    long tempResult = min(min(result1, result2), min(result3, result4));
    // cout << "TempResult: " << tempResult << endl << endl;
    // store cache
    table[indexA][indexB] = tempResult;
    return tempResult;
}

int solve(string A, string B) {
    int result = 0;
    int N = 450;
    vector< vector<long> > table(N, vector<long>(N, -1));

    // Hmm, this will only take care of insertions and deletions
    // What about replacements?
    // When can we replace?
    result = editDistance(A, B, A.size() - 1, B.size() - 1, table);

    return result;
}

int main(){
    string a = "Anshuman";
    string b = "Antihuman";
    cout << "Input string 1 : " << a << endl;
    cout << "Input strinb 2 : " << b << endl;

    int result = solve(a, b);
    cout << "Result: " << result << endl;
    return 0;
}

// g++ -std=c++11