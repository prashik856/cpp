/*
Problem Description

Given an integer array A of size N consisting of unique integers from 1 to N. You can swap any two integers atmost B times.

Return the largest lexicographical value array that can be created by executing atmost B swaps.



Problem Constraints
1 <= N <= 106

1 <= B <= 109



Input Format
First argument is an integer array A of size N.

Second argument is an integer B.



Output Format
Return an integer array denoting the largest lexicographical value array that can be created by executing atmost B swaps.



Example Input
Input 1:

 A = [1, 2, 3, 4]
 B = 1
Input 2:

 A = [3, 2, 1]
 B = 2


Example Output
Output 1:

 [4, 2, 3, 1]
Output 2:

 [3, 2, 1]


Example Explanation
Explanation 1:

 In one swap we can swap (1, 4) so that the array becomes : [4, 2, 3, 1].
Explanation 2:

 Array is already the largest lexicographical value array.
*/
/*
No clue how to solve it.
Solution Approach:
https://www.geeksforgeeks.org/largest-permutation-k-swaps/

Efficient approach: 
This is a greedy approach. 
The largest permutation is found when the largest elements are at the front of the array, 
i.e. the largest elements are sorted in decreasing order. 
There are at most k swaps so put the 1st, 2nd, 3rd, …, kth largest element at their respective position.

Note: If the number of swaps allowed is equal to the size of the array, 
then there is no need to iterate over the whole array. 
The answer will simply be the reverse sorted array.

Algorithm: 
-> Create a HashMap or an array of length n to store element-index pair or map element to its index.
-> Now run a loop k times.
-> In each iteration swap the ith element with the element n – i. where i is the index or count of the loop. 
Also swap their position, i.e. update the hashmap or array. 
So in this step the largest element in remaining element is swapped to the front.
-> Print the output array.
Since there are exactly N elements, we can easily get the position of value n-i!
And we can swap n-i and i k times.
Let's try it out!

Take care when we are swapping the maximum value and their positions.
It is very error prone.
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

vector<int> solve(vector<int> &a, int b){
    int n = a.size();
    vector<int> pos(n+1);
    for(int i=0; i<a.size(); i++){
        pos[a[i]] = i;
    }

    int index = 0;
    int count = 0;
    while(count < b && index < n){
        // cout << "Current Index: " << index << endl;
        // if already max, continue
        if(a[index] == n - index){
            // cout << "Given value is current max: " << a[index] << endl;
            index++;
            continue;
        }

        // else swap
        // cout << "Current Max: " << n - index << endl;
        // cout << "Current array value: " << a[index] << endl;
        int val1 = n - index;
        int pos1 = pos[val1];
        
        // swap
        int temp = a[index];
        a[index] = n - index;
        a[pos1] = temp;

        // values after swap
        // cout << "Current Index value: " << a[index] << endl;
        // cout << "Swapped position value: " << a[pos1] << endl;

        // update positions
        pos[n-index] = index;
        pos[temp] = pos1;
        // cout << "Updated Positions 1: " << n-index << " " << index << endl;
        // cout << "Updated Positions 2: " << temp << " " << pos1 << endl;

        // increment count
        count++;
        index++;
        // cout << endl;
    }

    return a;
}

int main(){
    vector<int> a = {3, 2, 4, 1, 5};
    cout << "Given array is: " << endl;
    printVector(a);
    int b = 3;
    cout << "Swaps given is: " << b << endl;

    vector<int> result = solve(a, b);
    cout << "Result: " << endl;
    printVector(result);
    return 0;
}

// g++ -std=c++11