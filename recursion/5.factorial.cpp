/**
 * Given number n, return the factorial of the number.
 * 
 * Factorial of the number n is defined as:
 * fact(n) = n * (n-1) * (n-1) * ... * 1.
 */

#include<bits/stdc++.h>
using namespace std;

long long fact(int n) {
    // base condition
    if(n==0) {
        return 1;
    }

    long long n1 = n;

    return n1 * fact(n-1);
}

int main() {

    int n = 20;
    cout << "Input: " << n << endl;

    long long output = fact(n);
    cout << "Output: " << output << endl;

    return 0;
}