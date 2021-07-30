'''
Target Sum:

arr: 1 1 2 3
sum: 1
Output: 3

Last pattern in Knapsack problem.


Flow:
1. Problem statement
2. Solving it and reducing it
3. will solve it using already solved problem.

1. Problem statement
We can either assign +/- sign to every element in our array.
We then need to sum them, and we should get the value of sum
Example
arr: 1 1 2 3
sum : 1
+1 -1 -2 +3 -> summing them gives 1.
there are three ways we can do this.

// my thinking
This is basically the same thing as s1 - s2 = diff
So, we just need to return the same guy

// if we have 0s in input, we need to take care of initialization properly.
// given arr = {0,1,2} and sum = 0
we can have two subsets, {} or {0} -> There are actually 2 ways 
arr = {0,0,1} -> how many?
for sum = 0, we have {} {0}, {} {0}, {} {0,0}, and {0} {0}
so, 2^(no Of zeros) will be the ways  to get answer as 0
when there are zeros in the input array.

The video has same thinking as me:
so, this is the same as our previous question.
This is the same problem as Count the number of 
subsets whose difference of sum is equal 
to the given difference.

The way they are asking things is different.
but it is the same as our Subset Sum difference count problem.


'''
arr = [1, 1, 2, 3]
sumValue = 1
'''
Refer previous problem
'''