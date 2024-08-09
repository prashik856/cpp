/**
 * Sort a K Sorted Array
 * Nearly Sorted Array
 * 
 * Given an array of n elements, where each element is at most k away from its target position, 
 * devise an algorithm that sorts in O(nlogk) time.
 * 
 * Explanation:
 * We just need to sort an array.
 * Array is almost nearly sorted.
 * 
 * What is K sorted array?
 * 6 5 3 2 8 10 9
 * 0 1 2 3 4 5  6
 * 
 * An example, index 0 can be present k size in the left or rigth size of the sorted array.
 * 
 * Identification:
 * Here, this is not a standard heap question.
 * As directly K is not given, nor smallest or largest is not provided.
 * 
 * How do we make use of k sorted array?
 * Let's say we create a min heap.
 * 
 * We put 6 in it.
 * for 6 -> 6
 * For 5 -> 5 6
 * For 3 -> 3 5 6
 * For 2 -> 2 3 5 6
 * Since k is 3, whatever value is at the top, we get our first array element
 * arr[0] = 2
 * We are not increasing the value of our heap. It will be constant of size k.
 * Since it is constant K, our sorting will not take value greater than nlogk.
 * So we pop 2, and arr[0] = 2.
 * 
 * For 8 -> 3 5 6 8
 * pop() -> arr[1] = 3
 * 
 * For 10 -> 5 6 8 10
 * pop() -> arr[2] = 5
 * 
 * For 7 -> 6 8 9 10
 * pop() -> arr[3] = 6
 * 
 * Now, we are left with our minHeap 8 9 10.
 * We can easily put these values in our new array while minheap is not empty.
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> sortKSortedArray(vector<int> &input, int k) {
    vector<int> output = vector<int>();

    // We need minimum element at the top, so use min heap
    priority_queue<int, vector<int>, greater<int>> minHeap = 
        priority_queue<int, vector<int>, greater<int>>();

    for(int i=0; i<input.size(); i++) {
        int item = input[i];
        minHeap.push(item);
        if(minHeap.size() > k) {
            int topItem = minHeap.top();
            minHeap.pop();
            output.push_back(topItem);
        }
    }

    while(!minHeap.empty()) {
        int topItem = minHeap.top();
        minHeap.pop();
        output.push_back(topItem);
    }

    return output;
}

int main() {
    vector<int> input = vector<int>({6, 5, 3, 2, 8, 10, 9});
    int k = 3;
    cout << "Input: " << endl;
    printVector(input);
    cout << "k: " << k << endl;

    vector<int> output = sortKSortedArray(input, k);
    cout << "Output: " << endl;
    printVector(output);

    return 0;
}