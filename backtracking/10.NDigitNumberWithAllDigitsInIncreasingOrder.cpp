/**
 * N Digit number where all digits are in increasing order.
 * 
 * Flow:
 * 1. Problem Statement Input Output
 * 2. Choices - controlled
 * 3. Explanation
 * 4. Code and Time Complexity.
 * 
 * Input: Number N = 2
 * Ps/Op: Return array of 2 digit number: where number is in increasing order.
 * [12, 13, ..., 19, 23, 24, ..., 29, 34, 35, ... 39, 45, ..., 49, 56, ... , 59, 67, 68, 
 * 69, 78, 79, 89]
 *      
 * Input: Number N=1
 * Ps/Op: [0, 1, 2, ...., 9]
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

int getIntegerFromVector(vector<int> &arr) {
    int ans = 0;
    for(int i=0; i<arr.size(); i++) {
        ans = ans * 10 + arr[i];
    }
    return ans;
}

// Using a vector is a good choice here. We can easily push and pop from the back.
// And at the end, we can easily conver the last output to a int number and push it to output.
// better and elegant solution
void solve1(int n, vector<int> &currentInput, vector<int> &output) {
    if(n == 0 ) {
        int ans = getIntegerFromVector(currentInput);
        // cout << "Got some solution: " << ans << endl;
        output.push_back(ans);
        return;
    }

    int lastValue = 0;
    if(currentInput.size() > 0) {
        lastValue = currentInput.back();
    }

    for(int i=lastValue+1; i<=9; i++) {
        // use this value
        currentInput.push_back(i);

        solve1(n-1, currentInput, output);

        // backtrack
        currentInput.pop_back();
    }
}

void solve(int n, char input, string &currentOutput, vector<string> &output) {
    // cout << "Previous value Char: " << input << endl;
    int previousValue = int(input) - 48;
    // cout << "Previous Value: " << previousValue << endl;

    // base condition
    if(n == 0) {
        // cout << "Got some output: " << currentOutput << endl;
        output.push_back(currentOutput);
        return;
    }

    for(int i=previousValue+1; i<=9; i++) {
        char item = i + 48;
        currentOutput.push_back(item);

        solve(n-1, item, currentOutput, output);

        // backtrack
        currentOutput.pop_back();
    }
}

vector<int> getIncreasingOrderNumber(int n) {
    vector<string> output = vector<string>();
    vector<int> intOutput = vector<int>();
    if(n==1) {
        for(int i=0; i<=9; i++) {
            intOutput.push_back(i);
        }
        return intOutput;
    }
    string currentOutput = "";
    solve(n, '0', currentOutput, output);
    for(int i=0; i<output.size(); i++) {
        intOutput.push_back(stoi(output[i]));
    }
    return intOutput;
}

vector<int> getIncreasingOrderNumberVideo(int n) {
    vector<int> output = vector<int>();
    if(n==1) {
        for(int i=0; i<=9; i++) {
            output.push_back(i);
        }
        return output;
    }
    vector<int> currentInput = vector<int>();

    solve1(n, currentInput, output);

    return output;
}

int main(){
    int n = 6;

    cout << "Input: " << n << endl;

    vector<int> output = getIncreasingOrderNumber(n);

    cout << "Output: " << endl;
    printVector(output);

    output = getIncreasingOrderNumberVideo(n);
    cout << "Output: " << endl;
    printVector(output);
}
// g++ -std=c++11