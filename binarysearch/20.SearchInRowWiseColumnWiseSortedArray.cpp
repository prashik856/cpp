/**
 * Search in Row wise and column wise sorted matrix
 * 
 * Given a 2D matrix where the rows and columns are sorted. 
 * Given an element, we need to find an element in the matrix.
 * 
 * Input: 
 * arr[][]: { {10, 20, 30, 40},
 *            {15, 25, 35, 45},
 *            {27, 29, 37, 48},
 *            {32, 33, 39, 50}}
 * Key: 29
 * 
 * Output: (2, 1)
 * Output the row and column index.
 * 
 * Approach:
 * The given matrix is row wise and column wise sorted.
 * 
 * Brute force? -> O(n^2) solution.
 * 
 * We start from top right,
 * i=0, j=m-1, this will be our mid.
 * 
 * We have (n x m) matrix.
 * We compare top right by key,
 * Now, can we divide our matrix into smaller part?
 * Yes, we can. If our current value is greater than key, that means,
 * the whole column is greater than key.
 * We can do j--.
 * 
 * Let key = 29.
 * i=0, j = 3;
 * 
 * 40 > 29.
 * We need to scrap the whole column as all values will be greater than 29.
 * j--;
 * 
 * Similarly, we reach column which starts from 30.
 * Since 30 > 29.
 * Again, we can scrap the column.
 * j--;
 * 
 * We reach i=0, j=1.
 * 20 < 29.
 * That means our answer can lie here.
 * Now, we have 10 on the left, and 25 on bottom.
 * Since 25 > 10 and 25 < 29.
 * We need to go towards 25.
 * i++;
 * 
 * i=1, j=1
 * left we have 15, down we have 29.
 * since 29 > 15 and 29 <= 29, we can go down.
 * i++
 * 
 * i = 2, j=1, since this value is equal to 29.
 * We get our output.
 * 
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print2DVector(vector< vector<int> > &arr) {
    for(int i=0; i<arr.size(); i++) {
        printVector(arr[i]);
    }
    cout << endl;
}

vector<int> findKeyInMatrix(vector<vector<int>> &input, int key) {
    vector<int> output = vector<int>();
    int n = 4;
    int m = 4;
    int i=0;
    int j= m - 1;

    while(i<n && j>=0) {
        if(input[i][j] == key) {
            output.push_back(i);
            output.push_back(j);
            break;
        }

        if(input[i][j] > key) {
            // go to left column
            j--;
        } else if(input[i][j] < key && i+1 < n) {
            if(input[i+1][j] <= key) {
                i++;
            } else {
                j--;
            }
        } else if(input[i][j] < key && i+1 >= n) {
            i++;
        }
    }

    return output;
}

int main() {
    vector< vector<int>> input = vector< vector<int>>(
        {   {10, 20, 30, 40},
            {15, 25, 35, 45},
            {27, 29, 37, 48},
            {32, 33, 39, 50}});
    cout << "Input Matrix: " << endl;
    print2DVector(input);

    int key = 36;
    cout << "Key: " << key << endl;
    
    vector<int> output = findKeyInMatrix(input, key);
    cout << "Output: " << endl;
    printVector(output);

    return 0;
}