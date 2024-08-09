/**
 * Kth Smallest Element
 * 
 * Given an array of integers, we need to find the Kth smallest element.
 * 
 * Input: 
 * arr: 7 10 4 3 20 15
 * K = 3
 * Output: 7
 * 
 * Identification:
 * We are provided a K and we are asked to find the smallest element.
 * So that means, we need to use heap.
 * 
 * Since we are asked smallest, we will use maxHeap.
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int getKthSmallestElement(vector<int> &input, int k) {
    int output;
    // Since we need to find smallest, we will use maxHeap.
    priority_queue<int> maxHeap = priority_queue<int>();

    for(int i=0; i<input.size(); i++) {
        int item = input[i];
        maxHeap.push(item);
        if(maxHeap.size() > k) {
            maxHeap.pop();
        }
    }

    output = maxHeap.top();

    return output;
}

int main() {
    vector<int> input = vector<int>({7, 10, 4, 3, 20, 15});
    int k = 3;
    cout << "Input: " << endl;
    printVector(input);
    cout << "k: " << k << endl;

    int output = getKthSmallestElement(input, k);
    cout << "Output: " << output << endl;

    return 0;
}