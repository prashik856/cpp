'''
Count the number of subset with a given difference.

Flow:
1. Problem statement
2. Will try to reduce the problem statement
3. Solve it using already solved problem.

arr: 1 1 2 3
Diff: 1


1. Problem staement
arr: 1 1 2 3
diff : 1
Output: 3 -> an integer output

// my thinking?
What we want?
we want s1 - s2 = diff
We want to find the cound s.t
s1 - s2 = diff
s1 + s2 = sumArr
2 * s1 = sumArr + diff
s1 = (sumArr + diff)/2
s2 = sumArr - sumArr/2 - diff/2
s2 = (sumArr-diff)/2

We will get value of s1, we will get value of s2.
Check how many values are there for s1
check how many values are there for s2

answer = min(table[s1], table[s2])


Video:
Given arr, we need s1 and s2, we need s1 - s2 = diff
for 1 1 2 3 -> (1,2) and (3,1) -> 3 - 4 = 1 so, we can use 1,2 and 3,1
(1,3) and (1,2) -> (this is a different 1) -> 4 - 3 = 1
(1,1,2) (3) -> 4 - 3 = 1
so 3 should be the output


2. Reduce the complex statement to simpler problem
Given arr: 
s1 - s2 = diff
s1 + s2 = sumArr
Thus we get the values of s1 and s2 using our above 2 equations
if we sum these two equations
2 * s1 = diff + sumArr
s1 = (diff + sumArr)/2
s2 = (sumArr - diff)/2
For the given example, s1 = 4, s2 = 3
Now, we actually need the count of s1 and s2

Now, we have already done this problem
This is CountofSubsetSum problem in actuality.
Thus, we need to run a CountofSubsetSum DP once, get the value of 
s1 and then get value of s2, and then get the minimum count.

Also, one thing to notice, 
what if diff + sumArr is odd?
then the value of s1 is not possible to be int.
We can just safely return 0 in this case.
There won't be any subset possible.

e.g. 1 1 2 3
sumArr = 7
Diff = 2
No combination is possible!

'''
arr = [1, 1, 2, 3]
diff = 2
n = len(arr)
sumArr = 0
for i in range(n):
    sumArr += arr[i]

result = 0
countS1 = 0
countS2 = 0
if (sumArr + diff) % 2 != 0:
    result = 0
else:
    s1 = int((sumArr + diff)/2)
    s2 = sumArr - s1
    table = []
    for i in range(n+1):
        table.append([])
        for j in range(sumArr + 1):
            table[i].append(-1)
            if(i == 0):
                table[i][j] = 0
            if(j == 0):
                table[i][j] = 1
    print(table)
    for i in range(1, n+1):
        for j in range(1, sumArr + 1):
            if(arr[i-1] > j):
                table[i][j] = table[i-1][j]
            else:
                table[i][j] = table[i-1][j] + table[i-1][j-arr[i-1]]
    print(table)
    countS1 = table[n][s1]
    countS2 = table[n][s2]
    print("Count s1: " + str(countS1))
    print("Count S2: " + str(countS2))
result = min(countS1, countS2)
print("Value of result is: ")
print(result)

'''
Summary:
Given array, we need to make two subsets
s1 and s2

We need
sum(s1) - sum(s2) = diff

we also know, sum(s1) + sum(s2) = sum(arr)
using these two equations, we get the value of
s1 and s2

Now, we just need to count the number of subsets
whose sum is equal to s1

First we need, sum(s1) = (sumArr + diff)/2
countSubset(arr, sum)
our result is in table[n][s1]
:)
'''