/*
Problem Description

Given the array of strings A, 
you need to find the longest string S which is the prefix 
of ALL the strings in the array.

Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2.

For Example: longest common prefix of "abcdefgh" and "abcefgh" is "abc".



Input Format
The only argument given is an array of strings A.



Output Format
Return the longest common prefix of all strings in A.



Example Input
Input 1:

A = ["abcdefgh", "aefghijk", "abcefgh"]
Input 2:

A = ["abab", "ab", "abcd"];


Example Output
Output 1:

"a"
Output 2:

"ab"


Example Explanation
Explanation 1:

Longest common prefix of all the strings is "a".
Explanation 2:

Longest common prefix of all the strings is "ab".
*/
/*
Solution Approach:
https://www.geeksforgeeks.org/longest-common-prefix-using-word-by-word-matching/
https://www.geeksforgeeks.org/longest-common-prefix-using-character-by-character-matching/
We can just use character matching!

Simple character matching worked.
*/

#include<bits/stdc++.h>
using namespace std;

string solve(vector<string> a){
    int n = a.size();
    string result = "";
    int minSize = 999999999;
    for(int i=0; i<a.size(); i++){
        minSize = min(minSize, (int) a[i].size());
    }
    // cout << "Minimum sized string: " << minSize << endl;
    
    int index = 0;
    bool breakLoop = false;
    while(index < minSize && !breakLoop){
        char val = a[0][index];
        for(int i=1; i<a.size(); i++){
            if(a[i][index] != val){
                breakLoop = true;
                break;
            }
        }
        if(!breakLoop){
            index++;
            result.push_back(val);
        }
    }
    return result;
}

int main(){
    vector<string> a = {"abab", "ab", "abcd"};
    string result = solve(a);
    cout << "Result is: " << result << endl;
    return 0;
}