
'''
Problem Description

Given a column title A as appears in an Excel sheet, return its corresponding column number.



Problem Constraints
1 <= |A| <= 100



Input Format
First and only argument is string A.



Output Format
Return an integer



Example Input
Input 1:

 1
Input 2:

 28


Example Output
Output 1:

 "A"
Output 2:

 "AB"


Example Explanation
Explanation 1:

 1 -> "A"
Explanation 2:

A  -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
'''

'''
Easy enough.
base conversion
'''
import math

def solve(s):
    result = 0
    start = ord(str('A')[0])

    powerValue = 0
    for i in range(len(s)-1, -1, -1):
        currentValue = ord(str(s[i]))
        currentValue -= start # set to 0 base
        currentValue += 1

        result += (currentValue * int(math.pow(26, powerValue)))

        powerValue += 1
    return result

s = "AAAAAAAAAA"
result = solve(s)
print(result)