'''
Matrix Chain Multiplication (MCM)

Given input:
arr [] : 40 20 30 10 30

Flow:
1. Problem Statement
2. Code using the format

1. Problem Statement
What does the array represent?
Give matrix A1, A2, A3 ...
A1 can be of size (2 x 5)
A2 can be of size (20x20)
A3 can be of size (30x20)

We want to multiply A1 x A2 x A3 x A4
While multiplying, we need to take care that the cost is minimum.
What is Cost? -> Number of multiplications

How to calculate Cost of multiplication of Matrix of sizes (a,b) and (c,d)
We already know that for the matrix multiplication to be possible, we need to have b == c.
And
Cost = a * b * d [for multiplication of size (a,b) x (b,d)]

Now, for example we have 4 matrixs A, B, C and D.
We want to find the minimum cost of 
AxBxCxD
Now we can either do (AB)(CD) -> Cost of AB + Cost CD + Cost (AB)(CD)
or We can do (A(BC)D)
or we can do (A(B(CD)))
There are many ways!
So, using these different brackets, we need to calculate the minimum cost to multiply these matrixs.

How will be represent the size of matrix?
Given an array a : [40 20 30 10 30]
This represents 4 matrices of size (40, 20), (20,30), (30,10), (10,30)!
This is how we can store size of matrices in a single array!

So, dimensions of A[i] = (arr[i-1], arr[i]) (We represent matrix from 1)


Next Step:
2. How do we know that this is a MCM Question?
-> First we see that we have some array
-> And we don't know where to put the brackets to solve that question
Usually, in the questions where we don't know where to put the brackets
And then solve the question recursively

3. Format:
We needed to choose i and j.
Now, looking at our given array
40 20 30 10 30
Since our dimension of matrix is caluculated as 
Ai = arr[i-1] + arr[i]
if we take i =0, we will have arr[-1] -> NOPE
So, value of i should be 1.
And value of j should be 4

Now, coming to our code
We need to return minimum cost
return type of our function is int

int solve(int arr[], int i, int j){
    if(i >= j ){
        return 0;
    }
}

Is our base condition going to change?
if i == j, 
This means we have 1 element in our array.
But, how will we calculate the size of our matrix 
using just 1 element?
Because Ai = arr[i-1] + arr[i]
So, i == j is not possible!

So, invalid inputs are
i > j 
i == j is also not allowed
so, i>=j -> return 0

Now, 
1. Find i and j values -> Done
2. Find right Base Condition -> Done
3. Move k -> i to j

How should we move k now?
Can we start k from i?
Yes, because, we already have valid value of i
And we will have grouping (i,k)(k+1,j)
No issues here.
Can k have the value of j?
Assume value of k is equal to j.
First group will be (i,k)(k+1,j) -> (i,j)(j+1,j)
But the array is only till j. j+1 is not a valid value at all.
So, k cannot go till j, it will go till j-1.

so k = i; k <= j - 1; k++

Can we have some other way to run this loop?
Yes, we can break our array in two way
First -> We take (i, k) and (k+1,j)
Second -> (i, k-1) and (k,j) This is also valid.
But here, out k will go till value of j, and k will start from i + 1.

Now, we also know the values of k.
int solve(int arr[], int i, int j){
    if(i >= j ){
        return 0;
    }

    for(int k=i; k<=j-1; k++){
        solve(arr,i,k);
        solve(arr,k+1,j);
        // How, will be calculate the cost of 
        // multiplying matrix (i,k) and (k+1,j)
        
        Consider example 
        40 20 30 10 30
            i  k     j
        
        So, our two arrays will be(i,k) and (k+1,j)
        so (40,20,30) and (10,30)
        So, we will have 
        (40,20) (20,30) and (30,10)(10,30)
        The resulting matrices will be
        (40,30) and (30,30)
        Our recursive functions will give us the cost of
        multiplying (40,20)(20,30) and (30,10)(10,30)
        Now we need to calculate the cost
        of multiplying matrices of size (40,30)(30,30) 
        which is the resulting matrix.
        Here, Cost = 40 * 30 * 30
        Remember our values of i,j and k
        Cost = arr[i-1] * arr[k] * arr[j]
    }
}

So, our function will actually look like this:
int solve(int arr[], int i, int j){
    if(i>=j){
        return 0;
    }

    int ans = INT_MAX;
    for(int k=i; k<=j-1; k++){
        int cost1 = solve(arr,i,k);
        int cost2 = solve(arr,k+1,j);
        int cost3 = arr[i-1] * arr[k] * arr[j];
        int tempCost = cost1 + cost2 + cost3;
        # Calculate minimum answer from temporary answer
        ans = min(ans, tempCost);
    }
    return ans; 
}
'''
def solve(a, i, j):
    # base condition
    # Cannot be single element
    # And i can never be greater than j
    if i >= j: 
        return 0
    
    ans = 999999999999
    for k in range(i, j, 1):
        cost1 = solve(a, i, k)
        cost2 = solve(a, k+1, j)
        cost3 = a[i-1]*a[k]*a[j]
        tempCost = cost1 + cost2 + cost3
        # Calculate the minimum cost of all these costs
        ans = min(ans, tempCost)
    
    return ans
    
a = [i for i in range(1,20)]
n = len(a)
print("Length of array: ")
print(n)
result = solve(a,1,n-1)
print("Value of result is: ")
print(result)