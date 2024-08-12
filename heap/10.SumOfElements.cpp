/**
 * Sum of elements between k1 smallest and k2 smallest numbers
 * 
 * Given an array of integers and two numbers k1 and k2.
 * Find the sum of all elements between given two k1th and k2th smallest elements 
 * of the array.
 * All array elements are distinct.
 * 
 * Example:
 * input: arr[] = {20, 8, 22, 4, 12, 10, 14}
 * k1 = 3
 * k2 = 6
 * Output = 26
 * 3rd smallest element is 14.
 * 6th smallest element is 20.
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

int getSumOfElements(vector<int> &input, int k1, int k2) {
    int output = 0;

    int k = -1;
    if(k1 > k2) {
        k = k1;
    } else {
        k = k2;
    }
    // We need smallest elements, so we need to use maxHeap
    priority_queue<int> maxHeap = priority_queue<int>();

    for(int i=0; i<input.size(); i++) {
        int item = input[i];
        maxHeap.push(item);

        if(maxHeap.size() > k) {
            maxHeap.pop();
        }
    }

    // Now, we need to find the sum between k1 and k2.
    int firstSize = k;
    // we will not need this
    maxHeap.pop();

    int secondSize = -1;
    if(k == k1) {
        secondSize = k2;
    } else {
        secondSize = k1;
    }

    while(maxHeap.size() != secondSize) {
        output = output + maxHeap.top();
        maxHeap.pop();
    }

    return output;
}

int main() {
    vector<int> input = vector<int>({1, 3, 12, 5, 15, 11});
    cout << "Input array: " << endl;
    printVector(input);
    int k1 = 3;
    int k2 = 6;
    cout << "K1: " << k1 << " | K2: " << k2 << endl;

    int output = getSumOfElements(input, k1, k2);
    cout << "Output: " << output << endl;

    return 0;
}