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
 * 
 * Simple binary search does this for us.
 * Rather than finding the floor and Ceil, we can simply run binary search
 * if we find key, return that index.
 * Else, go till high < low.
 * once that happens, we got two indices which is closes to key.
 * Find the difference between two, and return the index with lowest difference.
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findMinOptimal(vector<int> &input, int key) {
    int output = -1;

    int low =0;
    int high = input.size() - 1;
    while(high >= low) {
        int mid = (high + low)/2;

        if(input[mid] == key) {
            return mid;
            break;
        }

        if(key > input[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    int lowDiff = abs(input[low] - key);
    int highDiff = abs(input[high] - key);
    if(lowDiff < highDiff) {
        output = low;
    } else {
        output = high;
    }

    return output;
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
        
        // since all values are greater than key,
        // the smallest element will be closest to key
        ceil = 0;
    } else if(floor + 1 < input.size()) {
        // floor != -1

        // this value will be closest to key
        ceil = floor + 1;
    } else if(floor + 1 >= input.size()) {
        // floor != -1
        
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

    output = findMinOptimal(input, key);
    cout << "Output: " << output << endl;
    if(output >= 0) {
        cout << "Value: " << input[output] << endl;
    }

    return 0;
}