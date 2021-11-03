'''
Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.

NOTE A solution will always exist. read Goldbach’s  conjecture

Example:


Input : 4
Output: 2 + 2 = 4

If there are more than one solutions possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b,
and [c,d] is another solution with c <= d, then

[a, b] < [c, d] 

If a < c OR a==c AND b < d. 
'''
'''
Naive solution from me worked.
the first upper limit will be equal to N/2.
For every N/2, we try to find a prime P s.t. P and N-P, both are primes!
'''
import math
class Solution:
    def __init__(self, A):
        self.A = A
	# @param A : integer
	# @return a list of integers
    def isPrime(self, value):
        upperLimit = int(math.sqrt(value))
        for i in range(2, upperLimit + 1):
            if (value % i == 0):
                return False
        return True

    def primesum(self, A):
        upperLimit = int(A/2)
        result = []
        for i in range(2, upperLimit + 2):
            currentValue = i
            primeValue = self.isPrime(currentValue)
            if primeValue:
                a = i
                b = A - i
                bPrimeValue = self.isPrime(b)
                if bPrimeValue:
                    result.append(a)
                    result.append(b)
                    break
        return result

a = 12
solution = Solution(a)
result = solution.primesum(a)
print(result)