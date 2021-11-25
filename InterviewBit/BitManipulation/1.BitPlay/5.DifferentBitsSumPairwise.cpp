/*
We define f(X, Y) as number of different corresponding bits in binary representation of X and Y. For example, f(2, 7) = 2, since binary representation of 2 and 7 are 010 and 111, respectively. The first and the third bit differ, so f(2, 7) = 2.

You are given an array of N positive integers, A1, A2 ,…, AN. Find sum of f(Ai, Aj) for all pairs (i, j) such that 1 ≤ i, j ≤ N. Return the answer modulo 109+7.

For example,

A=[1, 3, 5]

We return

f(1, 1) + f(1, 3) + f(1, 5) + 
f(3, 1) + f(3, 3) + f(3, 5) +
f(5, 1) + f(5, 3) + f(5, 5) =

0 + 1 + 1 +
1 + 0 + 2 +
1 + 2 + 0 = 8
*/
/*
Solution Approach:
https://www.geeksforgeeks.org/sum-of-bit-differences-among-all-pairs/
An Efficient Solution can solve this problem in O(n) time using the fact that all numbers are represented using 32 bits 
(or some fixed number of bits). 
The idea is to count differences at individual bit positions. 
We traverse from 0 to 31 and count numbers with i’th bit set. 
Let this count be ‘count’. 
There would be “n-count” numbers with i’th bit not set. 
So count of differences at i’th bit would be “count * (n-count) * 2”, 
the reason for this formula is as every pair having one element which has set bit at i’th position 
and second element having unset bit at i’th position contributes exactly 1 to sum, 
therefore total permutation count will be count*(n-count) 
and multiply by 2 is due to one more repetition of all this type of pair as per given condition for making pair 1<=i, j<=N.


Man, I should have remembered this!
*/
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int solve(vector<int> a){
    int result = 0;
    int n = a.size();
    int MOD = 1000000007;

    vector<int> bits(32, 0);
    for(int i=0; i<n; i++){
        int value = a[i];
        int index = 0;
        while(value > 0){
            if(value % 2 == 1){
                bits[index]++;
            }
            index++;
            value = (value/2);
        }
    }
    // printVector(bits);

    long tempResult = 0;
    for(int i=0; i<32; i++){
        long val =(long) bits[i];
        long permutations = val * ((long)n - val);
        permutations = 2 * permutations; // (1, 2) is same as (2,1) but it is counted
        tempResult = tempResult + permutations;
        tempResult = (tempResult % MOD);
        result = tempResult;
    }

    return result;
}

int main(){
    vector<int> a = {1, 3, 5};
    int result = solve(a);
    cout << "Result is: " << result << endl;
    return 0;
}