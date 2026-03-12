/**
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].

The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.

Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]

Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]

Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]

Constraints:

    1 <= nums.length <= 100
    0 <= nums[i] <= 100
 */
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &arr) {
    for (int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void nextPermutation(vector<int>& nums) {
    int pivot = -1;

    for (int i=nums.size() - 2; i>=0; i--) {
        if (nums[i+1] > nums[i]) {
            pivot = i;
            break;
        }
    }

    cout << "Pivot obtained is: " << pivot << endl;

    if (pivot == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }

    int swapIndex = -1;
    // find the rightmost element greater than pivot
    for (int i=nums.size()-1; i>pivot; i--) {
        if (nums[i] > nums[pivot]) {
            swapIndex = i;
            break;
        }
    }
    cout << "Swap index obtained - " << swapIndex << endl;

    // swap
    int temp = nums[swapIndex];
    nums[swapIndex] = nums[pivot];
    nums[pivot] = temp;
    cout << "Print vector after swap: " << endl;
    printVector(nums);

    // Sort elements from pivot + 1 to n
    sort(nums.begin() + pivot + 1, nums.end());
    cout << "Print vector after sort: " << endl;
    printVector(nums);

}

int main() {
    vector<vector<int>> inputs = {{1,2,3}, {3,2,1}, {1,1,5}, {1, 2, 3, 6, 5, 4}, {2, 3, 1}};
    vector<vector<int>> outputs = {{1,3,2}, {1,2,3}, {1,5,1}, {1, 2, 4, 3, 5, 6}, {}};

    for (int i=0; i<inputs.size(); i++) {
        cout << "Input:" << endl;
        printVector(inputs[i]);

        nextPermutation(inputs[i]);
        cout << "Output: " << endl;
        printVector(inputs[i]);

        cout << "Expected Output: " << endl;
        printVector(outputs[i]);
        cout << endl;
    }

    return 0;
}

// Please mmake use of Next Permutation Algorithm
/*
 First find pivot
 a[i+1] > a[i] -> pivot is a[i].
 If pivot does not exists - > reverse the array

 Find the rightmost greater element than pivot
 swap that element pivot

 Sort the remaining elements
 Sort elements from pivot + 1 to n
 */