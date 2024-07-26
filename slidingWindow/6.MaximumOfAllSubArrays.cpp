/**
 * Maximum of All Subarrays of Size K
 * 
 * Flow: 
 * 1) Problem Statement Input and Output
 * 2. Identification
 * 3. Explanation
 * 4. Code
 * 
 * Input:
 * Array arr: 1 3 -1 -3 5 3 6 7
 * Window Size: 3
 * 
 * What do we need in output?
 * We need to take all subarrays of size 3, and get the maximum value from each subarray.
 * Ouput: An array: 3,3,5,5,6,7
 */

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> maximumOfAllSubarrays(vector<int> &arr, int n) {
    vector<int> output = vector<int>();

    int i=0,j=0;

    set<int> sq = set<int>();

    while(j<arr.size()) {
        if(j-i+1 < n) {
            sq.insert(arr[j]);
            j++;
        } else if(j-i+1 == n) {
            sq.insert(arr[j]);
            output.push_back(*sq.rbegin());

            sq.erase(arr[i]);
            i++;
            j++;
        }
    }

    return output;
}

int main() {
    vector<int> arr = vector<int>({1, 3, -1, -3, 3, 3, 3, 4, -9, -4, 5, 3, 6, 7});
    int k = 3;
    cout << "Input array: " << endl;
    printVector(arr);

    cout << "Sliding Window: " << k << endl;

    vector<int> output = maximumOfAllSubarrays(arr, k);
    cout << "Output array: " << endl;
    printVector(output);
}