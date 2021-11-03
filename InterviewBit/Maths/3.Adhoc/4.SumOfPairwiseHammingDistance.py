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

'''