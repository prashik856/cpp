/*
Problem Description

Write a function that takes an integer and returns the number of 1 bits it has.


Problem Constraints
1 <= A <= 109


Input Format
First and only argument contains integer A


Output Format
Return an integer as the answer


Example Input
Input1:
    11


Example Output
Output1:
3


Example Explanation
Explaination1:
11 is represented as 1101 in binary 
*/
/*
We have unsigned int. So, we might have an overflow.
Use long instead of int.
*/

#include<bits/stdc++.h>
using namespace std;

int solve(unsigned int a){
    int result = 0;
    if(a == 0){
        return 0;
    }

    long temp = a;
    while(temp > 0){
        if(temp % 2 == 1){
            result++;
        }
        temp = temp >> 1;
    }

    return result;
}

int main(){
    unsigned int a = 4294967295;
    int result = solve(a);
    cout << "Result is: " << result << endl;
    return 0;
}