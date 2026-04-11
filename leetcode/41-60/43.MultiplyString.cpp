/**
43. Multiply Strings

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"


Constraints:

    1 <= num1.length, num2.length <= 200
    num1 and num2 consist of digits only.
    Both num1 and num2 do not contain any leading zero, except the number 0 itself.

 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<char> &arr) {
    for(int i=0; i<arr.size(); i++) {
        cout << arr[i];
    }
    cout << endl;
}

void print2DVector(vector<vector<char>> &arr) {
    for(int i=0; i<arr.size(); i++) {
        printVector(arr[i]);
    }
    cout << endl;
}

string multiply(string num1, string num2) {
    string result = "";
    if(num1.size() == 1 && num1[0]=='0') {
        return "0";
    }
    if(num2.size() == 1 && num2[0] == '0') {
        return "0";
    }

    // cout << "Int value of 0 : " << int('0') << endl;

    vector<vector<char>> finalSums;
    vector<char> sum;
    int count = 0;
    int maxSize = 0;
    for(int j=num2.size() - 1; j>=0; j--) {
        int mul = int(num2[j]) - int('0');
        // cout << "Multiplier: " << mul << endl;

        int carry = 0;
        sum.clear();

        for(int i=0; i<count; i++) {
            sum.push_back('0');
        }

        for(int i=num1.size()-1; i>=0; i-- ) {
            int currentVal = num1[i] - '0';
            // cout << "Current Value to multiply to: " << currentVal << endl;
            
            int tempMul = currentVal * mul + carry;

            carry = tempMul / 10;

            int val = tempMul % 10;
            char charVal = char(int('0') + int(val));

            // cout << "Char value to push to sum: " << charVal << endl;
            sum.push_back(charVal);
        }

        while(carry > 0) {
            // cout << "Carry is greater than 0: " << carry << endl;
            int val = carry % 10;
            char charVal = char(int('0') + int(val));
            // cout << "Char value to push to sum: " << charVal << endl;
            sum.push_back(charVal);
            carry = carry / 10;
        }

        if(sum.size() > maxSize) {
            maxSize = sum.size();
        }

        // cout << "Current Sum value: " << endl;
        // printVector(sum);

        count++;
        finalSums.push_back(sum);
        // cout << endl;
    }

    // Add leading zeroes for now
    for(int i=0; i<finalSums.size(); i++) {
        if(finalSums[i].size() == maxSize) {
            continue;
        }
        int currentSize = finalSums[i].size();
        while(currentSize <maxSize) {
            finalSums[i].push_back('0');
            currentSize = finalSums[i].size();
        }
    }

    // cout << "Final Sums vector: " << endl;
    // print2DVector(finalSums);

    // Calculate final result
    int carry = 0;
    for(int j=0; j<maxSize; j++) {
        int sum = carry;
        for(int i=0; i<finalSums.size(); i++) {
            int val = int(finalSums[i][j]) - int('0');
            sum = sum + val;
        }

        carry = sum / 10;
        int currentVal = sum % 10;
        char currentCharVal = char(int('0') + currentVal);
        // cout << "Current Char Value: " << currentCharVal << endl;
        result.push_back(currentCharVal);
    }

    if(carry > 0) {
        // cout << "Carry is greater than 0 : " << carry << endl;
        while(carry > 0) {
            int currentVal = carry % 10;
            carry = carry / 10;
            char currentCharVal = char(int('0') + currentVal);
            // cout << "Current Char Value: " << currentCharVal << endl;
            result.push_back(currentCharVal);
        }
    }

    string output = "";
    for(int i=result.size() -1; i>=0; i--) {
        output.push_back(result[i]);
    }

    return output;
}

int main() {
    vector<string> input1s = {"2", "123", "99", "1000000000000000000000"};
    vector<string> input2s = {"3", "456", "99", "1000000000000000000000"};
    vector<string> outputs = {"6", "56088", "9801", "1000000000000000000000000000000000000000000"};

    for(int i=0; i<input1s.size(); i++) {
        cout << "Input 1: " << input1s[i] << endl;
        cout << "Input 2: " << input2s[i] << endl;

        string output = multiply(input1s[i], input2s[i]);
        cout << "Output: " << output << endl;

        cout << "Expected Output: " << outputs[i] << endl << endl;     
    }

    return 0;
}

// Implement classic multiplication