'''
Minimum Subset sum Difference

Flow:
1. Problem Statement
2. Similarity
3. Solve using the previous concept

1. Problem statement
arr: 1 6 11 5
O/P : 1

For now, we have learned
Knapsack -> Subset Sum -> Equal sum partition ->
Subset sum count

Here, we have Partition1 and partition2, we
have sum1 and sum2 for these partitions.
We want to minimize abs(s1 - s2) 


2. Similarity
I think this problem is equal to equal sum partition.

I am right, this problem is very similar to ES Partition.
Since, we have solve ESP using Subset Sum.
So, we want to solve this question using subset sum too.

Now, we want to calculate S1 and S2
And Partition1 and Partition2.

Right now, we don't know exact values of S1 and S2. 
Since we are clueless about s1 and s2
But we can get the range values of S1 and S2.
so S1 will be in range (0, sumOfGivenArray)
The extreme values of partition is? -> the sum of the given array
another exterme value is null (0) -> 0
So, the extreme two partitions are {} and {sumOfArray}

So, initially, S1 = 0 and S2 = 23, i.e. the extreme partitions.


Now....
arr: 1 2 7
two extremes: 0 and 10
s1 = 0 and s2 = 10

Let the sum of array be sumArr.
We know s1 + s2 = sumArr
and we want to minimize abs(s1 - s2)
substitue value of s2 in our equation
At the end of the day, we want to minimize
abs(s1 - (sumArr - s1))
= abs(sumArr - 2*s1)
We want to minimize this equation
So now, we have reduced our problem.
That means, maximize the value of s1.
That means, we cannot take value of S1 < sumArr/2
Since if we take s1 < sumArr/2, 
abs(sumArr - s2) will always be positive

To sum up:
We always keep the value of s1 be be less than sumArr/2
Since we want s2 - s1 to be a positive value.

We vary the range to s1 till sumArr/2, and get the value of
sumArr - 2 * s1, and we get the minimum value from these values obtained.


Now, how to do it?
we want to minimize (range - 2 * S1)
now, how to calculate the values which s1 can take?

For this, this is what we can do
for i in range(sumArr/2):
    check if for a given i, is there a subset in array whose value sum is i?
    remember subset sum, we can do this using that.
    
    We need to run subsetSum once.
    Using this, we will get a our table.
    Now, using the table, we can easily check if
    table[len(arr)][i] is true or not.
    
     if i exists, we calculate sumArr - 2 * i
    result = min (result, sumArr - 2 * i)
return result

Summary:

'''
arr = [1,2,7]
n = len(arr)
sumArr = 0
for i in range(len(arr)):
    sumArr += arr[i]
# Create our table 
table = []
for i in range(n + 1):
    table.append([])
    for j in range(sumArr + 1):
        table[i].append(False)
        if(i == 0):
            table[i][j] = False
        if(j == 0):
            table[i][j] = True 
print(table)
for i in range(1, n+1):
    for j in range(1, sumArr + 1):
        if(arr[i-1] > j):
            table[i][j] = table[i-1][j]
        else:
            table[i][j] = table[i-1][j] or table[i-1][j-arr[i-1]]
print(table)

# Now go till sumArr/2
result = 999999999999999
for i in range(int(sumArr/2) + 1):
    if(table[n][i]):
        result = min(result, sumArr - 2 * i)
print("Value of result is: ")
print(result)

'''
Summary:
Concept:
Question: minimize abs(s2 - s1)
and we know, s1 + s2 = sumArr
so, in the end, we want to minimize abs(sumArr - 2*s1)
What can be the values of s1, 
s1 can take a value between (0, sumArr)
we want to make s2 - s1 to be positive.
So, range of s1 is (0, sumArr/2)
Even if we go till value of range, it won't matter.
Since abs value are being taken, we will still get the correct answer.

Code:
Create subsetArr using our arr and sumArr
We use the last row of the table created, and
calculate
range - 2 * s1.
We select the minimum value from above calculations.

Let's take it slowly to evolve our brain.
:)

'''