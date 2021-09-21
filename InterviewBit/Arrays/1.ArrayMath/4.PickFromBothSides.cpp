/*
Problem Description

Given an integer array A of size N.

You can pick B elements from either left or right end of the array A to get maximum sum.

Find and return this maximum possible sum.

NOTE: Suppose B = 4 and array A contains 10 elements then

You can pick first four elements or can pick last four elements or can pick 1 from front and 3 from back etc . you need to return the maximum possible sum of elements you can pick.


Problem Constraints
1 <= N <= 105

1 <= B <= N

-103 <= A[i] <= 103



Input Format
First argument is an integer array A.

Second argument is an integer B.



Output Format
Return an integer denoting the maximum possible sum of elements you picked.



Example Input
Input 1:

 A = [5, -2, 3 , 1, 2]
 B = 3
Input 2:

 A = [1, 2]
 B = 1


Example Output
Output 1:

 8
Output 2:

 2


Example Explanation
Explanation 1:

 Pick element 5 from front and element (1, 2) from back so we get 5 + 1 + 2 = 8
Explanation 2:

 Pick element 2 from end as this is the maximum we can get
*/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B){
    int n = A.size();
    vector<long> frontSum;
    vector<long> backSum;

    cout << "Front sum array: " << endl;
    long currentSum = 0;
    for(int i=0; i<n; i++){
        currentSum += A[i];
        frontSum.push_back(currentSum);
        cout << currentSum << " ";
    }
    cout << endl;

    cout << "Back sum array: " << endl;
    currentSum = 0;
    for(int i=n-1; i>=0; i--){
        currentSum += A[i];
        backSum.push_back(currentSum);
        cout << currentSum << " ";
    }
    cout << endl;

    int result = numeric_limits<int>::min();

    currentSum = 0;
    // let's take first B elements
    currentSum = frontSum[B-1];

    result = max((long)result, currentSum);

    // let's take first B-1 elements 
    currentSum = backSum[B-1];
    result = max((long)result, currentSum);

    currentSum = 0;
    for(int i=0; i<B-1; i++){
        currentSum += frontSum[i];
        currentSum += backSum[B-2-i];
        result = max((long)result, currentSum);
        currentSum = 0;
    }

    return result;
}

int main(){
    int t;
    cin >> t;
    for(int z=0; z<t; z++) {
        int n, b; 
        cin >> n >> b;
        vector<int> arr;
        cout << "Given input array is: " << endl;
        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            arr.push_back(temp);
            cout << temp << " ";
        }
        cout << endl;

        int result = solve(arr, b);
        cout << "Result: " << result << endl;;
        cout << endl;
    }
}