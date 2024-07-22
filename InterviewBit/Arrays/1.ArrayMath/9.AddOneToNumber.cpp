/*
Problem Description

Given a non-negative number represented as an array of digits,
 add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit 
is at the head of the list.

NOTE: Certain things are intentionally left unclear in this question 
which you should practice asking the interviewer. For example: 
for this problem, following are some good questions to ask :

Q : Can the input have 0's before the most significant digit. 
Or in other words, is 0 1 2 3 a valid input?
A : For the purpose of this question, YES
Q : Can the output have 0's before the most significant digit? 
Or in other words, is 0 1 2 4 a valid output?
A : For the purpose of this question, NO. 
Even if the input has zeroes before the most significant digit.


Input Format
First argument is an array of digits.



Output Format
Return the array of digits after adding one.



Example Input
Input 1:

[1, 2, 3]


Example Output
Output 1:

[1, 2, 4]


Example Explanation
Explanation 1:

Given vector is [1, 2, 3].
The returned vector should be [1, 2, 4] as 123 + 1 = 124.
*/

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr) {
    int n = arr.size();
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


vector<int> solve(vector<int> &A) {
    // Remove leading zeros
    int n = A.size();

    bool foundNonZero = false;
    vector<int> arr;
    int index = 0;
    while(!foundNonZero) {
        if(A[index] > 0) {
            foundNonZero = true;
        } else {
            index++;
        }
    }

    for(int i=index; i<n; i++) {
        arr.push_back(A[i]);
    }

    cout << "Input array became: " << endl;
    printVector(arr);

    // check if arry is empty
    if(arr.size() == 0){
        arr.push_back(1);
        return arr;
    }

    int m = arr.size();
    int valueToAdd = 1;
    for(int i=m-1; i>=0; i--) {
        int value = arr[i];
        value += valueToAdd;
        valueToAdd = value / 10;
        if(valueToAdd > 0) {
            arr[i] = 0;
            continue;
        } else {
            arr[i] = value;
            break;
        }
    }

    if(valueToAdd > 0) {
        // Carry is still 1
        arr.insert(arr.begin(), valueToAdd);
    }

    return arr;
}

int main() {
    int t;
    cin >> t;
    for(int z=0; z<t; z++) {
        int n; 
        cin >> n;
        cout << n << endl;
        vector<int> arr;
        cout << "Given input array is: " << endl;
        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            arr.push_back(temp);
            cout << temp << " ";
        }
        cout << endl;

        vector<int>  result = solve(arr);
        cout << "Result: " << endl;
        printVector(result);
        cout << endl;
    }
    return 0;
}

/*

Need to take care of leading 0s case
when input contains only of 9s.

*/