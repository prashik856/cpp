
def fibonacci(n):
	if n == 0:
		return 0
	if n == 1:
		return 1
	table = [0]*(n+1)
	#print("Length of table is: " + str(len(table)))
	# fibonacci 0 is 1
	table[0] = 0
	table[1] = 1
	
	for i in range(len(table)):
		if i+1 <= n:
			table[i + 1] += table[i]
		if i+2 <= n:
			table[i + 2] += table[i]
	return table[n]

print(fibonacci(0))
print(fibonacci(1))
print(fibonacci(2))
print(fibonacci(5))
print(fibonacci(10))
print(fibonacci(15))
print(fibonacci(50))