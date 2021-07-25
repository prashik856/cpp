def fib(n):
	if(n <= 2):
 		return 1
	return fib(n-1) + fib(n-2)

# Fib falls in between dib and lib
# time complexity O(dib) < = O(fib) <= O(lib)
# O(2^n) <= O(fib) <= O(2^n)
# For Fib should have O(2^n) complexity
# O(2^n) time: O(n) space
# fib(50) = 2^50 steps : 1.12 x 10^11 
# We need to make this faster
# Need to reduce the number of recursive calls
# Let's have a look at fib(7):
# fib(3) is called 5 times
# fib(4) is called 3 times too
# fib(5) is called 2 times too
# Now, fib(5) should not change
# We want to resuse the values of fib(3) fib(4) and fib(5)
# This is a pattern of overlapping subproblems
# We need to find duplication in our recursive tree


print(fib(6))
print(fib(7))
print(fib(8))
#What if we give a larger number?
print(fib(50))


def foo(n):
	if(n <= 1):
		return
	foo(n-1)

# O(n) 

# More involved function
def bar(n):
	if(n <= 1):
		return
	bar(n-2)
# We move twice as fast
# O(n/2) time : O(n) time complexity
# O(n) space

def dib(n):
	if(n <= 1)
		return
	dib(n-1)
	dib(n-1)
# We will have a really god symmetrical tree
# height of the tree will be n
# number of levels: n (height)
# We will always have 1 level at top
# 2nd row will have 1*2 node
# For nth nodes, we will have 1*2^n nodes at the left
# O(2^n) time!
# Space complexity? : O(n) : Actually, the maximum length of stack will be exactly equal to 5.
# Space complexity is O(heighoftree) i.e. max length of stack.

def lib(n):
	if(n<=1):
		return
	lib(n-2)
	lib(n-2)

# Here will also have a base case
# Height: n/2
# Time complexity: O(2^n/2): O(2^n) time 
# Space complexity: O(n/2): O(n) space complexity

