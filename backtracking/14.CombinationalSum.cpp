/**
 * Combinational Sum
 * Given an array of positive integers arr[] and an integer x, 
 * The task is to find all unique combinations in arr[] where the sum is equal to x. 
 * 
 * Same number can be chosen unlimited number of times.
 * 
 * elements of the combination must be printed in ascending order.
 * 
 * If no combination, print empty.
 * 
 * Input: arr: 2, 4, 6, 8
 * x = 8
 * Output: 
 * [2, 2, 2, 2]
 * [2, 2, 4]
 * [2, 6]
 * [8]
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

void solve(vector<int>&arr, int x, 
    int index, vector<int> &currentOutput , vector<vector<int>> &output) {
    // breaking condition
    if(x == 0) {
        // cout << "Got some output: " << endl;
        // printVector(currentOutput);

        output.push_back(currentOutput);
        return;
    }
    if(index >= arr.size()) {
        return;
    }

    // Important for completion of question
    set<int> usedValue = set<int>();
    for(int i=index; i<arr.size(); i++) {
        if(arr[i] <= x && usedValue.find(arr[i]) == usedValue.end()) {
            usedValue.insert(arr[i]);
            currentOutput.push_back(arr[i]);

            solve(arr, x-arr[i], i, currentOutput, output);

            // backtrack
            currentOutput.pop_back();
        }
    }

}

vector<vector<int> > combinationalSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    // cout << "Sorted Input: " << endl;
    // printVector(arr);

    vector<vector<int> > output = vector<vector<int>>();
    vector<int> currentOutput = vector<int>();
    solve(A, B, 0, currentOutput, output);
    return output;
}

int main() {
    vector<int> arr = vector<int>({7,2,6,5});
    int x = 16;
    cout << "Sum required: " << x << endl;
    cout << "Input: " << endl;
    printVector(arr);

    vector< vector<int> > output = combinationalSum(arr, x);
    cout << "Output: " << endl;
    print2DVector(output);

    return 0;
}