/**
 * First Negative integer in every window size of K
 * 
 * Flow: 
 * 1) Problem statement - Input and Output
 * 2) Exmplaination 
 * Brute Fore and Using Previous Question
 * 3) Code
 * 
 * Input:
 * Array of int which can be positive or negative: 12 -1 -7 8 -15 30 16 18
 * window size k: 3
 * 
 * // when no negative integer, print 0
 * Output: -1 -1 -7 -15 -15 0 
 */

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> firstNegatvieIntegterWindow(vector<int> &arr, int w) {
    vector<int> output = vector<int>();
    queue<int> myQueue = queue<int>();
    int i=0,j=0;
    while(j<arr.size()) {
        if(j-i+1 <w) {
            if(arr[j] < 0) {
                myQueue.push(j);
            }
            j++;
        } else if(j-i+1 == w) {
            if(arr[j] < 0) {
                myQueue.push(j);
            }
            
            if(myQueue.size() > 0) {
                int arrIndex = myQueue.front();
                output.push_back(arr[arrIndex]);
                if(i == arrIndex) {
                    myQueue.pop();
                }
            } else {
                output.push_back(0);
            }

            i++;
            j++;
        }
    }

    return output;
}

vector<int> firstNegativeInteger(vector<int> &arr, int w) {
    vector<int> output = vector<int>();

    int i=0,j=0, k=0;
    vector<int> negIndex = vector<int>();
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] < 0) {
            negIndex.push_back(i);
        }
    }

    while(j<arr.size()) {
        if(j-i+1 <w) {
            j++;
        } else if(j-i+1 == w) {
            // window reached
            bool found = false;
            while(k < negIndex.size()) {
                int arrIndex = negIndex[k];
                if(arrIndex >=i && arrIndex <=j) {
                    output.push_back(arr[arrIndex]);
                    found = true;
                    break;
                } else if(arrIndex > j) {
                    break;
                } else {
                    k++;
                }
            }

            if(k >= negIndex.size() || !found) {
                output.push_back(0);
            }

            // at the end
            i++;
            j++;
        }
    }

    return output;
}

int main() {
    vector<int> arr = vector<int>({-12, 1, 7, 8, 15, 30, 16, 18});
    int k = 4;
    
    cout << "Input: " << endl;
    printVector(arr);
    
    cout << "Window Size: " << k << endl;

    vector<int> output = firstNegativeInteger(arr, k);

    // A better solution would be to keep track of a queue to store 
    // only negative integers.
    // And we keep track of this queue as we move along the window.

    cout << "Output: " << endl;
    printVector(output);

    output = firstNegatvieIntegterWindow(arr, k);
    cout << "Output with Queue: " << endl;
    printVector(output);
}