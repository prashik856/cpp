/*
Problem Discription:

Given an string A. The only operation allowed is to insert  characters in the beginning of the string.

Find how many minimum characters are needed to be inserted to make the string a palindrome string.




Input Format

The only argument given is string A.
Output Format

Return the minimum characters that are needed to be inserted to make the string a palindrome string.
For Example

Input 1:
    A = "ABC"
Output 1:
    2
    Explanation 1:
        Insert 'B' at beginning, string becomes: "BABC".
        Insert 'C' at beginning, string becomes: "CBABC".

Input 2:
    A = "AACECAAAA"
Output 2:
    2
    Explanation 2:
        Insert 'A' at beginning, string becomes: "AAACECAAAA".
        Insert 'A' at beginning, string becomes: "AAAACECAAAA".
*/
/*
Solution Approach:
https://www.geeksforgeeks.org/minimum-characters-added-front-make-string-palindrome/
We can solve this problem efficiently in O(n) time using lps array of KMP algorithm. 
First we concat string by concatenating given string, a special character and reverse of given string then we will get 
lps array for this concatenated string, 
recall that each index of lps array represent longest proper prefix which is also suffix. 
We can use this lps array for solving the problem.

For string = AACECAAAA
Concatenated String = AACECAAAA$AAAACECAA
LPS array will be {0, 1, 0, 0, 0, 1, 2, 2, 2, 
                   0, 1, 2, 2, 2, 3, 4, 5, 6, 7}
> Here we are only interested in the last value of this lps array because it shows us the largest suffix of the 
reversed string that matches the prefix of the original string 
i.e these many characters already satisfy the palindrome property. 
Finally minimum number of character needed to make the string a palindrome is length of the input string 
minus last entry of our lps array.
*/

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int solve(string a){
    int result = 0;
    int n = a.size();

    string temp = a;
    temp.push_back('$');
    for(int i=n-1; i>=0; i--){
        temp.push_back(a[i]);
    }
    
    vector<int> lps(temp.size(), 0);
    int len = 0;
    for(int i=1; i<temp.size(); i++){
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
    // printVector(lps);

    result = n - lps[temp.size() - 1];

    return result;
}

int main(){
    string a = "ABAAAB";
    int result = solve(a);
    cout << "Result is: " << result << endl;
    return 0;
}