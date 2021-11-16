/*
Another question which belongs to the category of questions which are intentionally stated vaguely. 

Expectation is that you will ask for correct clarification or you will state your assumptions before you start coding.

Implement strStr().

strstr - locate a substring ( needle ) in a string ( haystack ).

Try not to use standard library string functions for this question.

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

NOTE:

Good clarification questions:

What should be the return value if the needle is empty?

What if both haystack and needle are empty?

For the purpose of this problem, assume that the return value should be -1 in both cases.
*/
/*
Solution Approach:
Check the first and last guy first, if they are equal, try to equate the whole substring.
*/
#include<bits/stdc++.h>
using namespace std;

int solve(string a, string b){
    int result = -1;

    int n = a.size();
    int m = b.size();

    if(m > n){
        return result;
    }
    if(m == 0){
        return result;
    }
    if(n == 0){
        return result;
    }

    for(int i=0; i<n; i++){
        if(i+m-1 < n && a[i] == b[0] && a[i+m-1] == b[m-1]){
            bool found = true;
            int index = i;
            for(int j=0; j<m; j++){
                if(b[j] == a[index]){
                    index++;
                } else {
                    found = false;
                    break;
                }
            }
            if(found){
                result = i;
                return result;
            }
        } else if(i+m-1 >=n){
            break;
        }
    }

    return result;
}

int main(){
    string a = "abcdef";
    string b = "bce";
    int result = solve(a, b);
    cout << "Result is: " << result << endl;
    return 0;
}