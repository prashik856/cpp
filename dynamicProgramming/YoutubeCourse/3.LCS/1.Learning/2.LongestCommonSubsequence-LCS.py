'''
Longest Common Subsequence (LCS)

INPUT
X : a b c d g h
Y : a b e d f h r

OUTPUT

Flow:
1. Problem Statement
2. Recursive Discuss 
    -> Base Condition
    -> Choice Diagram
3. Code

Let's start with basic problem statement

1. Problem statement
Given two strings
x: abcdgh
y: abedfhr
O/P: abdh
Output the length of longest common subsequence
We have two inputs
We need to find longest common subsequence

What is the difference between longest common 
subsequence and longest common substring?
In longest common substring need to be continuous.
So, longest common substring of the given input is:
'ab' whose length is 2.
Subsequence can be discontinuous.

2. Recursive Approach
in recursive, we need to have 
1. base condition
2. choice diagram
3. need to make input small in the next recursion
function call.

Now, we have array: arr[n-1]
Using choice diagram, we will we making the input smaller.
we start with the last element, just like the last time.

Base condition:
What is the smallest valid input?
Think of it first
our valid input can be 
X: []  -> len(X) = n
y: [] -> len(Y) = m
We know, n>=0, m>=0 should be the valid inputs.
Since empty string can be the smallest valid input(length 0).
Now, when x==0, y==0, then LCS will be 0.
Since there are no strings at all, LCS n==0 || m ==0,
LCS will be 0
if x : abc, y : ''
Since we have nothing in common between, our LCS will be 0.
Nothing in common between them.

BC:
if(n == 0 || m == 0){
    return 0
}

Choice Diagram:
Example:
x : abcdgh
y : abedfhr

let our example be
x : abcdgh
y : abedfh
when x[n-1] == y[m-1],
that means, we have fully processed the n-1th
and m-1the element!
We can safely move back, and call the next function 
with the smaller input

1st choice
if(x[n-1] == y[n-1]):
    return 1 + lcs(x,y,n-1,m-1)
    change x -> n-1
    change y -> m-1

2nd Choice
x : abcdgh
y : abedfhr
now, h and r does not match.
Since they do not match, they are not common
So, now we have two choices
we can either reduce x, or we can either reduce y
So, we can have two function calls
with x -> n-1, y -> m
and x -> n , y -> m-1
So, 2 choices
Also, since we need to find the maximum LCS (LONGEST), 
we will  take the maximum of these two choices!
max((x -> n-1, y -> m ), (x -> n, y -> m-1))

So, we can have our function as this
else:
    return max(lcs(x,y,n-1,m), lcs(x,y,n,m-1))

So, our choice diagram will look like this:
if(x[n-1] == y[n-1]) {
    return 1 + lcs(x,y,n-1,m-1)
} else {
    return max(
        lcs(x,y,n-1,m),
        lcs(x,y,n,m-1)
    )
}

Our lcs function will look like this
int LCS(string x, string y, int n, int m){
    Base case Code
    if(n == 0 || m == 0){
        return 0;
    }

    // Choice diagram code
    if(x[n-1] == y[m-1]){
        // If our last element is equal
        return 1 + lcs(x,y,n-1,m-1);
    } else {
        // if our last element is not equal
        return max(
            // we return first smaller string
            lcs(x,y,n-1,m),
            // we return second smaller string
            lcs(x,y,n,m-1)
        )
    }
}

'''

def lcs(x,y,n,m):
    # Base condition
    if(n==0 or m == 0):
        return 0
    
    # Choice Diagram
    if(x[n-1] == y[m-1]):
        return 1 + lcs(x,y,n-1,m-1)
    else:
        return max(
            lcs(x,y,n,m-1),
            lcs(x,y,n-1,m)
        )

x = "abcdgh"
y = "abedfhr"
n = len(x)
m = len(y)
result = lcs(x,y,n,m)
print("Result Value is: ")
print(result)

'''
Sum up:

LCS
we have two strings, x and y with length n and m
Now, we first write the base condition
think of the smallest valid input.
So either n can be 0, or m can be 0.

Then we created a choice diagram.
We first check the last element, 
if they are equal, these elements are processed 
and we can move forward.

If they are not equal, we either make the first string
smaller or we either make the second string smaller
and take the maximum of them.
'''