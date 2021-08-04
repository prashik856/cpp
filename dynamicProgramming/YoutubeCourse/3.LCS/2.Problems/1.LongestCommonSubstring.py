'''
LONGEST COMMON SUBSTRING

Problem:
Print the length of longest common substring
Substring is always the continuous array.
e.g. abcd
has these substrings:
a b c d ab bc cd abc bcd abcd
So they are conitnuous segment of an array

Example:
x : acdghrb
y: abedfhr
O/P: 2 (hr here.)

How to identify that this is LCS problem?
Looking at the question, we see that it requires
a longest common substring.
This means we need to make sure of continuity.
If there is no continuity, the problem changes to
Longest Common subsequence.
Thus this problem is a variation of longest 
common subsequence

Initialization?
It will be the same.
Why? because if n==0, m!=0 -> There is no common substring
between two string. So 0.
Same goes if m==0 and n!=0.
so Initialization:
table[0][:] = 0
table[:][0] = 0

Code Variation:
Coming to our choice diagram code variation,
we need to look at the continuity
that means, we need continuous segment of
the array.
if given array values are not equal, we need to
set the value to 0.
Code will be as follows:
if(x[i-1] == y[j-1]):
    table[i][j] = 1 + table[i-1][j-1]
else:
    table[i][j] = 0
Then:
# We need to find the max value in the table
# Why is this so?
# Because substring can exist anywhere in the array
'''

x = "acdghrb"
y = "abedfhr"
n = len(x)
m = len(y)

table = []
for i in range(n+1):
    table.append([])
    for j in range(m+1):
        table[i].append(-1)
        if(i==0 or j==0):
            table[i][j] = 0

print(table)
result = -1
for i in range(1,n+1):
    for j in range(1,m+1):
        if(x[i-1] == y[j-1]):
            table[i][j] = 1 + table[i-1][j-1]
        else:
            table[i][j] = 0
        result = max(
            result,
            table[i][j]
        )
print(table)

print("Result of the value is: ")
print(result)