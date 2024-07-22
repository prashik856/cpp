/*
 * Kth Manhattan Distance Neighbourhood
 * Given a matrix M of size nxm and an integer K,
 find the maximum element in the K manhattan distance neighbourhood for all elements in nxm matrix.

In other words, for every element M[i][j] find the maximum element M[p][q] such that abs(i-p)+abs(j-q) <= K.

Note: Expected time complexity is O(N*N*K)

Constraints:

1 <= n <= 300
1 <= m <= 300
1 <= K <= 300
0 <= M[i][j] <= 1000
Example:

Input:
M  = [[1,2,4],[4,5,8]] , K = 2

Output:
ans = [[5,8,8],[8,8,8]]
 * */
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
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

void print2DVector(vector< vector<long> > arr){
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

void print4DVector(vector< vector< vector< vector<int>>>> arr) {
    for(int i=0; i<arr.size(); i++) {
        cout << i << " : " << endl;
        for(int j=0; j<arr[i].size(); j++) {
            cout << j << " : " << endl;
            for(int k=0; k<arr[j].size(); k++) {
                for(int l=0; l<arr[k].size(); l++) {
                    cout << arr[i][j][k][l] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }
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

int getMax(vector<int> &arr) {
    int maxValue = arr[0];
    for(int i=0; i<arr.size(); i++) {
        maxValue = max(maxValue, arr[i]);
    }
    return maxValue;
}

vector< vector<int>> solve(vector< vector<int>> &a,
                           int k) {
    vector< vector<int>> result;
    int n = a.size();
    int m = a[0].size();
    // We need to find value for k = 0
    // abs(i-p) + abs(j-q) <= 0.
    // Absolute values can only be positive. So that means, i=p and j=q. That means m[i][j] = m[p][q], when k = 0
    vector< vector< vector<int>>> dp(k+1, vector< vector<int>>(n, vector<int>(m)));

    // Initialize dp array for k = 0
    for(int j=0; j<n; j++) {
        for(int l=0; l<m; l++) {
            dp[0][j][l] = a[j][l];
        }
    }

    // Now, when we have k, our equation becomes
    // abs(i-p) + abs(j-q) <= k
    // When we go to k+1, our equation becomes,
    // abs(i-p) + abs(j-q) <= k
    // abs(i-p) + abs(j-q) - 1 <= k
    // Now, this -1 can come to 4 different combinations
    // dp[k+1][i][j] = max(dp[k][i][j], dp[k][i-1][j], dp[k][i][j-1], dp[k][i+1][j], dp[k][i][j+1])
    // Last logic is important to understand
    vector<int> temp(5, 0);
    for(int i=1; i<=k; i++) {
        for(int j=0; j<n; j++) {
            for(int l=0; l<m; l++) {
                int val1 = 0, val2 = 0, val3 = 0, val4 = 0;
                if(j-1 >=0) {
                    val1 = dp[i-1][j-1][l];
                }
                if(l-1 >=0) {
                    val2 = dp[i-1][j][l-1];
                }
                if(j+1 < n) {
                    val3 = dp[i-1][j+1][l];
                }
                if(l+1 < m) {
                    val4 = dp[i-1][j][l+1];
                }
                temp = {dp[i-1][j][l], val1, val2, val3, val4};
                dp[i][j][l] = getMax(temp);
            }
        }
    }

//    for(int i=0; i<=k; i++) {
//        for(int j=0; j<n; j++) {
//            for(int l=0; l<m; l++) {
//                cout << dp[i][j][l] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }
    result = dp[k];
    return result;
}

int main(){
    vector< vector<int>> m = {
            {1, 2, 4},
            {4, 5, 8}
    };
    cout << "Given input is: " << endl;
    print2DVector(m);

    int k = 2;
    cout << "Given value of k is: " << k << endl << endl;

    vector< vector<int>> result = solve(m, k);
    cout << "Result: " << endl;
    print2DVector(result);
}
// g++ -std=c++11