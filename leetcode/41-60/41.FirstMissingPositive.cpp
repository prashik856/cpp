/**
41. First Missing Positive

Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.

Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.

Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.

Constraints:

    1 <= nums.length <= 10^5
    -2^31 <= nums[i] <= 2^31 - 1

 */
#include<bits/stdc++.h>
using namespace std;

void printVector(const vector<int> &arr) {
    for (int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int firstMissingPositive_Hard(vector<int>& nums) {
    // Replace negative nums with n+1 value
    int result = 0;

    int n = nums.size();
    for(int i=0; i<n; i++) {
        if(nums[i] <= 0 || nums[i] > n) {
            nums[i] = n+1;
        }
    }
    // cout << "Input vector after filtering" << endl;
    // printVector(nums);

    // Mark attendence
    for(int i=0; i<n; i++) {
        int val = abs(nums[i]);

        // Mark val as index to be present in the array
        // The value at index val-1 should be a negative value
        if(val >=1 && val <= n) {
            nums[val-1] = -abs(nums[val-1]);
        }
    }
    // cout << "Input vector after attendence" << endl;
    // printVector(nums);

    // Find the first positive integer and return index + 1 as the solution
    // Get the index as his attendence was missing and is positive
    for(int i=0; i<n; i++) {
        int val = nums[i];
        if(val > 0) {
            result = i + 1;
            break;
        }
    }

    if(result == 0) {
        // nums from 1 to n are present in the array of size n. So answer is n+1
        result = n+1;
    }

    return result;
}

int firstMissingPositive_Easy(vector<int>& nums) {
    // We can use dictionary;
    int n = nums.size();
    unordered_map<int, int> dict;
    int result = 0;

    for(int i=0; i<n; i++) {
        dict.insert({nums[i], 1});
    }

    for(int i=1; i<=n+1; i++) {
        if(dict.find(i) == dict.end()) {
            result = i;
            break;
        }
    }

    return result;
}

int main() {
    vector<vector<int>> inputs = {{1,2,0}, {3,4,-1,1}, {7,8,9,11,12}, {1}};
    vector<int> outputs = {3, 2, 1, 2};

    for(int i=0; i<inputs.size(); i++) {
        cout << "Inputs: " << endl;
        printVector(inputs[i]);

        int output = firstMissingPositive_Hard(inputs[i]);
        cout << "Output: " << output << endl;

        cout << "Expected output: " << outputs[i] << endl << endl;
    }

    return 0;
}