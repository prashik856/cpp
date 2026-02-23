/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

    0 <= a, b, c, d < n
    a, b, c, and d are distinct.
    nums[a] + nums[b] + nums[c] + nums[d] == target

You may return the answer in any order.

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]

Constraints:

    1 <= nums.length <= 200
    -10^9 <= nums[i] <= 10^9
    -10^9 <= target <= 10^9

 */
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &arr) {
    for (int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print2DVector(vector<vector<int>> &arr) {
    for (int i=0; i<arr.size(); i++) {
        printVector(arr[i]);
    }
}

void getValidSolutions(vector<int> &nums, long target, int i, int j, int k, int l, set<vector<int>> &result) {
    while (k < l) {
        long val = static_cast<long>(nums[i]) + static_cast<long>(nums[j]) + static_cast<long>(nums[k]) + static_cast<long>(nums[l]);

        if (val == target) {
            // found a valid target
            vector<int> tempResult = {nums[i], nums[j], nums[k], nums[l]};
            // cout << "Current Result: " << endl;
            // printVector(tempResult);

            if (result.find(tempResult) == result.end()) {
                // not found
                // cout << "Result not found: " << endl;
                result.insert(tempResult);

                getValidSolutions(nums, target, i, j, k+1, l, result);
                getValidSolutions(nums, target, i, j, k, l-1, result);
            } else {
                // cout << "Result found in set" << endl;
                k++;
                l--;
                continue;
            }
        }

        if (val < target) {
            // increase
            k++;
        }

        if (val > target) {
            // decrease
            l--;
        }
    }
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;

    // sort the array
    sort(nums.begin(), nums.end());
    // cout << "Sorted input is: " << endl;
    // printVector(nums);

    int n = nums.size();

    set<vector<int>> tempResult;
    for (int i=0; i<n-3; i++) {
        //Check for duplicates, as we need unique ans
        // if (i+1 < n-3 && nums[i+1] == nums[i]) {
        //     continue;
        // }

        for (int j=i+1; j<n-2; j++) {
            // if (j+1 < n-2 && nums[j+1] == nums[j]) {
            //     continue;
            // }

            // let's do four sum here.
            getValidSolutions(nums, static_cast<long>(target), i, j, j+1, n-1, tempResult);
        }
    }

    for (auto itr: tempResult) {
        result.push_back(itr);
    }

    return result;
}

int main() {
    vector< vector<int>> inputs = {{1,0,-1,0,-2,2}, {2,2,2,2,2}, {1000000000,1000000000,1000000000,1000000000}};
    vector<int> targets = {0, 8, 0};
    vector<vector<vector<int>>> outputs = {{{-2,-1,1,2}, {-2,0,0,2}, {-1,0,0,1}}, {{2,2,2,2}}, {{}}};

    for (int i=0; i<inputs.size(); i++) {
        cout << "Input: " << endl;
        printVector(inputs[i]);

        cout << "Target: " << targets[i] << endl;

        vector<vector<int>> output = fourSum(inputs[i], targets[i]);
        cout << "Output: " << endl;
        print2DVector(output);

        cout << "Expected output: " << endl;
        print2DVector(outputs[i]);
        cout << endl;
    }

    return 0;
}


// Remember to take care of integer overflow