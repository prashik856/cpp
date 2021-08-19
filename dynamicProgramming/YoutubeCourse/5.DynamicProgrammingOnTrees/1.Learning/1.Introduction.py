'''
Dynamic Programming on Trees

Introduction

1. General Syntax
2. How DP can be applied to Trees (Identification)
3. Diameter of a Binary Tree (Need to solve this problem once)
4. Maximum path sum from Node to any node
5. Maximum Path sum from leafs to leafs
6. Diameter of N-ary Tree

2. how to identify if we can apply dp on this tree question?
Identification:
Somewhat introduction to Diameter of Tree
Diameter of Tree : Longest path between two leaves!
How will we do it?
It is not important that the path will pass through the root.
It can be be passing through the root, not it might not be.
Basically, for every node, we need to calculate the height 
of every node, and then calculate the maximum value of them.

For every node -> We calculate left tree height, and we calculate right tree height, and then find the max value.
To get heigh -> O(n) * n(for n nodes) = O(n*2) complexity 
without DP
We don't want to do repetitive work.
We don't want to travel a same node multiple times just to
calculate their heights.
Whenever something comes up about saving the value.
We should think of DP.

Whenever we have a function, when we need to tree traverse 
that too for every node, we will be using DP there.!

'''
