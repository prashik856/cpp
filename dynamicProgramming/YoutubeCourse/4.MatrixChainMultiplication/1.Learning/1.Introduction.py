'''
Here, first we will learn usual format of Matrix Chain Multiplication Problems

Our input will be an array
that array can be a String or normal Array

a : [1 2 .... n]

To solve this question, will have to do something like this,
We will take the first element of array as i, and last elemen of array as j
Let k be the interval(k>=1)

Let solve be our recursive funtion
so, 

What will be our base condition?
-> As we know, it usually depend on the lowest possible inputs or look at the VALID input. 
Here, we have i as the starting point of our array, and j as the end point of array.
So, the last possible value that can happen is i == j (Just one element)
So, when i <= j (since i is start, j is end, it will be valid)
But when i > j (start index is greater than subsequent element, this should never be possible!)

So, our base condition is if (i > j) -> return 0
int solve(int a[], int i, int j) {
    # base Condition
    if(i > j) {
        return 0
    }

    # Choice Diagram
    # we want to run k from i to j
    int ans;
    for(int k=i; k<j; k++){
        # Now, k can start from i, or it can start from i + 1
        # K can also end just before j, or it can end on j 
        # k can also increment by 2, or by 3
        # All these conditions depends on the question
        int tempAnswer = someFunction(solve(a,i,k),solve(a,k+1,j))
        ans = someFunction(tempAnswer, ans) 
        #These someFucntion() value can be anything, depending on the question
        #Similarly, we might need to add our recursive calls, or take max of them,
        # minimum of them, it all depends on the question.
    }
}
This is all the MCM is


Summing up:
Given Array
We need to take some i and j.
i will be in the left side of array, and j will be at the right side of array 
such that our i>=j
This is a must.
We need to move k from i to j, it's increment will depend on the question.
k can move from i+1, or till j-1, or it can increment by 2. All depending on the question.

'''