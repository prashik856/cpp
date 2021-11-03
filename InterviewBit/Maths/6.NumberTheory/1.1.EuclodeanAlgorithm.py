'''
Wiki:
https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/

GCD of two numbers is the largest number that divides both of them. 
A simple way to find GCD is to factorize both numbers and multiply common prime factors.

The algorithm is based on the below facts. 
-> If we subtract a smaller number from a larger (we reduce a larger number), GCD doesn’t change. 
So if we keep subtracting repeatedly the larger of two, we end up with GCD.
-> Now instead of subtraction, if we divide the smaller number, the algorithm stops when we find remainder 0.

'''

def gcd(a,b):
    # Instead of substraction, we do remainder

    if(a > b):
        temp = a
        smaller = b
    else:
        temp = b
        smaller = a
    
    while(smaller > 0):
        # Instead of substracting, we divide
        value = int(temp % smaller)

        # the biggest number remaining will be our GCD (temp here)
        temp = int(smaller)

        # We set the currently found smaller value
        smaller = int(value)
    
    return temp

a = 10
b = 15
result = gcd(a, b)
print("GCD is: " + str(result))