/**
 * Print Unique Subsets and Variations
 * 
 * Solution should not have duplicates and every subset should be unique.
 * 
 * What are the variations of this problem?
 * 
 * Print All Subsets Or Print PowerSet or Print All Subsequences
 * They all eventually mean the same thing.
 * 
 * PowerSet is basically all subsets of a set.
 * 
 * Substring - Substring is continuous.
 * 
 * Print All Subsequences - Subsequence can be discontinuous. But Order matters in subsequence.
 * If we have an array, abc, ac is a subsequence, but ca is not a subsequeuce.
 * So Order is important here.
 * 
 * Subset - subset can be discontinuous. Order does not matter here.
 * So, for the above example, ac is allowed and ca is also allowed.
 * 
 * Now, Substring is a subset of Subsequence. Subsequence is a subset of Powerset.
 * Powerset contains all possible combinations.
 * 
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print2DVector(vector< vector<int> > arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void getAllSubsets(vector<int> &input, set<vector<int>> &outputSet, int index, 
    vector<int> &currentOutput) {
        if(index == input.size()) {
            // got some output
            outputSet.insert(currentOutput);
            return;
        }

        int currentItem = input[index];
        index++;

        // don't include
        getAllSubsets(input, outputSet, index, currentOutput);

        // include
        currentOutput.push_back(currentItem);
        getAllSubsets(input, outputSet, index, currentOutput);

        // backtrack as pointers
        currentOutput.pop_back();
    }

int main() {
    vector<int> input = vector<int>({1,2,3,4,5,6,7,8,9,1,1,1});
    cout << "Input: " << endl;
    printVector(input);

    sort(input.begin(), input.end());
    cout << "Input sorted: " << endl;
    printVector(input);

    vector<int> currentOutput = vector<int>();
    set<vector<int>> outputSet = set<vector<int>>();

    getAllSubsets(input, outputSet, 0, currentOutput);

    cout << "Output: " << endl;
    for(set<vector<int>>::iterator it=outputSet.begin(); it!=outputSet.end(); it++) {
        printVector(*it);
    }
    
    return 0;
}