/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,

We get the following sequence (ie, for n = 3 ) :

1. "123"
2. "132"
3. "213"
4. "231"
5. "312"
6. "321"
Given n and k, return the kth permutation sequence.

For example, given n = 3, k = 4, ans = "231"

Good questions to ask the interviewer :

What if n is greater than 10. How should multiple digit numbers be represented in string?
In this case, just concatenate the number to the answer.

 so if n = 11, k = 1, ans = "1234567891011"

Whats the maximum value of n and k?
In this case, k will be a positive integer thats less than INT_MAX.

n is reasonable enough to make sure the answer does not bloat up a lot.
*/
/*
solution approach:
https://www.geeksforgeeks.org/find-the-k-th-permutation-sequence-of-first-n-natural-numbers/

Naive Approach:
To solve the problem mentioned above the simple approach is to find all permutation sequences and output the 
kth out of them. 
But this method is not so efficient and takes more time, hence it can be optimized.

Efficient Approach:
To optimize the above method mentioned above, observe that the value of k can be directly used to find 
the number at each index of the sequence.  

The first position of an n length sequence is occupied by each of the numbers from 1 to n 
exactly n! / n that is (n-1)! number of times and in ascending order. 
So the first position of the kth sequence will be occupied by the number present at index = k / (n-1)! 
(according to 1-based indexing).
The currently found number can not occur again so it is removed from the original n numbers and 
now the problem reduces to finding the ( k % (n-1)! )th permutation sequence of the remaining n-1 numbers.
This process can be repeated until we have only one number left which will be placed in the first position of 
the last 1-length sequence.
The factorial values involved here can be very large as compared to k. 
So, the trick used to avoid the full computation of such large factorials is that as soon as the product 
n * (n-1) * … becomes greater than k, we no longer need to find the actual factorial value because: 

k / n_actual_factorial_value = 0 
and k / n_partial_factorial_value = 0 
when partial_factorial_value > k 
 

The code is kinda important here.
Go through it once to understand properly.
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

void printStrings(vector<string> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << endl;
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

int findFirstIndex(int *k, int n){
    if(n == 1){
        return 0;
    }
    n--;
    int partialFactorial = n;

    while((*k) >= partialFactorial && n > 1){
        partialFactorial = partialFactorial * (n - 1);
        n--;
    }

    int index = (*k) / partialFactorial;
    (*k) = (*k) % partialFactorial;

    return index;
}

string solve(int n, int k){
    string result = "";
    set<int> st;
    for(int i=1; i<=n; i++){
        st.insert(i);
    }

    k--; // zero based indexing

    set<int> :: iterator itr;
    itr = st.begin();

    for(int i=0; i<n; i++){
        int index = findFirstIndex(&k, n-i);
        advance(itr, index);
        result = result + to_string(*itr);
        st.erase(itr);
        itr = st.begin();
    }

    return result;
}

int main(){
    int n = 2;
    int k = 1;

    string result = solve(n, k);
    cout << "Result: " << result << endl;
    return 0;
}

// g++ -std=c++11