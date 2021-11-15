'''
Given two integers x and n, write a function to compute xn. We may assume that x and n are small and overflow doesn’t happen.
'''
def power(x, y):
    if x == 0 and y == 0:
        return 1
    
    if x == 0 and y > 0:
        return 0
    
    if x == 1 and y >= 0:
        return 1
    
    if y == 0:
        return 1

    # we can use this to calculate power!
    if y % 2 == 0:
        return power(x, int(y/2)) * power(x, int(y/2))
    if y % 2 != 0:
        return x * power(x, int(y/2)) * power(x, int(y/2))

def solve(x, y):
    return power(x, y)
x = 2
y = 9

result = solve(x, y)
print(result)