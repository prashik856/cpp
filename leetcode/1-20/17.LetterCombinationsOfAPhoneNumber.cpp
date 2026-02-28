/**
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

2 - abc
3 - def
4 - ghi
5 - jkl
6 - mno
7 - pqrs
8 - tuv
9 - wxyz

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:

Input: digits = "2"
Output: ["a","b","c"]



Constraints:

    1 <= digits.length <= 4
    digits[i] is a digit in the range ['2', '9'].

 */
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<string> &arr) {
    for (int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

unordered_map<char, string> getDict() {
    unordered_map<char, string> dict = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
    {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    return dict;
}

void getCombinations(int index, string &digits, unordered_map<char, string> &dict, vector<string> &result, string &currentResult) {
    // cout << "Current Result: " << currentResult << endl;

    if (index == digits.size() && currentResult.size() == digits.size()) {
        // cout << "Got some result: " << currentResult << endl;
        result.push_back(currentResult);
        return;
    }

    while (index < digits.size()) {
        char digit = digits[index];
        string mappedValue = dict[digit];

        for (int i=0; i<mappedValue.size(); i++) {
            char mappedChar = mappedValue[i];
            currentResult.append(1, mappedChar);

            // go forward
            getCombinations(index+1, digits, dict, result, currentResult);

            // backtrack
            currentResult.pop_back();
        }

        index++;
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> result;

    unordered_map<char, string> dict = getDict();

    string currentResult = "";
    getCombinations(0, digits, dict, result, currentResult);

    return result;
}

int main() {
    vector<string> inputs = {"23", "2", "7777", "9999"};
    vector<vector<string>> outputs = {{"ad","ae","af","bd","be","bf","cd","ce","cf"}, {"a","b","c"}, {}, {}};

    for (int i=0; i<inputs.size(); i++) {
        cout << "Inputs: " << inputs[i] << endl;
        vector<string> output = letterCombinations(inputs[i]);
        cout << "Output obtained: " << endl;
        printVector(output);

        cout << "Expected Output: " << endl;
        printVector(outputs[i]);

        cout << endl;
    }

    return 0;
}

// Remember to use backtracking and storing the result as we move along
