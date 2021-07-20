'''
Write a function 'canConstruct(target, wordBank)' that accepts a target string and an array of string.

The function should return a boolean indicating whether or not the 'target' can be contructed by concatenating elements of the 'wordBank' array.

You may reuse elements of 'wordBank' as many times as needed.

Just yes or no
'''

# Examples
'''
canConstruct(abcdef, [ab, abc, cd, def, abcd]) -> true

canConstruct(skateboard, [bo,rd,ate,t,ska,sk,boar]) -> false

// base case
canConstruct('', [cat, dog, mouse]) -> true

We can visualize this via tree :)

start with fisrst example:
root -> abcdef
Go to child only if we have a matching prefix!

skateBoard -> false
root = skateboard

'''
memo = {}
def canConstruct(targetString, wordBank):
	if targetString in memo:
		return memo[targetString]

	if(targetString == ''):
		return True 

	# iterate through all the words
	for i in range(len(wordBank)):
		# when is it okay to use that word
		# need to make sure that wordBank[i] is a substring of targetString
		index = 0
		isPrefix = False
		# print("TargetString: " + str(targetString))
		# print("WordBank i: " + wordBank[i]) 
		for j in range(len(wordBank[i])):
			if targetString[index] == wordBank[i][j]:
				index += 1
			else:
				break
		if index == len(wordBank[i]):
			# Yes
			isPrefix = True
		else:
			# No
			isPrefix = False

		if isPrefix:
			# Slice our string and take the string after prefix
			suffix = targetString[len(wordBank[i]):]
			if canConstruct(suffix, wordBank):
				memo[targetString] = True
				return True

	memo[targetString] = False
	return False


t = int(input())
print("Number of test cases: " + str(t))
print()
for i in range(t):
	memo = {}
	print("Test case: " + str(i))
	targetString = input()
	print("Target String: " + str(targetString))
	wordBankLength = input()
	print("Word Bank Lenght: " + wordBankLength)
	wordBank = []
	for j in range(int(wordBankLength)):
		word = str(input())
		wordBank.append(word)
	print("Word Bank: ")
	print(wordBank)
	if canConstruct(targetString, wordBank):
		print("YES")
	else:
		print("NO")
	print()


# Time Complexities
'''
m = targetString.length
n = wordBank.length
Brute Force: 
time: O(n^m * m) -> We are checking if a given wordBank is a prefix of targetString
Space: O(m*m) -> We are also creating an array of new string, which is suffix
'''

# Optimizing
'''
We want to look for duplicate subtrees
We can just memoize our code.

Final Complexity Analysis:
m = targetString.length
n = wordBank.length
memoized:
O(n * m * m): time
O(m * m) : Space
'''