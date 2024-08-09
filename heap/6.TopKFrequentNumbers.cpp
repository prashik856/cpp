/**
 * Top K frequent numbers
 * 
 * Given an array of element, we need to print top k frequent numbers.
 * 
 * Example:
 * arr[]: {1, 1, 1, 3, 2, 2, 4}
 * k: 2
 * Output: 
 * [1, 2]
 * 
 * Since 1 and 2 has occured 3 and 2 times respectively.
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> getTopKFrequentNumbers(vector<int> &input, int k) {
    vector<int> output = vector<int>(k, 0);
    unordered_map<int, int> frequencyMapping = unordered_map<int, int>();
    for(int i=0; i<input.size(); i++) {
        int item = input[i];
        if(frequencyMapping.find(item) == frequencyMapping.end()) {
            // not found
            frequencyMapping[item] = 1;
        } else {
            frequencyMapping[item]++;
        }
    }

    // We want top frequent element. That means maximum values.
    // We need to use min heap, with pairs
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap = 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>();

    for(unordered_map<int, int>::iterator it=frequencyMapping.begin(); it!= frequencyMapping.end(); it++) {
        // cout << "Key: " << it->first << " | value: " << it->second << endl;
        int pairFirst = it -> second;
        int pairSecond = it -> first;
        pair<int, int> item = pair<int, int>({pairFirst, pairSecond});
        minHeap.push(item);

        if(minHeap.size() > k) {
            minHeap.pop();
        }
    }

    int index = output.size() - 1;
    while(!minHeap.empty()) {
        pair<int, int> item = minHeap.top();
        minHeap.pop();

        output[index] = item.second;
        index--;
    }

    return output;
}

int main() {
    vector<int> input = vector<int>({{2, 2, 2, 3, 2, 2, 4, 5, 5, 9, 9, 4, 4, 2, 3, 5, 7, 10}});
    int k = 3;
    cout << "Input: " << endl;
    printVector(input);
    cout << "K: " << k << endl;

    vector<int> output = getTopKFrequentNumbers(input, k);
    cout << "Output: " << endl;
    printVector(output);

    return 0;
}