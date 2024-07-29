/**
 * Longest Substring with K unique characters
 * 
 * 1. Input Output and Problem Statement
 * 2. Identification
 * 3. General Format
 * 4. Explanation
 * 5. Code
 * 
 * Input Output:
 * String: aabacbebebe
 * Integer K: 3
 * We need to find longest substring, where there are k unique characters.
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

int largestSubstringWithKUniqueCharacters(string &input, int k) {
    int i=0,j=0;
    unordered_map<char, int> mapping = unordered_map<char, int>();
    int count = 0;
    int output = 0;

    while(j < input.size()) {
        char item = input[j];

        if(count < k) {
            // process j
            if(mapping.find(item) == mapping.end()) {
                // new item
                mapping[item] = 1;
                count++;
            } else {
                // already here
                mapping[item] = mapping[item] + 1;
            }
            j++;
        } else if(count == k) {
            // process j
            if(mapping.find(item) == mapping.end()) {
                // new item
                mapping[item] = 1;
                count++;
            } else {
                // already here
                mapping[item] = mapping[item] + 1;
            }

            // got some output
            int width = j - i + 1; // j is ahead
            if(width > output) {
                output = width;
            }
            j++;
        } else if(count > k) {
            while(count > k) {
                // process i
                char iValue = input[i];
                if(mapping[iValue] == 1) {
                    // only once
                    mapping.erase(iValue);
                    count--;
                } else {
                    mapping[iValue] = mapping[iValue] - 1;
                }

                // increment i
                i++;
            }
        }
    }
    return output;
}

int main() {
    string input = "aabacdbebebe";
    int k = 5;
    cout << "Input String: " << input << endl;
    cout << "Number of Unique Characters: " << k << endl;

    int output = largestSubstringWithKUniqueCharacters(input, k);
    cout << "Output is: " << output << endl;

    return 0;
}