'''
https://www.geeksforgeeks.org/permutation-coefficient/
Intuition: P(n k) = n! / (n-k)!
'''

def factorial(n):
    fact = []
    fact.append(1)
    if n == 0:
        return fact
    value = 1
    for i in range(1, n + 1):
        value = value * i
        fact.append(value)
    return fact

def permutationCoefficient(n,k):
    fact = factorial(n)
    numerator = fact[n]
    denominator = fact[n-k]
    coefficient = int(numerator/denominator)
    return coefficient

print(permutationCoefficient(10,2))
print(permutationCoefficient(10,3))
print(permutationCoefficient(10,0))
print(permutationCoefficient(10,1))