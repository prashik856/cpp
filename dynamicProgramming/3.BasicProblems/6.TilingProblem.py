'''
Problem: https://www.geeksforgeeks.org/tiling-problem/

'''

memo = {}
def tiling(n):
    # base case
    # When n=0, no way
    if n in memo:
        return memo[n]
    if n == 0:
        return 0
    # when n = 1, only vertical way
    if n == 1:
        return 1
    memo[n] = tiling(n-1) + tiling(n-2)
    return memo[n]

print(tiling(4))
print(tiling(3))
print(tiling(10))
print(tiling(20))
print(tiling(50))