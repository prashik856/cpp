'''
Problem link: https://www.geeksforgeeks.org/program-nth-catalan-number/
Example problems:
Catalan numbers are a sequence of natural numbers that occurs in many interesting counting problems like following.

Count the number of expressions containing n pairs of parentheses which are correctly matched. For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).
Count the number of possible Binary Search Trees with n keys (See this)
Count the number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children) with n+1 leaves.
Given a number n, return the number of ways you can draw n chords in a circle with 2 x n points such that no 2 chords intersect.


'''
def factorial(n):
    if n == 0:
        return 1
    value = 1
    for i in range(1, n+1):
        value = value * i
    return value
    
# catalanNumber = C(2n n) * (1/(n+1)) = (2n)! / ((n+1)*n!)
def catalanNumber(n):
    fact2n = factorial(2*n)
    factn = factorial(n)
    result = int(fact2n/factn)
    result = int(result/(n+1))
    result = int(result/factn)
    return result

for i in range(50):
    print(catalanNumber(i))