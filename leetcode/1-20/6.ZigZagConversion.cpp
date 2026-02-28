/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R


And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I

Example 3:

Input: s = "A", numRows = 1
Output: "A"

Constraints:

    1 <= s.length <= 1000
    s consists of English letters (lower-case and upper-case), ',' and '.'.
    1 <= numRows <= 1000

*/
#include <iostream>
#include <string>
#include<vector>
using namespace std;

void printVector(vector<string> &arr) {
    for (int i=0; i<arr.size(); i++) {
        cout << arr[i] << endl;
    }
}

string convert(string s, int numRows) {
    if (numRows == 1) {
        return s;
    }
    // Initialize the vector
    string result = "";

    // cout << "Initializing our vector string" << endl;
    vector<string> arr(numRows, "");

    // cout << "Vector after initializing: " << endl;
    // printVector(arr);

    bool down = true;
    bool up = false;
    int i=0;
    int count = 0;
    int maxCount = s.size();
    // PAYPALISHIRING
    while (count < maxCount) {
        if (down) {
            // cout << "Going down" << endl;
            arr[i].append(1, s[count]);
            count++;
            i++;

            if (i == numRows) {
                // cout << "Cannot go down any further" << endl;
                down = false;
                up = true;
                i = i - 2;
                continue;
            }
        }

        if (up) {
            // cout << "Going up" << endl;
            arr[i].append(1, s[count]);
            count++;
            i--;

            if (i < 0) {
                // cout << "Cannot go up any further" << endl;
                down = true;
                up = false;
                i = i + 2;
            }
        }
    }

    for (int j=0; j<numRows; j++) {
        for (int k=0; k<arr[j].size(); k++) {
            result.append(1, arr[j][k]);
        }
    }

    return result;
}

int main() {
    string s = "AB";
    int numRows = 2;

    cout << "Input string s: " << s << endl;
    cout << "Number of rows: " << numRows << endl;

    string result = convert(s, numRows);

    cout << "Result: " << result << endl;

    return 0;
}