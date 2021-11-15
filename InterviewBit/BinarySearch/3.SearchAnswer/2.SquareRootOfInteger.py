'''
Problem Description

Given an integer A.

Compute and return the square root of A.

If A is not a perfect square, return floor(sqrt(A)).

DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY.

NOTE: Do not use sort function from standard library. Users are expected to solve this in O(log(A)) time.



Input Format
The first and only argument given is the integer A.



Output Format
Return floor(sqrt(A))



Example Input
Input 1:

 11
Input 2:

 9


Example Output
Output 1:

 3
Output 2:

 3


Example Explanation
Explanation:

 When A = 11 , square root of A = 3.316. It is not a perfect square so we return the floor which is 3.
 When A = 9 which is a perfect square of 3, so we return 3.
'''
'''
Solution Approach:
Simple binary search for the integer that we want!
'''
def binarySearch(A):
    low = 0
    high = int(A/2) + 1
    while(low < high):
        mid = (low + high)
        mid = int(mid/2)
        if mid*mid == A:
            return mid
        
        if A > mid*mid:
            low = mid + 1
        else:
            high = mid - 1
    return low

def solve(A):
    result = binarySearch(A)
    if(result*result == A):
        return result
    
    if(result*result > A):
        return result - 1
    
    if(result * result < A and (result+1)*(result+1) < A):
        return result + 1
    
    if(result * result < A and (result+1)*(result+1) > A):
        return result

    return result

A = 9
result = solve(A)
print("Result: " + str(result))