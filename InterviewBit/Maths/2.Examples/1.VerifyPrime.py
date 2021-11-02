'''
Problem:
Given a number N, verify if N is prime or not.

Return 1 if N is prime, else return 0.

Example :

Input : 7
Output : True
Problem Approach:

Complete code in the hint.

'''

'''
Soution approach:
Let's first try our classic method:
Upper limit is sqrt(n)
This works!
'''
import math
import random

class Solution:
    def __init__(self, A):
        self.A = A

    def isPrime(self, A):
        upperLimit = int(math.sqrt(A))
        if(A <= 1):
            return False
        for i in range(2, upperLimit + 1):
            if( A % i == 0):
                return False
        return True

maxLimit = 1000000000
while True:
    A = random.randint(0, maxLimit)
    solution = Solution(A)
    result = solution.isPrime(A)
    if result:
        print(A)
