/*
Given a string A.

Return the string A after reversing the string word by word.

NOTE:

A sequence of non-space characters constitutes a word.

Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.

If there are multiple spaces between words, reduce them to a single space in the reversed string.




Input Format

The only argument given is string A.
Output Format

Return the string A after reversing the string word by word.
For Example

Input 1:
    A = "the sky is blue"
Output 1:
    "blue is sky the"

Input 2:
    A = "this is ib"
Output 2:
    "ib is this"
*/
/*
Easy solution.
My solution works, but it doesn't work on interview bit. Fuck it.

*/

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<string> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

string solve(string a){
    string result = "";
    int n = a.size();
    vector<string> words;
    string currentWord = "";
    for(int i=0; i<n; i++){
        if(a[i] == ' '){
            if(currentWord.size() > 0){
                words.push_back(currentWord);
            }
            currentWord = "";
        } else {
            currentWord.push_back(a[i]);
        }
    }
    if(currentWord.size() > 0){
        words.push_back(currentWord);
    }

    for(int i=words.size() -1; i>=0; i--){
        for(int j=0; j<words[i].size(); j++){
            result.push_back(words[i][j]);
        }
        if( i < n-1){
            result.push_back(' ');
        }
    }
    // printVector(words);

    return result;
}

int main(){
    string text = "fwbpudnbrozzifml osdt ulc jsx kxorifrhubk ouhsuhf sswz qfho dqmy sn myq igjgip iwfcqq";
    string result = solve(text);
    cout << "Result is: " << result << endl;
    return 0;
}