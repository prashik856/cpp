/**
 * Ceil of an element in a sorted array.
 * 
 * Given a sorted array and a value x, the ceiling of x is the smallest element
 * in array greater than or equal to x.
 * Assuming that array is sorted in ascending order, write efficient function 
 * to find ceil of x.
 * 
 * 
 * Input:
 * arr[] = {1, 2, 8, 10, 10 , 12, 19}
 * element: 5
 * 
 * Output: 8
 * 
 * We need to find the smallest element in the array which is greater than or equal to x.
 * 
 * Very similar to our previous question. Instead of floor, we will find ceil.
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findCeil(vector<int> &input, int element) {
    int output = -1;

    int low = 0;
    int high = input.size() - 1;
    while(high >= low) {
        int mid = (high + low)/2;

        if(input[mid] >= element) {
            // potential solution
            output = mid;
            // go left for efficient solution
            high = mid - 1;
        } else if(input[mid] < element) {
            // no can do
            // go right
            low = mid + 1;
        }
    }

    return output;
}

int main() {
    vector<int> input = vector<int>({1, 2, 3, 4, 8, 10, 10, 12, 19});
    cout << "Input: " << endl;
    printVector(input);
    int element = -10;
    cout << "Element: " << element << endl;

    int output = findCeil(input, element);
    cout << "Output: " << output << endl;
    if(output >= 0) {
        cout << "Value: " << input[output] << endl;
    }

    return 0;
}