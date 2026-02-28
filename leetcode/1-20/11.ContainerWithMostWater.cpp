/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example 2:

Input: height = [1,1]
Output: 1

Constraints:

    n == height.length
    2 <= n <= 10^5
    0 <= height[i] <= 10^4
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> &arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int maxArea(vector<int>& height) {
    long result = 0;

    // the max value will be between these indices
    long left = 0;
    long right = height.size() - 1;

    // run this loop while left index is less than right
    long current_water_storage = 0;
    while (left < right) {
        // the rectangular area
        current_water_storage = (right - left) * min(static_cast<long>(height[left]), static_cast<long>(height[right])); // width * height
        if (current_water_storage > result) {
            result = current_water_storage;
        }

        if (height[left] < height[right]) {
            // if height of right is greater, we keep it as is. As we need pillar of max height
            left++;
        } else {
            right--;
        }
    }

    return result;
}

int main() {
    vector<int> height = {1,1};
    cout << "Input: " << endl;
    printVector(height);

    int result = maxArea(height);
    cout << "Result: " << result << endl;

    return 0;
}

// Need to use two pointer approach here. And need to use a greedy approach here. We need to know that the max value will only lie between
// the extreme two ends. And we need to update the indices based on the current values of left and right. Make sure to keep the max value
// and update the lower value when updating the indices