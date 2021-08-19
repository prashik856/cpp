'''
Egg Dropping Problem Memoization:

Flow:
1. Problem Statement
2. Why Memoization is needed
3. Table dimensions
4. Code variations

2. Why Memoization?
Because we don't want to calculate values of 
subtrees multiple times.

3. Table dimensions?
What are the values in our recursion functions that
are changing?
e and f
So, table = (e+1, f+1)
This will be the dimension of our table.

4. Code Variations
'''
maxE = 100
maxF = 100
table = []
for i in range(maxE + 1): 
    table.append([])
    for j in range(maxF + 1):
        table[i].append(-1)


def solve(e: int,f: int):
    # If value already calculated, return
    if table[e][f] != -1:
        return table[e][f]
    
    # Base conditions
    if e == 1:
        table[e][f] = f
        return f
    
    if f == 0 or f == 1:
        table[e][f] = f
        return f
    
    # Coming to our loop
    minValue = 9999999999
    for k in range(1, f+1):
        # Case 1, egg breaks
        case1 = solve(e-1,k-1)
        
        # Case 2, egg does not break
        # This will change our problem to us
        # have e eggs and we have a building of 
        # floor value f - k
        case2 = solve(e, f-k)

        # max because we need worst case
        # +1 because we are trying to attempt here
        tempValue = 1 + max(case1, case2)

        minValue = min(minValue, tempValue)
    
    table[e][f] = minValue
    return minValue

e = 3
f = 8
result = solve(e,f)
print("Value of result is: ")
print(result)