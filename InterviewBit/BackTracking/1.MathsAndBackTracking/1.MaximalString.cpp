/*
Problem Description

Given a string A and integer B, what is maximal lexicographical stringthat can be made from A if you do atmost B swaps.



Problem Constraints
1 <= |A| <= 9

A contains only digits from 0 to 9.

1 <= B <= 5



Input Format
First argument is string A.

Second argument is integer B.



Output Format
Return a string, the naswer to the problem.



Example Input
Input 1:

A = "254"
B = 1
Input 2:

A = "254'
B = 2


Example Output
Output 1:

 524
Output 2:

 542


Example Explanation
Explanation 1:

 Swap 2 and 5.
Explanation 2:

Swap 2 and 5 then swap 4 and 2.
*/
/*
Solution approach:
https://www.geeksforgeeks.org/find-maximum-number-possible-by-doing-at-most-k-swaps/
Naive Solution:
Approach: 
The idea is to consider every digit and swap it with digits following it one at a time and see if it leads to the 
maximum number. 
The process is repeated K times. 
The code can be further optimized, if the current digit is swapped with a digit less than the following digit.
Algorithm:  
-> Create a global variable which will store the maximum string or number.
-> Define a recursive function that takes the string as number and value of k
-> Run a nested loop, the outer loop from 0 to length of string -1 and inner loop from i+1 to end of the string.
-> Swap the ith and jth character and check if the string is now maximum and update the maximum string.
-> Call the function recursively with parameters: string and k-1.
-> Now again swap back the ith and jth character.


Efficient Solution:
Approach: 
The above approach traverses the whole string at each recursive call which is highly inefficient and unnecessary. 
Also, pre-computing the maximum digit after the current at a recursive call avoids unnecessary exchanges with each digit. 
It can be observed that to make the maximum string, the maximum digit is shifted to the front. 
So, instead of trying all pairs, try only those pairs where one of the elements is the maximum digit which is not 
yet swapped to the front. 
There is an improvement by 27580 microseconds for each test case.
Algorithm:  

Create a global variable which will store the maximum string or number.
Define a recursive function that takes the string as a number, the value of k, and the current index.
Find the index of the maximum element in the range current index to end.
if the index of the maximum element is not equal to the current index then decrement the value of k.
Run a loop from the current index to the end of the array
If the ith digit is equal to the maximum element
Swap the ith and element at the current index and check if the string is now maximum and update the maximum string.
Call the function recursively with parameters: string and k.
Now again swap back the ith and element at the current index.




Got it..
So, during recursion, when we find the maxvalue, we need to take every possible 
swap of the maxValues.
And when we are swapping, we have to take into account all the next recursion after a given swap.
That's why we call a recursive function in every for loop.
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

string maxString = "";
void getResult(string &a, int b, int low, int high) {
    if(b == 0){
        return;
    }

    if(low >= high){
        return;
    }

    char maxValue = a[low];
    int maxIndex = low;

    // find the max value
    for(int i=low+1; i<=high; i++){
        if(a[i] > maxValue){
            maxValue = a[i];
            maxIndex = i;
        }
    }

    // if max value changes, swap
    if(maxIndex != low){
        b--;
    }

    // Check all possible combinations of swap
    for(int i=high; i>=low + 1; i--){
        // swap if a[i] value is equal to maxValue
        if(a[i] == maxValue){
            // swap
            char temp = a[low];
            a[low] = a[i];
            a[i] = temp;

            // update maxString
            if(a.compare(maxString) > 0){
                maxString = a;
            }

            // go ahead with next recursion
            getResult(a, b, low + 1, high);

            // backtrack
            temp = a[i];
            a[i] = a[low];
            a[low] = temp;
        }
    }
}

string solve(string a, int b){
    maxString = a;
    int low = 0;
    int high = a.size() - 1;
    getResult(a, b, low, high);
    return maxString;
}

int main(){
    string a = "129814999";
    int b = 4;

    string result = solve(a, b);
    cout << "Result: " << maxString << endl;
    return 0;
}

// g++ -std=c++11