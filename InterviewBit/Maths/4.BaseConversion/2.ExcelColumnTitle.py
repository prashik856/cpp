'''
Problem Description

Given a positive integer A, return its corresponding column title as appear in an Excel sheet.



Problem Constraints
1 <= A <= 1000000000



Input Format
First and only argument is integer A.



Output Format
Return a string, the answer to the problem.



Example Input
Input 1:

 A = 1
Input 2:

 A = 28


Example Output
Output 1:

 "A"
Output 2:

 "AB"


Example Explanation
Explanation 1:

 1 -> A
Explanation 2:

1 -> A
2 -> B
3 -> C
...
26 -> Z
27 -> AA
28 -> AB 
'''
'''
Just the opposite to what we did in last question.
ord(<char value>) -> Gives ascii int
chr(<ascii int value>) -> Gives char value

Here, it is very important to take care of corner case, which are values which are divisible by 26.
When we are resetting the remainder, we also need to decrease the quotient (when number is divisible by 26).

Else, just decrease the remainder.
'''
def solve(a):
    result = ""

    temp = a
    while(temp > 0):
        quotient = int(temp / 26)
        remainder = int(temp % 26)
        
        if(remainder == 0):
            remainder = 25
            quotient -= 1
        else:
            remainder -= 1

        # print("Quotient value: " + str(quotient))
        # print("Remainder value: " + str(remainder))

        asciiIntValue = 65 + remainder
        charValue = chr(asciiIntValue)
        # print("Character value: " + str(charValue))
        result = str(charValue) + result

        temp = quotient
        print()

    return result

a = 103
result = solve(a)
print(result)
