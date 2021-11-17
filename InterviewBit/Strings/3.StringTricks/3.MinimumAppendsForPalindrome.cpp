/*
Problem Description

Given a string A consisting of lowercase characters.

We need to tell minimum characters to be appended (insertion at end) to make the string A a palindrome.



Problem Constraints
1 <= |A| <= 105

A consists only of lower-case characters.



Input Format
First argument is an string A.



Output Format
Return a integer denoting the minimum characters to be appended (insertion at end) to make the string A a palindrome.



Example Input
Input 1:

 A = "abede"
Input 2:

 A = "aabb"


Example Output
Output 1:

 2
Output 2:

 2


Example Explanation
Explanation 1:

 We can make string palindrome as "abedeba" by adding ba at the end of the string.
Explanation 2:

 We can make string palindrome as "aabbaa" by adding aa at the end of the string.
*/
/*
Solution approach:
We already know the approach to make a string palindrome by inserting elements at the start of the string.
Here, we will just reverse our string and repeat this process!

Same question, just asked differently.
*/

#include<bits/stdc++.h>
using namespace std;

int solve(string a){
    int result = 0;
    int n = a.size();
    string temp;
    for(int i=n-1; i>=0; i--){
        temp.push_back(a[i]);
    }

    // Now we have our reverse string and forward string.
    temp.push_back('$');
    temp = temp + a;
    n = temp.size();
    // Create lps for this guy
    int len = 0;
    vector<int> lps(n, 0);
    for(int i=1; i<n; i++){
        if(temp[len] == temp[i]){
            len++;
            lps[i] = len;
        } else {
            if(len > 0){
                len = lps[len - 1];
                i--;
            } else {
                lps[i] = len;
            }
        }
    }
    result = a.size() - lps[n-1];
    return result;
}

int main(){
    string a = "aabb";
    int result = solve(a);
    cout << "Result is: " << result << endl;
    return 0;
}