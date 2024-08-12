/**
 * Connect Ropes to minimize cost
 * 
 * Given n ropes of different lengths, we need to connect these ropes into one rope.
 * the cost to connect them is equal to their sum.
 * 
 * We need to connect the ropes with minimum cost.
 * 
 * E.g. We are given 4 ropes of length, 4, 3, 2, and 6. 
 * We can connecto ropes in the following ways:
 * 1. First connecto ropes of length 2, 3. We have 3 ropes of length 4, 6, and 5.
 * 2. Now connet ropes of length 4, 5. Now we have two ropes of length 6 and 9.
 * 3. Finally connect the two ropes and all ropes have connected.
 * 
 * Total cost of connecting all ropes is: 5 + 9 + 15 = 29.
 * This is the optimized cost for connecting ropes.
 * 
 * Other ways of connecting ropes would have same or mor cost.
 * But we need to get the optimized one.
 * 
 * How to we solve it using priority queue?
 * What we can do is to useMin Heap, and make use of the top two element always to add up.
 * We always take the min 2 ropes at a time.
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int getMinCost(vector<int> &input) {
    int output = 0;

    // get min heap
    priority_queue<int, vector<int>, greater<int>> minHeap = 
        priority_queue<int, vector<int>, greater<int>>();

    for(int i=0; i<input.size(); i++) {
        int item = input[i];
        minHeap.push(item);
    }

    while(minHeap.size() != 1) {
        int top1 = minHeap.top();
        minHeap.pop();
        int top2 = minHeap.top();
        minHeap.pop();

        output = output + top1 + top2;

        int newItem = top1 + top2;
        minHeap.push(newItem);
    }

    return output;
}

int main() {
    vector<int> input = vector<int>({1, 2, 3, 4, 5, 6});
    cout << "Input: " << endl;
    printVector(input);

    int output = getMinCost(input);
    cout << "Output: " << output << endl;

    return 0;
}