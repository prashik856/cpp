'''
Scramble String

Flow:
1. Problem Statement
2. How to Identify
3. How to approach
4. How To breakdown
5. Base Condition
6. Code Variation

a : "great"
b : "rgeat"
O/P: True

Kinda Complex Problem.

1. Problem Statement
We have two input strings, 'a' and 'b'.
We want to return True or False.
Check if 'a' and 'b' are Scramble String or not?

What is a Scramble String?
We can somehow create a binary tree of this given string.
And any child cannot be empty.

We need to breakdown such that no child can be empty
The breakdown of this string can happen any way.
We just need to make sure that the child is never empty.

So, any non-leaf node, we can do 0 or more swapping.
So, great and rgeat are Scrambled Strings.

Now, understand we have 0 or more swapping.
great and rgate are also scrambled String (2 swappings)

great and great -> True.

How can we swap?
Now, we first swap great such as:
g reat or
gr eat or
gre at or 
grea t 
Now, there are these many ways we can swap these guys!
Now, choice is
for k=1; k<n-1; k++
These are the choices that we have for k
Since we will have two choices
(i,k) and (k+1, j)
And i:k and k+1:j, the length of these stirngs needs to be
greater than or equal to 1.
This is how we have identified that this is an MCM Problem.
Even in MCM, we don't know where to break the given array 
or string.
So we try to break the array/string at some places, depending
on the value of k, and we try to solve that problem recursively.

Thus, we need to break the string at multiple places 
recursively. Thus MCM!

How to approach?
We have two cases for any k

Now, see
great 
for k = 2, we have gr and eat
Now, the two cases are we can either swap or
we don't swap
Two choices for gr is->
either swap or don't swap.
This goes for both gr and eat.


'''
def solve(a,b):
    # What will be the base conditions

    # Return False directly if lengths are not equal!
    if(len(a) != len(b)):
        return False

    # One we can say is if the length of given strings
    # is 1. They need to be equal! 
    if len(a) <= 1:
        if(a[0] == b[0]):
            return True
        else:
            return False
    
    # If a and b are equal, we need to return true!
    if a == b:
        return True


    # Now, we need to make two pieces of a
    # So, these two pieces can either swap or not swap
    # If they are swapped, we need to check the first half of a with second half of b, and second half of a with first half of b.
    # If they are not swapped, we need to check the first half of a with fisrt half of b, and second half of a with second half of b.
    for i in range(1,len(a)):
        # Why till len(a) - 1 ?
        # Because first group will be (0,i) and second will be (i+1,len(a))

        # Case 1
        # We swap here
        # first half of a should be equal to second half of b AND second half of a should be equal to first half of b
        # What will be the first half: a[0:i], second half a[i+1:len(a)]
        afront = a[0:i]
        aback = a[i:len(a)]
        bfront = b[0:len(a)-i]
        bback = b[len(a)-i:len(a)]
        case1 = solve(afront, bback) and solve(aback,bfront)

        # Case 2
        # Here, we are not swapping at all
        # So we need to compare the first half of a with first half of b
        # compare second half of a with second half of b
        afront = a[0:i]
        aback = a[i:len(a)]
        bfront = b[0:i]
        bback = b[i:len(b)]
        case2 = solve(afront, bfront) and solve(aback, bback)

        # If we get our string a is equal to b 
        # Either by swapping or not swapping, we need to return True
        tempResult = case1 or case2
        if(tempResult):
            return True
            
    return False

a = "great"
b = "rgeat"
n = len(a)
m = len(b)
result = solve(a,b)
print("Value of result is: ")
print(result)