/*
Given a string s, return the longest palendromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"
Output: "bb"

Constraints:

    1 <= s.length <= 1000
    s consist of only digits and English letters.


 */
#include <iostream>
#include <string>
using namespace std;

string longestPalindrome(string s) {
    string result = "";
    int resultSize = result.size();
    int inputSize = s.size();
    int resultLeft = -1;
    int resultRight = -1;
    for (int i=0; i<s.size(); i++) {
        int index = i;
        int currentLeft = i;
        int currenRight = i;

        // put it in center
        // cout << "Putting it in center " << endl;
        int count = 1;
        int j =1;
        while (index-j>=0 && index+j<inputSize) {
            if (s[index-j] == s[index+j]) {
                count = count + 2;
                currentLeft = index - j;
                currenRight = index + j;
                j++;
            } else {
                break;
            }
        }

        if (count > resultSize) {
            resultSize = count;
            resultLeft = currentLeft;
            resultRight = currenRight;
            // cout << "Result size increased: " << resultSize << endl;
            // cout << "Updated result left : " << resultLeft << endl;
            // cout << "Updated result right: " << resultRight << endl;
        }
        // else {
        //     cout << "Result size remains the same: " << resultSize << endl;
        // }

        // put it at the side
        // cout << "Putting it side by side" << endl;
        count = 0;
        j = 1;
        while (index - j + 1 >= 0 && index + j < inputSize) {
            if (s[index - j + 1] == s[index +j]) {
                currentLeft = index - j + 1;
                currenRight = index + j;
                j++;
                count = count + 2;
            } else {
                break;
            }
        }

        if (count > resultSize) {
            resultSize = count;
            resultLeft = currentLeft;
            resultRight = currenRight;
            // cout << "Result size increased: " << resultSize << endl;
            // cout << "Updated result left : " << resultLeft << endl;
            // cout << "Updated result right: " << resultRight << endl;
        }
        // else {
        //     cout << "Result size remains the same: " << resultSize << endl;
        // }
    }

    for (int i=resultLeft; i<=resultRight; i++) {
        result.append(1, s[i]);
    }
    // cout << "Result Size: " << resultSize << endl;

    return result;
}

int main() {
    string s = "cbbd";
    cout << "Input string is: " << s << endl;

    string result = longestPalindrome(s);

    cout << "Result: " << result << endl;
    return 0;
}

// Got accepted