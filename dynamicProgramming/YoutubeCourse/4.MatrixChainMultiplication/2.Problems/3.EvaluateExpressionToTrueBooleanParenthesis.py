'''
Evaluate Expression to True
Or Boolean Parenthesis

string : T or F and T -> (T|F&T)
O/P : 2  
There are two ways in which the statement will evaualte to True. (T|F)&T and (T|(F&T))
Need to return Count!
We can have 3 different symbols : | (or), & (and) and ^(XOR)
So, the string will have T,F and set of boolean operations (|,&,^)

Need to caluculate how we can apply brackets such that it's value will evaulate to True.


Flow:
1. Problem Statement
2. Format (Our 4 steps)

'''


'''
My Solution:

values of i and j?
i=0, and j=len(s)-1 ? -> It will work!

We need to store two values,
one is evaluated value, and second the count.

Okay.
Coming to base condition.
Can i be equal to j? -> NOPE
We cannot have a single element. 
so, BC is i>=j -> return 0

Coming to Choice Diagram?
for k in range(i,j,2):
    Why 2, because we have a boolean expression in between i and j
    solve(s,i,k) -> if cost returned is zero -> This expression evaluates to false
    solve(s,k+2,j) -> Same goes for this guy -> If value > 0, evaluation to True

T|F&T -> T (1)
      -> F & T (0)
Due to Or, This expression will evaulate to True
temp = 1
ans = ans + 1

F & T -> F (0) 
      -> T (1)
F(0)


'''
'''
This code Does not work.
My thinking was wrong.
N = 1000
table = []
for i in range(N+1):
    table.append([])
    for j in range(N+1):
        table[i].append(-1)

def solve(s,i,j):
    if(table[i][j] != -1):
        return table[i][j]
    
    if(i>j):
        table[i][j] = 0
        return 0

    if(i==j):
        if s[i] == "T":
            table[i][j] = 1
            return 1
        else:
            table[i][j] = 0
            return 0
    
    ans = 0
    for k in range(i,j,2):
        c1 = solve(s,i,k)
        c2 = solve(s,k+2,j)
        # print("String" + s[i:j+1])
        # print("C1: " + str(c1))
        # print("C2: " + str(c2))

        if(c1 == 0):
            b1 = False
        else:
            b1 = True
        
        if(c2 == 0):
            b2 = False
        else:
            b2 = True
        # print("B1 and B2: " + str(b1) + " | " + str(b2))

        b3 = False
        # print("Boolean Expression: " + s[k+1])
        if s[k+1] == "|":
            b3 = b1 or b2

        if s[k+1] == "^":
            b3 = b1 != b2

        if s[k+1] == "&":
            b3 = b1 and b2
        
        # print("B3: " + str(b3))
        if b3:
            c3 = 1
        else:
            c3 = 0

        ans += c3
    # print(ans)
    table[i][j] = ans
    return ans

s = "T|F&T^F"
n = len(s)
result = solve(s,0,n-1)
# print(table)
print("Value of result is : ")
print(result)
'''

'''
Video Code:

s : T|F&T^F
O/P: 3 ways

We will have k = k + 2? Becuase of the operator.

Coming to our 4 steps:
1. Find value of i and j:
i=0 and j=len(s) - 1

2. Base Condition:
What will be our base condition?
if(i>j) return False -> Empty String
if(i==j) {
    if isTrue:
        return s[i] == "T"
    else:
        return s[i] == "F"
}
This will be our base condition.


3. Value of k loop
We want to express the operator at k
So, our two groups will be (i,k-1) and (k+1,j)
for k=i+1; k<=j; k+=2 {
    // We actually need to calculate 4 variables
    // leftTrue, leftFalse, rightTrue, and rightFalse
    int leftTrue = solve(s,i,k-1,True)
    int leftFalse = solve(s,i,k-1,False)
    int rightTrue = solve(s,k+1,j,True)
    int rightFalse = solve(s,k+1,j,False)
}
This was the problem with my thinking!
I was not thinking of False statement.
Because to evaluate a boolean statement, we need both true and false answers to get the total number of ways.
Counting only one will never be enough.


4. Find Answer by applying some function to TempAnswer
Total for loop:
ans = 0
for k=i+1; k<=j; k+=2{
    int leftTrue = solve(s,i,k-1,True)
    int leftFalse = solve(s,i,k-1,True)
    int rightTrue = solve(s,k+1,j,True)
    int rightFalse = solve(s,k+1,j,True)

    if(s[k] == '&') {
        if isTrue:
            // Evaulate to true
            // && will only evaluate to true when both of the expressions will 
            // evaluate to true
            ans += leftTrue * rightTrue
        else:
            // Evaluate to false
            // when any of them is false
            ans += leftFalse * rightFalse + leftFalse * rightTrue + leftTrue * rightFalse
    }

    if(s[k] == '|') {
        if isTrue:
            // True
            // Any one of them is true
            ans += leftTrue * rightTrue + leftTrue * rightFalse + leftFalse * rightTrue
        
        else:
            // False
            // Both of them false
            ans += leftFalse * rightFalse
    }

    if(s[k] == '^') {
        if isTrue:
            // True
            // Both are different
            ans += leftFalse * rightTrue + leftTrue * rightFalse
        else:
            // False
            // Both same
            ans += leftFalse * rightFalse + leftTrue * rightTrue
    }
}
return ans
'''

def solve(s, i, j, isTrue):
    # Base Condition 1
    if(i>j):
        return 0
    
    if(i==j):
        if isTrue:
            if s[i] == "T":
                return 1
            else:
                return 0
        else:
            if s[i] == "F":
                return 1
            else:
                return 0
    
    ans = 0
    for k in range(i+1,j,2):
        leftTrue = solve(s,i,k-1,True)
        leftFalse = solve(s,i,k-1,False)
        rightTrue = solve(s,k+1,j,True)
        rightFalse = solve(s,k+1,j,False)

        if(s[k] == '&'):
            if isTrue:
                # // Evaulate to true
                # // && will only evaluate to true when both of the expressions will 
                # // evaluate to true
                ans += leftTrue * rightTrue
            else:
                # // Evaluate to false
                # // when any of them is false
                ans += leftFalse * rightFalse + leftFalse * rightTrue + leftTrue * rightFalse

        if(s[k] == '|'):
            if isTrue:
                # // True
                # // Any one of them is true
                ans += leftTrue * rightTrue + leftTrue * rightFalse + leftFalse * rightTrue
            
            else:
                # // False
                # // Both of them false
                ans += leftFalse * rightFalse

        if(s[k] == '^'):
            if isTrue:
                # // True
                # // Both are different
                ans += leftFalse * rightTrue + leftTrue * rightFalse
            else:
                # // False
                # // Both same
                ans += leftFalse * rightFalse + leftTrue * rightTrue
    return ans


s = "T|F&T|F|T"
n = len(s)
result = solve(s, 0, n-1, True)
print("Value of result is: ")
print(result)