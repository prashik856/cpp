/**
 * Generate All Parenthesis
 * 
 * Given an integer A, generate all combinations of well formed parenthesis of length 2*A
 * 
 * We can use Input Output method here.
 * 
 * Since we have to consider choices + decisions here, this becomes a recursive question.
 */
#include<bits/stdc++.h>
using namespace std;

void getAllWellFormedParenthesis(int A, int value, int count, string &currentOutput, 
    vector<string> &allOutputs) {
    // cout << "Current Output: " << currentOutput << endl;
    // cout << "Current Value: " << value << endl;
    // cout << "Current Count: " << count << endl;

    if(count == 2*A && value == 0) {
        // Got some output
        allOutputs.push_back(currentOutput);
        return;
    } else if(count == 2*A) {
        // Not a valid output
        return;
    }

    // We are going ahead
    count++;

    // Push (
    currentOutput.push_back('(');
    value++;
    if(value <= A && value >=0) {
        // Go Ahead
        getAllWellFormedParenthesis(A, value, count, currentOutput, allOutputs);
    }

    // backtrack
    currentOutput.pop_back();
    value--;

    // Push )
    currentOutput.push_back(')');
    value--;
    if(value <=A && value >=0) {
        // Go Ahead
        getAllWellFormedParenthesis(A, value, count, currentOutput, allOutputs);
    }

    // backtrack
    currentOutput.pop_back();
    // no need to backtrack value here as not using pointer
    
    return;
}

int main() {
    int A = 10;
    cout << "Input: " << A << endl;

    vector<string> allOutputs = vector<string>();
    string currentOutput = "";
    int value = 0;
    int count = 0;

    getAllWellFormedParenthesis(A, value, count, currentOutput, allOutputs);
    cout << "Output: " << endl;

    for(int i=0; i<allOutputs.size(); i++) {
        cout << allOutputs[i] << " ";
    }
    cout << endl;

    return 0;
}