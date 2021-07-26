def uglyNumbers(n):
    if n == 1:
        return 1
    multipleOf2 = 1
    multipleOf3 = 1
    multipleOf5 = 1
    for i in range(1, n):
        num = min(2*multipleOf2, 3*multipleOf3, 5*multipleOf5)
        if num == 2*multipleOf2:
            multipleOf2 += 1
        if num == 3*multipleOf3:
            multipleOf3 += 1
        if num == 5*multipleOf5:
            multipleOf5 += 1
    return num

print(uglyNumbers(1))
print(uglyNumbers(2))
print(uglyNumbers(3))
print(uglyNumbers(6))
print(uglyNumbers(10))
print(uglyNumbers(50))
print(uglyNumbers(100))
print(uglyNumbers(200))