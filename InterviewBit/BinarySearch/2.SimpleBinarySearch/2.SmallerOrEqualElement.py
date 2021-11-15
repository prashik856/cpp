'''
Problem Description

Given an sorted array A of size N. Find number of elements which are less than or equal to B.

NOTE: Expected Time Complexity O(log N)



Problem Constraints
1 <= N <= 106

1 <= A[i], B <= 109



Input Format
First agument is an integer array A of size N.

Second argument is an integer B.



Output Format
Return an integer denoting the number of elements which are less than or equal to B.



Example Input
Input 1:

 A = [1, 3, 4, 4, 6]
 B = 4
Input 2:

 A = [1, 2, 5, 5]
 B = 3


Example Output
Output 1:

 4
Output 2:

 2


Example Explanation
Explanation 1:

 Elements (1, 3, 4, 4) are less than or equal to 4.
Explanation 2:

 Elements (1, 2) are less than or equal to 3.
'''
'''
Man, simple question but it took time -_-!
'''
def lowerBound(A, B):
    low = 0
    high = len(A) - 1
    while(low < high):
        mid = low + high
        mid = int(mid/2)

        if(A[mid] == B):
            return mid
        
        if(B > A[mid]):
            low = mid + 1
        else:
            high = mid - 1
    return low

def solve(A, B):
    result = 0
    n = len(A)
    # print("Length of given array is: " + str(n))

    lowerBoundIndex = lowerBound(A, B)
    # print("Lower Bound Index : " + str(lowerBoundIndex))
    # print("Lower Bound Index Value : " + str(A[lowerBoundIndex]))

    while(lowerBoundIndex >= 0 and A[lowerBoundIndex] > B):
        lowerBoundIndex -= 1

    while(lowerBoundIndex < n and A[lowerBoundIndex] <= B):
        lowerBoundIndex += 1
    # print("Final Index: " + str(lowerBoundIndex))
    # print("Final Index Value: " + str(A[lowerBoundIndex]))

    result = lowerBoundIndex
    if(result < 0):
        result = 0

    return result

A = [ 5 ]
B = 1
print("Given array is: ")
print(A)
print("Value to find: " + str(B))
result = solve(A, B)
print("Result: " + str(result))