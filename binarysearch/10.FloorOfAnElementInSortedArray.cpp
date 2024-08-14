/**
 * Find Floor of an element in a sorted array.
 * 
 * Given a sorted array and a value x, the floor of x is the largest element
 * in array smaller than or equal to x. 
 * Write efficient functions to find floor of x.
 * 
 * Example: 
 * Input: 
 * arr[]: {1, 2, 8, 10, 10, 12, 19}
 * int element: 5
 * 
 * Output: 2
 * 
 * 2 is the largest element in arr[] smaller than 5.
 * 
 * We need a value in the arr which is <= element.
 * We need to update our binary search such that it does this for us.
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findFloor(vector<int> &input, int element) {
    int output = -1;

    int low = 0;
    int high = input.size() - 1;
    while(high >= low) {
        int mid = (high + low)/2;
        
        if(input[mid] <= element) {
            output = mid;
            // find efficient solution
            low = mid + 1;
        } else if(element < input[mid]) {
            // no can do, we need to go lower
            high = mid - 1;
        }
    }

    return output;
}

int main() {
    vector<int> input = vector<int>({1, 2, 3, 4, 8, 10, 10, 12, 19});
    cout << "Input: " << endl;
    printVector(input);
    int element = 10;
    cout << "Element: " << element << endl;

    int output = findFloor(input, element);
    cout << "Output: " << output << endl;
    if(output >= 0) {
        cout << "Value: " << input[output] << endl;
    }

    return 0;
}