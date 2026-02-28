/**
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

Constraints:

    3 <= nums.length <= 3000
    -10^5 <= nums[i] <= 10^5
 */
#include <bits/stdc++.h>
using namespace std;

// Create array of set like this:
/*
vector<int> arr1 = {1, 2, 3};
vector<int> arr2 = {3, 4, 5};
vector<int> arr3 = {1, 2, 3};

set<vector<int>> myset;
myset.insert(arr1);
myset.insert(arr2);
myset.insert(arr3);

cout << "Printing content inside the set: " << endl;
for (auto& arr: myset) {
    printVector(arr);
}
 */

// Test 2. How to sort from stl
/*
vector<int> arr1 = {1, 2, 3, -1, 0, -5};
sort(arr1.begin(), arr1.end());
cout << "Sorted arr: " << endl;
printVector(arr1);
 */

void printVector(const vector<int> &arr) {
    for (int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print2DVector(vector<vector<int>> &arr) {
    for (int i=0; i<arr.size(); i++) {
        printVector(arr[i]);
        cout << endl;
    }
}

vector<int> getSmallVector(int i, int j, int k) {
    if (i <= j && i <= k && j <= k) {
        return {i, j, k};
    }

    if (i <= j && i <= k && k <= j) {
        return {i,k,j};
    }

    if (j <= i && j <= k && i <= k) {
        return {j, i, k};
    }

    if (j <= i && j <= k && k <= i) {
        return {j, k, i};
    }

    if (k <= i && k <= j && i <= j) {
        return {k, i, j};
    }

    return {k, j, i};
}

vector<vector<int>> threeSumHashMap(vector<int>& nums) {
    vector<vector<int> > result;

    unordered_map<int, int> dict;
    for (int i=0; i<nums.size(); i++) {
        dict[nums[i]] = i;
    }

    set<vector<int>> resultSet;

    // Start our 3sum
    for (int i=0; i<nums.size()-2; i++) {
        for (int j=i+1; j<nums.size()-1; j++) {
            long numToFind = 0 - nums[i] - nums[j];
            if (dict.find(numToFind) != dict.end()) {
                // found it
                int k = dict[numToFind];
                if (i != j && j != k && i != k) {
                    resultSet.insert(getSmallVector(nums[i], nums[j], nums[k]));
                }
            }
        }
    }

    for (auto itr: resultSet) {
        // cout << "Outputs: " << endl;
        // printVector(itr);
        result.push_back(itr);
    }

    return result;
}

// We can have multiple solutions
void getValidOutput(vector<int> &nums, int i, int j, int k, set<vector<int>> &result) {

    while (j < k) {
        int val = nums[i] + nums[j] + nums[k];
        if (val == 0) {
            // We got a valid triplet
            // cout << "Found a valid triplet" << endl;
            vector<int> resultVector = {nums[i], nums[j], nums[k]};
            // printVector(resultVector);
            if (result.find(resultVector) == result.end()) {
                // not found
                // cout << "Vector not found in result " << endl;
                result.insert(resultVector);

                // check for duplicate
                if (j+1 < k && nums[j+1] != nums[j]) {
                    getValidOutput(nums, i, j+1, k, result);
                } else {
                    j++;
                }

                if (k - 1 > j && nums[k-1] != nums[k]) {
                    getValidOutput(nums, i, j, k-1, result);
                } else {
                    k--;
                }

            } else {
                // cout << "Vector found in result" << endl;
                j++;
                k--;
            }
        }

        if (val < 0) {
            // increase
            j++;
        }

        if (val > 0) {
            // decrease
            k--;
        }
    }
}

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    set<vector<int>> tempResult;

    // Sort our array
    // cout << "Sorting our array" << endl;
    sort(nums.begin(), nums.end());
    printVector(nums);

    for (int i=0; i<nums.size()-2; i++) {
        // No point finding as all values will be positive
        if (nums[i] > 0) {
            // cout << "Greater than 0" << endl;
            break;
        }

        // No point for the duplicate
        if (i > 0 && nums[i] == nums[i-1]) {
            // cout << "Duplicate" << endl;
            continue;
        }

        getValidOutput(nums, i, i+1, nums.size() - 1, tempResult);
    }

    for (auto itr: tempResult) {
        // cout << "Result Obtained is: " << endl;
        // printVector(itr);
        result.push_back(itr);
    }

    return result;
}

int main() {
    vector<vector<int> > inputs = {{-1,0,1,2,-1,-4}, {0,1,1}, {0,0,0}, {-100,-70,-60,110,120,130,160}, {2,-3,0,-2,-5,-5,-4,1,2,-2,2,0,2,-4,5,5,-10}};
    vector<vector<vector<int>>> outputs = {
        {{-1,-1,2}, {-1,0,1}}, {{}}, {{0,0,0}}, {{-100,-60,160},{-70,-60,130}},{{-10,5,5},{-5,0,5},{-4,2,2},{-3,-2,5},{-3,1,2},{-2,0,2}}
    };

    for (int i=0; i<inputs.size(); i++) {
        cout << "Current Input is: " << endl;
        printVector(inputs[i]);

        vector<vector<int>> output = threeSum(inputs[i]);
        cout << "Current Output is: " << endl;
        print2DVector(output);

        cout << "Expected Output is: " << endl;
        print2DVector(outputs[i]);
    }

    return 0;
}

