'''
Print Longest LCS between 2 strings

Flow:
1. Problem Statement
2. Identify
3. Will go deeper into how lcs works
4. will write the code

Problem:
a : acbcf
b : abcdaf
O/P : acf
'''
# My code
x = "acbcf"
y = "abcdaf"
n = len(x)
m = len(y)

# What will be our initialization?
# if n==0 or m==0, lcs value is '' -> empty
table = []
for i in range(n+1):
    table.append([])
    for j in range(m+1):
        table[i].append("")
print(table)

for i in range(1, n+1):
    for j in range(1, m+1):
        if(x[i-1] == y[j-1]):
            table[i][j] =  str(table[i-1][j-1]) + str(x[i-1])
        else:
            str1 = table[i-1][j]
            str2 = table[i][j-1]
            if(len(str1) > len(str2)):
                table[i][j] = table[i-1][j]
            else:
                table[i][j] = table[i][j-1]
print(table)
result = table[n][m]
print("Required LCS is: ")
print(result)

# What if we want to reduce the space complexity?
# We need to use back tracking!
# first fill the table normally, and then use backtracking
# How do we do that?
print("Result using back tracking")
table = []
for i in range(n+1):
    table.append([])
    for j in range(m+1):
        table[i].append(-1)
        if i==0 or j==0:
            table[i][j]=0
print(table)
for i in range(1,n+1):
    for j in range(1,m+1):
        if(x[i-1] == y[j-1]):
            table[i][j] = 1 + table[i-1][j-1]
        else:
            table[i][j] = max(
                table[i-1][j],
                table[i][j-1]
            )
print(table)
# We should use backtracking to get the lcs that we
# need
# Now to print the subsequence, we back track from
# i=n and j=m
i,j = n,m
result = ""
while i>0 and j>0:
    if(x[i-1] == y[j-1]):
        result = x[i-1] + result
        i = i - 1
        j = j - 1
    else:
        value1 = table[i-1][j]
        value2 = table[i][j-1]
        if(value1 > value2):
            i = i - 1
        else:
            j = j - 1
print("Value of result is: ")
print(result)
# print("Value of LCS is: ")
# # this operator will give us the reversed object
# result = result[::-1]
# print(result)
