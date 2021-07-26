# Print how many ways?

def gridTraveler(m,n):
	table = [[]] * (m+1)
	for i in range(len(table)):
		table[i] = [0] * (n+1)
	
	# Since we need count, we can initialize all to zero
	# When either m or n is 0, the number of ways to travel is also equal to 0.

	# base case m ==1, and n == 1. The number of ways to travel is 1
	table[1][1] = 1

	for i in range(m+1):
		for j in range(n+1):
			if i + 1 <= m:
				table[i+1][j] += table[i][j]
			if j + 1 <= n:
				table[i][j+1] += table[i][j]
	return table[m][n]

print(gridTraveler(1,1)) # 1
print(gridTraveler(2,2)) # Some value
print(gridTraveler(3,3))
print(gridTraveler(4,3))
print(gridTraveler(4,4))
print(gridTraveler(10,10))
print(gridTraveler(20,20))
print(gridTraveler(50,50))