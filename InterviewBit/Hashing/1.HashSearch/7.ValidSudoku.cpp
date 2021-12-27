/*
Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx

The Sudoku board could be partially filled, where empty cells are filled with the character ‘.’.



The input corresponding to the above configuration :

["53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"]
A partially filled sudoku which is valid.

Note:

A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/

/*
Solution Approach:
1. An empty sudoku is always okay
2. A sudoku is okay if every row, column and each box has unique elements in side them.
Yeah, this worked.
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
}

void printStrings(vector<string> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << endl;
    }
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

bool checkRows(vector<string> a) {
    bool result = true;
    int char0 = (int)'0';
    for(int i=0; i<9; i++){
        unordered_map<int, int> rowMap;
        rowMap.clear();
        for(int j=0; j<9; j++){
            if(a[i][j] != '.'){
                int intValue = (int)a[i][j] - char0;
                if(intValue == 0){
                    return false;
                }
                int mapValue = rowMap[intValue];
                if(mapValue == 0){
                    rowMap[intValue] = 1;
                } else {
                    // this number already exists
                    return false;
                }
            }
        }
    }

    return result;
}

bool checkColumns(vector<string> a) {
    bool result = true;
    int char0 = (int)'0';
    for(int i=0; i<9; i++){
        unordered_map<int, int> colMap;
        colMap.clear();
        for(int j=0; j<9; j++){
            if(a[j][i] != '.'){
                int intValue = (int)a[j][i] - char0;
                if(intValue == 0){
                    return false;
                }
                int mapValue = colMap[intValue];
                if(mapValue == 0){
                    colMap[intValue] = 1;
                } else {
                    // this number already exists
                    return false;
                }
            }
        }
    }

    return true;
}

bool checkBoxes(vector<string> a) {
    bool result = true;
    vector<int> rowIndices = {0, 0, 0, 3, 3, 3, 6, 6, 6};
    vector<int> colIndices = {0, 3, 6, 0, 3, 6, 0, 3, 6};
    int char0 = (int)'0';
    int index = 0;
    while(index < 9){
        unordered_map<int, int> boxesMapping;
        boxesMapping.clear();
        for(int i=rowIndices[index]; i<rowIndices[index]+3; i++){
            for(int j=colIndices[index]; j<colIndices[index]+3; j++){
                if(a[i][j] != '.'){
                    int intValue = (int)a[i][j] - char0;
                    // cout << intValue << " ";
                    if(intValue == 0){
                        return false;
                    }
                    int mapValue = boxesMapping[intValue];
                    if(mapValue == 0){
                        boxesMapping[intValue] = 1;
                    } else {
                        // this number already exists
                        return false;
                    }
                }
            }
        }
        // cout << endl;
        index++;
    }

    return result;
}

int solve(vector<string> a){
    int result = 1;

    bool rows = checkRows(a);
    // if(rows){
    //     cout << "Rows are okay" << endl;
    // }
    bool column = checkColumns(a);
    // if(column){
    //     cout << "Columns are okay" << endl;
    // }
    bool boxes = checkBoxes(a);
    // if(boxes){
    //     cout << "Boxes are okay" << endl;
    // }
    
    if(rows && column && boxes){
        return 1;
    } else {
        return 0;
    }

    return result;
}

int main(){
    vector<string> a = {"..5.....6", "....14...", ".........", ".....92..", "5....2...", ".......3.", "...54....", "3.....42.", "...27.6.."};
    cout << "Given sudoku is: " << endl;
    printStrings(a);

    int result = solve(a);
    cout << "Result: " << result << endl;
    return 0;
}

// g++ -std=c++11