/*
Problem Description

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Given s = "Hello World",


return 5 as length("World") = 5.

Please make sure you try to solve this problem without using library functions. Make sure you only traverse the string once.
*/
/*
Easy.
Just start with last character.
*/
#include<bits/stdc++.h>
using namespace std;

int solve(string a){
    int n = a.size();
    bool wordEncountered = false;
    int result = 0;
    for(int i=n-1; i>=0; i--){
        if(!wordEncountered && a[i] == ' '){
            continue;
        } else if(!wordEncountered && a[i] != ' '){
            wordEncountered = true;
            result++;
        } else if(wordEncountered && a[i] != ' '){
            result++;
        } else if(wordEncountered && a[i] == ' '){
            break;
        }
    }
    return result;
}

int main(){
    string text = "Hello World   ";
    int result = solve(text);
    cout << "Result is: " << result << endl;
    return 0;
}