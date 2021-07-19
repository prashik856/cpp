# Optimized Solution

memo = {}

def canSum(targetSum, numbers):
	# print("Current TargetSum: " + str(targetSum))
	if targetSum in memo:
		return memo[targetSum]
	if(targetSum == 0):
		return True
	if targetSum < 0:
		return False
	for i in range(len(numbers)):
		# Can sum will return boolean value
		if canSum(targetSum - numbers[i], numbers):
			memo[targetSum] = True
			return True
	# After all possibilities, we return the false value
	memo[targetSum] = False
	return False

print(canSum(7, [2,3]))
memo = {}
print(canSum(7, [5, 3, 4, 7]))
memo = {}
print(canSum(7, [2, 4]))
memo = {}
print(canSum(8, [2,3, 5]))
memo = {}
print(canSum(300, [7,14])) # This will take a lot of time

# Optimized solution
'''
m = target sum
n = array length

brute force: O(n^m) time, O(m) space
memoized: O(m * n) time, O(m) space

'''