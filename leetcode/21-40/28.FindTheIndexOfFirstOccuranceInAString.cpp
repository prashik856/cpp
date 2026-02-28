/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

Constraints:

    1 <= haystack.length, needle.length <= 104
    haystack and needle consist of only lowercase English characters.

 */
#include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle) {
    int result = -1;

    int needleSize = needle.size();
    for (int i=0; i<haystack.size(); i++) {
        int firstIndex = i;
        int lastIndex = i + needleSize - 1;

        if (lastIndex < haystack.size() && haystack[firstIndex] == needle[0] && haystack[lastIndex] == needle[needle.size() - 1]) {
            // Search the whole string now
            int from = firstIndex + 1;
            int to = lastIndex - 1;
            int needleIndex = 1;

            bool found = true;
            while (from <= to) {
                if (haystack[from] != needle[needleIndex]) {
                    found = false;
                    break;
                }
                from++;
                needleIndex++;
            }

            if (found) {
                result = firstIndex;
                break;
            }
        }
    }

    return result;
}

int main( ) {
    vector<string> inputs = {"sadbutsad", "leetcode", "sadbutsad"};
    vector<string> toFind = {"sad", "leeto", "but"};
    vector<int> outputs = {0, -1, 3};

    for (int i=0; i<inputs.size(); i++) {
        cout << "Input: " << inputs[i] << endl;
        cout << "Value to find: " << toFind[i] << endl;

        int output = strStr(inputs[i], toFind[i]);
        cout << "Output: " << output << endl;

        cout << "Expected output: " << outputs[i] << endl;

        cout << endl;
    }
    return 0;
}

// Accepted