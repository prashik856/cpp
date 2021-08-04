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

