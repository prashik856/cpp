'''
Rearrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space.

Example:

Input : [1, 0]
Return : [0, 1]
Lets say N = size of the array. Then, following holds true :

All elements in the array are in the range [0, N-1]
N * N does not overflow for a signed integer
'''

'''
Solution Approach:
https://www.geeksforgeeks.org/rearrange-given-array-place/
Approach: The array elements of the given array lies from 0 to n-1. 
Now an array element is needed that can store two different values at the same time. 
To achieve this increment every element at ith index is incremented by (arr[arr[i]] % n)*n.
After the increment operation of first step, every element holds both old values and new values. 
Old value can be obtained by arr[i]%n and a new value can be obtained by arr[i]/n.

How this can be achieved? 
Let’s assume an element is a and another element is b, 
both the elements are less than n. 
So if an element a is incremented by b*n. 
So the element becomes a + b*n so when a + b*n is divided by n then the value is b and a + b*n % n is a.

'''
def solve(a):
    for i in range(len(a)):
        n = len(a)
        index = int(a[i] % n)
        # print("Index: " + str(index))
        if(index == n):
            index = 0
        # print("Value at index: " + str(a[index]))
        previousValue = int(a[index] % n)
        # print("Previous value: " + str(previousValue))
        valueToAdd = previousValue * n
        # print("Value to add: " + str(valueToAdd))
        a[i] += valueToAdd
        # print()
    # print("Array after incrementing")
    # print(a)

    for i in range(len(a)):
        a[i] = int(a[i]/n)

    return a

a = [1, 0, 2, 5, 4, 3]
print("Input array: ")
print(a)
result = solve(a)
print("Result: ")
print(result)