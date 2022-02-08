/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

1. Each child must have at least one candy.
2. Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Input Format:

The first and the only argument contains N integers in an array A.
Output Format:

Return an integer, representing the minimum candies to be given.
Example:

Input 1:
    A = [1, 2]

Output 1:
    3

Explanation 1:
    The candidate with 1 rating gets 1 candy and candidate with rating cannot get 1 candy as 1 is its neighbor. 
    So rating 2 candidate gets 2 candies. In total, 2 + 1 = 3 candies need to be given out.

Input 2:
    A = [1, 5, 2, 1]

Output 2:
    7

Explanation 2:
    Candies given = [1, 3, 2, 1]
*/
/*
Solution Approach:
https://afteracademy.com/blog/distribute-candy-problem
1. We will use brute force:
The most straight forward approach for this problem would be to start with distributing one candy to 
each child and then check if any child who has more rating than his one of the neighbours should have more candy 
than its neighbour. 
So, distribute one more candy to that child who does not satisfy the above condition. 
Do this until every child is satisfied.

Solution Steps

Create a 1-D candy array that will represent the number of candies given to each child corresponding to the rating array. 
The question states that each child must have at least one candy so, initialize each index of candy array by one.

Now, iterate over the rating array and check if the ith child rating is higher than (i-1)th child, 
then candy[i] should be greater than candy[i-1] . 
So, update candy[i] = candy[i-1]+1 .
Similarily, if the ith child rating is greater than (i+1)th child, then candy[i] should be greater than candy[i+1] . 
So, update candy[i] = candy[i+1] + 1 .
Do the above two steps until no update in the number of candies required for any child.

Ultimately return the sum of candy array which will be the minimum number of candies required.

Why the hell is n^2 working???????
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

int solve(vector<int> &a){
    int result = 0;

    int n =a.size();
    vector<int> candies(n, 1);
    
    // // forward traverse
    // for(int i=0; i<n-1; i++){
    //     if(a[i+1] > a[i] && candies[i+1] <= candies[i]){
    //         candies[i+1] = candies[i] + 1;
    //     }
    // }

    // cout << "Forward update:" << endl;
    // printVector(candies);

    // // backward traverse
    // for(int i=n-2; i>=0; i--){
    //     // if a[i] > a[i+1] and candies is atmost
    //     if(a[i] > a[i+1] && candies[i] <= candies[i+1]){
    //         candies[i+1] = candies[i] + 1;
    //     } 
    //     // if a[i] == a[i+1] and candies is less
    //     else if(a[i] == a[i+1] && candies[i] < candies[i+1]){
    //         candies[i+1] = candies[i] + 1;
    //     }
    // }
    // cout << "Backward update: " << endl;
    // printVector(candies);

    // for(int i=0; i<candies.size(); i++){
    //     result += candies[i];
    // }

    bool flag = true;
    while(flag){
        flag = false;
        for(int i=0; i<n; i++){
            // compare i and i + 1
            if(i != n-1 && a[i] > a[i+1] && candies[i] <= candies[i+1]){
                candies[i] = candies[i+1] + 1;
                flag = true;
            }

            // compare i and i - 1
            if(i != 0 && a[i] > a[i-1] && candies[i] <= candies[i-1]){
                candies[i] = candies[i-1] + 1;
                flag = true;
            }
        }
    }

    for(int i=0; i<candies.size(); i++){
        result += candies[i];
    }

    return result;
}

int main(){
    vector<int> a = {-255, 369, 319, 77, 128, -202, -147, 282, -26, -489, -443, -401, 385, 465, -134, 126, 304, 179, 16, 112, 473, -467, 279, -233, 66, 76, 408, 148, -369, 328, 138, -164, 492, -276, -326, 170, 168, 189, 13, 383, 341, 426, 219, 337, -62, -197, 263, 338, -324, 261, 273, -74, -8, -133, 318, -100, 487, -196, -465, -495, -136, 94, -201, 491, 204, 323, 156, -337, -99, 115, 179, 184, -249, 76, -396, 265, 500, -83, 270, 438, -418, 401, -184, -247, -203, 190, 191, -282, -248, 465, 146, 7, -381, 326, -409, 474, 186, -206, 447, 17, 156, -273, 381, -307, -206, 164, -147, 58, -224, 284, 204, 267, 123, 141, -8, 225, -246, 12, 399, -261, -104, 191, 390, 152, 313, -91, 8, -476, -363, -183, -280, -282, -431, 366, 89, -166, -257, 132, 98, -387, 389, -219, -332, 227, 386, -33, 361, -308, -494, -33, 110, 423, -465, -417, 496, -333, -259, 402, 36, 380, -385, -329, 283, 389, 396, -161, 466, -405, -293, 442, 259, 377, -386, -386, 329, 204, 438, 346, -185, -401, -219, 213, 351, -18, -20, 364, 319, 187, 197, 122, -182, -126, -211, -448, 44, -360, -345, -147, 480, -387, 222, 92, -262, -409, 163, 323, -291, -61, -431, -288, -309, -490, -494, 328, -207, 398, 475, -228, -37, 44, 227, -371, -91, -440, 220, 39, -73, 80, -189, 37, 94, -96, -400, -380, 172, -179, -442, -119, 411, -184, 218, -18, 170, 430, -157, 345, 418, 390, -39, -85, 216, -197, -421, 328, -311, 160, 432, 104, -419, -140, -115, -202, 58, 415, 473, -87, 475, 430, 114, -314, 430, -419, 375, 258, 255, 42, -63, 54, -352, -337, -180, -31, 441, -382, -176, 209, -137, 171, -89, 155, 421, 308, -153, 254, -210, -245, 373, -435, -29, -398, 326, 297, 81, -157, 254, 52, 479, 356, -497, -16, 109, -353, -20, -122, -172, 23, 20, -344, 203, 372, -306, -9, 238, -190, 495, 9, -2, 125, 150, -180, -340, -1, -347, -269, -181, -15, 83, -304, -365, 490, -475, 161, 422, 440, -414, 380, -446, -404, -352, -144, -297, -62, -23, -223, 359, 127, 183, -20, 93, -285, -477, 223, 1, 131, -359, -74, 321, 197, 452, -338, 367, -337, 183, -41, 218, -75, -212, 208, 188, -38, 91, 332, 388, -185, -247, 405, -390, -371, 313, -471, 457, 307, 494, -467, -225, -3, -271, -164, -120, 101, 385, -12, 234, -368, -317, 167, 241, -494, -279, -288, 452, -499, 372, 464, 234, 16, 40, 264, -474, -400, 429, 33, 495, -285, 201, 190, 328, 127, 286, 312, 100, -24, 409, -392, 183, -69, -352, -56, -304, -261, -296, -140, 453, 253, -215, 195, 288, -300, 10, -104, -491, 275, -275, 175, 24, 387, 408};
    cout << "Given ranking is: " << endl;
    printVector(a);

    int result = solve(a);
    cout << "Given result: " << result << endl;
    return 0;
}

// g++ -std=c++11