'''
Palindrome Partitioning - Memoized (Recursion + Memoization):

Flow:
1. Problem Statement
2. Follow Format Rule
3. Further Optimization

Input: 
s : nitin
o/p : 3
We need to divide the whole string into minimum number
of substrings, such that they are a palindrome.

e.g.
For nitin:
So, 0 is the answer

For array:
arra | y -> All of these subsequences are Palindromes
O/p -> 1 (only 1 partition needed)

How to identify if this is a MCM Question?
nitin -> min # of Partitions
Now, we don't know where to partition
let's take i from left end, and take j from right end.
We actually don't know where and how to partition!
This is one of the cases where we require MCM.

When we have a Palindromic String, we will just return 0.
Here, c1 = solve(s, i , k)
c2 = solve(s, k+1, j)
c3 = 1 (why? Becuase we are doing 1 partition)
tempAnswer = c1 + c2 + c3
ans = min(ans, tempAnswer)

Coming to our format:
1. What is the value of i and j?
2. What is base condition?
3. What is the Cost values?
4. K loop value
5. Find temp answer and minimum answer.
What will be our recursive code?

1. Values of i and j
in our example:
nitin
min vaue of i can be 0.
No issue.
min value of j can be len(s) - 1
solve(s, i , j)

2. Base Condition
if(i > j): return 0
if(i==j) -> Palindrome (size 1 string)
if(i>=j): return 0 -> Works
When string itself is a Palindrome, then again we don't need
to partition
if(isPalindrome(s,i,j)):
    return 0

Coming to our loop:
for k=i; k<j; k++{
    we have partition
    (i,k)
    (k+1,j) -> since we have k+1, our max value of
    k can only be j-1.
}

'''

'''
My Solution:
solve(s, i, j)
Minimum values of i,j?
i=0, j = len(s) - 1 => Why? looking at our second example,
we need all the elements of the string

Last base condition, we had
i>=j: return 0
if i==j: -> Single element is palindrome
    return 1
Here, what happens when i == j, that means a single element,
and it's allowed
We can change our condition to i > j -> return 0

Choice diagram
Let's divide our string:
ans = 99999999
for k = i; k<=j-1; k++{
    ans1 = solve(a, i , k) (n -> return 0)
    ans2 = solve(a, k+1, j) (itin -> return 2)
    tempAns = ans1 + ans2
    # check if our current string is palindrome:
    isPalindrome = checkPalindrome(s,i,j)
    if isPalindrome:
        ans3 = 0
    else:
        ans3 = INTMAX (since not palindrome)
    ans = min(ans3, ans1 + ans2)
}

aka -> a ka
    -> ak a

For ak and a
ak -> a(0) k(0)

ka -> k(0) a(0) return 1? -> we have one partition between k and a
    What about ka? -> is it palindrome? No
    ans1 = 0
    ans2 = 0
    ans3 = Whole string palindrome -> if yes -> 0, if no -> 1
    tempAnswer = min(ans3, 1 + ans1 + ans2)
    ans = min(tempAns, ans)
return ans


# Code below is my Code, and I think it works
N = 100
table = []
for i in range(N+1):
    table.append([])
    for j in range(N+1):
        table[i].append(-1)

def checkPalindrome(s, start, end):
    # Check if string s[i:j] is a Palindrome or not
    while start <= end:
        if(s[start] == s[end]):
            start += 1
            end -= 1
        else:
            return 9999999999
    return 0

def solve(s, i, j):
    if(table[i][j] != -1):
        return table[i][j]
    
    if i>j:
        return 0
    
    # Single element is a palindrome
    if i==j:
        return 0

    ans = 9999999999
    for k in range(i,j):
        ans1 = solve(s,i,k)
        ans2 = solve(s,k+1,j)
        ans3 = checkPalindrome(s,i,j)
        tempAnswer = min(ans3, 1 + ans1 + ans2)
        ans = min(tempAnswer, ans)

    table[i][j] = ans
    return ans

s = "jfowjelkfnvcssaaaasaaaaaaaaafeeeeeewrwdfsdfsdf"
n = len(s)
result = solve(s, 0, n-1)
print("Value of result is : ")
print(result)
'''

# Code from Video
# Only 1 thing which I was doing wrong.
# Check if the string is palindrome in the base condition itself.
# Rather than checking it inside the for loop

N = 1000
table = []
for i in range(N+1):
    table.append([])
    for j in range(N+1):
        table[i].append(-1)
        

def checkPalindrome(s, start, end):
    # Check if string s[i:j] is a Palindrome or not
    while start <= end:
        if(s[start] == s[end]):
            start += 1
            end -= 1
        else:
            return False
    return True


def solve(s, i , j):
    if(table[i][j] != -1):
        return table[i][j]
        
    if(i>=j):
        return 0
    
    if checkPalindrome(s, i, j):
        return 0
    
    ans = 9999999999
    for k in range(i,j,1):
        c1 = solve(s, i, k)
        c2 = solve(s, k+1, j)
        c3 = 1
        temp = c1 + c2 + c3
        ans = min(temp, ans)

    table[i][j] = ans
    return ans

s = "nitik"
n = len(s)
result = solve(s, 0, n-1)
print("Value of result is : ")
print(result)


'''
Memoization from the Video:
Same as mine

'''