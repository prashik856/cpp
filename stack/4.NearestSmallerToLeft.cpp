/**
 * Nearest Smaller to the Left
 * 
 * Given an array of integers, find the closest (not considering distance but value)
 * smaller on the left of every element. If an element has no smaller on the left side,
 * print -1.
 * 
 * Input: 
 * arr[]: {4, 5, 2, 25}
 * Output: {-1, 4, -1, 2}
 * 
 * This again a variation of the previous question.
 * Instead of greater element, we need to find a smaller element to the left
 * 
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<long long> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<long long> getNextSmallerToLeft(vector<long long> &input, int n) {
    vector<long long> output = vector<long long>(n, -1);

    stack<long long> st = stack<long long>();

    for(int i=0; i<input.size(); i++) {
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
    vector<long long> input = vector<long long>({5, 1, 3, 2, 4});
    cout << "Input: " << endl;
    printVector(input);

    vector<long long> output = getNextSmallerToLeft(input, input.size());
    cout << "Output: " << endl;
    printVector(output);

    return 0;
}