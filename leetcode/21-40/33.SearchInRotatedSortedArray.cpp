/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the
resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left
rotated by 3 indices and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.


You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:

Input: nums = [1], target = 0
Output: -1

Constraints:

    1 <= nums.length <= 5000
    -10^4 <= nums[i] <= 10^4
    All values of nums are unique.
    nums is an ascending array that is possibly rotated.
    -10^4 <= target <= 10^4
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(const vector<int> &arr) {
    for (int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int searchInArray(vector<int> &nums, int target, int leftIndex, int rightIndex) {
    int n = nums.size();
    int left = leftIndex;
    int right = rightIndex;

    while (left <= right && left < n && right >= 0) {
        // cout << "Left: " << left << endl;
        // cout << "Right:" << right << endl;
        int mid = (left + right)/2;
        // cout << "Mid:" << mid << endl;

        if (target == nums[mid]) {
            return mid;
        }

        if (target > nums[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int search(vector<int>& nums, int target) {
    // Find pivot first
    int result = -1;
    int pivot = -1;
    int n = nums.size();

    if (n == 1) {
        // cout << "Single value in nums: " << endl;
        if (target == nums[0]) {
            return 0;
        }
        return -1;
    }

    // minimum size needed for me is 3
    if (n == 2) {
        // cout << "Double value in nusm: " << endl;
        if (nums[0] == target) {
            return 0;
        }
        if (nums[1] == target) {
            return 1;
        }
    }

    bool rotated = false;
    // if we have vector like 4512 -> rotate, a[0] < a[1]. And since we only have left rotation, this will always be true.
    if (nums[0] > nums[n - 1]) {
        // cout << "Array is rotated: " << endl;
        rotated = true;
    }

    // if not rotated, find the result normally
    if (!rotated) {
        // cout << "Array is not rotated:" << endl;
        result = searchInArray(nums, target, 0, n-1);
    } else {
        // Rotated
        // Find pivot, where for a pivot since we have distinct values, arr[pivot] < arr[pivot-1] and arr[pivot] < arr[pivot+1]
        // Now, if pivot at the start i.e. at -1, we have normal ascending order array.
        // while if pivot is at end, we have a[nums.size() - 1

        // check if pivot at end
        if (nums[n - 1] < nums[n-2] && nums[n-1] < nums[0]) {
            // cout << "Pivot at right end: " << endl;
            pivot = n-1;
        }

        if (pivot == -1) {
            // cout << "Pivot value is - 1: " << endl;
            int left = 0;
            int right = n-1;

            while (true) {
                // cout << "Left: " << left << endl;
                // cout << "Right: " << right << endl;
                // mid is between here
                int mid = (left + right)/2;
                // cout << "Mid: " << mid << endl;
                if (nums[mid] < nums[mid-1] && nums[mid] < nums[mid+1]) {
                    // cout << "Found the pivot value:" << endl;
                    pivot = mid;
                    break;
                }

                // else
                if (nums[left] > nums[mid]) {
                    // cout << "Pivot is between " << left << " and " << mid << endl;
                    right = mid;
                } else if (nums[mid] > nums[right]) {
                    // cout << "Pivot is between " << mid << " and " << right << endl;
                    // pivot is between mid+1 and right
                    left = mid;
                }
            }
        }

        // cout << "Pivot value is: " << pivot << endl;

        if (target >= nums[pivot] && target <= nums[n-1]) {
            // cout << "Search between: " << nums[pivot] << " and " << nums[n-1] << endl;
            // target between pivot and n-1
            result = searchInArray(nums, target, pivot, n-1);
        } else {
            // cout << "Search between: " << nums[0] << " and " << nums[pivot-1] << endl;
            // target between 0 and pivot - 1
            result = searchInArray(nums, target, 0, pivot - 1);
        }
    }

    return result;
}

int main() {
    vector<vector<int>> inputs = {{4,5,6,7,0,1,2}, {4,5,6,7,0,1,2}, {1}, {1, 2, 3, 4, 5}, {2, 3, 4, 5, 1}};
    vector<int> targets = {0, 3, 0, 4, 1};
    vector<int> outputs = {4, -1, -1, 3, 4};

    for (int i=0; i<inputs.size(); i++) {
        cout << "Input: " << endl;
        printVector(inputs[i]);

        cout << "Target: " << targets[i] << endl;

        int output = search(inputs[i], targets[i]);
        cout << "Output: " << output<< endl;

        cout << "Expected Output: " << outputs[i] << endl << endl;
    }

    return 0;
}

// The actual question here is to find the pivot
// Remember, to find the pivot, make use of left rotation of the array.
// As pivot will lie between two larger values.