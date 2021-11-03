/*

Problem Description

You are given an integer N and the task is to reverse the digits of the given integer. Return 0 if the result overflows and does not fit in a 32 bit signed integer


Look at the example for clarification.



Problem Constraints
N belongs to the Integer limits.



Input Format
Input an Integer.



Output Format
Return a single integer denoting the reverse of the given integer.



Example Input
Input 1:

 x = 123


Input 2:

 x = -123


Example Output
Output 1:

 321


Ouput 2:

 -321


Example Explanation
 If the given integer is negative like -123 the output is also negative -321.

*/
/*
My code works but locally but it does not work in interview bit!
*/

#include<bits/stdc++.h>
using namespace std;

long reverse(long inputValue) {
    long result = 0;
    while(inputValue > 0){
        long remainder = inputValue % 10;

        result = result * 10 + remainder;

        inputValue = inputValue / 10;
    }

    return result;
}

int solve(int n){
    int result = 0;
    long temp = abs(n);

    long reverseInteger = reverse((long)temp);

    long maxIntegerValue = numeric_limits<int>::max();
    long minIntegerValue = numeric_limits<int>::min();

    // cout << "Reverse value of given input is: " << reverseInteger << endl;

    if(n < 0){
        reverseInteger = -reverseInteger;
        if(reverseInteger < (long) minIntegerValue){
            result = 0;
        } else {
            result = (int) reverseInteger;
        }
    } else {
        if(reverseInteger > (long) maxIntegerValue){
            result = 0;
        } else {
            result = (int) reverseInteger;
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;
    for(int z=0; z<t; z++) {
        int n; 
        cin >> n;
        cout << "Given input is: " << n << endl;
        
        int result = solve(n);
        cout << "Result: " <<  result << endl;

        cout << endl;
    }
    return 0;
}