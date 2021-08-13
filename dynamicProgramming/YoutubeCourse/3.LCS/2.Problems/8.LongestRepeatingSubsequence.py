'''
Given a String, determine the longest repeating subsequence:

Example:
a : a a b b h c d 
O/P : a b d

How do we identify that this is a LCS Problem?
Simple -> Just by lookin at the question, it is asking us to find the "Longest Repeating Subsequence".

But there is only one input given?
Given only a single string a, we want to figure out what will be b.
Now, for string a, if we take string b equal to a, it's LCS will be string a itself.

How do we solve this problem?
We need Longest Repeating subsequence. That means, for a repeating subsequence, it's value should be repeated 
at least once.

To solve this question, this is what we will do:
Take string a. Take string b = string a.
How, find lcs of a and b, with a change such that when checking if a[i-1] == b[j-1], i should not be equal to j.
This will ensure that we don't match the same index. this will match some different index repeating character, and it will be included in 
our Longest Repeating Subsequence!
'''
a = "AABEBCDD"
b = ""
for i in range(len(a)):
    b = b + a[i]
print("String a: " + a)
print("String b: " + b)
n = len(a)

table = []
for i in range(n+1):
    table.append([])
    for j in range(n+1):
        table[i].append(-1)
        if i==0 or j==0:
            table[i][j] = 0
print(table)

# Fill the table
# Let's write normal lcs first
for i in range(1, n+1):
    for j in range(1, n+1):
        # Make the required change here
        # i != j
        if(a[i-1] == b[j-1] and i != j):
            table[i][j] = 1 + table[i-1][j-1]
        else:
            table[i][j] = max(
                table[i-1][j],
                table[i][j-1]
            )
print(table)
result = table[n][n]
print("Result is: ")
print(result)