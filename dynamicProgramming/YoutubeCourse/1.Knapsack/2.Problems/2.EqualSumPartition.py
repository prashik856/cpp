'''
Equal Sum Partition Problem

Flow:
1. Problem Statement
2. Subset sum problem and how these are similar
3. Odd/Even significance
4. Code Variation.

1. Problem Statement
arr: 1 5 11 5
O/P: T/F
Given array
Output: True or False
Divide the array in two subsets such that their sum value is equal

So, given two partitions, arr1 and arr2, and their sum1 and sum2.
Sum1 == sum2.

2.Subset sum and similarities
Given array such that it's sum is equal to the value of sum.
boolean subsetSum(int arr[], int Sum, int n)
Output is True or False.
We know how everything goes...
Create table, initialize value, and fill values using choices.

Similarity is that, we need to find subset and sum in both questions.
We have some similartities here.

Assuming that we partition array in two parts.
say S1 and S2.
If S1 and S2 are supposed to be equal, their value should be 2*S.
And that means, the value of sum of the array should always be an even number.

First Condition:
if the sum of array is not even, return False.
This will be the first step.

long sum = 0
for(i in arr):
    sum += sum
if sum % 2 != 0:
    return False
else :
    // sum is even, we can move forward
    // Need to think now for even sum
    Assuming our sum value is S, we need to find 
    ONLY ONE partition now whose value is equal to 
    S/2. since S is even, S/2 is int.
    Thus reducing our Question and the next
    recursion call.
    We need to find just one subset from that array, 
    we will get the another subset automatically.

So our reduced problem is this:
get sumValue
if sum %2 != 0:
    return False
else:
    get the subset of value S/2 from this array
    // just checking if we have a subset whose value is equal to sum/2
    return SubsetSum(arr, sum/2);

Now, our input is:
arr: 
len(arr)

for(int i=0; i<n; i++){
    sum += arr[i]
}

if(sum %2 != 0){
    return False;
}

else {
    return subsetSum(arr, sum/2)
}

'''

def SubsetSum(arr, sumValue):
    n = len(arr)
    table = []
    for i in range(n + 1):
        table.append([])
        for j in range(sumValue + 1):
            table[i].append(False)
            if i == 0:
                table[i][j] = False
            if j == 0:
                # if sum is 0, possible
                table[i][j] = True

    for i in range(1, n+1):
        for j in range(1, sumValue + 1):
            if(arr[i-1] > sumValue):
                table[i][j] = table[i-1][j]
            else :
                table[i][j] = table[i-1][j] or table[i-1][j - arr[i-1]]
    print(table)
    return table[n][sumValue]

arr = [1,5,11,1]
n = len(arr)
sumValue = 0
for i in range(n):
    sumValue += arr[i]
print("Sum Value is: " + str(sumValue))

result = False
if(sumValue % 2 != 0):
    result = False
else:
    result = SubsetSum(arr, int(sumValue/2))
print("Result value: ")
print(result)

'''
We got our code!!!!
Simple code
Knapsack -> Subset sum -> Equal sum partition

Good question.
'''