/**
 * Sort given array using recursion (Merge Sort?)
 * 
 * Flow:
 * 1. Problem Statement - Input and Output
 * 2. Explanation
 * 3. Code
 * 
 * Time complexity here won't be O(nlogn)
 * 
 * // For our Hypothesis, 
 * lets say we remove the last element of the array and give the remaining array to the 
 * recursive function.
 * 
 * // Our Base condition 
 * will be when our array size reaches 1, we return the same array
 * 
 * // Our induction
 * 
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void putValue(vector<int> &input, int index, int value) {
    // base condition
    if(index == input.size()) {
        // we have the biggest element
        input.push_back(value);
        return;
    }

    if(input[index] > value) {
        // we got our value
        input.insert(input.begin() + index, value);
        return;
    }

    putValue(input, index + 1, value);
}

vector<int> sortRecursion(vector<int> input) {
    // cout << "Current Input: " << endl;
    // printVector(input);

    // base condition
    if(input.size() == 1) {
        // cout << "Base Condition reached: " << endl;
        return input;
    }

    int lastValue = input[input.size() - 1];
    input.pop_back();
    // cout << "Last Element: " << lastValue << endl;

    // hypothesis
    input = sortRecursion(input);

    // Induction
    // Now we have a new recursion problem to put a value inside an array.
    // We have a sorted array input, and we need to put a new element, lastValue 
    // inside the array using recursion
    // cout << "Putting value inside vector: " << lastValue << endl;
    putValue(input, 0, lastValue);
    // cout << "Vector after putting value: " << endl;
    // printVector(input);
    // cout << endl;

    return input;
}

int main() {
    vector<int> input = vector<int>({2,3,7,0,6,4,5,9,1});
    cout << "Input array: " << endl;
    printVector(input);

    vector<int> output = sortRecursion(input);
    cout << "Sorted Output array: " << endl;
    printVector(output);

    return 0;
}