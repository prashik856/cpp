/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

You need to do this in place.

Note that if you end up using an additional array, you will only receive partial score.

Example:

If the array is

[
    [1, 2],
    [3, 4]
]
Then the rotated array becomes:

[
    [3, 1],
    [4, 2]
]
*/

/*
Solution Approach:
First, using a new martrix:
We just need last column of the new matrix to be equal to first row of original matrix, second last row to be equal to 2nd row and so on.


Second, using same matrix:
We just need 4 variables that we need to rotate:
here, they are temp1, temp2, temp3 and temp4.
Take care of how we are looping, and we just need to swap these values.
*/
#include<bits/stdc++.h>
using namespace std;

void print2DVector(vector< vector<int> > arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void solve(vector< vector<int> > &arr) {
    // No extra space
    int n = arr.size(); 
    // cout << "Temp values: " << endl;
    for(int i=0; i<n-1-i; i++){
        for(int j=i; j<n-1-i; j++) {
            int temp1 = arr[i][j];
            int temp2 = arr[j][n-1-i];
            int temp3 = arr[n-1-i][n-1-j];
            int temp4 = arr[n-1-j][i];
            // cout << temp1 << " " << temp2 << " " << temp3 << " " << temp4 << endl;
            arr[j][n-1-i] = temp1;
            arr[n-1-i][n-1-j] = temp2;
            arr[n-1-j][i] = temp3;
            arr[i][j] = temp4;
        }
        // cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    for(int z=0; z<t; z++) {
        int n; 
        cin >> n;
        cout << n << endl;
        cout << "Matrix is of size: " << n << "x" << n << endl;
        vector< vector<int> > arr(n, vector<int>(n, 0));
        cout << "Given input array is: " << endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int temp;
                cin >> temp;
                arr[i][j] = temp;
                cout << temp << " ";
            }
            cout << endl;
        }
        cout << endl;

        solve(arr);
        cout << "Result: " << endl;
        print2DVector(arr);
        cout << endl;
    }
    return 0;
}