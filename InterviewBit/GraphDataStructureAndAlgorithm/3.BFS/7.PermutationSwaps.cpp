/*

Problem Description

Rishabh has a permutation A of N integers 1, 2, ... N but he doesn't like it. Rishabh wants to get a permutation B.

Also, Rishabh has some M good pairs given in a form of 2D matrix C of size M x 2  where (C[i][0], C[i][1]) denotes that two indexes of the permutation A.

In one operation he can swap Ax and Ay only if (x, y) is a good pair.

You have to tell whether Rishabh can obtain permutation B by performing the above operation any number of times on permutation A.

If the permutation B can be obtained return 1 else return 0.



Problem Constraints
2 <= N <= 105
1 <= M <= 105
1 <= A[i], B[i] <= N
A[i] and B[i] are all distinct.
1 <= C[i][0] < C[i][1] <= N


Input Format
First arguement is an integer array A of size N denoting the permutation A.

Second arguement is an integer array B of size N denoting the permutation B.

Third argument is an 2D integer array C of size M x 2 denoting the M good pairs.



Output Format
If the permutation B can be obtained return 1 else return 0.



Example Input
Input 1:

 A = [1, 3, 2, 4]
 B = [1, 4, 2, 3]
 C = [ 
        [3, 4]
     ]
Input 2:

 A = [1, 3, 2, 4]
 B = [1, 4, 2, 3]
 C = [
        [2, 4]
     ] 


Example Output
Output 1:

 0
Output 2:

 1


Example Explanation
Explanation 1:

 As A != B you have to perform operations on A but there is only good pair available i,e (3, 4) so if you swap
 A3 with A4 you get A = [1, 3, 4, 2] which is not equal to B so we will return 0.
Explanation 2:

 As A != B you have to perform operations on A but there is only good pair available i,e (2, 4) so if you swap
 A2 with A4 you get A = [1, 4, 2, 3] which is equal to B so we will return 1.
*/
/*
Solution Approach:
I think this is a Disjoint set question.
Now, assume our A is something like:
a,b,c,d,e,f,g,h

B is:
d,e,f,g,h,a,b,c
Now, we first find all the disjoint sets (all swappable pairs groups)

Then, we go through a and which value doesn't match.
if a[i] and b[i] doesn't match, they are swappable only if a[i] and b[i] has the same root.
else they are not swappable.
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

class DisjointSet {
    private:
        unordered_map<int, int> parent;
        unordered_map<int, int> rank;
        vector<int> n;
    public:
        DisjointSet(vector<int> &N){
            parent.clear();
            rank.clear();
            n.clear();
            n = N;
            // parent of i is i
            for(int i=0; i<n.size(); i++){
                parent[n[i]] = n[i];
            }
            // rank is 0?
            for(int i=0; i<n.size(); i++){
                rank[n[i]] = 0;
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

int solve(vector<int> &a, vector<int> &b, vector< vector<int> > &c){
    int result = 1;

    DisjointSet dset(a);
    for(int i=0; i<c.size(); i++){
        int to = c[i][0] - 1;
        int from = c[i][1] - 1;
        int toVal = a[to];
        int fromVal = a[from];
        dset.getUnion(toVal, fromVal);
    }
    // for(int i=0; i<a.size(); i++){
    //     cout << a[i] << " -> " << dset.find(a[i]) << endl;
    // }
    for(int i=0; i<a.size(); i++){
        int aval = a[i];
        int bval = b[i];

        if(aval == bval){
            continue;
        } else {
            int arep = dset.find(aval);
            int brep = dset.find(bval);
            if(arep == brep){
                continue;
            } else {
                result = 0;
                break;
            }
        }
    }

    return result;
}

int main(){
    vector<int> a = {1, 3, 2, 4};
    vector<int> b = {1, 4, 2, 3};
    vector< vector<int> > c = {
        {2, 4}
    };
    cout << "Given input is: " << endl;
    printVector(a);
    cout << "Required pattern is: " << endl;
    printVector(b);
    cout << "Given good pairs are: " << endl;
    print2DVector(c);

    int result = solve(a, b, c);
    cout << "Result: " << result << endl;
    return 0;
}

// g++ -std=c++11