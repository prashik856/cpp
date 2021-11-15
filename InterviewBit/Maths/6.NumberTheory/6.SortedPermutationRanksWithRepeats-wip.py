'''
Given a string, find the rank of the string amongst its permutations sorted lexicographically. 

Note that the characters might be repeated. If the characters are repeated, we need to look at the rank in unique permutations. 

Look at the example for more details.

Example :

Input : 'aba'
Output : 2

The order permutations with letters 'a', 'a', and 'b' : 
aab
aba
baa
The answer might not fit in an integer, so return your answer % 1000003

NOTE: 1000003 is a prime number

NOTE: Assume the number of characters in string < 1000003
'''

'''
Solution Approach:
First we learn this:
https://www.geeksforgeeks.org/lexicographic-rank-of-a-string/
And for this problem, we learn something new here:
https://www.geeksforgeeks.org/lexicographic-rank-string-duplicate-characters/

To solve the Multiplication and Division with Modulo operator, we also need to learn first this:
https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/

And once we learn multiplicative inverse under modulo, we need to learn:
https://www.geeksforgeeks.org/modular-division/

Step 1: 
The method here is a little different from the without repetition version. 
Here we have to take care of the duplicate characters also. 

Let’s look at the string “settLe”. 
It has repetition(2 ‘e’ and 2 ‘t’) as well as upper case letter(‘L’). 
Total 6 characters and the total number of permutations are 6!/(2!*2!). 

Now there are 3 characters(2 ‘e’ and 1 ‘L’) on the right side of ‘s’ which come before ‘s’ lexicographically. 
If there were no repetition then there would be 3*5! smaller strings which have the first character less than ‘s’. 
But starting from position 0, till the end there are 2 ‘s’ and 2 ‘t'(i.e. repetitions). 
Hence, the number of possible smaller permutations with the first letter smaller than ‘s’ are (3*5!)/(2!*2!). 

Similarly, if we fix ‘s’ and look at the letters from index 1 to end then there is 1 character(‘L’) lexicographically less than ‘e’. 
And starting from position 1 there are 2 repeated characters(2 ‘e’ and 2 ‘t’). 
Hence, the number of possible smaller permutations with first letter ‘s’ and second letter smaller than ‘e’ are (1*4!)/(2!*2!).

Similarly, we can workup for all other characters.  

Step 2:
How to do big factorial multiplication and division with modulo?

'''
def getFactorials(n):
    factorials = []
    if(n == 1):
        return [0, 1]
    factorials.append(1)
    factorials.append(1)
    for i in range(2, n+1):
        value = i * factorials[i-1]
        value = int(value % 1000003)
        factorials.append(value)
    return factorials

def solve(a):
    if(len(a) == 1):
        return 1
    
    result = 0
    n = len(a)

    # create repetations array
    start = ord('A')
    end = ord('z')
    length = end - start + 1
    repetitions = []
    for i in range(length):
        repetitions.append(0)
    # print("Initialized repetitions array is: ")
    # print(repetitions)

    for i in range(len(a)):
        charIntValue = ord(a[i])
        indexValue = charIntValue - 65
        repetitions[indexValue] += 1
    
    # print("Updated repetitions value is: ")
    # print(repetitions)

    factorials = getFactorials(n)
    # print("Value of factorials is: ")
    # print(factorials)

    for i in range(n):
        mod = 1000003
        charValue = a[i]
        # print("Character: " + a[i])
        count = 0
        for j in range(i+1, n):
            if(charValue > a[j]):
                count += 1
        # print("Count: " + str(count))
        rank = n - i - 1
        # print("Rank: " + str(rank))
        if(rank <= 0):
            rank = 0
        withoutRepeats = count * factorials[rank]
        withoutRepeats = int(withoutRepeats % mod)
        # print("Without repeats: " + str(withoutRepeats))

        withRepeats = 1
        for j in range(len(repetitions)):
            withRepeats *= factorials[repetitions[j]]
            withRepeats = int(withRepeats % mod)
        # print("With repeats: " + str(withRepeats))

        for j in range(mod-2):
            withRepeats *= withRepeats
            withRepeats = int(withRepeats % mod)
        # print("With repeats after mod: " + str(withRepeats))

        actualRank = withRepeats * withoutRepeats
        actualRank = int(actualRank % mod)

        # Decrease count
        repetitionsIndex = ord(a[i]) - 65
        repetitions[repetitionsIndex] -= 1

        result += actualRank
        result = int(result % mod)
        # print()

    # Actual rank is +1
    result += 1
    result = int(result % mod)
    return result

a = "MTrsfRcPnqhTOpMiTlgxtNePVPsvzONuzpQhCVUEdbXXZRygRASyvlaYlyXQzlLKIcoudZSQGNDimOiLZnthPlEAyPJSxPbUEWyJmYaGwxeCdVMGHVdaSqWBxddneOFdvesReQJPwgWvWsRpKCNLxCojQaGeZnTFcMekFcyNGtxXrOuODPJYqBkmKSoFmvocVTWBSdeaadDCpFArGwvtyTITGOoVNTGifHRDcBGqVUxOCdpYieKPNObMUchYCdbcgDDTKEycRaJPIfzJFxTeLUBGYccIVviXifAUFuBwtmuuDkbUhiqnmahEldaHhupOJUokLOztOECPgVSgxqqsSWgovSGVnkELsygdoeUIgoIguZqAbeHFwuphiaDdGRjNnleusCvXuQCBjfADGwpzgwNxWFqciJGkOIwpf"
result = solve(a)
print("Result: " + str(result))