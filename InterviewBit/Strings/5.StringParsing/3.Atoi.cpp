/*
There are certain questions where the interviewer would intentionally frame the question vague.

The expectation is that you will ask the correct set of clarifications or state your assumptions before you jump into coding.

Implement atoi to convert a string to an integer.

Example :

Input : "9 2704"
Output : 9
Note: There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.

Questions:

Q1. Does string contain whitespace characters before the number?

A. Yes

Q2. Can the string have garbage characters after the number?

A. Yes. Ignore it.

Q3. If no numeric character is found before encountering garbage characters, what should I do?

A. Return 0.

Q4. What if the integer overflows?

A. Return INT_MAX if the number is positive, INT_MIN otherwise.

Warning : DO NOT USE LIBRARY FUNCTION FOR ATOI.

If you do, we will disqualify your submission retroactively and give you penalty points.
*/
/*
Got it. 
Needed to handle a lot of cases.
*/

#include<bits/stdc++.h>
using namespace std;

int solve(string a){
    int n = a.size();
    bool encounteredNumber = false;
    bool encounteredSign = false;
    bool positiveSign = true;
    bool negativeSign = false;
    string temp;
    int index = 0;
    for(int i=0; i<n; i++){
        if(a[i] == ' '){
            continue;
        } else {
            index = i;
            break;
        }
    }
    // cout << "First non space character is: " << a[index] << endl;

    if(a[index] == '+' || a[index] == '-'){
        // cout << "We encountered a sign" << endl;
        encounteredSign = true;
        if(a[index] == '-'){
            negativeSign = true;
            positiveSign = false;
            index++;
        } else {
            positiveSign = true;
            negativeSign = false;
            index++;
        }
    }

    // We did not encounter sign, nor a number
    if(!encounteredSign && !(a[index] >= '0' && a[index] <= '9')){
        // cout << "No sign. Not a number." << endl;
        return 0;
    }

    // We encountered sign, but next index is not a number
    if(encounteredSign && !(a[index] >= '0' && a[index] <= '9')){
        // cout << "Sign. But next number is not a number." << endl;
        return 0;
    }

    if(a[index] >= '0' && a[index] <= '9'){
        for(int i=index; i<n; i++){
            bool isNumber = (a[i] >= '0' && a[i] <= '9');
            if(isNumber){
                temp.push_back(a[i]);
            } else{
                break;
            }
        }
    }

    int m = temp.size();
    long result = 0;
    long intmax = (long) abs( (long) INT_MIN);
    bool greater = false;
    // cout << temp << endl;
    for(int i=0; i<m; i++){
        int num = (int) temp[i];
        num = num - 48;

        result *= 10;
        result += num;

        if(result >= intmax){
            greater = true;
            break;
        }
    }

    if(greater){
        if(positiveSign){
            return INT_MAX;
        } else {
            return INT_MIN;
        }
    }

    if(negativeSign){
        return (int) -result;
    }

    return (int) result;
}

int main(){
    string text = "-88297 248252140B12 37239U4622733246I218 9 1303 44 A83793H3G2 1674443R591 4368 7 97";
    int result = solve(text);
    cout << "Result is: " << result << endl;
    return 0;
}