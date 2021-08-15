'''
Palindromic Partitioning Optimized Memoization:

We have already seen 
-> Recursive Solution
-> Memoization Solution

What do I think is the issue with Memoizatoin Solution?
Here, we are storing a table value as a whole matrix -> this way, even the values which are never being used are stored
in the matrix!
We can optimize this by using a dictionary rather than using a matrix.

Also, inside the for loop, when we are calling the two functions,
How can we further Optimize it?
Well, it is very much possible that the recursive functions that we are calling might already be solved!
This way we can save up our Stack Memory
Now, what we mean is -> We can first check if the recursive function is already solved or not.
If the function solve(s,i,k) is already solved, there is no need to call this function
Same goes for solve(s,k+1,j), if it's value is already available in the table, no need to call this function in our recursive call.

'''
n_max = 1000
table = []
for i in range(n_max + 1):
    table.append([])
    for j in range(n_max + 1):
        table[i].append(-1)


def checkPalindrome(s,start,end):
    while(start <= end):
        if s[start] == s[end]:
            start += 1
            end += 1
        else:
            return False
    return True
        

def solve(s,i,j):
    if(table[i][j]!= -1):
        return table[i][j]
    
    if(i>=j):
        table[i][j] = 0
        return 0
    
    if checkPalindrome(s,i,j):
        table[i][j] = 0
        return 0
    
    ans = 9999999999
    for k in range(i,j,1):
        if(table[i][k] != -1):
            c1 = table[i][k]
        else:
            c1 = solve(s,i,k)
        
        if(table[k+1][j] != -1):
            c2 = table[k+1][j]
        else:
            c2 = solve(s,k+1,j)
        c3 = 1
        temp = c1 + c3 + c3
        ans = min(ans, temp)

    table[i][j] = ans 
    return ans

a = "nitik"
n = len(a)
result = solve(a,0,n-1)
print("Reuslt value is: ")
print(result)