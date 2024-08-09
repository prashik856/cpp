/**
 * Kth Largest Element
 * 
 * Given an array, and a K, we need to return the Kth largest element.
 * 
 * Example:
 * arr: 7 10 4 3 20 15
 * K = 3
 * Output: 10
 * 
 * Identification:
 * We are given a K, and we are asked a largest element.
 * So, we can see that we can use sorting here.
 * 
 * We should always start with sorting solution, and then optimize it in the face to face interview.
 */

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int getKthLargestElement(vector<int> &input, int k) {
    int output = 0;

    // Since largest is asked, we will use min array
    priority_queue<int, vector<int>, greater<int>> minHeap = 
        priority_queue<int, vector<int>, greater<int>>();

    for(int i=0; i<input.size(); i++) {
        int item = input[i];

        minHeap.push(item);

        if(minHeap.size() > k) {
            minHeap.pop();
        }
    }

    output = minHeap.top();

    return output;
}

int main() {
    vector<int> input = vector<int>({7, 10, 4, 3, 20, 15});
    int k = 3;
    cout << "Input: " << endl;
    printVector(input);
    cout << "k: " << k << endl;

    int output = getKthLargestElement(input, k);
    cout << "Output: " << output << endl;

    return 0;
}