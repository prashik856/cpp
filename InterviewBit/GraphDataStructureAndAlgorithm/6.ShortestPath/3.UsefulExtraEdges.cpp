/*
Given a graph of A nodes. Also given the weighted edges in the form of array B.

You are also given starting point C and destination point D.

Also given are some extra edges in the form of vector E.

You need to find the length of the shortest path from C to D if you can use maximum one road from the given roads in E.

All roads are bidirectional.



Problem Constraints
1 <= A <= 100000

1 <= |B| <= 100000

1 <= C, D <= A

1 <= |E| <= 300

All lengths of the roads lie between 1 and 1000.



Input Format
First argument is the integer A.

Second argument is the vector of vectors B.

Third argument is the integer C.

Fourth argument is the integer D.

Fifth argument is the vector of vectors E.



Output Format
Return -1 if C is not reachable from D. Else return the shortest distance between them.



Example Input
Input 1:

 A = 3
B = [   [1, 2, 1]
        [2, 3, 2]
    ]
C = 1
D = 3
E = [   [1, 3, 2]
    ]
Input 2:

 A = 4
B = [   [1, 2, 1]
        [2, 3, 2]
        [3, 1, 4]
    ]
C = 1
D = 4
E = [   [1, 3, 2]
    ]


Example Output
Output 1:

 2
Output 2:

 -1


Example Explanation
Explanation 1:

 Use the direct edge from 1 to 3. It has shortest path from 1 to 3.
Explanation 2:

 4 cannot be reached from 1.
*/
/*
Solution Approach:
We first need to run two dijkstras algorithms
One from source and get distance matrix for it.
One from destination and get distance matrix for it.
If any node is not reachable, it's distance should be stored as INT_MAX

After this, store our result as distSource[destination] // initial result
Now, for every extra extra edge, we need to see if our resulting distance will be smaller.
And since this is bidirectional, we need to check from to directions.

Case 1:
from e[0] to e[1]
Cost from source to e[0] = distSource[e[0]]
Cost from distination to e[1] = destSource[e[1]]
Cost from e[0] to e[1] = e[3]
if distSource[e[0]] and destSource[e[1]] != INT_MAX
temp = distSource[e[0]] + destSource[e[1]] + e[3]
result = min(result, temp)

And vice versa here.
Case 2:
from e[1] to e[0]

we return our result as result if it isn't equal to INT_MAX, else return INT_MAX
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

vector<int> runDijkstras(int source, vector< vector< pair<int, int> > > &adj){
    vector<int> dist(adj.size(), INT_MAX);
    vector<bool> visited(adj.size(), false);
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;

    dist[source] = 0;
    pair<int, int> temp = {dist[source], source};
    pq.push(temp);

    // run while pq. is non empty
    while(!pq.empty()){
        pair<int, int> top = pq.top();
        pq.pop();

        int root = top.second;
        int rootDistance = top.first;
        if(visited[root]){
            continue;
        }
        // cout << "Visiting node: " << root << endl;
        visited[root] = true;

        for(int i=0; i<adj[root].size(); i++){
            pair<int,int> neighbourPair = adj[root][i];
            int neighbour = neighbourPair.first;
            int neighbourCost = neighbourPair.second;
            // not visited
            if(!visited[neighbour]){
                if(rootDistance + neighbourCost < dist[neighbour]){
                    // cout << "Pushing neighbour : " << neighbour << endl;
                    // calculate distance
                    dist[neighbour] = rootDistance + neighbourCost;
                    // update 
                    temp = {dist[neighbour], neighbour};
                    // push into pq
                    pq.push(temp);
                }
            }
        }
    }

    return dist;
}

int solve(int a, 
    vector< vector<int> > &b,
    int c,
    int d,
    vector< vector<int> > &e) {
    int result = INT_MAX;

    vector< vector< pair<int, int> > > adj(a+1, vector< pair<int, int> >());
    // Create adjacency matrix
    for(int i=0; i<b.size(); i++){
        int from = b[i][0];
        int to = b[i][1];
        int cost = b[i][2];
        pair<int,int> temp;
        // Create pair
        // from to to
        temp.first = to;
        temp.second = cost;
        adj[from].push_back(temp);
        // to to from
        temp.first = from;
        temp.second = cost;
        adj[to].push_back(temp);
    }

    // cout << "Our adjacency matrix: " << endl;
    // for(int i=0; i<adj.size(); i++){
    //     cout << i << " -> ";
    //     for(int j=0; j<adj[i].size(); j++){
    //         pair<int, int> temp = adj[i][j];
    //         cout << temp.first << "|" << temp.second << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // Adjacency matrix is created
    vector<int> distC = runDijkstras(c, adj);
    // cout << "Distance metrix for source: " << endl;
    // printVector(distC);
    // cout << endl;

    vector<int> distD = runDijkstras(d, adj);
    // cout << "Distance metrix of destination: " << endl;
    // printVector(distD);
    // cout << endl;

    result = distC[d];

    for(int i=0; i<e.size(); i++){
        int from,to,cost, tempCost;

        // first case
        from = e[i][0];
        to = e[i][1];
        cost = e[i][2];
        // Calculate cost from c to from
        if(distC[from] != INT_MAX && distD[to] != INT_MAX){
            // cout << "Cost from c to e[0]: " << distC[from] << endl;
            // cout << "Cost from d to e[1]: " << distD[to] << endl;
            // cout << "Cost from e[0] to e[1]: " << cost << endl;
            tempCost = distC[from] + distD[to] + cost;
            result = min(result, tempCost);
        } else {
            tempCost = INT_MAX;
        }

        // second case
        from = e[i][1];
        to = e[i][0];
        cost = e[i][2];
        if(distC[from] != INT_MAX && distD[to] != INT_MAX){
            // cout << "Cost from c to e[0]: " << distC[from] << endl;
            // cout << "Cost from d to e[1]: " << distD[to] << endl;
            // cout << "Cost from e[0] to e[1]: " << cost << endl;
            tempCost = distC[from] + distD[to] + cost;
            result = min(result, tempCost);
        } else {
            tempCost = INT_MAX;
        }
    }
    if(result == INT_MAX){
        return -1;
    }

    return result;
}

int main(){
    int a = 3;
    vector< vector<int> > b = {
        {1,2,1},
        {2,3,2}
    };
    int c = 1;
    int d = 3;
    vector< vector<int> > e = {
        {1,3,2}
    };
    cout << "Number of nodes: " << a << endl;
    cout << "Given weight metrix: " << endl;
    print2DVector(b);
    cout << "Given source: " << c << endl;
    cout << "Given destination: " << d << endl;
    cout << "Given extra edges: " << endl;
    print2DVector(e);

    int result = solve(a, b, c, d, e);
    cout << "Result: " << result << endl;
    return 0;
}

// g++ -std=c++11