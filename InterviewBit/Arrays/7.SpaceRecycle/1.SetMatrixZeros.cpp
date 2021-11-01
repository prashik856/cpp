/*
Problem Description

Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.
Note: This will be evaluated on the extra memory used. Try to minimize the space and time complexity.

Input Format:

The first and the only argument of input contains a 2-d integer matrix, A, of size M x N.
Output Format:

Return a 2-d matrix that satisfies the given conditions.
Constraints:

1 <= N, M <= 1000
0 <= A[i][j] <= 1
Examples:

Input 1:
    [   [1, 0, 1],
        [1, 1, 1], 
        [1, 1, 1]   ]


Output 1:
    [   [0, 0, 0],
        [1, 0, 1],
        [1, 0, 1]   ]



Input 2:
    [   [1, 0, 1],
        [1, 1, 1],
        [1, 0, 1]   ]



Output 2:
    [   [0, 0, 0],
        [1, 0, 1],
        [0, 0, 0]   ]


*/
/*
Solution Approach:
For every 0 that we encounter in the 2D array, we store the value of row and column in two sets.
And then set the values of all the rows and columns in the sets to 0.
*/
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr) {
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print2DVector(vector< vector<int> > arr) {
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector< vector<int> > solve(vector< vector<int> > arr) {
    int n = arr.size();
    int m = arr[0].size();

    set<int> row;
    set<int> col;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++){
            if(arr[i][j] == 0) {
                row.insert(i);
                col.insert(j);
            }
        }
    }

    // cout << "Here" << endl;
    set<int>::iterator itr;
    for(itr = row.begin(); itr!=row.end(); itr++){
        int rowValue = *itr;
        for(int j=0; j<m; j++){
            arr[rowValue][j] = 0;
        }
    }
    // cout << "Here" << endl;
    for(itr = col.begin(); itr!=col.end(); itr++){
        int colValue = *itr;
        // cout << "Col Value: " << colValue << endl;
        for(int j=0; j<n; j++){
            arr[j][colValue] = 0;
        }
    }
    // cout << "Here" << endl;
    return arr;
}

int main() {
    int t;
    cin >> t;
    for(int z=0; z<t; z++) {
        int m,n; 
        cin >> m >> n;
        cout << "Matrix is of size: " << m << "x" << n << endl;
        vector< vector<int> > arr(m, vector<int>(n, 0));
        cout << "Given input array is: " << endl;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int temp;
                cin >> temp;
                arr[i][j] = temp;
                cout << temp << " ";
            }
            cout << endl;
        }
        cout << endl;
        
        vector< vector<int> > result = solve(arr);
        cout << "Result: " << endl;
        print2DVector(result);

        cout << endl;
    }
    return 0;
}