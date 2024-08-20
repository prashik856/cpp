/**
 * Nearest Smaller to Right
 * 
 * Given an array of integers, find the closest (not considering distance, but value) 
 * smaller on right of every element. If an element has no smaller on the right side, print -1.
 * 
 * Input:
 * arr[]: {1, 3, 2, 4}
 * Output: {-1, 2, -1, -1}
 * 
 * This again is a variation of our previous question.
 * this time, we need to find the nearest smaller element to the right.
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<long long> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<long long> getNextSmallerToRight(vector<long long> &input, int n) {
    vector<long long> output = vector<long long>(n, -1);

    stack<long long> st = stack<long long>();
    for(int i=n-1; i>=0; i--) {
        long long item = input[i];

        if(st.empty()) {
            st.push(item);
            continue;
        }

        while(!st.empty()) {
            long long top = st.top();

            if(top < item) {
                output[i] = top;
                st.push(item);
                break;
            } else {
                st.pop();
            }
        }

        if(st.empty()) {
            st.push(item);
        }
    }

    return output;
}

int main() {
    vector<long long> input = vector<long long>({4, 5, 2, 10, 8});
    cout << "Input: " << endl;
    printVector(input);

    vector<long long> output = getNextSmallerToRight(input, input.size());
    cout << "Output: " << endl;
    printVector(output);

    return 0;
}

