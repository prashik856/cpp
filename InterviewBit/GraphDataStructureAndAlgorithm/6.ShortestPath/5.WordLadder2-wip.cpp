/*
Given two words (start and end), and a dictionary, find the shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
If there are multiple such sequence of shortest length, return all of them. Refer to the example for more details.

Note:

All words have the same length.
All words contain only lowercase alphabetic characters.
Input Format

The first argument is string start.
The second argument is string end.
The third argument is an array of strings dict
Output Format

Return all transformation sequences such that first word of each sequence is start and last word is end, all intermediate words belongs to dictionary(dict) and consecutive words had atmost 1 difference.  
Example :

:

start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return

  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
*/
/*
Solution approach:

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

vector< vector<string> > solve(string start, string end, vector<string> &dict){
    vector< vector<string> > result;

    if(start.size() != end.size()){
        return result;
    }

    if(start.compare(end) == 0){
        result.push_back({start});
        return result;
    }

    if(dict[0].size() > 0 && start.size() != dict[0].size()){
        return result;
    }

    dict.push_back(start);
    int source = dict.size() - 1;
    dict.push_back(end);
    int dest = dict.size() - 1;
    
    // Store in our dictionary
    unordered_map<string, int> wordSet;
    for(int i=0; i<dict.size(); i++){
        wordSet[dict[i]] = i+1;
    }

    // Create adjacency matrix
    int n = dict.size();
    vector< set<int> > adj(n, set<int> ());
    for(int i=0; i<n; i++){
        string temp = dict[i];
        int m = temp.size();
        for(int j=0; j<m; j++){
            for(int k='a'; k<='z'; k++){
                char prevValue = temp[j];
                if(prevValue == k){
                    continue;
                }
                temp[j] = k;
                int dictValue = wordSet[temp];
                if(dictValue != 0){
                    int neighbourIndex = dictValue - 1;
                    adj[i].insert(neighbourIndex);
                }
                temp[j] = prevValue;
            }
        }
    }

    wordSet.clear();


    // print adj matrix
    // cout << "Our adjacency matrix is: " << endl;
    // for(int i=0; i<n; i++){
    //     cout << i << " -> ";
    //     for(auto j=adj[i].begin(); j!= adj[i].end(); j++){
    //         cout << *j << " ";
    //     }
    //     cout << endl;
    // }
    vector<int> dist(n, INT_MAX);
    vector<int> visited(n, false);
    


    return result;
}

int main(){
    string start = "hit";
    string end = "cog";
    vector<string> dict = {
        "hot","dot","dog","lot","log"
    };
    cout << "Start: " << start << endl;
    cout << "End: " << end << endl;
    cout << "Given dict: " << endl;
    printStrings(dict);

    vector< vector<string> > result = solve(start, end, dict);
    cout << "Result: " << endl;
    print2DStrings(result);
    return 0;
}

// g++ -std=c++11