'''
Problem Description

Given an integer A you need to find the Ath fibonacci number modulo 109 + 7.

The first fibonacci number F1 = 1

The first fibonacci number F2 = 1

The nth fibonacci number Fn = Fn-1 + Fn-2 (n > 2)



Problem Constraints
1 <= A <= 109.



Input Format
First argument is an integer A.



Output Format
Return a single integer denoting Ath fibonacci number modulo 109 + 7.



Example Input
Input 1:

 A = 4
Input 2:

 A = 3


Example Output
Output 1:

 3
Output 2:

 2


Example Explanation
Explanation 1:

 F3 = F2 + F1 = 1 + 1 = 2
 F4 = F3 + F2 = 2 + 1 = 3
Explanation 2:

 F3 = F2 + F1 = 1 + 1 = 2
'''
'''
Solution Approach:
https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/

Method 1:
A simple method that is a direct recursive implementation mathematical recurrence relation given above.
time: exponential

Method 2:
We can avoid the repeated work done in method 1 by storing the Fibonacci numbers calculated so far. 
time: O(n)

Method 3:
We can optimize the space used in method 2 by storing the previous two numbers 
only because that is all we need to get the next Fibonacci number in series. 
time: O(n)

Method 4:
This another O(n) which relies on the fact that if we n times multiply the matrix M = {{1,1},{1,0}} to itself 
(in other words calculate power(M, n)), 
then we get the (n+1)th Fibonacci number as the element at row and column (0, 0) in the resultant matrix.
We need to write a matrix multiplication code for this.
The code to multiply two matrix, we need to hardcode write that.

Method 5:
The method 4 can be optimized to work in O(Logn) time complexity. 
We can do recursive multiplication to get power(M, n) in the previous method (Similar to the optimization done in this post)

Method 6:
Below is one more interesting recurrence formula that can be used to find n’th Fibonacci Number in O(Log n) time.  
If n is even then k = n/2:
F(n) = [2*F(k-1) + F(k)]*F(k)

If n is odd then k = (n + 1)/2
F(n) = F(k)*F(k) + F(k-1)*F(k-1)
How does this formula work? 
The formula can be derived from above matrix equation. 
We solve the 2 matrix:
we know, we can use matrix: M = {{1,1}, {1, 0}}, and multiply it to the power n, to get the nth fibonacci number
M^n = {{Fn+1, Fn}, 
     {Fn, Fn-1}}
And also, from this , we can see that F[0] = 1, F[1] = 1

Taking determinant on both sides, we get 

(-1)n = Fn+1Fn-1 - Fn2 
 
Moreover, since AnAm = An+m for any square matrix A, 
the following identities can be derived (they are obtained 
form two different coefficients of the matrix product)

FmFn + Fm-1Fn-1 = Fm+n-1         ---------------------------(1)

By putting n = n+1 in equation(1),
FmFn+1 + Fm-1Fn = Fm+n             --------------------------(2)

Putting m = n in equation(1).
F2n-1 = Fn2 + Fn-12
Putting m = n in equation(2)

F2n = (Fn-1 + Fn+1)Fn = (2Fn-1 + Fn)Fn (Source: Wiki)   --------
( By putting Fn+1 = Fn + Fn-1 )
To get the formula to be proved, we simply need to do the following 
If n is even, we can put k = n/2 
If n is odd, we can put k = (n+1)/2

If n is even then k = n/2:
F(n) = [2*F(k-1) + F(k)]*F(k)

If n is odd then k = (n + 1)/2
F(n) = F(k)*F(k) + F(k-1)*F(k-1)

Wiki: 
https://en.wikipedia.org/wiki/Fibonacci_number#Matrix_form

Method 7:
In this method we directly implement the formula for nth term in the fibonacci series. 
Fn = {[(√5 + 1)/2] ^ n} / √5 

Reference: http://www.maths.surrey.ac.uk/hosted-sites/R.Knott/Fibonacci/fibFormula.html 
'''

allFibos = {}
def getFibo(n):
    # print("Given n is: " + str(n))
    
    MODULOVALUE = 1000000007
    result = 0
    if(n <= 0):
        return 0
    
    if(n == 1):
        return 1
    
    if(n == 2):
        return 1

    if n in allFibos:
        return allFibos[n]
    
    if(n % 2 == 0):
        k = int(n/2)
        # print("Even")
        # print("Value of k is: " + str(k))
        result = ((2 * getFibo(k-1) + getFibo(k)) * getFibo(k))
    else:
        # print("Odd")
        k = int((n+1)/2)
        # print("Value of k is: " + str(k))
        result = getFibo(k) * getFibo(k) + getFibo(k-1) * getFibo(k-1)

    # print()
    result = int(result % MODULOVALUE)
    allFibos[n] = result
    return result

a = 1000000000
result = getFibo(a)
print("Result: " + str(result))