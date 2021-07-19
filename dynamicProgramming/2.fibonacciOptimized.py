# Optimizing fibonacci:
# We are going to use Memoization: 
# Need to use hashMap for an array of sime kind
# Keys to our object will be arg to function,
# Value will be the return value
def fib(n, memo={}):
	if n in memo:
		return memo[n]
	if n <= 2:
		return 1
	memo[n] = fib(n-1, memo) + fib(n-2, memo)
	return memo[n]
print(fib(6))
print(fib(7))
print(fib(8))
#What if we give a larger number?
print(fib(50))


# We now go back to our recursion tree and see what we have done
# fib(6) memoized
# time: O(2n) : O(n) time
# Space: O(n) 

# By memoizing, we have bought down the time complexity to linear from exponential

