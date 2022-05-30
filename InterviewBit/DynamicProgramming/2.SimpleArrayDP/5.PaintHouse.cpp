/*
Problem Description

There are a row of N houses, each house can be painted with one of the three colors: red, blue or green.

The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a N x 3 cost matrix A.

For example, A[0][0] is the cost of painting house 0 with color red; A[1][2] is the cost of painting house 1 with color green, and so on.

Find the minimum total cost to paint all houses.



Problem Constraints
1 <= N <= 105

1 <= A[i][j] <= 103



Input Format
First and only argument is an 2D integer matrix A of size N x 3 denoting the cost to paint the houses.



Output Format
Return an integer denoting the minimum total cost to paint all houses.



Example Input
Input 1:

 A = [  [1, 2, 3]
        [10, 11, 12]
     ]


Example Output
Output 1:

 12


Example Explanation
Explanation 1:

 Paint house 1 with red and house 2 with green i.e A[0][0] + A[1][1] = 1 + 11 = 12
*/
/*
Solution Approach:
We keep track of all of our 3 tracks.
First, we initialize our dict with A[0], A[1] and A[2], which will be our initial paths.
Second, we go through the whole array, and keep updating our dictionary.
dict[i][0] = A[i][0] + min(dict[i-1][1], dict[i-1][2]) // if we are choosing 0, we choose min(1, 2) in the previous step

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

int solve2(vector< vector<int> > &a, int indexA, int color, int prevColor) {
    if(indexA >= a.size()) {
        return 0;
    }

    // first time
    if(color == -1 && prevColor == -1){
        // cout << "First time" << endl;
        int result1 = a[indexA][0] + solve2(a, indexA + 1, 0, -1);
        int result2 = a[indexA][1] + solve2(a, indexA + 1, 1, -1);
        int result3 = a[indexA][2] + solve2(a, indexA + 1, 2, -1);
        int tempResult = min(min(result1, result2), min(result2, result3));
        return tempResult;
    }

    // second time
    if(prevColor == -1 && color != -1){
        // cout << "Second time" << endl;
        if(color == 0) {
            int result1 = a[indexA][1] + solve2(a, indexA + 1, 1, color);
            int result2 = a[indexA][2] + solve2(a, indexA + 1, 2, color);
            int tempResult = min(result1, result2);
            return tempResult;
        }
        
        if(color == 1) {
            int result1 = a[indexA][2] + solve2(a, indexA + 1, 2, color);
            int result2 = a[indexA][0] + solve2(a, indexA + 1, 0, color);
            int tempResult = min(result1, result2);
            return tempResult;
        }
        
        if(color == 2) {
            int result1 = a[indexA][0] + solve2(a, indexA + 1, 0, color);
            int result2 = a[indexA][1] + solve2(a, indexA + 1, 1, color);
            int tempResult = min(result1, result2);
            return tempResult;
        }
    }

    // color != -1 && prevColor != -1
    // only 1 choice
    if(prevColor != -1 && color != -1) {
        // cout << "Third time" << endl;
        if((color == 0 && prevColor == 1) || (color == 1 && prevColor == 0)) {
            // choose 2
            return a[indexA][2] + solve2(a, indexA + 1, 2, color);
        } else if((color == 1 && prevColor == 2) || (color == 2 && prevColor == 1)) {
            // choose 0
            return a[indexA][0] + solve2(a, indexA + 1, 0, color);
        } else if((color == 2 && prevColor == 0) || (color == 0 && prevColor == 2)) {
            // choose 1
            return a[indexA][1] + solve2(a, indexA + 1, 1, color);
        }
    }

    // else, we just return 0
    return 0;
}

int solve(vector< vector<int> > &A) {
    int result = 0;

    // if input vector is 0, return 0
    if(A.size() == 0){
        return 0;
    }

    // Store our dictionary
    vector< vector<int> > dict(A.size() + 1, vector<int>(3, 0));
    // Keep track of all our paths
    dict[1][0] = A[0][0];
    dict[1][1] = A[0][1];
    dict[1][2] = A[0][2];
    for(int i=2; i<=A.size(); i++) {
        // If we are choosing 0 here, that means i-1 should be min(1, 2)
        // Same for others
        dict[i][0] = A[i-1][0] + min(dict[i-1][1], dict[i-1][2]);
        dict[i][1] = A[i-1][1] + min(dict[i-1][0], dict[i-1][2]);
        dict[i][2] = A[i-1][2] + min(dict[i-1][0], dict[i-1][1]);
    }

    result = min(min(dict[A.size()][1], dict[A.size()][2]), dict[A.size()][0]);
    return result;
}

int main(){
    vector< vector<int> > a = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {12, 11, 10},
        {15, 13, 14},
        {16, 18, 17}
    };
    cout << "Given input is: " << endl;
    print2DVector(a);

    int result = solve(a);
    cout << "Result: " << result << endl;
    return 0;
}

// g++ -std=c++11