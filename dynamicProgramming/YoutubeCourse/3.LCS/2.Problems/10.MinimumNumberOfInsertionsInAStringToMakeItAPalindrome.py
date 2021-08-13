'''
Minimum number of Insertions (or Deletions) to convert a given string into a Palinfrome?

a : "a r r a y"
op: 1

How do we identify it as a LCS Problem?

Let's have a look at deletions?
What will be the minimum number of deletions to convert a string to a palindrome?
-> Here, we can solve it this way
-> Find the LPS
-> Len(a) - LPS is the required answer, as LPS is longest possible subsequence which will be a palindrome.
We can just delete all other alphabets.

What about insertions?
Well, let's have a look at what our LPS will be here.
arra
Now, we are left with y.
If we insert y at the start of the array, we will have a palindrome
So, answer = 1

What if input is: e a r r a y
-> LPS = arra
-> We need to insert e and y
What do we observe?
We just need to add characters which are not there in the LPS.
What will be it's value -> Len(a) - len(LPS)

So, no of deletions and no of insertions will be the same question, which can be asked very differently.

'''
a = "array"
b = a[::-1]
n = len(a)

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
        if(a[i-1] == b[j-1]):
            table[i][j] = 1 + table[i-1][j-1]
        else:
            table[i][j] = max(
                table[i-1][j],
                table[i][j-1]
            )
print(table)
result = table[n][n]
result = n - result
print("Required number of Insertions/Deletions are: ")
print(result)
