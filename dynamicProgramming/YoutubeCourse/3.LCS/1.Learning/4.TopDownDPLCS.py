'''
TOP Down DP - LCS

Flow: 
1. Problem Statement: 
2. Why do we need it?
3. Code Variations

'''

x = "acdghrb"
y = "abedfhr"
n = len(x)
m = len(y)
table = []
for i in range(n + 1):
    table.append([])
    for j in range(m + 1):
        table[i].append(-1)
        if(i==0 or j==0): 
            table[i][j] = 0

print(table)
for i in range(1, n+1):
    for j in range(1, m+1):
        # if they are equal
        if(x[i-1] == y[j-1]):
            table[i][j] = 1 + table[i-1][j-1]
        else:
            table[i][j] = max(
                table[i][j-1],
                table[i-1][j]
            )
print(table)
result = table[n][m]
print("Result is: ")
print(result)
'''
In tabulization:
Remember our recursive solution:
def lcs(x,y,n,m):
    # base condition
    if(n==0 or m==0):
        return 0

    # choice diagram
    if(x[n-1] == y[m-1]):
        return 1 + lcs(x,y,n-1,m-1)
    else:
        return max(
            lcs(x,y,n,m-1),
            lcs(x,y,n-1,m)
        )

Now, for our table initialization, we look at our 
base condition
if(n==0 or m==0):
    return 0
this changes to
if(i==0 or j==0){
    table[i][j] = 0
}

Looking at choice diagram
if(x[n-1] == y[m-1]):
    return 1 + lcs(x,y,n-1,m-1)
else:
    return max(
        lcs(x,y,n,m-1),
        lcs(x,y,n-1,m)
    )

This changes to:
if(x[n-1] == y[m-1]):
    table[i][j] = 1 + table[i-1][j-1]
else:
    table[i][j] = max(
        table[i][j-1],
        table[i-1][j]
    )
Thats it.
'''