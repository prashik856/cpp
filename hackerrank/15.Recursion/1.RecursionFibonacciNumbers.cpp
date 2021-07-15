// Problem: https://www.hackerrank.com/challenges/ctci-fibonacci-numbers/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=recursion-backtracking
// Intuition: Dynamic programming
// Store previous results

#include <bits/stdc++.h>

using namespace std;

int fibonacci(int n) {
    // Complete the function.
    vector<int> fibonacci(n+1,0);
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    if(n == 1){
        return fibonacci[1];
    }
    for(int i=2; i<=n; i++){
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }
    return fibonacci[n];
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}