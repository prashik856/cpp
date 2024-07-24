/**
 * Palindrome Partitioning
 * 
 * Given a string str, a partitioning of the string is a palindrome partitioning 
 * if every sub-string of the partition is a palindrome, 
 * the task is to find the minimum number of cuts needed for palindrome 
 * partitioning of the given string.
 * 
 * E.g.
 * Input: ababbbabbababa
 * Output: a | babbbab | b | ababa
 * Output: 4
 * 
 * Input: geek
 * Output: 2
 * 
 * Input: aaaa
 * Output: 0
 * String is already a palindrome
 * 
 * Input: abcde
 * Output: 4
 * 
 * Input: abbac
 * Output: 1
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

bool isPalindrome(string &input, int i, int j) {
    while(i<=j) {
        if(input[i] == input[j]) {
            i++;
            j--;
        } else {
            return false;
        }
    }
    return true;
}

void solve(string &input, int index, int currentOutput, int &output) {
    // stop when we reach end
    if(index == input.size()) {
        if(currentOutput < output) {
            output = currentOutput;
        }
        return;
    }

    for(int i=index; i<input.size(); i++) {
        if(isPalindrome(input, index, i)) {
            solve(input, i+1, currentOutput + 1, output);
        }
    }
}

int palindromePartitioning(string &input) {
    int output = 9999;

    solve(input, 0, 0, output);

    // Output is the number of palindromes required. Number of cuts is output - 1;
    return output-1;
}

int main() {
    string input = "abbac";
    // string input = "abccba";
    cout << "Input: " << input << endl;

    int output = palindromePartitioning(input);
    cout << "Output: " << output << endl;

    return 0;
}
// This solution won't work when in put is big. 
// For that, we will need dynamic programming solution.

