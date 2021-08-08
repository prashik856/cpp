'''
Given a string, determine the number of deletions
needed to convert it to a palindrome.

a : a r r a y
op: 1

x : geek
op: 2

Explanation?
How does it relates to LCS?
And then how does it relates to LPS?

Let's have a look at the example:
x : geek
LPS : ee
Now, deletions = len(x) - len(LPS)

How?
LPS gives us the Longest Palindromic Subsequence
How, this value will the maximum subsequence in a 
string which will be a palindrome.
Now, the number of deletions will be the remaining 
letters we need to delete from the string other than
LPS.
How, we have already seen LPS, which is already related 
to LCS.
'''

a = "geej"
n = len(a)
b = a[::-1]

table = []
for i in range(n+1):
    table.append([])
    for j in range(n+1):
        table[i].append(-1)
        if i==0 or j==0:
            table[i][j] = 0
print(table)

for i in range(1,n+1):
    for j in range(1,n+1):
        if a[i-1] == b[j-1]:
            table[i][j] = 1 + table[i-1][j-1]
        else:
            table[i][j] = max(
                table[i][j-1],
                table[i-1][j]
            )
print(table)

result = table[n][n]
print("Length of LCS: ")
print(result)
result = n - result 
print("Number of deletions required: ")
print(result)