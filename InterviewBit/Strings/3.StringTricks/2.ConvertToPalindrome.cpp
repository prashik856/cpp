/*
Problem Description

Given a string A consisting only of lowercase characters, we need to check whether it is possible to make this string a palindrome after removing exactly one character from this.

If it is possible then return 1 else return 0.



Problem Constraints
3 <= |A| <= 105

 A[i] is always a lowercase character.



Input Format
First and only argument is an string A.



Output Format
Return 1 if it is possible to convert A to palindrome by removing exactly one character else return 0.



Example Input
Input 1:

 A = "abcba"
Input 2:

 A = "abecbea"


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 We can remove character ‘c’ to make string palindrome
Explanation 2:

 It is not possible to make this string palindrome just by removing one character 
*/
/*
Solution approach:
1. If the given string is already palindrome, it is always possible.
2. If the given string is not palindrome for two indices, low and high.
We have 2 choices, either remove low and check, or either remove high and check.
That's it.
*/
#include<bits/stdc++.h>
using namespace std;

int solve(string a){
    int result = 0;
    int n = a.size();
    int low = 0;
    int high = n - 1;
    bool isPalindrome = true;
    int removableLow = -1;
    int removableHigh = -1;
    while(low <= high){
        if(a[low] == a[high]){
            low++;
            high--;
        } else {
            isPalindrome = false;
            removableLow = low;
            removableHigh = high;
            break;
        }
    }

    if(isPalindrome){
        return 1;
    } else {
        isPalindrome = true;
        // remove low
        low = 0;
        high = n-1;
        while(low <= high){
            if(low == removableLow){
                low++;
            }
            if(low <= high && a[low] == a[high]){
                low++;
                high--;
            } else {
                isPalindrome = false;
                break;
            }
        }
        if(isPalindrome){
            return 1;
        }

        // remove high
        low = 0;
        high = n-1;
        while(low <= high){
            if(high == removableHigh){
                high--;
            }
            if(low <= high && a[low] == a[high]){
                low++;
                high--;
            } else {
                isPalindrome = false;
                break;
            }
        }
        if(isPalindrome){
            return 1;
        }
    }       

    return result;
}

int main(){
    string a = "abecbea";
    int result = solve(a);
    cout << "Result is: " << result << endl;
    return 0;
}