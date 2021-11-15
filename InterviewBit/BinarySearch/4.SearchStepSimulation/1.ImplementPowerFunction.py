'''
Problem Description

Implement pow(x, n) % d.
In other words, given x, n and d,

find (xn % d)

Note that remainders on division cannot be negative. In other words, make sure the answer you return is non negative.

Input : x = 2, n = 3, d = 3
Output : 2


2^3 % 3 = 8 % 3 = 2.
'''

'''
Simple method won't work:

Efficient Solution:
Solution Approach:
https://www.geeksforgeeks.org/write-a-c-program-to-calculate-powxn/

public:
int power(int x, unsigned int y)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return power(x, y / 2) * power(x, y / 2);
    else
        return x * power(x, y / 2) * power(x, y / 2);
}
};

Algorithmic Paradigm: Divide and conquer.
Above function can be optimized to O(logn) by calculating power(x, y/2) only once and storing it. 
'''
def power(x, n, d):
    if x == 0 and n == 0:
        return 1
    
    if x == 0 and n > 0:
        return 0
    
    if n == 0:
        return 1
    
    if x == 1 and n > 0:
        return 1
    
    if x >= 1 and n == 0:
        return 1
    
    temp = power(x, int(n/2), d)
    if n % 2 == 0:
        return int(temp * temp) % d
    elif n % 2 != 0:
        return int(x * temp * temp) % d

def solve(x, n, d):
    result = power(x, n, d)
    result = int(result % d)
    return result

A = 71045970
B = 41535484
C = 64735492

result = solve(A, B, C)
print("Result: " + str(result))