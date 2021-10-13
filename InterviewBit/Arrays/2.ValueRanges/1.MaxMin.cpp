/*
Problem Description

Given an array A of size N. You need to find the sum of Maximum and Minimum element in the given array.

NOTE: You should make minimum number of comparisons.



Problem Constraints
1 <= N <= 105

-109 <= A[i] <= 109



Input Format
First and only argument is an integer array A of size N.



Output Format
Return an integer denoting the sum Maximum and Minimum element in the given array.



Example Input
Input 1:

 A = [-2, 1, -4, 5, 3]
Input 2:

 A = [1, 3, 4, 1]


Example Output
Output 1:

 1
Output 2:

 5


Example Explanation
Explanation 1:

 Maximum Element is 5 and Minimum element is -4. (5 + (-4)) = 1. 
Explanation 2:

 Maximum Element is 4 and Minimum element is 1. (4 + 1) = 5.
*/
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr) {
    int n = arr.size();
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

long solve(vector<int> &A) {
    int n = A.size();
    int minValue = numeric_limits<int>::max();
    int maxValue = numeric_limits<int>::min();

    long result = 0;

    for(int i=0; i<n; i++){
        minValue = min(minValue, A[i]);
        maxValue = max(maxValue, A[i]);
    }

    result = (long) minValue + (long) maxValue;

    return result;
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

        long result = solve(arr);
        cout << "Result: " << result << endl;;
        cout << endl;
    }
    return 0;
}