/**
 * Swap Sort Algorithm
 * 
 * Find a duplicate and a missing number.
 * 
 * Previous Approaches:
 * Using Map, we were using extra space.
 * 
 * Using math, we were using a complicated way to solve the problem. 
 * If the number of missing numbers increases, our complexity will increase even more.
 * This method is not scalable.
 * 
 * 
 * Observation:
 * If the array is read only array, we cannot use this swap sort algorithm.
 * 
 * Problem Statement:
 * Idea case, we are given a 1 to N array.
 * Now, if we sort this array:
 * [1, 2, 3, 4, 5]
 * So, our index will be 
 * [0, 1, 2, 3, 4]
 * 
 * So, for any index i, the value in this index should be i+1.
 * So, after sorting our ideal array, every index will have a value i+1 in this ideal array.
 * 
 * Now, let's say our given array is
 * [2, 3, 1, 5, 1]
 * So, after sorting our array should look like this:
 * [1, 2, 3, , 5] -> We can put this by using our array, and making use 
 * of our previous observation.
 * Since one place is empty, we will put 1 in it (the duplicate)
 * [1, 2, 3, 1, 5]
 * 
 * Now, we need this kind of array.
 * using this kind of array, it makes us easy to identify which number is 
 * missing, and which number is duplicate.
 * 
 * This scalable is easily scalable.
 * If we have multiple duplicates and multiple missing numbers, we can easily find them
 * as well.
 */
#include <iostream>
#include<vector>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swapSortByMe(vector<int> &arr) {
    int i=0;
    while(i < arr.size()) {
        int item = arr[i];
        int expectedIndex = item - 1;
        if(i == expectedIndex) {
            i++;
        } else {
            int valueOfExpectedIndex = arr[expectedIndex];
            if(valueOfExpectedIndex == item) {
                i++;
            } else {
                // perform swap of i and expectedIndex.
                int temp = arr[i];
                arr[i] = arr[expectedIndex];
                arr[expectedIndex] = temp;
                continue;
            }
        }
    }

    int missing = 0;
    int duplicate = 0;
    // Now, we got our expected array.
    for(int i=0; i<arr.size(); i++) {
        if(arr[i]-1 != i) {
            duplicate = arr[i];
            missing = i + 1;
        }
    }

    cout << "Duplicate: " << duplicate << endl;
    cout << "Missing: " << missing << endl;
}

int main() {
    vector<int> arr = vector<int>({10, 1, 2, 5, 4, 3, 9, 8, 7, 9});
    cout << "Input: " << endl;
    printVector(arr);

    swapSortByMe(arr);
    return 0;
}