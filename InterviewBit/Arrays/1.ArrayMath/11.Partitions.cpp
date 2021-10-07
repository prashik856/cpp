/*
Problem Description

You are given a 1D integer array B containing A integers.

Count the number of ways to split all the elements of the array into 3 contiguous parts so that the sum of elements in each part is the same.

Such that : sum(B[1],..B[i]) = sum(B[i+1],...B[j]) = sum(B[j+1],...B[n]) 



Problem Constraints
1 <= A <= 105

-109 <= B[i] <= 109



Input Format
First argument is an integer A.

Second argument is an 1D integer array B of size A.



Output Format
Return a single integer denoting the number of ways to split the array B into three parts with the same sum.



Example Input
Input 1:

 A = 5
 B = [1, 2, 3, 0, 3]
Input 2:

 A = 4
 B = [0, 1, -1, 0]


Example Output
Output 1:

 2
Output 2:

 1


Example Explanation
Explanation 1:

 There are no 2 ways to make partitions -
 1. (1,2)+(3)+(0,3).
 2. (1,2)+(3,0)+(3).
Explanation 2:

 There is only 1 way to make partition -
 1. (0)+(-1,1)+(0).
*/

/**
 * Solution approach:
 * https://www.geeksforgeeks.org/count-the-number-of-ways-to-divide-an-array-into-three-contiguous-parts-having-equal-sum/
 * */

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr) {
    int n = arr.size();
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int solve(vector<int> &A) {
    int n = A.size();
    int result = 0;

    vector<int> prefix(n,0);
    vector<int> suffix(n,0);

    // Step1: Create Prefix array
    int sumValue = 0;
    for(int i=0; i<A.size(); i++){
        sumValue += A[i];
        prefix[i] = sumValue;
    }
    // Step 0: if sum of all elements is not divisible by 3, return 0.
    if(sumValue % 3 != 0) {
        return 0;
    }

    int comparisonValue = sumValue/3;

    // Step 2: Create suffix array.
    vector<int> possibleIndices;
    sumValue = 0;
    for(int i=n-1; i>=0; i--){
        sumValue += A[i];
        suffix[i] = sumValue;
    }

    // Step 3: Find all possible indixes in suffix array whose value is sumValue/3
    for(int i=0; i<suffix.size(); i++){
        if(suffix[i] == comparisonValue){
            possibleIndices.push_back(i);
        }
    }
    
    // cout << "Prefix Array: " << endl;
    // printVector(prefix);

    // cout << "Suffix Array: " << endl;
    // printVector(suffix);

    // cout << "Possible Index Array: " << endl;
    // printVector(possibleIndices);

    vector<int>::iterator itr;
    // Step 4: Traverse the prefix array, find the value equal to sumValue/3
    for(int i=0; i<n; i++){
        int value = prefix[i];
        if(prefix[i] == comparisonValue){
            // Step 5: If a value is found i, we need to get count of all possible indices
            // whose value is greater than i + i 
            // this can be achieved by upperbound
            // cout << "Index value: " << i << endl;
            // Use the upperbound function here.
            itr = upper_bound(possibleIndices.begin(), possibleIndices.end(), i+1);
            if(itr != possibleIndices.end()) {
                // cout << "Iterator value: " << (*itr) << endl;
                result += possibleIndices.end() - itr;
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