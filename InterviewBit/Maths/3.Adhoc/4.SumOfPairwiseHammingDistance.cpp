/*
'''
Problem Description

Hamming distance between two non-negative integers is defined as the number of positions at which the corresponding bits are different.

Given an array A of N non-negative integers, find the sum of hamming distances of all pairs of integers in the array.
Return the answer modulo 1000000007.



Problem Constraints
1 <= |A| <= 200000

1 <= A[i] <= 109



Input Format
First and only argument is array A.



Output Format
Return one integer, the answer to the problem.



Example Input
Input 1:

 A = [1]
Input 2:

 A = [2, 4, 6]


Example Output
Output 1:

 0
Output 2:

 8


Example Explanation
Explanation 1:

 No pairs are formed.
Explanation 2:

 We return, f(2, 2) + f(2, 4) + f(2, 6) + f(4, 2) + f(4, 4) + f(4, 6) + f(6, 2) + f(6, 4) + f(6, 6) = 8
'''
'''
Naive Solution – 
A Simple Solution is to run two loops to consider all pairs one by one. 
For every pair, count bit differences. 
Finally return sum of counts. 
Time complexity of this solution is O(n2). 
We are using bitset::count() which is an inbuilt STL in C++ which returns the number of set bits in the binary representation of a number. 


Efficient Solution – 

An Efficient Solution can solve this problem in O(n) time using the fact that all numbers are represented using 32 bits 
(or some fixed number of bits). 
The idea is to count differences at individual bit positions. 
We traverse from 0 to 31 and count numbers with i’th bit set. 
Let this count be ‘count’. 
There would be “n-count” numbers with i’th bit not set. 

So count of differences at i’th bit would be “count * (n-count) * 2”, 
the reason for this formula is as every pair having one element which has set bit at i’th position 
and second element having unset bit at i’th position contributes exactly 1 to sum, 
therefore total permutation count will be count*(n-count)! (It is very important to understand this!) 
and multiply by 2 is due to one more repetition of all this type of pair as per given condition for making pair 1<=i, j<=N 
[(1,2) != (2,1), so we have to count both the pairs!].

Example:
1 2 3 4
now, bits array will be
2 2 0 0 .... 0
for 0'th bit set, we have 1 and 3, and non set will be 2 and 4.
So, for 1, the number of pairs will be:
(1,2) (1,4) = (n-count) pairs
for 3 our pairs will be
(3,2) (3,4) = (n-count) pairs
Now, this will continue till count times.
So, number of pairs generated will be => count * (n-count) pairs!
But, (1,2) != (2,1). Both of them are treated as different in this question.
So, our total number of pairs will be => 2 * count * (n-count) pairs! 
This will be for every value of bit vector.
We just need to get the sum of these values, and modulo it.

'''
*/
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr) {
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int solve(vector<int> arr){
    if(arr.size() == 1){
        return 0;
    }
    int result = 0;
    unsigned long long currentSum = 0;
    int n = arr.size();

    vector<int> bits(32, 0);
    for(int i=0; i<n; i++) {
        int value = arr[i];
        int index = 0;
        while(value > 0){
            if(value % 2 != 0){
                bits[index]++;
            }
            value = value/2;
            index++;
        }
    }

    // cout << "Given bits array is: " << endl;
    // printVector(bits);

    for(int i=0; i<bits.size(); i++){
        long value = bits[i];
        long currentPairs = value * (n-value) * 2;
        currentSum += currentPairs;
    }

    currentSum = currentSum % 1000000007;
    result = currentSum;

    return result;
}

int main() {
    int t;
    cin >> t;
    for(int z=0; z<t; z++) {
        int n; 
        cin >> n;
        cout << "Given size of array is: " << n << endl;
        vector<int> arr(n, 0);
        for(int i=0; i<n; i++){
                int temp;
                cin >> temp;
                arr[i] = temp;
                cout << temp << " ";
        }
        cout << endl;
        
        int result = solve(arr);
        cout << "Result: " <<  result << endl;

        cout << endl;
    }
    return 0;
}