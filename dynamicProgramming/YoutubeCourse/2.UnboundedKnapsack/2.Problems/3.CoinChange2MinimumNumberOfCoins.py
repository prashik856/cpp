'''
Coin Change 2 - Minimum number of Coins
Coin[] : 1 2 3
sum : 5


Flow:
1. Problem Statement
2. Initialization
3. Code Variation

1. Problem statement:
This is unbounded knapsack variation.

input: 
coin[]: 1 2 3
sum : 5

We want to find a way, where we will require minimum 
number to coins whose sum will be equal to given 
sum value.

2. Initialization:
Remember initialization of t[n+1][w+1],
we had w, W
we have only given weight, so we only consider w[] (coins)
and W (sum)

Dimensions of table will be
t[n+1][sum+1]
n = 3, for given input
sum = 5, for given input
t[4][6] will be the dimensions of our table array

Let us look at our base cases:
when sum > 0 and coin[]:, what is the minimum number 
of coins? -> mathematically we can say we will require 
INF number of coins
let INF be represented by INF_MAX
so, for n == 0 and sum > 0 -> table[0][1:] = INF

What about when n == 0, sum == 0 -> we have no coins, 
but we need their sum as 0
Again, if we select INF number of coins, maybe we 
will get sum as 0
so t[0][0] = INF

Now, when sum = 0, and coin []: 1
Now, we need sum as 0, and we have one coin.
So, actual number of coins needed is 0.
table[1:][0] = 0

Will be get the answer if we now start filling the 
table using code?

Should we initialize 2nd Row?
We can, we will have some value in arr[0]
so, we can just fill in the second row ourselves.

What happens, when our coin value is 3, sum required is 4.
Now, we can never get the value of 4 using 3.
So, will fill the table[1][4] = INF (impossible way)
but, we will fill the table[1][3] = 1(because it is 
possible)

Let's fill the 2nd row now
for(j=1; j<=sum; j++){
    if j % arr[0] == 0:
        t[i][j] = j / arr[0]
}
// I solved it below, and I don't think we
// will need to initialze the second row.

Now, here if we want max number of coins, we 
will need to initialize it differently
and we will just run our knapsack code.

'''
coins = [1, 2, 3, 4, 5]
money = 5
n = len(coins)

INT_MAX = 999999999
table = []
for i in range(n + 1):
    table.append([])
    for j in range(money + 1):
        table[i].append(INT_MAX)
        if(i > 0):
            table[i][j] = 0
print(table)

for i in range(1, n+1):
    for j in range(1, money + 1):
        if(coins[i-1] <= j):
            table[i][j] = min(
                table[i-1][j],
                # since we have included the coin here
                # we increase the value
                1 + table[i][j-coins[i-1]]
            )
        else:
            table[i][j] = table[i-1][j]
print(table)
result = table[n][money]
print("Value of result is: ")
print(result)

'''
Code Variations:
-> Unbounded knapsack variation here
we know our code
w[] -> coin[]
W -> sum
'''