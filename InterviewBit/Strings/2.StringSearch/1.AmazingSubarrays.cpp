/*
You are given a string S, and you have to find all the amazing substrings of S.

Amazing Substring is one that starts with a vowel (a, e, i, o, u, A, E, I, O, U).

Input

Only argument given is string S.
Output

Return a single integer X mod 10003, here X is number of Amazing Substrings in given string.
Constraints

1 <= length(S) <= 1e6
S can have special characters
Example

Input
    ABEC

Output
    6

Explanation
	Amazing substrings of given string are :
	1. A
	2. AB
	3. ABE
	4. ABEC
	5. E
	6. EC
	here number of substrings are 6 and 6 % 10003 = 6.
*/
/*
Easy enough.
Number of subarrays starting from a vowel will be equal to n-i
*/

#include<bits/stdc++.h>
using namespace std;

int solve(string a){
    int result = 0;
    int n = a.size();
    int MOD = 10003;
    for(int i=0; i<a.size(); i++){
        int currentSum = 0;
        if(a[i] == 'a' ||
            a[i] == 'e' ||
            a[i] == 'i' ||
            a[i] == 'o' ||
            a[i] == 'u' ||
            a[i] == 'A' ||
            a[i] == 'E' ||
            a[i] == 'I' ||
            a[i] == 'O' ||
            a[i] == 'U'){
                currentSum += (n-i);
            }
        result += currentSum;
        result = result % MOD;
    }

    return result;
}

int main(){
    string a = "aaaabbbbccccdddd";
    int result = solve(a);
    cout << "Result is: " << result << endl;
    return 0;
}