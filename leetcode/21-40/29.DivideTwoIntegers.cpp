/*
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 2^31 - 1, then return 2^31 - 1, and if the quotient is strictly less than -2^31, then return -231.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.

Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.

Constraints:

    -231 <= dividend, divisor <= 231 - 1
    divisor != 0

*/
#include<bits/stdc++.h>
using namespace std;

int divideWithDivision(int dividend, int divisor) {
    cout << "Int Max: " << INT_MAX << endl;
    cout << "Int Min: " << INT_MIN << endl;
    // edge cases
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    if (divisor == 1) {
        return dividend;
    }

    if (divisor == -1) {
        return -dividend;
    }

    // This got accepted. But I used division.


    return dividend/divisor;
}

int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    if (divisor == 1) {
        return dividend;
    }

    if (divisor == -1) {
        return -dividend;
    }

    int dividendNeg = dividend;
    if (dividend > 0) {
        dividendNeg = -dividend;
    }

    int divisorNeg = divisor;
    if (divisor > 0) {
        divisorNeg = -divisor;
    }

    cout << "Negative values. Dividend: " << dividendNeg << " . Divisor: " << divisorNeg << endl;

    int quotient = 0;

    long currentVal = divisorNeg;
    long currentQuotient = 1;
    while (currentVal >= dividendNeg) {

        // cout << "Current Value: " << currentVal << endl;
        if (currentVal << 1 == dividendNeg) {
            currentQuotient = currentQuotient << 1;
            quotient = quotient + currentQuotient;
            break;
        }

        if (currentVal << 1 < INT_MIN || currentVal << 1 < dividendNeg) {
            dividendNeg = dividendNeg - currentVal;
            quotient = quotient + currentQuotient;
            // cout << "New Dividend Neg: " << dividendNeg << endl;

            currentQuotient = 1;
            currentVal = divisorNeg;
        } else {
            currentVal = currentVal << 1;
            currentQuotient = currentQuotient << 1;
        }
    }

    if (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0) {
        quotient = -quotient;
    }

    return quotient;
}

int main() {
    vector<int> inputs = {10, 7, -2147483648, 1344556, 2, -2147483648, 2147483647};
    vector<int> divisors = {3, -3, -1, 1232, 2, 2, 3};
    vector<int> outputs = {3, -2, 2147483647, 1091, 1, -1073741824, 0};

    for (int i=0; i<inputs.size(); i++) {
        cout << "Dividend: " << inputs[i] << endl;
        cout << "Divisor: " << divisors[i] << endl;

        int output = divide(inputs[i], divisors[i]);
        cout << "Output: " << output << endl;

        cout << "Expected Output: " << outputs[i] << endl;
        cout << endl;
    }


    return 0;
}

/**
The optimization uses bit shifting (doubling) to speed up the process:

    Convert both numbers to negative to avoid overflow issues (since -2^31 cannot be represented as a positive 32-bit integer)
    For each iteration, find the largest multiple of the divisor (using left shifts to double it) that can be subtracted from the current dividend
    Subtract this multiple and add the corresponding count to the answer
    Repeat until the remaining dividend is smaller than the divisor
    Apply the correct sign to the final result

 */