'''
Lenght of Longest common supersequence

x : geek
y : eke
o/p: 5

This time we just need to print the length of 
supersequence.
'''
x = "geek"
y = "eke"
n = len(x)
m = len(y)

table = []
for i in range(n + 1):
    table.append([])
    for j in range(m + 1):
        table[i].append(-1)
        if i == 0 or j == 0:
            table[i][j] = 0
print(table)

for i in range(1, n+1):
    for j in range(1, m + 1):
        if x[i-1] == y [j-1]:
            table[i][j] = 1 + table[i-1][j-1]
        else:
            table[i][j] = max(
                table[i][j-1],
                table[i-1][j]
            )
print(table)
result = table[n][m]
print("Value of LCS is: ")
print(result)

result = m + n - result
print("Lenght of supersequence is: ")
print(result)