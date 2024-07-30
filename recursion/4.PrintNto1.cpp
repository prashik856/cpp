/**
 * Print N to 1 using recursion
 * 
 */

#include<bits/stdc++.h>
using namespace std;

void print(int n) {
    // base condition
    if(n == 0) {
        return;
    }

    // Using just one change, we are changing the way our recursive function works.

    // Hypothesis
    cout << n << " ";

    // Induction
    print(n-1);

}

int main() {
    int n = 10;
    cout << "Input: " << n << endl;

    cout << "Output: " << endl;
    print(n);
    cout << endl;

    return 0;
}