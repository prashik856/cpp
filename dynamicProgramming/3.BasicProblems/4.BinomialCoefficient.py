'''
Problem: https://www.geeksforgeeks.org/binomial-coefficient-dp-9/
Intuition: C(n k) = n! / (k! * (n-k)!)

Time: O(n)
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

def binomialCoefficient(n, k):
    fact = factorial(n)
    numerator = fact[n]
    denominator = fact[n-k]*fact[k]
    coefficient = int(numerator/denominator)
    return coefficient

print(binomialCoefficient(4,3))
print(binomialCoefficient(4,1))
print(binomialCoefficient(2,2))
print(binomialCoefficient(3,2))