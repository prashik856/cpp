/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.' 

You may assume that there will be only one unique solution.



A sudoku puzzle,



and its solution numbers marked in red.

Example :

For the above given diagrams, the corresponding input to your program will be

[[53..7....], [6..195...], [.98....6.], [8...6...3], [4..8.3..1], [7...2...6], [.6....28.], [...419..5], [....8..79]]
and we would expect your program to modify the above array of array of characters to

[[534678912], [672195348], [198342567], [859761423], [426853791], [713924856], [961537284], [287419635], [345286179]]
*/
/*
Solution Approach:
https://www.geeksforgeeks.org/sudoku-backtracking-7/
Let's try it the way we did.
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

int getBoxIndex(int row, int col){
    if(row >= 0 && row <=2 && col >=0 && col <=2){
        return 0;
    }

    if(row >= 0 && row <=2 && col >=3 && col <=5){
        return 1;
    }

    if(row >= 0 && row <=2 && col >=6 && col <=8){
        return 2;
    }

    if(row >= 3 && row <=5 && col >=0 && col <=2){
        return 3;
    }

    if(row >= 3 && row <=5 && col >=3 && col <=5){
        return 4;
    }

    if(row >= 3 && row <=5 && col >=6 && col <=8){
        return 5;
    }

    if(row >= 6 && row <=8 && col >=0 && col <=2){
        return 6;
    }

    if(row >= 6 && row <=8 && col >=3 && col <=5){
        return 7;
    }

    if(row >= 6 && row <=8 && col >=6 && col <=8){
        return 8;
    }

}

void getSolution(vector< vector<char> > &a,
    int rowStart,
    int rowEnd,
    int colStart,
    int colEnd,
    bool *foundSolution,
    vector< unordered_map<char, int> > &rowMapping,
    vector< unordered_map<char, int> > &colMapping,
    vector< unordered_map<char, int> > &boxMapping,
    vector< vector<char> > &result
    ){
        int breakValue = true;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(a[i][j] == '.'){
                    breakValue = false;
                    break;
                }
            }
        }
        
        if(breakValue){
            *foundSolution = true;
            return;
        }

        if((*foundSolution)){
            return;
        }

        if(rowStart > rowEnd || colStart > colEnd){
            return;
        }
        string temp = "123456789";
        for(int i=rowStart; i<=rowEnd; i++){
            for(int j=colStart; j<=colEnd; j++){
                if(a[i][j] == '.'){
                    // check all possible values
                    for(int k=0; k<temp.size(); k++){
                        char val = temp[k];
                        int rowIndex = i;
                        int colIndex = j;
                        int boxIndex = getBoxIndex(rowIndex, colIndex);

                        // check if this value is possible
                        if(rowMapping[rowIndex].find(val) == rowMapping[rowIndex].end() &&
                            colMapping[colIndex].find(val) == colMapping[colIndex].end() &&
                            boxMapping[boxIndex].find(val) == boxMapping[boxIndex].end()){
                                // This value is possible
                                // set
                                a[i][j] = val;
                                rowMapping[rowIndex][val] = 1;
                                colMapping[colIndex][val] = 1;
                                boxMapping[boxIndex][val] = 1;

                                // recurse
                                getSolution(a,
                                rowIndex,
                                rowEnd,
                                colIndex + 1,
                                colEnd,
                                foundSolution,
                                rowMapping,
                                colMapping,
                                boxMapping,
                                result);

                                // backtrack
                                a[i][j] = '.';
                                rowMapping[rowIndex].erase(val);
                                colMapping[colIndex].erase(val);
                                boxMapping[boxIndex].erase(val);
                            }
                    }
                }
            }
        }

    }

void solve(vector< vector<char> > &a){

    vector< vector<char> > result;    
    vector< unordered_map<char, int> > rowMapping(9);
    vector< unordered_map<char, int> > colMapping(9);
    vector< unordered_map<char, int> > boxMapping(9);

    // for boxes
    for(int i=0; i<a.size(); i++){
        unordered_map<char, int> tempBox;
        boxMapping[i] = tempBox ;
    }

    // For rows
    for(int i=0; i<a.size(); i++){
        unordered_map<char, int> tempRow;
        for(int j=0; j<a[i].size(); j++){
            char val = a[i][j];
            if(val != '.'){
                int boxIndex = getBoxIndex(i, j);
                boxMapping[boxIndex][val] = 1;
                tempRow[val] = 1;
            }
        }
        rowMapping[i] = tempRow;
        tempRow.clear();
    } 

    // for cols
    for(int i=0; i<a.size(); i++){
        unordered_map<char, int> tempCol;
        for(int j=0; j<a[i].size(); j++){
            char val = a[j][i];
            if(val != '.'){
                tempCol[val] = 1;
            }
        }
        colMapping[i] = tempCol;
        tempCol.clear();
    }

    // Print the mappings
    cout << "Row mapping is: " << endl;
    for(int i=0; i<9; i++){
        cout << "Row: " << i << endl;
        for(auto itr: rowMapping[i]){
            cout << itr.first << ":" << itr.second << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Print the mappings
    cout << "Column Mapping is: " << endl;
    for(int i=0; i<9; i++){
        cout << "Col: " << i << endl;
        for(auto itr: colMapping[i]){
            cout << itr.first << ":" << itr.second << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Print the mappings
    cout << "Box mapping is: " << endl;
    for(int i=0; i<9; i++){
        cout << "Box: " << i << endl;
        for(auto itr: boxMapping[i]){
            cout << itr.first << ":" << itr.second << " ";
        }
        cout << endl;
    }
    cout << endl;

    int rowStart = 0;
    int rowEnd = 8;
    int colStart = 0;
    int colEnd = 8;
    bool foundSolution = false;
    getSolution(a, rowStart,rowEnd, colStart, colEnd, &foundSolution, rowMapping, colMapping, boxMapping, result);
    a = result;
    return;
}

int main(){
    vector< vector<char> > a = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '5', '.'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'},};
    cout << "Given Sudoko board is: " << endl;
    print2DVector(a);

    solve(a);
    cout << "Solution Soduko is: " << endl;
    print2DVector(a);
    return 0;
}

// g++ -std=c++11