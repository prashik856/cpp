'''
Sequence Pattern Matching

a: x y z
b : a b x c d y e f z
OUTPUT: YES

Check if sequence a appears in sequence b.
Basically we need to find if a is a subsequence of b.

1. Best method which takes O(len(a) + len(b)) time -> take two pointers and check if value of a appears in b.
if i is pointer to b, j is pointer to a. if a[j] appears in b[i], increment i.
if value of j == len(a) -> YES
Else NO

DP Solution
2. We need to find if LCS of a and b is equal to len(a). 
Why?
This is because whole sequence a will only appear in b iff the LCS between a and b is actually equal to a itself.
So, we can calculate LCS between a and b, and check 
if table[n][m] == len(a) -> YES
else -> NO
'''

a = "xyz"
b = "abxcdefz"
n = len(a)
m = len(b)

print("Using the First Method: ")
j = 0
for i in range(m):
    if(a[j] == b[i]):
        j += 1
    if(j == len(a)):
        break
if(j == len(a)):
    print("YES")
else:
    print("NO")


print("Using DP")
table = []
for i in range(n+1):
    table.append([])
    for j in range(m+1):
        table[i].append(-1)
        if i==0 or j==0:
            table[i][j] = 0
print(table)

for i in range(1, n+1):
    for j in range(1, m+1):
        if(a[i-1] == b[j-1]):
            table[i][j] = 1 + table[i-1][j-1]
        else :
            table[i][j] = max(
                table[i-1][j],
                table[i][j-1]
            )
print(table)
result = table[n][m]
if(result == len(a)):
    print("YES")
else:
    print("NO")
