'''
You are given two positive numbers A and B. You need to find the maximum valued integer X such that:

X divides A i.e. A % X = 0
X and B are co-prime i.e. gcd(X, B) = 1
For example,

A = 30
B = 12
We return
X = 5
'''

'''
Solution Approach:
https://www.geeksforgeeks.org/largest-number-divides-x-co-prime-y/

Best Approach:
Here, first we will remove the common factors of x and y from x by finding the greatest common divisor (gcd) of x and y 
and dividing x with that gcd. 

Mathematically: 
x = x / gcd(x, y) 

Now, we repeat STEP1 till we get gcd(x, y) = 1. 
At last, we return a = x 
 
'''
def gcd(a, b):
    if a > b:
        greater = a
        smaller = b
    else:
        greater = b
        smaller = a
    
    while(smaller > 0):
        temp = smaller
        smaller = int(greater % smaller)
        greater = temp

    return greater

def solve(A, B):
    result = 0

    # Check if a is the answer:
    while(True):
        gcdAB = gcd(A,B)
        if(gcdAB == 1):
            result = A
            break
        A = int(A/gcdAB)
    return result

A = 30
B = 12
result = solve(A, B)
print("Result is: " + str(result))