/*
https://www.geeksforgeeks.org/maximum-manhattan-distance-between-a-distinct-pair-from-n-coordinates/
Given an array arr[] consisting of N integer coordinates,
the task is to find the maximum Manhattan Distance between any two distinct pairs of coordinates.

The Manhattan Distance between two points (X1, Y1) and (X2, Y2) is given by |X1 – X2| + |Y1 – Y2|.

Naive Approach:
The simplest approach is to iterate over the array, and for each coordinate,
calculate its Manhattan distance from all remaining points.
Keep updating the maximum distance obtained after each calculation.
Finally, print the maximum distance obtained.


Efficient Approach:
The idea is to use store sums and differences between X and Y coordinates and find the answer by sorting those
differences.
Below are the observations to the above problem statement:
Manhattan Distance between any two points (Xi, Yi) and (Xj, Yj) can be written as follows:
|Xi – Xj| + |Yi – Yj| = max(Xi – Xj -Yi + Yj,
                                         -Xi + Xj + Yi – Yj,
                                         -Xi + Xj – Yi + Yj,
                                          Xi – Xj + Yi – Yj).

The above expression can be rearranged as:
|Xi – Xj| + |Yi – Yj| = max((Xi – Yi) – (Xj – Yj),
                                          (-Xi + Yi) – (-Xj + Yj),
                                          (-Xi – Yi) – (-Xj – Yj),
                                          (Xi + Yi) – (Xj + Yj))

It can be observed from the above expression, that the answer can be
found by storing the sum and differences of the coordinates.

Follow the below steps to solve the problem:

Initialize two arrays sum[] and diff[].
- Store the sum of X and Y coordinates i.e., Xi + Yi in sum[] and their difference i.e., Xi – Yi in diff[].
- Sort the sum[] and diff[] in ascending order.
- The maximum of the values (sum[N-1] – sum[0]) and (diff[N-1] – diff[0]) is the required result.
*/
