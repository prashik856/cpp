/**
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

    Each of the digits 1-9 must occur exactly once in each row.
    Each of the digits 1-9 must occur exactly once in each column.
    Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

The '.' character indicates empty cells.

Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:

Constraints:

    board.length == 9
    board[i].length == 9
    board[i][j] is a digit or '.'.
    It is guaranteed that the input board has only one solution.

 */
#include<bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<char>> &board) {
    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[0].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isValidSudoku(vector<vector<char>>& board) {
    bool result = false;

    // Check each row
    unordered_map<char, int> dict;
    for (int i=0; i<board.size(); i++) {
        dict.clear();
        // cout << "Current Row: " << endl;
        for (int j=0; j<board[i].size(); j++) {
            char val = board[i][j];
            // cout << val << " ";
            if (dict.find(val) == dict.end()) {
                dict.insert({val, 1});
            } else {
                // cout << "Value already found: " << endl;
                return result;
            }
        }
        // cout << endl;
    }

    // check each column
    for (int i=0; i<board.size(); i++) {
        dict.clear();
        // cout << "Current Column: " << endl;
        for (int j=0; j<board[i].size(); j++) {
            char val = board[j][i];

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

int getBoxIndex(int i, int j) {
    if(i>=0 && i <=2 && j>= 0 && j<=2) {
        return 0;
    }

    if(i>=0 && i <=2 && j>= 3 && j<=5) {
        return 1;
    }

    if(i>=0 && i <=2 && j>= 6 && j<=8) {
        return 2;
    }

    if(i>=3 && i <=5 && j>= 0 && j<=2) {
        return 3;
    }

    if(i>=3 && i <=5 && j>= 3 && j<=5) {
        return 4;
    }

    if(i>=3 && i <=5 && j>= 6 && j<=8) {
        return 5;
    }

    if(i>=6 && i <=8 && j>= 0 && j<=2) {
        return 6;
    }

    if(i>=6 && i <=8 && j>= 3 && j<=5) {
        return 7;
    }

    if(i>=6 && i <=8 && j>= 6 && j<=8) {
        return 8;
    }
    return -1;
}

void helper(vector<vector<char>> &board, int i, int j, bool *found, 
    vector<unordered_map<char, int>> &rowDict, vector<unordered_map<char, int>> &columnDict, 
    vector<unordered_map<char, int>> &boxDict, vector<char> &validValues, vector<vector<char>> &output) {
    // cout << endl << "New function call: " << endl;
    // cout << "Current Board: " << endl;
    // printBoard(board);
    
    // cout << "Found value: " << *found << endl;
    // cout << "i Index: " << i  << " | j Index: " << j  << " | Value: " << board[i][j]<< endl;
    
    if(*found) {
        return;
    }

    // check for end
    if(j==9 && i == 8) {
        // Reached the end
        // cout << "Board is full now. Validate if it is good." << endl;    
        bool validSudoku = isValidSudoku(board);
        if(validSudoku) {
            *found = true;
            output = board;
        }
        return;
    }

    // balance values of i and j
    if(j == 9) {
        j = 0;
        i++;
    }

    char val = board[i][j];
    if(val != '.') {
        // move forward
        helper(board, i, j+1, found, rowDict, columnDict, boxDict, validValues, output);
        return;
    }

    int row = i;
    int col = j;
    int boxIndex = getBoxIndex(row, col);

    // cout << "Val is ." << endl;
    char possibleValue = '0';
    for(int index=0; index<9; index++) {
        char temp = validValues[index];
        if(rowDict[row].find(temp) == rowDict[row].end() &&
        columnDict[col].find(temp) == columnDict[col].end() &&
        boxDict[boxIndex].find(temp) == boxDict[boxIndex].end()) {
            // cout << "Possible value that can be used: " << temp << endl;
            // update possible value
            possibleValue = temp;

            // update board
            board[i][j] = possibleValue;

            // update dicts
            rowDict[row].insert({possibleValue, 1});
            columnDict[col].insert({possibleValue, 1});
            boxDict[boxIndex].insert({possibleValue, 1});

            // go forward
            helper(board, i, j+1, found, rowDict, columnDict, boxDict, validValues, output);
            
            if(*found) {
                return;
            }

            // cout << "Possible value" << possibleValue << " cannot be used" << endl;

            // cout << "Backtracking. Updating index " << row << " and " << col << endl;

            // back port
            rowDict[row].erase(possibleValue);
            columnDict[col].erase(possibleValue);
            boxDict[boxIndex].erase(possibleValue);

            // update board
            board[i][j] = '.';

            // update possible value
            possibleValue = '0';
        }
    }
}

void solveSudoku(vector<vector<char>>& board) { 
    int iIndex = 0;
    int jIndex = 0;

    vector<unordered_map<char, int>> rowDict(9);
    vector<unordered_map<char,int>> columnDict(9);
    vector<unordered_map<char,int>> boxDict(9);
    vector<char> validValues = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    vector<vector<char>> output;
    bool found = false;

    // Initialize dictionaries
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            char val = board[i][j];
            if(val == '.') {
                continue;
            }
            
            int row = i;
            int col = j;
            int boxIndex = getBoxIndex(row, col);

            rowDict[row].insert({val, 1});
            columnDict[col].insert({val, 1});
            boxDict[boxIndex].insert({val, 1});
        }
    }

    helper(board, 0, 0, &found, rowDict, columnDict, boxDict, validValues, output);

    board = output;
}

int main() {
    vector<vector<vector<char>>> inputs = {
        {{'5','3','.','.','7','.','.','.','.'}
        ,{'6','.','.','1','9','5','.','.','.'}
        ,{'.','9','8','.','.','.','.','6','.'}
        ,{'8','.','.','.','6','.','.','.','3'}
        ,{'4','.','.','8','.','3','.','.','1'}
        ,{'7','.','.','.','2','.','.','.','6'}
        ,{'.','6','.','.','.','.','2','8','.'}
        ,{'.','.','.','4','1','9','.','.','5'}
        ,{'.','.','.','.','8','.','.','7','9'}}};

    vector<vector<vector<char>>> outputs = {
        {{'5','3','4','6','7','8','9','1','2'}
        ,{'6','7','2','1','9','5','3','4','8'}
        ,{'1','9','8','3','4','2','5','6','7'}
        ,{'8','5','9','7','6','1','4','2','3'}
        ,{'4','2','6','8','5','3','7','9','1'}
        ,{'7','1','3','9','2','4','8','5','6'}
        ,{'9','6','1','5','3','7','2','8','4'}
        ,{'2','8','7','4','1','9','6','3','5'}
        ,{'3','4','5','2','8','6','1','7','9'}}};

    for(int i=0; i<inputs.size(); i++) {
        cout << "Input: " << endl;
        printBoard(inputs[i]);

        cout << "Output: " << endl;
        printBoard(inputs[i]);

        solveSudoku(inputs[i]);

        bool inputValid = isValidSudoku(inputs[i]);
        cout << "Solved sudoku is valid: " << inputValid << endl;

        bool valid = isValidSudoku(outputs[i]);
        cout << "Output is valid: " << valid << endl;

        cout << "Expected Output: " << endl << endl;
        printBoard(outputs[i]);
    }
    
    return 0;
}