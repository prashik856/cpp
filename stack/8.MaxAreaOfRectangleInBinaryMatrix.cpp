/**
 * Maximum area of rectangle in Binary Matrix
 * 
 * Given a 2D matrix, 
 * 0 1 1 0
 * 1 1 1 1
 * 1 1 1 1 
 * 1 1 0 0
 * 
 * Difference between MAH and this question
 * - MAH had natural numbers and here we have binary numbers
 * 
 * In MAH, we had 1D array, in this question, we are given a 2D array.
 * 
 * Can we compress the 2D array to 1D array, and get the area from there?
 * We can do this:
 * Create a new vector with size equal to the number of columns.
 * Now,
 * This vector will be equal to the first row of the matrix, for the first row.
 * For the subsequent rows, if arr[row][i] == arr[row+1][i] == 1,
 * our vector value will increment by 1.
 * Else, if our arr[row+1][i] == 0, our vector value will crash back to 0.
 * 
 * And after this calculation, for every row, we will calculate the 
 * Maximum Area of Histogram.
 * 
 * The maximum of Maximum Area of Histogram is our required answer.
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

void print2DVector(vector< vector<int> > arr) {
    for(int i=0; i<arr.size(); i++) {
        printVector(arr[i]);
        cout << endl;
    }
}

int getMaxAreaOfHistogram(vector<int> &arr) {
    int output = 0;
    int n = arr.size();

    vector<int> smallestLeft = vector<int>(n, -1);
    vector<int> smallestRight = vector<int>(n, n);

    stack<pair<int, int>> st = stack<pair<int, int>>();

    // get smallest left
    for(int i=0; i<n; i++) {
        pair<int, int> item = pair<int, int>({arr[i], i});

        if(st.empty()) {
            st.push(item);
            continue;
        }

        while(!st.empty()) {
            pair<int, int> top = st.top();

            if(top.first < item.first) {
                st.push(item);
                smallestLeft[i] = top.second;
                break;
            } else {
                st.pop();
            }
        }

        if(st.empty()) {
            st.push(item);
        }
    }

    // empty stack
    while(!st.empty()) {
        st.pop();
    }

    // get smallest right
    for(int i=n-1; i>=0; i--) {
        pair<int, int> item = pair<int, int>({arr[i], i});

        if(st.empty()) {
            st.push(item);
            continue;
        }

        while(!st.empty()) {
            pair<int, int> top = st.top();

            if(top.first < item.first) {
                st.push(item);
                smallestRight[i] = top.second;
                break;
            } else {
                st.pop();
            }
        }

        if(st.empty()) {
            st.push(item);
        }
    }

    cout << "Smallest Left: " << endl;
    printVector(smallestLeft);

    cout << "Smallest Right: " << endl;
    printVector(smallestRight);

    for(int i=0; i<n; i++) {
        int height = arr[i];

        int leftIndex = smallestLeft[i];
        int rightIndex = smallestRight[i];

        int left = i - leftIndex - 1;
        int right = rightIndex - i - 1;
        int width = 1 + left + right;

        int area = width * height;
        output = max(output, area);
    }

    return output;
}

int getMaxAreaOfRectangle(vector<vector<int> > arr) {
    int output = 0;
    int n = arr.size();

    vector<int> compressed = vector<int>(n, 0);
    for(int i=0; i<arr.size(); i++) {
        for(int j=0; j<arr[i].size(); j++) {
            if(i==0) {
                compressed[j] = arr[i][j]; 
            } else {
                // both values are 1
                if(arr[i][j] == 1 && arr[i][j] == arr[i-1][j]) {
                    compressed[j]++;
                } else if(arr[i][j] == 1 && arr[i][j] != arr[i-1][j]) {
                    // current value is 1 but last row's value is 0
                    compressed[j] = 1;
                } else {
                    // current value is 0
                    compressed[j] = 0;
                }
            }
        }

        cout << "Current Input to Max Area of Histogram: " << endl;
        printVector(compressed);

        int tempOutput = getMaxAreaOfHistogram(compressed);
        cout << "Temp Output: " << tempOutput << endl;
        cout << endl;

        output = max(output, tempOutput);
    }

    return output;
}

int main() {
    vector< vector<int> > arr = vector< vector<int>> ({
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    });
    cout << "Input: " << endl;
    print2DVector(arr);

    int output = getMaxAreaOfRectangle(arr);
    cout << "Output: " << output << endl;

    return 0;
}