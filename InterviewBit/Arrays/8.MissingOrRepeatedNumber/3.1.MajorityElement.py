'''
Majority Element
https://www.geeksforgeeks.org/majority-element/
Write a function which takes an array and prints the majority element (if it exists), otherwise prints “No Majority Element”. 

A majority element in an array A[] of size n is an element that appears more than n/2 times (and hence there is at most one such element). 

Examples:
Input : {3, 3, 4, 2, 4, 4, 2, 4, 4}
Output : 4
Explanation: The frequency of 4 is 5 which is greater
than the half of the size of the array size. 

Input : {3, 3, 4, 2, 4, 4, 2, 4}
Output : No Majority Element
Explanation: There is no element whose frequency is
greater than the half of the size of the array size.
'''
'''
Method1:
Approach: The basic solution is to have two loops and keep track of the maximum count for all different elements. If maximum count becomes greater than n/2 then break the loops and return the element having maximum count. If the maximum count doesn’t become more than n/2 then the majority element doesn’t exist.
Algorithm: 
Create a variable to store the max count, count = 0
Traverse through the array from start to end.
For every element in the array run another loop to find the count of similar elements in the given array.
If the count is greater than the max count update the max count and store the index in another variable.
If the maximum count is greater than the half the size of the array, print the element. Else print there is no majority element.
O(n^2) solution

Method2:
METHOD 2 (Using Binary Search Tree) 

Approach: Insert elements in BST one by one and if an element is already present then increment the count of the node. At any stage, if the count of a node becomes more than n/2 then return.
Algorithm: 
Create a binary search tree, if same element is entered in the binary search tree the frequency of the node is increased.
traverse the array and insert the element in the binary search tree.
If the maximum frequency of any node is greater than the half the size of the array, then perform a inorder traversal and find the node with frequency greater than half
Else print No majority Element.
O(n^2) if BST
O(nlogn) if Self adjusting BST
O(n) space


METHOD 3 (Using Moore’s Voting Algorithm):   
Approach: This is a two-step process. 
The first step gives the element that maybe the majority element in the array. If there is a majority element in an array, then this step will definitely return majority element, otherwise, it will return candidate for majority element.
Check if the element obtained from the above step is majority element. This step is necessary as there might be no majority element.

Algorithm: 
Loop through each element and maintains a count of majority element, and a majority index, maj_index
If the next element is same then increment the count if the next element is not same then decrement the count.
if the count reaches 0 then changes the maj_index to the current element and set the count again to 1.
Now again traverse through the array and find the count of majority element found.
If the count is greater than half the size of the array, print the element
Else print that there is no majority element
Complexity Analysis: 

Time Complexity: O(n). 
As two traversal of the array is needed, so the time complexity is linear.
Auxiliary Space: O(1). 
As no extra space is required.


 METHOD 4 (Using Hashmap): 

Approach: This method is somewhat similar to Moore voting algorithm in terms of time complexity, but in this case, there is no need for the second step of Moore voting algorithm. But as usual, here space complexity becomes O(n). 
In Hashmap(key-value pair), at value, maintain a count for each element(key) and whenever the count is greater than half of the array length, return that key(majority element). 
 
Algorithm:
Create a hashmap to store a key-value pair, i.e. element-frequency pair.
Traverse the array from start to end.
For every element in the array, insert the element in the hashmap if the element does not exist as key, else fetch the value of the key ( array[i] ), and increase the value by 1
If the count is greater than half then print the majority element and break.
If no majority element is found print “No Majority element”
O(n)
and O(n)
'''

def mooresVotingAlgorithm(A):
    result = 0

    # First loop
    # finding majority
    maj_index = 0
    count = 1
    for i in range(1, len(A)):
        if(A[maj_index] == A[i]):
            count += 1
        else:
            count -= 1

        if(count <= 0):
            maj_index = i
            count = 1
            
    print("Majority index is: " + str(maj_index))
    print("Majority value is: " + str(A[maj_index]))


    # Check if maj_index is actually majority
    count = 0
    for i in range(0, len(A)):
        if(A[maj_index] == A[i]):
            count += 1
    
    if(count > int(len(A)/2)):
        result = 1
    else:
        result = -1
    
    return result

A = [3, 3, 4, 2, 4, 4, 2, 4, 4]
result = mooresVotingAlgorithm(A)
print("Result: " + str(result))