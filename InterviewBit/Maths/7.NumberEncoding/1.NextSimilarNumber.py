
def solve(A):
    result = ""
    a = list(A)
    n = len(a)
    # print("Length of array is: " + str(n))
    index = -1
    for i in range(n-1, 0, -1):
        if a[i] > a[i-1]:
            index = i-1
            break
    if(index == -1):
        return "-1"
    else:
        temp = a[n-1]
        a[n-1] = a[index]
        a[index] = temp
        # print("String after replace: ")
        # print(a)

        b = a[index+1:]
        # print("Remaining string is: ")
        # print(b)

        b = sorted(b)
        # print("Remaining string after sort: ")
        # print(b)

        bIndex = 0
        for i in range(index+1, n):
            a[i] = b[bIndex]
            bIndex += 1
        
        # print("Resulting array is: ")
        # print(a)

        for i in range(n):
            result += str(a[i])

    return result

A = "892795"
print("Input string is: " + str(A))
result = solve(A)
print("Result: " + str(result))