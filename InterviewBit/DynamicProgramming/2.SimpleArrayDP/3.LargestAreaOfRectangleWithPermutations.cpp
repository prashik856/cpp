/*
Problem Description

Given a binary grid A of size N x M consisting of 0's and 1's, find the area of the largest rectangle inside the grid such that all the cells inside the chosen rectangle should have 1 in them.

You are allowed to permutate the columns matrix i.e. you can arrange each of the column in any order in the final grid.

Please follow the sample input and explanation for more clarity.



Input Format
First and only argument is an 2D binary array A.



Output Format
Return a single integer denoting the area of the largest rectangle inside the grid such that all the cells inside the chosen rectangle should have 1 in them.



Example Input
Input 1:

 A = [  [1, 0, 1]
        [0, 1 ,0]
        [1, 0, 0]
    ]


Example Output
Output 1:

 2


Example Explanation
Explanation 1:

    1 0 1
    0 1 0
    1 0 0


At present we can see that max rectangle satisfying the criteria mentioned in the problem
 is of 1 * 1 = 1 area i.e either of the 4 cells which contain 1 in it.



Now since we are allowed to permutate the columns of the given matrix, we can take column 1
 and column 3 and make them neighbours. One of the possible configuration of the grid can be:
 1 1 0
 0 0 1
 1 0 0



Now In this grid, first column is column 1, second column is column 3 and third column
 is column 2 from the original given grid.



Now, we can see that if we calculate the max area rectangle, we get max area as 1 * 2 = 2
 which is bigger than the earlier case. Hence 2 will be the answer in this case.
*/
/*
Solution Approach:
Why the fuck interview bit doesn't give limits?
Fucking sucks man!

One of the solutions:
int Solution::solve(vector<vector<int>> &mat) {
 
     
      int m=mat.size();
      if(m==0)
      {
          return 0;
      }
      int n=mat[0].size();

      // Firstly we add the values in vertical column for rach column
      // if any value is 0 , then put 0 there

      //[1 , 0 , 0]                    [1 , 0 , 0]
      //[1 , 1 , 1]  ---> After adding [2 , 1 , 1]
      //[1 , 0 , 1]                    [3 , 0 , 2]
      //[0 , 1 , 1]                    [0 , 1 , 3]

      // this is 4 by 3 matrix

      // Now apply the permutation property , as each row has no
      // of consecutive ones it has above it

      // sort it , as most ones containing should be together

      // [0 , 0 , 1]
      // [1 , 1 , 2]
      // [0 , 2 , 3]
      // [0 , 1 , 3]

      // calculate the area for each row and take maximum of it

      for(int i=1;i<m;i++)
      {
          for(int j=0;j<n;j++)
          {
              if(mat[i][j]!=0)
              {
                  mat[i][j]+=mat[i-1][j];
                  // adding from previous row
              }
          }
      }

      for(auto &x : mat)
      {
          sort(x.begin(),x.end());
      }

      int max_area=0 , curr_area = 0 , width =1;

      for(int i=0;i<m;i++)
      {
          width=1;
          for(int j=n-1;j>=0;j--)
          {
              curr_area=width*mat[i][j];
              width++; //  incerase the width as moving right to left
              // [ 0 , 2 , 3]
        // width = 3 ,w=2 ,w = 1
              max_area=max(max_area , curr_area);
          }
      }

      return max_area;

}

We need to use greedy approach for this.
No need to use Dynamic programming.

Algo:
1. Get the consicutive rows. If any row value is 0, keep it as zero.
2. Once we add rows, we then sort all the rows. (Why are we sorting the rows? -> It will bring all consecutive ones together)
3. Then, calculate the area of each row and take the maximum
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

int solve(vector< vector<int> > &A) {
    int result = 0;

    int n = A.size();
    // Number of columns are 0
    if(A[0].size() == 0){
        return 0;
    }
    int m = A[0].size();

    // Get consicutive rows
    for(int i=1; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(A[i][j] != 0){
                A[i][j] = A[i][j] + A[i-1][j];
            }
        }
    }

    // cout << "Updated Matrix is: " << endl;
    // print2DVector(A);

    // cout << "Sorting every row to brings 1s together" << endl;
    for(int i=0; i<n; i++){
        sort(A[i].begin(), A[i].end());
    }

    // cout << "Matrix after sorting: " << endl;
    // print2DVector(A);

    // cout << "Calculating maximum area of each row" << endl;
    int max_area = 0, curr_area = 0, width = 1;
    for(int i=0; i<n; i++) {
        width = 1;
        curr_area = 0;
        // start from the left
        for(int j=m-1; j>=0; j--) {
            curr_area = width * A[i][j];
            max_area = max(max_area, curr_area);
            width++;
        }
    }
    result = max_area;
    return result;
}

int main(){
    vector< vector<int> > a = {
        {1,0,1},
        {0,1,0},
        {1,0,0}
    };
    cout << "Given input matrix is: " << endl;
    print2DVector(a);

    int result = solve(a);
    cout << "Result: " << result << endl; 
    return 0;
}

// g++ -std=c++11