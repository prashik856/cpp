/**
 * Rainwater Trapping
 * 
 * Minimum Stack Implementation
 * - Using Extra Space
 * - Using O(1) space
 * 
 * Implement Stack using heap
 * The celebrity problem
 * Longest valid parenthesis
 * Iterative Tower of Hanoi
 * 
 * 
 * Problem Statement:
 * Given an array of N non-negative integers, arr[] representing an elevation map, where
 * width of each bar is 1, compute how much water it can trap after rain.
 * 
 * Example:
 * Input: 
 * arr[] = {3, 0, 1, 0, 4, 0, 2}
 * Output: 10
 * 
 * Input:
 * arr[] = {3, 0, 2, 0, 4}
 * Output: 7
 * We can trap 3 units of water between 3 and 2
 * 1 unit on top of bar 2, and 3 units between 2 and 4.
 * 
 * 
 * My understanding:
 * We need to find the maximum left and maximum right value of every element
 * in the array.
 * The corner elements value will always be -1 as they define the boundary.
 * 
 * Then, for every index, we can easily calculate the amount of water it 
 * can trap.
 * It can be calculated using this:
 * min(arr[leftMax], arr[rightMax]) - arr[i]
 * We can add this value for every index, and we will get our answer.
 */
#include <iostream>
#include <vector>
#include<stack>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int rainwaterTrapping(vector<int> arr) {
    int output = 0;
    int n = arr.size();

    stack<int> st = stack<int>();

    vector<int> greatestLeft = vector<int>(n, -1);
    vector<int> greatestRight = vector<int>(n, -1);

    for(int i=0; i<n; i++) {
        int item = arr[i];

        if(st.empty()) {
            st.push(item);
            continue;
        }

        while(!st.empty()) {
            int top = st.top();
            if(top >= item) {
                // we can keep top value as is.
                greatestLeft[i] = top;
                break;
            } else {
                st.pop();
            }
        }

        if(st.empty()) {
            // all values to the left are smaller
            st.push(item);
        }
    }

    cout << "Greatest Left Array: " << endl;
    printVector(greatestLeft);

    while(!st.empty()) {
        st.pop();
    }

    for(int i=n-1; i>=0; i--) {
        int item = arr[i];

        if(st.empty()) {
            st.push(item);
            continue;
        }

        while(!st.empty()) {
            int top = st.top();
            if(top >= item) {
                // we can keep top value as is.
                greatestRight[i] = top;
                break;
            } else {
                st.pop();
            }
        }

        if(st.empty()) {
            // all values to the left are smaller
            st.push(item);
        }

    }

    cout << "Greatest Right Vector: " << endl;
    printVector(greatestRight);

    for(int i=0; i<n; i++) {
        int leftMax = greatestLeft[i];
        int rightMax = greatestRight[i];

        if(leftMax == -1 || rightMax == -1) {
            // this guy cannot store water
            continue;
        } else {
            // calculate water stored for current index
            int waterStored = min(leftMax, rightMax) - arr[i];

            // update output
            output = output + waterStored;
        }
    }

    return output;
}

int main() {
    vector<int> arr = vector<int>({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1});
    cout << "Input: " << endl;
    printVector(arr);

    int output = rainwaterTrapping(arr);
    cout << "Output: " << output << endl;

    return 0;
}