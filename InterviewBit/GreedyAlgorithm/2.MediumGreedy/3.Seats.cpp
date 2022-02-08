/*
There is a row of seats. Assume that it contains N seats adjacent to each other. There is a group of people who are already seated in that row randomly. i.e. some are sitting together & some are scattered.

An occupied seat is marked with a character 'x' and an unoccupied seat is marked with a dot ('.')

Now your target is to make the whole group sit together i.e. next to each other, without having any vacant seat between them in such a way that the total number of hops or jumps to move them should be minimum.

Return minimum value % MOD where MOD = 10000003

Example

Here is the row having 15 seats represented by the String (0, 1, 2, 3, ......... , 14) -

              . . . . x . . x x . . . x . .

Now to make them sit together one of approaches is -
                  . . . . . . x x x x . . . . .

Following are the steps to achieve this -
1 - Move the person sitting at 4th index to 6th index -  
    Number of jumps by him =   (6 - 4) = 2

2 - Bring the person sitting at 12th index to 9th index - 
    Number of jumps by him = (12 - 9) = 3

So now the total number of jumps made = 
    ( 2 + 3 ) % MOD = 
    5 which is the minimum possible jumps to make them seat together.

There are also other ways to make them sit together but the number of jumps will exceed 5 and that will not be minimum.

For example bring them all towards the starting of the row i.e. start placing them from index 0. 
In that case the total number of jumps will be 
    ( 4 + 6 + 6 + 9 )%MOD 
    = 25 which is very costly and not an optimized way to do this movement

*/
/*
Solution Approach: 
https://www.geeksforgeeks.org/minimum-jumps-required-to-make-a-group-of-persons-sit-together/
Approach: 
The idea is to use a Greedy Approach to solve this problem. 
Observe that it is always optimal to shift the elements towards the median element among the persons or 
the center person among all the persons present. 
The number of jumps will always be minimum when we shift points to the median. 

Below are the steps:
-> Initialize a vector position to store the indexes of the persons present.
-> Find the median of the vector position[]. All the other persons will now be made to sit around this person as this will give the minimum number of jumps that are required to be made.
-> Initialize a variable ans that stores the minimum jumps required.
-> Now, traverse the vector position[] and for every index i find the median element and update ans as:
ans= ans+ abs(position[i] – medianElement)

-> After the above steps, print the value of ans as the result.

// Interesting way to solve this problem.
-> As mentioned, we initialize a vector.
First, traverse through the array, and keep count of number of seats occupied.
And inside the position vector, rather than pushing index, push index - count.
Why? -> This is because it will help us get our answer more easily.
-> We need a difference between median element and the seat position.
-> By keeping index - count, if elements are consicutive, the value stored are same, and that's what we want.
Interesing man!
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

int solve(string a){
    int result = 0;
    int MOD = 10000003;

    vector<int> position;
    int n = a.size();


    // first traverse of array
    // Store the value of i - count rather than i.
    int count = 0;
    for(int i=0; i<n; i++){
        if(a[i] == 'x'){
            position.push_back(i - count);
            count++;
        }
    }

    // base case
    if(count == n || count == 0){
        return 0;
    }

    // get the median value index
    int medianIndex = (count - 1)/2;
    // get median value
    int medianValue = position[medianIndex];

    long tempAns = 0;
    // Second traverse to get the answer
    for(int i=0; i<position.size(); i++){
        // Get the hop value
        long diff = abs(position[i] - medianValue);

        // add it to our answer
        tempAns = tempAns + diff;

        // get int value
        tempAns = tempAns % MOD;
    }
    tempAns = tempAns % MOD;
    result = tempAns;

    return result;
}

int main(){
    string a = "....x..xx...x.";
    cout << "Given input string is: " << a << endl;

    int result = solve(a);
    cout << "Result: " << result << endl;
    return 0;
}

// g++ -std=c++11