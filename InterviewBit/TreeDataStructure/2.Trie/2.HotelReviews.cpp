/*
Problem Description

Given a set of reviews provided by the customers for different hotels and a string containing Good Words, you need to sort the reviews in descending order according to their Goodness Value (Higher goodness value first). We define the Goodness Value of a string as the number of Good Words in that string.

NOTE: Sorting should be stable. If review i and review j have the same Goodness Value then their original order would be preserved.

You are expected to use Trie in an Interview for such problems



Problem Constraints
1 <= No.of reviews <= 200
1 <= No. of words in a review <= 1000
1 <= Length of an individual review <= 10,000
1 <= Number of Good Words <= 10,000
1 <= Length of an individual Good Word <= 4
All the alphabets are lower case (a - z)


Input Format
First argument is a string A containing "Good Words" separated by "_" character

Second argument is a vector B of strings containing Hotel Reviews. Review strings are also separated by "_" character.



Output Format
Return a vector of integers which contain the original indexes of the reviews in the sorted order of reviews.



Example Input
Input 1:

 A = "cool_ice_wifi"
 B = ["water_is_cool", "cold_ice_drink", "cool_wifi_speed"]


Example Output
Output 1:

 [2, 0, 1]


Example Explanation
Explanation 1:

 sorted reviews are ["cool_wifi_speed", "water_is_cool", "cold_ice_drink"]
*/
/*
Solution Approach:
Create a mapping to get the count of number of positive words in the review.
> Problem comes during sorting, we need to implement our own mergesort, that is just painful :(
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
}

void printStrings(vector<string> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << endl;
    }
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

void merge(int low, int mid, int high, vector< vector<int> > &sorted){
    int size = high - low + 1;
    vector< vector<int> > temp(size, vector<int> (2));
    int index = 0;
    int i = low, j= mid +1;
    for(i=low, j=mid+1; i<=mid && j<=high;){
        if(sorted[j][0] > sorted[i][0]){
            // j will come before i
            temp[index][0] = sorted[j][0];
            temp[index][1] = sorted[j][1];
            j++;
            index++;
        } else {
            // i will come before j
            temp[index][0] = sorted[i][0];
            temp[index][1] = sorted[i][1];
            i++;
            index++;
        }
    }

    while(i <= mid){
        temp[index][0] = sorted[i][0];
        temp[index][1] = sorted[i][1];
        i++;
        index++;
    }

    while(j <= high){
        temp[index][0] = sorted[j][0];
        temp[index][1] = sorted[j][1];
        j++;
        index++;
    }

    index = 0;
    for(i=low; i<=high; i++){
        sorted[i][0] = temp[index][0];
        sorted[i][1] = temp[index][1];
        index++;
    }
}

void mergeSort(int low, int high, vector< vector<int> > &sorted){
    if(low >= high){
        return;
    }
    int mid = low + (high - low)/2;
    mergeSort(low, mid, sorted);
    mergeSort(mid + 1, high, sorted);

    // cout our output
    // cout << "low" << endl;
    // for(int i=low; i<=mid; i++){
    //     cout << sorted[i][0] << " " << sorted[i][1] << endl;
    // }
    // cout << "high" << endl;
    // for(int i=mid+1; i<=high; i++){
    //     cout << sorted[i][0] << " " << sorted[i][1] << endl;
    // }

    // merge them
    merge(low, mid, high, sorted);


    // cout << "merged" << endl;
    // for(int i=low; i<=high; i++){
    //     cout << sorted[i][0] << " " << sorted[i][1] << endl;
    // }
    // cout << endl;
}

vector<int> solve(string a, vector<string> b){
    vector<int> result;

    int n = b.size();
    unordered_map<string, int> mapping;
    string temp = "";
    for(int i=0; i<a.size(); i++){
        if(a[i] == '_'){
            mapping[temp]++;
            temp = "";
            continue;
        } else {
            temp.push_back(a[i]);
        }
    }
    mapping[temp]++;
 
    vector< vector<int> > sorted;
    for(int i=0; i<b.size(); i++){
        temp = "";
        int count = 0;

        for(int j=0; j<b[i].size(); j++){
            if(b[i][j] == '_'){
                // not in mapping
                if(mapping.find(temp) != mapping.end()){
                    count++;
                }
                temp = "";
            } else {
                temp.push_back(b[i][j]);
            }
        }
        // for last element
        if(mapping.find(temp) != mapping.end()){
            count++;
        }
        vector<int> temp = {count, i};
        sorted.push_back(temp);
    }
    // Man, now I need to write merge sort for this bugger.
    // Let's revise it.
    int low = 0;
    int high = sorted.size() - 1;
    // cout << "Starting merge sort: " << endl;
    mergeSort(low, high, sorted);
    // cout << endl;
    // cout << "Sorted: " << endl;
    // print2DVector(sorted);
    for(int i=0; i<sorted.size(); i++){
        result.push_back(sorted[i][1]);
    }

    return result;
}

int main(){
    string a = "cool_ice_wifi";
    vector<string> b = {"water_is_cool", "cold_ice_drink", "cool_wifi_speed"};
    cout << "Given cool words are: " << a << endl;
    cout << "Given reviews are : " << endl;
    printStrings(b);
    cout << endl;

    vector<int> result = solve(a, b);
    cout << "Result: " << endl;
    printVector(result);
    return 0;
}

// g++ -std=c++11