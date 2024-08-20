/**
 * Nearest Greater to Right
 * Next largest element
 * 
 * Given an array, print the next greater element for every element.
 * The next greater element for an item x is the first greater element on the 
 * right side of x in the array.
 * Elements for which no greater element exists, consider next it's next greater
 * element is -1.
 * 
 * Input: 
 * arr[]: {4, 5, 2, 25}
 * Output: {5, 25, 25, -1}
 * 
 * arr[]: {13, 7, 6, 12}
 * Output: {-1, 12, 12, -1}
 * 
 * Identification:
 * We can see that our input is provided an array.
 * And for every element i, we will have the second loop j, which is dependent on i.
 * The loop will go like this:
 * for(int i=0; i<n; i++) {
 *  for(int j=i+1; j<n; j++) {
 *  }
 * }
 * Since j is dependent on i, we can see that this question can be solved using stack.
 * 
 * Solution worked.
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<long long> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<long long> getNextGreaterToRight(vector<long long> &input, int n) {
    vector<long long> output = vector<long long>(input.size(), -1);
    
    stack<long long> st = stack<long long>();
    for(int i=n-1; i>=0; i--) {
        long long item = input[i];

        if(st.empty()) {
            // stack empty
            st.push(input[i]);
            output[i] = -1;
            continue;
        }

        while(!st.empty()) {
            long long top = st.top();
            if(top > item) {
                // got it
                output[i] = top;
                st.push(item);
                break;
            } else {
                st.pop();
            }
        }

        // if stack is empty
        if(st.empty()) {
            output[i] = -1;
            st.push(item);
        }
    }

    return output;
}

int main() {
    vector<long long> input = vector<long long>({6, 8, 0, 1, 3});
    cout << "Input: " << endl;
    printVector(input);

    vector<long long> output = getNextGreaterToRight(input, input.size());
    cout << "Output: " << endl;
    printVector(output);

    return 0;
}