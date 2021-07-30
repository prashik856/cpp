'''
0-1 Knapsack Problem
Subset sum
Equal sum partition
count of subse sum
Minimum subset sum diff
target sum
No of subset and given difference

These are the problems in knapsack 0-1

There are minor changes in all these problems.

What is 0-1?
Knapsack problem is the first dp problem.

Knapsack are of three types:
1) Fractional knapsack (this comes in greedy)
2) 0/1 knapsack
3) Unbounded knapsack

What is the difference?

What is a knapsack?
Any bag is called the knapsack.

What happens?
Input is usually items -> i1, i2....in
Some value for their values
We have some weight array
We have value array
w : 1 3 4 5
v : 1 4 5 7

Then we have capacity W = 7

We want to pick items such that our profit is maximum.

Constraints:
We have maximum weight. We cannot extent weight W.
We want to choose the items such that we have max profit.

This is a knapsack problem.


1. Fractional knapsack
We can put fractional items in the knapsack.
For example, 1kg weight is left in the knapsack,
but we don't have any item of 1 kg. So, we can put a 
fractional item in our knapsack to maximize profit.
We can break the items!
We use a Greedy approach here. No need of DP here.

2. 0/1 knapsack:
We cannot put fractional items.
We either need to put the whole item in the knapsack, or don't put the item in knapsack at all.


3. UnBounded Knapsack:
We can put an item multiple times in our kanpsack.
This means that once we select an item, and put it in our knapsack, we 
can again select that item again and put it in our knapsack.
There is an unlimited supply of items.

Thus we have Fractional (0.5 possible), 0/1 (as a whole, no multiple occurance) and Unbounded knapsack (multiple occurance).


Coming back to 0/1 knapsack.
How to identify 0/1 knapsack?
we have w[], v[] and W.
w: 1 3 4 5
v: 1 4 5 7
W: 7
O/P : Max Profit

How to identify if it's DP.
-> We need a Choice (We also have a choice. We can put any item in our bag!)
-> We need an optimal choice (max, min, largest, etc. So we can see it here!).
thus the problem is DP problem.

First, always think of Recursion solution!
Then memoization!
Then optional is top-down, either do it or not, up to you.
DP = Recursion + Storage.




'''

