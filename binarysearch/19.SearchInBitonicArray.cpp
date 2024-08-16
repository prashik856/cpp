/**
 * Find an element in Bitonic element
 * 
 * Given a bitonic sequence of n distinct elements, write a program to find a given element
 * x in the bitonic sequence in O(logn) time.
 * A Bitonic Sequence is a sequence of numbers which is first strictly increasing,
 * then after a point, strictly decreasing.
 * 
 * // My method?
 * First find the peak of the array, and then find the element 
 * either in left size or right size.
 * 
 * I think this is the right way.
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int maxElement(vector<int> &input) {
    if(input.size() == 1) {
        return 0;
    }

    int output = -1;

    int low = 0;
    int high = input.size() - 1;

    while(high >= low) {
        cout << "low: " << low << " | high: " << high << endl;
        int mid = low + (high - low)/2;
        cout << "Mid: " << mid << endl;

        if(mid == 0) {
            if(input[mid] > input[mid+1]) {
                output = mid;
                break;
            }

            // go forward
            low = mid + 1;
        } else if(mid == input.size() - 1) {
            if(input[mid] > input[mid - 1]) {
                output = mid;
                break;
            }

            // go backward
            high = mid - 1;
        } else if(mid-1>=0 && mid+1<input.size()) {
            if(input[mid] > input[mid-1] && input[mid] > input[mid+1]) {
                output = mid;
                break;
            }

            // else
            if(input[mid-1] > input[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << endl;
    }

    return output;
}

int searchInBitonicArray(vector<int> &input, int key) {
    int output = -1;

    int pivotIndex = maxElement(input);
    cout << "Pivot index: " << pivotIndex << endl;

    // search left
    int low = 0;
    int high = pivotIndex;
    while(high >= low) {
        int mid = (high + low)/2;

        if(input[mid] == key){
            output = mid; 
            break;
        }

        if(key > input[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if(output == -1 && pivotIndex + 1 < input.size()) {
        cout << "Searching right array: " << endl;
        // not found in left, search right
        low = pivotIndex + 1;
        high = input.size() - 1;
        while(high >= low) {
            int mid = (high + low)/2;

            if(input[mid] == key){
                output = mid; 
                break;
            }

            if(key > input[mid]) {
                // decreasing order
                // go left
                high = mid - 1;
            } else {
                // decreasing order
                // key < input[mid]
                // go right
                low = mid + 1;
            }
        }
    }

    return output;
}

int main() {
    vector<int> input = vector<int>({1, 3, 8, 12, 5, 4, 2, 0});
    cout << "Input vector: " << endl;
    printVector(input);

    int key = 2;
    cout << "Key to search: " << key << endl;

    int output = searchInBitonicArray(input, key);
    cout << "Output: " << output << endl;

    return 0;
}