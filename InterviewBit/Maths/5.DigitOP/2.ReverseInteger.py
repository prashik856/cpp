'''
Problem Description

You are given an integer N and the task is to reverse the digits of the given integer. 
Return 0 if the result overflows and does not fit in a 32 bit signed integer


Look at the example for clarification.



Problem Constraints
N belongs to the Integer limits.



Input Format
Input an Integer.



Output Format
Return a single integer denoting the reverse of the given integer.



Example Input
Input 1:

 x = 123


Input 2:

 x = -123


Example Output
Output 1:

 321


Ouput 2:

 -321


Example Explanation
 If the given integer is negative like -123 the output is also negative -321.
'''
'''
Need to do it in cpp
FUCK IT, LET'S DO IT HERE
-2147483648
2147483647

Stupid interview bit.
The same logic worked here in python.
'''

def getReverse(inputValue):
    result = 0
    while(inputValue > 0):
        remainder = int(inputValue % 10)
        result = result * 10 + remainder
        inputValue = int(inputValue/10)
    return result

def solve(a):
    result = 0
    temp = abs(a)

    MAXINT = 2147483647
    MININT = -2147483648

    reverseNumber = getReverse(temp)

    # print("Reverse of value is: " + str(reverseNumber))

    if a < 0:
        reverseNumber = -reverseNumber
        if(reverseNumber < MININT):
            result = 0
        else:
            result = reverseNumber
    else:
        if(reverseNumber > MAXINT):
            result = 0
        else:
            result = reverseNumber
    return result


a = 1234567891
result = solve(a)
print("Result is: " + str(result))