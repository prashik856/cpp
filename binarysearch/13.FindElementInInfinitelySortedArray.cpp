/**
 * Find the position of an element in an Infinitely Sorted Array
 * 
 * We have an element of infinite size. 
 * And we need to find an element inside it. 
 * 
 * How do we do it?
 * We first need to find our limits.
 * Our low, and our high.
 * 
 * if key < low, key is not in array, return -1
 * our low will be 0.
 * to find high, we can apply a while loop, till key > high.
 * And when key > high, we should update low value as high.
 * 
 * while(key > high) {
 *  low = high;
 *  high = 2 * high;
 * }
 * 
 * Once high > key, 
 * We have our limits, low and high, and element to search key.
 * We can safely apply our Binary Search.
 * 
 * This question can be asked in an interview rather than to actually code it.
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<char> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int binarySearcyInInfinitelySortedArray(vector<int> &input, int key) {
    int output = -1;

    int low = 0;
    int high = 1;

    while(key > input[high]) {
        low = high;
        high = high * 2;
    }

    // Now we have our low and high, and our key between input[low] and input[high]

    while(high >= low) {
        int mid = (high + low)/2;
        if(input[mid] == key) {
            output = mid;
            break;
        }

        if(key > input[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return output;
}