/**
 * Minimum Window Substring
 * 
 * Flow: 
 * 1. Problem Statement, Input, Output
 * 2. Identification
 * 3. Explanation
 * 4. Code
 * 
 * Input:
 * String s = "timetopractice"
 * string t = "toc"
 * 
 * Output: "toprac", 6
 * 
 * We need to ge the minimum window substring where:
 * 1. all the letters of string t with at least same quantity should be present in string s.
 * It is okay if the letters are present more than once in the string s.
 * 
 * Explanation:
 * 
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int minimumWindowSubstring(string &s, string &t) {
    int output = INT_MAX;

    int i=0,j=0;
    vector<int> patternMapping = vector<int>(26, 0);
    int patternCount=0;
    for(int i=0; i<t.size(); i++) {
        int value = int(t[i]) - int('a');
        patternMapping[value]++;
    }

    vector<int> stringMapping = vector<int>(26, 999999);
    for(int i=0; i<26; i++) {
        if(patternMapping[i] != 0) {
            stringMapping[i] = patternMapping[i];
            patternCount++;
        }
    }

    cout << "Count Value: " << patternCount << endl;
    cout << "Pattern Mapping: " << endl;
    printVector(patternMapping);

    cout << "String Mapping: " << endl;
    printVector(stringMapping);

    int count = 0;
    while(j<s.size()) {
        cout << "i: " << i << " | j: " << j << endl;
        int item = int(s[j]) - int('a');
        if(count < patternCount) {
            // process j
            stringMapping[item]--;
            if(stringMapping[item] == 0) {
                count++;
            }
            j++;
        } else if(count == patternCount) {
            // Got some output
            int width = j - i;
            if(width < output) {
                output = width;
            }
            cout << "Got Possible Solution: " << output << endl;

            // process i
            while(count == patternCount) {
                cout << "Optimizing..." << endl;
                int iValue = int(s[i]) - int('a');

                stringMapping[iValue]++;
                // positive
                if(stringMapping[iValue] == 1) {
                    count--;
                }
                i++;

                if(count == patternCount) {
                    int width = j-i;
                    if(width < output) {
                        output = width;
                        cout << "New Optimized Output: " << output << endl;
                        cout << "i: " << i << " | j: " << j << endl;
                    }
                }
            }

            // process j
            stringMapping[item]--;
            if(stringMapping[item] == 0) {
                count++;
            }
            j++;
        }

        // last input, mappings are updated, process it.
        if(j == s.size()) {
            if(count == patternCount) {
                int width = j - i;
                if(width < output) {
                    output = width;
                }
            }
        }
    }

    return output;
}

int main() {
    string s = "totmtaptat";
    string t = "tta";
    cout << "Input string: " << s << endl;
    cout << "Pattern: " << t << endl;

    int output = minimumWindowSubstring(s,t);
    cout << "Output: " << output << endl;

    return 0;
}