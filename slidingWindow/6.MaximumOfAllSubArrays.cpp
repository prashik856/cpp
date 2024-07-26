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

void updateMaxValues(int &max1, int &max2, 
    int &max1Index, int &max2Index, 
    int value, int valueIndex) {
    if(max1Index == -1 && max2Index == -1) {
        max1 = value;
        max1Index = valueIndex;
    }

    if(max2Index == -1 && max1Index != -1) {
        if(value > max1) {
            // Update max1 and max2
            max2 = max1;
            max2Index = max1Index;
            max1 = value;
            max1 = valueIndex;
        } else {
            // Update max2
            max2 = value;
            max2Index = valueIndex;
        }
    }

    if(max1Index == -1 && max2Index  != -1) {
        if(value>max2) {
            max1 = value;
            max1Index = valueIndex;
        }
    }

    if(max1Index != -1 && max2Index != -1) {
        if(value > max1) {
            max2 = max1;
            max2Index = max1Index;
            max1 = value;
            max1Index = valueIndex;
        }
        if(value > max2 && value < max1) {
            max2 = value;
            max2Index = valueIndex;
        }
    }
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