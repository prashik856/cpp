/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:

Input: n = 1
Output: ["()"]

Constraints:

    1 <= n <= 8

 */
#include <bits/stdc++.h>
using namespace std;

void printStrings(vector<string> &arr) {
    for (int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void generateParentheses(int index, int maxSize, vector<string> &result, string &currentString, int leftCount, int rightCount, int n) {
    // cout << "Current String: " << currentString << endl;
    if (index == maxSize && leftCount == n && rightCount == n) {
        // cout << "Got some result: " << endl;
        result.push_back(currentString);
        return;
    }

    if (leftCount > n || rightCount > n) {
        // cout << "Bad output: " << endl;
        return;
    }

    if (rightCount > leftCount) {
        // cout << "Bad output: " << endl;
        return;
    }

    currentString.append(1, '(');
    generateParentheses(index+1, maxSize, result, currentString, leftCount+1, rightCount, n);

    // backtrack
    currentString.pop_back();

    currentString.append(1, ')');
    generateParentheses(index+1, maxSize, result, currentString, leftCount, rightCount+1, n);
    // backtrack
    currentString.pop_back();
}

vector<string> generateParenthesis(int n) {
    vector<string> result;

    string currentString = "";
    int leftCount = 0;
    int rightCount = 0;
    generateParentheses(0, 2*n, result, currentString, leftCount, rightCount, n);

    return result;
}

int main() {
    vector<int> inputs = {3, 1, 4, 8};
    vector<vector<string>> outputs = {{"((()))","(()())","(())()","()(())","()()()"}, {"()"}, {}, {}};

    for (int i=0; i<inputs.size(); i++) {
        cout << "Input: " << inputs[i] << endl;

        vector<string> output = generateParenthesis(inputs[i]);
        cout << "Output: " << endl;
        printStrings(output);

        cout << "Expected output: " << endl;
        printStrings(outputs[i]);

        cout << endl;
    }

    return 0;
}

// Remember to use backtracking here