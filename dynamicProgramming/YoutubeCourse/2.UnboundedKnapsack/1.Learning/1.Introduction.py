'''
UNBOUNDED KNAPSACK

Repeated items are allowed here.

Flow:
Recall Differences
See Code difference and variations

Related Problems:
1) Rod Cutting
2) Coin change (max number of ways)
3) Coin change 2 (minimum number of coins)
4) Maximum ribbon cut


Video:
Knapsack are of 3 types:
1 -> Fractional knapsack (Greedy)
2 -> 0/1 knapsack (Done)
3 -> Unbounded Knapsack ( and it's variations)

1. Recall Differences
Recalling 0/1 knapsack
we have items arr[] which can have two properties, 
weigh[] and value[]
In 0/1, we cannot have multiple occurance of a same item.
In Unbounded knapsack, it is allowed.

What will be it's recursive code?
in our knapsack code, we had a decision to make
for n-1 value, we made a decision to either include the data
or not include the data.

Now, when we process n-1 th value, 
if we select n-1th element, and do not include it.
-> That means our n-1th element is processed
If we select n-1th element, and include it in our knapsack
-> That means that our n-1th element is still not processed.


Once we regect an item, we will just just that we will never visit that item again.
But if we like an item, and we include it in our item,
we may accept to include that item again in our knapsack.


To Sum up:
In 0/1 knapsack, if we include an item in our knapsack, it is finally processed.
That is not the case here.
We will have multiple occurances here.

2. Code and Variations
Remember our knapsack code
if(w[i-1] <= j) {
    t[i][j] = max(val[i-1] + t[i-1][j-w[i-1]], t[i-1][j])
} else {
    t[i][j] = t[i-1][j]
}

Initialization:
When sum = 0, and n>=0, there can be not profit at all
So, table[:][0] = 0 {the first column is 0}
When sum > 0, and n=0, again since there are no items,
we cannot do anything.
Again the profit is 0.
So table[:][0] = 0

For unbounded knapsack:
when we include nth item, and choice not to take it, we will call n-1th item
But when we include nth, and choose to take it,
we need to again call nth item.
So, our recursive function will be:
if(w[i-1] <= j){
    // since i can be occured, multiple times, 
    // we need to include i
    // This will be only for the table.

    // This is the only change here.
    // include i again and again and again.
    t[i][j] = max(
        val[i-1] + t[i][j-w[i-1]],
        t[i-1][j]
    )
} else {
    t[i][j] = t[i-1][j]
}

'''
w = [1,1,2,3]
v = [5,6,2,6]
W = 10
n = len(w)

table = []
for i in range(n+1):
    table.append([])
    for j in range(W + 1):
        table[i].append(-1)
        if(i==0 or j==0):
            table[i][j] = 0
print(table)

for i in range(1, n+1):
    for j in range(1, W+1):
        if(w[i-1] > j):
            table[i][j] = table[i-1][j]
        else:
            table[i][j] = max(
                v[i-1] + table[i][j - w[i-1]],
                table[i-1][j]
            )
print(table)
result = table[n][W]
print("Result is : ")
print(result)