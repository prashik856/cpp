/*
Problem Description

Given a string A of size N, find and return the longest palindromic substring in A.

Substring of string A is A[i...j] where 0 <= i <= j < len(A)

Palindrome string:

A string which reads the same backwards. More formally, A is palindrome if reverse(A) = A.

Incase of conflict, return the substring which occurs first ( with the least starting index).



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
    string b;

    // for backtracking
    int tempResult = 0;
    int maxValueRow = 0;
    int maxValueColumn = 0;
    
    vector< vector<int> > table(n + 1, vector<int>(n+1, -1));
    for(int i=n; i>=0; i--){
        table[i][0] = 0;
        table[0][i] = 0;
        if(i == n){
            continue;
        } else {
            b.push_back(a[i]);
        }
    }
    // cout << "Initial table is: " << endl;
    // print2DVector(table);
    // cout << "Reversed string is: " << endl;
    // cout << b << endl;

    // Simple Longest Common Substring code
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){

            if(a[i-1] == b[j-1]){
                table[i][j] = 1 + table[i-1][j-1];
            }
            else{
                table[i][j] = 0;
            }
            
            if(table[i][j] > tempResult){
                tempResult = table[i][j];
                maxValueRow = i;
                maxValueColumn = j;
            }

        }
    }

    print2DVector(table);
    cout << "Longest Common substring length is: " << tempResult << endl;
    cout << "Row: " << maxValueRow << " | Column: " << maxValueColumn << endl; 

    // Backtrack
    int i=maxValueRow, j=maxValueColumn;
    while(i>0 && j>0){
        result.push_back(a[i-1]);
        i--;j--;
    }

    return result;
}

int main(){
    string a = "abacdfgdcaba";
    string result = solve(a);
    cout << "Result is: " << result << endl;
    return 0;
}