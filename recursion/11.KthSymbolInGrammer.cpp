/**
 * Kth Symbol in Grammer
 * 
 * Problem Statement:
 * 
 * Inputs:
 * Two Inputs integer
 * int: N, K
 * 
 * We need to generate Grammer using N and K.
 * 
 * Grammer:
 * Recursively defined.
 * 
 * if n == 1 and k == 1, we return 0.
 * 
 * From the given rule, 
 * When we have  
 * N-1 == 0, we have N = 01.
 * N-1 == 1, we have N = 10. 
 * 
 * So, by this definition, 
 * when N == 2, Since when N==1 is 0.
 * When N = 2, output is 01.
 * 
 * Something like this
 * N=1, K = 1, Output 0
 * N=2, Output 0    1, where k=1, output = 0, k=2, output = 1
 * N=3, Output 0    1   1   0, where k = 1,2,3,4 respectively
 * N=4, Output 0    1   1   0   1   0   0   1, where k=1,2,3,4,5,6,7,8 respectively
 * 
 * From the above outputs, we can observe one thing.
 * 1. the length of every next line is double the size of the previous line.
 * 2. The output of the first half of N is always equal to N-1.
 * 3. The latter half of any N is the compliment of the first half. And this is true for every row.
 * 
 * So, from this,
 * when K <= Mid.
 * solve(N, K) == solve(N-1,K)
 * 
 * When, K>Mid
 * Solve(N,K) = Not of solve(N-1,K-Mid)
 * 
 * So, this is our induction step.
 * 
 * Now, For any Given (N,K), we need to return the Ouput of this value.
 * The Output can either be 0 or 1, only.
 * 
 */
#include<bits/stdc++.h>
using namespace std;

int getOutput(int n, int k) {
    // cout << "N: " << n << " | K: " << k << endl;
    int output = -1;

    // base condition
    if(n==1 && k==1) {
        return 0;
    }

    int midValue = int(ceil(pow(2, n-2)));
    // cout << "Mid Value: " << midValue << endl;

    if(k <= midValue) {
        output = getOutput(n-1, k);
    } else if(k > midValue) {
        output = 1 - getOutput(n-1, k-midValue);
    }

    return output;
}

int main() {
    int n=4;
    int k=3;

    cout << "Inputs are, N: " << n << " | K: " << k << endl;

    int output = getOutput(n,k);
    cout << "Output: " << output << endl;

    return 0;
}