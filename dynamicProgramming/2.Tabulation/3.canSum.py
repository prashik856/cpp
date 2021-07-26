'''
given numbers and a targetSum value, determine if it is possible to obtain the value of the sum
'''

def canSum(targetSum, numbers):
	table = [False] * (targetSum + 1)

	# if target sum value is zero, it is always possible to select subarray
	# We can just select anything

	table[0] = True

	for i in range(targetSum + 1):
		for j in range(len(numbers)):
			if table[i]:
				value = i + numbers[j]
				# it is possible to obtain value using
				if(value <= targetSum):
					table[value] = True
	return table[targetSum]

print(canSum(1, [1])) # True
print(canSum(2,[1])) # True
print(canSum(3,[2])) # False
print(canSum(4,[1,2])) # True
print(canSum(7, [2,3])) # True
print(canSum(7, [5, 3, 4, 7])) # True
print(canSum(7, [2, 4])) # False
print(canSum(8, [2,3, 5])) # True
print(canSum(300, [7,14])) # False