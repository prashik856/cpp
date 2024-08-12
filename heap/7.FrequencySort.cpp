/**
 * Frequency Sort
 * 
 * Print Elements of an array in the increasing frequency.
 * If 2 numbers have same frequency, then print the one which came first
 * 
 * Input: arr[] = {2, 5, 2, 8, 5, 6, 8, 8}
 * Output: arr[] = {8, 8, 8, 2, 2, 5, 5, 6}
 * 
 * We need to make use of two maps, one to store index and one to store the freq of items.
 * 
 * Now, we again make use of two heaps,
 * first max heap is used to store values freq in decending order.
 * We use second min heap to store all index and freq pair of all values whole freq is same.
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

vector<int> frequencySort(vector<int> &input) {
    vector<int> output = vector<int>();

    // store frequency
    // Store lowest index
    unordered_map<int, int> indexMapping = unordered_map<int, int>();
    unordered_map<int, int> freq = unordered_map<int, int>();
    for(int i=0; i<input.size(); i++) {
        int item = input[i];
        if(freq.find(item) == freq.end()) {
            freq[item] = 1;
            indexMapping[item] = i;
        } else {
            freq[item]++;
        }
    }

    // We need freq in decending order
    // So we make use of maxHeap, so our top is highest
    priority_queue<pair<int, int>> maxHeap = priority_queue<pair<int, int>>();

    // Create pairs and put them in heap
    for(int i=0; i<input.size(); i++) {
        int item = input[i];
        if(freq.find(item) == freq.end()) {
            continue;
        } else {
            // get count
            int count = freq[item];
            // create pair
            pair<int, int> val = pair<int, int>({count, item});
            // remove from map
            freq.erase(item);
            // put pair in hashmap
            maxHeap.push(val);
        }
    }   

    while(!maxHeap.empty()) {
        pair<int, int> topValue = maxHeap.top();
        maxHeap.pop();
        int topValueIndex = indexMapping[topValue.second];

        // Create minHeap to store pair of index
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap = 
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>();
        pair<int, int> topIndexCount = pair<int, int>({topValueIndex, topValue.first});
        minHeap.push(topIndexCount);

        // loop through till we have similar count values
        while(true) {
            if(maxHeap.empty()) {
                break;
            }
            pair<int, int> currentTopValue = maxHeap.top();
            if(currentTopValue.first == topValue.first) {
                maxHeap.pop();
                int currentTopValueIndex = indexMapping[currentTopValue.second];
                minHeap.push(pair<int,int>({currentTopValueIndex, currentTopValue.first}));
            } else {
                break;
            }
        }

        while(!minHeap.empty()) {
            pair<int, int> item = minHeap.top();
            minHeap.pop();

            int indexValue = item.first;
            int countValue = item.second;

            while(countValue != 0) {
                int outputItem = input[indexValue];
                output.push_back(outputItem);
                countValue--;
            }
        }
    }

    return output;
}

int main() {
    vector<int> input = vector<int>({6, 2, 3, 5, 2, 8, 5, 6, 8, 8, 3});
    cout << "Input Vector: " << endl;
    printVector(input);

    vector<int> output = frequencySort(input);
    cout << "Output: " << endl;
    printVector(output);

    return 0;
}