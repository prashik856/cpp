/**
 * Maximum Area of Histogram
 * 
 * Find the largest area possible in the given histogram where the largest rectangle
 * can be made of a number of contiguous bars.
 * For simplicity, assume all bars have same width and the width is 1 unit.
 * 
 * Before solving this problem, 
 * We know that in the previous StockSpanProblem, we calculated index of Nearest Greater 
 * Left for every element using stack.
 * We did it by using pairs, and we put the index of each element in that pair.
 * 
 * If we can find the whole vector of Nearest Greater Left, that means we can find the 
 * Nearest Greater Right, Nearest Smaller Right, and Nearest Smaller Left vector as well.
 * 
 * Input:
 * arr[]: 6 2 5 4 5 1 6
 * 
 * Given these histograms, we need to find the maximum are of this histogram.
 * Basically we need to find a rectangle in this graph, whose area is maximum.
 * 
 * So, basically for every building, we need to see if we can expand it or not.
 * For that, what we can do is to calculate nearest smaller left and nearest smaller right
 * of every element.
 * And then using the index of these nearest smaller left and right, we should be able to 
 * calculate the maximum area of the histogram.
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

int maxAreaOfHistogram(vector<int> arr) {
    int output = 0;
    int n = arr.size();

    vector<int> smallerLeft = vector<int>(n, -1);
    vector<int> smallerRight = vector<int>(n, n);

    // stack 
    stack<pair<int, int>> st = stack<pair<int, int>>();

    for(int i=0; i<n; i++) {
        pair<int, int> item = pair<int, int>({arr[i], i});

        if(st.empty()) {
            st.push(item);
            // left one is initialzed to -1
            continue;
        }

        while(!st.empty()) {
            pair<int, int> top = st.top();

            if(top.first < item.first) {
                // top value is small
                smallerLeft[i] = top.second;
                st.push(item);
                break;
            } else {
                st.pop();
            }
        }

        // if stack is actually empty after all the popping
        if(st.empty()) {
            st.push(item);
            // value will be -1, already initialized.
        }
    }

    cout << "Smaller Left" << endl;
    printVector(smallerLeft);

    // clear stack
    while(!st.empty()) {
        st.pop();
    }

    for(int i=n-1; i>=0; i--) {
        pair<int, int> item = pair<int, int>({arr[i], i});

        // if stack empty, push
        if(st.empty()) {
            st.push(item);
            continue;
        }

        while(!st.empty()) {
            pair<int, int> top = st.top();

            if(top.first < item.first) {
                st.push(item);
                smallerRight[i] = top.second;
                break;
            } else {
                st.pop();
            }
        }

        if(st.empty()) {
            // stack is empty
            st.push(item);
        }
    }

    cout << "Smaller Right: " << endl;
    printVector(smallerRight);

    for(int i=0; i<n; i++) {
        int height = arr[i];
        int leftSmallerIndex = smallerLeft[i];
        int rightSmallerIndex = smallerRight[i];
        int left = 0;
        int right = 0;
        if(leftSmallerIndex == -1) {
            left = i;
        } else {
            left = i - leftSmallerIndex - 1;
        }

        if(rightSmallerIndex == n) {
            right = n - i - 1;
        } else {
            right = rightSmallerIndex - i - 1;
        }
        int width = 1 + left + right;
        int area = width * arr[i];
        output = max(output, area);
    }

    return output;
}

int main() {
    vector<int> arr = vector<int>({6, 2, 5, 4, 5, 1, 6});
    cout << "Input: " << endl;
    printVector(arr);

    int output = maxAreaOfHistogram(arr);
    cout << "Output: " << output << endl;

    return 0;
}