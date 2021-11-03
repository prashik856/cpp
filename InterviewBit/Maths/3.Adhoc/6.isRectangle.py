'''
Problem Description

Given four positive integers A, B, C, D, determine if there’s a rectangle such that the lengths of its sides are A, B, C and D (in any order).

If any such rectangle exist return 1 else return 0.



Problem Constraints
1 <= A, B, C, D <= 100



Input Format
First argument is an interger A.

Second argument is an interger B.

Third argument is an interger C.

Fourth argument is an interger D.



Output Format
If any such rectangle exist whose sides are A, B, C, D in any orde then return 1 else return 0.



Example Input
Input 1:

 A = 1
 B = 1
 C = 2
 D = 2
Input 2:

 A = 1
 B = 2
 C = 3
 D = 4


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 
 The rectangle drawn above is one of the rectangles that can be formed by side length of 1, 1, 2, 2 so we will return 1.
Explanation 2:

 No such rectangle exist whose sides are 1, 2, 3, 4. So, we will return 0.
'''

'''
Easy Enough!
'''
def solve(A, B, C, D):
    if(A == B):
        if(C == D):
            return 1
        else:
            return 0
    elif(A == C):
        if(B == D):
            return 1
        else:
            return 0
    return 0

allValues = [1, 1, 2, 2]
A = allValues[0]
B = allValues[1]
C = allValues[2]
D = allValues[3]

result = solve(A, B, C, D)