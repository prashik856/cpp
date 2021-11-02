'''
Given a number N, find all prime numbers upto N ( N included ).

Example:

if N = 7,

all primes till 7 = {2, 3, 5, 7}

Make sure the returned array is sorted.

Problem Approach:

Complete code in the hint.
'''
'''
Let's do this using the same logic:
And it worked!
'''
import math
import random
import time
class Solution:
    def __init__(self, A):
        self.A = A

    def isPrime(self, value):
        if(value <= 1):
            return False
        upperLimit = int(math.sqrt(value))
        for i in range(2, upperLimit+1):
            if(value % i == 0):
                return False
        return True

    def sieve(self, A):
        result = []
        for i in range(A + 1):
            isprime = self.isPrime(i)
            if isprime:
                result.append(i)
        return result

maxLimit = 100000
while True:
    a = random.randint(0, maxLimit)
    solution = Solution(a)
    result = solution.sieve(a)
    print(result)
    time.sleep(2)