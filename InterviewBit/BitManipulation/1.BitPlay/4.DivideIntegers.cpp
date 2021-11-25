/*
Divide two integers without using multiplication, division and mod operator.

Return the floor of the result of the division.

Example:

5 / 2 = 2
Also, consider if there can be overflow cases. For overflow case, return INT_MAX.

Note: INT_MAX = 2^31 - 1
*/
/*
Solution approach:
https://www.geeksforgeeks.org/divide-two-integers-without-using-multiplication-division-mod-operator/

Method 1:
Approach : Keep subtracting the dividend from the divisor until dividend becomes less than divisor. 
The dividend becomes the remainder, and the number of times subtraction is done becomes the quotient. 
O(divident) time complexity.

Method 2:
Efficient Approach: Use bit manipulation in order to find the quotient. 
The divisor and dividend can be written as 
dividend = quotient * divisor + remainder
As every number can be represented in base 2(0 or 1), represent the quotient in binary form by using shift operator as given below : 

1. Determine the most significant bit in the quotient. 
This can easily be calculated by iterating on the bit position i from 31 to 1.
2. Find the first bit for which divisor << i, 
is less than dividend and keep updating the ith bit position for which it is true.
3. Add the result in temp variable for checking the next position such that (temp + (divisor << i) ) is less than dividend.
4. Return the final answer of quotient after updating with corresponding sign.


Code wise:
We need to use long long to avoid any integer overflow!
1. First get the sign of the quotient.
2. Then for i =32 to i=0, we try to find a values where:
if temp + (divisor << i) <= divisor:
    then 
        temp += (divisor << i)
        // set the i'th bit in quotient
        quotient |= (1LL << i)
3. We then return the quotient with is sign.

Got it. 
Also, take care of the case when divisor is 1.

Take care of overflow.
*/
#include<bits/stdc++.h>
using namespace std;

int solve(int a, int b){
    int result = 0;
    if(a == 0){
        return 0;
    }

    int sign = 1;
    if(( a < 0 && b >= 0) || (a >= 0 && b < 0)){
        // cout << "Negavite sign" << endl;
        sign = -1;
    }

    long long quotient=0, temp = 0;
    long long dividend = abs((long long)a), divisor= abs((long long)b);
    long long one = 1;
    // cout << "Dividend is: " << dividend << endl;
    // cout << "Divisor is: " << divisor << endl;

    if(divisor == 1){
        quotient = dividend;
    } else {
        for(int i=31; i>=0; i--){
            if(temp + (divisor << i) <= dividend){
                // update temp
                temp += (divisor << i);
                quotient |= (one << i);
            }
        }
    }

    if(sign < 0){
        // cout << "Negative quotient" << endl;
        quotient = -quotient;
        if(quotient < INT_MIN){
            return INT_MIN;
        }
        return quotient;
    }

    if(quotient > INT_MAX){
        // cout << "Positive quotitne" << endl;
        return INT_MAX;
    }

    return quotient;
}

int main(){
    int a = -2147483648;
    int b = -1;
    int result = solve(a, b);
    cout << "Result is: " << result << endl;
    return 0;
}