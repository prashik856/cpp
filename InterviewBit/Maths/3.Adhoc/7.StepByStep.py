'''
Problem Description

Given a target A on an infinite number line, i.e. -infinity to +infinity.

You are currently at position 0 and you need to reach the target by moving according to the below rule:

In ith move you can take i steps forward or backward.
Find the minimum number of moves required to reach the target.



Problem Constraints
-109 <= A <= 109



Input Format
First and only argument is an integer A.



Output Format
Return an integer denoting the minimum moves to reach target.



Example Input
Input 1:

 3
Input 2:

 2


Example Output
Output 1:

 2
Output 2:

 3


Example Explanation
Explanation 1:

 On the first move we step from 0 to 1.
 On the second step we step from 1 to 3.
Explanation 2:

 On the first move we step from 0 to 1.
 On the second move we step  from 1 to -1.
 On the third move we step from -1 to 2.
'''
'''
Solution Approach:
https://www.geeksforgeeks.org/find-minimum-moves-reach-target-infinite-line/

If target is negative, we can take it as positive because we start from 0 in symmetrical way. 

Idea is to move in one direction as long as possible, this will give minimum moves. 

Starting at 0 first move takes us to 1, second move takes us to 3 (1+2) position, third move takes us to 6 (1+2+3) position, 
ans so on; 
So for finding target we keep on adding moves until we find the nth move such that 1+2+3+…+n>=target. 
Now if sum (1+2+3+…+n) is equal to target the our job is done, i.e we’ll need n moves to reach target. 
(We have implemented it using inquality)
(we can find the value of n by solving this equation: n(n+1)/2 >= target. Given target, we can get the value of n)

Now next case where sum is greater than target. 
Find the difference by how much we are ahead, i.e sum – target. Let the difference be d = sum – target. 

If we take the i-th move backward then the new sum will become (sum – 2i), 
i.e 1+2+3+…-x+x+1…+n. 
(We can work it out ourselves. If we have any i'th move backward, our sum will actually be equal to sum-2i.)

Now if sum-2i = target then our job is done. 
Since, sum – target = 2i, i.e difference should be even as we will get an integer i flipping which will give the answer. 
So following cases arise. 
Case 1 : Difference is even then answer is n, (because we will always get a move flipping which will lead to target). 
Case 2 : Difference is odd, then we take one more step, i.e add n+1 to sum and now again take the difference. 
If difference is even the n+1 is the answer else we would have to take one more move and this will 
certainly make the difference even then answer will be n+2.

Explanation : Since difference is odd. Target is either odd or even. 
case 1: n is even (1+2+3+…+n) then adding n+1 makes the difference even. 
case 2: n is odd then adding n+1 doesn’t makes difference even so we would have to take one more move, so n+2.

Example: 
target = 5. 
we keep on taking moves until we reach target or we just cross it. 
sum = 1 + 2 + 3 = 6 > 5, step = 3. 
Difference = 6 – 5 = 1. 
Since the difference is an odd value, 
we will not reach the target by flipping any move from +i to -i. 
So we increase our step. 
We need to increase step by 2 to get an even difference (since n is odd and target is also odd). 
Now that we have an even difference, we can simply switch any move to the left (i.e. change + to -) 
as long as the summation of the changed value equals to half of the difference. We can switch 1 and 4 or 2 and 3 or 5. 
'''
import math

def solve(a):
    a = abs(a)
    result = 0

    sqrtValue = math.sqrt(8 * a + 1)
    n = sqrtValue - 1
    n = n/2
    # print("Value of n is: " + str(n))

    maxN = int(math.ceil(n))
    minN = int(math.floor(n))

    minReach = minN * (minN + 1)
    minReach = int(minReach/2)

    maxReach = maxN * (maxN + 1)
    maxReach = int(maxReach/2)

    # print("Minimum Reach is: " + str(minReach))
    # print("Maximum Reach is: " + str(maxReach))

    if(maxReach == a):
        return maxN
    if(minReach == a):
        return minN

    diff = maxReach - a

    # if diff is even
    if(diff % 2 == 0):
        return maxN
    # diff is odd
    else:
        maxReach += maxN + 1
        diff = maxReach - a
        if(diff % 2 == 0):
            return maxN + 1
        else:
            return maxN + 2

    return result

a = 100000
result = solve(a)
print(result)