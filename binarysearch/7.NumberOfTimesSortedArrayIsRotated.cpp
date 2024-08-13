/**
 * How many times is a sorted array rotated.
 * 
 * Given a sorted array, which is rotated k times. Our task is to find this k.
 * 
 * Input: arr[]: {11, 12, 15, 18, 2, 5, 6, 8}
 * Output = 4
 * 
 * From our observation, 
 * We can see that the number of times the array is rotated is equal to the index
 * of the smallest element in the given array.[depending on how we rotate it]
 * If index = 2, rotation = arr.size() - index
 * if rotated in different direction, rotation = index.
 * 
 * How do we apply binary search here?
 * First thing we need to do is to find the pivot element.
 * We can apply linear search, but since array is sorted, we need to apply binary search.
 * 
 * Here, we need to take advantage of rotation of sorted array.
 * When an array is rotated:
 * we will minimum element, where it will be smaller than index-1 and index+1.
 * 
 * Now, when our mid reaches any value, we will do some comparisions.
 * w
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int numberOfTimesRotated(vector<int> &input) {
    int output = -1;

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

    return output;
}

int main() {
    vector<int> input = vector<int>({5, 6, 7, 8, 9, 10, 11, 0, 1, 2});
    cout << "Input: " << endl;
    printVector(input);

    int output = numberOfTimesRotated(input);
    cout << "Output: " << output << endl;

    return 0;
}