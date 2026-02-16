/*
Given an integer x, return true if x is a palindrome., and false otherwise.

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Constraints:

    -2^31 <= x <= 2^31 - 1

 */

#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }

    vector<int> arr = {};
    int originalx = x;
    while (originalx > 0) {
        int val = originalx % 10;
        originalx = originalx / 10;
        arr.push_back(val);
    }

    // cout << "Constructed vector: " << endl;
    // printVector(arr);

    int i=0;
    int j=arr.size() - 1;
    while (i <= j) {
        if (arr[i] != arr[j]) {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

int main() {
    vector<int> inputs = {121, -121, 10};
    vector<bool> outputs = {true, false, false};

    for (int i=0; i<inputs.size(); i++) {
        cout << "Input: " << inputs[i] << endl;
        bool actualOutput = isPalindrome(inputs[i]);
        cout << "Actual Output: " << actualOutput << endl;
        cout << "Expected Output: " << outputs[i] << endl;
        cout << endl;
    }

    return 0;
}