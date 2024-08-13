/**
 * Order not known search
 * 
 * We need to search in an array whose order is unknown to us. 
 * It can either be ascending or in decending order.
 * 
 * Just a variation?
 * Can't we just check at the start of array and use a flag?
 * if(arr[0] > arr[1]) {
 *  ascending = false;
 * } else {
 *  ascending = true;
 * }
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int orderNotKnownBinarySearch(vector<int> &input, int element) {
    // assuming input.size() > 1
    bool ascending = false;

    // let us compare first and last elements
    if(input[0] < input[input.size() - 1]) {
        ascending = true;
    } else if(input[0] > input[input.size() - 1]) {
        ascending = false;
    } else if(input[0] == input[input.size() - 1]) {
        // all elements are equal
        ascending = true;
        if(input[0] == element) {
            return 0;
        } else {
            return -1;
        }
    }

    int output = -1;
    int low = 0;
    int high = input.size() - 1;
    if(ascending) {
        while(high >= low) {
            int mid = low + (high - low)/2;
            if(element == input[mid]) {
                output = mid;
                break;
            }

            if(element > input[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    } else {
        while(high >= low) {
            int mid = low + (high - low)/2;

            if(element == input[mid]) {
                output = mid;
                break;
            }

            if(element > input[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }

    return output;
}

// binary search is available in stl too
int main() {
    vector<int> input = vector<int>({1, 2, 3, 4, 5, 6});
    cout << "Input: " << endl;
    printVector(input);

    int element = 1;

    int output = orderNotKnownBinarySearch(input, element);
    cout << "Output: " << output << endl;

    return 0;
}