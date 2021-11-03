'''
Problem Description

Determine whether an integer is a palindrome. Do this without extra space.

A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed. 
Negative numbers are not palindromic.

Example :

Input : 12121
Output : True


Input : 123
Output : False
'''
'''
Easy enough:
Get the reverse and compare the results.

Corner cases: When input is 0
corner cases: When input ends with 0 and not equal to 0
corner case: When input is negative.
'''

def getReverse(self, a):
    result = 0
    temp = a
    while(temp > 0):
        value = temp % 10
        result = result * 10 + value
        temp = int(temp/10)
    return result
    
def isPalindrome(self, a):
    if(a == 0):
        return 1
    if(a % 10 == 0):
        return 0
    if(a < 0):
        return 0
    result = 1
    reverseOfA = self.getReverse(a)
    # print("Reverse of A: " + str(reverseOfA))    

    temp1 = reverseOfA
    temp2 = a
    while(temp1 > 0 and temp2 > 0):
        value1 = int(temp1 % 10)
        value2 = int(temp2 % 10)
        if(value1 != value2):
            result = 0
            break
        temp1 = int(temp1/10)
        temp2 = int(temp2/10)
    return result

a = 1
result = solve(a)
print("Result: " + str(result))