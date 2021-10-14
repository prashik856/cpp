'''
Problem Description

Given numRows, generate the first numRows of Pascal's triangle.
Pascal's triangle : To generate A[C] in row R, sum up A'[C] and A'[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]
'''

'''
Solution approach:
We already know what a pascals triangle is.
We already know how to get binomial coefficients.
'''

class Solution:

    def __init__(self, A):
        self.A = A

    def factorials(self, a):
        factorials = []
        factorials.append(1)
        for i in range(1, a+1):
            value = i * factorials[i-1]
            factorials.append(value)
        return factorials

    def solve(self, A):
        result = []
        factorials = self.factorials(A)
        # Now we have all the factorials
        for i in range(0, A):
            # We need a from 0
            temp = []
            for j in range(0, i+1):
                coefficient = (factorials[i]/(factorials[i-j]*factorials[j]))
                temp.append(int(coefficient))
            result.append(temp)
        # print(result)
        return result

A = 5
for i in range(1, A+1):
    solution = Solution(i)
    solution.solve(i)