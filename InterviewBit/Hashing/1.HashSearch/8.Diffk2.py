'''
I ran the same fucking code in cpp and it didn't work.
Fuck you IB.
'''
def diffPossible(a, b):
    result = 0
    mapping = {}
    for i in range(len(a)):
        val = a[i]
        if val in mapping.keys():
            mapValue = mapping[val]
            mapValue.append(i+1)
        else:
            mapping[val] = [i+1]
    
    # Check my map
    # for i in range(len(a)):
    #     val = a[i]
    #     print(val)
    #     print(mapping[val])
    
    for i in range(len(a)):
        val = a[i]
        valToFind = a[i] - b
        if valToFind in mapping.keys():
            mapValue = mapping[valToFind]
            for j in range(len(mapValue)):
                indexValue = mapValue[j] - 1
                if(indexValue != i):
                    return 1

    return result


a = [1, 5, 2]
b = 3
result = diffPossible(a,b)
print("Result: " + str(result))