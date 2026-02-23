/*
Given an integer array nums of length n and an integer target, find three integers at distinct indices in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

Constraints:

    3 <= nums.length <= 500
    -1000 <= nums[i] <= 1000
    -10^4 <= target <= 1^04

 */
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &arr) {
    for (int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int getClosestValue(vector<int> &nums, int target, int i, int j , int k) {
    int result = -1;
    int current_max = INT_MAX;
    while (j < k) {
        int currentSum = nums[i] + nums[j] + nums[k];
        // cout << "Current Sum: " << currentSum << endl;

        int diff = abs(target - currentSum);

        if (diff < current_max) {
            current_max = diff;
            result = currentSum;
        }

        // Equal value
        if (currentSum == target) {
            result = currentSum;
            break;
        }

        if (currentSum < target) {
            j++;
        }

        if (currentSum > target) {
            k--;
        }
    }

    return result;
}

int threeSumClosest(vector<int>& nums, int target) {
    int result = 0;

    sort(nums.begin(), nums.end());
    // cout << "Sorted arrary is: " << endl;
    // printVector(nums);

    int n = nums.size();

    int currentMax = INT_MAX;
    for (int i=0; i<n-2; i++) {

        // cout << "Index: " << i << " value: " << nums[i] << endl;
        int tempResult = getClosestValue(nums, target, i, i+1, n-1);


        if (tempResult == target) {
            result = target;
            break;
        }

        int diff = abs(target - tempResult);

        if (diff < currentMax) {
            currentMax = diff;
            result = tempResult;
        }
    }

    return result;
}

int main() {
    vector<vector<int>> inputs = {{-1,2,1,-4}, {0,0,0}, {1,1,1,1}, {4,0,5,-5,3,3,0,-4,-5}, {-100,-98,-2,-1}, {2,3,8,9,10}, {-1000,-5,-5,-5,-5,-5,-5,-1,-1,-1}};
    vector<int> targets = {1, 1, 3, -2, -101, 16, -14};
    vector<int> outputs = {2, 0, 3, -2, -101, 15, -15};

    for (int i=0; i<inputs.size(); i++) {
        cout << "Input is: " << endl;
        printVector(inputs[i]);

        cout << "Target is: " << targets[i] << endl;

        int output = threeSumClosest(inputs[i], targets[i]);
        cout << "Output: " << output << endl;
        cout << "Expected output: " << outputs[i] << endl << endl;
    }
    return 0;
}

// Remember, here we can have duplicates.
// And the end result is similar to 3 sum with duplicates
// And check the absolute value after getting the result from the helper function
