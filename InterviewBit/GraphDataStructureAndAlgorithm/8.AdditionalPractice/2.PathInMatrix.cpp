/*
Problem Description
 
 

Given N x N matrix filled with 0, 1, 2, 3.

Find whether there is a path possible from source to destination, traversing through blank cells only. 
 
You can traverse up, down, right, and left. Return a single integer 1 if a path exists, otherwise 0.

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Blank Wall.
Note: there are an only a single source and single destination(sink).


Problem Constraints
2 <= N <= 103
0 <= Ai, j <= 3


Input Format
The first argument is the 2D integer array A.


Output Format
Return a single integer 1 if a path exists, otherwise 0.


Example Input
Input 1:
A = [[1, 0], [0, 2]]
Input 2:

A = [[1, 3], [3, 2]]


Example Output
Output 1:
0
Output 2:

1


Example Explanation
Explanation 1:
The source is blocked by walls on all its sides. So, there is no way to reach the destination.
Explanation 2:

We can take any possible path to reach the destination from the source.
*/
/*
Solution Approach:
Create graph first from the given board.
then just do a travel from source, and see if we can visit destination.
*/
