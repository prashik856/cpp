# Question
'''
Write a function 'countConstruct(target, wordBank)' that accepts a target string and an array of strings.

The function should return the number of ways that the 'target' can be constructed by concatenating elements of the 'wordBank' array.

You may reuse elements of 'wordBank' as many times as needed.
'''

# Examples:
'''
countConstruct(abcdef, [ab, abc, cd, def, abcd]) -> 1

If we have a value where we get a node which cannot be further down
It should return 0 value.

The parent should add up the values returned by their children


countConstruct(purple, [purp, p, ur, le, purpl]) -> 2

'''
memo = {}

def countConstruct(targetString, wordBank):
	if targetString in memo:
		return memo[targetString]

	if targetString == '':
		return 1
	# iterate through all the words
	value = 0
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
			value = value + countConstruct(suffix, wordBank)

	memo[targetString] = value
	return value


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
		word = input()
		wordBank.append(word)
	print("Word Bank: ")
	print(wordBank)
	print(countConstruct(targetString, wordBank))
	print()

'''
m = targetString.length
n = wordBank.length
Brute force
time: O(n^m * m)
Space: O(m*m)

Memoized:
time: O(n*m*m)
Space: O(m*m)
'''

