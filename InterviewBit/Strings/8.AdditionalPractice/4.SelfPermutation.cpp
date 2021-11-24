/*
Problem Description
 
 

You are given two strings A and B.
Check whether there exists any permutation of both A and B such that they are equal.

Return a single integer 1 if its exists, 0 otherwise.



Problem Constraints
1 <= |A|, |B| <= 105
Both strings contain only lowercase english alphabets.


Input Format
The first argument is the string A. The second argument is the string B.


Output Format
Return a single integer 1 if a permutation exists, 0 otherwise.


Example Input
Input 1:
A = 'scaler'
B = 'relasc'
Input 2:

A = 'scaler'
B = 'interviewbit'


Example Output
Output 1:
1
Output 2:

0


Example Explanation
Explanation 1:
We can rearrange the second string to 'scaler', hence, a permuation exists.
Explanation 2:

The given length of the two strings itself is different. There is no possible permutation.
*/
/*
Just check all counts
*/
#include<bits/stdc++.h>
using namespace std;

int solve(string a, string b){
    int result = 1;
    vector<int> aCount(26, 0);
    vector<int> bCount(26, 0);
    int n = a.size();
    int m = b.size();
    if(n != m){
        return 0;
    }
    for(int i=0; i<n; i++){
        int start = 'a';
        int aIndex = a[i] - start;
        int bIndex = b[i] - start;
        aCount[aIndex]++;
        bCount[bIndex]++;
    }
    for(int i=0; i<26; i++){
        if(aCount[i] != bCount[i]){
            return 0;
        }
    }

    return result;
}

int main(){
    string a = "scaler";
    string b = "relasc";
    int result = solve(a, b);
    cout << "Result is: " << result << endl;
    return 0;
}