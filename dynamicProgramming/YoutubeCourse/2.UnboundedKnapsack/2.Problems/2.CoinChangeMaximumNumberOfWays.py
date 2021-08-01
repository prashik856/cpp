'''
Coin Change 1 - Maximum number of ways

Coins[]: 1 2 3
sum : 5
O/P : 5

Flow:
1. Problem Statement
2. Remember Subset Sum knapsack?
3. Why this is knapsack and why is it unbounded knapsack?
4. Code Variation.

1. Problem Statement
Coin change can also have minimum number of coins, 
which is another variation.
We have infinite supply of coins.
We want all the set of coins whose value will be equal
to the value ot sum.
We want to calculate total number of ways
using set of coins whose value is sum

3. Why is it knapsack?
Here, for every coin, we have a choice, whether to 
include it or not.
Thus, for the given items, we have a choide to include
it or not. 
Thus it is a knapsack pattern.

3. Why unbounded knapsack?
Matching first:
We only have one given array.
Thus, we have our w[] as coins[]
and W as sum
from the given set, we can select a coin any number of
times.
That means, we can use an item multiple times.
Thus this is an unbounded knapsack question.

2.Recall Subset sum?
given arr and a sum, is it possible to have a 
subset in array whose sum is equal to sum.
Just true or False.

Remember
if(arr[i-1] <= j)
    t[i][j] = t[i-1][j] || t[i-1][j-arr[i]]
else:
    t[i][j] = t[i-1][j]

Remember Count of Subset:
if(arr[i-1] <= j)
    Why this?
    Because we wanted the all possible counts
    from the choises!
    Thus we need to add them.
    Whenever there is count or number of ways, there 
    is addition.
    t[i][j] = t[i-1][j] + t[i-1][j-arr[i]]
else:
    t[i][j] = t[i-1][j]

4. Code Variation:
Coin Change -> max number of ways
Matching -> Knapsack -> Unbounded knapsack.
also, w[] -> coins[]
    W -> sum

Now, what to change?
if(arr[i-1] <= j)
    t[i][j] = t[i-1][j] + t[i][j-arr[i-1]]
else :
    t[i][j] = t[i-1][j]

Initialization?
when n == 0, W == 0?
we can take {}, whose sum is 0.
So n==0 or W ==0, t[0][0] = 1
when sum==0, t[:][0] = 1
when len(arr) == 0, t[1:][1] = 0
why, when sum>0, and arr = {},
we cannot have any subset, whose sum is greater than 0.

Thus initialization done. 
Code done.
'''
arr = [1,2,3]
sum = 5
n = len(arr)

table = []
for i in range(n + 1):
    table.append([])
    for j in range(sum + 1):
        table[i].append(-1)
        if i == 0:
            table[i][j] = 0
        if j == 0:
            table[i][j] = 1
print(table)

for i in range(1, n + 1):
    for j in range(1, sum + 1):
        if(arr[i-1] > j):
            table[i][j] = table[i-1][j]
        else :
            table[i][j] = table[i-1][j] + table[i][j-arr[i-1]]
print(table)

result = table[n][sum]
print("Result is: ")
print(result)

'''

'''