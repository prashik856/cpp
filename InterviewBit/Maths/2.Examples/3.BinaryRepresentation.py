'''
Given a number N >= 0, find its representation in binary.

Example:

if N = 6,

binary form = 110

Problem Approach:

Complete code in the hint.
'''
'''
Solution Approach:
Standard Binary conversion method:
number is temp.
divide temp by 2
quotient beocomes new temp.
remainder becomes first binary digit.
continue till temp > 0
'''
class Solution:
	# @param A : integer
	# @return a strings
    def __init__(self, A):
        self.A = A

    def findDigitsInBinary(self, A):
        if(A == 0):
            return "0"
        result = ""
        quotient = 0
        remainder = 0
        temp = A 
        while(temp > 0):
            quotient = int(temp/2)
            remainder = int(temp % 2)
            temp = quotient
            result = str(remainder) + result
        return result

a = 21321321
solution = Solution(a)
result = solution.findDigitsInBinary(a)
print(result)