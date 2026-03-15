/*
35. Search Insert Position

Given a sorted array of distinct integers and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4

Constraints:

    1 <= nums.length <= 10^4
    -10^4 <= nums[i] <= 10^4
    nums contains distinct values sorted in ascending order.
    -10^4 <= target <= 10^4

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

    while (left < right) {
        int mid = (left + right)/2;

        if (arr[mid] == target) {
            return mid;
        }

        if (target > arr[mid]) {
            left = mid + 1;
        }

        if (target < arr[mid]) {
            right = mid - 1;
        }

        if (left == right) {
            break;
        }
    }

    // we will only come here if left == right
    if (target > arr[left]) {
        result = left + 1;
    } else {
        result = left;
    }

    return result;
}

int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();

    // if empty, we need to put it in first position
    if (n ==0) {
        return 0;
    }

    int result = searchInArray(nums, target, 0, n - 1);

    return result;
}

int main() {
    vector<vector<int>> inputs = {{1,3,5,6}, {1,3,5,6}, {1,3,5,6}, {1,3,5,6}};
    vector<int> targets  ={5, 2, 7};
    vector<int> outputs = {2, 1, 4};

    for (int i=0; i<inputs.size(); i++) {
        cout << "Input: " << endl;
        printVector(inputs[i]);

        cout << "Target: " << targets[i] << endl;

        int output = searchInsert(inputs[i], targets[i]);
        cout << "Output:" << output <<  endl;

        cout << "Expected Output: " << outputs[i] << endl;

        cout << endl;
    }

    return 0;
}