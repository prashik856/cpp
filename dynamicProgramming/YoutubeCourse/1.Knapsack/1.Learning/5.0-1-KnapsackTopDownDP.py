'''
If you write topdown, we get some extra marks!

Complexity of Memoize and Tabulation is same.
Sometimes, any of them is better.

We can use memoization safely!

From the Constraint, we create the table array with max dimensions from the chaning inputs to function..

This will pass all the test cases even with memoization.

We need to learn Top down approach as well.

Is top down real dp? lol?

We will look at recursive code memoized and convert it to topdown approach.
Then use other 6 problems which are the variations.

We will use our old concepts to write the top down approach.

Coming back, we had Recrusvie code -> Base condition + Choice condition

Memoized code => Choice code 
Remeber the way we initialized the table.


Here in top down approach, we will only use the table.
we won't use recursive call at all.
This is better because the stack value might sometime become too big.
We can get Stack Overflow error.
Using top down, we will never get stack overflow error.
So we usually use Top down approach for these problems, and it is usually better.

Best for DP is always Top - down approach.
Memoized code not working is a rarity. 

Now, we have recursive code ready with memoization version.
We come down to topdown version.

Since we can do memoization using recursive, so that can also mean we can convert it to top down DP.

If recursion is not strong, DP will be difficult for us.
Learn recursion properly.

Now, what is the size of metrix?
we already know it from the memoized. We use the variables from the function which are actually changing.
We usually store +1 size of the table.

How do we store this table?
Step 1 -> Initialization
Step 2 -> We need to change recursive calls to iterative.

How to Initialize?
What is the value of table[n][W]?

let's see an example first
W = 7
w : [1 3 4 5]
v : [1 4 5 7]

We need to make table for this input.
we have n=4, W = 7
table will be of size table[n+1][W+1] = table[5][8]
Now we have created a metrix.

What does table[i][j] signifies?
it tells us the optimal answer when teh value of W = j, and n = i.
thus max profit for W= j and n=i. (when we are only give initial i items, and some weight W.)
for table[2][3], we will have answer for n = 3 and weight W = 3.
for table[3][6] -> it will give us the optimal solution for W = 6, n = 3, so w: [1,3,4] and v: [1 4 5]
So these are sub problems. We are actually storing the solution of all of our sub problems.
After we solve all these subproblems, we arrive at our final solution.

table[4][7] -> optimal solution for W = 7, n=4 , w: [1 3 4 5] v: [1 4 5 7]
Thus we will get our solution at table[n][W]
Thus returning table[n][W] will give us our solution.

Why is initializtion important?
We need to make our solution iteration.
coming back to recursion, we had a base condition. 
What will happen to this base condition?
This base condition will change it to our base condition.
Once we write a recursive solution, we have everything.

So using base condition, we will initialize our table.
Now, 
Recursive base condition -> Top Down Initialization.
if n==0 | W == 0 {
    return 0
}

That means, any table[0][:] = 0, and table[:][0] = 0. Using our base condition.
Recursive funtion is everything. Always first write the recursive function.
make it work first at all costs.


'''
n = 4
W = 7
w = [1,3,4,5]
v = [1,4,5,7]
table = []
for i in range(n+1):
    table.append([])
    for j in range(W+1):
        table[i].append(-1)
        # base condition.
        '''
        remember the recurseive funtion
        if(n == 0 || W ==0) {
            return 0
        }
        '''
        if( i == 0 or j == 0): 
            table[i][j] = 0
print(table)

# Now choice diagram recursion code.
'''
Choice condition.
if w > W -> don't include
if w <= W -> either take or don't take

if(weight[n-1] <= W) {
    return max(value[n-1] + knapsack(w,v, W - weight[n-1], n-1),
                knapsack(w,v,W,n-1))
}
in tabulation
    table[n][W] = max(value[n-1] + table[n-1][W-weight[n-1]], 
                    table[n-1][W])

else {
    return knapsack(w,v,W,n-1)
}
in tabulation
    table[n][W] = table[n-1][W]

Now, we can replace n,W with i,j

    if(weight[i-1] <= j){
        table[i][j] = max(value[i-1] + table[i-1][W - weight[i-1]],
                        table[i-1][W])
    } else {
        table[i][j] = table[i-1][W]
    }
so
'''
for i in range(1,n+1):
    for j in range(1, W+1):
        if w[i-1] <= j:
            table[i][j] = max(
                v[i-1] + table[i-1][j - w[i-1]],
                table[i-1][j]
            )
        else :
            table[i][j] = table[i-1][j]
# Got our result in table[n][W]
print(table)
print(table[n][W])


'''
Summary: 
we made table[n+1][W+1]

intitialized it using base condition.
table[0][:] = 0
table[:][0] = 0

We then use our Choice diagram to fill up the table.

return table[n][W]
'''