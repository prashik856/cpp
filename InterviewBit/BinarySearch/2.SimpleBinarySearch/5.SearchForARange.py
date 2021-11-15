'''
Given a sorted array of integers A(0 based index) of size N, find the starting and ending position of a given integar B in array A.

Your algorithm’s runtime complexity must be in the order of O(log n).

Return an array of size 2, such that first element = starting position of B in A and second element = ending position of B in A, if B is not found in A return [-1, -1].




Input Format

The first argument given is the integer array A.
The second argument given is the integer B.
Output Format

 Return an array of size 2, such that first element = starting position of B in A and second element = ending position of B in A, if B is not found in A return [-1, -1].
Constraints

1 <= N <= 10^6
1 <= A[i], B <= 10^9
For Example

Input 1:
    A = [5, 7, 7, 8, 8, 10]
    B = 8
Output 1:
    [3, 4]
Explanation 1:
    First occurence of 8 in A is at index 3
    Second occurence of 8 in A is at index 4
    ans = [3, 4]

Input 2:
    A = [5, 17, 100, 111]
    B = 3
Output 2:
    [-1, -1]
'''

'''
Easy enough!
'''

def binarySearch(A, B, n):
    low = 0
    high = n-1
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
    result = []
    n = len(A)
    # All Equal
    if(A[0] == A[n-1] and A[0] == B):
        return [0, n-1]

    if(n == 1):
        if(A[0] == B):
            return [0, 0]
        else:
            return [-1, -1]

    indexValue = binarySearch(A, B, n)

    if(A[indexValue] != B):
        return [-1, -1]
    else:
        temp = indexValue
        start = -1
        end = -1
        while( temp < n and A[temp] == B):
            temp += 1
        end = temp - 1
        temp = indexValue - 1
        while(temp >= 0 and A[temp] == B):
            temp -=1
        start = temp + 1
        result = [start, end]

    return result

A = [5, 17, 100, 111]
B = 3

result = solve(A, B)
print("Result: ")
print(result)