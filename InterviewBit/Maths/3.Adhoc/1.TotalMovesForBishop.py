'''
Problem Description

Given the position of a Bishop (A, B) on an 8 * 8 chessboard.

Your task is to count the total number of squares that can be visited by the Bishop in one move.

The position of the Bishop is denoted using row and column number of the chessboard.



Problem Constraints
1 <= A, B <= 8



Input Format
First argument is an integer A denoting the row number of the bishop.

Second argument is an integer B denoting the column number of the bishop.



Output Format
Return an integer denoting the total number of squares that can be visited by the Bishop in one move.



Example Input
Input 1:

 A = 4
 B = 4


Example Output
Output 1:

 13
'''

'''
Simple math calculations
We just calculate min required steps!
'''

class Solution:
    # @param A : integer
    # @param B : integer
    # @return an integer
    def __init__(self, A, B):
        self.A = A
        self.B = B

    def solve(self, A, B):
        result = min(A-1, B-1) + min(A-1, 8-B) + min(8-A, B-1) + min(8-A, 8-B)
        return result
