'''
Minimum number of Insertions and Deletions To Convert String A To String B.

a : heap
b : pea
O/P : 
Insertions: 1
Deletions : 2

How is this related to LCS?
Now, we want to convert the string a to string b.

Let's look at insertions:
we don't have a 'p' in str(a).
So, what do we do, we need to insert it.
So, insertion = 1.
What about deletions, 
since this is subsequence, the order is important.
We since h is not in str(b) we need to delete it.
what about p? It is in str(b) but it is after 'ea'.
So that means, we need to delete it too.
Deletions = 2.

What about the string 'ea'?
This is our LCS.
That means, we can relate this problem to lcs.

we have two strings, we need to find the longest 
common subsequence.

What will be the number of insertions?
Deletions = m - len(LCS)
Insertions = n - len(LCS)

'''
a = "heap"
b = "pea"
n = len(a)
m = len(b)

table = []
for i in range(n+1):
    table.append([])
    for j in range(m+1):
        table[i].append(-1)
        if(i==0 or j==0):
            table[i][j] = 0
print(table)

for i in range(1, n+1):
    for j in range(1, m + 1):
        if(a[i-1] == b[j-1]):
            table[i][j] = 1 + table[i-1][j-1]
        else:
            table[i][j] = max(
                table[i][j-1],
                table[i-1][j]
            )
print(table)
result = table[n][m]

print("Length of LCS is: ")
print(result)

insertions = m - result
deletions = n - result
print("Insertions: " + str(insertions))
print("Deletions: " + str(deletions))