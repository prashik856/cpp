/*
Problem Description

It’s Tushar’s birthday today and he has N friends.

Friends are numbered [0, 1, 2, ...., N-1] and ith friend have a positive strength B[i].

Today being his birthday, his friends have planned to give him birthday bombs (kicks).

Tushar's friends know Tushar's pain bearing limit and would hit accordingly.

If Tushar’s resistance is denoted by A (>=0) then find the lexicographically smallest order of friends to kick Tushar so that the cumulative kick strength (sum of the strengths of friends who kicks) doesn’t exceed his resistance capacity and total no. of kicks hit are maximum.

Also note that each friend can kick unlimited number of times (If a friend hits x times, his strength will be counted x times)

Return the lexicographically smallest array of maximum length where the ith index represents the index of the friend who will hit.

NOTE:

[a1, a2, ...., am] is lexicographically smaller than [b1, b2, .., bm] if a1 < b1 or (a1 = b1 and a2 < b2) ... .
Input cases are such that the length of the answer does not exceed 100000.


Problem Constraints
1 <= N <= 100

1 <= A <= 15 * 106



1 <= B[i] <= 105



Input Format
The first argument contains an integer, A of length N.

The second argument contains an array of integers B.



Output Format
Return an array of integer, as described in the problem statement.



Example Input
Input 1:

 A = 12
 B = [3, 4]
Input 2:

 A = 11
 B = [6, 8, 5, 4, 7]


Example Output
Output 1:

 [0, 0, 0, 0]
Output 2:

 [0, 2]
*/
/*
Solution approach:
Looks like knapsack problem.
Following conditions needs to be met
1. No of kicks shoudld be maximum.
2. sum of kicks is <= A
3. Lexicographically smallerst order
4. Each friend can kick unlimited number of times

This question will be difficult using DP. 
We will required a loop of size A*B.size() which will be of 10^8
Actual DP solution:
vector<int> Solution::solve(int A, vector<int> &B) {
    int n=B.size();
    
    vector<int> dp(A+1,0),index(A+1);
    
    for(int i=0;i<=A;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i>=B[j])
            {
                if(dp[i-B[j]]+1 > dp[i])
                {
                    dp[i]=dp[i-B[j]]+1;
                    index[i]=j;
                }
            }
        }
    }
    
    vector<int> ans;
    
    int val=A;
    
    while(val>0 && val>=B[index[val]])
    {
        ans.push_back(index[val]);
        val=val-B[index[val]];
    }
    
    return ans;
    
}


Greedy approach:
1. while (A - minValue) > 0, we push our minimum value inside A. This will ensure maximum lenght of our answer.
2. Now, we can have some other boy kicking tushar in the middle (between 0 and minValueIndex), 
if A + minValue - B[j] > 0(j is the boy). 
If so, we set someIndex = 0, a[someIndex++] = j, A = A + minValue - B[j], else we move on ahead with our some other buy index.

vector Solution::solve(int A, vector &B) {
    vector ans;
    // Pushing minimum element first
    int mn=*min_element(B.begin(),B.end());
    int x=min_element(B.begin(),B.end())-B.begin();
    while(A>=mn){
        ans.push_back(x);
        A-=mn;
    }
    
    int j=0;
    int a=0;
    while(a<ans.size() && j<x){
        if(A-B[j]+mn>=0){
            A=A-B[j]+mn;
            ans[a]=j;
            a++;
        }
        else j++;
    }
    return ans;
}
// My Approach?
Sort b and keep track of indices:

// push values in our array

// sort the array

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

void solve2(int a, 
    vector<int> &b, 
    int indexB,
    int currentScore,
    vector<int> &currentPath,
    int *result_score,
    vector<int> &result) {
        // When we receive empty b, we cannot
        if(indexB >= b.size()) {
            return;
        }

        // if our currentScore <= a
        if(currentScore <= a){
            // if equal score
            int pathSize = currentPath.size();
            if(pathSize > *result_score){
                *result_score = pathSize;
                result = currentPath;
            }
        }

        // What is changing -> currentScore, indexB, currentPath -
        // We want to maximize currentPath


        // can current index be included?
        if(b[indexB] + currentScore <= a){
            // include current index and don't move ahead
            currentPath.push_back(indexB);

            solve2(a, b, indexB, b[indexB] + currentScore, currentPath, result_score, result);
            // include current index and move ahead
            solve2(a, b, indexB+1, b[indexB] + currentScore, currentPath, result_score, result);

            // backtrack
            currentPath.pop_back();

            // don't include current index and move ahead
            solve2(a, b, indexB + 1, currentScore, currentPath, result_score, result);
        } else {
            // don't include the current index and move ahead
            solve2(a, b, indexB+1, currentScore, currentPath, result_score, result);
        }

        return;
}

vector<int> solve3(int a, vector<int> &b, int indexB){
    if(indexB < 0) {
        return vector<int>();
    }
    if(a == 0){
        return vector<int>();
    }

    if(a - b[indexB] >= 0){
        vector<int> result1 = solve3(a - b[indexB], b, indexB);
        result1.insert(result1.begin(), indexB);
        vector<int> result2 = solve3(a - b[indexB], b, indexB - 1);
        result2.insert(result2.begin(), indexB);
        vector<int> result3 = solve3(a, b, indexB - 1);
        if(result1.size() >= result2.size() && result1.size() >= result3.size()){
            return result1;
        } else if(result2.size() > result1.size() && result2.size() > result3.size()){
            return result2;
        } else if(result3.size() > result1.size() && result3.size() > result2.size()){
            return result3;
        }
    } else {
        vector<int> result4 = solve3(a, b, indexB - 1);
        return result4;
    }

    return vector<int>();
}

vector<int> solve(int a, vector<int> &b) {
    vector<int> result;
    // Greedy solution is better
    int minValue = INT_MAX;
    int minValueIndex = 0;
    for(int i=0; i<b.size(); i++){
        if(b[i] < minValue){
            minValue = b[i];
            minValueIndex = i;
        }
    }

    // fill in our result
    while(a >= minValue){
        result.push_back(minValueIndex);
        a = a - minValue;
    }

    // Get the middle guy kicking tushar
    int ansIndex = 0;
    int j = 0;
    while(ansIndex < result.size() && j < minValueIndex){
        if(a + minValue - b[j] >= 0){
            a = a + minValue - b[j];
            result[ansIndex] = j;
            ansIndex++;
            // try with some other index
        } else {
            j++;
        }
    }

    return result;
}

int main(){
    int a = 11;
    vector<int> b = {6, 8, 5, 4, 7, 34, 3, 32432 ,4,532423, 2342, 5324234 ,53534322, 24321,123, 424, 987};
    cout << "Limit : " << a << endl;
    cout << "Weight array: " << endl;
    printVector(b);

    vector<int> result = solve(a, b);
    cout << "Result: " << endl;
    printVector(result);
    return 0;
}

// g++ -std=c++11