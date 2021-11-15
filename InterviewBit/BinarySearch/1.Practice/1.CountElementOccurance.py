'''
Given a sorted array of integers, find the number of occurrences of a given target value.

Your algorithm’s runtime complexity must be in the order of O(log n).

If the target is not found in the array, return 0

**Example : **

Given [5, 7, 7, 8, 8, 10] and target value 8,

return 2.

PROBLEM APPROACH :

For complete solution, look at the hint.
'''
'''
Use binary search to get the index first.
And then we will count the occurance
'''
def lowerBound(a, b):
    low = 0
    high = len(a) - 1
    while(low < high):
        mid = int((low + high)/2)
        if(b == a[mid]):
            return mid
        
        if( b > a[mid]):
            low = mid + 1
        else:
            high = mid - 1
    return low

def solve(a, b):
    result = 0
    searchIndex = lowerBound(a, b)
    # print("Search index value is: " + str(searchIndex))

    if(a[searchIndex] == b):
        temp = searchIndex
        count = 0
        while(temp < len(a) and a[temp] == b):
            count += 1
            temp += 1
        
        temp = searchIndex - 1
        while(temp >= 0 and a[temp] == b):
            count += 1
            temp -= 1
        result = count
    else:
        result = 0
    return result

a = [1]
b = 1

result = solve(a, b)
print("Result is: " + str(result))