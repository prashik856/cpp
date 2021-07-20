
# memo = {}
# def bestSum(targetSum, numbers):
# 	# base cases
# 	if targetSum in memo:
# 		# print("Target Sum : " + str(targetSum))
# 		# print("Memo value: ")
# 		# print(memo[targetSum])
# 		return memo[targetSum]
# 	if targetSum == 0:
# 		return []
# 	if targetSum < 0:
# 		return None	

# 	shortestCombination = []

# 	for i in range(len(numbers)):
# 		remainder = targetSum - numbers[i]
# 		remainderCombination = bestSum(remainder, numbers)
# 		if remainderCombination is not None:
# 			# possible to generate
# 			remainderCombination.append(numbers[i])
# 			if(len(remainderCombination) < len(shortestCombination)):
# 				shortestCombination = remainderCombination

# 	# print("Target Sum: " + str(targetSum))
# 	# print("Shortest Path: ")
# 	# print(shortestCombination)
# 	if len(shortestCombination) > 0:
# 		memo[targetSum] = shortestCombination
# 	else:
# 		memo[targetSum] = None
# 	# print("Current Memo after storage: ")
# 	# print(memo)
# 	# print()

# 	return shortestCombination

# # print(bestSum(7, [5,3,4,7])) # [7]
# # print(memo)
# # memo = {}
# print(bestSum(8, [2,5,3])) # [3, 5]
# print(memo)
# # memo = {}
# # print(bestSum(8, [1,4])) # [4, 4]
# # memo = {}
# # print(bestSum(100, [1,2,5,25])) # [25, 25, 25, 25]
# # print(memo)
# # memo = {}
# # print(bestSum(2, [1,2]))