/*
Problem Description
 
 

Given a graph with A nodes.
The edges in graph are given in a 2D array B.
There is an undirected edge between B[i][0] and B[i][1].
Find the number of connected components in the given graph.


Problem Constraints
1 <= A <= 105
1 <= |B| <= 105
1 <= B[i][0], B[i][1] <= A


Input Format
First argument is an integer A.
Second argument is a 2D integer array B.


Output Format
Return an integer.


Example Input
Input 1:
A = 4
B = [[1, 2],
     [2, 3]]
Input 2:

A = 3
B = [1, 2]
    [2, 1]


Example Output
Output 1:
2
Output 2:

2


Example Explanation
Explanation 1:
 The two connected components are [1, 2, 3] and [4].
Explanation 2:

The two connected components are [1, 2] and [3].
*/
/*
Simple disjoint set
*/
