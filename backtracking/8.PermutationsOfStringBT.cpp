/*
Permutations of String Using Backtracking

Flow:
1. Think real life example
2. Backtracking 
3. Code
4. Time Complexity

Base Condition: 
When our current index == len(string) - 1;

How to get all combinations:
We start from currentIndex, and we go till the end of the string, swapping them in the process.
the next index will just be index+1.

Backtracking:
We need to swap back as well for backtracking.

How to handle duplicates?
Here also, while swapping, we can use a set to check if we have already used the current alphabet for swapping.

Time Complexity?
Number of nodes will be of the factor of O(n!)
Every node will have work done of O(n) [loop].
Total time complexity: O(n * n!)
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

void swapChar(string &s, int i, int j) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

void solve(string &input, int index, vector<string> &output) {
    cout << "Current Input: " << input << endl;
    cout << "Current Index: " << index << endl;

    // base condition. If index reached lenght of string
    if((index > input.length() - 1)) {
        cout << "Got some output: " << input << endl;
        string tempOutput = input;
        output.push_back(tempOutput);
        return;
    }

    unordered_map<char, int> mp = unordered_map<char, int>();

    // Choices
    for(int i=index; i<input.length(); i++) {
        char item = input[i];
        if(mp.find(item) == mp.end()) {
            // not found
            mp[item] = 1;
            // swap index with i
            swapChar(input, i, index);

            // move forward with less input
            solve(input, index+1, output);

            // backtrack
            swapChar(input, i, index);
        } else {
            cout << "We have gone through this route already. " << endl;
        }
    }

    cout << endl;
}

vector<string> getAllPermutationsBacktracking(string input) {
    vector<string> output = vector<string>();
    solve(input, 0, output);
    return output;
}

int main(){
    string input = "aabcaaa";
    cout << "Input: " << input << endl;

    vector<string> output = getAllPermutationsBacktracking(input);
    
    cout << "Output: " << endl;
    printStrings(output);
}
// g++ -std=c++11