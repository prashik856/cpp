def howSum(targetSum, numbers):
	table = []
	isPossible = []
	for i in range(targetSum + 1):
		table.append([])
		isPossible.append(False)
	# print(table)
	

	# If targetsum is 0, it is always possible to
	# we can just return empty list []

	isPossible[0] = True
	# print(isPossible)
	for i in range(targetSum + 1):
		for j in range(len(numbers)):
			if isPossible[i]:
				# What is the value that we will be getting?
				value = table[i]
				print("Value before: ")
				print(value)
				value.append(numbers[j])
				print("Value after append: ")
				print(value)
				sumValue = sum(value)
				print("Sum :" + str(sumValue))
				if sumValue <= targetSum:
					isPossible[sumValue] = True
					table[sumValue] = value
					print("Table value after assigning: ")
					print(table)
	if not isPossible[targetSum]:
		return None
	else:
		return table[targetSum]


print(howSum(1, [1])) # True
# print(howSum(2,[1])) # True
# print(howSum(3,[2])) # False
# print(howSum(4,[1,2])) # True
# print(howSum(7, [2,3])) # True
# print(howSum(7, [5, 3, 4, 7])) # True
# print(howSum(7, [2, 4])) # False
# print(howSum(8, [2,3, 5])) # True
# print(howSum(300, [7,14])) # False