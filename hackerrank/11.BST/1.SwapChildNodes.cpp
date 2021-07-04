#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'swapNodes' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY indexes
 *  2. INTEGER_ARRAY queries
 */
class Node {
    public:
        int data;
        int depth;
        Node *left;
        Node *right;    
        Node(int dataValue, int depthValue, Node *leftValue, Node *rightValue){
            data = dataValue;
            left = leftValue;
            right = rightValue;
            depth = depthValue;
        }
};

Node *findNode(Node *root, int dataValue){
    Node *result = 0;
    
    if(root->data == dataValue){
        // cout << "Node Found" << endl;    
        return root;
    } else {
        if(root -> left != 0){
            // cout << "Going Left" << endl;
            result = findNode(root->left, dataValue);
            if(result != 0){
                return result;
            }
        }
        
        if(root -> right != 0){
            // cout << "Going Right" << endl;
            result = findNode(root->right, dataValue);
            if(result != 0){
                return result;
            }
        }    
    }
    return result;
}

void inOrder(Node *root, vector< int > &result){
    if(!root){
        return;
    }
    inOrder(root -> left, result);
    //cout << "Visiting Node: " << root -> data << endl;
    result.push_back(root->data);
    inOrder(root -> right, result);
}

void BFS(Node *root, int requiredDepth, int maxDepth){
    vector<int> allDepths;
    for(int i=1; ; i++){
        if(requiredDepth * i <= maxDepth){
            allDepths.push_back(requiredDepth*i);
        } else {
            break;
        }
    }
    //cout << "All depths to swap: " << endl;
    for(int i=0; i<allDepths.size(); i++){
        //cout << allDepths[i] << " ";
    }
    // cout << endl;
    
    for(int i=0; i<allDepths.size(); i++){
        queue<Node *> q;
        q.push(root);
        while(!q.empty()){
            Node *node = q.front();
            
            // When node depth reaches requiredDepth,
            // All nodes should have the same depth
            if(node -> depth == allDepths[i]){
                break;
            }
            if(node -> left != 0){
                q.push(node -> left);
            }
            if(node -> right != 0){
                q.push(node -> right);
            }
            
            q.pop();
        }
    
        //cout << "Data in queue: " << endl;
        while(!q.empty()){  
            // cout << "Node data: " << q.front() -> data << endl;
            // cout << "Node depth: " << q.front() -> depth << endl;
            Node *node = q.front();
            Node *temp = node -> left;
            node ->left = node -> right;
            node -> right = temp;
            q.pop();
        }
    }
    
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    vector< vector<int> > result;
    // cout << "Creating Root" << endl;
    Node root(1, 1, 0, 0);
    int n = indexes.size();
    int k = queries.size();
    // Create our BST
    // cout << "Creating BST" << endl;
    int maxDepth = -1;
    for(int i=0; i<n; i++){
        // Find current node
        int currentdata = i+1;
        // cout << "Find data node: " << currentdata << endl;
        Node *node = findNode(&root, currentdata);
        if(node -> depth > maxDepth){
            maxDepth = node -> depth;
        }
        
        int leftData = indexes[i][0];
        // cout << "Left data node: " << leftData << endl;
        int rightData = indexes[i][1];
        // cout << "Right data node: " << rightData << endl;
        
        
        Node *left, *right;
        // Check if null
        if(leftData == -1){
            left = 0;
        } else {
            // left data is positive
            left = new Node(leftData, node->depth + 1, 0, 0);
        }
        if(rightData == -1){
            right = 0;
        } else {
            right = new Node(rightData, node->depth + 1, 0, 0);
        }
        // Create children
        node -> left = left;
        node -> right = right;
        // cout << endl;
    }
    
    for(int i=0; i<k; i++){
        int requiredDepth = queries[i];
        BFS(&root, requiredDepth, maxDepth);
        result.push_back(vector<int>());
        //cout << "Starting inorder traverse" << endl;
        inOrder(&root, result[result.size() - 1]);
        // cout << endl;
    }
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> indexes(n);

    for (int i = 0; i < n; i++) {
        indexes[i].resize(2);

        string indexes_row_temp_temp;
        getline(cin, indexes_row_temp_temp);

        vector<string> indexes_row_temp = split(rtrim(indexes_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int indexes_row_item = stoi(indexes_row_temp[j]);

            indexes[i][j] = indexes_row_item;
        }
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
