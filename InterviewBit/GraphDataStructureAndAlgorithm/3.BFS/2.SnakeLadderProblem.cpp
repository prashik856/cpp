/*
Problem Description

Rishabh takes out his Snakes and Ladders Game, stares the board and wonders: "If I can always roll the die to whatever number I want, what would be the least number of rolls to reach the destination?"

RULES:

The game is played with cubic dice of 6 faces numbered from 1 to A.
Starting from 1 , land on square 100 with the exact roll of the die. If moving the number rolled would place the player beyond square 100, no move is made.
If a player lands at the base of a ladder, the player must climb the ladder. Ladders go up only.
If a player lands at the mouth of a snake, the player must go down the snake and come out through the tail. Snakes go down only.
BOARD DESCRIPTION:

The board is always 10 x 10 with squares numbered from 1 to 100.
The board contains N ladders given in a form of 2D matrix A of size N * 2 where (A[i][0], A[i][1]) denotes a ladder that has its base on square A[i][0] and end at square A[i][1].
The board contains M snakes given in a form of 2D matrix B of size M * 2 where (B[i][0], B[i][1]) denotes a snake that has its mouth on square B[i][0] and tail at square B[i][1].


Problem Constraints
1 <= N, M <= 15

1 <= A[i][0], A[i][1], B[i][0], B[i][1] <= 100

A[i][0] < A[i][1] and B[i][0] > B[i][1]

Neither square 1 nor square 100 will be the starting point of a ladder or snake.

A square will have at most one endpoint from either a snake or a ladder.



Input Format
First argument is a 2D matrix A of size N * 2 where (A[i][0], A[i][1]) denotes a ladder that has its base on square A[i][0] and end at square A[i][1].

Second argument is a 2D matrix B of size M * 2 where (B[i][0], B[i][1]) denotes a snake that has its mouth on square B[i][0] and tail at square B[i][1].



Output Format
Return the least number of rolls to move from start to finish on a separate line. If there is no solution, return -1.



Example Input
Input 1:

 A = [  [32, 62]
        [42, 68]
        [12, 98]
     ]
 B = [  [95, 13]
        [97, 25]
        [93, 37]
        [79, 27]
        [75, 19]
        [49, 47]
        [67, 17]
Input 2:

 A = [  [8, 52]
        [6, 80]
        [26, 42]
        [2, 72]
     ]
 B = [  [51, 19]
        [39, 11]
        [37, 29]
        [81, 3]
        [59, 5]
        [79, 23]
        [53, 7]
        [43, 33]
        [77, 21] 


Example Output
Output 1:

 3
Output 2:

 5


Example Explanation
Explanation 1:

 The player can roll a 5 and a 6 to land at square 12. There is a ladder to square 98. A roll of 2 ends the traverse in 3 rolls.


Explanation 2:

 The player first rolls 5 and climbs the ladder to square 80. Three rolls of 6 get to square 98.
 A final roll of 2 lands on the target square in 5 total rolls.
*/
/*
Simple Dijkstras Algo
-> Need to create a weight vector
-> Need to create visited vector
-> When running dijkstra's algo, we need to get the index of node with minimum distance
-> Run for all nodes.
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

int getMinDistRoot(vector<int> &dist, vector<bool> &visited){
    int minValue = INT_MAX;
    int minValueIndex = -1;
    for(int i=0; i<dist.size(); i++){
        if(!visited[i] && dist[i] < minValue){
            minValue = dist[i];
            minValueIndex = i;
        }
    }
    return minValueIndex;
}

int solve(vector< vector<int> >&a, vector< vector<int> >&b){
    int result = 0;
    vector< vector<int> > adj(101, vector<int>());
    unordered_map<int, int> ladders;
    unordered_map<int, int> snakes;
    vector< vector<int> > weight(101, vector<int>(101, 0));
    // setup ladders
    for(int i=0; i<a.size(); i++){
        int to = a[i][0];
        int from = a[i][1];
        ladders[to] = from;
    }

    // setup snakes
    for(int i=0; i<b.size(); i++){
        int to = b[i][0];
        int from = b[i][1];
        snakes[to] = from;
    }
    // setup all nodes
    for(int i=1; i<101; i++){
        // a ladder. need to go up
        if(ladders[i] != 0){
            adj[i].push_back(ladders[i]);
            continue;
        }
        // a snake, go down
        if(snakes[i] != 0){
            adj[i].push_back(snakes[i]);
            continue;
        }
        // 1
        if(i+1 < 101){
            adj[i].push_back(i+1);
            weight[i][i+1] = 1;
        }

        // 2
        if(i+2<101){
            adj[i].push_back(i+2);
            weight[i][i+2] = 1;
        }

        // 3
        if(i+3<101){
            adj[i].push_back(i+3);
            weight[i][i+3] = 1;
        }

        // 4
        if(i+4<101){
            adj[i].push_back(i+4);
            weight[i][i+4] = 1;
        }

        // 5
        if(i+5<101){
            adj[i].push_back(i+5);
            weight[i][i+5] = 1;
        }

        // 6
        if(i+6<101){
            adj[i].push_back(i+6);
            weight[i][i+6] = 1;
        }
    }
    
    // cout << "The board is: " << endl;
    // for(int i=0; i<101; i++){
    //     cout << i << " -> ";
    //     for(int j=0; j<adj[i].size(); j++){
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int root = 1;
    int target = 100;
    vector<int> dist(101, INT_MAX);
    vector<bool> visited(101, false);
    dist[root] = 0;

    for(int i=1; i<101; i++){
        int currentRoot = getMinDistRoot(dist, visited);
        if(currentRoot == -1){
            break;
        }
        int currentDistance = dist[currentRoot];
        visited[currentRoot] = true;

        for(int i=0; i<adj[currentRoot].size(); i++){
            int currentNeighbour = adj[currentRoot][i];
            if( !visited[currentNeighbour] && (dist[currentNeighbour] > currentDistance + weight[currentRoot][currentNeighbour])){
                dist[currentNeighbour] = currentDistance + weight[currentRoot][currentNeighbour];
            }
        }
    }
    // cout << "Final dist: " << endl;
    // for(int i=0; i<101; i++){
    //     cout << i << " -> " << dist[i] << endl;
    // }

    result = dist[100];
    if(result == INT_MAX){
        return -1;
    }
    return result;
}

int main(){
    vector< vector<int> > a = {
        {3, 54},
        {37, 100}
        };
    vector< vector<int> > b = {
        {56, 33}
    };
    cout << "Given ladders are: " << endl;
    print2DVector(a);

    cout << "Given snakes are: " << endl;
    print2DVector(b);

    int result = solve(a, b);
    cout << "result: " << result << endl;
    return 0;
}

// g++ -std=c++11