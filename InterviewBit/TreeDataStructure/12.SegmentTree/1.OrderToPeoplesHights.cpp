/*
You are given the following :

A positive number N
Heights : A list of heights of N persons standing in a queue
Infronts : A list of numbers corresponding to each person (P) that gives the number of persons who are taller than P and standing in front of P
You need to return  list of actual order of persons’s height

Consider that heights will be unique

Example

Input : 
Heights: 5 3 2 6 1 4
InFronts: 0 1 2 0 3 2
Output : 
actual order is: 5 3 2 1 6 4 
So, you can see that for the person with height 5, there is no one taller than him who is in front of him, and hence Infronts has 0 for him.

For person with height 3, there is 1 person ( Height : 5 ) in front of him who is taller than him.

You can do similar inference for other people in the list.
*/
/*
Solution Approach:
WTF, the same approach ,it is working for him but not for me??
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

vector<int> solve(vector<int> a, vector<int> b){
    int n = a.size();
    vector<int> result(n, -1);
    unordered_map<int, int> mapping;
    for(int i=0; i<a.size(); i++){
        mapping[a[i]] = b[i];
    }

    sort(a.begin(), a.end());

    for(int i=0; i<a.size(); i++){
        int currentValue = a[i];
        int mapValue = mapping[currentValue];
        // cout << "Current Value is: " << currentValue << endl;
        // cout << "Map value is: " << mapValue << endl;
        int peopleBefore = 0;
        for(int j=0; j<result.size(); j++){
            if(peopleBefore == mapValue && result[j] == -1){
                result[j] = currentValue;
                break;
            } else if(peopleBefore == mapValue && result[j] != -1){
                continue;
            } else if(peopleBefore != mapValue && result[j] == -1){
                peopleBefore++;
            } else if(peopleBefore != mapValue && result[j] != -1){
                continue;
            }
        }
    }

    return result;
}

vector<int> solve2(vector<int> &A, vector<int> &B){
    // Create the mapping
    vector<pair<int,int>> v;
    int n=A.size();
    // we store the mapping;
    for(int i=0;i<n;i++){
        v.push_back({A[i],B[i]});
    }

    sort(v.begin(),v.end());
    vector<int> ans(n,0);
    for(int i=0;i<n;i++){
        int j=0;
        int count=0;
        while(count<=v[i].second){
            if(ans[j]==0) count++;
            j++;
        }
        ans[j-1]=v[i].first;
    }
    return ans;
}

int main(){
    vector<int> a = {5, 3, 2, 6, 1, 4};
    vector<int> b = {0, 1, 2, 0, 3, 2};
    cout << "Given heights are : " << endl;
    printVector(a);
    printVector(b);

    vector<int> result = solve2(a, b);
    cout << "Result:" << endl;
    printVector(result);
    return 0;
}

// g++ -std=c++11