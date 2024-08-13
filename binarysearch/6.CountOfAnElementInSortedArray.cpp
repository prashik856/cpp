/**
 * Count of an element in a sorted array.
 * 
 * Given a sorted array, you need to find the count of a given element.
 * 
 * Input: arr[]: {2, 4, 10, 10 , 10, 18, 20}
 * int element = 10
 * 
 * Output: 3
 * 
 * // Very similar to first and last occurance.
 * Once we get first and last occurance, we get their difference and that is our answer.
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int countOfElement(vector<int> &input, int element) {
    int output = -1;

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

    output = last - first + 1;

    return output;
}

int main() {
    vector<int> input = vector<int>({2, 4, 10, 10, 10, 18, 20});
    cout << "Input: " << endl;
    printVector(input);

    int element = 20;

    int output = countOfElement(input, element);
    cout << "Output: " << output << endl;
    return 0;
}