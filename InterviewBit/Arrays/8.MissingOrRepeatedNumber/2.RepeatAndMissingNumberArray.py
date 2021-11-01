'''
There are certain problems which are asked in the interview to also check how you take care of overflows in your problem.

This is one of those problems.

Please take extra care to make sure that you are type-casting your ints to long properly and at all places. Try to verify if your solution works if number of elements is as large as 105

Food for thought :

Even though it might not be required in this problem, in some cases, you might be required to order the operations cleverly so that the numbers do not overflow.
For example, if you need to calculate n! / k! where n! is factorial(n), one approach is to calculate factorial(n), factorial(k) and then divide them.
Another approach is to only multiple numbers from k + 1 ... n to calculate the result.
Obviously approach 1 is more susceptible to overflows.
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4
'''
'''
https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/?ref=lbp
Solution Approach:
Method 7 (Make two equations using sum and sum of squares)
Approach:

Let x be the missing and y be the repeating element.
Let N is the size of array.
Get the sum of all numbers using formula S = N(N+1)/2
Get the sum of square of all numbers using formula Sum_Sq = N(N+1)(2N+1)/6
Iterate through a loop from i=1….N
S -= A[i]
Sum_Sq -= (A[i]*A[i])
It will give two equations 
x-y = S – (1) 
x^2 – y^2 = Sum_sq 
x+ y = (Sum_sq/S) – (2) 

Rather than using multiplication, we use sum of squares!
'''
import random

class Solution:
    # @param A : tuple of integers
    # @return a list of integers
    def __init__(self, A):
        self.A = A

    def repeatedNumber(self, A):
        n = len(A)
        # print("Length of array is: " + str(n))

        # Save the sum
        s = n * (n+1)
        s = int(s/2)
        

        # sum of squares
        sumOfSquaresOfArray = 0
        sumOfArray = 0
        sumOfSquares = 0
        for i in range(len(A)):
            sumOfArray += A[i]
            sumOfSquaresOfArray += (A[i]*A[i])
            sumOfSquares += (i+1)*(i+1)

        # print("Sum of array: " + str(sumOfArray))
        # print("Sum of n integers: " + str(s))
        # print("Sum of squares of array: " + str(sumOfSquaresOfArray))
        # print("Sum of squares of n intergers: " + str(sumOfSquares))

        numerator = sumOfSquaresOfArray - sumOfSquares
        denominator = sumOfArray - s
        constant1 = int(numerator/denominator)
        # print("Value of constant 1 is: " + str(constant1))

        constant2 = sumOfArray - s
        # print("Value of constant 2 is: " + str(constant2))

        constant3 = constant1 + constant2
        # print("Value of constant 3 is: " + str(constant3))

        constant4 = constant1 - constant2
        # print("Value of constant 4 is: " + str(constant4))

        a = int(constant3/2)
        b = int(constant4/2)

        # print("The missing numbers are: ")
        # print(a)
        # print(b)

        result = []
        result.append(a)
        result.append(b)
        return result

while True:
    maxValue = random.randint(1, 100001)
    A: list = [i for i in range(1, maxValue + 1)]
    deletedValueIndex: int = random.randint(0, maxValue - 1)
    deletedValue: int = A[deletedValueIndex]    
    # print("Deleted Value is: " + str(deletedValue))

    replacedValueIndex: int = random.randint(0, maxValue - 1)
    replacedValue: int = A[replacedValueIndex]
    # print("Replaced Value is: " + str(replacedValue))

    A[deletedValueIndex] = A[replacedValueIndex]

    random.shuffle(A)

    solution: Solution = Solution(A)
    result = solution.repeatedNumber(A)
    if result[0] == replacedValue and result[1] == deletedValue:
        print("Correct")
    else:
        print("Incorrect")
        print(result)
        print("Replaced Value is: " + str(replacedValue))
        print("Deleted Value is: " + str(deletedValue))
        break