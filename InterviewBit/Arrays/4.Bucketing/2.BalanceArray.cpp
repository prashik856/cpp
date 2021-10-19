/*
Problem Description

Given an integer array A of size N. You need to count the number of special elements in the given array.

A element is special if removal of that element make the array balanced.

Array will be balanced if sum of even index element equal to sum of odd index element.



Problem Constraints
1 <= N <= 105

1 <= A[i] <= 109



Input Format
First and only argument is an integer array A of size N.



Output Format
Return an integer denoting the count of special elements.



Example Input
Input 1:

 A = [2, 1, 6, 4]
Input 2:

 A = [5, 5, 2, 5, 8]


Example Output
Output 1:

 1
Output 2:

 2


Example Explanation
Explanation 1:

 After deleting 1 from array : {2,6,4}
    (2+4) = (6)
 Hence 1 is the only special element, so count is 1
Explanation 2:

 If we delete A[0] or A[1] , array will be balanced
    (5+5) = (2+8)
 So A[0] and A[1] are special elements, so count is 2.
*/

/*
Solution Approach:
Make use of Odd and Even sum prefix array.
Using these two arrays, get the proper value of oddsum and evenSum when any element is removed.
*/

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<long> arr) {
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int solve(vector<int> arr){
    int result = 0;
    int n = arr.size();
    vector<long> oddSum(n, 0);
    vector<long> evenSum(n, 0);

    long currentOddSum = 0;
    long currentEvenSum = 0;
    for(int i=0; i<n; i++){
        if(i%2 == 0){
            currentEvenSum = currentEvenSum + arr[i];
        } else {
            currentOddSum = currentOddSum + arr[i];
        }
        evenSum[i] = currentEvenSum;
        oddSum[i] = currentOddSum;
    }
    // cout << "Even sum array: " << endl;
    // printVector(evenSum);

    // cout << "Odd sum array: " << endl;
    // printVector(oddSum);


    for(int i=0; i<n; i++){
        int value = arr[i];
        if(i % 2 == 0){
            long eS = evenSum[i] - value;
            eS += oddSum[n-1] - oddSum[i];

            long oS = evenSum[n-1] - evenSum[i];
            oS += oddSum[i];

            if(oS == eS){
                result++;
            }
        } else {
            long eS = oddSum[n-1] - oddSum[i];
            eS += evenSum[i];

            long oS = oddSum[i] - value;
            oS += evenSum[n-1] - evenSum[i];
            if(oS == eS){
                result++;
            }
        }
    }

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

        int result = solve(arr);
        cout << "Result: " << result << endl;;
        cout << endl;
    }
    return 0;
}