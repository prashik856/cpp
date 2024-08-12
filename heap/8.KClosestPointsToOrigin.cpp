/**
 * K Closest Points to Origin
 * 
 * Given a list of points on the 2D plane and an integer K. The task is to find the 
 * closest points to the origin ad print them.
 * 
 * Input: 
 * arr[] = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}}
 * K=2
 * 
 * Output: {{0, 1}, {-2, 2}}
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print2DVector(vector< vector<int> > arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<vector<int>> getClosestPoint(vector<vector<int>> &input, int k) {
    vector<vector<int>> output = vector<vector<int>>(k);

    // Create max heap since we need closest distance
    priority_queue< pair<long long, int>> maxHeap = priority_queue<pair<long long, int>>();

    for(int i=0; i<input.size(); i++) {
        long long x = input[i][0];
        long long y = input[i][1];

        long long diff = x*x + y*y;
        pair<long long, int> diffIndexPair = pair<long long, int>({diff, i});

        maxHeap.push(diffIndexPair);
        if(maxHeap.size() > k) {
            maxHeap.pop();
        }
    }

    int outputIndex = output.size()-1;
    while(!maxHeap.empty()) {
        pair< long long, int> topValue = maxHeap.top();
        maxHeap.pop();

        int inputIndex = topValue.second;
        vector<int> inputValue = input[inputIndex];

        output[outputIndex] = inputValue;
        outputIndex--;
    }

    return output;
}

int main() {
    vector< vector<int>> input = vector<vector<int>>({{1, 3}, {-2, 2}, {5, 8}, {0, 1}});
    cout << "Input: " << endl;
    print2DVector(input);

    int k = 2;
    cout << "K: " << k << endl;

    vector<vector<int>> output = getClosestPoint(input, k);
    cout << "Output: " << endl;
    print2DVector(output);
    return 0;
}