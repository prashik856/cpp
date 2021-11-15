'''
Problem Description

Given a sorted array A and a target value B, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.



Problem Constraints
1 <= |A| <= 100000

1 <= B <= 109



Input Format
First argument is array A.

Second argument is integer B.



Output Format
Return an integer, the answer to the problem.



Example Input
Input 1:

 A = [1, 3, 5, 6]
B = 5
Input 2:

 A = [1, 3, 5, 6]
B = 2


Example Output
Output 1:

 2
Output 2:

 1


Example Explanation
Explanation 1:

 5 is found at index 2.
Explanation 2:

 2 will be inserted ar index 1.
'''

'''
Easy enough:
Take care of greater or smaller condition.
'''
def binarySearch(A, B, n):
    low = 0
    high = n - 1
    while(low < high):
        mid = low + high
        mid = int(mid/2)
        if(A[mid] == B):
            return mid
        
        if(B > A[mid]):
            low = mid + 1
        else:
            high = mid - 1
    return low

def solve(A, B):
    result = -1
    n = len(A)
    index = binarySearch(A, B, n)
    if(A[index] == B):
        return index

    if(B > A[index]):
        return index + 1
    
    if(B < A[index]):
        result = index
        return result

    return result

A = [ 3, 4, 18, 19, 20, 27, 28, 31, 36, 42, 44, 71, 72, 75, 82, 86, 88, 97, 100, 103, 105, 107, 110, 116, 118, 119, 121, 122, 140, 141, 142, 155, 157, 166, 176, 184, 190, 199, 201, 210, 212, 220, 225, 234, 235, 236, 238, 244, 259, 265, 266, 280, 283, 285, 293, 299, 309, 312, 317, 335, 341, 352, 354, 360, 365, 368, 370, 379, 386, 391, 400, 405, 410, 414, 416, 428, 433, 437, 438, 445, 453, 457, 458, 472, 476, 480, 485, 489, 491, 493, 501, 502, 505, 510, 511, 520, 526, 535, 557, 574, 593, 595, 604, 605, 612, 629, 632, 633, 634, 642, 647, 653, 654, 656, 658, 686, 689, 690, 691, 709, 716, 717, 737, 738, 746, 759, 765, 775, 778, 783, 786, 787, 791, 797, 801, 806, 815, 820, 822, 823, 832, 839, 841, 847, 859, 873, 877, 880, 886, 904, 909, 911, 917, 919, 937, 946, 948, 951, 961, 971, 979, 980, 986, 993 ]
B = 902

result = solve(A, B)
print("Result: " + str(result))