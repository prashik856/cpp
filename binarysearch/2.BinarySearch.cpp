/**
 * Given a sorted array, write a function which finds a given element in the array
 * using O(logN) time.
 * 
 * Input: arr[]: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
 * int element: 2
 * 
 * Output: 1
 * Return the index of the element found.
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
    int high = input.size()-1;

    int found = false;
    while(high >= low) {
        int mid = (high + low)/2;
        if(element == input[mid]){
            output = mid;
            break;
        }

        // we have checked mid, we can now safely ignore it.
        if(element < input[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return output;
}

// binary search is available in stl too
int main() {
    vector<int> input = vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    cout << "Input: " << endl;
    printVector(input);

    int element = -1;

    int output = customBinarySearch(input, element);
    cout << "Output: " << output << endl;

    return 0;
}