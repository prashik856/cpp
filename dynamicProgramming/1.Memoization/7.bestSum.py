# Problem definition
'''
Write a function 'bestSum(targetSum, numbers)' that takes in a targetSum and an array of numbers as arguments.

The function should return an array containing the shortest combination of numbers that add up to exactly the targetSum.

If there is a tie for the shortest combination, you may return any one of the shortest.

Array containing the least amount of numbers.
'''

# Examples
'''
bestSum(7, [5,3,4,7])
[3,4]
or [7]
Since length of array 7 is less than array containing [3,4], 7 is the answer.

bestSum(8,[2,3,5])
[2,2,2,2]
[2,3,3]
[3,5] -> result

Do we need to sort the array?

Example as tree:
bestSum(8, [2,3,5])
	Here, we cannot return early because we need to find the optimal answer
	We need to make a decicion when the arrays are returned, which of the returned array is shortest.
	We take that array
	we cannot be sure unless and until we have explored every other possibility.

'''
# need to do exaustive search
def bestSum(targetSum, numbers):
	# base cases
	if targetSum == 0:
		return []
	if targetSum < 0:
		return None
	
	shortestCombination = None

	for i in range(len(numbers)):
		remainder = targetSum - numbers[i]
		remainderCombination = bestSum(remainder, numbers)
		if remainderCombination is not None:
			# possible to generate
			remainderCombination.append(numbers[i])
			if(shortestCombination is None or len(remainderCombination) < len(shortestCombination)):
				shortestCombination = remainderCombination

	return shortestCombination

print(bestSum(7, [5,3,4,7])) # [7]
print(bestSum(8, [2,5,3])) # [3, 5]
print(bestSum(8, [1,4])) # [4, 4]
print(bestSum(100, [1,2,5,25])) # [25, 25, 25]
# The biggest will not always return the optimal solution

# Complexity
'''
m = target sum
n = len(numbers)

Brute Force
time: O(n^m * m )
Space: O(m*m)
'''