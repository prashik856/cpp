'''
# Grid Traveller
# Say that you are a traveler on a 2D grid. You begint in top-left corner and your goal is to travle to the bottom -right corner. You may only move down or right.
# In how many ways can you travel to the goal on a grid with dimensions m * n?
# Grid can be a rectangle
# Write a function gridTraveler(m,n) that calculates this

# e.g gridTraveler(2,3) : 2 x 3 grid
# r r d, r d r, d r r 
# three unique ways to travle

# gridTraveler(1,1) -> 1 unique way
# S is same as end

# gridTraveler(0,1) -> Grid is empty
# 0 ways to travel
# gridTraveler(1,0) -> 0
# girdTraveler(0,0) -> 0

# These are our base cases

# gridTraveler(3,3) -> ?
# if we move down, we then want to calculate gridTraveler(2,3) 
# this is our independent subproblem that we have here
# if now we move to right -> we want to find gridTraveler(2,2) 
# Now, we definitely have an overlapping subproblem

# let's visualize it using tree

(2,3) -> (1,3) or (2,2) 
We are reducing one of the dimensions by one
Now, child of 1,3 is (0,3) or (1,2)
and child of (2,2) -> (1,2) or (2,1)
Now, this is just a spinoff of fibonacci numbers

Left hand tree is going downwards, right hand tree is going rightward.
Using the tree, we also know the way to win the game. i.e. the path twe followed to come to this conclusion.

'''

def gridTraveler(m,n):
	# base cases
	if( m == 1 and n == 1):
		return 1
	if( m == 0 or n == 0):
		return 0
	# m - 1 go down
	# n - 1 go right
	return gridTraveler(m-1, n) + gridTraveler(m, n-1)

print(gridTraveler(1,1))
print(gridTraveler(2,3))
print(gridTraveler(3,2))
print(gridTraveler(3,3))
print(gridTraveler(18,18)) # 18x18 will time out 

'''
why is our code so slow now?
example: gridTraveler(2,3):
We want improvement
Our node can branch up to two children
Height of our tree is 2
O(2^(n+m)) time
space: O(n+m) since we have n + m levels

'''