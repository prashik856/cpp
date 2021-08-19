'''
Scramble String Memoization:

Flow:
1. Problem Statement
2. Why memoization needed?
3. Table/map?
4. Code

Rather than using a table, we want to use the map.
It would be better in this case!

When entering the solve function, we will see if the 
subtree is already calculated.
if it is, we will return that value.
if not, we will calculate it.

'''
mp = {}

def solve(a,b):
    key = a + " " + b
    # If key is already present
    if key in mp:
        return mp[key]
    
    # If length not equal
    if len(a) != len(a):
        return False
    
    # if single element
    if len(a) <= 1:
        if a[0] == b[0]:
            mp[key] = True
            return True
        else:
            mp[key] = False
            return False

    # If both equal
    if a == b:
        mp[key] = True
        return True
    
    flag = False
    for i in range(1, len(a)):
        # Case 1: not swapped
        afront = a[0:i]
        aback = a[i:len(a)]
        bfront = b[0:i]
        bback = b[i:len(b)]
        case1 = solve(afront, bfront) and solve(aback, bback)

        # Case 2 : swapped
        afront = a[0:i]
        aback = a[i:len(a)]
        bback = b[len(b)-i:len(b)]
        bfront = b[0:len(b)-i]
        case2 = solve(afront, bback) and solve(aback, bfront)

        # save our value
        if case1 or case2:
            flag = True
            break
    
    mp[key] = flag
    return flag



a = "great"
b = "rgeat"
print(mp)
result = solve(a,b)
print(mp)
print("Value of result is: ")
print(result)