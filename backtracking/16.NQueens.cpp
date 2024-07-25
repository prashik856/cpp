/**
 * The N Queen is the problem of placing N chess queens on an N×N chessboard 
 * so that no two queens attack each other.
    The expected output is in the form of a matrix that has ‘Q‘s for the blocks where 
    queens are placed and the empty spaces are represented by ‘.’ . 
    For example, the following is the output matrix for the above 4-Queen solution.

    . Q . .
    . . . Q 
    Q . . .
    . . Q . 

 * 
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

void print2DVector(vector< vector<long> > arr){
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

void print4DVector(vector< vector< vector< vector<int>>>> arr) {
    for(int i=0; i<arr.size(); i++) {
        cout << i << " : " << endl;
        for(int j=0; j<arr[i].size(); j++) {
            cout << j << " : " << endl;
            for(int k=0; k<arr[j].size(); k++) {
                for(int l=0; l<arr[k].size(); l++) {
                    cout << arr[i][j][k][l] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }
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

bool isValid(int row, int column, vector<vector<int>> &input, set<int> &setValue) {
    if(setValue.find(column) == setValue.end()) {
        // up left; i-- j--
        for(int i=row, j=column; i>=0 && j>=0; ) {
            if(input[i][j] == 1) {
                return false;
            }
            i--;j--;
        }

        // up right
        for(int i=row,j=column; i>=0 && j<input.size(); ) {
            if(input[i][j] == 1) {
                return false;
            }
            i--; j++;
        }
    } else {
        return false;
    }
    return true;
}

void solve(vector<vector<int>> &input, int row, 
    set<int> &column, vector<vector<int>> &output, bool &gotOutput) {
    if(gotOutput) {
        return;
    }
    // breaking point
    if(row >= input.size()) {
        // cout << "Got some solution" << endl;
        output = input;
        return;
    }

    for(int i=0; i<input.size(); i++) {
        // see if i is valid.
        if(isValid(row, i, input, column)){
            // valid position found.

            input[row][i] = 1;
            column.insert(i);

            solve(input, row+1, column, output, gotOutput);

            // backtrack
            input[row][i] = 0;
            column.erase(i);
        }
    }
}

vector<vector<int>> NQueens(vector<vector<int>> &input) {
    vector<vector<int>> output = vector<vector<int>>();
    set<int> column = set<int>();
    bool gotOutput = false;
    solve(input, 0, column, output, gotOutput);
    return output;
}

int main() {
    int n = 7;
    vector<vector<int>> input = vector<vector<int>>();
    for(int i=0; i<n; i++) {
        vector<int> arr = vector<int>();
        for(int j=0; j<n; j++) {
            arr.push_back(0);
        }
        input.push_back(arr);
    }
    cout << "Input matrix: " << endl;
    print2DVector(input);

    vector<vector<int>> output = NQueens(input);
    cout << "Output: " << endl;
    print2DVector(output);

}