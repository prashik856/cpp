/**
 * Given an unsorted array and two numbers x and k, find k closest values to x.
 * 
 * Input:
 * arr = {10, 2, 14, 4, 7, 6}
 * x = 5
 * k = 3
 * 
 * Identification:
 * We are given a k, are we given an array.
 * We have a number x, and we need to find k closest values to x.
 * 
 * Since we need to find k closest values, we are provided k.
 * And we know that closest values are usually smallest values, that means we need to 
 * find smallest value close to x.
 * That means, we can use heap here.
 * 
 * We can make use of diff array here, and make sure that we use pairs to keep track of index.
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> getKClosestNumbers(vector<int> &input, int x, int k) {
    vector<int> output = vector<int>(k, 0);

    vector< pair<int, int>> diffVector = vector<pair<int,int>>();
    for(int i=0; i<input.size(); i++) {
        int item = input[i];
        int diff = item - x;
        if(diff < 0) {
            diff = -1 * diff;
        }
        pair<int, int> newPair = pair<int, int>();
        newPair.first = diff;
        newPair.second = i;
        // we got absolute value
        diffVector.push_back(newPair);
    }

    // Now, we have stored diffVector with value and index.
    // Since we need minimum values, we create max heap
    priority_queue< pair<int, int>> maxHeap = priority_queue<pair<int, int>>();
    for(int i=0; i<diffVector.size(); i++) {
        pair<int, int> item = diffVector[i];
        maxHeap.push(item);
        if(maxHeap.size() > k) {
            maxHeap.pop();
        }
    }

    // Now, our max heap stores the 3 closes values
    int count = output.size() - 1;
    while(!maxHeap.empty()) {
        pair<int, int> topValue = maxHeap.top();
        maxHeap.pop();
        int index = topValue.second;
        int itemValue = input[index];
        output[count] = itemValue;
        count--;
    }

    return output;
}

int main() {
    vector<int> input = vector<int>({5, 6, 7, 8, 9});
    int k = 3;
    int x = 7;
    cout << "Input: " << endl;
    printVector(input);
    cout << "k: " << k << endl;
    cout << "x: " << x << endl;

    vector<int> output = getKClosestNumbers(input, x, k);
    cout << "Output: " << endl;
    printVector(output);

    return 0;
}