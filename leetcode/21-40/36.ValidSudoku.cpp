/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

    Each row must contain the digits 1-9 without repetition.
    Each column must contain the digits 1-9 without repetition.
    Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:

    A Sudoku board (partially filled) could be valid but is not necessarily solvable.
    Only the filled cells need to be validated according to the mentioned rules.

Example 1:
Input: board =
{{'5','3','.','.','7','.','.','.','.'}
,{'6','.','.','1','9','5','.','.','.'}
,{'.','9','8','.','.','.','.','6','.'}
,{'8','.','.','.','6','.','.','.','3'}
,{'4','.','.','8','.','3','.','.','1'}
,{'7','.','.','.','2','.','.','.','6'}
,{'.','6','.','.','.','.','2','8','.'}
,{'.','.','.','4','1','9','.','.','5'}
,{'.','.','.','.','8','.','.','7','9'}}
Output: true

Example 2:

Input: board =
{{'8','3','.','.','7','.','.','.','.'}
,{'6','.','.','1','9','5','.','.','.'}
,{'.','9','8','.','.','.','.','6','.'}
,{'8','.','.','.','6','.','.','.','3'}
,{'4','.','.','8','.','3','.','.','1'}
,{'7','.','.','.','2','.','.','.','6'}
,{'.','6','.','.','.','.','2','8','.'}
,{'.','.','.','4','1','9','.','.','5'}
,{'.','.','.','.','8','.','.','7','9'}}
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

Constraints:

    board.length == 9
    board{i}.length == 9
    board{i}{j} is a digit 1-9 or '.'.
*/
#include<bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    bool result = false;

    // Check each row
    unordered_map<char, int> dict;
    for (int i=0; i<board.size(); i++) {
        dict.clear();
        // cout << "Current Row: " << endl;
        for (int j=0; j<board[i].size(); j++) {
            char val = board[i][j];
            cout << val << " ";
            if(val == '.') {
                continue;
            }
            if (dict.find(val) == dict.end()) {
                dict.insert({val, 1});
            } else {
                // cout << "Value already found: " << endl;
                return result;
            }
        }
        cout << endl;
    }

    // check each column
    for (int i=0; i<board.size(); i++) {
        dict.clear();
        // cout << "Current Column: " << endl;
        for (int j=0; j<board[i].size(); j++) {
            char val = board[j][i];
            if(val == '.') {
                continue;
            }

            if (dict.find(val) == dict.end()) {
                dict.insert({val, 1});
            } else {
                // cout << "Value already found: " << endl;
                return result;
            }
        }
    }


    // check each small box
    vector<int> iIndex = {0, 0, 0, 3, 3, 3, 6, 6, 6};
    vector<int> jIndex = {0, 3, 6, 0, 3, 6, 0, 3, 6};
    int index = 0;
    while(index < iIndex.size()) {
        int i=iIndex[index];
        int imax = i + 3;
        int j=jIndex[index];
        int jmax = j + 3;
        // cout << "i Index: " << i << endl;
        // cout << "j index: " << j << endl;
        // cout << "i max: " << imax << endl;
        // cout << "j max: " << jmax << endl;
        dict.clear();
        for(int k=i; k<imax; k++) {
            for(int l=j; l<jmax; l++) {
                char val = board[k][l];
                // cout << val;
                if(val == '.') {
                    continue;
                }

                if(dict.find(val) == dict.end()) {
                    dict.insert({val, 1});
                } else {
                    // cout << "Value already found: " << endl;
                    return result;
                }
            }
            // cout << endl;
        }
        // cout << endl;
        index++;
    }

    // cout << "Valid sudoku found" << endl;
    return true;
}

int main() {
    vector<vector<vector<char>>> inputs = {{{'5','3','.','.','7','.','.','.','.'}
,{'6','.','.','1','9','5','.','.','.'}
,{'.','9','8','.','.','.','.','6','.'}
,{'8','.','.','.','6','.','.','.','3'}
,{'4','.','.','8','.','3','.','.','1'}
,{'7','.','.','.','2','.','.','.','6'}
,{'.','6','.','.','.','.','2','8','.'}
,{'.','.','.','4','1','9','.','.','5'}
,{'.','.','.','.','8','.','.','7','9'}},

        {{'8','3','.','.','7','.','.','.','.'}
    ,{'6','.','.','1','9','5','.','.','.'}
    ,{'.','9','8','.','.','.','.','6','.'}
    ,{'8','.','.','.','6','.','.','.','3'}
    ,{'4','.','.','8','.','3','.','.','1'}
    ,{'7','.','.','.','2','.','.','.','6'}
    ,{'.','6','.','.','.','.','2','8','.'}
    ,{'.','.','.','4','1','9','.','.','5'}
    ,{'.','.','.','.','8','.','.','7','9'}},

    {{'.','.','.','.','5','.','.','1','.'},{'.','4','.','3','.','.','.','.','.'},{'.','.','.','.','.','3','.','.','1'},{'8','.','.','.','.','.','.','2','.'},{'.','.','2','.','7','.','.','.','.'},{'.','1','5','.','.','.','.','.','.'},{'.','.','.','.','.','2','.','.','.'},{'.','2','.','9','.','.','.','.','.'},{'.','.','4','.','.','.','.','.','.'}}};

    vector<bool> outputs = {true, false, false};

    for (int i=0; i<inputs.size(); i++) {
        cout << "Input: " << endl;

        bool output = isValidSudoku(inputs[i]);
        cout << "Output : " << output << endl;

        cout << "Expected output : " << outputs[i] << endl;
        cout << endl;
    }
    return 0;
}

// Accepted
