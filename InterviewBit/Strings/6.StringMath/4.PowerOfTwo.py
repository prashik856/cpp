'''
Find if Given number is power of 2 or not. 

More specifically, find if given number can be expressed as 2^k where k >= 1.

Input:

number length can be more than 64, which mean number can be greater than 2 ^ 64 (out of long long range)
Output:

return 1 if the number is a power of 2 else return 0

Example:

Input : 128
Output : 1
'''

'''
Editiorial Solution:
Man, c++ solution is not even working.
Even with java, we might need to use BigIntegers.

'''
class Solution:
	# @param A : string
	# @return an integer
	def power(self, A):
        if A == "1":
            return 0
        # How is this working?
        x = int(A)
        count = 0
        
        while x:
            count+=1
            # This is a really cool way of dividing a number by 2
            x = x & (x-1)
        
        if count == 1:
            result = 1
        else:
            result = 0
        return result
