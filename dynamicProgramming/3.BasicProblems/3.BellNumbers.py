'''
Problem link: https://www.geeksforgeeks.org/bell-numbers-number-of-ways-to-partition-a-set/
Intuition: https://en.wikipedia.org/wiki/Bell_triangle
Given a set of n elements, find number of ways of partitioning it. 
'''

def bellNumbers(n):
    # print("Value of n: " + str(n))
    if n == 0:
        return 1
    if n == 1:
        return 1
    table = []
    for i in range(n):
        table.append([])
        for j in range(n):
            table[i].append(0)
    
    table[0][0] = 1
    for i in range(1, n):
        table[i][0] = table[i-1][i-1]
        for k in range(1, n):
            table[i][k] = table[i][k-1] + table[i-1][k-1]
    return table[n-1][n-1]

for i in range(50):
    print(bellNumbers(i))