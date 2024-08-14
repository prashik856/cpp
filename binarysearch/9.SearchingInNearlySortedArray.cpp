/**
 * Searching in Nearly Sorted array
 * 
 * Given an array which is sorted, but after sorting some elemnts are moved to either of the
 * adjacent positions, i.e. arr[i] may be present at arr[i+1] or arr[i-1]. 
 * Write an efficient function to search an element in this array. 
 * Basically the element arr[i] can only be swapped with either arr[i+1] or arr[i-1]
 * 
 * So, since a sorted array is given, we need to apply binary search.
 * 
 * We need to update our binary sort algorithm by checking more elements 
 * when updating our low and high values.
 * When updating low, we need to check mid-1 (as element can be swapped with i-1, 
 * and we will be getting rid of this region.)
 * when updating high, we need to check mid+1 (as element can be swapped with i+1, 
 * and we will be getting rid of this region.)
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findElementInNearlySorted(vector<int> &input, int element) {
    int output = -1;

    int low = 0;
    int high = input.size() - 1;
    while(high >= low) {
        int mid = low + (high - low);

        if(input[mid] == element) {
            output = mid;
            break;
        }

        if(element > input[mid]) {
            // go right
            // we are updating low. 
            // So check mid - 1 before going ahead to mid + 1;
            if(mid - 1 >= 0) {
                if(input[mid-1] == element) {
                    output = mid - 1;
                    break;
                }
            }
            low = mid + 1;
        } else {
            // go left
            // We are updating high.
            // check mid+1 before going to mid - 1;
            if(mid+1 <= input.size() - 1) {
                if(input[mid+1] == element) {
                    output = mid + 1;
                    break;
                }
            }
            high = mid - 1;
        }
    }

    return output;
}

int main() {
    vector<int> input = vector<int>({10, 3, 40, 20, 50, 80, 70});
    cout << "Input: " << endl;
    printVector(input);

    int element = 999;
    cout << "Element to find: " << element << endl;

    int output = findElementInNearlySorted(input, element);
    cout << "Output: " << output << endl;

    return 0;
}