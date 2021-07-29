# Our knapsack problem
# n is the len(weight)

# We create matrix
# We have max value of n and W
# e.g. n <= 100, W<=1000
table = []
for i in range(102):
    table.append([])
    for j in range(1002):
        table[i].append(-1)

# We need to do this for every test case
# i.e before our first knapsack function call
def initTable(n, W):
    table = []
    for i in range(102):
        table.append([])
        for j in range(1002):
            table[i].append(-1)
    # print(table)
# This will be our table
# We need to 

def knapsack(weight, value, W, n):
    # base case
    # Smallest valid input
    #print(table)

    if n == 0 or W == 0:
        return 0
    
    # Check if value is already present
    if(table[n][W] != -1):
        return table[n][W]

    # Choice diagram code
    if weight[n - 1] <= W:
        # include the profite we got value[n-1]
        includeChoice = value[n-1] + knapsack(weight, value, W - weight[n-1], n-1)
        
        # No need to include profit here
        notIncludeChoice = knapsack(weight, value, W, n-1)
        
        # return max of these choices
        table[n][W] = max(includeChoice, notIncludeChoice)
        return table[n][W]
    else:
        # No need to include n-1 weight value at all.
        table[n][W] = knapsack(weight, value, W, n-1)
        return table[n][W]
    # This will be our knapsack DP code
    # MEMOIZED

'''
Memoization is alternative of Topdown approach.
Memoization is kinda easy.
Complexity of Memoization and Tabulation is same.

We make our Table Array now.
Assuming we make our Table array.
What are the dimensions of this array?

In our function call, we have some inputs which changes, we have some values which changes.
In our function, W is changing and n is changing. 
Weight and Values array remain the same.

Make table array for only those variables which changes.
So! We need to include W and n to create our Table array.
W, n -> these two changing variables. 
We make matrix t of size n+1 x W+1
This matrix will be something like this:

(n+1) x (W + 1)
We will use memset() or some loop value to initialize it to -1 value.

Before we call any recursive funtion call, we will check if that value is already present in our table.
If it is present, we will return that value, and won't call the recursive function.
If the value is not present, we will call the recursive functoin.

In a nutshell > What are the changes that we are doing.
'''

initTable(4 + 1, 7 + 1)
print(knapsack([1,3,4,5], [1,4,5,7], 7, 4))