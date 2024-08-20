/**
 * Stock Span Problem
 * 
 * The stock span problem is a financial problem where we have a series of n daily
 * price quotes for a stock and we need to calculate span of stock's price for all n days.
 * 
 * The span S[i] of the stock's price on a given day i, is defind as the maximum number of 
 * consecutive days just before the given day, for which the price of the stock on the 
 * current day is less than or equal to its price on the given day.
 * 
 * For example, if an array of 7 days prices is given as:
 * arr[]: {100, 80, 60, 70, 60, 75, 85}
 * then the span values of the corresponding 7 days are:
 * Output: {1, 1, 1, 2, 1, 4, 6}
 * 
 * Explanation:
 * This problem is very similar to finding the nearest greater value to the left.
 * For 100, it is -1, for 80, it is 100,
 * for 60, it is 80, for 70, it is 80. 
 * For 60, it is 70, for 75, it is 80
 * and at last for 85, it is 100.
 * 
 * Now, we need to update our stack to store the value of indexes as well.
 * This is because, our output needs to be difference between index of current
 * element and nearest greater value.
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<long long> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<long long> stockPlan(vector<long long> &input, int n) {
    vector<long long> output = vector<long long>(n, 1);

    stack<pair<long long, int>> st = stack<pair<long long, int>>();

    for(int i=0; i<n; i++) {
        int item = input[i];
        pair<long long, int> pairItem = pair<long long, int>({item, i});

        if(st.empty()) {
            st.push(pairItem);
            continue;
        }

        while(!st.empty()) {
            pair<long long, int> topPair = st.top();
            long long top = topPair.first;
            if(top >= item) {
                st.push(pairItem);
                output[i] = i - topPair.second;
                break;
            } else {
                st.pop();
            }
        }

        // got the greatest element
        if(st.empty()) {
            st.push(pairItem);
            output[i] = i + 1;
        }

    }

    return output;
}

int main() {
    vector<long long> input = vector<long long>({110, 100, 105, 80, 60, 70, 60, 75, 85, 110});
    cout << "Input: " << endl;
    printVector(input);

    vector<long long> output = stockPlan(input, input.size());
    cout << "Output: " << endl;
    printVector(output);

    return 0;
}