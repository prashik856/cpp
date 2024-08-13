/**
 * Find an element in a sorted rotated array.
 * 
 * Input: arr[]: {11, 12, 15, 18, 2, 5, 6, 8}
 * int element = 6
 * 
 * Output: 6
 * 
 * Very similar to previous question.
 * First here, we will find the pivot element (the smallest element).
 * Once we find the smallest element, we will see where the search element lies, 
 * and search our array in that direction.
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findElementInRotatedArray(vector<int> &input, int element) {
    int output = -1;

    // Code to find the pivot element
    int n = input.size();
    int low = 0;
    int high = n - 1;
    while(high >= low) {
        int mid = low + (high - low)/2;

        int midl = mid-1;
        if(midl < 0) {
            midl = n - 1;
        }
        int midh = mid+1;
        if(midh == n) {
            midh = 0;
        }

        // pivet condition
        if(input[mid] < input[midh] && input[mid] < input[midl]) {
            // found our pivet
            output = mid;
            break;
        }

        // When out mid is greater than high, pivet lies between mid and high
        if(input[mid] > input[high]) {
            // unsorted place
            // go here
            low = mid + 1;
        } else if(input[mid] < input[low]) {
            // it lies between mid and low
            // unsorted place
            // go here
            high = mid - 1;
        } else if(input[mid] > input[low]) {
            // we are currently in sorted section. 
            // we need to go lower as we need to find the minimum element.
            high = mid - 1;
        }
    }

    // return if pivot is output
    int pivot = output;
    if(input[pivot] == element) {
        return pivot;
    }

    // checking where element lies
    if(element > input[n - 1]) {
        // element lies before pivot
        low = 0;
        high = pivot - 1;
    } else {
        // element lies after pivot
        low = pivot + 1;
        high = n - 1;
    }

    while(high >= low) {
        int mid = (high + low)/2;

        if(input[mid] == element) {
            return mid;
        }

        if(element > input[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> input = vector<int>({5, 6, 7, 8, 9, 10, 11, 0, 1, 2});
    cout << "Input: " << endl;
    printVector(input);

    int element = 0;
    cout << "Element: " << element << endl;

    int output = findElementInRotatedArray(input, element);
    cout << "Output: " << output << endl;

    return 0;
}