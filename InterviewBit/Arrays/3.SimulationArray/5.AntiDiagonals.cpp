/*
Problem Description

Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.
Example:

Input:

1 2 3
4 5 6
7 8 9
Return the following:
[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]


Input: 
1 2
3 4
Return the following: 
[
  [1],
  [2, 3],
  [4]
]
*/

/*
Solution Approach:
We already know how to travel spirally.
Here, rather than spirally, we first want to go right, and then down.
While downing that, we want to travel diagonally to the left and storing those values.
Need to keep track of values of rows and columns of the array.
*/

#include<bits/stdc++.h>
using namespace std;

void print2DArray(vector< vector<int> > arr){
    cout << "Given array is: " << endl;
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

vector< vector<int> > solve(vector< vector<int> > arr) {
    int n = arr.size();
    vector< vector<int> > result;
    int x1=0,y1=0,x2=n-1,y2=n-1;

    int index = 0;
    // go right
    for(int i=x1; i<x2; i++){
        int row = 0;
        int col = i;
        result.push_back(vector<int>());
        while(row < n && col >= 0){
            result[index].push_back(arr[row][col]);
            // cout << arr[row][col] << " ";
            row++;
            col--;
        }
        index++;
        // cout << endl;
    }

    // go down
    // cout << "Going down" << endl;
    for(int i=y1; i<=y2; i++){
        int row = i;
        int col = x2;
        result.push_back(vector<int>());
        while(row < n && col >=0) {
            result[index].push_back(arr[row][col]);
            // cout << arr[row][col] << " ";
            row++;
            col--;
        }
        index++;
        // cout << endl;
    }

    return result;
}

int main() {
    int t;
    cin >> t;
    for(int z=0; z<t; z++) {
        int n; 
        cin >> n;
        cout << n << endl;
        vector< vector<int> > arr(n, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int temp;
                cin >> temp;
                arr[i][j] = temp;
            }
        }
        print2DArray(arr);

        vector< vector<int> > result = solve(arr);
        cout << "Result: " <<  endl;
        print2DArray(result);
        cout << endl;
    }
    return 0;
}