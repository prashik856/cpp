/*
Given any source point, (C, D) and destination point, (E, F) on a chess board, we need to find whether Knight can move to the destination or not.

Knight's movements on a chess board

The above figure details the movements for a knight ( 8 possibilities ).

If yes, then what would be the minimum number of steps for the knight to move to the said point.

If knight can not move from the source point to the destination point, then return -1.

Note: A knight cannot go out of the board.



Input Format:

The first argument of input contains an integer A.
The second argument of input contains an integer B.
    => The chessboard is of size A x B.
The third argument of input contains an integer C.
The fourth argument of input contains an integer D.
    => The Knight is initially at position (C, D).
The fifth argument of input contains an integer E.
The sixth argument of input contains an integer F.
    => The Knight wants to reach position (E, F).
Output Format:

If it is possible to reach the destination point, return the minimum number of moves.
Else return -1.
Constraints:

1 <= A, B <= 500
Example

Input 1:
    A = 8
    B = 8
    C = 1
    D = 1
    E = 8
    F = 8
    
Output 1:
    6

Explanation 1:
    The size of the chessboard is 8x8, the knight is initially at (1, 1) and the knight wants to reach position (8, 8).
    The minimum number of moves required for this is 6.
*/
/*
Solution approach:
Use BFS. 
We visited the current node and keep track of it's distance.
If node is unvisited, visit it.
If node is visited, visit it iff currentDistance + 1 < distance[node]
return destination distance
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

void customBFS(int c, 
    int d, 
    vector< vector<bool> >&visited, 
    vector< vector<int> >&distance, 
    int currentDistance ){
        // limits
        int rowMax = visited.size();
        int colMax = visited[0].size();
        queue< vector<int> > q;
        vector<int> temp = {c, d, currentDistance};
        q.push(temp);
        visited[c][d] = true;
        distance[c][d] = currentDistance;

        // while q is non empty
        while(!q.empty()){
            vector<int> front = q.front();
            q.pop();
            int i = front[0];
            int j = front[1];
            int k = front[2];

            int row,col;
            row = i + 2; col = j - 1;
            if(row >= 0 && row < rowMax && col >=0 && col < colMax){
                if(!visited[row][col]){
                    visited[row][col] = true;
                    distance[row][col] = k + 1;
                    // push in queue
                    temp = {row, col, k + 1};
                    q.push(temp);

                } else {
                    // point is already visited
                    // visited this point iff currentDistance + 1 < distance[row][col]
                    if(k + 1 < distance[row][col]){
                        distance[row][col] = k + 1;
                        temp = {row, col, k+1};
                        q.push(temp);
                    }
                }
            }

            row = i + 2; col = j + 1;
            if(row >= 0 && row < rowMax && col >=0 && col < colMax){
                if(!visited[row][col]){
                    visited[row][col] = true;
                    distance[row][col] = k + 1;
                    // push in queue
                    temp = {row, col, k + 1};
                    q.push(temp);

                } else {
                    // point is already visited
                    // visited this point iff currentDistance + 1 < distance[row][col]
                    if(k + 1 < distance[row][col]){
                        distance[row][col] = k + 1;
                        temp = {row, col, k+1};
                        q.push(temp);
                    }
                }
            }

            row = i - 2; col = j - 1;
            if(row >= 0 && row < rowMax && col >=0 && col < colMax){
                if(!visited[row][col]){
                    visited[row][col] = true;
                    distance[row][col] = k + 1;
                    // push in queue
                    temp = {row, col, k + 1};
                    q.push(temp);

                } else {
                    // point is already visited
                    // visited this point iff currentDistance + 1 < distance[row][col]
                    if(k + 1 < distance[row][col]){
                        distance[row][col] = k + 1;
                        temp = {row, col, k+1};
                        q.push(temp);
                    }
                }
            }

            row = i - 2; col = j + 1;
            if(row >= 0 && row < rowMax && col >=0 && col < colMax){
                if(!visited[row][col]){
                    visited[row][col] = true;
                    distance[row][col] = k + 1;
                    // push in queue
                    temp = {row, col, k + 1};
                    q.push(temp);

                } else {
                    // point is already visited
                    // visited this point iff currentDistance + 1 < distance[row][col]
                    if(k + 1 < distance[row][col]){
                        distance[row][col] = k + 1;
                        temp = {row, col, k+1};
                        q.push(temp);
                    }
                }
            }

            row = i - 1; col = j + 2;
            if(row >= 0 && row < rowMax && col >=0 && col < colMax){
                if(!visited[row][col]){
                    visited[row][col] = true;
                    distance[row][col] = k + 1;
                    // push in queue
                    temp = {row, col, k + 1};
                    q.push(temp);

                } else {
                    // point is already visited
                    // visited this point iff currentDistance + 1 < distance[row][col]
                    if(k + 1 < distance[row][col]){
                        distance[row][col] = k + 1;
                        temp = {row, col, k+1};
                        q.push(temp);
                    }
                }
            }

            row = i + 1; col = j + 2;
            if(row >= 0 && row < rowMax && col >=0 && col < colMax){
                if(!visited[row][col]){
                    visited[row][col] = true;
                    distance[row][col] = k + 1;
                    // push in queue
                    temp = {row, col, k + 1};
                    q.push(temp);

                } else {
                    // point is already visited
                    // visited this point iff currentDistance + 1 < distance[row][col]
                    if(k + 1 < distance[row][col]){
                        distance[row][col] = k + 1;
                        temp = {row, col, k+1};
                        q.push(temp);
                    }
                }
            }

            row = i - 1; col = j - 2;
            if(row >= 0 && row < rowMax && col >=0 && col < colMax){
                if(!visited[row][col]){
                    visited[row][col] = true;
                    distance[row][col] = k + 1;
                    // push in queue
                    temp = {row, col, k + 1};
                    q.push(temp);

                } else {
                    // point is already visited
                    // visited this point iff currentDistance + 1 < distance[row][col]
                    if(k + 1 < distance[row][col]){
                        distance[row][col] = k + 1;
                        temp = {row, col, k+1};
                        q.push(temp);
                    }
                }
            }

            row = i + 1; col = j - 2;
            if(row >= 0 && row < rowMax && col >=0 && col < colMax){
                if(!visited[row][col]){
                    visited[row][col] = true;
                    distance[row][col] = k + 1;
                    // push in queue
                    temp = {row, col, k + 1};
                    q.push(temp);

                } else {
                    // point is already visited
                    // visited this point iff currentDistance + 1 < distance[row][col]
                    if(k + 1 < distance[row][col]){
                        distance[row][col] = k + 1;
                        temp = {row, col, k+1};
                        q.push(temp);
                    }
                }
            }
        }
}

int solve(int a, int b, int c, int d, int e, int f) {
    int result = 0;

    // Create visited vector
    vector< vector<bool> > visited(a, vector<bool>(b, false));
    vector< vector<int> > distance(a, vector<int>(b, INT_MAX));
    // zero indexed
    // knight position
    c--;
    d--;
    // final position
    e--;
    f--;

    customBFS(c,d,visited,distance,0);
    // print2DVector(distance);
    if(distance[e][f] == INT_MAX){
        result = -1;
    } else {
        result = distance[e][f];
    }

    return result;
}

int main(){
    int a = 500;
    int b = 500;
    int c = 1;
    int d = 1;
    int e = 500;
    int f = 500;

    cout << "Given Board size is: " << a << "," << b << endl;
    cout << "Given Knight position is: " << c << "," << d << endl;
    cout << "Given destination is: " << e << "," << f << endl;

    int result = solve(a, b, c, d, e, f);
    cout << "Result: " << result << endl;
    return 0;
}

// g++ -std=c++11