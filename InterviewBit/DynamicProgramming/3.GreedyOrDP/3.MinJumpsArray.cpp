/*
Given an array of non-negative integers, A, of length N, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Return the minimum number of jumps required to reach the last index.

If it is not possible to reach the last index, return -1.

Input Format:

The first and the only argument contains an integer array, A.
Output Format:

Return an integer, representing the answer as described in the problem statement.
Constraints:

1 <= N <= 1e6
0 <= A[i] <= 50000
Examples:

Input 1:
    A = [2, 1, 1]

Output 1:
    1
    
Explanation 1:
    The shortest way to reach index 2 is
        Index 0 -> Index 2
    that requires only 1 jump.

Input 2:
    A = [2,3,1,1,4]

Output 2:
    2

Explanation 2:
    The shortest way to reach index 4 is
        Index 0 -> Index 1 -> Index 4
    that requires 2 jumps.
*/
/*
Solution Approach:
A better version of the previous problem.
Right now, no clue how to solve this.
https://www.geeksforgeeks.org/minimum-number-jumps-reach-endset-2on-solution/

Algorithm:
1. We initialize 3 variables, 
maxReach, jump and steps
2. maxReach = a[0], steps = a[0] and jump = 1
3. We start the traversal, 
if(we reach destination) -> return jump
// we update max reach
maxReach = max(maxReach, i + a[i])
// check if maxReach is reachable
if(i >= maxReach) -> return -1;
// we decrement the step
step--;
if step == 0 -> We cannot take any more step
    // update step
    step = maxReach - i;
    jump++
// if nothing happened, return -1
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
    int result = -1;

    // if length of array is 1, we are already here
    if(a.size() <= 1){
        return 0;
    }

    // if current jump is 0, we cannot jump
    if(a[0] == 0){
        return result;
    }

    // define max reach
    int maxReach = a[0];

    // steps remaining
    int steps = a[0];

    // our jumps required
    // we will always start with 1 jump
    int jump = 1;
    for(int i=1; i<a.size(); i++){

        // We have arrived at the destination
        if(i == a.size() - 1){
            return jump;
        }

        // update maxreach
        maxReach = max(maxReach, i + a[i]);

        // not possible to reach the end
        if(i >= maxReach){
            return -1;
        }

        // we have taken a step
        // so we need to decrement it
        steps--;

        // Update jump
        if(steps == 0){
            // increment jump
            jump++;
            // update our steps
            steps = maxReach - i;
        }
    }

    return result;
}

int main(){
    vector<int> a = {2, 1, 1};
    cout << "Input: " << endl;
    printVector(a);

    int result = solve(a);
    cout << "Result: " << result << endl;
    return 0;
}

// g++ -std=c++11