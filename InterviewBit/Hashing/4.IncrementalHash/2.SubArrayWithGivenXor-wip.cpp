/*
Problem Description

Given an array of integers A and an integer B.

Find the total number of subarrays having bitwise XOR of all elements equals to B.



Problem Constraints
1 <= length of the array <= 105

1 <= A[i], B <= 109



Input Format
The first argument given is the integer array A.

The second argument given is integer B.



Output Format
Return the total number of subarrays having bitwise XOR equals to B.



Example Input
Input 1:

 A = [4, 2, 2, 6, 4]
 B = 6
Input 2:

 A = [5, 6, 7, 8, 9]
 B = 5


Example Output
Output 1:

 4
Output 2:

 2


Example Explanation
Explanation 1:

 The subarrays having XOR of their elements as 6 are:
 [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]
Explanation 2:

 The subarrays having XOR of their elements as 2 are [5] and [5, 6, 7, 8, 9]

*/

/*
Solution Approach:

Method 1:
A Simple Solution is to use two loops to go through all possible subarrays of arr[] and 
count the number of subarrays having XOR of their elements as m. 

Efficient Approach:
An Efficient Solution solves the above problem in O(n) time. 
Let us call the XOR of all elements in the range [i+1, j] as A, 
in the range [0, i] as B, 
and in the range [0, j] as C. 
If we do XOR of B with C, the overlapping elements in [0, i] from B and C zero out, 
and we get XOR of all elements in the range [i+1, j], 
i.e. A. 
Since A = B XOR C, we have B = A XOR C. 
Now, if we know the value of C and we take the value of A as m, 
we get the count of A as the count of all B satisfying this relation. 
Essentially, we get the count of all subarrays having XOR-sum m for each C. 
As we take the sum of this count overall C, we get our answer.

1) Initialize ans as 0.
2) Compute xorArr, the prefix xor-sum array.
3) Create a map mp in which we store count of 
   all prefixes with XOR as a particular value. 
4) Traverse xorArr and for each element in xorArr
   (A) If m^xorArr[i] XOR exists in map, then 
       there is another previous prefix with 
       same XOR, i.e., there is a subarray ending
       at i with XOR equal to m. We add count of
       all such subarrays to result. 
   (B) If xorArr[i] is equal to m, increment ans by 1.
   (C) Increment count of elements having XOR-sum 
       xorArr[i] in map by 1.
5) Return ans.
*/
