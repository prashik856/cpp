/**
 * Longest Substring with without repeating characters
 * 
 * 1. Problem Statement Input and Output
 * 2. Identify
 * 3. Relate to Previous Problem
 * 4. Code
 * 
 * Input: pwwkew
 * Output: 3
 * 
 * How is it sliding window?
 * Need to find substring which is longest, and all characters should be unique.
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;

int longestSubstringWithoutRepeatingCharacters(string &input) {
    int output = 0;

    int i=0,j=0;
    unordered_map<char,int> mapping = unordered_map<char, int>();

    while(j < input.size()) {
        char item = input[j];

        if(mapping.find(item) == mapping.end()) {
            // not found
            mapping[item] = 1;
            if(mapping.size() > output) {
                output = mapping.size();
            }
            j++;
        } else if(mapping[item] >= 1) {
            // find and delete the previous entry
            while(mapping.find(item) != mapping.end()) {
                char iValue = input[i];
                mapping.erase(iValue);
                i++;
            }
        }
    }

    return output;
}

int main() {
    string input = "aabacbebebefghij";
    cout << "Input provided: " << input << endl;

    int output = longestSubstringWithoutRepeatingCharacters(input);
    cout << "Output: " << output << endl;
}