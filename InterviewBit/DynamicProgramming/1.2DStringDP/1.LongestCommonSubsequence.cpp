/*
Problem Description

Given two strings A and B. Find the longest common sequence ( A sequence which does not need to be contiguous), which is common in both the strings.

You need to return the length of such longest common subsequence.



Problem Constraints
1 <= |A|, |B| <= 1005



Input Format
First argument is an string A.

Second argument is an string B.



Output Format
Return the length of such longest common subsequence between string A and string B.



Example Input
Input 1:

 A = "abbcdgf"
 B = "bbadcgf"


Example Output
Output 1:

 5


Example Explanation
Explanation 1:

 The longest common subsequence is "bbcgf", which has a length of 5
*/
/*
Solution Approach:
Simple LCS
Table worked but dictionary did not work.
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


int lcs(string A, int indexA, string B, int indexB, vector< vector<int> > &table) {
    if(indexA < 0 || indexB < 0) {
        return 0;
    }
    if(table[indexA][indexB] != -1){
        // cout << "Cache hit" << endl;
        // value not empty
        return table[indexA][indexB];
    }

    int result3 = 0;
    int result2 = 0;
    int result1 = 0;

    if(A[indexA] == B[indexB]){
        // cout << "Equal" << endl;
        result1 = 1 + lcs(A, indexA - 1, B , indexB - 1, table);
    } else {
        result2 = lcs(A, indexA, B, indexB - 1, table);
        result3 = lcs(A, indexA - 1, B, indexB, table);
    }
    // cout << "Index: " << indexA << endl;
    // cout << "Value: " << A[indexA] << endl;
    // cout << "Index: " << indexB << endl;
    // cout << "Value: " << B[indexB] << endl;
    // cout << "Result1: " << result1 << endl;
    // cout << "Result2: " << result2 << endl;
    // cout << "Result3: " << result3 << endl;
    // cout << endl;
    // cout << "Cache miss" << endl;
    int tempResult = max(max(result1, result2), max(result2, result3));
    table[indexA][indexB] = tempResult;
    return tempResult;
}

int solve(string A, string B) {
    int result = 0;

    // cout << "Starting lcs" << endl;
    // now, let's store values
    int N = 1005;
    vector< vector<int> > table(N, vector<int>(N, -1));
    result = lcs(A, A.size() - 1, B, B.size() - 1, table);

    return result;
}

int main(){
    string A = "cceeceaebebaddcdaceacdcdecebebbbaaddededecdcddcdcbdeacababcbdbeabcdbcabbeeaceeabbaddadeceedcaeabcdeeaadacaebacdbcbeebabaebaebadaacebaedcacacedaebbdcbcabdacbcabcadaacdeedebeadddeebbbbebdbdaeeebcabcacdddcadadcaeabcdcbbaedeacaaedeaccabeaeabdacddababeaccceceebadbcbcdceacadcdecaccdcaabcbddbadbbbcabacbeeceedbeabecbbeadcdeecabaadbcadbacaeaebaaaadcbdcddbdcdbcabeeeebeddaaedaeeceddeaeddecdaaebbdccbbaceabccddccdaeaecadbeabaeeabbcadbeaedacecceebaeaaebbcadbeecddedeabdbbdaaaeedbadeabccbbadaebdebeececdccdeeaccacbceeeacbacbbccabdccbdaddeedecebabcbdddbaccceeecababbcbadbdcaebcddbddeeeeeddacdaaabccdcabcadcbacebcadbecaccbbcdbcadeaccbacbeabdbaababaceebcaeaebacdcacdceebbdecaebacdcbdaaaebebdebbbdbdedbabceddadcecbecbeccbadabedbabadecbdbebecaabbeedadcbdadbebcceeadbcdededdaaededbabedbbcebabaaaaadeedaaddaeceabccedddaacdcbdcbadcacaacaaabcbcadbceeaebccedcbccbecdbeddeaaebeebabcabbdbacbcbaacbedcbddcddbbcbeeecbddabbccd";
    string B = "aaddbabbbeedeccababcedeeeeaadaaeaeebbcccddccaeedeabbbaaabbcbbccdddeeaeddcbcacdaeebcadccbaeaddcbcddddccebabbcacdbaadbdccadcbbccaaceaebedddbaddebbbbcbdecbedcbcddaedbadeabbabbbeedabedddeeddcddaacabeddebbceeaaedacaacabbbaaeaceddcedaeabbbdbcccebecbbdecaabbccbaaaecebbceebddaaebcacaaabcdeedacdadacbbbaaebdbbacdccdeebbcabccaaaddcebabccccdaebdcaebeaabddbadbadbeedcaaeaecababaaadecddabedecacecdcebeadaeddabdcbceeaebcaedecddebcacdaabebebedbbaaccbabbacceabddaddbaacedbddbebdbabcaeacbcbdabcbbcebcbdbcbbbacebecaecacdcdcdcbbddaacddacebdbadeeaeeeedaddedaabeabeceedcdecbcaabdeceacedbdebdaadebddabcaccbeeddccceeadabcecceaddbbeeedebabbcebbedaddededeeaeeaeadaecbbebecaadcebcaabaebadcbeecaddbaecbcdddebaddcadbbecdabeeddbbbadccaabdacaaaaedacebcebaadddebceaeeaecaeecbbedeecabeeeaecaacccdcbeedbbecbdeabaadbdacececcebedbdebeeebeccedeadbabeaeecddaeebcacddbadebabaddcdecaeaeaeedbaedebaccbeadaceaaecaecaacbabaadabdeeaebddbbbddd";
    cout << "input string is: " << A << endl;
    cout << "input 2 string is: " << B << endl;
    cout << endl;
    int result = solve(A, B);
    cout << "Result: " << result << endl;
    return 0;
}

// g++ -std=c++11