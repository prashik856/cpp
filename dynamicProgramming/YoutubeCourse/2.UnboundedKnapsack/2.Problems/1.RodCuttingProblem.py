'''
Rod Cutting Problem

Flow:
1. Problem Staetment
2. Matching
3. How to identify?
Whether it is 0/1 or unbounded
4. Code variation
(if any)


Problem Statement:
Input:
length: 1 2 3 4 5  6  7  8
Prune:  1 5 8 9 10 17 17 20
N = 8
What is the problem statement?
Given a Rod with length N.
let say our unit is 8m.
We want to cut this rod. 
We have no restriction on cutting this rod.
We can have infinite number of cuts on this rod (Thus 
this is an unbounded knapsack).
Every lenght of rod will have a price.
We want to maximize this profit obtained after 
cutting the rod in pieces.

3. How to identify? 0/1 or unbounded knapsack?
Lenght can vary from 1 to N
and a Price array:
N = length of rod.
Some, times we are not given length array, since
we already know from the index of the price array what
is the length array.
thus, even if only price array is given, we can create a
length array

Thus, we have given, Price array[] and length of rod.
Thus, we ahve Price[], length[] and N e.g. length of Rod.

If we try similarity, 
These are our matching.
we have w[] as length[], value[] as Price[]
and W as N.
Thus this structure values our Knapsack problem

Example:
N : 4
length[]: 1 2 3 4
Price[]:  5 6 8 8
We want to cut the rod in pieces, such that we
want to maximize the profit.
Also, we have a choice whether to choose 1 or not.
choose 2 or not.
3 or not.
4 or not.
But we have learned 0/1 and Unbounded knapsack.
Which knapsack is this?
Now, we know 0/1 knapsack, items cannot be repeated.
But in unbounded knapsack, items can be repeated.
In this question, we can have multiple pieces of same size.
Thus this is a unbounded knapsack.

4. Code variation.
Are there any?
-> Now, we have variation of unbounded knapsack question.
Matching:
w[] - lenght[]
v[] - price[]
W - N
There are not changes at all.
This is basically traditional unbounded knapsack question.
'''

length = [1,2,3,4]
price = [5, 6, 8, 8]
N = 4
table = []
n = N
for i in range(n + 1):
    table.append([])
    for j in range(N + 1):
        table[i].append(-1)
        if i == 0 or j == 0:
            # No profit at all mate
            # when either N is 0, or no items given
            table[i][j] = 0
print(table)

for i in range(1, n+1):
    for j in range(1, N+1):
        if(length[i-1] > j):
            table[i][j] = table[i-1][j]
        else:
            table[i][j] = max(
                price[i-1] + table[i][j - length[i-1]],
                table[i-1][j]
            )
print(table)
result = table[n][N]
print("Result is : ")
print(result)

'''
This is just unbounded knapsack asked in a different way.

'''