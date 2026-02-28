/**
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:

    2 <= nums.length <= 10^4
    -10^9 <= nums[i] <= 10^9
    -10^9 <= target <= 10^9
    Only one valid answer exists.

 
Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> input = {3,2,4};
    cout << "Input: " << endl;
    printVector(input);

    int target = 6;
    cout << "Target: " << target << endl;

    int left = -1;
    int right = -1;

    // We use dictionary for this
    unordered_map<long, int> dict;
    
    for(int i=0; i<input.size(); i++) {
        long value = input[i];
        dict.insert({value,i});
    }

    for(int i=0; i<input.size(); i++) {
        long value = input[i];
        long valueToFind = target - value;

        if(dict.find(valueToFind) != dict.end()) {
            // value found
            left = i;
            right = dict[valueToFind];
            if (left == right) {
                continue;
            } else {
                break;
            }
        } 
    }

    vector<int> result;
    result.push_back(left);
    result.push_back(right);

    printVector(result);
}

// this got accepted.