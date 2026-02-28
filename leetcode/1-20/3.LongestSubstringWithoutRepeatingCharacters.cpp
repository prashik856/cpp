/**
Given a string s, find the length of the longest without duplicate characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Constraints:

    0 <= s.length <= 5 * 104
    s consists of English letters, digits, symbols and spaces.


 */
#include<iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string s = "abcadefgabcea";

    cout << "Input String is: " << s << endl;

    int result = 0;

    int i = 0;
    int n = s.size();
    if (n == 1) {
        return 1;
    }
    int j = i+1;
    int currentMax = 1;
    unordered_map<char, int> dict;
    dict.insert({s[i], 1});
    while (i < n) {
        // cout << "i value : " << i << endl;
        // cout << "j value : " << j << endl;
        char val = s[j];
        // cout << "Character: " << val << endl;
        if (dict.find(s[j]) == dict.end()) {
            // cout << "Not found" << endl;
            // not found
            dict.insert({val, 1});
            currentMax++;
            // cout << "Current Max is : " << currentMax << endl;
            if (currentMax > result) {
                result = currentMax;
            }
            if (j < n-1) {
                j++;
            } else {
                // j > n, we reached our limit
                break;
            }
        } else {
            // found the value
            // cout << "Character found" << endl;
            dict.erase(s[i]);
            currentMax--;
            // cout << "Current Max is : " << currentMax << endl;
            i++;
        }
        // cout << endl;
    }

    // cout << endl << "Result is: " << result << endl;

    return 0;
}

// got accepted