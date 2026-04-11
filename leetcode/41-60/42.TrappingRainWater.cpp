/***
42. Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9

Constraints:

    n == height.length
    1 <= n <= 2 * 10^4
    0 <= height[i] <= 10^5


*/
#include<bits/stdc++.h>
using namespace std;

void printVector(const vector<int> &arr) {
    for (int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int trap(vector<int>& height) {
    int result = 0;

    vector<int> left(height.size());
    vector<int> right(height.size());

    int maxValue = INT_MIN;
    // Pre compute the max left array
    for(int i=0; i<height.size(); i++) {
        int val = height[i];
        maxValue = max(maxValue, val);
        left[i] = maxValue;
    }
    // cout << "Left max array: " << endl;
    // printVector(left);

    // Pre compute the max right array
    maxValue = INT_MIN;
    for(int i=height.size() - 1; i>=0; i--) {
        int val = height[i];
        maxValue = max(maxValue, val);
        right[i] = maxValue;
    }

    // Compute the water stored at each node
    // min(left[i], right[i]) - height[i]
    for(int i=0; i<height.size(); i++) {
        result = result + min(left[i], right[i]) - height[i];
    }

    return result;
}

int main() {
    vector<vector<int>> inputs = {{3, 0, 2, 0, 4}, {0,1,0,2,1,0,1,3,2,1,2,1}, {4,2,0,3,2,5}};
    vector<int> outputs = {7, 6, 9};

    for(int i=0; i<inputs.size(); i++) {
        cout << "Input: " << endl;
        printVector(inputs[i]);

        int output = trap(inputs[i]);
        cout << "Output: " << output << endl;

        cout << "Expected output: " << outputs[i] << endl << endl;
    }

    return 0;
}

// Remember left and right max array