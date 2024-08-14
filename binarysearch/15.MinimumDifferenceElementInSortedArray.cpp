/**
 * Minimum Difference Element in a Sorted Array
 * 
 * Given a sorted array, find the element in the array which has minimum
 * difference with the given number.
 * 
 * Input:
 * arr[] : {4, 6, 7, 10}
 * key = 7
 * 
 * Output:
 * 3
 * 
 * What we can do is, we can first find ceil and then find floor of the key.
 * And using these two values, we can return the element which has minimum difference.
 * While finding this, if our input[mid] value equals key, return that input[mid] value
 * as that is output.
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findMinDifference(vector<int> &input, int key) {
    int output = -1;
    int floor = -1;
    int ceil = -1;

    int low = 0;
    int high = input.size();
    while(high >= low) {
        int mid = (high + low)/2;

        if(input[mid] == key) {
            return mid;
        }

        if(input[mid] <= key) {
            // can be floor value
            floor = mid;
            // go right for efficient value
            low = mid + 1;
        } else if(input[mid] > key) {
            // no can do, value should be less
            // Go lower
            high = mid - 1;
        }
    }

    if(floor == -1) {
        // don't have any value which is less than or equal to key
        // All values are greater than key
        // the smallest element is closest to key
        floor = 0;
    }
    
    if(floor + 1 < input.size()) {
        // this value will be closes to key
        ceil = floor + 1;
    } 
    
    if(floor + 1 >= input.size()) {
        // no ceil value available
        // no value which is greater than or equal to key
        // All values are smaller than key.
        ceil = input.size() - 1;
    }

    int floorDiff = abs(input[floor] - key);
    int ceilDiff = abs(input[ceil] - key);
    if(floorDiff < ceilDiff) {
        output = floor;
    } else {
        output = ceil;
    }

    return output;
}

int main() {
    vector<int> input = vector<int>({1, 2, 3, 4, 8, 10, 10, 12, 19});
    cout << "Input: " << endl;
    printVector(input);
    int key = 5;
    cout << "Element: " << key << endl;

    int output = findMinDifference(input, key);
    cout << "Output: " << output << endl;
    if(output >= 0) {
        cout << "Value: " << input[output] << endl;
    }

    return 0;
}