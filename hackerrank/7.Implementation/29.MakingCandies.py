

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'minimumPasses' function below.
#
# The function is expected to return a LONG_INTEGER.
# The function accepts following parameters:
#  1. LONG_INTEGER m
#  2. LONG_INTEGER w
#  3. LONG_INTEGER p
#  4. LONG_INTEGER n
#

# how to solve this question: learn it here
# https://www.youtube.com/watch?v=ayHZZEb2gVQ&ab_channel=KuldipGhotane
# Problem is available here:
# https://www.hackerrank.com/challenges/making-candies/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=search
def minimumPasses(m, w, p, n):
    # Write your code here
    passValue = 0
    
    # result is the upper bound of currently
    # maxDays = n / m*w this when we don't purchase anything
    # This is the max number of passes right now
    result = math.ceil(n / (m*w))
    # print("Maximum Upper bound: " + str(result))
    
    # current resuorces in hand
    resources = 0
    # print()
    
    while(passValue < result):
        # We do some calculations here
        # print("Current values of m and w are: " + str(m) + ":" + str(w))
        # print("Cost to purchase: " + str(p))
        
        # What is the straight pass value
        # Number of days we can skip
        straightPass = math.ceil((p-resources)/(m*w))
        # print("Straight pass: " + str(straightPass))
        # get resources after doing a starting pass
        resources += straightPass * m * w 
        # print("Initial Resources: " + str(resources))
        # increase the current pass value
        passValue += straightPass
        # done with calculations
        # print("Pass Value after straight Pass: " + str(passValue))
        
        # Check if our current purchasing power is greater than difference between m and w
        purchasingPower = math.floor(resources/p)
        # print("Purchasing Power: " + str(purchasingPower))
        # Update resources
        resources -= purchasingPower * p
        # print("Resources left after purchase: " + str(resources))
        # we can purchasing Power amount of m or w
        # We can equate m and w only when purchasingPower is greater than their absolute difference
        # print("Absolute difference: " + str(abs(m-w)))
        if purchasingPower >= abs(m-w):
            # print("Purchasing Power is greater than absolute difference")
            # Equate m and w
            purchasingPower -= abs(m-w)
            if m > w:
                # print("Increasing w")
                w += abs(m-w)
            else :
                # print("Increasing m")
                m += abs(m-w)
            # print("Equating m and w: " + str(m) + ":" + str(w))
            # print("Purchasing Power after equating: " + str(purchasingPower))
            # Now we have equated m and w
            
            # Do mass hiring now
            # giving half to m
            # print("Bulk hiring m and w")
            m += math.floor(purchasingPower/2)
            # Giving the remaining to w
            w += purchasingPower - math.floor(purchasingPower/2)
            # print("Updated m and w after bulk hiring: " + str(m) + ":" + str(w))
            # Now we have updated m and w
            # We have made sure to spend all the purchasing power
            # update purchasing power
            purchasingPower -= purchasingPower
            # print("Purchasing Power after bulk hiring m and w is: " + str(purchasingPower))
        else:
            # If our purchasing Power is less than abs(m-w)
            # We check which one is smaller and add purchasing power to that value
            # print("Purchasing Power is smaller than absolute difference")
            if m > w:
                # print("Increasing w")
                w += purchasingPower
            else:
                # print("Increasing m")
                m += purchasingPower
            # We have made sure to spend all the purchasing power
            purchasingPower -= purchasingPower
            # print("Purchasing Power after updating m and w is: " + str(purchasingPower))
            # print("Updated m and w: " + str(m) + ":" + str(w))
        # Get our remaining resources
        resources -= purchasingPower * p
        # print("Resources left: " + str(resources))
        
        # Now that we have our remaining resources, check the min pass now
        # Check remaining candies required
        candyRemaining = n - resources
        # print("Candy left: " + str(candyRemaining))
        # Check minimum number of days with updated m and w to make 
        minPass = math.ceil(candyRemaining/(m*w))
        # print("Minimum Passes required now: " + str(minPass))
        if(result > passValue + minPass):
            result = passValue + minPass
        # print("Updated result: " + str(result))
        # Upper while loop ends
        # print()
    return result

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    m = int(first_multiple_input[0])

    w = int(first_multiple_input[1])

    p = int(first_multiple_input[2])

    n = int(first_multiple_input[3])

    result = minimumPasses(m, w, p, n)

    fptr.write(str(result) + '\n')

    fptr.close()
