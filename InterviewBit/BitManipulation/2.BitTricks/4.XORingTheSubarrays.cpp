/*
Problem Description

Given an integer array A of size N.

You need to find the value obtained by XOR-ing the contiguous subarrays, followed by XOR-ing the values thus obtained. Determine and return this value.

For example, if A = [3, 4, 5] :

Subarray    Operation   Result
3       None            3
4       None            4
5       None            5
3,4   3 XOR 4         7
4,5   4 XOR 5         1
3,4,5    3 XOR 4 XOR 5   2

Now we take the resultant values and XOR them together:

3 ⊕ 4 ⊕ 5 ⊕ 7 ⊕ 1⊕ 2 = 6 we will return 6.



Problem Constraints
1 <= N <= 105

1 <= A[i] <= 108



Input Format
First and only argument is an integer array A.



Output Format
Return a single integer denoting the value as described above.



Example Input
Input 1:

 A = [1, 2, 3]
Input 2:

 A = [4, 5, 7, 5]


Example Output
Output 1:

 2
Output 2:

 0


Example Explanation
Explanation 1:

 1 ⊕ 2 ⊕ 3 ⊕  (1 ⊕ 2 ) ⊕ (2 ⊕ 3) ⊕ (1 ⊕ 2 ⊕ 3) = 2
Explanation 2:

 4 ⊕ 5 ⊕ 7 ⊕ 5 ⊕ (4 ⊕ 5) ⊕ (5 ⊕ 7) ⊕ (7 ⊕ 5) ⊕ (4 ⊕ 5 ⊕ 7) ⊕ (5 ⊕ 7 ⊕ 5) ⊕ (4 ⊕ 5 ⊕ 7 ⊕ 5) = 0
*/
/*
Solution Approach:
https://www.geeksforgeeks.org/xor-subarray-xors/

First thing to learn is to get the frequency of an element in the subarrays is given by:
int freq = (i + 1) * (N - i);
Where i starts from 0 and ends at N-1.

Now, if our element is odd, we include it in our result.

Efficient solution:
An efficient solution is based on the idea to enumerate all subarrays, 
we can count the frequency of each element that occurred totally in all subarrays, 
if the frequency of an element is odd then it will be included in the final result otherwise not. 

In our example:
arr[] = [3, 5, 2, 4, 6]
As in above example, 
3 occurred 5 times,
5 occurred 8 times,
2 occurred 9 times,
4 occurred 8 times,
6 occurred 5 times
So our final result will be xor of all elements which occurred odd number of times
i.e. 3^2^6 = 7

From above occurrence pattern we can observe that number at i-th index will have 
(i + 1) * (N - i) frequency. 

So we can iterate over all elements once and calculate their frequencies and 
if it is odd then we can include that in our final result by XORing it with the result. 

*/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> arr){
    int result =0;
    int n = arr.size();
    for(int i=0; i<n; i++){
        int frequency = (i+1)*(n-i);

        if(frequency % 2 == 1){
            result = result ^ arr[i];
        }
    }

    return result;
}

int main(){
    vector<int> a = {3, 4, 5};
    int result = solve(a);
    cout << "Result is: " << result << endl;
    return 0;
}
