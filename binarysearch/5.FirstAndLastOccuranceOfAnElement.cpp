/**
 * First and last occurance of an element.
 * 
 * Given an array, which can have duplicate element, 
 * and provided an input element, provide the first and last occurance of the element in the
 * array.
 * 
 * Input: 
 * arr[]: {2, 4, 10, 10, 10, 18, 20}
 * int element: 10
 * 
 *     // We can do one thing, apply binary search one,
    // and find the element. if element is found, we can go left 
    // and right to the get the first and last occurance.
 * 
 * Output: 2, 4
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> firstAndLastOccurance(vector<int> &input, int element) {
    vector<int> output = vector<int>();

    // first occurance
    int first = -1;
    int last = -1;
    int low = 0;
    int high = input.size() - 1;
    while(high >= low) {
        int mid = low + (high - low)/2;
        if(input[mid] == element) {
            first = mid;
            if(last == -1) {
                last = mid;
            }
            // go down to see if we have element in the lower area
            high = mid - 1;
            continue;
        }

        if(element > input[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // not found
    if(first == -1) {
        // I am returning empty output
        return output;
    }

    low = last + 1;
    high = input.size() - 1;
    while(high >= low) {
        int mid = low + (high-low)/2;

        if(input[mid] == element) {
            last = mid;
            // move forward
            low = mid + 1;
            continue;
        }

        if(element > input[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    output.push_back(first);
    output.push_back(last);

    return output;
}

// binary search is available in stl too
int main() {
    vector<int> input = vector<int>({2, 4, 10, 10, 10, 18, 20});
    cout << "Input: " << endl;
    printVector(input);

    int element = 20;

    vector<int> output = firstAndLastOccurance(input, element);
    cout << "Output: " << endl;
    printVector(output);

    return 0;
}