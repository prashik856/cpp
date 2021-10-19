'''
Problem Description

Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.
Sample Input:

[3 4 1 4 1]

Sample Output:

1

If there are multiple possible answers ( like in the sample case above ), output any one.

If there is no duplicate, output -1
'''
'''
Solution Approach:
Making use of dictionary
'''

class Solution:
    def __init__(self, A):
        self.A = A
    # @param A : tuple of integers
    # @return an integer
    def repeatedNumber(self, A):
        arrayDict = {}
        for i in range(len(A)):
            value = A[i]
            if value in arrayDict:
                return value
            else:
                arrayDict[value] = 1
        return -1

solution = Solution(10)
A = [3, 4, 1, 4, 1]
print(solution.repeatedNumber(A))
A = [3, 4, 1]
print(solution.repeatedNumber(A))