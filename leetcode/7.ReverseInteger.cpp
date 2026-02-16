/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:

Input: x = 123
Output: 321

Example 2:

Input: x = -123
Output: -321

Example 3:

Input: x = 120
Output: 21

Constraints:

    -231 <= x <= 231 - 1

 */
#include <climits>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int reverse(int x) {
    // cout << "X : " << x << endl;
    // my base condition
    if (x == 0 || x == INT_MIN || x == INT_MAX) {
        return 0;
    }

    // cout << "INT MIN: " << INT_MIN << endl;
    // cout << "INT MAX: " << INT_MAX << endl;
    int result = 0;

    unsigned int reversex = 0;
    unsigned int originalx = abs(x);
    cout << "Original x positive: " << originalx << endl;

    int leadingZeroes = 0;
    while (true) {
        if (originalx % 10 == 0) {
            leadingZeroes++;
            originalx = originalx / 10;
        } else {
            break;
        }
    }
    cout << "Leading zeroes: " << leadingZeroes << endl;

    originalx = abs(x);

    unsigned int val = 10;
    while (originalx > 0) {
        unsigned int modulo = originalx % 10; // 3, 2, 1
        originalx = originalx / 10; // 12, 1, 0

        if (reversex * val + modulo <= INT_MAX) {
            reversex = reversex * val + modulo; // 0 * 10 + 3 = 3, 3 * 10 + 2 = 32, 32*10 + 1 = 321
        } else {
            return 0;
        }
    }

    cout << "Reverse x positive: " << reversex << endl;
    unsigned int originalrev = reversex; // still positive
    unsigned tempx = 0;
    while (originalrev > 0) {
        unsigned modulo = originalrev % 10;
        originalrev = originalrev / 10;

        tempx = tempx * val + modulo;
    }

    if (leadingZeroes > 0) {
        cout << "We have leading zeroes in oroginal x. Appending it." << endl;
        while (leadingZeroes > 0) {
            tempx = tempx * 10;
            leadingZeroes--;
        }
    }

    cout << "Temp x positive: " << tempx << endl;

    // Recheck here
    int temp2;
    if (x < 0) {
        temp2 = static_cast<int>(-tempx);
    } else {
        temp2 = static_cast<int>(tempx);
    }

    // cout << "Temp x after signing: " << tempx << endl;
    // cout << "Value of x: " << x << endl;

    if (x != temp2) {
        return 0;
    }


    if (x < 0) {
        if (0 - int(reversex) >= INT_MIN) {
            result = 0 - reversex;
        }
    } else {
        if (reversex <= INT_MAX) {
            result = reversex;
        }
    }
    // cout << "Reverse x after signing: " << reversex << endl;

    return result;
}

int main() {

    int x = 1534236469;

    cout << "Given value is: " << x << endl;

    int result = reverse(x);

    cout << "Result is: " << result << endl;

    return 0;
}

// Accepted somehow xD