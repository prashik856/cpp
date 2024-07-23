/*
Problem Statement:
Find the largest number in K swaps

Flow:
1) Problem statement input and outputs
2) Identification -> is it Greedy or Backtracking
3) All Choices
Recognise the For loop, base condition, and controlled recursion. 
4) Base Condition
5) Similarity and disimilarity with the last question.

1. Problem Statement Input and Outputs
Input: String s: "1234567"
        int k: 4
Create a largest number after k swaps. Our swaps are limited.

2. Identification if greedy or Backtracking:
We get a counter example where we have duplicates in the input.
With this, we can see that using greedy solution here is bad.

Combinatsion:
Even though we have not been directly asked to get all the combinations, we actually 
need to go through all the possible combinations to get the highest number.

Controlled recursion:
We swap only when the number we want to swap is greater, and we only swap with the max number.

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

bool compareStrings(string &a, string &b) {
    // compare returns 0 if a == b.
    // compare returns less than 0, if a is less than b.
    // compare returns greater than 0, if a is greater than b.
    if(a.compare(b) >= 0) {
        return true;
    }
    return false;
}

void swapChar(string &s, int i, int j) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

char getMax(string &s, int index) {
    char maxValue = '0';
    for(int i=index; i<s.length(); i++) {
        if(s[i] > maxValue) {
            maxValue = s[i];
        }
        // early return
        if(maxValue == '9') {
            return maxValue;
        }
    }
    return maxValue;
}

void solve(string &input, int k, int index, string &output) {
    // cout << "Current Input: " << input << endl;

    // Since our answer can be on any node.
    if(compareStrings(input, output)) {
        // tempOutput > output
        output = input;
    }

    // Base condition
    // either swaps reached or index reached
    if(k==0 || index == (input.length()-1)) {
        return;
    }

    char maxValue = getMax(input, index);

    for(int i=index; i<input.length(); i++) {
        // don't swap
        // solve(input, k, index+1, output);

        // only swap when input[i] > input[index], and input[i] == maxValue
        if(input[i] > input[index] && input[i] == maxValue) {
            // swap
            swapChar(input, i, index);

            // I swapped
            solve(input, k-1, index+1, output);

            // backtrack
            swapChar(input, i, index);
        }
          
    }

    // We don't swap anything but we move the index up.
    solve(input, k, index+1, output);
    // cout << endl;
}

string getLargestNumberAfterKSwaps(string &input, int k) {
    string output = "0";
    solve(input, k, 0, output);
    return output;
}

int main(){
    string input = "28166";
    int k = 10;

    string output = getLargestNumberAfterKSwaps(input, k);

    cout << "Largest Number: " << output << endl;
}
// g++ -std=c++11