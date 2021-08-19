a = 'abcd'
b = 'cdab'
for i in range(1,len(a)):
    afront = a[0:i]
    aback = a[i:len(a)]
    print(afront)
    print(aback)
    print()

    bfront = b[0:len(a)-i]
    bback = b[len(a)-i:len(a)]
    print(bfront)
    print(bback)
    print()
