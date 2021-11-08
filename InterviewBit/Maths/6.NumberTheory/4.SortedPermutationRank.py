'''
Given a string, find the rank of the string amongst its permutations sorted lexicographically. 

Assume that no characters are repeated.

Example :

Input : 'acb'
Output : 2

The order permutations with letters 'a', 'c', and 'b' : 
abc
acb
bac
bca
cab
cba
The answer might not fit in an integer, so return your answer % 1000003
'''
'''
Solution Approach:
https://www.geeksforgeeks.org/lexicographic-rank-of-a-string/

Method 1:
One simple solution is to initialize rank as 1, generate all permutations in lexicographic order. 
After generating a permutation, check if the generated permutation is same as given string, if same, then return rank, 
if not, then increment the rank by 1. 
The time complexity of this solution will be exponential in worst case. 

Method 2;
Let the given string be “STRING”. In the input string, ‘S’ is the first character. 
There are total 6 characters and 4 of them are smaller than ‘S’. 
So there can be 4 * 5! smaller strings where first character is smaller than ‘S’, like following
R X X X X X 
I X X X X X 
N X X X X X 
G X X X X X
Now let us Fix ‘S’ and find the smaller strings starting with ‘S’.

Repeat the same process for T, rank is 4*5! + 4*4! +…

Now fix T and repeat the same process for R, rank is 4*5! + 4*4! + 3*3! +…

Now fix R and repeat the same process for I, rank is 4*5! + 4*4! + 3*3! + 1*2! +…

Now fix I and repeat the same process for N, rank is 4*5! + 4*4! + 3*3! + 1*2! + 1*1! +…

Now fix N and repeat the same process for G, rank is 4*5! + 4*4! + 3*3! + 1*2! + 1*1! + 0*0!

Rank = 4*5! + 4*4! + 3*3! + 1*2! + 1*1! + 0*0! = 597

Note that the above computations find count of smaller strings. 
Therefore rank of given string is count of smaller strings plus 1. The final rank = 1 + 597 = 598

Remember, we also have to give rank % 1000003 as the answer!
'''
def getAllFactorials(n):
    factorials=[]
    factorials.append(1)
    factorials.append(1)
    for i in range(2, n+1):
        value = i * factorials[i-1]
        factorials.append(value)
    return factorials

def solve(a):
    result = 0
    factorials = getAllFactorials(len(a))
    # print("Factorial Array is: ")
    # print(factorials)

    count = []
    for i in range(len(a)):
        value = 0
        for j in range(i+1, len(a)):
            if a[i] > a[j]:
                value += 1
        count.append(value)
    # print("Count array is: ")
    # print(count)


    for i in range(len(a)):
        characterRank = len(a) - i - 1
        if(characterRank <= 0):
            characterRank = 0
        # print("Character rank: " + str(characterRank))
        # print("Count value: " + str(count[i]))
        value = count[i] * factorials[characterRank]
        result += value
        # print(i)
    # this is rank of just before
    result += 1
    result = int(result % 1000003)

    return result

Limit = 20
a = "DTNGJPURFHYEW"
result = solve(a)
print("Result: " + str(result))