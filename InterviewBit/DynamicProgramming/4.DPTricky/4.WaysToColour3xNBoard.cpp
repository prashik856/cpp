/*
Given a 3 x A board,  find the number of ways to color it using at most 4 colors such that no 2 adjacent boxes have same color.

Diagonal neighbors are not treated as adjacent boxes.

Return the ways modulo 109 + 7 as the answer grows quickly.

Input Format:

The first and the only argument contains an integer, A.
Output Format:

Return an integer representing the number of ways to color the board.
Constraints:

1 <= A < 100000
Examples:

Input 1:
    A = 1

Output 1:
    36

Input 2:
    A = 2

Output 2:
    588
*/
/*
Solution Approach:
https://www.geeksforgeeks.org/ways-color-3n-board-using-4-colors/
We are going to solve this using dynamic approach because when a new column is added to the board, 
the ways in which colors are going to be filled depends just upon the color pattern in the current column. 
We can only have a combination of two colors and three colors in a column. 
All possible new columns that can be generated is given in the image. 
Please consider A, B, C and D as 4 colors. 
From now, we will refer 3 colors combination for a Nth column of the 3*N board as W(n) and two colors as Y(n). 
We can see that each W can generate 5Y and 11W, and each Y can generate 7Y and 10W. We get two equation from here 
We have two equations now, 
 
W(n+1) = 10*Y(n)+11*W(n);
Y(n+1) = 7*Y(n)+5*W(n);

Video Solution:
https://www.youtube.com/watch?v=wInXbAHi72g&ab_channel=ChirayuJain
*/
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

class Triplet {
    public:
        int x,y,z;
        Triplet(int a, int b, int c) {
            x = a;
            y = b;
            z = c;
        }
        void printTriplet() {
            cout << x << " " << y << " " << z << endl;
        }
};

// Function to check if t1 is compatible to t2
bool isCompatible(Triplet t1, Triplet t2) {
    // We already made sure that vertically we shouldn't have any
    // equal adjacent values.
    // So here, we will just check horizontal equal values
    if(t1.x == t2.x || t1.y == t2.y || t1.z == t2.z) {
        return false;
    }
    return true;
}

int solve2(int n) {
    int result = 0;
    // the initial state when using 2 colors
    long long c2 = 12;
    // The initial state when using 3 colors
    long long c3 = 24;
    int mod = 1000000007;

    for(int i=2; i<=n; i++) {
        // It is not easy to arrive at this conclusion
        // For this, we need to first get all the possible combinations (36, which we can get)
        // After this, consider a column with only 2 colours -> For this column,
        // we need to find all possible columns from our combinations which has only 2 colours and
        // it satisfies adjacency
        // We then also need to find columns with 3 colours and it satisfies adjacency
        // Now consider a column with 3 colors, for this column, we find the next columns from combinations
        // with only 2 colors and 3 colours respectively
        // From two equations, we get
        // C2 = 7 (C2 columns) and 10 (C3 columns)
        // C3 = 5 (C2 columns) and 11 (C3 columns)
        // To get next C2[i] = 7 * C2[i-1] + 5 * C3[i-1]
        // To get next C3[i] = 10 * C2[i-1] + 11 * C3[i-1]
        long long temp2 = 7 * c2 + 5 * c3;
        long long temp3 = 10 * c2 + 11 * c3;
        c2 = temp2 % mod;
        c3 = temp3 % mod;
    }
    long long tempResult = c2 + c3;
    tempResult = tempResult % mod;
    result = tempResult;
    return result;
}

int solve(int n) {
    // This will be one approach to solve this problem
    //
    int result;
    int mod = 1000000007;
    // base condition
    if(n <= 0){
        return -1;
    }
    int N  = n+1;
    vector<Triplet> combinations;
    // Create triplet
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            for(int k=0; k<4; k++) {
                if(i!=j && j!=k) {
                    // not equal condition because we don't want adjacent values to be equal
                    combinations.push_back(Triplet(i, j, k));
                }
            }
        }
    }

    // print triplet
//    for(int i=0; i<combinations.size(); i++) {
//        combinations[i].printTriplet();
//    }
//    cout << endl;
//    cout << "Length of combination: " << combinations.size() << endl;

    // Create our dp array
    // This will be a 4D array of size 4x4x4xN
    int dp[4][4][4][N];
    // Initialize it to 0;
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            for(int k=0; k<4; k++) {
                for(int l=0; l<N; l++) {
                    dp[i][j][k][l] = 0;
                }
            }
        }
    }

    // Let's go through all our columns
    for(int i=1; i<=n; i++) {
        // Let's go through all our combinations
        for(int j=0; j<36; j++) {
            // 1st column check
            if(i == 1) {
                dp[combinations[j].x][combinations[j].y][combinations[j].z][i] = 1;
            } else {
                long long temp = 0;
                // this is not first column
                // we go through all of our combinations
                for(int k=0; k<36; k++) {
                    // check if j and k are compatible
                    if(isCompatible(combinations[j], combinations[k])) {
                        // check what is the value of
                        // Here, we want to check what combinations will work with current j.
                        // here combination variable is k, and last column is i-1.
                        // that's why we are adding value of i-1 and k'th combination to our current
                        // value (combinations[j], i)
                        temp += dp[combinations[k].x][combinations[k].y][combinations[k].z][i-1];
                        temp = temp % mod;
                    }
                }
                dp[combinations[j].x][combinations[j].y][combinations[j].z][i] = temp;
            }
        }
        // all columns done.
    }

    // Here, now we try to get our answer
    // Let's get all possible answers and add them up because we need total number of ways to
    // color board.
    // Remember we stored our answer in the last column of our dp.
    // Add all combinations answer to get the result.
    long long ans = 0;
    for(int i=0; i<combinations.size(); i++) {
        ans = ans + dp[combinations[i].x][combinations[i].y][combinations[i].z][n];
        ans = ans % mod;
    }
    result = ans;
    return result;
}

int main(){
    int n = 4;
    cout << "Number of Columns: " << n << endl;

    int result = solve2(n);
    cout << "Result: " << result << endl;
    return 0;
}

// g++ -std=c++11