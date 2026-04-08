/**
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.


Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:

Input: candidates = [2], target = 1
Output: []

Constraints:

    1 <= candidates.length <= 30
    2 <= candidates[i] <= 40
    All elements of candidates are distinct.
    1 <= target <= 40


 */
#include<bits/stdc++.h>
using namespace std;

void printVector(const vector<int> &arr) {
    for (int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print2Dvector(const vector<vector<int>> &arr) {
    for(int i=0; i<arr.size(); i++) {
        printVector(arr[i]);
    }
    cout << endl;
}

void solve(vector<int> &arr, int target, int currentSum, set<vector<int>> &output, vector<int> &currentOutput, int index) {
    if(target == currentSum) {
        // cout << "Found some output: " << endl;
        output.insert(currentOutput);
        return;
    }

    int val = arr[index];
    // cout << "Current Index: " << index << "| Value: " << val << " | Current Sum : " << currentSum << endl;

    // Value is greater, so I cannot include this value
    if(currentSum + val > target && index - 1 >=0) {
        // cout << "Cannot include val as sum is greater." << endl;
        solve(arr, target, currentSum, output, currentOutput, index - 1);
    }

    if(currentSum + val <= target) {
        // include val and same index
        currentOutput.push_back(val);
        solve(arr, target, currentSum + val, output, currentOutput, index);
        
        if(index - 1>=0) {
            solve(arr, target, currentSum + val, output, currentOutput, index - 1);
        }
        

        // don't include this value
        currentOutput.pop_back();
        if(index - 1 >= 0) {
            solve(arr, target, currentSum, output, currentOutput, index - 1);
        }
    }
    
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> output;
    int index = candidates.size() - 1;
    vector<int> currentOutput;
    set<vector<int>> result;

    solve(candidates, target, 0, result, currentOutput, index);

    for(auto itr: result) {
        output.push_back(itr);
    }
    return output;
}

int main() {
    vector<vector<int>> inputs = {{2,3,6,7}, {2,3,5}, {2}};
    vector<int> targets = {7, 8, 1};
    vector<vector<vector<int>>> outputs = {{{2,2,3}, {7}}, {{2,2,2,2}, {2,3,3}, {3,5}}, {}};

    for(int i=0; i<inputs.size(); i++) {
        cout << "Inputs: " << endl;
        printVector(inputs[i]);

        cout << "Target: " << targets[i] << endl;

        vector<vector<int>> output = combinationSum(inputs[i], targets[i]);

        cout << "Output: " << endl;
        print2Dvector(output); 

        cout << "Expected Output: " << endl;
        print2Dvector(outputs[i]);

        cout << endl;
    }

    return 0;
}