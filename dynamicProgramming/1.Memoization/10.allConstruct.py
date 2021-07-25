# Question:
'''
Write a function 'allConstruct(target, wordBank)' that accepts a target string and an array of strings.

the function should return a 2D array containing all of the ways that the 'target' can be constructed by concatenating elements of the 'wrodBank' array.

Each element of the 2D array should represent one combination that contructs the 'target'.

You may reuse elements of 'wrodBank' as many times as needed.

'''

# Examples:
'''
allconstruct[purple, [purp, p, ur. le, purpl]] -> [[purp, le], [p, ur, p, le]]

allConstruct(abcdef, [ab, abc, cd, def, abcd, ef, c]) -> [[ab, cd, ef], [ab, c, def], [abc, def], [abcd, ef]]
'''

# Base scenarios
'''
allConstruct(hello, [cat, dog, mouse]) -> return empty array
allConstruct('', [cat, dog, mouse]) -> [[]] // one way to create an empty element

allConstruct(abcdef, [ab, abc, cd, def, abcd, ef, c]):
Reconstructing this as a tree:
Now, we are receive the inputs from the childs to the parents, 
all the childrens will return 2D arrays. 
The parent should combine all the elements inside these 2D arrays to a single 2D array.



Another purple example
allconstruct[purple, [purp, p, ur. le, purpl]]

'''
class Value:
    def __init__(self, value):
        self.value = value

memo={}
def allConstruct(targetString, wordBank):
    if targetString in memo:
        return list(memo[targetString])

    if len(targetString) == 1:
        # print("Returning...")
        value = list()
        value.append([])
        return value
    
    result = list([])

    for i in range(len(wordBank)):
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
            suffix = str(targetString[len(wordBank[i]):])
            # print("Suffix is: " + suffix)
            # print("Length of suffix: " + str(len(suffix)))
            suffixWays = allConstruct(suffix, wordBank)
            # print("Suffix ways is: ")
            # print(suffixWays)
            targetWays = list(suffixWays)
            for j in range(len(targetWays)):
                targetWays[j].insert(0, wordBank[i])
                result.append(targetWays[j])
            # print("Target Ways is : ")
            # print(targetWays)
    
    # print("Result is: ")
    # print(result)
    memo[targetString] = result
    print("Memo value: " )
    print(memo)
    return result



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
        word = str(input()).rstrip()
        wordBank.append(word)
    print("Word Bank: ")
    print(wordBank)
    print(allConstruct(targetString, wordBank))
    print()

'''
Need to write cpp code for this one

Conclusion:
m - target.length
n = wordBank.length

Brute Force:
O(n^m) combinations!
O(n^m) subarrays!
Space: O(m)


Memoized:



'''