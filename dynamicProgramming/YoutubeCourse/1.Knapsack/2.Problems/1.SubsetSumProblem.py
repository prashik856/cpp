'''
Subset Sum Problem

1. Problem Statement
2. Similarity
3. Code Variations (Code, Initialization)

1. Problem Statement
arr: 2 3 7 8 10
sum: 11

Check whether we have a subset of array whose sum is equal to the given sum.

Output just requires true or false.
We don't need to output the given array.
Printing it is possible, but now we will just print if true or false.


2. Similarity
We know, in knapsack we are givne item array, and a weight W (max capacity or something)
Since we are just given one array, we will just assume we have given a weight array.
Here, we have give a single array, which will be our weight array.
We are given a sum so we have a W whose value is equal to sum.

And we want to choose the values of the array (subset of the array)
Thus we have a similarity!

Now, we array
arr: 2 3 7 8 10
so n = 5
sum : 11
W = 11
so, table of size table[5+1][11+1] = table[6][12]

We will create our matrix.
Our output will be true or false.

Initialization:
Looking at our subproblem.
Given empty array, and a sum is 0.
we cannot select anything from the array

We can just select tempty subset whose sum is 0.
if size of array is 1. we have some elemnet {2 here}.
for n==1, W==0, we can again select {} whose sum is 0.
So its always possible!
for table[:][0] = True {for weight 0, it's always possible.}

now, when sum = 1, and arr : {} .
Since we have empty array, how can we select anything.
So it's not possible to select anything from the array whose sum is 1.
so table[0][0] = true.
But table[0][1] = false // empty array
so table[0][1], table[0][2], .... table[0][n] = False.

Now, our code time for initialization.
for i:
    for j:
        if(i==0){
            table[i][j] = False
        }
        if(j == 0){
            table[i][j] = True
        }

Now, initialization done.
We have a different initialization here.

Now, Choice code.
now, wt[] -> arr[]
W -> sum

To convert max to true or false, in numbers 
max of two numbers will be numbers.
But in bool, we can change max to || condition.

Now, our variation.
if(arr[i-1] <= j){
    table[i][j] = table[i-1][j-arr[i-1]] || table[i-1][j]
} else {
    table[i][j] = table[i-1][j]
}
'''
arr = [2,3,7,8,10]
n = len(arr)
sumValue = 11
W = sumValue
table = []
for i in range(n+1):
    table.append([])
    for j in range(W+1):
        table[i].append(False)
        # If arr size is 0, always false
        if(i == 0):
            table[i][j] = False
        # If sum is 0, always true
        if(j==0):
            table[i][j] = True 
print(table)
for i in range(1,n+1):
    for j in range(1,W+1):
        if(arr[i-1] <= j):
            table[i][j] = table[i-1][j-arr[i-1]] or table[i-1][j]
        else:
            table[i][j] = table[i-1][j]
print(table)
print(table[n][W])

'''
Summary:
given arr: 2  3 7 8 10
sum 11
Give true or false, if we have a subset of array whose sum is equal to given sum.

Remember, the sum of null subset is always equal to 0.
wt -> arr
W -> sum.
Use the similarities from our knapsack problem in this problem.
'''