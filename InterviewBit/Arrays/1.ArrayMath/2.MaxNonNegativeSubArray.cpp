/*
Problem Description

Given an array of integers, A of length N, find out the maximum sum sub-array of non negative numbers from A.

The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array.

Find and return the required subarray.

NOTE:  

If there is a tie, then compare with segment's length and return segment which has maximum length.
If there is still a tie, then return the segment with minimum starting index.


Problem Constraints
1 <= N <= 105

-109 <= A[i] <= 109



Input Format
The first and the only argument of input contains an integer array A, of length N.



Output Format
Return an array of integers, that is a subarray of A that satisfies the given conditions.



Example Input
Input 1:

 A = [1, 2, 5, -7, 2, 3]
Input 2:

 A = [10, -1, 2, 3, -4, 100]


Example Output
Output 1:

 [1, 2, 5]
Output 2:

 [100]


Example Explanation
Explanation 1:

 The two sub-arrays are [1, 2, 5] [2, 3].
 The answer is [1, 2, 5] as its sum is larger than [2, 3].
Explanation 2:

 The three sub-arrays are [10], [2, 3], [100].
 The answer is [100] as its sum is larger than the other two.
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A){
A.push_back(-1);

    long currentSum = 0;
    long currentLenght = 0;
    int startingIndex = 0;
    int endingIndex = 0;


    vector<int> result;
    long maxSum = 0;
    long maxLength = 0;
    int resultStartingIndex = 1000000;
    int resultEndingIndex = 1000000;

    for(int i=0; i<A.size(); i++){
        if(A[i] < 0){
            // set ending index
            endingIndex = i;

            // We need to break our subarray here
            if(maxSum < currentSum) {
                // update indices
                resultStartingIndex = startingIndex;
                resultEndingIndex = endingIndex;
                maxSum = currentSum;
                maxLength = currentLenght;
            }

            else if(maxSum == currentSum) {
                if(currentLenght > maxLength) {
                    // set our result parameters
                    maxLength = currentLenght;
                    resultStartingIndex = startingIndex;
                    resultEndingIndex = endingIndex;
                }
            }

            currentSum = 0;
            currentLenght = 0;
        }

        else {
            // starting index
            if(currentLenght == 0){
                startingIndex = i;
            }

            currentLenght++;
            currentSum = currentSum + A[i];
        }
    }

    // Create result array
    if(resultStartingIndex == 1000000){
        return result;
    }

    for(int i=resultStartingIndex; i<resultEndingIndex; i++){
        result.push_back(A[i]);
    }

    return result;
}

int main(){
    int t;
    cin >> t;
    for(int z=0; z<t; z++){
        cout << "Case: " << z << endl;
        int n;
        cin >> n;
        vector<int> arr;
        cout << "Given array is: " << endl;
        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            arr.push_back(temp);
            cout << temp << " ";
        }
        cout << endl << endl;

        vector<int> result = solve(arr);
        cout << "Result Obtained is: " << endl;
        for(int i=0; i<result.size(); i++){
            cout << result[i] << " ";
        }
        cout << endl << endl;
    }

}