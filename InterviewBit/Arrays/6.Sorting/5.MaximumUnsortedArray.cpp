/*
You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.

Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that sub array, then the whole array should get sorted.

If A is already sorted, output -1.

Example :

Input 1:

A = [1, 3, 2, 4, 5]

Return: [1, 2]

Input 2:

A = [1, 2, 3, 4, 5]

Return: [-1]
In the above example(Input 1), if we sort the subarray A1, A2, then whole array A should get sorted.
*/

/*
Solution approach:
We just check the sorted array and unsorted array.
Get the left index from left side array, and right index from right side.
No index present, return -1;
*/
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr) {
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> solve(vector<int> arr) {
    vector<int> result;
    vector<int> temp = arr;
    int left = -1;
    int right = -1;
    int n = arr.size();

    sort(arr.begin(), arr.end());
    
    for(int i=0; i<n; i++){
        if(temp[i] != arr[i]) {
            left = i;
            break;
        }
    }

    if(left != -1) {
        for(int i=n-1; i>=0; i--){
            if(temp[i] != arr[i]) {
                right = i;
                break;
            }
        }
        result.push_back(left);
        result.push_back(right);
    } else {
        result.push_back(-1);
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
        vector<int> arr;
        cout << "Given input array is: " << endl;
        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            arr.push_back(temp);
            cout << temp << " ";
        }
        cout << endl;
        
        vector<int> result = solve(arr);
        cout << "Result: " << endl;
        printVector(result);

        cout << endl;
    }
    return 0;
}