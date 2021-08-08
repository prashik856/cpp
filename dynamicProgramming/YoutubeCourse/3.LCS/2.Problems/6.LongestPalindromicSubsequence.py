'''
Longest Palindromic subsequence

a : a h b c b a
O/P: 5

Explanations:
the longest common palindromic subsequence is: abcba

How do we relate it to lcs problem?
This is because they are asking us the longest 
palindromic subsequence.

But what about inputs?
We only have 1 string array as input.
That must mean that something is wrong.
Or that we don't actually need to be given the second
string in the input.
That means we need to create the second input string?

How do we create the second input string?
Let's look at the question.
It is asking for longest Palindromic subsequence.
What is a Palindrome?
a string is a palindrome when the reverse of string 
is equal to that of the given string.

So, looking at the question, it looks like we need to 
reverse the given string.
So, our second input will be
b : reverse(a)
Now, the longest palindromic subsequence will
be the lcs between a and b?
Why so?
Because, here we are trying to find a longest
common subsequence between a string and it's reverse.

That means, at the end of the day, if we have a look
at it, we are actually finding the longest palindromic
subsequence.

example:
a : a h b c b a
Value of b = reverse(a) = a b c b h a
If we find it's lcs:
a b c b a
Which is the actual required answer.

'''

a = "array"
n = len(a)
b = a[::-1]

table = []
for i in range(n+1):
    table.append([])
    for j in range(n+1):
        table[i].append(-1)
        if i==0 or j==0:
            table[i][j] = 0
print(table)

for i in range(1, n+1):
    for j in range(1, n+1):
        if a[i-1] == b[j-1]:
            table[i][j] = 1 + table[i-1][j-1]
        else:
            table[i][j] = max(
                table[i][j-1],
                table[i-1][j]
            )
print(table)

result = table[n][n]
print("LPS is : ")
print(result)