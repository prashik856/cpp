'''
LCS MEmoized Bottom Up DP

Flow:
1. Why do we need it?
2. How to know the size of the matrix?
3. How does it works?
4. Code variation.

We already know our LCS code
int lcs(string x, string y, int n, int m) {
    if (n == 0 || m == 0){
        return 1 + lcs(x, y, n-1, m-1)
    } 
    else {
        return max(
            lcs(x,y,n-1,m),
            lcs(x,y,n,m-1)
        )
    }
}

1. Why do we need DP in it?
In DP, we always have a look at subproblems
If the recursion function is only calling 
it's own but only one, then we don't need DP.

Subproblems only comes into case when a fucntion is 
calling two recursive functions.
In this case, we might get a subproblem which is already 
stored some where in our tree

Recursive function -> pure recursive calls
in DP, we store the results to avoid multiple calculations
of the same sub problems.

lcs problem example
x: axyt
y: ayzx

What will be the size of the table?
look at the variables which are changing in the 
recusion table?
they are n and m.
So, the size of our table will be table[n+1][m+1]
we want the last value to be t[n+1][m+1],
that's why we need the size of table as (n+1)x(m+1)

We initialize the value of the table with -1.
Since we want to check if this subproblem is already 
solved or not, we wanted to initialize the matrix 
to a value which we can check at the end.   
'''
x = "acdghrb"
y = "abedfhr"
n = len(x)
m = len(y)
table = []
for i in range(n + 1):
    table.append([])
    for j in range(m + 1):
        table[i].append(-1)

def lcs(x,y,n,m):
    # precheck
    if(table[n][m] != -1):
        return table[n][m]

    # Base condition
    if(n==0 or m == 0):
        return 0
    
    # Choice Diagram
    if(x[n-1] == y[m-1]):
        table[n][m] = 1 + lcs(x,y,n-1,m-1)
        return table[n][m]
    else:
        table[n][m] = max(
            lcs(x,y,n,m-1),
            lcs(x,y,n-1,m)
        )
        return table[n][m]


result = lcs(x,y,n,m)
print(table)
print("Result Value is: ")
print(result)

'''
Sum up:
When a recursive funtion calls two functions 
at the same time, there is a chance of overlapping
subproblems

So, we store values to make it memoized version.
'''