/**
 * Print numbers from 1 to n using recursion.
 * 
 * Input : int n: 5
 * Output: Print numbers from 1 to n
 * 1,2,3,4,5,...,n
 */
#include<bits/stdc++.h>
using namespace std;

void print(int n) {
    if(n == 0) {
        return;
    }

    print(n-1);

    cout << n << " ";
}

int main() {
    int n = 10;
    cout << "Input: " << n << endl;

    cout << "Output: " << endl;
    print(n);
    cout << endl;

    return 0;
}