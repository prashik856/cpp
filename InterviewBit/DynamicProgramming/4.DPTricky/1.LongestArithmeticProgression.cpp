/*
Find longest Arithmetic Progression in an integer array A of size N, and return its length.

More formally, find longest sequence of indices, 0 < i1 < i2 < … < ik < ArraySize(0-indexed) such that sequence A[i1], A[i2], …, A[ik] is an Arithmetic Progression.

Arithmetic Progression is a sequence in which all the differences between consecutive pairs are the same, i.e sequence B[0], B[1], B[2], …, B[m - 1] of length m is an Arithmetic Progression if and only if B[1] - B[0] == B[2] - B[1] == B[3] - B[2] == … == B[m - 1] - B[m - 2]

Note: The common difference can be positive, negative or 0.



Input Format:

The first and the only argument of input contains an integer array, A.
Output Format:

Return an integer, representing the length of the longest possible arithmetic progression.
Constraints:

1 <= N <= 1000
1 <= A[i] <= 1e9
Examples:

Input 1:
    A = [3, 6, 9, 12]

Output 1:
    4

Explanation 1:
    [3, 6, 9, 12] form an arithmetic progression.

Input 2:
    A = [9, 4, 7, 2, 10]

Output 2:
    3

Explanation 2:
    [4, 7, 10] form an arithmetic progression.
*/
/*
Solution approach:
https://www.geeksforgeeks.org/longest-arithmetic-progression-dp-35/
Lenght of Longest Arithmatic Progression (LLAP)
-> A simple solution is to one by one consider every pair as first two elements of AP and check for the remaining elements 
in sorted set. 
-> To consider all pairs as first two elements, we need to run a O(n^2) nested loop. 
-> Inside the nested loops, we need a third loop which linearly looks for the more elements in Arithmetic Progression (AP). 
-> This process takes O(n3) time. 

We can solve this problem in O(n2) time using Dynamic Programming. 
To get idea of the DP solution, let us first discuss solution of following simpler problem.

Given a sorted set, find if there exist three elements in Arithmetic Progression or not 
- Please note that, the answer is true if there are 3 or more elements in AP, otherwise false.
- To find the three elements, we first fix an element as middle element and search for other two (one smaller and one greater).
- We start from the second element and fix every element as middle element. 
- For an element set[j] to be middle of AP, there must exist elements ‘set[i]’ and ‘set[k]’ such that 
    set[i] - d + set[k] + d= 2*set[j] where 0 <= i < j and j < k <=n-1. 
- How to efficiently find i and k for a given j? We can find i and k in linear time using following simple algorithm. 
-> Initialize i as j-1 and k as j+1
-> Do following while i >= 0 and k <= n-1
-> If set[i] + set[k] is equal to 2*set[j], then we are done.
        If set[i] + set[k] > 2*set[j], 
            then decrement i (do i–).
        Else if set[i] + set[k] < 2*set[j], 
            then increment k (do k++).
// The function returns true if there exist three
// elements in AP Assumption: set[0..n-1] is sorted.
// The code strictly implements the algorithm provided
// in the reference.
bool arithmeticThree(vector<int> set, int n)
{
     
    // One by fix every element as middle element
    for(int j = 1; j < n - 1; j++)
    {
         
        // Initialize i and k for the current j
        int i = j - 1, k = j + 1;
 
        // Find if there exist i and k that form AP
        // with j as middle element
        while (i >= 0 && k <= n-1)
        {
            if (set[i] + set[k] == 2 * set[j])
                return true;
                 
            (set[i] + set[k] < 2 * set[j]) ? k++ : i--;
        }
    }
    return false;
}

How to extend the above solution for the original problem? 
- The above function returns a boolean value. 
- The required output of original problem is Length of the Longest Arithmetic Progression (LLAP) which is an integer value. 
- If the given set has two or more elements, then the value of LLAP is at least 2 (Because two elements are always in AP)
- The idea is to create a 2D table L[n][n]. 
- An entry L[i][j] in this table stores LLAP with set[i] and set[j] as first two elements of AP and j > i. 
- The last column of the table is always 2 (Why – see the meaning of L[i][j]). 
- Rest of the table is filled from bottom right to top left. 
- To fill rest of the table, j (second element in AP) is first fixed. 
- i and k are searched for a fixed j. 
- If i and k are found such that i, j, k form an AP, then the value of L[i][j] is set as L[j][k] + 1. 
- Note that the value of L[j][k] must have been filled before as the loop traverses from right to left columns.


// Now, the above solution will work when we have a sorted array as input
What if the array is not sorted?
https://www.geeksforgeeks.org/longest-subsequence-forming-an-arithmetic-progression-ap/?ref=rp

// Not able to understand.
Better see this video:
https://www.youtube.com/watch?v=Lm38EAoDc7c&ab_channel=ChirayuJain
How to apporach this problem?
Make some observations:
A = [9, 4, 7, 2, 10]
Let's node down all the differences
for 9, 4 - 9 = -5
        7 - 9 = -2
        2 - 9 = -7
        10 - 9 = 1
for 4, 7-4 = 3
        2 - 4 = -2
        1- - 4 = 6
for 7, 2 - 7 = -5
        10 - 7 = 3
for 2, 10 - 2 = 8
Listed down all the differences

Observation from this example:
There will be two states in our DP solution
1. Difference
2. last value of AP with that difference

DP[val][diff] will contain the number of elements of AP whose last element is val
and difference is diff
Now, how do we store these kind of values?
we can use vector< unordered_map<int, int> >.
for(int i=n-2; i>=0; i--){
    for(int j=i+1; j<n; j++){
        int difference = a[j] - a[i];

        // check if cache exists
        if yes -> get value, and update the dp
        if no -> update the dp

        keep track of global maximum.
    }
}

// The solution below got accepted in leetcode. 
Fuck interview bit for having numbers > 500
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

int solve(vector<int> &a){
    int result = 0;
    int n = a.size();

    // base case
    if(n <= 2) {
        return n;
    }

    // n will the last value of ap series
    // and unordered_map key will store the value of difference and value will store the value of 
    vector< vector<int> > dp(n, vector<int>(1001, 0));

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++) {
            // cout << "j -> " << j << " -> " << a[j] << endl;
            // cout << "i -> " << i << " -> " << a[i] << endl;
            
            int difference = a[j] - a[i] + 500;
            // cout << "Difference: " << difference << endl;
            int currentValue = 2;

            // see if this value exists
            if(dp[i][difference] != 0){
                // cout << "hit" << endl;
                // cout << "Cached value: " << existingMap[difference] << endl;
                // found it
                currentValue = 1 + dp[i][difference];

                // Store incremented value in a new map
                // cout << "New value: " << currentValue << endl;
                // Store the optimal value
                dp[j][difference] = max(currentValue, dp[j][difference]);
            } else {
                // cout << "No hit" << endl;
                // not found
                currentValue = 2;
                // cout << "New value: " << currentValue << endl;
                // Store the optimal value
                dp[j][difference] = max(dp[j][difference], currentValue);
            }
            result = max(result, dp[j][difference]);
        }
    }
    // print2DVector(dp);

    return result;
}

int main(){
    vector<int> a = {1, 1, 1, 1, 1};
    cout << "Given input vector is: " << endl;
    printVector(a);

    int result = solve(a);
    cout << "Result: " << result << endl;
    return 0;
}

// g++ -std=c++11