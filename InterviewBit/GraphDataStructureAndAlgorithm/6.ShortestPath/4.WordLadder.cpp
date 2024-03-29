/*
Given two words A and B, and a dictionary, C, find the length of shortest transformation sequence from A to B, such that:

You must change exactly one character in every transformation.
Each intermediate word must exist in the dictionary.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.


Input Format:

The first argument of input contains a string, A.
The second argument of input contains a string, B.
The third argument of input contains an array of strings, C.
Output Format:

Return an integer representing the minimum number of steps required to change string A to string B.
Constraints:

1 <= length(A), length(B), length(C[i]) <= 25
1 <= length(C) <= 5e3
Example :

Input 1:
    A = "hit"
    B = "cog"
    C = ["hot", "dot", "dog", "lot", "log"]

Output 1:
    5

Explanation 1:
    "hit" -> "hot" -> "dot" -> "dog" -> "cog"
*/
/*
Working solution:
int Solution::solve(string A, string B, vector<string> &C) {
    unordered_set<string> wordSet; // will contain all the words from dict
    bool isPresent = true; // checks if endword(B) is there in dict
    
    for(auto word: C){
        if(B.compare(word) == 0) isPresent = true;
        wordSet.insert(word);
    }
    if(!isPresent) return 0; // end word is not there in dict
    
    queue<string> q; // for BFS graph traversal
    q.push(A);
    int depth = 0;
    
    while(!q.empty()){
        depth+=1;
        int N = q.size(); // no. of ele in current level of graph
        while(N--){
            string curr = q.front(); q.pop();
            // replace all letters in curr word and check these condt
            for(int i = 0; i<curr.size(); i++){
                string temp = curr;
                for(char c = 'a'; c<='z'; c++){
                    temp[i] = c;
                    // if curr and new temp word(with a letter replaced) are same
                    // then continue and do not add duplicate into queue
                    if(curr.compare(temp) == 0) continue; 
                    // it is established that temp is diff from curr
                    // now if temp = B(end word) return depth+1
                    // as this endword is obviously coming in the next level from 
                    // where we are now
                    if(temp.compare(B) == 0) return depth+1;
                    // if temp word is also present in wordSet, then insert into q
                    // and delete it from wordSet
                    if(wordSet.find(temp) != wordSet.end()){
                        q.push(temp); wordSet.erase(temp);
                    }
                }
                
            }
        }
    }
    
    
}
*/
/*
Fuck this. 
Implementation of my code is correct but IB is giving me errors.
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

int solve(string A, string B, vector<string> &C){
    int result = 0;
    // Base case 1
    if(A.size() != B.size()){
        // cout << "A and B sizes not same" << endl;
        return 0;
    }
    
    // Base case 2
    if(B.compare(A) == 0){
        // cout << "A is equal to B" << endl;
        return 1;
    }

    // Base case 3
    if(C.size() > 0 && C[0].size() != A.size()){
        // cout << "Size of dictionary word is not equal to A" << endl;
        return 0;
    }
    
    C.push_back(A);
    int source = C.size() - 1;
    C.push_back(B);
    int dest = C.size() - 1;

    // Store in our dictionary
    unordered_map<string, int> dict;
    for(int i=0; i<C.size(); i++){
        dict[C[i]] = i+1;
    }
    // Create adjacency matrix
    int n = C.size();
    vector< set<int> > adj(n, set<int> ());
    for(int i=0; i<n; i++){
        string temp = C[i];
        int m = temp.size();
        for(int j=0; j<m; j++){
            for(int k='a'; k<='z'; k++){
                char prevValue = temp[j];
                if(prevValue == k){
                    continue;
                }
                temp[j] = k;
                int dictValue = dict[temp];
                if(dictValue != 0){
                    int neighbourIndex = dictValue - 1;
                    adj[i].insert(neighbourIndex);
                }
                temp[j] = prevValue;
            }
        }
    }

    dict.clear();

    // Print the adjacency matrix
    // cout << "Adjacency matrix: " << endl;
    // for(int i=0; i<n; i++){
    //     cout << i << " -> ";
    //     for(auto j=adj[i].begin(); j!= adj[i].end(); j++){
    //         cout << *j << " ";
    //     }
    //     cout << endl;
    // }

    // Now that we have our adjacency matrix, let's work on dijkstras algo
    vector<int> dist(n, INT_MAX);
    vector<int> visited(n, false);
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    dist[source] = 1;
    pq.push({1, source});
    while(!pq.empty()){
        pair<int, int> top = pq.top();
        pq.pop();
        int node = top.second;
        int currentDist = top.first;
        visited[node] = true;
        if(node == dest){
            break;
        }
        // go through all the nodes
        for(auto j=adj[node].begin(); j!= adj[node].end(); j++){
            int currentNeighbour = *j;
            // current neighbour is not visited
            if(!visited[currentNeighbour]){
                if(currentDist + 1 < dist[currentNeighbour]){
                    dist[currentNeighbour] = currentDist + 1;
                    pq.push({currentDist + 1, currentNeighbour});
                }
            }
        }
    }

    // cout << "Distance matrix: " << endl;
    // for(int i=0; i<n; i++){
    //     cout << i << " -> " << dist[i] << endl;
    // }

    result = dist[dest];
    if(result == INT_MAX){
        result = 0;
    }

    return result;
}

int main(){
    string a = "hit";
    string b = "cog";
    vector<string> c = {
        "hit",
        "hot",
        "dot",
        "dog",
        "cog"
    };
    cout << "Given source string is: " << a << endl;
    cout << "Given destination string is: " << b << endl;
    cout << "Given dictionary is: " << endl;
    printStrings(c);

    int result = solve(a, b, c);
    cout << "Result: " << result << endl;
    return 0;
}

// g++ -std=c++11