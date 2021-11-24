/*
Problem Description

Given two binary strings, return their sum (also a binary string).
Example:

a = "100"


b = "11"
Return a + b = "111".
*/
/*
Solution Approach:
Just make the strings of equal length first.
Then take care of currentCarry and currentSum.
Take care of leading zeroes.
*/
#include<bits/stdc++.h>
using namespace std;

string solve(string a, string b){
    string result = "";

    int n = a.size();
    int m = b.size();

    if(n == 0 && m == 0){
        return "0";
    }
    if(n == 0){
        return b;
    }
    if(m == 0){
        return a;
    }

    int difference = 0;
    // result can overflow by max 1 digit
    if(n > m){
        result = string(n+1, '0');
        difference = n - m;
        string zeroString = string(difference, '0');
        b = zeroString + b;
    } else {
        result = string(m+1, '0');
        difference = m - n;
        string zeroString = string(difference, '0');
        a = zeroString + a;
    }
    // if(a.size() == b.size()){
        // cout << "Now they are of equal size!" << endl;
        // cout << a << endl;
        // cout << b << endl;
    // }
    int maxLength = max(n,m);

    int index = maxLength;
    char carry = '0';
    char currentSum = '0';
    for(int i=maxLength - 1; i>=0; i--){
        char valA = a[i];
        char valB = b[i];
        // cout << "Value of a: " << valA << endl;
        // cout << "Value of b: " << valB << endl;

        if(valA == '0' && valB == '0'){
            // cout << "Enitial carry: " << carry << endl;
            if(carry == '0'){
                currentSum = '0';
            } else {
                currentSum = '1';
            }

            // set result
            result[index] = currentSum;
            index--;

            // set carry and current sum
            carry = '0';
            // cout << "Carry : " << carry << endl;
            // cout << "Sum: " << currentSum << endl;
            currentSum = '0';
        } else if(valA == '0' && valB == '1'){
            // cout << "Enitial carry: " << carry << endl;
            if(carry == '0'){
                currentSum = '1';
                carry = '0';
            } else {
                currentSum = '0';
                carry = '1';
            }
            result[index] = currentSum;
            index--;

            // cout << "Carry : " << carry << endl;
            // cout << "Sum: " << currentSum << endl;
            currentSum = '0';
        } else if(valA == '1' && valB == '0'){
            // cout << "Enitial carry: " << carry << endl;
            if(carry == '0'){
                currentSum = '1';
                carry = '0';
            } else {
                currentSum = '0';
                carry = '1';
            }
            result[index] = currentSum;
            index--;

            // cout << "Carry : " << carry << endl;
            // cout << "Sum: " << currentSum << endl;
            currentSum = '0';
        } else if(valA == '1' && valB == '1'){
            // cout << "Enitial carry: " << carry << endl;
            if(carry == '0'){
                currentSum = '0';
                carry = '1';
            } else {
                currentSum = '1';
                carry = '1';
            }
            result[index] = currentSum;
            index--;

            // cout << "Carry : " << carry << endl;
            // cout << "Sum: " << currentSum << endl;
            currentSum = '0';
        }
        // cout << endl;
    }
    result[index] = carry;
    // cout << "Current result obtained: " << result << endl;

    if(result[0] == '0'){
        // cout << "Result has leading zeroes" << endl;
        index = 0;
        while(result[index] == '0'){
            index++;
        }
        string newResult = string(result.begin() + index, result.end());
        return newResult;
    } else {
        return result;
    }

    return result;
}

int main(){
    string a = "1";
    string b = "1";
    string result = solve(a,b);
    cout << "Result is: " << result << endl;
    return 0;
}