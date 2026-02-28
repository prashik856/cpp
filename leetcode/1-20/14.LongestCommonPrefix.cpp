/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Constraints:
    1 <= strs.length <= 200
    0 <= strs[i].length <= 200
    strs[i] consists of only lowercase English letters if it is non-empty.

 */
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<string> arr) {
    for (int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

string longestCommonPrefix(vector<string>& strs) {
    string result = "";

    if (strs.size() == 0) {
        return result;
    }

    for (int i=0; i<strs.size(); i++) {
        if (strs[i].size() == 0) {
            return result;
        }
    }

    int index = 0;

    while (true) {
        char val = 0;
        if (strs[0].size() > index) {
            val = strs[0][index];
        } else {
            break;
        }

        bool found = true;
        for (int i=0; i<strs.size(); i++) {
            if (strs[i].size() <= index || strs[i][index] != val) {
                found = false;
                break;
            }
        }

        if (!found) {
            break;
        }

        result.append(1, val);

        index++;
    }

    return result;
}

int main() {
    vector< vector<string> > inputs = {{"flower","flow","flight"}, {"dog","racecar","car"}};
    vector<string> outputs = {"fl", ""};

    for (int i=0; i<inputs.size(); i++) {
        cout << "Inputs: " << endl;
        printVector(inputs[i]);

        string output = longestCommonPrefix(inputs[i]);

        cout << "Output: " << output << endl;
        cout << "Expected output: " << outputs[i] << endl;
        cout << endl;
    }

    return 0;
}