'''
A robot is located at the top-left corner of an A x B grid (marked ‘Start’ in the diagram below).

Path Sum: Example 1

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked ‘Finish’ in the diagram below).

How many possible unique paths are there?

Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.

Example :

Input : A = 2, B = 2
Output : 2

2 possible routes : (0, 0) -> (0, 1) -> (1, 1) 
              OR  : (0, 0) -> (1, 0) -> (1, 1)

'''

'''
Solution Approach:
Remember unique path in a grid using recursion and grid.

We first find the proper recursive solution and then use DP.
'''
import random

class Solution:
    def __init__(self, a, b):
        self.a = a
        self.b = b
    
    def getResult(self, tempa, tempb, a, b, allWays):
        key=str(tempa) + "-" + str(tempb)
        
        if(tempa >= a or tempb >= b):
            return 0
        if(tempa == a-1 and tempb == b-1):
            return 1
        if(key in allWays):
            return allWays[key]

        result = self.getResult(tempa + 1, tempb, a, b, allWays) + self.getResult(tempa, tempb+1, a, b, allWays)
        allWays[key] = result
        return result

    def uniquePaths(self, a, b):
        currenta = 0
        currentb = 0
        allWays = {}
        if a == 1 or b == 1:
            return 1
        result = self.getResult(currenta, currentb, a, b, allWays)
        return result
    


Limit = 100
a = random.randint(1, Limit)
b = random.randint(1, Limit)
a = 1
b = 3000
print("A: " + str(a))
print("B: " + str(b))
solution = Solution(a ,b)
result = solution.uniquePaths(a, b)
print("Result: " + str(result))
