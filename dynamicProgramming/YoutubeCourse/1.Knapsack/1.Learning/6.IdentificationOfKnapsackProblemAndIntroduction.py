'''
Revision of Knapsack and Introduction to further problems

1) Subset sum Problem
2) Equal sum partition
3) count of Subset sum
4) Minimum subset sum difference
5) Target sum
6) No of subsets of given difference

How do we identify?

One more thing before that

Input: 
w[]
v[]
W

We also had 
if(w[i-1] <= j){
    table[i][j] = max(
        v[i-1] + table[i-1][j - w[i-1]],
        table[i-1][j]
        )
} else {
    table[i][j] = table[i-1][j]
}

Upcoming problem, we might have just one array.
In our knapsack array too, we actually had just one array,
item array consisting of 2 properties, weight and value.

Sometimes, we might be given just one array.
In this case we only consider weight array, and remove the value array.
And we will have a Capacity.

What was our problem?
Given number of items, i1,i2...in, and a given W.
We had to choose and fill the W.

If we have a pattern where we have a number of items, and we have some bag (some max value).
And from items, we have some choice. 
Then this pattern is a Knapsack pattern.


'''