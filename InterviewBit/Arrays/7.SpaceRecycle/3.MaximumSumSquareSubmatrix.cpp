/*
Problem Description

Given a 2D integer matrix A of size N x N find a B x B submatrix where B<= N and B>= 1, such that sum of all the elements in submatrix is maximum.



Problem Constraints
1 <= N <= 103.

1 <= B <= N 

-102 <= A[i][j] <= 102.



Input Format
First arguement is an 2D integer matrix A.

Second argument is an integer B.



Output Format
Return a single integer denoting the maximum sum of submatrix of size B x B.



Example Input
Input 1:

 A = [
        [1, 1, 1, 1, 1]
        [2, 2, 2, 2, 2]
        [3, 8, 6, 7, 3]
        [4, 4, 4, 4, 4]
        [5, 5, 5, 5, 5]
     ]
 B = 3
Input 2:

 A = [
        [2, 2]
        [2, 2]
    ]
 B = 2


Example Output
Output 1:

 48
Output 2:

 8


Example Explanation
Explanation 1:

    Maximum sum 3 x 3 matrix is
    8 6 7
    4 4 4
    5 5 5
    Sum = 48
Explanation 2:

 Maximum sum 2 x 2 matrix is
  2 2
  2 2
  Sum = 8
*/
/*
Solution Approach:
Solution Approach
Brute Force:
A Simple Solution is to consider all possible sub-squares of size B x B in our input matrix and find the one which has maximum sum.
Time complexity of above solution is O(N2B2).
This will timeout for the given constraints.


Efficient Approach:
We can solve this problem in O(N2) time.

The idea is to preprocess the given square matrix. 
In the preprocessing step, calculate sum of all vertical strips of size B x 1 in a temporary square matrix stripSum[][].
Once we have sum of all vertical strips, 
we can calculate sum of first sub-square in a row as sum of first B strips in that row, 
and for remaining sub-squares, 
we can calculate sum in O(1) time by removing the leftmost strip of previous subsquare and adding the rightmost strip of new square.
*/
#include<bits/stdc++.h>
using namespace std;

void print2DVector(vector< vector<int> >  arr) {
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int solve(vector< vector<int> >  arr, int b){
    int result = numeric_limits<int>::min();
    int n = arr.size();
    vector< vector<int> > stripArray(n-b+1, vector<int>(n, 0));

    // Creating split array
    // We store the values of sum of columns of all the strips of size Bx1.
    for(int i=0; i<n; i++){
        int currentSum = 0;
        for(int j=0; j<n; j++){
            if(j < b - 1){
                currentSum += arr[j][i];
            } else if(j == b - 1) {
                currentSum += arr[j][i];
                stripArray[j+1-b][i] = currentSum;
            } else if(j > b - 1){
                currentSum += arr[j][i];
                currentSum -= arr[j-b][i];
                stripArray[j+1-b][i] = currentSum;
            }
        }
    }

    // cout << "Split Array is: " << endl;
    // print2DVector(stripArray);

    cout << "Calculating max Sum: " << endl;
    for(int i=0; i<stripArray.size(); i++){
        int currentSum = 0;
        for(int j=0; j<stripArray[i].size(); j++){
            if(j < b - 1){
                currentSum += stripArray[i][j];
            } else if(j == b-1){
                // We have the first sum here
                currentSum += stripArray[i][j];
                result = max(result, currentSum);
            } else if(j > b-1){
                currentSum += stripArray[i][j];
                currentSum -= stripArray[i][j-b];
                result = max(result, currentSum);
            }
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;
    for(int z=0; z<t; z++) {
        int n, b; 
        cin >> n >> b;
        cout << "Given size of array is: " << n << "x" << n << endl;
        cout << "Given submatrix size is: " << b << "x" << b << endl;
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
        
        int result = solve(arr, b);
        cout << "Result: " <<  result << endl;

        cout << endl;
    }
    return 0;
}