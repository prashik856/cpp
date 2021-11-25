/*
Problem Description

Reverse the bits of an 32 bit unsigned integer A.



Problem Constraints
0 <= A <= 232



Input Format
First and only argument of input contains an integer A.



Output Format
Return a single unsigned integer denoting the decimal value of reversed bits.



Example Input
Input 1:

 0
Input 2:

 3


Example Output
Output 1:

 0
Output 2:

 3221225472


Example Explanation
Explanation 1:

        00000000000000000000000000000000

=>      00000000000000000000000000000000
Explanation 2:

        00000000000000000000000000000011    
=>      11000000000000000000000000000000
*/
/*
Create bits array and then create the number.
*/

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

unsigned int solve(unsigned int a){
    unsigned int result;
    if(a == 0){
        return a;
    }

    vector<int>bits(32, 0);
    unsigned int temp = a;
    int index = 31;
    while(temp > 0){
        if(temp % 2 == 1){
            bits[index] = 1;
        }
        temp = temp >> 1;
        index--;
    }
    // cout << "Bits array is: " << endl;
    // printVector(bits);

    result = 0;
    for(int i=0; i<32; i++){
        if(bits[i] == 1){
            unsigned int value = pow(2, i);
            result += value;
        }
    }
    return result;
}

int main(){
    unsigned int a = 3;
    unsigned int result = solve(a);
    cout << "Result is: " << result << endl;
    return 0;
}