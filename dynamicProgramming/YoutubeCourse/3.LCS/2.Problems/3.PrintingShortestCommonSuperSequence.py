'''
PRINTING SHORTEST COMMON SUPERSEQUENCE

Problem statement: 
x : geek
y : eke
o/p: gekek

We want to print the short common supersequence
such that both x and y are the subset of supersequence.

'''
# Implementing my solution here:
x = "AGGTAB"
y = "GXTXAYB"
n = len(x)
m = len(y)
table = []
for i in range(n + 1):
    table.append([])
    for j in range(m+1):
        table[i].append(-1)
        if(i==0 or j == 0):
            table[i][j] = 0
print(table)

for i in range(1, n+1):
    for j in range(1, m+1):
        if(x[i-1] == y[j-1]):
            table[i][j] = 1 + table[i-1][j-1]
        else:
            table[i][j] = max(
                table[i-1][j],
                table[i][j-1]
            )
print(table)

result = ""
i = n 
j = m
while(i > 0 or j > 0):
    if i == 0 and j > 0:
        result = result + y[j-1]
        #print(result)
        j = j - 1
        continue
    
    if j == 0 and i > 0:
        result = result + x[i-1]
        #print(result)
        i = i - 1
        continue
        
    if(x[i-1] == y[j-1]):
        result = result + x[i-1]
        #print(result)
        i = i-1
        j = j-1
    else:
        value1 = table[i-1][j]
        value2 = table[i][j-1]
        if value1 > value2:
            result = result + x[i-1]
            #print(result)
            i = i - 1
        else:
            result = result + y[j-1]
            #print(result)
            j = j - 1
print("Value of result is: ")
print(result) 
print("Value of result is: ")
result = result[::-1]
print(result)