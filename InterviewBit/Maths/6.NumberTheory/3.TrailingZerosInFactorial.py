'''
Problem Description

Given an integer A, return the number of trailing zeroes in A!.

Note: Your solution should be in logarithmic time complexity.



**Problem Constraints**
1 <= A <= 10000



**Input Format**
First and only argumment is integer A.



**Output Format**
Return an integer, the answer to the problem.



**Example Input**
Input 1:

 A = 4
Input 2:

 A = 5


**Example Output**
Output 1:

 0
Output 2:

 1


**Example Explanation**
Explanation 1:

 4! = 24
Explanation 2:

 5! = 120
'''
'''
Solution Approach:
https://www.geeksforgeeks.org/count-trailing-zeroes-factorial-number/
Method 1:
A simple method is to first calculate factorial of n, 
then count trailing 0s in the result 
(We can count trailing 0s by repeatedly dividing the factorial by 10 till the remainder is 0).

Method 2: 
The above method can cause overflow for slightly bigger numbers as the factorial of a number is a big number 
(See factorial of 20 given in above examples). 
The idea is to consider prime factors of a factorial n. 
A trailing zero is always produced by prime factors 2 and 5. 
If we can count the number of 5s and 2s, our task is done. 
Consider the following examples.
n = 5: There is one 5 and 3 2s in prime factors of 5! (2 * 2 * 2 * 3 * 5). So a count of trailing 0s is 1.
n = 11: There are two 5s and eight 2s in prime factors of 11! (2 8 * 34 * 52 * 7). So the count of trailing 0s is 2.
 
We can easily observe that the number of 2s in prime factors is always more than or equal to the number of 5s. 
So if we count 5s in prime factors, we are done. 
How to count the total number of 5s in prime factors of n!? 
A simple way is to calculate floor(n/5). 
For example, 7! has one 5, 10! has two 5s. 
It is not done yet, there is one more thing to consider. Numbers like 25, 125, etc have more than one 5. 
For example, if we consider 28! we get one extra 5 and the number of 0s becomes 6. 
Handling this is simple, first, divide n by 5 and remove all single 5s, 
then divide by 25 to remove extra 5s, and so on. 

Following is the summarized formula for counting trailing 0s.
Trailing 0s in n! = Count of 5s in prime factors of n!
                  = floor(n/5) + floor(n/25) + floor(n/125) + ....
'''
import random

def solve(a):
    count = 0

    multipleOfFive = 5

    while multipleOfFive <= a:
        quotient = int(a/multipleOfFive)
        # print("Quotient: " + str(quotient))
        count += quotient
        multipleOfFive *= 5
    
    return count

Limit = 10000
a = random.randint(1, Limit)
print("Input: " + str(a))

result = solve(a)
print("Result: " + str(result))