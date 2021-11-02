'''
Given a number N, find all factors of N.

Example:

N = 6 
factors = {1, 2, 3, 6}
Make sure the returned array is sorted.

Problem Approach:

Complete code in the hint.
'''

'''
Solution approach:
Upper limit will be number/2 + 1
Check till this number, if number is divisible.

Different Approach:

Method 1:
A Naive Solution would be to iterate all the numbers from 1 to n, 
checking if that number divides n and printing it. 


Method2:
If we look carefully, all the divisors are present in pairs. 
For example if n = 100, then the various pairs of divisors are: (1,100), (2,50), (4,25), (5,20), (10,10)
Using this fact we could speed up our program significantly. 
We, however, have to be careful if there are two equal divisors as in the case of (10, 10). 
In such case, we’d print only one of them. 

'''
import math
class Solution:
	# @param A : integer
	# @return a list of integers

    def __init__(self, A):
        self.A = A

    def allFactors(self, A):
        upperLimit = int(math.sqrt(A))
        if(A == 1):
            return [1]
        
        tempResult = set(())
        result = []
        for i in range(1, upperLimit + 1):
            if(A % i == 0):
                quotient = int(A / i)
                tempResult.add(i)
                tempResult.add(quotient)
        print(tempResult)
        while len(tempResult) > 0:
            result.append(tempResult.pop())
        return result

a = 1000
solution = Solution(a)
result = solution.allFactors(a)
print(result)
