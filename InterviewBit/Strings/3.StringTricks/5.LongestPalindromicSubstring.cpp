/*
Problem Description

Given a string A of size N, find and return the longest palindromic 
substring in A.

Substring of string A is A[i...j] where 0 <= i <= j < len(A)

Palindrome string:

A string which reads the same backwards. 
More formally, A is palindrome if reverse(A) = A.

Incase of conflict, return the substring which occurs first 
( with the least starting index).



Input Format
First and only argument is a string A.



Output Format
Return a string denoting the longest palindromic substring of string A.



Example Input
A = "aaaabaaa"


Example Output
"aaabaaa"


Example Explanation
We can see that longest palindromic substring is of length 7 and the string is "aaabaaa".
*/
/*
Rather than DP, our simple Idea worked.
The idea is taken from here:
https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-1/?ref=rp

We need to check Palindrome condition from each index.
Either as current index as center (count = 1), 
or current index as not a center(count =0),
and then we move out accordingly.
*/

#include<bits/stdc++.h>
using namespace std;

void print2DVector(vector< vector<int> > arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

string solve(string a){
    string result = "";
    int n = a.size();
    
    int startPosition = -1;
    int endPosition = -1;
    int maxSize = 0;
    for(int i=0; i<a.size(); i++){

        int j = i-1;
        int k = i+1;
        int count = 1;
        // cout << "Center as " << i << endl;
        // cout << "j: " << j << endl;
        // cout << "k: " << k << endl;
        // with center as i;
        while(j >=0 && k<n){
            // cout << "a[j]: " << a[j] << endl;
            // cout << "a[k]: " << a[k] << endl;
            if(a[j] == a[k]){
                count++;
                count++;
            } else {
                break;
            }
            j--;
            k++;
        }
        // cout << "Count: " << count << endl;
        if(count > maxSize){
            maxSize = count;
            startPosition = j;
            endPosition = k;
            // cout << "Max size: " << maxSize << endl;
            // cout << "Start: " << startPosition << endl;
            // cout << "End: " << endPosition << endl;
        }

        // with no center
        j = i;
        k = i+1;
        count = 0;
        // cout << "No Center" << endl;
        // cout << "j: " << j << endl;
        // cout << "k: " << k << endl;
        while(j >=0 && k<n){
            if(a[j] == a[k]){
                count++;
                count++;
            } else {
                break;
            }
            j--;
            k++;
        }
        if(count > maxSize){
            maxSize = count;
            startPosition = j;
            endPosition = k;
            // cout << "Max size: " << maxSize << endl;
            // cout << "Start: " << startPosition << endl;
            // cout << "End: " << endPosition << endl;
        }
        // cout << endl;
    }
    if(maxSize == 1){
        result.push_back(a[0]);
        return result;
    } else {
        if(startPosition >= 0 && endPosition < n){
            startPosition++;
            endPosition--;
        }
        else if(startPosition < 0 && endPosition < n){
            startPosition = 0;
            endPosition--;
        }
        else if(startPosition >= 0 && endPosition >= n ){
            startPosition++;
            endPosition = n - 1;
        }
        else if(startPosition < 0 && endPosition >= n){
            startPosition = 0;
            endPosition = n-1;
        }
        for(int i=startPosition; i<=endPosition; i++){
            result.push_back(a[i]);
        }
    }
    return result;
}

int main(){
    string a = "bccbcbcacbab";
    cout << "Given input string is: " << a << endl;
    string result = solve(a);
    cout << "Result is: " << result << endl;
    return 0;
}