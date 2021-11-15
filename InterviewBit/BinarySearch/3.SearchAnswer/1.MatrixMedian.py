'''
Given a matrix of integers A of size N x M in which each row is sorted.

Find an return the overall median of the matrix A.

Note: No extra memory is allowed.

Note: Rows are numbered from top to bottom and columns are numbered from left to right.




Input Format

The first and only argument given is the integer matrix A.
Output Format

Return the overall median of the matrix A.
Constraints

1 <= N, M <= 10^5
1 <= N*M  <= 10^6
1 <= A[i] <= 10^9

N*M is odd
For Example

Input 1:
    A = [   [1, 3, 5],
            [2, 6, 9],
            [3, 6, 9]   ]
Output 1:
    5
Explanation 1:
    A = [1, 2, 3, 3, 5, 6, 6, 9, 9]
    Median is 5. So, we return 5.

Input 2:
    A = [   [5, 17, 100]    ]
Output 2:
    17 ``` Matrix=
'''
'''
Solution Approach:
https://www.geeksforgeeks.org/find-median-row-wise-sorted-matrix/
Method 1:
Simple method. Create a single matrix, store all elements in it, and then find the median.
We will be using extra space here.

Method 2:
An efficient approach for this problem is to use a binary search algorithm. 
The idea is that for a number to be median there should be exactly (n/2) numbers which are less than this number. 
So, we try to find the count of numbers less than all the numbers.
Algorithm:
> First, we find the minimum and maximum elements in the matrix. 
> The minimum element can be easily found by comparing the first element of each row, and similarly, 
the maximum element can be found by comparing the last element of each row.
> Then we use binary search on our range of numbers from minimum to maximum, we find the mid of the min and max 
and get a count of numbers less than or equal to our mid. 
> And accordingly change the min or max.
> For a number to be median, there should be (r*c)/2 numbers smaller than that number.
> So for every number, we get the count of numbers less than that by using upper_bound() in each row of the matrix, 
> if it is less than the required count, the median must be greater than the selected number, 
else the median must be less than or equal to the selected number.
'''
def binary_search(arr, low, high, value):
    n = len(arr)
    while low < high:
        mid = low + high
        mid = int(mid / 2)

        if arr[mid] == value:
            return mid
        
        if value > arr[mid]:
            low = mid + 1
        else:
            high = mid - 1
    
    # For upper bound
    while(low >=0 and low < n and arr[low] <= value):
        low += 1

    return low

def solve(A):
    # find min and max
    n = len(A)
    m = len(A[0])
    print("N: " + str(n))
    print("M: " + str(m))
    minValue = 9999999999
    maxValue = -9999999999

    for i in range(n):
        minValue = min(A[i][0], minValue)
        maxValue = max(A[i][m-1], maxValue)

    print("Min value: " + str(minValue))
    print("Max value: " + str(maxValue))
    # Got our min and max value
    # We need exactly n*m/2 elements smaller
    value = n*m + 1
    value = int(value/2)
    print("Value to find: " + str(value))
    result = 0
    while minValue < maxValue:
        mid = minValue + maxValue
        mid = int(mid/2)
        # for each row, we need to count the numbers less than mid
        place = 0
        for i in range(n):
            index = binary_search(A[i], 0, m-1, mid)
            place += index
        if value > place:
            minValue = mid + 1
        else:
            maxValue = mid
    return minValue

A = [   
        [1, 3, 5],
        [2, 6, 9],
        [3, 6, 9]   
    ]
A = [   [5, 17, 100]    ]

result = solve(A)
print("Result: " + str(result))

# Better to check out cpp code, which is working awesomely