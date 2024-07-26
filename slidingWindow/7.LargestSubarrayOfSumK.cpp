/**
 * Largest Subarray of Sum K
 * 
 * arr: 4 1 1 1 2 3 5
 * Sum: 5
 * 
 * Find all subarrays first whose sum is 5, and we need to find the maximum value.
 * 
 * To solve this, 
 * while running the window, 
 * we keep on storing the value of sum.
 * Wherever j is going, we will ge incrementing sum.
 * As soon as we get sum value as input, we got at least one output.
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int largestSubarrayOfSumK(vector<int>&input, int sum) {
    int output = 0;

    int i=0,j=0;
    int currentSum = 0;
    while(j < input.size()) {
        if(currentSum < sum) {
            currentSum = currentSum + input[j];
            j++;
        } else if(currentSum == sum) {
            // possible solution
            int windowSize = j-i+1;
            if(windowSize > output) {
                output = windowSize;
            }

            currentSum = currentSum + input[j];
            j++;
        } else if(currentSum > sum) {
            currentSum = currentSum - input[i];
            i++;
        }
    }
    return output-1;
}

int main() {
    vector<int> input = vector<int>({4,1,1,1,2,3,5});
    cout << "Input vector: " << endl;
    printVector(input);
 
    int sum = 8;
    cout << "Sum provided: " << sum << endl;

    int output = largestSubarrayOfSumK(input, sum);
    cout << "Output: " << output << endl;

    return 0;
}

