/**

Combination Sum II

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]

Constraints:

    1 <= candidates.length <= 100
    1 <= candidates[i] <= 50
    1 <= target <= 30

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

string getKey(int index, int target) {
    return to_string(index) + "," + to_string(target);
}

void solve(vector<int> &arr, int target, int currentSum, set<vector<int>> &output, 
    vector<int> &currentOutput, int index, unordered_map<string, set<vector<int>>> &dict) {
    string key = getKey(index, currentSum);
    // cout << "Current Sum: " << currentSum << endl;
    // cout << "Current Index: " << index << " | Current Value: " << arr[index] << endl;
    // cout << "Current Output " << endl;
    // printVector(currentOutput);

    if(dict.find(key) == dict.end()) {
        // cout << "Could not find current sum in my dictionary: " << endl;
        set<vector<int>> tempSet;
        tempSet.insert(currentOutput);
        dict.insert({key, tempSet});
    } else {
        // cout << "Found current sum in my dictionary" << endl;
        set<vector<int>> tempSet = dict[key];
        if(tempSet.find(currentOutput) == tempSet.end()) {
            // cout << "Current output vector not found in existing set." << endl;
            tempSet.insert(currentOutput);
            dict[key] = tempSet;
        } else {
            // cout << "Current output is already present in dict." << endl;
        }
    }

    if(target == currentSum) {
        // cout << "Found some output: " << endl;
        output.insert(currentOutput);
        return;
    }

    if(index < 0) {
        return;
    }

    int val = arr[index];

    // Value is greater, so I cannot include this value
    if(currentSum + val > target) {
        // cout << "Cannot include val " << val << " as sum is greater." << endl;
        solve(arr, target, currentSum, output, currentOutput, index - 1, dict);
        // cout << endl;
    }

    if(currentSum + val <= target) {
        // include val and same index
        // Update current output
        currentOutput.push_back(val);
        // cout << "Include value " << val << endl;
        string includeKey = getKey(index-1, currentSum+val);
        if(dict.find(includeKey) == dict.end()) {
            // cout << "Include key " << includeKey << " not found." << endl;
            solve(arr, target, currentSum + val, output, currentOutput, index - 1, dict);
        } else {
            // cout << "Include key " << includeKey << " already found. " << endl;
            set<vector<int>> tempSet = dict[includeKey];
            if(tempSet.find(currentOutput) == tempSet.end()) {
                solve(arr, target, currentSum + val, output, currentOutput, index - 1, dict);
                tempSet.insert(currentOutput);
                dict[includeKey] = tempSet;
            }

            if(currentSum + val == target) {
                // cout << "Found some output: " << endl;
                output.insert(currentOutput);
            }
        }
        
        // backtrack
        currentOutput.pop_back();

        // don't include this value
        // cout << "Don't include value " << val << endl;
        solve(arr, target, currentSum, output, currentOutput, index - 1, dict);
    }
    
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> output;
    int index = candidates.size() - 1;
    vector<int> currentOutput;
    set<vector<int>> result;
    sort(candidates.begin(), candidates.end());
    unordered_map<string, set<vector<int>>> dict;
    // cout << "Sorted vector: " << endl;
    // printVector(candidates);

    solve(candidates, target, 0, result, currentOutput, index, dict);

    for(auto itr: result) {
        output.push_back(itr);
    }
    return output;
}

int main() {
    vector<vector<int>> inputs = {{10,1,2,7,6,1,5}, {2,5,2,1,2}, {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
    vector<int> targets = {8, 5, 30};
    vector<vector<vector<int>>> outputs = {{{1,1,6}, {1,2,5}, {1,7}, {2,6}}, {{1,2,2}, {5}}, {}};

    for(int i=0; i<3; i++) {
        cout << "Inputs: " << endl;
        printVector(inputs[i]);

        cout << "Target: " << targets[i] << endl;

        vector<vector<int>> output = combinationSum2(inputs[i], targets[i]);

        cout << "Output: " << endl;
        print2Dvector(output); 

        cout << "Expected Output: " << endl;
        print2Dvector(outputs[i]);

        cout << endl;
    }

    return 0;
}