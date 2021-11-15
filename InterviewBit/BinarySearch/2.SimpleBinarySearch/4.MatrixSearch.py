'''
Given a matrix of integers A of size N x M and an integer B.

Write an efficient algorithm that searches for integar B in matrix A.

This matrix A has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than or equal to the last integer of the previous row.
Return 1 if B is present in A, else return 0.

Note: Rows are numbered from top to bottom and columns are numbered from left to right.




Input Format

The first argument given is the integer matrix A.
The second argument given is the integer B.
Output Format

Return 1 if B is present in A, else return 0.
Constraints

1 <= N, M <= 1000
1 <= A[i][j], B <= 10^6
For Example

Input 1:
    A = 
    [ [1,   3,  5,  7],
      [10, 11, 16, 20],
      [23, 30, 34, 50]  ]
    B = 3
Output 1:
    1

Input 2:
    A = [   [5, 17, 100, 111]
            [119, 120,  127,   131]    ]
    B = 3
Output 2:
    0
'''
'''
Solution Approach:

1. First, we need to find the value of row.
2. Then we need to find the value of column.

PLEASE TAKE CARE OF INEQUALITY
'''
def getRowIndex(A, B):
    low = 0
    high = len(A) - 1
    while(low < high):
        mid = low + high
        mid = int(mid/2)
        if(A[mid][0] == B):
            return mid
        
        if(B > A[mid][0]):
            low = mid + 1
        else:
            high = mid - 1
    
    return low

def getColumnIndex(A, B, rowIndex, m):
    low = 0
    high = m-1
    while(low < high):
        mid = low + high
        mid = int(mid/2)
        if(A[rowIndex][mid] == B):
            return mid
        if(B > A[rowIndex][mid]):
            low = mid + 1
        else:
            high = mid - 1
    return low

def solve(A, B):
    result = 0
    n = len(A)
    m = len(A[0])
    # Base condition
    if(A[0][0] > B):
        return 0
    if(B > A[n-1][m-1]):
        return 0

    # Now, our B exists somewhere in our matrix
    rowIndex = getRowIndex(A, B)
    print("RowIndex: " + str(rowIndex))
    if(A[rowIndex][0] == B):
        return 1

    if(rowIndex - 1 >= 0 and B < A[rowIndex][0]):
        rowIndex -= 1
    
    elif(rowIndex + 1 <= n-1 and B > A[rowIndex][m-1]):
        rowIndex += 1

    columnIndex = getColumnIndex(A, B, rowIndex, m)
    if(A[rowIndex][columnIndex] == B):
        return 1

    return result

A =[
  [1, 4, 7, 7, 11, 12, 13, 18, 23, 24],
  [32, 34, 35, 36, 37, 40, 41, 44, 44, 44],
  [45, 52, 52, 53, 54, 55, 57, 59, 63, 64],
  [66, 73, 75, 76, 76, 79, 85, 89, 90, 92],
  [92, 94, 95, 96, 96, 96, 97, 97, 97, 98],
]
B = 18
print("Given array is: ")
print(A)
print("Value to find: " + str(B))
print("Number of rows in A: " + str(len(A)))
print("Number of columns in A: " + str(len(A[0])))
result = solve(A, B)
print("Result: " + str(result))