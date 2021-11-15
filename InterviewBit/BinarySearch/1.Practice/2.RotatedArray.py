'''
Suppose a sorted array A is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array will not contain duplicates.

NOTE 1: Also think about the case when there are duplicates. Does your current solution work? How does the time complexity change?*
PROBLEM APPROACH:

Note: If you know the number of times the array is rotated, then this problem becomes trivial. If the number of rotation is x, then minimum element is A[x].

Lets look at how we can calculate the number of times the array is rotated.

Complete solution in the hints.
'''

'''
Solution Approach:

We do this using binary search:
Case 1:
When our array is already sorted:
while low < high:
    # This case signifies that our array is sorted.
    if (A[low] <= A[high]) 
        return A[low]; // Case 1
                
    int mid = (low + high) / 2;
    int next = (mid + 1) % len;
    int prev = (mid + len - 1) % len;
                            
    # We reached pivot point.
    if (A[mid] <= A[next] && A[mid] <= A[prev]) // Case 2
        return A[mid];
    
    # Low value
    else if (A[mid] <= A[high]) 
        high = mid - 1; // Case 3

    # High value
    else if (A[mid] >= A[low]) 
        low = mid + 1; // Case 4

Need to take care of base case as well.
'''
def solve(a):
    if(len(a) == 1):
        return a[0]
    n = len(a)
    low = 0
    high = len(a) - 1
    minValue = -1
    while(low <= high):
        if(a[low] <= a[high]):
            return a[low]
        
        mid = int((low+high)/2)
        nextIndex = ( mid + 1 ) % n
        prevIndex = (mid - 1) % n

        if(a[nextIndex] >= a[mid] and a[prevIndex] >= a[mid]):
            return a[mid]
        elif(a[mid] >= a[low]):
            low = mid + 1
        elif(a[mid] <= a[high]):
            high = mid - 1
    return minValue

a = [4, 5, 6, 7, 0, 1, 2]
result = solve(a)
print("Result: " + str(result))