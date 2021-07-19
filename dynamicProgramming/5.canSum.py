'''
Write a function 'canSum(targetSum, numbers)' that takes in a targetSum and an array of numbers as arguments
The function should return a boolean indicating whether or not it is possible to generate the targetSum using the numbers from the array.

We may use an element of the array as many times as needed.

We may assume that all input numbers are nonnegative

'''

# Intuition
'''
canSum(7, [5,3,4,7]) -> true
3 + 4
7 

canSum(7,[2,4]) -> false

How can we do this recursively?

canSum(7, [5,3,4,7]) 
We start with root node as 7.
Now we have len(arr) number of choices
Then if we select 5, we still need 2
for 3, need 4
for 4 need 3
for 7 need 0
However, for 2. We don't have any valid input afterwards. As we will be getting our target sum as negavtive.
Whereas for 4 and 3, we have some options
for 3, we have a choice, but for 0 we don't have any further choices.

Now, some leafs are 0. 
Now, we have found our base case.
So, whenever we encounter 0, we must return true.
A left over value (e.g. 2 or 1) should return false to their parents
The parent should just check if atleast if one of them is true.
If any of them is true, the parent should also return a true value

How do we know the flipside? The leaf that will always have a false answer?

If we have atleast one key which has true value, we can just early stop!

'''

def canSum(targetSum, numbers):
	if(targetSum == 0):
		return True
	if targetSum < 0:
		return False
	for i in range(len(numbers)):
		# Can sum will return boolean value
		if canSum(targetSum - numbers[i], numbers):
			return True
	# After all possibilities, we return the false value
	return False


print(canSum(7, [2,3]))
print(canSum(7, [5, 3, 4, 7]))
print(canSum(7, [2, 4]))
print(canSum(8, [2,3, 5]))
print(canSum(300, [7,14])) # This will take a lot of time

'''
Complexity of brute force solution:
canSum(8, [2,3,5])
m = target sum
n = array length
Height of the tree will be m
What is the branching factor?
Every node will have almost n children
O(n^m) time
O(m) Space -> Height of the tree
'''

# How can we improve this?
'''
Now, we have overlapping subproblem!
for example
canSum(8, [2,3,5]) -> true
canSum(3) is called 3 times
We can just cache them
'''