'''
Egg Dropping Problem : Classic DP Problem.

Flow: 
1. Problem Statement
2. MCM Pattern
3. Break Down
4. Recursive Code

Input: 
e = 3
f = 5
O/P = 3

1. Problem Statement
e is the number of eggs
f is the number of floors

We are given with the number of eggs and the floors
We have to find the minimum number of attempts to find
the critical floor with the given number of eggs.
Here we can afford to have leftover eggs.

1. MCM Pattern
How is it analogous?
-> Here, no array is given. 
But we can write f as an array, as it will have a total
of f floors.
So, we can have array of 1...f

Now, given the building, where do we start the first attempt?
Where? We have no clue.
So, we need to apply this pattern everywhere.
So, for all k values, we need to do this.
What will be the value of i and j

i = 1 (first floor)
j = f (last floor)
for k = 1; k <=j ; k++{

}

Talking of base condition?
Think of the smallest input:
We have e anf f
e -> 0/1 (1 means worst case. We need to throw from
the first floor to the f'th floor. So answer will be f.
e -> 0 is not valid. Because we cannot check at all.)
or f -> 0/1 (1 means answer will be f. As we can just 
throw from the 1st floor and we will get the answer.
For ground floor, there is no floor at all. No
threshold floor.(0 value).
for f -> 0/1 -> return f.)

What if we drop the egg from the k'th floor.
for the given f and fiven e.
So, the egg will either break, or the egg will not break.

let our function be solve(e,f)
We are on the kth floor
break -> solve(e-1,k-1) (Why, because since the egg 
breaks from kth floor, we need to check all the floors
below k.)
no break -> solve(e, f-k) (Why, because, egg didn't 
break. So the critical floor is above k'th floor.)
There are f-k remaining floors.
All the floors below k don't have the critical 
floor.
The critical floor lies in the floor between 
k+1 and f.
Thus we check all the floors between k+1 and f.

When we send k-1, it means that the next 
solve function will check the critical floor between
1 to k.
When we send f-k, it means that the next solve
function will check the critical floor between
1 to f - k.
here, 1 will represent the k+1'th floor from the previous 
k.


Writing the whole code:

'''

def solve(e,f):
    # When floor value is either 0 or 1
    if f==0 or f==1:
        return f
    
    # When the egg value is 1
    # So, here the worst case if f
    # because we need to go from the 1st floor to
    # last floor
    if e == 1:
        return f
    
    minValue = 9999999999
    # Break the value of k from 1 to the f'th floor
    for k in range(1,f+1,1):
        # when egg breaks
        case1 = solve(e-1,k-1)

        # When egg does not breaks
        case2 = solve(e,f-k)

        # Now this is one attempt
        # Why? becuase we are throwing the egg here
        # That means we are attempting to find 
        # Critical floor here
        tempValue = 1 + max(case1, case2)
        # Why to use max here?
        # Because we need to find the minimum worst
        # case value
        # That's the reason we are doing the 
        # worst case calculation here

        # Here, we are finding the minimum value
        # of all our possible combinations
        # of attempting.
        minValue = min(minValue, tempValue)
    
    return minValue

e = 3
f = 8
result = solve(e,f)
print("Value of result is: ")
print(result)