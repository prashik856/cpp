/*
Problem Description

Given a binary tree A consisting of N nodes, return a 2-D array denoting 
the vertical order traversal of A.

Go through the example and image for more details.

NOTE:

If 2 or more Tree Nodes shares the same vertical level then the one with earlier occurence in the pre-order traversal of tree comes first in the output.
Row 1 of the output array will be the nodes on leftmost vertical line similarly last row of the output array will be the nodes on the rightmost vertical line.


Problem Constraints
0 <= N <= 104



Input Format
First and only argument is an pointer to root of the binary tree A.



Output Format
Return a 2D array denoting the vertical order traversal of A.



Example Input
Input 1:

      6
    /   \
   3     7
  / \     \
 2   5     9
Input 2:

           1
         /   \
        2     3
       / \
      4   5


Example Output
Output 1:

 [
    [2],
    [3],
    [6, 5],
    [7],
    [9]
 ]
Output 2:

 [
    [4],
    [2],
    [1, 5],
    [3]
 ]


Example Explanation
Explanation 1:

 
 Nodes on Vertical Line 1: 2
 Nodes on Vertical Line 2: 3
 Nodes on Vertical Line 3: 6, 5
    As 6 and 5 are on the same vertical level but as 6 comes first in the pre-order traversal of the tree so we will output 6 before 5.
 Nodes on Vertical Line 4: 7
 Nodes on Vertical Line 5: 9
Explanation 2:

 Nodes on Vertical Line 1: 4
 Nodes on Vertical Line 2: 2
 Nodes on Vertical Line 3: 1, 5
 Nodes on Vertical Line 4: 3
*/
/*
Solution approach:
Create a graph first using the given number of nodes.
Then, we need to do BFS from the left most node.
Before storing the values in the vector, we need to make sure that they are inserted using preOrder traversal values.

Man, what a stupid question.

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

unordered_map<int, vector<TreeNode *> > lengthMapping;
void createGraphFromTree(TreeNode *root, 
    int *maxLength,
    int *minLength,
    int currentLength
    ){
    // if root is null, return
    if(root == 0){
        return;
    }

    // cout << "Current Length is: " << currentLength << endl;
    int parent = root -> val;
    vector<TreeNode *> mapValue = lengthMapping[currentLength];
    // cout << "Current Length: " << currentLength << endl;
    if(mapValue.size() == 0){
        // cout << "Not in map" << endl;
        vector<TreeNode *> temp;
        temp.push_back(root);
        lengthMapping[currentLength] = temp;
    } else {
        // cout << "In Map" << endl;
        mapValue.push_back(root);
        lengthMapping[currentLength] = mapValue;
    }
    // cout << endl;

    // get maxLength
    if(currentLength > *maxLength){
        *maxLength = currentLength;
    }

    // get minLength
    if(currentLength < *minLength){
        *minLength = currentLength;
    }

    createGraphFromTree(root -> left, maxLength, minLength, currentLength + 1);
    createGraphFromTree(root -> right, maxLength, minLength, currentLength - 1);
}

vector< vector<int> > solve(TreeNode *root){
    vector< vector<int> > result;
    if(root == 0){
        return result;
    }
    int N = 10001;
    int maxLength = INT_MIN;
    int minLength = INT_MAX;
    int currentLength = 0;
    lengthMapping.clear();
    // need to do bfs first, and get their order.
    queue<TreeNode *> qt;
    unordered_map<TreeNode*, vector<int> > mapping;
    TreeNode *temp;
    qt.push(root);
    int count = 0;
    while(!qt.empty()){
        temp = qt.front();
        count++;
        vector<int> mapValue = {count, temp -> val};
        mapping[temp] = mapValue;
        if(temp -> left != 0){
            qt.push(temp -> left);
        }
        if(temp -> right != 0){
            qt.push(temp -> right);
        }
        qt.pop();
    }
    // Now, we have stored the count value and it's int value as well.
    // That too for every node.

    // create graph
    createGraphFromTree(root, &maxLength, &minLength, currentLength);
    // cout << "MaxLegth : " << maxLength << endl;
    // cout << "MinLength : " << minLength << endl;
    
    for(int i=maxLength; i>=minLength; i--){
        vector<TreeNode *> mapValue = lengthMapping[i];
        vector< vector<int> > someVector;
        if(mapValue.size() > 0){
            for(int j=0; j<mapValue.size(); j++){
                TreeNode *currentNode = mapValue[j];
                // cout << "Current Node is: " << currentNode -> val << " ";
                vector<int> rankVector = mapping[currentNode];
                someVector.push_back(rankVector);
            }
            sort(someVector.begin(), someVector.end());
            vector<int> resultVector;
            for(int j=0; j<someVector.size(); j++){
                resultVector.push_back(someVector[j][1]);
            }
            result.push_back(resultVector);
            // cout << endl;
        }
    }

    return result;
}

int main(){
    int rootNode = 19;
    vector<int> a = {1,2,3,4,5, 34, 23, 2, 34, 9, 39, 90, 63, 63, 24, 95, 221, 23};
    TreeNode *root = createTree(rootNode, a);
    cout << "Given tree is: " << endl;
    inOrder(root); cout << endl;

    vector< vector<int> > result = solve(root);
    cout << "Result: " << endl; 
    print2DVector(result);
    return 0;
}

// g++ -std=c++11