/**
 * Binary Search on Decending Sorted Array
 * 
 * Suppose the array provided is in decending sorted, write a binary 
 * search function to find an element in this array.
 * 
 * Input: arr[]: {6, 5, 4, 3, 2, 1}
 * int element : 1
 * 
 * Output: 5
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int customBinarySearch(vector<int> &input, int element) {
    int output = -1;

    int low = 0;
    int high = input.size() - 1;

    while(high >= low) {
        int mid = (high + low)/2;

        if(element == input[mid]) {
            output = mid;
            break;
        }

        if(element > input[mid]) {
            // towards input 0
            high = mid - 1;
        } else {
            // towards input.size() - 1
            low = mid + 1;
        }
    }

    return output;
}

// binary search is available in stl too
int main() {
    vector<int> input = vector<int>({6, 5, 4, 3, 2, 1});
    cout << "Input: " << endl;
    printVector(input);

    int element = 1;

    int output = customBinarySearch(input, element);
    cout << "Output: " << output << endl;

    return 0;
}