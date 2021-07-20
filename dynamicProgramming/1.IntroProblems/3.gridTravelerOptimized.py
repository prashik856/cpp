'''
Do we have some duplicates?
Yeah. Subtree (1,2) is being called twice.
Asking the total number of ways to travel (1,2) is the same as number of ways to travle from (2,1)
So gridTraveler(a,b) = gridTraveler(b,a)
'''

def gridTraveler(m,n, memo={}):
	# we need a separator because we need unique keys
	key = str(m) + "-" + str(n)

	# are the args in the memo
	if key in memo:
		return memo[key]
	# base cases
	if( m == 1 and n == 1):
		return 1
	if( m == 0 or n == 0):
		return 0

	memo[key] = gridTraveler(m-1,n, memo) + gridTraveler(m, n-1, memo)
	return memo[key]
	

print(gridTraveler(1,1))
print(gridTraveler(2,3))
print(gridTraveler(3,2))
print(gridTraveler(3,3))
print(gridTraveler(18,18)) # 18x18 will time out 
# Very quick now
'''
What are the new time complexities now?
for m = 4
m : {0,1,2,3,4}
n : {0,1,2,3}
n * m possible combinations

Memoized: O(m * n) time
O(n + m): Space

Very much faster

Try to visualize our Problem in terms of a tree
using that tree, we can visualize how we can reduce the number of problems that we have in our problem.
That way we can also reach to an optimal solution
'''

