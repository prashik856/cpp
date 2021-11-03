'''
Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0. A and P both should be integers.

Example

Input : 4
Output : True  
as 2^2 = 4. 
'''
'''
Solution approach:
a^p = t
p log(a,a) = log(a, t)
p = log(a,t) -> log t base a
So, we just need to check for integer value of log t base a
'''
import math
def solve(a):
    if(a == 1):
        return 1
    
    upperLimit = math.ceil(math.sqrt(a))
    # print("Upper limit is: " + str(upperLimit))

    for i in range(2, upperLimit+2):
        # print("Value of A is: " + str(i))

        value = int(math.floor(math.log(a, i)))
        # print("Value of P is: " + str(value))
        # recheck
        powerValue = int(math.pow(i, value))

        if(powerValue == a and value > 1):
            # print("Value of P is: " + str(value))
            # print("Value of A is: " + str(i))
            return 1

    return 0

a = 10000000
result = solve(a)
if result:
    print("Possible")
else:
    print("Not Possible")