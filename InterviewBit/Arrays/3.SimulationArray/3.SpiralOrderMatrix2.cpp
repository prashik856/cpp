/*
Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order.

Input Format:

The first and the only argument contains an integer, A.
Output Format:

Return a 2-d matrix of size A x A satisfying the spiral order.
Constraints:

1 <= A <= 1000
Examples:

Input 1:
    A = 3

Output 1:
    [   [ 1, 2, 3 ],
        [ 8, 9, 4 ],
        [ 7, 6, 5 ]   ]

Input 2:
    4

Output 2:
    [   [1, 2, 3, 4],
        [12, 13, 14, 5],
        [11, 16, 15, 6],
        [10, 9, 8, 7]   ]
*/
#include<bits/stdc++.h>
using namespace std;

void print2DVector(vector< vector<int> > arr){
    cout << "Given 2D array is: " << endl;
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector< vector<int> > solve(int A){
    vector< vector<int> > result(A, vector<int>(A, 0));
    int x1=0,x2=A-1,y1=0,y2=A-1;
    int value = 1;
    while(true) {

        if(x1 >= x2 || y1 >= y2) {
            if(A%2 == 0){
                break;
            } else {
                result[y1][x1] = value;
                break;
            }
        }

        // go right
        for(int i=x1; i<x2; i++){
            result[y1][i] = value;
            value++;
        }

        // go down
        for(int i=y1; i<y2; i++){
            result[i][x2] = value;
            value++;
        }

        // go left
        for(int i=x2; i>x1; i--){
            result[y2][i] = value;
            value++;
        }

        // go up
        for(int i=y2; i>y1; i--){
            result[i][x1] = value;
            value++;
        }

        x1++;
        x2--;
        y1++;
        y2--;
    }
    
    // print2DVector(result);

    return result;
}

int main() {
    int t;
    cin >> t;
    for(int z=0; z<t; z++) {
        int n; 
        cin >> n;
        cout << n << endl;
        cout << "Given input is: " << n << endl;
        vector< vector<int> > result = solve(n);
        cout << "Result: " << endl;
        print2DVector(result);
        cout << endl;
    }
    return 0;
}
