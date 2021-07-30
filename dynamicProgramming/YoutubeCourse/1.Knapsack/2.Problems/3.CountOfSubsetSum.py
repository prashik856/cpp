'''
Count of subsets of a given sum.

Flow:
1. Problem Statement
2. Similar to subset sum
3. Code variation -> Initialization and Code
4. Return Type

1. Problem Statement
arr: 2 3 5 6 8 10
sum: 10

Return the count of number of subsets of array 
whose sum is equal to the given sum.

// My thinking
I think here, we will have to
if n==0 and W==0 -> one way, so 1
if W==0 -> always one way
if n==0 and W>0 -> No way, why? because sum of empty array
is always 0.
here, value will be 1.
we will have max (table[i-1][j-arr[i-1]] + table[i-1][j])
or table[i][j] = table[i-1][j]


Video ahead :)
We have seen knapsack -> subsetsum problem (if true or false)
-> Equal sum Partition
Now we are at Count of Subset.

1. Problem statement
arr[] and a sum. (similar to subset sum)
a subset whose sum value is equal to sum.

Here, we have an additional challenge of returning the count


4. Return Type
This will return a count.
here, return type is actually integer. (subset sum had a boolean return type)

3. code Variation:
code initialization
we have arr[] and sum.
arr: 2 3 5 6 8 10
sum: 10
For our example, the table size will be:
n = 6
sum = 10
table[7][11] -> our size of table
Similar to subset sum value, we initialize our table
we initilize True value to 1 [empty array sum is 0] 
and False value to 0[empty array sum always 0. so 
if sum > 0, it's impossible to set a subset]


Remember subset sum
if( arr[ i-1] <= j){
    t[i][j] = t[i-1][j] || t[i-1][j-arr[i-1]]
else 
    t[i][j] = t[i-1][j]
}

For countSubsetSum:
Our change:
# Parent is calling two choices
# we need to add their outputs, 
# since both of them represent a count
t[i][j] = t[i-1][j] + t[i-1][j-arr[i-1]] 

t[i][j] = t[i-1][j]
'''

arr = [2, 3, 5, 6, 8, 10]
W = 10
n = len(arr)
table = []
for i in range(n + 1):
    table.append([])
    for j in range(W + 1):
        table[i].append(-1)
        if( i == 0):
            table[i][j] = 0
        if( j == 0):
            table[i][j] = 1
print(table)

for i in range(1, n + 1):
    for j in range(1, W + 1):
        if(arr[i-1] > j):
            table[i][j] = table[i-1][j]
        else:
            table[i][j] = table[i-1][j] + table[i-1][j - arr[i-1]]
print(table)
print("Result is: ")
print(table[n][W])

'''
Summary:
count subsets with a given sum
arr[] 2 3 5 6 8 10
sum : 10
Expected output : 3

This is very similar to subset sum problem.
We change the return type to int.
we initialize our table first.
And we changed the or condition to count condition (summation)

That's it.
'''