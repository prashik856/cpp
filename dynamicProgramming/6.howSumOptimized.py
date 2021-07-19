memo = {}
def howSum(targetSum, numbers):
	# print("TargetSum: " + str(targetSum))
	if(targetSum in memo):
		return memo[targetSum]
	if(targetSum == 0):
		return []
	if targetSum < 0:
		return None

	for i in range(len(numbers)):
		value = howSum(targetSum - numbers[i], numbers)
		if value is not None:
			value.append(numbers[i])
			memo[targetSum] = value
			return value

	memo[targetSum] = None
	return None

print(howSum(7, [2,3]))
memo = {}
print(howSum(7, [5,3,4,7]))
memo = {}
print(howSum(7, [2,4]))
memo = {}
print(howSum(8, [2,3,5]))
memo = {}
print(howSum(300, [7,14]))
memo = {}
print(howSum(300, [1,2]))

'''
Optimized:
Memoized:
Time = O(n*m^2)
Space = O(m*m)
'''


'''
howSum:
m = targetSum
n = array length

brute force:
O(n^m * m) -> Time
O(m) space

memoized:
O(n * m ^ 2) time -> Not exponential
O(m^2) space -> A little more cose
'''
