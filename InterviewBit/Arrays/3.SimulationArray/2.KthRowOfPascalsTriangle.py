'''
/*
Problem Description

Given an index k, return the kth row of the Pascal's triangle.
Pascal's triangle: To generate A[C] in row R, sum up A'[C] and A'[C-1] from previous row R - 1.

Example:

Input : k = 3


Return : [1,3,3,1]

Note: k is 0 based. k = 0, corresponds to the row [1]. 

Note: Could you optimize your algorithm to use only O(k) extra space?
*/
'''
'''
Solution Approach:
What is Pascals triangle? -> https://en.wikipedia.org/wiki/Pascal%27s_triangle
What are binomial coefficients -> https://en.wikipedia.org/wiki/Binomial_coefficient
Remember, binomial coefficients are the coeffients of (1+x)^N, and they are given by N!/k! * (N-k)!, where k is the kth coefficient.
Pascals triange is the triagle formed for k=0,1,2...., where k is the value of each row.
The triangle looks like this:
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
.....
We just need to calculate each row.
'''

class Solution:
    def __init__(self, A):
        self.A = A

    def factorial(self, a: int):
        factorialList = []
        factorialList.append(1)
        for i in range(1, a+1):
            temp = i * factorialList[i-1]
            factorialList.append(temp)
        return factorialList

    def getRow(self, A):
        result = []
        factorials = self.factorial(A)
        for i in range(0, A+1):
            coefficient = (factorials[A]/(factorials[i]*factorials[A-i]))
            result.append(int(coefficient))
        return result

solution = Solution(5)
for i in range(0, 8):
    result = solution.getRow(i)
    print(result)
