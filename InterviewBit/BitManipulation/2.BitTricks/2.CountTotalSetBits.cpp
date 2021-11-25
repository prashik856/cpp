/*
Problem Description

Given a positive integer A, the task is to count the total number of set bits in the binary representation of all the numbers from 1 to A.

Return the count modulo 109 + 7.



Problem Constraints
1 <= A <= 109



Input Format
First and only argument is an integer A.



Output Format
Return an integer denoting the ( Total number of set bits in the binary representation of all the numbers from 1 to A )modulo 109 + 7.



Example Input
Input 1:

 A = 3
Input 2:

 A = 1


Example Output
Output 1:

 4
Output 2:

 1


Example Explanation
Explanation 1:

 DECIMAL    BINARY  SET BIT COUNT
    1          01        1
    2          10        1
    3          11        2
 1 + 1 + 2 = 4 
 Answer = 4 % 1000000007 = 4
Explanation 2:

 A = 1
  DECIMAL    BINARY  SET BIT COUNT
    1          01        1
 Answer = 1 % 1000000007 = 1
*/
/*
Naive solution:
Method 1 (Simple) 
A simple solution is to run a loop from 1 to n and sum the count of set bits in all numbers from 1 to n.  

Method 2:
If we observe bits from rightmost side at distance i than bits get inverted after 2^i position in vertical sequence. 
for example n = 5; 
0 = 0000 
1 = 0001 
2 = 0010 
3 = 0011 
4 = 0100 
5 = 0101
Observe the right most bit (i = 0) the bits get flipped after (2^0 = 1) 
Observe the 3rd rightmost bit (i = 2) the bits get flipped after (2^2 = 4) 
So, We can count bits in vertical fashion such that at i’th right most position bits will be get flipped after 2^i iteration;
O(k*n) 
*/

#include<bits/stdc++.h>
using namespace std;

int solve(int a){
    int result = 0;


    int 
}

int main(){
    int a = 3;
    int result = solve(a);
    cout << "Result is: " << result << endl;
    return 0;
}