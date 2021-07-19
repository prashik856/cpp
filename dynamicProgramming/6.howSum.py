# Question
'''
Write a function 'howSum(targetSum, numbers) that takes in a targetSum and an arrya of numbers as arguments'

The function should return an array containing any combination of elements that add up to exactly the targetSum. If there is no combination that adds up to the targetSum, then return null.

If there are multiple combinations possible, we may return any single one
'''

# Examples:
'''
howSum(7, [5, 3, 4, 7])  -> [7] or [3, 4]
howSum(8, [2,3,5]) -> [3, 5] or [2,2,2,2]
howSum(7, [2,4]) -> Null
howSum(0, [1,2,3]) -> [] : Return an empty array when we have 0 have.
howSum(7, [5,3,4,7]) 
We have some scenearios, we get a value of 0.
When we get 0, we just return empty array
When we get a number, we add that number to the current array
so, parent should return [4]
When we reach 7, we shoud push 3 in array [4,3] should be an answer for this problem
we want to add the value of the edge
When we reach a node where sum is impossible, return null
need to consider return values considered.
If atleast one of the branches gives us an array, then we know that it is possible
We can return early too, since one combination is okay
'''

def howSum(targetSum, numbers):
	# print("TargetSum: " + str(targetSum))
	if(targetSum == 0):
		return []
	if targetSum < 0:
		return None

	for i in range(len(numbers)):
		value = howSum(targetSum - numbers[i], numbers)
		if value is not None:
			value.append(numbers[i])
			return value

	return None

print(howSum(7, [2,3]))
print(howSum(7, [5,3,4,7]))
print(howSum(7, [2,4]))
print(howSum(8, [2,3,5]))
print(howSum(300, [7,14]))

# Time Complexity?
'''
time: O(n^m * m )
Space: O(m + n)

'''