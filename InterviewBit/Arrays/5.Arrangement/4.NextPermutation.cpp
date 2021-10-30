/*
Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers for a given array A of size N.

If such arrangement is not possible, it must be rearranged as the lowest possible order i.e., sorted in an ascending order.

Note:

1. The replacement must be in-place, do **not** allocate extra memory.
2. DO NOT USE LIBRARY FUNCTION FOR NEXT PERMUTATION. Use of Library functions will disqualify your submission retroactively and will give you penalty points.
Input Format:

The first and the only argument of input has an array of integers, A.
Output Format:

Return an array of integers, representing the next permutation of the given array.
Constraints:

1 <= N <= 5e5
1 <= A[i] <= 1e9
Examples:

Input 1:
    A = [1, 2, 3]

Output 1:
    [1, 3, 2]

Input 2:
    A = [3, 2, 1]

Output 2:
    [1, 2, 3]

Input 3:
    A = [1, 1, 5]

Output 3:
    [1, 5, 1]

Input 4:
    A = [20, 50, 113]

Output 4:
    [20, 113, 50]
*/

/*
Solution Approach:
https://www.geeksforgeeks.org/find-the-next-lexicographically-greater-word-than-a-given-word/
The same program can also be implemented without using STL. 
Below is the code snippet for the same. 
The idea is based on the following facts:
1) An sequence sorted in descending order does not have next permutation. 
For example edcba” does not have next permutation.
2) For a sequence which is not sorted in descending order for example “abedc”, we can follow below steps.
……….a) Traverse from right and find the first item that is not following the descending order. 
For example in “abedc”, the character ‘b’ does not follow the descending order.
……….b) Swap the found character with closest greater (or smallest greater) element on right side of it. 
In case of “abedc”, we have ‘c’ as the closest greater element. 
After swapping ‘b’ and ‘c’, string becomes “acedb”.
……….c) After swapping, sort the string after the position of character found in step a. 
After sorting the substring “edb” of “acedb”, we get “acbde” which is the required next permutation.

Optimizations in step b) and c)
a) Since the sequence is sorted in decreasing order, we can use binary search to find the closest greater element.
c) Since the sequence is already sorted in decreasing order (even after swapping as we swapped with the closest greater), 
we can get the sequence sorted (in increasing order) after reversing it.
*/

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr) {
    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int lowerBound(vector<int> arr, int low, int high, int value) {
    int result;
    if(low == high){
        return low;
    }
    int mid = (low + high)/2;
    if(arr[mid] == value){
        result = mid;
    } else {
        if(value > arr[mid]) {
            result = lowerBound(arr, low, mid, value);
        } else {
            result = lowerBound(arr, mid+1, high, value);
        }
    }
    return result;
}

vector<int> solve(vector<int> arr) {
    vector<int> result;
    int n = arr.size();

    int index = -1;
    for(int i=n-1; i>0; i--){
        if(arr[i] > arr[i-1]) {
            index = i-1;
            break;
        }
    }

    if(index == -1) {
        // reverse the list and return
        for(int i=n-1; i>=0; i--){
            result.push_back(arr[i]);
        }
    } else {
        // find the lower bound
        cout << "index value: " << index << endl;
        cout << "Index value in arr: " << arr[index] << endl;
        int lower = lowerBound(arr, index + 1, n-1, arr[index]);
        if(arr[index] > arr[lower]) {
            lower--;
        }
        cout << "lower value: " << lower << endl;
        cout << "lower value in arr: " << arr[lower] << endl;
        // swap values
        int temp = arr[lower];
        arr[lower] = arr[index];
        arr[index] = temp;

        for(int i=0; i<=index; i++){
            result.push_back(arr[i]);
        }
        for(int i=n-1; i>index; i--){
            result.push_back(arr[i]);
        }
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
