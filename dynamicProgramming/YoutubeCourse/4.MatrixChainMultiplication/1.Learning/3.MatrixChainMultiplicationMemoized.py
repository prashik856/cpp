'''
Matrix Chain Multiplication - Memoized:

Flow: 
1. MCM Recursion
2. How to build a table?
3. Why it is neede?
4. Changes

How to build our Cache now?

First, how to find the dimensions of the table?
What are the values that are changing?
What are the inputs to our recusion function?
Our inputs are input array a, the index i, and index j.
Only value that remains constant is a.
And the value of i and j are changing.
So, we need to make a matrix based on the values of i and j.
What is max value of i and j, which is size of array.

So, we can create our table of size of given array.
if len(a) = n
we need table of size (n+1,n+1)

How, we have a matrix.
How to store value inside it? (Initialize?)
We can just initialize it with -1.
If value is not equal to -1, it is already solved.
If value is -1, that means, this is the value which 
we are solving the first time.

Now, 
We have n,
table[n+1][n+1] -> We have initialized it with -1.

Now, coming to our recursion code:

int solve(int arr[], int i, int j) {

    # Memoizing it
    if(table[i][j] != -1) {
        return table[i][j]
    }

    if(i>=j) {
        return 0
    }

    int ans = INT_MAX
    for(int k=i; k<=j-1; k++) {
        int cost1 = solve(arr, i, k);
        int cost2 = solve(arr, k+1, j);
        int cost3 = arr[i-1]*arr[k]*arr[j];
        int tempCost = cost1 + cost2 + cost3
        ans = min(ans, tempCost);
    }
    
    table[i][j] = ans;
    return ans;
 }
'''
maxLengthA = 50
table = []
for i in range(maxLengthA + 1):
    table.append([])
    for j in range(maxLengthA + 1):
        table[i].append(-1)

def solve(a, i, j):
    if(table[i][j] != -1):
        return table[i][j]
    
    if(i>=j):
        return 0
    
    ans = 999999999999
    for k in range(i, j, 1):
        cost1 = solve(a, i, k)
        cost2 = solve(a, k+1, j)
        cost3 = a[i-1] * a[k] * a[j]
        tempCost = cost1 + cost2 + cost3
        ans = min(tempCost, ans)
    
    table[i][j] = ans
    return ans

a = [i for i in range(1,4)]
n = len(a)
print("Length of array: ")
print(n)
result = solve(a,1,n-1)
print("Value of result is: ")
print(result)