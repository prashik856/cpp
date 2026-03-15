/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:

Input: nums = [], target = 0
Output: [-1,-1]

Constraints:

    0 <= nums.length <= 10^5
    -10^9 <= nums[i] <= 10^9
    nums is a non-decreasing array.
    -10^9 <= target <= 10^9

 */
#include <bits/stdc++.h>
using namespace std;

void printVector(const vector<int> &arr) {
    for (int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int searchInArray(vector<int> &arr, int target, int left, int right) {
    int result = -1;

    while (left <= right) {
        int mid = (left + right)/2;

        if (arr[mid] == target) {
            result = mid;
            break;
        }

        if (target > arr[mid]) {
            left = mid + 1;
        }

        if (target < arr[mid]) {
            right = mid - 1;
        }
    }

    return result;
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result = {-1, -1};
    int n = nums.size();

    if (n == 0) {
        return result;
    }

    if (n == 1 && nums[0] == target) {
        return {0, 0};
    }

    if (n == 1 && nums[0] != target) {
        return result;
    }

    int index = searchInArray(nums, target, 0, n-1);
    if (index == -1) {
        // cout << "Value not found: " << endl;
        return result;
    }

    // cout << "Value found at index: " << index << endl;
    int leftIndex = index;
    int rightIndex = index;

    while (true) {
        // cout << "Finding left index: " << endl;
        int left = 0;
        int right = index - 1;

        if (index != 0 && nums[right] == target) {
            // cout << "Finding between " << left << " and " << right << endl;
            // find left index
            int tempResult = searchInArray(nums, target, left, right);
            // cout << "Temp Result: " << tempResult << endl;
            if (tempResult == -1) {
                // cout << "Did not find target " << endl;
                // did not find target between left and right, so answer is right + 1;
                leftIndex = index;
                break;
            }

            // cout << "Found target " << endl;
            index = tempResult;
        } else {
            leftIndex = index;
            break;
        }
    }
    // cout << "Left Index: " << leftIndex << endl;
    while (true) {
        // find right index
        // cout << "Finding right index: " << endl;
        int left = index + 1;
        int right = n-1;
        if (index != n-1 && nums[left] == target) {
            // cout << "Finding between " << left << " and " << right << endl;
            int tempResult = searchInArray(nums, target, left, right);
            // cout << "TempResult: " << tempResult << endl;
            if (tempResult == -1) {
                // cout << "Did not find target " << endl;
                rightIndex = index;
                break;
            }

            // cout << "Found target " << endl;
            index = tempResult;
        } else {
            rightIndex = index;
            break;
        }
    }
    // cout << "Right Index: " << rightIndex << endl;

    result = {leftIndex, rightIndex};
    return result;
}

int main() {
    vector<vector<int>> inputs = {{5,7,7,8,8,10}, {5,7,7,8,8,10}, {}, {5, 7, 7, 8, 8, 8, 8, 10}};
    vector<int> targets  ={8, 6, 0, 8};
    vector<vector<int>> outputs = {{3,4}, {-1, -1}, {-1, -1}, {3, 6}};

    for (int i=0; i<inputs.size(); i++) {
        cout << "Input: " << endl;
        printVector(inputs[i]);

        cout << "Target: " << targets[i] << endl;

        vector<int> output = searchRange(inputs[i], targets[i]);
        cout << "Output:" << endl;
        printVector(output);

        cout << "Expected Output: " << endl;
        printVector(outputs[i]);

        cout << endl;
    }

    return 0;
}