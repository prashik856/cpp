/*
https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
Kadane’s Algorithm:

Initialize:
    max_so_far = INT_MIN
    max_ending_here = 0

Loop for each element of the array
  (a) max_ending_here = max_ending_here + a[i]
  (b) if(max_so_far < max_ending_here)
            max_so_far = max_ending_here
  (c) if(max_ending_here < 0)
            max_ending_here = 0
return max_so_far
*/

/*

Find the contiguous subarray within an array, A of length N which has the largest sum.

Input Format:

The first and the only argument contains an integer array, A.
Output Format:

Return an integer representing the maximum possible sum of the contiguous subarray.
Constraints:

1 <= N <= 1e6
-1000 <= A[i] <= 1000
For example:

Input 1:
    A = [1, 2, 3, 4, -10]

Output 1:
    10

Explanation 1:
    The subarray [1, 2, 3, 4] has the maximum possible sum of 10.

Input 2:
    A = [-2, 1, -3, 4, -1, 2, 1, -5, 4]

Output 2:
    6

Explanation 2:
    The subarray [4,-1,2,1] has the maximum possible sum of 6.
*/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> A) {
    int maxSum = numeric_limits<int>::min();
    int maxSumSoFar = 0;

    for(int i=0; i<A.size(); i++) {
        maxSumSoFar += A[i];

        maxSum = max(maxSum, maxSumSoFar);

        if(maxSumSoFar < 0) {
            maxSumSoFar = 0;
        }
    }

    return maxSum;
}

int main() {
    int t;
    cin >> t;
    for(int z=0; z<t; z++) {
        int n; 
        cin >> n;
        cout << n << endl;
        vector<int> arr;
        cout << "Given input array is: " << endl;
        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            arr.push_back(temp);
            cout << temp << " ";
        }
        cout << endl;

        int result = solve(arr);
        cout << "Result: " << result << endl;;
        cout << endl;
    }
    return 0;
}