/*
Given a 3 x A board,  find the number of ways to color it using at most 4 colors such that no 2 adjacent boxes have same color.

Diagonal neighbors are not treated as adjacent boxes.

Return the ways modulo 109 + 7 as the answer grows quickly.

Input Format:

The first and the only argument contains an integer, A.
Output Format:

Return an integer representing the number of ways to color the board.
Constraints:

1 <= A < 100000
Examples:

Input 1:
    A = 1

Output 1:
    36

Input 2:
    A = 2

Output 2:
    588
*/
/*
Solution Approach:
https://www.geeksforgeeks.org/ways-color-3n-board-using-4-colors/
We are going to solve this using dynamic approach because when a new column is added to the board, 
the ways in which colors are going to be filled depends just upon the color pattern in the current column. 
We can only have a combination of two colors and three colors in a column. 
All possible new columns that can be generated is given in the image. 
Please consider A, B, C and D as 4 colors. 
From now, we will refer 3 colors combination for a Nth column of the 3*N board as W(n) and two colors as Y(n). 
We can see that each W can generate 5Y and 11W, and each Y can generate 7Y and 10W. We get two equation from here 
We have two equations now, 
 
W(n+1) = 10*Y(n)+11*W(n);
Y(n+1) = 7*Y(n)+5*W(n);

Video Solution:
https://www.youtube.com/watch?v=wInXbAHi72g&ab_channel=ChirayuJain
*/