/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example:

"A man, a plan, a canal: Panama" is a palindrome.

"race a car" is not a palindrome.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/

/*
Take care of other unwanted characters.
Just use two pointers.
*/

#include<bits/stdc++.h>
using namespace std;

int solve(string a){
    string b;
    for(int i=0; i<a.size(); i++){
        char val = a[i];
        if((val >= '0' && val <= '9') ||
            (val >= 'A' && val <= 'Z') ||
            (val >= 'a' && val <= 'z')){
                val = tolower(val);
                b.push_back(val);
            }
    }
    cout << "B string is: " << b << endl;

    int n = b.size();
    int high = n-1;
    int low = 0;
    while(low <= high){
        if(b[low] != b[high]){
            return 0;
        }
        low++;
        high--;
    }
    return 1;
}

int main(){
    string a = "A man, a plan, a canal: Panama";
    int result = solve(a);
    cout << "Result is: " << result << endl;
    return 0;
}