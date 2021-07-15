# Problem: https://www.hackerrank.com/challenges/ctci-recursive-staircase/problem
# Intuition: Use of permutations to get all the permutations of same size
# Use of DP to get factorials
# Use of DP to get the answer


#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'stepPerms' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER n as parameter.
#

def getFactorial(n):
    factorials = []
    factorials.append(1)
    if n == 0:
        return factorials[0]
    for i in range(1,n+1):
        value = i * factorials[i - 1]
        factorials.append(value)
    return factorials[n]

def stepPerms(n):
    # Write your code here
    moduloNumber = 10000000007
    result = 0
    for x in range(0, n + 1):
        for y in range(0, n + 1):
            for z in range(0, n + 1):
                sum = x + 2 * y + 3 * z
                if sum > n:
                    break
                if sum == n:
                    value = getFactorial(x + y + z)
                    xFact = getFactorial(x)
                    yFact = getFactorial(y)
                    zFact = getFactorial(z)
                    ways = int(value/(xFact*yFact*zFact))
                    result = result + ways
    # print("Total Number of ways: " + str(result))
    result = result % moduloNumber
    return result

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = int(input().strip())

    for s_itr in range(s):
        n = int(input().strip())

        res = stepPerms(n)

        fptr.write(str(res) + '\n')

    fptr.close()
