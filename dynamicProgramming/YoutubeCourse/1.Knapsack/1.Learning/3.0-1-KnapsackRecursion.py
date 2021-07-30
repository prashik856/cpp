'''
0/1 Knapsack Recursive

We have learned how to identify if this problem can be solved by dp.


Input:
w[] : 1 3 4 5
v[] : 1 4 5 7
W : 7

Output:
Maximum profit

This is a recursive solution.
Why? Because we have a choice.

Before recusion, we need to learn choice diagram.

We want to select an item. 
How many choices do we have have for this item?

Condidion 1 : We can include this only when it's weight is less than W.

so w1 <= W. -> either include it or not. (2 choices)
second : w1 > W -> Not to include w1. (1 choice)

So, we have three outcomes.
1. not to include w1 because its weight is greater than W.
2. Include w1 becuase it's weight is less than W.
3. Not to include w1 even though it's weight is less than W.
This is called a choice diagram for an item.

our function will look like this:
Our return type is int (will return maximum problem)

For any recursive function, we first need to take care of the base case!
1) Base Condition
2) choice diagram
This is true for any recursive function.

What is base condition?
Think of the smallest valid input!
Our input is w, v and W.
Our smallest value input is?
for weight array, our array size can be 0.
So our smallest size can be 0.
W smallest value can also be 0.

base case
if( len(w) == 0 || W == 0) -> return 0
There won't be any items. Assume we got to a shop, we have bag but the shop doesn't have any items.
Our profit will be 0.
Assume, shop has a lot of items, but our weight of bag is 0. Thus our profit will also be 0.

Choice diagram.
Whenever we write recursion function, 
Always make sure that in a recursive call, the function that we are calling again has been called to a lesser input value.
e.g. fib(n):
        ...
        fib(n-1) // imp -> smaller input should be called.
Now, we have w and v
let's start with the last item, and slowly move towards the start of the weight array
choices: w1 <= W -> include or not include (2 choices)
        w1 > W -> do not include
if(w[len(w) - 1] <= W){
    // can include
    // If we include this, we will have value of n-1.
    // Now we need to choose the values from the remaining arrays.
    include choice -> value[len(w) - 1] + knapsack(w, v, W - w[len(w) - 1], n-1)
    not include choice -> knapsack(w, v, W, n-1)
    We need maximization
    so 
    return max(value[len(w) - 1] + knapsack(w, v, W - w[len(w) - 1], n-1), knapsack(w, v, W, n-1))
} else {
    // do no include
    // n-1 becuase we have processed n-1th element.
    return knapsack(w,v,W, n-1)
}


'''

# Our knapsack problem
# n is the len(weight)
def knapsack(weight, value, W, n):
    # base case
    # Smallest valid input
    if n == 0 or W == 0:
        return 0
    

    # Choice diagram code
    if weight[n - 1] <= W:
        # include the profite we got value[n-1]
        includeChoice = value[n-1] + knapsack(weight, value, W - weight[n-1], n-1)
        
        # No need to include profit here
        notIncludeChoice = knapsack(weight, value, W, n-1)
        
        # return max of these choices
        return max(includeChoice, notIncludeChoice)
    else:
        # No need to include n-1 weight value at all.
        return knapsack(weight, value, W, n-1)

print(knapsack([1,3,4,5], [1,4,5,7], 7, 4))